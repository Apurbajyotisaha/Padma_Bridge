#include <windows.h>
#include<math.h>
#include <cstdlib>
# define PI 3.1416
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;



float run = 0.0;
float run2 = 0.0;
float run3 = 0.0;
float tri = 0.0;
float bt = 0.0;

bool frd = false;
bool bck = false;
bool onOff;

bool B_frd = false;
bool B_bck = false;
bool B_onOff;

void carbackward (int value){

    if(bck) {

        tri -= 2.2f;

        if (tri < -350)
            {
            tri = 1100;
            }

        glutPostRedisplay();
        glutTimerFunc(25, carbackward, 0);

            }
}


void carforward (int value ) {

    if (frd) {

        tri += 2.2f;

        if(tri > 1000)
        {

            tri -= 1400;
        }

        glutPostRedisplay();
        glutTimerFunc(25, carforward, 0);

    }

}

void boatbackward (int value){

    if(B_bck) {

        bt -= 2.2f;

        if (bt < -350)
            {
            bt = 1100;
            }

        glutPostRedisplay();
        glutTimerFunc(25, boatbackward, 0);

            }
}

void boatforward (int value ) {

    if (B_frd) {

        bt += 2.2f;

        if(bt > 1000)
        {

            bt -= 1400;
        }

        glutPostRedisplay();
        glutTimerFunc(25, boatforward, 0);

    }

}


void update (int value)
{

    run += 1.5f;
    if (run > 1300)
    {
        run -= 1700;
    }

    run2 += 4.5f;
    if (run2 > 1300)
    {
        run2 -= 1700;
    }

    run3 += 3.0f;
    if (run3 > 1300)
    {
        run3 -= 1700;
    }

    if (onOff)
    {
        tri += 2.5f;

        if (tri > 1600)
        {

            tri = 1300;
        }
    }

    if (B_onOff)
    {
        bt += 2.5f;

        if (bt > 1600)
        {

            bt = 1300;
        }

    }

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);

}

//ALAMIN
void sun()
{
   //Sun //Sun//Sun//Sun//Sun//Sun//Sun
    GLfloat x=1200; GLfloat y=1800;GLfloat radius =50;
    int triangleAmount = 20; //# of triangles used to draw circle# of triangles used to draw circle# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(249,215,28);
        glVertex2f(x, y); // center of circle
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}

void myKeyboard (unsigned char key, int x, int y) {

    switch (key)
    {
    case 'a':
        frd = false;
        bck = true;
        carbackward (tri);
        break;


    case 'd':
        frd = true;
        bck = false;
        carforward (tri);
        break;

    case 's':
        frd = false;
        bck = false;
        break;

    case 'z':
        B_frd = false;
        B_bck = true;
        boatbackward (bt);
        break;


    case 'c':
        B_frd = true;
        B_bck = false;
        boatforward (bt);
        break;

    case 'x':
        B_frd = false;
        B_bck = false;
        break;

    default:
    break;

    }

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);


    //RIVER

    glBegin(GL_POLYGON);
    glColor3f(0.2,0.2,1.0);
    glVertex2i(0,0);
    glVertex2i(0,720);
    glVertex2i(1400,720);
    glVertex2i(1400,0);
    glEnd();

    // SKY

    glBegin(GL_POLYGON);
    glColor3f(0.2,0.8,1.0);
    glVertex2i(0,1340);
    glVertex2i(0,2000);
    glVertex2i(1400,2000);
    glVertex2i(1400,1340);
    glEnd();

    ////scenario

    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,1.0);
    glVertex2f(0, 1340);
    glVertex2f(1400, 1340);
    glVertex2f(1400, 1400);
    glVertex2f(0, 1400);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,1.0);
    glVertex2f(0, 1340);
    glVertex2f(1400, 1340);
    glVertex2f(1400, 1400);
    glVertex2f(0, 1400);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2,0.8,0.0);
    glVertex2f(0, 1480);
    glVertex2f(1400, 1480);
    glVertex2f(1400, 1400);
    glVertex2f(0, 1400);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8,0.3,0.0);
    glVertex2f(200,1600);
    glVertex2f(340,1540);
    glVertex2f(60,1540);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8,0.8,0.1);
    glVertex2f(100,1440);
    glVertex2f(300,1440);
    glVertex2f(300,1540);
    glVertex2f(100,1540);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.8,0.3,0.0);
    glVertex2f(1100,1600);
    glVertex2f(1240,1540);
    glVertex2f(960,1540);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.8,0.8,0.1);
    glVertex2f(1000,1440);
    glVertex2f(1200,1440);
    glVertex2f(1200,1540);
    glVertex2f(1000,1540);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.5,0.2);
    glVertex2f(280,1600);
    glVertex2f(400,1760);
    glVertex2f(520,1600);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.4,0.1,0.0);
    glVertex2f(400,1440);
    glVertex2f(420,1440);
    glVertex2f(420,1600);
    glVertex2f(400,1600);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.5,0.2);
    glVertex2f(540,1600);
    glVertex2f(620,1740);
    glVertex2f(700,1600);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.4,0.1,0.0);
    glVertex2f(620,1460);
    glVertex2f(640,1460);
    glVertex2f(640,1600);
    glVertex2f(620,1600);
    glEnd();

    //Alamin sun
    sun();

