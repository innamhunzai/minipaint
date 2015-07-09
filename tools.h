#include"mygraphics.h"

class tools{
      MyGraphics GT;
      int def_tool;
      int def_color;
      int def_b_color;
      int def_size;
      
      public:
             tools();
             ~tools() {}
             void select_tool(int, int, int);
             int get_current_tool();
             int get_current_color();
             int get_current_size();
             void set_tool(int,int);
             void free_tool();
             int select_color(int);
             int get_color(int,int);
             int get_current_b_color();
       };
       
tools::tools()
{
              def_tool=LINE;
              def_color=BLACK;
              def_b_color= WHITE;
              def_size=1;
}
    
void tools::select_tool(int t,int c,int bc)
{
     
     switch(t)
       {
                       case 0:
                            GT.pressed_button(30,140,80," ");                         
                            readimagefile("line_tool.JPG",32,142,77,177); 
                            break;
                            
                       case 1:
                            GT.pressed_button(130,140,180," ");                        
                            readimagefile("text_tool.JPG",132,142,177,177); 
                            break;
                            
                       case 2:
                            GT.pressed_button(30,210,80," ");                         
                            readimagefile("fill_tool.JPG",32,212,77,247); 
                            break;
                            
                       case 3:
                            GT.pressed_button(130,210,180," ");                        
	                        readimagefile("eraser_tool.JPG",132,212,177,247);     
                            break;
                            
                       case 4:                                                     
                            GT.pressed_button(30,280,80," ");                           
                            readimagefile("rectangle_tool.JPG",32,282,77,317);     
                            break;                                                 
                                                                                   
                       case 5:                                                     
                            GT.pressed_button(130,280,180," ");                       
                            readimagefile("circle_tool.JPG",132,282,177,317);     
                            break;
       }
      setbkcolor(c);
      setfillstyle(1,c);
      bar(32,432,77,467);
      setbkcolor(bc);
      setfillstyle(1,bc);
	  bar(102,432,132,468); 
}
void tools::set_tool(int x,int y)
{
    if((x>=30 && x<=80)&&(y>=140 && y<=180))
        {
              free_tool();
              def_tool=LINE;
              select_tool(def_tool,def_color,def_b_color);
        }
        
    else if((x>=130 && x<=180)&&(y>=140 && y<=180))
        {
              free_tool();
              def_tool=PTEXT;
              select_tool(def_tool,def_color,def_b_color);
        }
        
    else if((x>=30 && x<=80)&&(y>=210 && y<=250))
        {
              free_tool();
              def_tool=PEN;
              select_tool(def_tool,def_color,def_b_color);
        }
        
    else if((x>=130 && x<=180)&&(y>=210 && y<=250))
        {
              free_tool();
              def_tool=eraser;
              select_tool(def_tool,def_color,def_b_color);
              int tmp = GT.getinput();
              if (tmp >5)
                GT.msg_box(0);
              else
                def_size = tmp;
              GT.clear_panel(20,495,205,595, DARKGRAY);
        }
        
    else if((x>=30 && x<=80)&&(y>=280 && y<=320))
        {
              free_tool();
              def_tool=RECT;
              select_tool(def_tool,def_color,def_b_color);
        }
        
    else if((x>=130 && x<=180)&&(y>=280 && y<=320))
        {
              free_tool();
              def_tool=CRIC;
              select_tool(def_tool,def_color,def_b_color);
        }
            
}
void tools::free_tool()
{
        switch(def_tool)
       {
                       case 0:
                            GT.unpressed_button(30,140,80," ");                         
                            readimagefile("line_tool.JPG",32,142,77,177); 
                            break;
                            
                       case 1:
                            GT.unpressed_button(130,140,180," ");                        
                            readimagefile("text_tool.JPG",132,142,177,177); 
                            break;
                            
                       case 2:
                            GT.unpressed_button(30,210,80," ");                         
                            readimagefile("fill_tool.JPG",32,212,77,247); 
                            break;
                            
                       case 3:
                            GT.unpressed_button(130,210,180," ");                        
	                        readimagefile("eraser_tool.JPG",132,212,177,247);     
                            break;
                            
                       case 4:                                                     
                            GT.unpressed_button(30,280,80," ");                           
                            readimagefile("rectangle_tool.JPG",32,282,77,317);     
                            break;                                                 
                                                                                   
                       case 5:                                                     
                            GT.unpressed_button(130,280,180," ");                       
                            readimagefile("circle_tool.JPG",132,282,177,317);     
                            break;
       }  
}

int tools::get_current_tool()
{
    return def_tool;
}

int tools::get_current_color()
{
    return def_color;
}

int tools::get_current_b_color()
{
	return def_b_color;
}
int tools::get_current_size()
{
	return def_size;
}
int tools::select_color(int ch)
{
          int mx=0,my=0;                                  //       VARIABLES TO GET MOUSE CLICK                                             
          clearmouseclick(WM_LBUTTONDOWN);
         while (!ismouseclick(WM_LBUTTONDOWN))                       //                 MOUSE EVENT
            delay(5);
                                                    //
         getmouseclick(WM_LBUTTONDOWN, mx, my);
         
         if( (mx>=30 && mx <=183)&&(my>=505&&my<=596) )
                      { 
                          GT.clear_panel(20,490,200,620,DARKGRAY);
                          if (ch==1)
						      def_color = get_color(mx,my);
						   else
						      def_b_color = get_color(mx,my);
						      
                          select_tool(def_tool,def_color,def_b_color);
                          clearmouseclick(WM_LBUTTONDOWN);
                      }
         else 
         {
              GT.clear_panel(20,490,200,620,DARKGRAY);
              clearmouseclick(WM_LBUTTONDOWN);
         }
}

int tools::get_color(int x, int y)
{
    if((x>=30&&x<=60)&&(y>=505&&y<=535))
      return 1;
    else if((x>=61&&x<=91)&&(y>=505&&y<=535))
      return 2;
    else if((x>=92&&x<=122)&&(y>=505&&y<=535))
      return 3;
    else if((x>=123&&x<=153)&&(y>=505&&y<=535))
      return 4;
    else if((x>=154&&x<=184)&&(y>=505&&y<=535))
      return 5;
    else if((x>=30&&x<=60)&&(y>=536&&y<=566))
      return 6;
    else if((x>=61&&x<=91)&&(y>=536&&y<=566))
      return 7;
    else if((x>=92&&x<=122)&&(y>=536&&y<=566))
      return 8;
    else if((x>=123&&x<=153)&&(y>=536&&y<=566))
      return 9;
    else if((x>=154&&x<=184)&&(y>=536&&y<=566))
      return 10;
    else if((x>=30&&x<=60)&&(y>=567&&y<=597))
      return 11;
    else if((x>=61&&x<=91)&&(y>=567&&y<=597))
      return 12;
    else if((x>=92&&x<=122)&&(y>=567&&y<=597))
      return 13;
    else if((x>=123&&x<=153)&&(y>=567&&y<=597))
      return 14;
    else if((x>=154&&x<=184)&&(y>=567&&y<=597))
      return 15;
    
    else return 0;
    
}


