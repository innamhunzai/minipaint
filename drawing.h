class drawing
{  
  public:
    drawing(){}
    ~drawing(){}
    void start_drawing(int t,int c,int bc,int size,int x1, int y1)
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
                             if((x2>=230 && x2 <=getmaxx()-18)&&(y2>=97&&y2<=getmaxy()-13))
                              { 
                                         int r=x2-x1;
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
};