//////Bird

    glPushMatrix();
    glTranslatef(run3, 0.0, 0.0);

    glBegin(GL_TRIANGLES);
    glColor3f(0.7,0.0,0.0);
    glVertex2f(80,1900);
    glVertex2f(100,1850);
    glVertex2f(80,1800);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8,1.0,0.0);
    glVertex2f(100,1850);
    glVertex2f(125,1900);
    glVertex2f(125,1800);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8,1.0,0.0);
    glVertex2f(175,1900);
    glVertex2f(200,1850);
    glVertex2f(175,1800);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.7,0.0,0.2);
    glVertex2f(200,1865);
    glVertex2f(210,1850);
    glVertex2f(200,1835);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8,1.0,0.0);
    glVertex2f(125,1900);
    glVertex2f(175,1900);
    glVertex2f(175,1800);
    glVertex2f(125,1800);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.7,0.0,0.2);
    glVertex2f(150,1850);
    glVertex2f(130,1780);
    glVertex2f(170,1780);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.7,0.0,0.0);
    glVertex2f(230,1900);
    glVertex2f(250,1850);
    glVertex2f(230,1800);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8,1.0,0.0);
    glVertex2f(250,1850);
    glVertex2f(275,1900);
    glVertex2f(275,1800);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.8,1.0,0.0);
    glVertex2f(325,1900);
    glVertex2f(350,1850);
    glVertex2f(325,1800);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.7,0.0,0.2);
    glVertex2f(350,1865);
    glVertex2f(360,1850);
    glVertex2f(350,1835);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8,1.0,0.0);
    glVertex2f(275,1900);
    glVertex2f(325,1900);
    glVertex2f(325,1800);
    glVertex2f(275,1800);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.7,0.0,0.2);
    glVertex2f(300,1850);
    glVertex2f(280,1780);
    glVertex2f(320,1780);
    glEnd();

    glPopMatrix();

    //ALAMIN
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.4,0.0);
    glVertex2f(780,1440);
    glVertex2f(800,1440);
    glVertex2f(800,1760);
    glVertex2f(780,1760);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0,0.5,0.2);
    glVertex2f(680,1660);
    glVertex2f(800,1820);
    glVertex2f(920,1660);
    glEnd();

     glBegin(GL_TRIANGLES);
    glColor3ub(0, 125, 0);
    glVertex2f(640,1720);
    glVertex2f(800,1860);
    glVertex2f(940,1720);
    glEnd();

    //RAIL LINE 1st box
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
    glVertex2i(0,720);
    glVertex2i(0,760);
    glVertex2i(1400,760);
    glVertex2i(1400,720);
    glEnd();

    //RAIL LINE 1st box
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
    glVertex2i(0,860);
    glVertex2i(0,900);
    glVertex2i(1400,900);
    glVertex2i(1400,860);
    glEnd();

    //rail line

    glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
    glVertex2i(0,1300);
    glVertex2i(0,1340);
    glVertex2i(1400,1340);
    glVertex2i(1400,1300);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
    glVertex2i(0,1300);
    glVertex2i(0,1340);
    glVertex2i(1400,1340);
    glVertex2i(1400,1300);
    glEnd();




    //road
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.2);
    glVertex2i(0,900);
    glVertex2i(0,1300);
    glVertex2i(1400,1300);
    glVertex2i(1400,900);
    glEnd();

    //road design
    glBegin(GL_POLYGON);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2i(100,1100);
    glVertex2i(100,1060);
    glVertex2i(300,1060);
    glVertex2i(300,1100);
    glEnd();

    glBegin(GL_POLYGON);//road design
    glColor3f(0.9, 0.9, 0.9);
    glVertex2i(400,1100);
    glVertex2i(400,1060);
    glVertex2i(600,1060);
    glVertex2i(600,1100);
    glEnd();

    glBegin(GL_POLYGON);//road design
    glColor3f(0.9, 0.9, 0.9);
    glVertex2i(700,1100);
    glVertex2i(700,1060);
    glVertex2i(900,1060);
    glVertex2i(900,1100);
    glEnd();

    glBegin(GL_POLYGON);//road design
    glColor3f(0.9, 0.9, 0.9);
    glVertex2i(1000,1100);
    glVertex2i(1000,1060);
    glVertex2i(1200,1060);
    glVertex2i(1200,1100);
    glEnd();

    //Nafiz CAR


    glPushMatrix();

    glTranslatef(tri, 0.0, 0.0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.5, 0.5);
    glVertex2i(60,980);
    glVertex2i(60,1040);
    glVertex2i(460,1040);
    glVertex2i(460,980);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 1.0, 0.5);
    glVertex2i(60,1040);
    glVertex2i(460,1040);
    glVertex2i(460,1180);
    glVertex2i(60,1180);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 1.0);
    glVertex2i(60,1180);
    glVertex2i(460,1180);
    glVertex2i(500,1200);
    glVertex2i(100,1200);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 1.0);
    glVertex2i(460,1180);
    glVertex2i(500,1200);
    glVertex2i(500,1000);
    glVertex2i(460,980);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2i(140,960);
    glVertex2i(160,960);
    glVertex2i(180,980);
    glVertex2i(180,1000);
    glVertex2i(160,1020);
    glVertex2i(140,1020);
    glVertex2i(120,1000);
     glVertex2i(120,980);
    glEnd();

    //2nd tire
     glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2i(340,980);
    glVertex2i(360,960);
     glVertex2i(380,960);
    glVertex2i(400,980);
    glVertex2i(400,1000);
    glVertex2i(380,1020);
    glVertex2i(360,1020);
    glVertex2i(340,1000);
     glVertex2i(340,980);
    glEnd();

    //front window
     glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);

    glVertex2i(460,1020);
    glVertex2i(500,1040);
    glVertex2i(500,1200);
     glVertex2i(460,1180);
    glEnd();

    glPopMatrix();



    //AAM BOAT 2 Auto

    glPushMatrix();

    glTranslatef(run, 0.0, 0.0);

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(240,440);
    glVertex2i(300,400);
    glVertex2i(460,400);
    glVertex2i(520,440);
    glVertex2i(460,420);
    glVertex2i(300,420);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.4, 0.2);
    glVertex2i(240,440);
    glVertex2i(300,420);
    glVertex2i(460,420);
    glVertex2i(520,440);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.0, 0.0);
    glVertex2i(400,420);
    glVertex2i(420,540);
    glVertex2i(340,580);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2i(400,420);
    glVertex2i(400,560);
    glEnd();

    glPopMatrix();

    //AAM BOAT 3 AUTO

    glPushMatrix();

    glTranslatef(run, 0.0, 0.0);

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(740,440);
    glVertex2i(800,400);
    glVertex2i(960,400);
    glVertex2i(1020,440);
    glVertex2i(960,420);
    glVertex2i(800,420);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.4, 0.2);
    glVertex2i(740,440);
    glVertex2i(800,420);
    glVertex2i(960,420);
    glVertex2i(1020,440);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.8, 0.6);
    glVertex2i(800,420);
    glVertex2i(900,420);
    glVertex2i(920,480);
    glVertex2i(840,480);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.2, 0.0);
    glVertex2i(900,420);
    glVertex2i(940,440);
    glVertex2i(920,480);
    glEnd();

    glPopMatrix();



    //1st pillar
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
     glVertex2i(100,720);
    glVertex2i(120,640);
    glVertex2i(220,640);
     glVertex2i(240,720);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
     glVertex2i(120,640);
    glVertex2i(220,640);
    glVertex2i(220,420);
     glVertex2i(120,420);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
     glVertex2i(120,420);
    glVertex2i(220,420);
    glVertex2i(240,340);
     glVertex2i(100,340);
    glEnd();

    //pillar bottom design
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
     glVertex2i(100,360);
    glVertex2i(240,360);
    glVertex2i(260,340);
    glVertex2i(240,320);
     glVertex2i(100,320);
     glVertex2i(80,340);
    glEnd();

     glBegin(GL_POLYGON);//1 st pillar bottom design
    glColor3f(0.7,0.7,0.7);
     glVertex2i(100,320);
    glVertex2i(240,320);
    glVertex2i(260,340);
    glVertex2i(260,320);
     glVertex2i(240,300);
     glVertex2i(100,300);
     glVertex2i(80,320);
      glVertex2i(80,340);
    glEnd();

    //2nd pillar
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
     glVertex2i(580,720);
    glVertex2i(600,640);
    glVertex2i(700,640);
     glVertex2i(720,720);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
     glVertex2i(600,640);
    glVertex2i(700,640);
    glVertex2i(700,420);
     glVertex2i(600,420);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
     glVertex2i(600,420);
    glVertex2i(700,420);
    glVertex2i(720,340);
     glVertex2i(580,340);
    glEnd();


    glBegin(GL_POLYGON);//2nd  pillar bottom design
    glColor3f(0.7,0.7,0.7);
     glVertex2i(580,320);
    glVertex2i(720,320);
    glVertex2i(740,340);
    glVertex2i(720,360);
     glVertex2i(580,360);
     glVertex2i(560,340);

    glEnd();

     glBegin(GL_POLYGON);// 2nd pillar last bottom design
    glColor3f(0.7,0.7,0.7);
     glVertex2i(580,320);
    glVertex2i(720,320);
    glVertex2i(740,340);
    glVertex2i(740,320);
     glVertex2i(720,300);
     glVertex2i(580,300);
     glVertex2i(560,320);
      glVertex2i(560,340);
    glEnd();


    //3rd pillar
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
     glVertex2i(1060,720);
    glVertex2i(1080,640);
    glVertex2i(1180,640);
     glVertex2i(1200,720);
    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
     glVertex2i(1080,640);
    glVertex2i(1180,640);
    glVertex2i(1180,420);
     glVertex2i(1080,420);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7,0.7,0.7);
     glVertex2i(1080,420);
    glVertex2i(1180,420);
    glVertex2i(1200,340);
     glVertex2i(1060,340);
    glEnd();


      glBegin(GL_POLYGON);//3rd pillar bottom design
    glColor3f(0.7,0.7,0.7);
     glVertex2i(1060,320);
    glVertex2i(1200,320);
    glVertex2i(1220,340);
    glVertex2i(1200,360);
     glVertex2i(1060,360);
     glVertex2i(1040,340);

    glEnd();

    glBegin(GL_POLYGON);// 3rd pillar last bottom design
    glColor3f(0.7,0.7,0.7);
     glVertex2i(1060,320);
    glVertex2i(1200,320);
    glVertex2i(1220,340);
    glVertex2i(1220,320);
     glVertex2i(1200,300);
     glVertex2i(1060,300);
     glVertex2i(1040,320);
      glVertex2i(1040,340);
    glEnd();


     glBegin(GL_POLYGON);// RAIL LINE
    glColor3f(0.7,0.7,0.7);
     glVertex2i(0,760);
    glVertex2i(100,865);
    glVertex2i(100,820);
    glVertex2i(40,760);

    glEnd();

    glBegin(GL_POLYGON);// RAIL LINE
    glColor3f(0.7,0.7,0.7);
     glVertex2i(100,865);
    glVertex2i(100,820);
    glVertex2i(160,760);
    glVertex2i(200,760);

    glEnd();



    glBegin(GL_POLYGON);// RAIL LINE
    glColor3f(0.7,0.7,0.7);
     glVertex2i(300,865);
    glVertex2i(300,820);
    glVertex2i(240,760);
    glVertex2i(200,760);

    glEnd();

    glBegin(GL_POLYGON);// RAIL LINE
    glColor3f(0.7,0.7,0.7);
     glVertex2i(300,865);
    glVertex2i(300,820);
    glVertex2i(360,760);
    glVertex2i(400,760);

    glEnd();

    glBegin(GL_POLYGON);// RAIL LINE
    glColor3f(0.7,0.7,0.7);
     glVertex2i(500,865);
    glVertex2i(500,820);
    glVertex2i(440,760);
    glVertex2i(400,760);

    glEnd();

     glBegin(GL_POLYGON);// RAIL LINE
    glColor3f(0.7,0.7,0.7);
     glVertex2i(500,865);
    glVertex2i(500,820);
    glVertex2i(560,760);
    glVertex2i(600,760);

    glEnd();

     glBegin(GL_POLYGON);// RAIL LINE
    glColor3f(0.7,0.7,0.7);
     glVertex2i(700,865);
    glVertex2i(700,820);
    glVertex2i(640,760);
    glVertex2i(600,760);

    glEnd();

     glBegin(GL_POLYGON);// RAIL LINE
    glColor3f(0.7,0.7,0.7);
     glVertex2i(700,865);
    glVertex2i(700,820);
    glVertex2i(760,760);
    glVertex2i(800,760);

    glEnd();


    glBegin(GL_POLYGON);// RAIL LINE
    glColor3f(0.7,0.7,0.7);
     glVertex2i(900,865);
    glVertex2i(900,820);
    glVertex2i(840,760);
    glVertex2i(800,760);

    glEnd();

    glBegin(GL_POLYGON);// RAIL LINE
    glColor3f(0.7,0.7,0.7);
     glVertex2i(900,865);
    glVertex2i(900,820);
    glVertex2i(960,760);
    glVertex2i(1000,760);

    glEnd();

     glBegin(GL_POLYGON);// RAIL LINE
    glColor3f(0.7,0.7,0.7);
     glVertex2i(1100,865);
    glVertex2i(1100,820);
    glVertex2i(1040,760);
    glVertex2i(1000,760);

    glEnd();

     glBegin(GL_POLYGON);// RAIL LINE
    glColor3f(0.7,0.7,0.7);
    glVertex2i(1100,865);
    glVertex2i(1100,820);
    glVertex2i(1160,760);
    glVertex2i(1200,760);

    glEnd();

    glBegin(GL_POLYGON);// RAIL LINE
    glColor3f(0.7,0.7,0.7);
    glVertex2i(1300,865);
    glVertex2i(1300,820);
    glVertex2i(1240,760);
    glVertex2i(1200,760);

    glEnd();


    glBegin(GL_POLYGON);// RAIL LINE
    glColor3f(0.7,0.7,0.7);
    glVertex2i(1300,865);
    glVertex2i(1300,820);
    glVertex2i(1360,760);
    glVertex2i(1400,760);

    glEnd();

    //AAM BOAT

    glPushMatrix();

    glTranslatef(bt, 0.0, 0.0);

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(200,140);
    glVertex2i(300,100);
    glVertex2i(500,100);
    glVertex2i(600,140);
    glVertex2i(500,120);
    glVertex2i(300,120);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.4, 0.2);
    glVertex2i(200,140);
    glVertex2i(300,120);
    glVertex2i(500,120);
    glVertex2i(600,140);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.0, 0.0);
    glVertex2i(320,120);
    glVertex2i(440,120);
    glVertex2i(460,180);
    glVertex2i(360,180);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.2, 0.0);
    glVertex2i(440,120);
    glVertex2i(480,140);
    glVertex2i(460,180);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.5, 1.0);
    glVertex2i(480,120);
    glVertex2i(500,300);
    glVertex2i(400,360);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(480,309);
    glVertex2i(480,340);
    glVertex2i(485,340);
    glVertex2i(485,309);
    glEnd();

    glPopMatrix();

    //Helicopter
    glPushMatrix();
    glTranslatef(run2, 0.0, 0.0);

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.3, 0.0);

    glVertex2i(20,850);
    glVertex2i(30,820);
    glVertex2i(100,820);
    glVertex2i(110,800);
    glVertex2i(200,800);
    glVertex2i(200,815);
    glVertex2i(190,830);
    glVertex2i(180,830);
    glVertex2i(170,860);
    glVertex2i(155,860);
    glVertex2i(150,870);
    glVertex2i(135,860);
    glVertex2i(115,860);
    glVertex2i(100,825);
    glVertex2i(30,850);
    glEnd();


    glColor3ub(225, 19, 14);
    glBegin(GL_TRIANGLES);
    glVertex2i(200,800);
    glVertex2i(200,815);
    glVertex2i(215,808);
    glEnd();

     glPushMatrix();
     glTranslatef(28, 850, 0);

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
     glTranslatef(28, 850, 0);

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=16;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(200,800);
    glVertex2i(200,815);
    glVertex2i(215,808);
    glEnd();

     glPushMatrix();
     glTranslatef(142, 870, 0);

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=30;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(142, 870, 0);

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=29;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130, 790, 0);

    glBegin(GL_POLYGON);
    glColor3ub(44, 42, 45);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(165, 790, 0);

    glBegin(GL_POLYGON);
    glColor3ub(44, 42, 45);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/200;
		float r=8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
    glPopMatrix();

    glFlush();

}



void init(void)
{
    glClearColor(0.5,0.4,0.5,0.0);//water color glClearColor(0.0,0.3,0.4,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1400.0,0.0,2000.0,-10.0,10.0);
}

int main(int argc, char** argv)
{
    cout << endl << "*********** Padma Bridge ********************" << endl << endl;

    cout << "Press D : To Forward the Bus" << endl << endl;
    cout << "Press A : To Backward the Bus" << endl << endl;
    cout << "Press S : To Stop the Bus" << endl << endl;

    cout << endl;

    cout << "Press C : To Forward the Boat" << endl << endl;
    cout << "Press Z : To Backward the Boat" << endl << endl;
    cout << "Press X : To Stop the Boat" << endl << endl;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
    glutInitWindowSize(1300,750);
    glutInitWindowPosition(100,50);
    glutCreateWindow("Practice");
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);
    glutTimerFunc(25, update, 0);
    init();
    glutMainLoop();
    return 0;
}
