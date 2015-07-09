#include<graphics.h>

 # define LINE 0
 # define PTEXT 1
 # define PEN 2
 # define eraser 3
 # define RECT 4
 # define CRIC 5

class MyGraphics
       {
	  public:
		MyGraphics( ) {}
		~MyGraphics( ) { }
		void loading_bar(int,int,int);
		void unpressed_button(int,int,int,char*);
		void pressed_button(int,int,int,char *);
		void show_portion(int,int,int,int);
		void msg_box(int);
		int getinput();
		void display_color_panel();
        void clear_panel(int,int,int,int,int);
        void check_main_menu(int , int);
        void start_drawing(int,int,int,int,int, int);
};
    

void MyGraphics::loading_bar(int x1,int y1,int x2)
{
      setbkcolor(WHITE);
      setfillstyle(1,WHITE);
      bar(x1,y1,x2,y1+20);
      setbkcolor(BLUE);                                         
      setfillstyle(1,BLUE);
      int s=x1;
      for(int e=x1+10;e<=x2;e++)           
      {            
        bar(s,y1,e,y1+20);               	                      
        delay(10);                                        
	  }
      setbkcolor(BLACK);
      setfillstyle(1,BLACK);
      bar(x1,y1,x2,y1+20);   
}



void MyGraphics::unpressed_button(int left,int top,int right,char caption[])
 {
     setlinestyle(SOLID_LINE,0,5);
     setcolor(WHITE);
     int bottom=top+40;
     
     rectangle(left,top,right,bottom);
     setfillstyle(1,LIGHTBLUE);
     bar(left+1,top+1,right-1,bottom-1);
     
     int x=((right-left)/2)+left;
     
     int len=(strlen(caption)*15)/2;     
     setbkcolor(LIGHTBLUE);
     settextstyle(TRIPLEX_FONT,0,3);
	 setcolor(RED);
     outtextxy(x-len,top+10,caption);
     setbkcolor(BLACK);
}

void MyGraphics::pressed_button(int left,int top,int right,char caption[])
{
     setlinestyle(SOLID_LINE,0,5);
     setcolor(RED);
     int bottom=top+40;
     
     rectangle(left,top,right,bottom);
     setfillstyle(1,LIGHTBLUE);
     bar(left+1,top+1,right-1,bottom-1);
     
     int x=((right-left)/2)+left;
     
     int len=(strlen(caption)*15)/2;     
     setbkcolor(LIGHTBLUE);
     settextstyle(TRIPLEX_FONT,0,3);
	 setcolor(RED);
     outtextxy(x-len,top+10,caption);
     setbkcolor(BLACK);
     delay(200);
}


void MyGraphics::display_color_panel()
{
       setcolor(WHITE);
       rectangle(25,500,188,601);
       setbkcolor(BLACK);
       setfillstyle(0,RED);
       bar(27,502,186,599);
       
       int counter=1;
       int i=0, j=0;
       int x1=30,x2=60,y1=505,y2=535;
       for(i=0;i<3;i++)
       {
            x1=30;
            x2=60;
            for(j=0;j<5;j++)
            {
                 setbkcolor(counter++);
                 setfillstyle(0,RED);
                 bar(x1,y1,x2,y2);
                 x1=x1+31;
                 x2=x2+31;
            }
            y1=y1+31;
            y2=y2+31;
       }
}


int MyGraphics::getinput()
{
      msg_box(1);
      int x=90;
	  int y= 550;     
      char Number[6];
      int c=0;
      Number[0]='\0';
      int z=x;
      do
		{
           char key;          
           setcolor(WHITE);
           settextstyle(SIMPLEX_FONT,0,1);
           outtextxy(x,y,Number);
		   
          while(!kbhit())
            {
                         setfillstyle(1,WHITE);
                         bar(z,y+15,z+10,y+17);
                         delay(250);
                         setfillstyle(1,BLACK);
                         bar(z,y+15,z+10,y+17);
                         delay(250);
            }
         
          if(kbhit())
		  {     key=getch();
             
            }
          if(key=='\r')
           break;
          if((key>=48) && (key<=57))           
             {
               Number[c]=key;
               c++;
               Number[c]='\0';
               z=z+15;
             }
           else
             continue;  
     }while(true);
	      
   int num = atoi(Number);
   return num;
}

