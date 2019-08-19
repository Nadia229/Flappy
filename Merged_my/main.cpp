#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include <windows.h>
#include <glut.h>




#define pi (2*acos(0.0))
#define GLUT_DISABLE_ATEXIT_HACK;
#define PI 3.1416


GLvoid *font_style = GLUT_BITMAP_HELVETICA_18;


double cameraHeight;
double cameraAngle;
static float clx1 = 280;
static float cly1 = 70;
int drawgrid;
int drawaxes;
int a=0;
double angle;
double incx, incy;
int state,state1,state2,state3;
int tx,ty,tx1=-60,ty1=150,tx2=-60,ty2=-20,tx3,ty3,tx4=-14,ty4=15;
float tx5=150,ty5,tx6=300,ty6,tx7=-90,ty7=0,tx8=-10,ty8=16;
char text[100]="START";
char text2[100]="Enter space to start";
char text1[100]="LET's PLAY THE FLAPY BIRD";
char text3[100]="Thanks for play!";
char text4[100]="Score:";
double inc_ang=0.05;
int stop=0;
double score;
char msg[30];
char sc[30]="Score=";



struct point
{
	double x,y,z;
};
void bird()
{

}

void continuous()
{
    tx+=1;
    tx1-=1;
    tx2+=1;
    //ty4+=1;

    if(state ==0 && ty4>10){ state =1;}
    if(state ==1 && ty4<15){ state =0;}

    if(state==1) ty4-=3;
    if(state==0) ty4+=3;



    if(state1 ==0 && tx5 <-690){ state1 =1;}
    if(state1 ==1 && tx5==155 ){state1 =0;}

    if(state1==0) tx5-=0.2;
    if(state1==1){tx5=155;}

    if(state2 ==0 && tx6 <-250){ state2 =1;}
    if(state2 ==1 && tx6==100 ){state2 =0;}

    if(state2==0) tx6-=0.2;
    if(state2==1){tx6=100;}


    /*tx5-=0.05;
     if(tx5 <= -650)
        tx5 = tx5 + 480;*/



    if(state3==0) {state3=1;}

    if(state3==1) {//tx7+=0.02;
                   ty7-=0.05;
                   }



   /* tx6-=0.02;
     if(tx6 <= -390)
        tx6 = tx6 + 150;*/










    clx1 -= 0.08;
    if(clx1 <= -240)
        clx1 = clx1 + 450;



    /*if(state1 == 0) {
                    tx5+=.05;}

    if(state1 ==1) {
                    tx5-=.05;}
    if(state1 ==2) {
                    tx5+=.05;}*/



  // ty=0;
    glutPostRedisplay();

}







void drawAxes()
{
	if(drawaxes==1)
	{
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);{
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);

			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);

			glVertex3f(0,0, 100);
			glVertex3f(0,0,-100);
		}glEnd();
	}
}


void drawGrid()
{
	int i;
	if(drawgrid==1)
	{
		glColor3f(0.6, 0.6, 0.6);	//grey
		glBegin(GL_LINES);{
			for(i=-8;i<=8;i++){

				if(i==0)
					continue;	//SKIP the MAIN axes

				//lines parallel to Y-axis
				glVertex3f(i*10, -90, 0);
				glVertex3f(i*10,  90, 0);

				//lines parallel to X-axis
				glVertex3f(-90, i*10, 0);
				glVertex3f( 90, i*10, 0);
			}
		}glEnd();
	}
}

