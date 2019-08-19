#include<windows.h>
#include <glut.h>
#include <stdlib.h>

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  //sets the color value to clear buffer
    glOrtho(-5,5,-5,5,-5,5); //left,right,bottom,top, near, far
}
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT); //clear buffer, buffer_bit indicates the buffers currently enabled for color writing

    /*glColor3f(0.0f, 1.0f, 0.0f); // GREEN RECTANGLE
    glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE

        glVertex2d(2,2);
        glVertex2d(-2,2);
        glVertex2d(-2,-2);
        glVertex2d(2,-2);

    glEnd();

     glColor3f(1.0f, 0.0f, 0.0f); //RED TRIANGLE
    glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE

        glVertex2d(0.0,2.5);
        glVertex2d(-2.5,0.0);
        glVertex2d(2.5,0.0);

    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f); //BLUE LINE
    glBegin(GL_LINES); // It can be any type Gl_POINT,_LINE

        glVertex2d(-4.0,-2.0);
        glVertex2d(4.0,2.0);

    glEnd();*/

    //glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS); // DRAWING 4 SIDED QUADRILATERAL
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(-2.0,-4.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(4.0,-2.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2d(4.0,2.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2d(-2.0,4.0);
    glEnd();

    /*
    glBegin(GL_TRIANGLES); // DRAWING 3 SIDED TRIANGLE
        glColor3f(1.0f, 0.0f, 0.0f); glVertex2d(-2.0,-4.0);
        glColor3f(1.0f, 1.0f, 0.0f); glVertex2d(4.0,-2.0);
        glColor3f(1.0f, 0.0f, 1.0f); glVertex2d(-2.0,4.0);
    glEnd();*/

    /*
    glBegin(GL_POLYGON); // DRAWING POLYGON
        glColor3f(1.0, 1.0, 0.0); // yellow
        glVertex2f(0.0, 0.0) ;
        glVertex2f(0.0, 3.0) ;
        glVertex2f(4.0, 3.0) ;
        glVertex2f(4.5, 1.5) ;
        glVertex2f(4.0, 0.0);
    glEnd();
    */

    glFlush(); //force execution of Gl commands
}

int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600); // Size of the window
    glutInitWindowPosition(100, 100); // location of the window
    glutCreateWindow("Tutorial 1"); // Create window with this name
    init(); // call initialize function
    glutDisplayFunc(myDisplay); // call display function
    glutMainLoop();
    return 0;
}