void MyGraphics::msg_box(int mesg)
{
       setbkcolor(BLUE);
       setfillstyle(0,BLUE);
       bar(25,500,200,590);
       show_portion(25,500,200,590);
       
       setcolor(LIGHTCYAN);
       settextstyle(SIMPLEX_FONT,0,2);
       if(mesg==1)
       {
         setbkcolor(BLUE);
		 outtextxy(35,510,"Enter Size:");
		 
         setbkcolor(BLACK);
         setfillstyle(0,BLACK);
         bar(70,540,130,570);
       }
       
       else if(mesg==0)
       {
            setbkcolor(BLUE);
		    settextstyle(2,0,8);
		    setcolor(RED);
		    outtextxy(35,530,"     Error ");
		    outtextxy(35,560,"   limit is 5");
		    delay(1000);
         
      }
}

void MyGraphics::clear_panel(int x1,int y1,int x2,int y2,int bc)
{
      setbkcolor(bc);
      setfillstyle(1,bc);
      bar(x1,y1,x2,y2);
}

void MyGraphics::show_portion(int x_1,int y_1,int x_2,int y_2)
{
     setcolor(WHITE);
	 rectangle(x_1,y_1,x_2,y_2);
	 rectangle(x_1+1,y_1+1,x_2-1,y_2-1);

     setcolor(LIGHTGRAY);
	 rectangle(x_1+2,y_1+2,x_2-2,y_2-2);
	 rectangle(x_1+3,y_1+3,x_2-3,y_2-3);
	 

     setcolor(DARKGRAY);
	 rectangle(x_1+5,y_1+5,x_2-5,y_2-5);
	 rectangle(x_1+6,y_1+6,x_2-6,y_2-6);
}

//////////////////////////////////////////////////////////// MAIN MENU EVENT HANDLER FUNCTION //////////////////////////////////////////////////////////////

void MyGraphics::check_main_menu(int x1, int y1)
{
	if((x1>=30&&x1<=80)&&(y1>=22&&y1<=62))
	   readimagefile(NULL,225,90,getmaxx()-13, getmaxy()-13); 
	                                                                
	else if((x1>=110&&x1<=160)&&(y1>=22&&y1<=62))                
          {
				setbkcolor(WHITE);
                setfillstyle(1,WHITE);
				bar(225,90,getmaxx( )-13,getmaxy( )-13);
		  }    	                                                       
	else if((x1>=190&&x1<=240)&&(y1>=22&&y1<=62))                   
	  writeimagefile(NULL,225,90,getmaxx()-13, getmaxy()-13,true, NULL);	 
	  
}

//////////////////////////////////////////////////////////// PAINT DRAWING FUNCTION ////////////////////////////////////////////////////////////////////