void drawSquare(double a)
{
    //glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);{
		glVertex3f( a, a,2);
		glVertex3f( a,-a,2);
		glVertex3f(-a,-a,2);
		glVertex3f(-a, a,2);
	}glEnd();
}
void circle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 20;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

	glEnd();
}
void draw_tail()
{
      glColor3f(1,1,1);
        int i;
    struct point points[100];
    //glColor3f(0.7,0.7,0.7);
    //generate points
    for(i=10;i<=25;i++)
    {
        points[i].x=8*cos(((double)i/(double)15)*2*pi);
        points[i].y=5*sin(((double)i/(double)15)*2*pi);
    }
    //draw segments using generated points
    for(i=10;i<25;i++)
    {
        glBegin(GL_POLYGON);
        {
			glVertex3f(points[i].x,points[i].y,0);
			glVertex3f(points[i+1].x,points[i+1].y,0);
			glVertex3f(points[i+2].x,points[i+2].y,0);
			glVertex3f(points[i+3].x,points[i+3].y,0);
			glVertex3f(points[i+4].x,points[i+4].y,0);
			glVertex3f(points[i+5].x,points[i+5].y,0);
			glVertex3f(points[i+6].x,points[i+6].y,0);
			glVertex3f(points[i+7].x,points[i+7].y,0);
			glVertex3f(points[i+8].x,points[i+8].y,0);
			glVertex3f(points[i+9].x,points[i+9].y,0);
            glVertex3f(points[i+10].x,points[i+10].y,0);
            glVertex3f(points[i+11].x,points[i+11].y,0);
        }
        glEnd();


    }

}
void circle1()
{
    int i;
    struct point points[100];
    //glColor3f(0.7,0.7,0.7);
    //generate points
    for(i=10;i<=25;i++)
    {
        points[i].x=4*cos(((double)i/(double)15)*2*pi);
        points[i].y=6*sin(((double)i/(double)15)*2*pi);
    }
    //draw segments using generated points
    for(i=10;i<25;i++)
    {
        glBegin(GL_POLYGON);
        {
			glVertex3f(points[i].x,points[i].y,0);
			glVertex3f(points[i+1].x,points[i+1].y,0);
			glVertex3f(points[i+2].x,points[i+2].y,0);
			glVertex3f(points[i+3].x,points[i+3].y,0);
			glVertex3f(points[i+4].x,points[i+4].y,0);
			glVertex3f(points[i+5].x,points[i+5].y,0);
			glVertex3f(points[i+6].x,points[i+6].y,0);
			glVertex3f(points[i+7].x,points[i+7].y,0);
			glVertex3f(points[i+8].x,points[i+8].y,0);
			glVertex3f(points[i+9].x,points[i+9].y,0);
            glVertex3f(points[i+10].x,points[i+10].y,0);
            glVertex3f(points[i+11].x,points[i+11].y,0);
        }
        glEnd();
    }
}
void circle2()
{
    int i;
    struct point points[100];
    //glColor3f(0.7,0.7,0.7);
    //generate points
    for(i=10;i<=25;i++)
    {
        points[i].x=2*cos(((double)i/(double)15)*2*pi);
        points[i].y=3*sin(((double)i/(double)15)*2*pi);
    }
    //draw segments using generated points
    for(i=10;i<25;i++)
    {
        glBegin(GL_POLYGON);
        {
			glVertex3f(points[i].x,points[i].y,0);
			glVertex3f(points[i+1].x,points[i+1].y,0);
			glVertex3f(points[i+2].x,points[i+2].y,0);
			glVertex3f(points[i+3].x,points[i+3].y,0);
			glVertex3f(points[i+4].x,points[i+4].y,0);
			glVertex3f(points[i+5].x,points[i+5].y,0);
			glVertex3f(points[i+6].x,points[i+6].y,0);
			glVertex3f(points[i+7].x,points[i+7].y,0);
			glVertex3f(points[i+8].x,points[i+8].y,0);
			glVertex3f(points[i+9].x,points[i+9].y,0);
            glVertex3f(points[i+10].x,points[i+10].y,0);
            glVertex3f(points[i+11].x,points[i+11].y,0);
        }
        glEnd();
    }
}





void drawCircle(double radius,int segments)
{
    int i;
    struct point points[100];
    glColor3f(1.0,0.8,0.0);
    //generate points
    for(i=0;i<=segments;i++)
    {
        points[i].x=11*cos(((double)i/(double)segments)*2*pi);
        points[i].y=radius*sin(((double)i/(double)segments)*2*pi);
    }
    //draw segments using generated points
    for(i=0;i<segments;i++)
    {
        glBegin(GL_POLYGON);
        {

			glVertex3f(points[i].x,points[i].y,0);
			glVertex3f(points[i+1].x,points[i+1].y,0);
			glVertex3f(points[i+2].x,points[i+2].y,0);
			glVertex3f(points[i+3].x,points[i+3].y,0);
			glVertex3f(points[i+4].x,points[i+4].y,0);
			glVertex3f(points[i+5].x,points[i+5].y,0);
			glVertex3f(points[i+6].x,points[i+6].y,0);
			glVertex3f(points[i+7].x,points[i+7].y,0);
			glVertex3f(points[i+8].x,points[i+8].y,0);
			glVertex3f(points[i+9].x,points[i+9].y,0);
            glVertex3f(points[i+10].x,points[i+10].y,0);
            glVertex3f(points[i+11].x,points[i+11].y,0);



        }
        glEnd();
    }
}


