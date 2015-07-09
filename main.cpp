
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//   *********************************  ASSINGMENT INFORMATION  ************************************   //
//   *                                                                                             *   //
//   *                            ASSINGMENT:    Paint                                             *   // 
//   *                                                                                             *   //   
//   *                            Instructor:    Osama Khalid.                                     *   //
//   *                                                                                             *   //
//   *                                                                                             *   // 
//   *                            Submitted By :                                                   *   //
//   *                                         Innam Ullah Baig.                                   *   //
//   *                                                                                             *   // 
//   *                            DATE:        20-Feb-2012.                                        *   //
//   *                                                                                             *   //
//   *                                                                                             *   //
//   *                            Contact:                                                         *   //
//   *                                      admin@innamhunzai.tk                                   *   //
//   *                                      innamhunzai@gmail.com                                  *   //
//   ***********************************************************************************************   //
/////////////////////////////////////////////////////////////////////////////////////////////////////////




#include <iostream>                       ////////////////////////////////////////////////////////
#include <graphics.h>                     //                                                    //
#include <stdlib.h>                        //                     HEADER FILES                  //   
#include <conio.h>                       ////////////////////////////////////////////////////////
#include "paint.h"
#include<string.h>
#include<conio.h>

using namespace std;


//////////////////////////////////////  MAIN FUNCTION ///////////////////////////////////////////////////////////
int main()
{
       initwindow(getmaxwidth( ), getmaxheight( ),"Paint by Innam Hunzai");
       
	   paint  P;      
       
	   P.show_window();
       P.start_working();
       
	   getch();
       closegraph();
       return 0;  
}
///////////////////////////////  MAIN FUNCTION END /////////////////////////////////////////////////////////////////////////////