void MyGraphics::start_drawing(int t,int c,int bc,int size,int x1, int y1)
    {
		                setcolor(c);
		                setbkcolor(bc);
                        setfillstyle(SOLID_FILL,bc);
                        if(t == LINE)
                        {
                             int x2,y2;
                             while (!ismouseclick(WM_LBUTTONUP))
                              delay(5);                                            //
                             getmouseclick(WM_LBUTTONUP, x2, y2);
                             if((x2>=230 && x2 <=getmaxx()-18)&&(y2>=97&&y2<=getmaxy()-13))
                               line(x1,y1,x2,y2); 
                        }
                        else if(t == CRIC)
                        {
                             int x2,y2;
                             while (!ismouseclick(WM_LBUTTONUP))
                              delay(5);
                             getmouseclick(WM_LBUTTONUP, x2, y2);
                             int r=x2-x1;
                             int x3=x1-r;
                             int y3=y1-r;
                             if(((x2>=230 && x2 <=getmaxx()-18)&&(y2>=97&&y2<=getmaxy()-13))&&((x3>=230 && x3 <=getmaxx()-18)&&(y3>=97&&y3<=getmaxy()-13)))
                              { 
                                         
                                         circle(x1,y1,r);
                                         floodfill(x1, y1, c);
                              }
                        }
                        else if(t == RECT)
                        {
                              int x2,y2;
                             while (!ismouseclick(WM_LBUTTONUP))
                              delay(5);
							   setbkcolor(bc);                                            //
                             getmouseclick(WM_LBUTTONUP, x2, y2);
                             if((x2>=230 && x2 <=getmaxx()-18)&&(y2>=97&&y2<=getmaxy()-13))
                               {  
									rectangle(x1,y1,x2,y2);
                                    floodfill((x1+x2)/2, (y1+y2)/2, c);
							   }  
                        }
                        else if(t == eraser)
                        {
                            int x2=0,y2=0;
                            clearmouseclick(WM_LBUTTONUP);
                            while (!ismouseclick(WM_LBUTTONUP))
                            {                                              //
                             while(!ismouseclick(WM_MOUSEMOVE))
							 delay(10);
							 getmouseclick(WM_MOUSEMOVE, x2, y2);
                             if(((x2>=230 && x2 <=getmaxx()-18)&&(y2>=97&&y2<=getmaxy()-13))&&(size==1))
                                    bar(x2-10,y1-10,x2+10,y2+10);
							 else if(((x2>=240 && x2 <=getmaxx()-28)&&(y2>=107&&y2<=getmaxy()-23))&&(size==2))        
							          bar(x2-20,y2-20,x2+20,y2+20);
							 else if(((x2>=250 && x2 <=getmaxx()-38)&&(y2>=117&&y2<=getmaxy()-33))&&(size==3))        
							          bar(x2-30,y2-30,x2+30,y2+30);
							 else if(((x2>=250 && x2 <=getmaxx()-48)&&(y2>=127&&y2<=getmaxy()-43))&&(size==4))        
							          bar(x2-40,y2-40,x2+40,y2+40);
							 else if(((x2>=260 && x2 <=getmaxx()-58)&&(y2>=137&&y2<=getmaxy()-53))&&(size==5))        
							          bar(x2-50,y2-50,x2+50,y2+50);
						     clearmouseclick(WM_MOUSEMOVE);
						   }	    
                        }
                        else if(t==PEN)
                        {
						    setcolor(c);
							int x2=0,y2=0;
                            while (!ismouseclick(WM_LBUTTONUP))
                            {                                          //
                             getmouseclick(WM_MOUSEMOVE, x2, y2);
                             if((x2>=230 && x2 <=getmaxx()-18)&&(y2>=97&&y2<=getmaxy()-13))
                               putpixel(x2, y2, c);
                               putpixel(x2-1, y2, c);
                               putpixel(x2+1, y2, c);
                               putpixel(x2, y2-1, c);
                               putpixel(x2, y2+1, c);
							} 	
						}
						else if(t == PTEXT)
                        {
							setcolor(c);
							setbkcolor(bc);   
                            char txt[30];
                            int c=0;
                            txt[0]='\0';
                            
                            do
		                    {
                              char key;          
                              outtextxy(x1,y1,txt);
		                      settextstyle(SIMPLEX_FONT,0,1);
	                          
   	                          
                              delay(250);
                        
		                      key=getch();
                              if(key=='\r')
                                 break;
							  if(key==8)
							    {  
								   c--;
								   txt[c]='\0';
								   strcat(txt, "     ");
								   outtextxy(x1,y1,txt);
								} 
							 else           
                              {
						    	txt[c]=key;
                                c++;
                                txt[c]='\0';
							 }
                           }while(true);
  
                        }
						            
    }