void draw_rec()
{
    glColor3f(0,1,0);
   // glRotatef(2*angle,0,0,1);
   // continuous();
   // glTranslatef(tx,ty,0);
    //glRotatef(5*angle,0,0,1);
    drawSquare(10);

}
void obstacle1()
{

glPushMatrix();
    //glTranslatef(20,3,0);

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,155);
        glVertex2f(115,155);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,20);
        glVertex2f(120,20);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();

   // glTranslatef(99,-165,0);


    glPopMatrix();










    glPushMatrix();
    glTranslatef(-20,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-20);
        glVertex2f(120,-20);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();

   // glTranslatef(99,-165,0);
    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();


    //drawSquare(13);


     glPushMatrix();
    glTranslatef(60,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-60);
        glVertex2f(120,-60);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();

   // glTranslatef(99,-165,0);
    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();


    //drawSquare(13);



     glPushMatrix();
    glTranslatef(80,3,0);

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,150);
        glVertex2f(115,150);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,50);
        glVertex2f(120,50);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();

   // glTranslatef(99,-165,0);


    glPopMatrix();





}
void obstacle2()
{

    glPushMatrix();
    glTranslatef(360,3,0);

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,155);
        glVertex2f(115,155);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,20);
        glVertex2f(120,20);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();

   // glTranslatef(99,-165,0);


    glPopMatrix();









    glPushMatrix();
    glTranslatef(170,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-20);
        glVertex2f(120,-20);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();

   // glTranslatef(-100,-165,0);
    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();


    //drawSquare(13);


     glPushMatrix();
    glTranslatef(300,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-60);
        glVertex2f(120,-60);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();

    //glTranslatef(-100,-165,0);
    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();


    //drawSquare(13);



     glPushMatrix();
    glTranslatef(280,3,0);

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,150);
        glVertex2f(115,150);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,50);
        glVertex2f(120,50);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();

   // glTranslatef(99,-165,0);


    glPopMatrix();



}
void obstacle3()
{

    glPushMatrix();
    glTranslatef(440,3,0);

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,155);
        glVertex2f(115,155);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,20);
        glVertex2f(120,20);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();

   // glTranslatef(99,-165,0);


    glPopMatrix();









    glPushMatrix();
    glTranslatef(340,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-20);
        glVertex2f(120,-20);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();

   // glTranslatef(-100,-165,0);
    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();


    //drawSquare(13);


     glPushMatrix();
    glTranslatef(490,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-60);
        glVertex2f(120,-60);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();

    //glTranslatef(-100,-165,0);
    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();















    glPopMatrix();

    glPopMatrix();


    //drawSquare(13);



     glPushMatrix();
    glTranslatef(210,3,0);

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,150);
        glVertex2f(115,150);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,50);
        glVertex2f(120,50);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();

   // glTranslatef(99,-165,0);


    glPopMatrix();






}
void obstacle4()
{
    glPushMatrix();
    //glTranslatef(20,3,0);

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,155);
        glVertex2f(115,155);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,20);
        glVertex2f(120,20);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();

   // glTranslatef(99,-165,0);


    glPopMatrix();









    glPushMatrix();
    glTranslatef(-20,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-20);
        glVertex2f(120,-20);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();

   // glTranslatef(99,-165,0);
    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();


    //drawSquare(13);


     glPushMatrix();
    glTranslatef(60,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-60);
        glVertex2f(120,-60);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();

   // glTranslatef(99,-165,0);
    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();


    //drawSquare(13);



     glPushMatrix();
    glTranslatef(80,3,0);

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,150);
        glVertex2f(115,150);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

 glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,50);
        glVertex2f(120,50);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();

   // glTranslatef(99,-165,0);


    glPopMatrix();


}
void drawSS()
{
    glColor3f(1,0,0);
    drawSquare(20);
    glPushMatrix();
    //glRotatef(angle,0,0,1);
    glTranslatef(110,0,0);
    //glRotatef(2*angle,0,0,1);
    glColor3f(0,1,0);
    drawSquare(15);
    //glPopMatrix();if(state ==2) incx-=0.1;
    glPushMatrix();
    {
//        glRotatef(angle,0,0,1);
        glTranslatef(60,0,0);
       // glRotatef(2*angle,0,0,1);
        glColor3f(0,0,1);
        drawSquare(10);
    }
    glPopMatrix();

}
void lip()
{
    glBegin(GL_TRIANGLES);
    {
        glColor3f(1,0,0);
        glVertex3f(-1,16,0);
        glVertex3f(6,16,0);
        glVertex3f(-1,9,0);

    }
    glEnd();

    glBegin(GL_TRIANGLES);
    {
        glColor3f(1,0,0);
        glVertex3f(0,28,0);
        glVertex3f(8,17,0);
        glVertex3f(0,17,0);

    }
    glEnd();

}


