Minipaint
=========

Mini Paint is C++ BGI Graphics Project to demonstrate basic paint functionalities.

## How to use code and exe file ##

### Using exe file ###
  
 1. The secreen resolution should be 800 X 800 or higher to run the program correctly.

### Using Code in DEV C++ ###

How do I use Borland Graphics Interface (graphics.h)?
 
 1. The files we need are:
     graphics.h 	(download to C:\Dev-Cpp\include)
     libbgi.a    	(download to C:\Dev-Cpp\lib) 
     download using this link http://www.uniqueness-template.com/devcpp/

 2. Create a new project.
    A "project" can be considered as a container that is used to store all the elements that are required to compile a program.

    Go to the "File" menu and select "New", "Project...".
    Choose "Empty Project" and make sure "C++ project" is selected.
    Here you will also give your project a name. You can give your project any valid filename, but keep in mind that the name of your project will also be the name of your final executable.
    Once you have entered a name for your project, click "OK".
    Dev-C++ will now ask you where to save your project. Its better to create a folder in any directory you want and save project in that.

 3. Create/add source file(s).
    You can add empty source files one of two ways:

    Go to the "File" menu and select "New Source File" (or just press CTRL+N) OR
    Go to the "Project" menu and select "New File".
    Note that Dev-C++ will not ask for a filename for any new source file until you attempt to:
        Compile
        Save the project
        Save the source file

 4. Go to "Project" menu and choose "Project Options" (or just press ALT+P).
    Go to the "Parameters" tab
    In the "Linker" field, enter the following text:
    
    -lbgi
    -lgdi32
    -lcomdlg32
    -luuid
    -loleaut32
    -lole32 

 5. Complile
 6. Execute

 ENJOY!!
