#include"tools.h"


class paint
       {
            tools T;
            MyGraphics GP;
            
	  public:
		paint( );
		~paint( ) { }
        void show_window();
        void start_working();
		int getinput();
};

paint::paint( )   //constructor  
{}         

/////////////////////////////////////////////////////////// Display Main Window of paint ///////////////////////////////////////////////////////////////////////////////////////   
void paint::show_window()
{
    cleardevice( );
    setcolor(15);
    setlinestyle(1,0,3);

    rectangle(5,5,getmaxx( )-5,getmaxy( )-5);

    setlinestyle(0,0,0);
    GP.show_portion(5,5,getmaxx( )-5,80); // Header portion
    setfillstyle(1,DARKGRAY);
    bar(13,13,getmaxx( )-13,72);
    
    GP.unpressed_button(30,22,80," ");                     /////////////////////////////////////////////////////////////////////////////////
    readimagefile("open.GIF",32,24,78,60);                 //
                                                           //
	GP.unpressed_button(110,22,160," ");                   //                       MAIN MENU
    readimagefile("new.GIF",112,22,158,60);                // 
	                                                       //  
	GP.unpressed_button(190,22,240," ");                   //
	readimagefile("save.JPG",192,22,238,60);               /////////////////////////////////////////////////////////////////////////////////////  
	
    setcolor(RED);
    setbkcolor(DARKGRAY);
    settextstyle(SIMPLEX_FONT,0,5);
	outtextxy(250,22,"Mini Paint by Innam Hunzai");
     setlinestyle(0,0,0); 
    GP.show_portion(5,82,215,getmaxy( )-5);                      //menu sidebar    
    setfillstyle(1,DARKGRAY);
    bar(13,90,207,getmaxy( )-13);

    GP.show_portion(217,82,getmaxx( )-5,getmaxy( )-5);  // drawing area     setfillstyle(1,WHITE);
    setfillstyle(1,WHITE);
    bar(225,90,getmaxx( )-13,getmaxy( )-13);
     
    setcolor(WHITE);
    settextstyle(SIMPLEX_FONT,0,2);                             //////////////////////////////////////////////////////////
	                                                            //
    outtextxy(17,107,"Select Tool:");                           // 
                                                                // 
                                                                // 
	 setcolor(14);                                              //   
	                                                            //
	   GP.unpressed_button(30,140,80," ");                         //
	   readimagefile("line_tool.JPG",32,142,77,177);            //  
	                                                            //
	   GP.unpressed_button(130,140,180," ");                       //  
	   readimagefile("text_tool.JPG",132,142,177,177);          //              DISPLAY DRAWING TOOL
	                                                            //
       GP.unpressed_button(30,210,80," ");                         //
	   readimagefile("fill_tool.JPG",32,212,77,247);            //  
	                                                            // 
	   GP.unpressed_button(130,210,180," ");                       //  
	   readimagefile("eraser_tool.JPG",132,212,177,247);        // 
	                                                            // 
       GP.unpressed_button(30,280,80," ");                         //   
       readimagefile("rectangle_tool.JPG",32,282,77,317);       //
                                                                //   
       GP.unpressed_button(130,280,180," ");                       //
       readimagefile("circle_tool.JPG",132,282,177,317);        /////////////////////////////////////////////////////////////       
       
       setcolor(WHITE);
       settextstyle(SIMPLEX_FONT,0,2);                          //////////////////////////////////////////////////////////
	   setbkcolor(DARKGRAY);                                    //
       outtextxy(17,400,"Select color:");                       //              DISPLAY COLOR BOX
       GP.unpressed_button(30,430,80," ");                      //
       GP.unpressed_button(100,430,135," ");                    ///////////////////////////////////////////////////////////       
	   T.select_tool(T.get_current_tool(),T.get_current_color(),T.get_current_b_color());
}

///////////////////////////////////////////////////////    Start Working ///////////////////////////////////////////////////////////////////////////////////////////
void paint::start_working()
{
      int mode,ch=1;
       int old_window;
       int mx,my;
       while(true)
       {
		
			while (!ismouseclick(WM_LBUTTONDOWN))
			 delay(5);
			
         getmouseclick(WM_LBUTTONDOWN, mx, my);
         clearmouseclick(WM_LBUTTONDOWN);
         clearmouseclick(WM_LBUTTONUP);
         if( (mx>=30 && mx <=180)&&(my>=140&&my<=320) )
            { 
                          T.set_tool(mx,my);
            }
         else if( (mx>=30 && mx <=80)&&(my>=430&&my<=470) )
            {
                          GP.display_color_panel();
                          T.select_color(1);
                      
            }
        else if( (mx>=100 && mx <=135)&&(my>=430&&my<=470) )
            {
                          GP.display_color_panel();
                          T.select_color(2);
                      
            }
        else if( (mx>=230 && mx <=getmaxx()-18)&&(my>=97&&my<=getmaxy()-13) )
            { 
                           GP.start_drawing(T.get_current_tool(),T.get_current_color(),T.get_current_b_color(),T.get_current_size(),mx,my);
            }
        else if( (mx>=20 && mx <=getmaxx())&&(my>=15&&my<=80) )
            {
			   GP.check_main_menu(mx,my);	
			}
          else
        {
                  clearmouseclick(WM_LBUTTONDOWN);
                  clearmouseclick(WM_LBUTTONUP);             
          }
       }
}
/////////////////////////////////////////////////  END Working Function ////////////////////////////////////////////////////////////////////////////////////////////////////