void draw_bird_body()
{



    //int angle=45;
    glPushMatrix();
    glTranslatef(tx3,ty3,0);

    glPushMatrix();
    glPushMatrix();
    glTranslatef(tx4,ty4,0);
    glRotatef(-290,10,30,0);
    //glScalef(-1,1,0);
    draw_tail();
    glPopMatrix();


    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-4,25,0);
    circle2();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-4,25,0);
    circle1();
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0,0);
    glTranslatef(-10,20,0);
    drawCircle(15,20);
    glPopMatrix();
    glPushMatrix();
    lip();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-24,22,0);
    //glTranslatef(tx4,ty4,0);
    glRotatef(180,10,30,0);
    draw_tail();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-22,15,0);
    glRotatef(2*190,10,30,0);
    draw_tail();
    glPopMatrix();



    glPopMatrix();




}

void keyboardListener(unsigned char key, int x,int y){
	switch(key){

		case 32:
			//drawgrid=1-drawgrid;
			//glutIdleFunc(continuous1);
            glutIdleFunc(continuous);
            //glutIdleFunc(animate);
			break;

		default:
			break;
	}
}


void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN:
		    //ty3-=5;
		    ty7-=5;

		    // inc_ang-=0.01;	//down arrow key
			cameraHeight -= 3.0;
			break;
		case GLUT_KEY_UP:
		    ty7+=5;

		    //ty3+=5;
		    //inc_ang+=0.01;		// up arrow key
			cameraHeight += 3.0;

			break;

		case GLUT_KEY_RIGHT:
		    tx3+=5;
		    //ty4+=2;

		    // tx+=1
          //  glutIdleFunc(continuous1);
          //  glutIdleFunc(continuous);



            //glutPostRedisplay();
            //glutPostRedisplay();
		    //continuous();
           // glutPostRedisplay();

			//cameraAngle += 0.03;
			break;

		case GLUT_KEY_LEFT:
		    tx3-=5;
			cameraAngle -= 0.03;
			break;

		case GLUT_KEY_PAGE_UP:
			break;
		case GLUT_KEY_PAGE_DOWN:
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
			break;
		case GLUT_KEY_END:
			break;
        case 32:
            glutIdleFunc(continuous);
            break;

		default:
			break;
	}
}






void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN){		// 2 times?? in ONE click? -- solution is checking DOWN or UP
				drawaxes=1-drawaxes;
			}
			break;

		case GLUT_RIGHT_BUTTON:
			//........
			break;

		case GLUT_MIDDLE_BUTTON:
			//........
			break;

		default:
			break;
	}
}

void draw_text1(const char *text,int length,int x,int y)
{
    glMatrixMode(GL_PROJECTION);
    double *matrix=new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX,matrix);
    glLoadIdentity();
    glOrtho(-400,500,-200,300,-5,5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x,y);
    for(int i=0;text[i]!='\0';i++)
 {
     // setFont(GLUT_BITMAP_HELVETICA_18);
     // glutBitmapCharacter(GLUT_BITMAP_9_BY_15,(int)text[i]);
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,(int)text[i]);




 }

   glPopMatrix();
   glMatrixMode(GL_PROJECTION);
   glLoadMatrixd(matrix);
   glMatrixMode(GL_MODELVIEW);

}

void coliision()
{

    glPushMatrix();
   // glTranslatef(-20,10,0);
    glColor3f(1,1,1);
    draw_text1(text3,100,-20,80);
    glPopMatrix();
    glPushMatrix();
   // glTranslatef(-20,10,0);
    glColor3f(1,1,1);
    draw_text1(sc,100,-20,60);
    draw_text1(msg,100,35,60);
    glPopMatrix();


         glPushMatrix();
         glColor3f(0,0,0);
         glBegin(GL_QUADS);
         glVertex2f(-175,180);
         glVertex2f(-175,-180);
         glVertex2f(175,-180);
         glVertex2f(175,180);
         glEnd();
         glPopMatrix();



}


void firstpage()

{
    int num = 10;
    itoa(score,msg,10);//converting score into string

     if(stop==1)//when piller will touch
     {

         return coliision();
     }
   //printf("ty7=%f,tx5=%f\n",ty7,tx5);


     if(ty7>=-10&&(tx5<=-173&&tx5>=-200))
     {
         stop=1;
     }
     if(ty7<=-25&&(tx5<=-151&&tx5>=-176))
     {
         stop=1;
     }
     if(ty7<=-63&&(tx5<=-230&&tx5>=-254))
     {
        stop=1;
     }
     if(ty7>=10&&(tx5<=-250&&tx5>=-274))
     {
         stop=1;
     }
     if(ty7<=-25&&(tx5<=-338&&tx5>=-374))
     {
        stop=1;
     }
     if(ty7>=20&&(tx5<=-382&&tx5>=-400))
     {
         stop=1;
     }
     if(ty7<=-65&&(tx5<=-472&&tx5>=-488))
     {
         stop=1;
     }
     if(ty7<=-20&&(tx5<=-512&&tx5>=-532))
     {
         stop=1;
     }
     if(ty7<=-65&&(tx5<=-660&&tx5>=-680))
     {
         stop=1;
     }
     if(ty7>=-6&&(tx5<=-529&&tx5>=-540))
     {
         stop=1;
     }
     if(ty7>=-13&&(tx5<=-611&&tx5>=-628))
     {
         stop=1;
     }
     if(ty7>=-20&&(tx5<=-380&&tx5>=-400))
     {
         //stop=1;
     }
     if(ty7>=-10&&(tx5<=-450&&tx5>=-470))
     {
         stop=1;
     }











    glPushMatrix();

    glPushMatrix();
     glTranslatef(tx7,ty7,0);
	 draw_bird_body();
	 glPopMatrix();



	  glColor3f(1,1,0);
    draw_text1(msg,100,-320,250);
    draw_text1(sc,100,-380,250);




    glPushMatrix();
    glColor3f(1,1,0);
    draw_text1(text2,100,tx2,ty2);
    glPopMatrix();
    glPushMatrix();

    glColor3f(1,1,0);
    draw_text1(text1,100,tx1,ty1);
    glPopMatrix();
     glPushMatrix();
    glColor3f(1,1,0);
	draw_text1(text,100,tx,ty);
	glPopMatrix();


	glPopMatrix();
	glPushMatrix();
	score=score+.1;
	//printf("score=%lf\n",score);
	glTranslatef(tx5,ty5,0);
	obstacle1();
	obstacle2();
	obstacle3();
    glPopMatrix();



	 //obs();




	 glPushMatrix(); //clouds
            glTranslated(clx1,cly1,0);
            glColor3d(0.91,0.91,0.91);
            glTranslated(0,70,0);
            circle(5,10);
            glTranslated(5,4,0);
            circle(5,10);
            glTranslated(5,-4,0);
            circle(5,10);
            glTranslated(-5,-4,0);
            circle(5,10);

            glTranslated(30,0,0);
            circle(10,10);
            glTranslated(5,4,0);
            circle(5,10);
            glTranslated(5,-4,0);
            circle(10,10);
            glTranslated(-5,-4,0);
            circle(5,10);

            glTranslated(-100,10,0);
            circle(8,10);
            glTranslated(-5,4,0);
            circle(5,10);
            glTranslated(0,-8,0);
            circle(5,10);
            glTranslated(-5,4,0);
            circle(8,10);
        glPopMatrix();

            glEnd();




}



void display(){


     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glClearColor(0.52940,0.80780,0.9800,0);

     	//color black
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//clear the display


	//load the cor inc_ang+=0.01;rect matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();




	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera looking?
	//3. Which direction is the camera's UP direction?

	//gluLookAt(100,100,100,	0,0,0,	0,0,1);
	//gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	gluLookAt(0,0,200,	0,0,0,	0,1,0);


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	firstpage();




	//ADD this lglTranslatef(-40, 0, 0);ine in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}



void init(){
	//codes for initialization
	drawgrid=0;
	drawaxes=1;
	cameraHeight=150.0;
	cameraAngle=1.0;
	angle=45;

	//clear the screen


    glClearColor(0,0,0,0);


	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(80,	1,	1,	1000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
}


int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(-500, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("Flappy bird");

	init();


	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
		//what you want to do in the idle time (when no drawing is occuring)

	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);
	glutMouseFunc(mouseListener);
//    glutTimerFunc(1000,MyTimerFunc,0);


	glutMainLoop();		//The main loop of OpenGL

	return 0;
}




