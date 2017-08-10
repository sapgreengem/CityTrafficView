#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include "imageloader.h"
using namespace std;

GLuint roadTexture;
GLuint foothpathTexture;
GLuint grassTexture;

GLuint foothpathThicknessTexture;


int r = 25;// car wheel radious
double xCenter = 0, yCenter = 0, xCenter1=0; //car wheel circle position
double xSunCenter = 0, ySunCenter = 0;// sun circle

double Car1X = 0, Car1Y = 0, Car1Z = 0;// car1 position
double Car2X = 0, Car2Y = 0, Car2Z = 0;// car2 position

static int flag = 1;// flag for car color change and reset
static int flag1 = 1;// flag for sun get down

float a = 0, b = 0, c = 255, d = 255, e = 0, f = 0;// car color changing variable

float bcR=0, bcG = 0, bcB = 0;//Background color variable

float sunR = 1.0, sunG = 0.2, sunB = 0.0;// initial sun color

float redR = 0.0, redG = 0.0, redB = 0.0;//traffic signal red light variable
float yellowR = 0.0, yellowG = 0.0, yellowB = 0.0;//traffic signal yellow light variable
float greenR = 0.0, greenG = 1.0, greenB = 0;//traffic signal green light variable

float windowR=0.0, windowG=0.0, windowB=0.0;// door and window color variable


void building()// drawing the buildings
{
	// Staart og buiding 1 ---------------------------------------------------
	glColor3ub(68, 68, 68);
	glBegin(GL_POLYGON); // Building 1 Left Side
	glVertex2i(70, 240 + 10);
	glVertex2i(100, 220);
	glVertex2i(100, 600);
	glVertex2i(70, 630);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 1 Left Side
	glVertex2i(70, 240 + 10);
	glVertex2i(100, 220);
	glVertex2i(100, 600);
	glVertex2i(70, 630);
	glEnd();

	glColor3ub(118, 118, 118);
	glBegin(GL_POLYGON); // Building 1 Front Side
	glVertex2i(100, 220);
	glVertex2i(350, 220);
	glVertex2i(350, 600);
	glVertex2i(100, 600);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 1 Front Side
	glVertex2i(100, 220);
	glVertex2i(350, 220);
	glVertex2i(350, 600);
	glVertex2i(100, 600);
	glEnd();

	glColor3ub(99, 99, 99);
	glBegin(GL_POLYGON); // Building 1 Roof Front \/ bottom
	glVertex2i(100, 600);
	glVertex2i(360, 600);
	glVertex2i(360, 620);
	glVertex2i(100, 620);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 1 Roof Front \/ bottom
	glVertex2i(100, 600);
	glVertex2i(360, 600);
	glVertex2i(360, 620);
	glVertex2i(100, 620);
	glEnd();

	glColor3ub(99, 99, 99);
	glBegin(GL_POLYGON); // Building 1 Roof left
	glVertex2i(60, 640);
	glVertex2i(100, 600);
	glVertex2i(100, 620);
	glVertex2i(60, 660);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 1 Roof left
	glVertex2i(60, 640);
	glVertex2i(100, 600);
	glVertex2i(100, 620);
	glVertex2i(60, 660);
	glEnd();

	glColor3ub(99, 99, 99);
	glBegin(GL_POLYGON); // Building 1 Roof Front /\ up
	glVertex2i(80, 640);
	glVertex2i(320, 640);
	glVertex2i(320, 660);
	glVertex2i(60, 660);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 1 Roof Front /\ up
	glVertex2i(80, 640);
	glVertex2i(320, 640);
	glVertex2i(320, 660);
	glVertex2i(60, 660);
	glEnd();

	glColor3ub(99, 99, 99);
	glBegin(GL_POLYGON); // Building 1 Roof right
	glVertex2i(320, 640);
	glVertex2i(340, 620);
	glVertex2i(360, 620);
	glVertex2i(320, 660);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 1 Roof right
	glVertex2i(320, 640);
	glVertex2i(340, 620);
	glVertex2i(360, 620);
	glVertex2i(320, 660);
	glEnd();

	glColor3ub(118, 118, 118);
	glBegin(GL_POLYGON); // Building 1 Roof floor _____
	glVertex2i(80, 640);
	glVertex2i(100, 620);
	glVertex2i(340, 620);
	glVertex2i(320, 640);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 1 Roof floor _____
	glVertex2i(80, 640);
	glVertex2i(100, 620);
	glVertex2i(340, 620);
	glVertex2i(320, 640);
	glEnd();

	// Start of buiding 2 ---------------------------------------------------
	glColor3ub(68, 68, 68);
	glBegin(GL_POLYGON); // Building 2 Left Side
	glVertex2i(70 + 550, 240 + 10);
	glVertex2i(100 + 550, 220);
	glVertex2i(100 + 550, 600 - 30);
	glVertex2i(70 + 550, 630 - 30);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 2 Left Side
	glVertex2i(70 + 550, 240 + 10);
	glVertex2i(100 + 550, 220);
	glVertex2i(100 + 550, 600 - 30);
	glVertex2i(70 + 550, 630 - 30);
	glEnd();

	glColor3ub(118, 118, 118);
	glBegin(GL_POLYGON); // Building 2 Front Side
	glVertex2i(100 + 550, 220);
	glVertex2i(350 + 550, 220);
	glVertex2i(350 + 550, 600 - 30);
	glVertex2i(100 + 550, 600 - 30);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 2 Front Side
	glVertex2i(100 + 550, 220);
	glVertex2i(350 + 550, 220);
	glVertex2i(350 + 550, 600 - 30);
	glVertex2i(100 + 550, 600 - 30);
	glEnd();

	glColor3ub(99, 99, 99);
	glBegin(GL_POLYGON); // Building 2 Roof Front \/ bottom
	glVertex2i(100 + 550, 600 - 30);
	glVertex2i(360 + 550, 600 - 30);
	glVertex2i(360 + 550, 620 - 30);
	glVertex2i(100 + 550, 620 - 30);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 2 Roof Front \/ bottom
	glVertex2i(100 + 550, 600 - 30);
	glVertex2i(360 + 550, 600 - 30);
	glVertex2i(360 + 550, 620 - 30);
	glVertex2i(100 + 550, 620 - 30);
	glEnd();

	glColor3ub(99, 99, 99);
	glBegin(GL_POLYGON); // Building 2 Roof left
	glVertex2i(60 + 550, 640 - 30);
	glVertex2i(100 + 550, 600 - 30);
	glVertex2i(100 + 550, 620 - 30);
	glVertex2i(60 + 550, 660 - 30);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 2 Roof left
	glVertex2i(60 + 550, 640 - 30);
	glVertex2i(100 + 550, 600 - 30);
	glVertex2i(100 + 550, 620 - 30);
	glVertex2i(60 + 550, 660 - 30);
	glEnd();

	glColor3ub(99, 99, 99);
	glBegin(GL_POLYGON); // Building 2 Roof Front /\ up
	glVertex2i(80 + 550, 640 - 30);
	glVertex2i(320 + 550, 640 - 30);
	glVertex2i(320 + 550, 660 - 30);
	glVertex2i(60 + 550, 660 - 30);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 2 Roof Front /\ up
	glVertex2i(80 + 550, 640 - 30);
	glVertex2i(320 + 550, 640 - 30);
	glVertex2i(320 + 550, 660 - 30);
	glVertex2i(60 + 550, 660 - 30);
	glEnd();

	glColor3ub(99, 99, 99);
	glBegin(GL_POLYGON); // Building 2 Roof right
	glVertex2i(320 + 550, 640 - 30);
	glVertex2i(340 + 550, 620 - 30);
	glVertex2i(360 + 550, 620 - 30);
	glVertex2i(320 + 550, 660 - 30);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 2 Roof right
	glVertex2i(320 + 550, 640 - 30);
	glVertex2i(340 + 550, 620 - 30);
	glVertex2i(360 + 550, 620 - 30);
	glVertex2i(320 + 550, 660 - 30);
	glEnd();

	glColor3ub(118, 118, 118);
	glBegin(GL_POLYGON); // Building 2 Roof floor _____
	glVertex2i(80 + 550, 640 - 30);
	glVertex2i(100 + 550, 620 - 30);
	glVertex2i(340 + 550, 620 - 30);
	glVertex2i(320 + 550, 640 - 30);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 2 Roof floor _____
	glVertex2i(80 + 550, 640 - 30);
	glVertex2i(100 + 550, 620 - 30);
	glVertex2i(340 + 550, 620 - 30);
	glVertex2i(320 + 550, 640 - 30);
	glEnd();

	// start of Building 3 --------------------------------------------------------------------
	glColor3ub(118, 118, 118);
	glBegin(GL_POLYGON); // Building 3 Front
	glVertex2i(350, 280);
	glVertex2i(480, 280);
	glVertex2i(480, 480);
	glVertex2i(350, 480);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 3 Front
	glVertex2i(350, 280);
	glVertex2i(480, 280);
	glVertex2i(480, 480);
	glVertex2i(350, 480);
	glEnd();

	glColor3ub(99, 99, 99);
	glBegin(GL_POLYGON); // Building 3 Roof Front \/ bottom
	glVertex2i(350, 480);
	glVertex2i(490, 480);
	glVertex2i(490, 490);
	glVertex2i(350, 490);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 3 Roof Front \/ bottom
	glVertex2i(350, 480);
	glVertex2i(490, 480);
	glVertex2i(490, 490);
	glVertex2i(350, 490);
	glEnd();

	glColor3ub(99, 99, 99);
	glBegin(GL_POLYGON); // Building 3 Roof Front /\ up
	glVertex2i(350, 480 + 30);
	glVertex2i(490 - 30, 480 + 30);
	glVertex2i(490 - 30, 490 + 30);
	glVertex2i(350, 490 + 30);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 3 Roof Front /\ up
	glVertex2i(350, 480 + 30);
	glVertex2i(490 - 30, 480 + 30);
	glVertex2i(490 - 30, 490 + 30);
	glVertex2i(350, 490 + 30);
	glEnd();

	glColor3ub(99, 99, 99);
	glBegin(GL_POLYGON); // Building 3 Roof Right
	glVertex2i(460, 530 - 20);
	glVertex2i(480, 510 - 20);
	glVertex2i(490, 510 - 20);
	glVertex2i(460, 540 - 20);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 3 Roof Right
	glVertex2i(460, 530 - 20);
	glVertex2i(480, 510 - 20);
	glVertex2i(490, 510 - 20);
	glVertex2i(460, 540 - 20);
	glEnd();

	glColor3ub(118, 118, 118);
	glBegin(GL_POLYGON); // Building 3 Roof Floor
	glVertex2i(350, 490);
	glVertex2i(480, 510 - 20);
	glVertex2i(460, 530 - 20);
	glVertex2i(350, 480 + 30);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 3 Roof Floor
	glVertex2i(350, 490);
	glVertex2i(480, 510 - 20);
	glVertex2i(460, 530 - 20);
	glVertex2i(350, 480 + 30);
	glEnd();

	// start of Building 4 --------------------------------------------------------------------

	glColor3ub(68, 68, 68);
	glBegin(GL_POLYGON); // Building 4 Left
	glVertex2i(500, 300);
	glVertex2i(520, 280);
	glVertex2i(520, 480);
	glVertex2i(500, 500);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 4 Left
	glVertex2i(500, 300);
	glVertex2i(520, 280);
	glVertex2i(520, 480);
	glVertex2i(500, 500);
	glEnd();

	glColor3ub(118, 118, 118);
	glBegin(GL_POLYGON); // Building 4 Front
	glVertex2i(520, 280);
	glVertex2i(620, 280);
	glVertex2i(620, 480);
	glVertex2i(520, 480);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 4 Front
	glVertex2i(520, 280);
	glVertex2i(620, 280);
	glVertex2i(620, 480);
	glVertex2i(520, 480);
	glEnd();

	glColor3ub(99, 99, 99);
	glBegin(GL_POLYGON); // Building 4 Roof Front /\ up
	glVertex2i(350 + 140 + 10, 480 + 30);
	glVertex2i(490 - 30 + 140 + 20, 480 + 30);
	glVertex2i(490 - 30 + 140 + 20, 490 + 30);
	glVertex2i(350 + 140, 490 + 30);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 4 Roof Front /\ up
	glVertex2i(350 + 140 + 10, 480 + 30);
	glVertex2i(490 - 30 + 140 + 20, 480 + 30);
	glVertex2i(490 - 30 + 140 + 20, 490 + 30);
	glVertex2i(350 + 140, 490 + 30);
	glEnd();

	glColor3ub(99, 99, 99);
	glBegin(GL_POLYGON); // Building 4 Roof Front \/ bottom
	glVertex2i(520, 480);
	glVertex2i(620, 480);
	glVertex2i(620, 490);
	glVertex2i(520, 490);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 4 Roof Front \/ bottom
	glVertex2i(520, 480);
	glVertex2i(620, 480);
	glVertex2i(620, 490);
	glVertex2i(520, 490);
	glEnd();

	glColor3ub(99, 99, 99);
	glBegin(GL_POLYGON); // Building 4 Roof Left
	glVertex2i(460 + 30, 530 - 20);
	glVertex2i(480 + 30 + 10, 510 - 30);
	glVertex2i(490 + 30, 510 - 20);
	glVertex2i(460 + 30, 540 - 20);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 4 Roof Left
	glVertex2i(460 + 30, 530 - 20);
	glVertex2i(480 + 30 + 10, 510 - 30);
	glVertex2i(490 + 30, 510 - 20);
	glVertex2i(460 + 30, 540 - 20);
	glEnd();

	glColor3ub(118, 118, 118);
	glBegin(GL_POLYGON); // Building 4 Roof Floor
	glVertex2i(350 + 170, 490);
	glVertex2i(480 + 160 - 20, 510 - 20);
	glVertex2i(460 + 160, 530 - 20);
	glVertex2i(350 + 150, 480 + 30);
	glEnd();
	glColor3ub(1, 1, 1);
	glBegin(GL_LINE_LOOP); // Building 4 Roof Floor
	glVertex2i(350 + 170, 490);
	glVertex2i(480 + 160 - 20, 510 - 20);
	glVertex2i(460 + 160, 530 - 20);
	glVertex2i(350 + 150, 480 + 30);
	glEnd();
}
void land()//drawing the landscape
{
	
	// ################ Road Divider Start ######################
	glBegin(GL_POLYGON); // Road Divider
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(10, 90);
	glVertex2i(110, 90);
	glVertex2i(100, 100);
	glVertex2i(0, 100);
	glEnd();

	glBegin(GL_POLYGON); // Road Divider
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(10+ 120, 90);
	glVertex2i(110+ 120, 90);
	glVertex2i(100+ 120, 100);
	glVertex2i(0 + 120, 100);
	glEnd();

	glBegin(GL_POLYGON); // Road Divider
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(10 + 120 + 120, 90);
	glVertex2i(110 + 120 + 120, 90);
	glVertex2i(100 + 120 + 120, 100);
	glVertex2i(0 + 120 + 120, 100);
	glEnd();

	glBegin(GL_POLYGON); // Road Divider
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(10 + 120 + 120 + 120, 90);
	glVertex2i(110 + 120 + 120 + 120-20, 90);
	glVertex2i(100 + 120 + 120 + 120-20, 100);
	glVertex2i(0 + 120 + 120 + 120, 100);
	glEnd();

	glBegin(GL_POLYGON); // Road Divider
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(10 + 120 + 120 + 120 + 120 + 120 -40, 90);
	glVertex2i(110 + 120 + 120 + 120 + 120 + 120 - 40, 90);
	glVertex2i(100 + 120 + 120 + 120 + 120 + 120 - 40, 100);
	glVertex2i(0 + 120 + 120 + 120 + 120 + 120 - 40, 100);
	glEnd();

	glBegin(GL_POLYGON); // Road Divider
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(10 + 120 + 120 + 120 + 120 + 120 + 120 - 40, 90);
	glVertex2i(110 + 120 + 120 + 120 + 120 + 120 + 120 - 40, 90);
	glVertex2i(100 + 120 + 120 + 120 + 120 + 120 + 120 - 40, 100);
	glVertex2i(0 + 120 + 120 + 120 + 120 + 120 + 120 - 40, 100);
	glEnd();

	glBegin(GL_POLYGON); // Road Divider
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(10 + 120 + 120 + 120 + 120 + 120 + 120 + 120 - 40, 90);
	glVertex2i(110 + 120 + 120 + 120 + 120 + 120 + 120 + 120 - 40, 90);
	glVertex2i(100 + 120 + 120 + 120 + 120 + 120 + 120 + 120 - 40, 100);
	glVertex2i(0 + 120 + 120 + 120 + 120 + 120 + 120 + 120 - 40, 100);
	glEnd();

	glBegin(GL_POLYGON); // Road Divider
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(10 + 120 + 120 + 120 + 120 + 120 + 120 + 120 + 120 - 40, 90);
	glVertex2i(110 + 120 + 120 + 120 + 120 + 120 + 120 + 120 + 120 - 40, 90);
	glVertex2i(100 + 120 + 120 + 120 + 120 + 120 + 120 + 120 + 120 - 40, 100);
	glVertex2i(0 + 120 + 120 + 120 + 120 + 120 + 120 + 120 + 120 - 40, 100);
	glEnd();
	// ############### Road Divider Ends #######################
	// ############### Road Crossing Start #######################
	
	glBegin(GL_POLYGON); // Road Crossing
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(460 - 15 - 15 - 15, 100 + 35 - 45 + 15 + 15 + 15);
	glVertex2i(560 - 15 - 15 - 15, 100 + 35 - 45 + 15 + 15 + 15);
	glVertex2i(550 - 15 - 15 - 15, 110 + 35 - 45 + 15 + 15 + 15);
	glVertex2i(450 - 15 - 15 - 15, 110 + 35 - 45 + 15 + 15 + 15);
	glEnd();

	glBegin(GL_POLYGON); // Road Crossing
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(460 - 15 - 15, 100 + 35 - 45 + 15 + 15);
	glVertex2i(560 - 15 - 15, 100 + 35 - 45 + 15 + 15);
	glVertex2i(550 - 15 - 15, 110 + 35 - 45 + 15 + 15);
	glVertex2i(450 - 15 - 15, 110 + 35 - 45 + 15 + 15);
	glEnd();

	glBegin(GL_POLYGON); // Road Crossing
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(460-15, 100 + 35 - 45+15);
	glVertex2i(560-15, 100 + 35 - 45+15);
	glVertex2i(550-15, 110 + 35 - 45+15);
	glVertex2i(450-15, 110 + 35 - 45+15);
	glEnd();

	glBegin(GL_POLYGON); // Road Crossing
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(460, 100 + 35-45);
	glVertex2i(560, 100 + 35-45);
	glVertex2i(550, 110 + 35-45);
	glVertex2i(450, 110 + 35-45);
	glEnd();


	glBegin(GL_POLYGON); // Road Crossing
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(460+15, 100 + 35 - 45-15);
	glVertex2i(560+15, 100 + 35 - 45-15);
	glVertex2i(550+15, 110 + 35 - 45 - 15);
	glVertex2i(450+15, 110 + 35 - 45 - 15);
	glEnd();

	glBegin(GL_POLYGON); // Road Crossing
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(460 + 15 +15, 100 + 35 - 45 - 15-15);
	glVertex2i(560 + 15 + 15, 100 + 35 - 45 - 15-15);
	glVertex2i(550 + 15 + 15, 110 + 35 - 45 - 15-15);
	glVertex2i(450 + 15 + 15, 110 + 35 - 45 - 15-15);
	glEnd();

	glBegin(GL_POLYGON); // Road Crossing
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(460 + 15 + 15+15, 100 + 35 - 45 - 15 - 15-15);
	glVertex2i(560 + 15 + 15 + 15, 100 + 35 - 45 - 15 - 15 - 15);
	glVertex2i(550 + 15 + 15 + 15, 110 + 35 - 45 - 15 - 15 - 15);
	glVertex2i(450 + 15 + 15 + 15, 110 + 35 - 45 - 15 - 15 - 15);
	glEnd();

	// ############### Road Crossing ends #######################

	/*glColor3ub(0, 122, 5);
	glBegin(GL_POLYGON); // Open Space field
	glVertex2i(0, 220);
	glVertex2i(1000, 220);
	glVertex2i(1000, 300);
	glVertex2i(0, 300);
	glEnd();*/
}
void windowDoor()//drawing door and windows
{
	glColor3f(windowR, windowG, windowB);
	// Building 1 windowdows -------------------------------------------
	glBegin(GL_POLYGON); // Building 1
	glVertex2i(120, 310);
	glVertex2i(190, 310);
	glVertex2i(190, 360);
	glVertex2i(120, 360);
	glEnd();

	glBegin(GL_POLYGON); // Building 1
	glVertex2i(260, 310);
	glVertex2i(330, 310);
	glVertex2i(330, 360);
	glVertex2i(260, 360);
	glEnd();

	glBegin(GL_POLYGON); // Building 1
	glVertex2i(120, 310 + 70);
	glVertex2i(190, 310 + 70);
	glVertex2i(190, 360 + 70);
	glVertex2i(120, 360 + 70);
	glEnd();

	glBegin(GL_POLYGON); // Building 1
	glVertex2i(260, 310 + 70);
	glVertex2i(330, 310 + 70);
	glVertex2i(330, 360 + 70);
	glVertex2i(260, 360 + 70);
	glEnd();

	glBegin(GL_POLYGON); // Building 1
	glVertex2i(120, 310 + 70 + 70);
	glVertex2i(190, 310 + 70 + 70);
	glVertex2i(190, 360 + 70 + 70);
	glVertex2i(120, 360 + 70 + 70);
	glEnd();

	glBegin(GL_POLYGON); // Building 1
	glVertex2i(260, 310 + 70 + 70);
	glVertex2i(330, 310 + 70 + 70);
	glVertex2i(330, 360 + 70 + 70);
	glVertex2i(260, 360 + 70 + 70);
	glEnd();

	glBegin(GL_POLYGON); // Building 1
	glVertex2i(120, 310 + 70 + 70 + 70);
	glVertex2i(190, 310 + 70 + 70 + 70);
	glVertex2i(190, 360 + 70 + 70 + 70);
	glVertex2i(120, 360 + 70 + 70 + 70);
	glEnd();

	glBegin(GL_POLYGON); // Building 1
	glVertex2i(260, 310 + 70 + 70 + 70);
	glVertex2i(330, 310 + 70 + 70 + 70);
	glVertex2i(330, 360 + 70 + 70 + 70);
	glVertex2i(260, 360 + 70 + 70 + 70);
	glEnd();

	glBegin(GL_POLYGON); // Building 1 Door
	glVertex2i(200, 220);
	glVertex2i(250, 220);
	glVertex2i(250, 300);
	glVertex2i(200, 300);
	glEnd();

	glBegin(GL_POLYGON); // Building 1 Lift
	glVertex2i(210, 310);
	glVertex2i(240, 310);
	glVertex2i(240, 570);
	glVertex2i(210, 570);
	glEnd();


	// Building 2 windowdows -------------------------------------------
	glBegin(GL_POLYGON); // Building 2
	glVertex2i(120 + 550, -20 + 310);
	glVertex2i(190 + 550, -20 + 310);
	glVertex2i(190 + 550, -20 + 360);
	glVertex2i(120 + 550, -20 + 360);
	glEnd();

	glBegin(GL_POLYGON); // Building 2
	glVertex2i(260 + 550, -20 + 310);
	glVertex2i(330 + 550, -20 + 310);
	glVertex2i(330 + 550, -20 + 360);
	glVertex2i(260 + 550, -20 + 360);
	glEnd();

	glBegin(GL_POLYGON); // Building 2
	glVertex2i(120 + 550, -20 + 310 + 70);
	glVertex2i(190 + 550, -20 + 310 + 70);
	glVertex2i(190 + 550, -20 + 360 + 70);
	glVertex2i(120 + 550, -20 + 360 + 70);
	glEnd();

	glBegin(GL_POLYGON); // Building 2
	glVertex2i(260 + 550, -20 + 310 + 70);
	glVertex2i(330 + 550, -20 + 310 + 70);
	glVertex2i(330 + 550, -20 + 360 + 70);
	glVertex2i(260 + 550, -20 + 360 + 70);
	glEnd();

	glBegin(GL_POLYGON); // Building 2
	glVertex2i(120 + 550, -20 + 310 + 70 + 70);
	glVertex2i(190 + 550, -20 + 310 + 70 + 70);
	glVertex2i(190 + 550, -20 + 360 + 70 + 70);
	glVertex2i(120 + 550, -20 + 360 + 70 + 70);
	glEnd();

	glBegin(GL_POLYGON); // Building 2
	glVertex2i(260 + 550, -20 + 310 + 70 + 70);
	glVertex2i(330 + 550, -20 + 310 + 70 + 70);
	glVertex2i(330 + 550, -20 + 360 + 70 + 70);
	glVertex2i(260 + 550, -20 + 360 + 70 + 70);
	glEnd();

	glBegin(GL_POLYGON); // Building 2
	glVertex2i(120 + 550, -20 + 310 + 70 + 70 + 70);
	glVertex2i(190 + 550, -20 + 310 + 70 + 70 + 70);
	glVertex2i(190 + 550, -20 + 360 + 70 + 70 + 70);
	glVertex2i(120 + 550, -20 + 360 + 70 + 70 + 70);
	glEnd();

	glBegin(GL_POLYGON); // Building 2
	glVertex2i(260 + 550, -20 + 310 + 70 + 70 + 70);
	glVertex2i(330 + 550, -20 + 310 + 70 + 70 + 70);
	glVertex2i(330 + 550, -20 + 360 + 70 + 70 + 70);
	glVertex2i(260 + 550, -20 + 360 + 70 + 70 + 70);
	glEnd();

	glBegin(GL_POLYGON); // Building 2 Door
	glVertex2i(190 + 550, 220);
	glVertex2i(260 + 550, 220);
	glVertex2i(260 + 550, 300 - 20);
	glVertex2i(190 + 550, 300 - 20);
	glEnd();

	glBegin(GL_POLYGON); // Building 2 Lift
	glVertex2i(210 + 550 + 5, 310 - 20);
	glVertex2i(240 + 550 - 5, 310 - 20);
	glVertex2i(240 + 550 - 5, 560 - 10);
	glVertex2i(210 + 550 + 5, 560 - 10);
	glEnd();

	// Building 3 windowdows -------------------------------------------
	glBegin(GL_POLYGON); // Building 3
	glVertex2i(400, 430);
	glVertex2i(450, 430);
	glVertex2i(450, 460);
	glVertex2i(400, 460);
	glEnd();

	glBegin(GL_POLYGON); // Building 3
	glVertex2i(400, 430 - 40);
	glVertex2i(450, 430 - 40);
	glVertex2i(450, 460 - 40);
	glVertex2i(400, 460 - 40);
	glEnd();

	glBegin(GL_POLYGON); // Building 3
	glVertex2i(400, 430 - 80);
	glVertex2i(450, 430 - 80);
	glVertex2i(450, 460 - 80);
	glVertex2i(400, 460 - 80);
	glEnd();

	glBegin(GL_POLYGON); // Building 3 Door
	glVertex2i(350, 280);
	glVertex2i(390, 280);
	glVertex2i(390, 280 + 60);
	glVertex2i(350, 280 + 60);
	glEnd();

	// Building 4 windowdows -------------------------------------------
	glBegin(GL_POLYGON); // Building 4
	glVertex2i(400 + 150, 430);
	glVertex2i(450 + 150, 430);
	glVertex2i(450 + 150, 460);
	glVertex2i(400 + 150, 460);
	glEnd();

	glBegin(GL_POLYGON); // Building 4
	glVertex2i(400 + 150, 430 - 40);
	glVertex2i(450 + 150, 430 - 40);
	glVertex2i(450 + 150, 460 - 40);
	glVertex2i(400 + 150, 460 - 40);
	glEnd();

	glBegin(GL_POLYGON); // Building 4
	glVertex2i(400 + 150, 430 - 80);
	glVertex2i(450 + 150, 430 - 80);
	glVertex2i(450 + 150, 460 - 80);
	glVertex2i(400 + 150, 460 - 80);
	glEnd();
}

void sun()//drawing sun using circle algorithm
{
	int sunX = 0;
	int rad = 40; // radious of sun
	int sunY = rad;
	int asp10 = 5 / 4 - rad;
	while (sunX <= sunY)
	{
		glColor3f(sunR, sunG, sunB);// set sun color from variables
		glBegin(GL_TRIANGLE_FAN);
		glVertex2i(xSunCenter + sunY-100, 450+10 + ySunCenter + sunX);
		glVertex2i(xSunCenter + sunX-100, 450+10 + ySunCenter + sunY);
		glVertex2i(xSunCenter + sunX-100, 450+10 + ySunCenter - sunY);
		glVertex2i(xSunCenter + sunY-100, 450+10 + ySunCenter - sunX);
		glVertex2i(xSunCenter - sunY-100, 450 +10+ ySunCenter - sunX);
		glVertex2i(xSunCenter - sunX-100, 450 +10+ ySunCenter - sunY);
		glVertex2i(xSunCenter - sunX-100, 450 +10+ ySunCenter + sunY);
		glVertex2i(xSunCenter - sunY-100, 450 +10+ ySunCenter + sunX);
		if (asp10 < 0)
		{
			asp10 = asp10 + 2 * sunX + 1;
			sunX++;
		}
		else
		{
			asp10 = asp10 + 2 * sunX + 1 - 2 * sunY;
			sunX++;
			sunY--;
		}
	}
	glEnd();
}
void sunReset()// sthart the sun from it's stating place
{
	xSunCenter = 0;//x cordinate of the center of sun
	ySunCenter = 0;//y cordinate of the center of sun
	
	bcR = 0;//backgroung color reset
	bcG = 0;
	bcB = 0;

	sunR = 1.0;//sun color reset
	sunG = 0.2;
	sunB = 0.0;
}

void Car1()//drawing car1
{
	glTranslated(Car1X, Car1Y, Car1Z); // car translation initialize
	//car1 body----------------------------------------
	glBegin(GL_POLYGON);
	glColor3ub(a, b, c);//car1 color
	glVertex2i(0 + Car1X, 140);
	glVertex2i(250 + Car1X, 140);
	glVertex2i(250 + Car1X, 180);
	glVertex2i(200 +Car1X, 190);
	glVertex2i(0 +Car1X, 190);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3ub(1, 1, 1);
	glVertex2i(0 + Car1X, 140);
	glVertex2i(250 + Car1X, 140);
	glVertex2i(250 + Car1X, 180);
	glVertex2i(200 + Car1X, 190);
	glVertex2i(0 + Car1X, 190);
	glEnd();

	/*glBegin(GL_POLYGON);
	glColor3ub(a, b, c);
	glVertex2i(20 + Car1X, 190);
	glVertex2i(200 + Car1X, 190);
	glVertex2i(160 + Car1X, 220);
	glVertex2i(50 + Car1X, 220);
	glEnd();*/
	glBegin(GL_LINE_LOOP);
	glColor3ub(1, 1, 1);
	glVertex2i(20 + Car1X, 190);
	glVertex2i(200 + Car1X, 190);
	glVertex2i(160 + Car1X, 220);
	glVertex2i(50 + Car1X, 220);
	glEnd();
	//---------------------------------------------------
	//wheel 1 for car1----------------------------------
	int x = 0; 
	int y = r;
	int asp0 = 5 / 4 - r;
	while (x <= y)
	{
		glBegin(GL_TRIANGLE_FAN);
		glColor3ub(1, 1, 1);
		glVertex2i(50 + xCenter + y, 140 + yCenter + x);
		glVertex2i(50 + xCenter + x, 140 + yCenter + y);
		glVertex2i(50 + xCenter + x, 140 + yCenter - y);
		glVertex2i(50 + xCenter + y, 140 + yCenter - x);
		glVertex2i(50 + xCenter - y, 140 + yCenter - x);
		glVertex2i(50 + xCenter - x, 140 + yCenter - y);
		glVertex2i(50 + xCenter - x, 140 + yCenter + y);
		glVertex2i(50 + xCenter - y, 140 + yCenter + x);
		
		if (asp0 < 0)
		{
			asp0 = asp0 + 2 * x + 1;
			x++;
		}
		else
		{
			asp0 = asp0 + 2 * x + 1 - 2 * y;
			x++;
			y--;
		}
	}
	glEnd();
	//--------------------------------------------------------
	//wheel 2 for car1----------------------------------------
	int x1 = 0; 
	int y1 = r;
	int asp1 = 5 / 4 - r;

	while (x1 <= y1)
	{
		glBegin(GL_TRIANGLE_FAN);
		glColor3ub(1, 1, 1);
		glVertex2i(140 + 60 + xCenter + y1, 140 + yCenter + x1);
		glVertex2i(140 + 60 + xCenter + x1, 140 + yCenter + y1);
		glVertex2i(140 + 60 + xCenter + x1, 140 + yCenter - y1);
		glVertex2i(140 + 60 + xCenter + y1, 140 + yCenter - x1);
		glVertex2i(140 + 60 + xCenter - y1, 140 + yCenter - x1);
		glVertex2i(140 + 60 + xCenter - x1, 140 + yCenter - y1);
		glVertex2i(140 + 60 + xCenter - x1, 140 + yCenter + y1);
		glVertex2i(140 + 60 + xCenter - y1, 140 + yCenter + x1);

		if (asp1 < 0)
		{
			asp1 = asp1 + 2 * x1 + 1;
			x1++;
		}
		else
		{
			asp1 = asp1 + 2 * x1 + 1 - 2 * y1;
			x1++;
			y1--;
		}
	}
	glEnd();
	//----------------------------------------------------------
}
void Car2()//drawing car1
{
	glTranslated(Car2X, Car2Y, Car2Z);// car2 translation initialize
	//car2 body---------------------------------
	glBegin(GL_POLYGON);
	glColor3ub(d, e, f);// car2 color
	glVertex2i(0+800-50 + Car2X, 70);
	glVertex2i(250+800 -50+ Car2X, 70);
	glVertex2i(250+800 -50+ Car2X, 120);
	glVertex2i(50+800 -50+ Car2X, 120);
	glVertex2i(0+800-50 + Car2X, 110);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3ub(1, 1, 1);
	glVertex2i(0 + 800 - 50 + Car2X, 70);
	glVertex2i(250 + 800 - 50 + Car2X, 70);
	glVertex2i(250 + 800 - 50 + Car2X, 120);
	glVertex2i(50 + 800 - 50 + Car2X, 120);
	glVertex2i(0 + 800 - 50 + Car2X, 110);
	glEnd();

	/*glBegin(GL_POLYGON);
	glColor3ub(d, e, f);
	glVertex2i(50 + 800 + Car2X, 120);
	glVertex2i(230 + 800 + Car2X, 120);
	glVertex2i(200 + 800 + Car2X, 150);
	glVertex2i(50 +40 + 800 + Car2X, 150);
	glEnd();*/
	glBegin(GL_LINE_LOOP);
	glColor3ub(1, 1, 1);
	glVertex2i(50 + 800 - 50 + Car2X, 120);
	glVertex2i(230 + 800 - 50 + Car2X, 120);
	glVertex2i(200 + 800 - 50 + Car2X, 150);
	glVertex2i(50 + 40 - 50 + 800 + Car2X, 150);
	glEnd();
	//--------------------------------------------------------------------
	//wheel 1 for car2---------------------------------------------
	int xc2 = 0;
	int yc2 = r;
	int asp0c2 = 5 / 4 - r;
	while (xc2 <= yc2)
	{
		glBegin(GL_TRIANGLE_FAN);
		glColor3ub(1, 1, 1);
		glVertex2i(50 + 800 - 50 + xCenter1 + yc2, 70 + yCenter + xc2);
		glVertex2i(50 + 800 - 50 + xCenter1 + xc2, 70 + yCenter + yc2);
		glVertex2i(50 + 800 - 50 + xCenter1 + xc2, 70 + yCenter - yc2);
		glVertex2i(50 + 800 - 50 + xCenter1 + yc2, 70 + yCenter - xc2);
		glVertex2i(50 + 800 - 50 + xCenter1 - yc2, 70 + yCenter - xc2);
		glVertex2i(50 + 800 - 50 + xCenter1 - xc2, 70 + yCenter - yc2);
		glVertex2i(50 + 800 - 50 + xCenter1 - xc2, 70 + yCenter + yc2);
		glVertex2i(50 + 800 - 50 + xCenter1 - yc2, 70 + yCenter + xc2);

		if (asp0c2 < 0)
		{
			asp0c2 = asp0c2 + 2 * xc2 + 1;
			xc2++;
		}
		else
		{
			asp0c2 = asp0c2 + 2 * xc2 + 1 - 2 * yc2;
			xc2++;
			yc2--;
		}
	}
	glEnd();
	//-------------------------------------------------------
	//wheel 2 for car2-----------------------------------
	int x1c2 = 0;
	int y1c2 = r;
	int asp1c2 = 5 / 4 - r;

	while (x1c2 <= y1c2)
	{
		glBegin(GL_TRIANGLE_FAN);
		glColor3ub(1, 1, 1);
		glVertex2i(140 + 60 + 800 - 50 + xCenter1 + y1c2, 70 + yCenter + x1c2);
		glVertex2i(140 + 60 + 800 - 50 + xCenter1 + x1c2, 70 + yCenter + y1c2);
		glVertex2i(140 + 60 + 800 - 50 + xCenter1 + x1c2, 70 + yCenter - y1c2);
		glVertex2i(140 + 60 + 800 - 50 + xCenter1 + y1c2, 70 + yCenter - x1c2);
		glVertex2i(140 + 60 + 800 - 50 + xCenter1 - y1c2, 70 + yCenter - x1c2);
		glVertex2i(140 + 60 + 800 - 50 + xCenter1 - x1c2, 70 + yCenter - y1c2);
		glVertex2i(140 + 60 + 800 - 50 + xCenter1 - x1c2, 70 + yCenter + y1c2);
		glVertex2i(140 + 60 + 800 - 50 + xCenter1 - y1c2, 70 + yCenter + x1c2);

		if (asp1c2 < 0)
		{
			asp1c2 = asp1c2 + 2 * x1c2 + 1;
			x1c2++;
		}
		else
		{
			asp1c2 = asp1c2 + 2 * x1c2 + 1 - 2 * y1c2;
			x1c2++;
			y1c2--;
		}
	}
	glEnd();
	//---------------------------------------------------------
}

void car1Light()//car1 headlight
{
	glTranslated(Car1X, Car1Y, Car1Z);//car1 headlight translation
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(250 + Car1X, 160);
	glVertex2i(350 + Car1X, 120);
	glVertex2i(500 + Car1X, 120);
	glVertex2i(250 + Car1X, 170);
	glEnd();
}
void car2Light()//car2 headlight
{
	glTranslated(Car2X, Car2Y, Car2Z);//car2 headlight translation
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2i(550 -50+ Car2X, 50);
	glVertex2i(700-50 + Car2X, 50);
	glVertex2i(800-50 + Car2X, 90);
	glVertex2i(800-50 + Car2X, 100);
	glEnd();
}

void reset()//car reset ti its original place
{
	Car1X = -200;//reset car1 position
	Car1Y = 0;
	Car1Z = 0;

	Car2X = 200;//reset car2 position
	Car2Y = 0;
	Car2Z = 0;

	r = 25;
	xCenter = -200, xCenter1 = 200; // reset car wheel
}

void trafficSignal()//Draw traffic signal post
{
	//signal stracture--------------------------------
	glColor3ub(89, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(495, 150);
	glVertex2i(505, 150);
	glVertex2i(505, 350);
	glVertex2i(495, 350);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(475, 350);
	glVertex2i(525, 350);
	glVertex2i(525, 450);
	glVertex2i(475, 450);
	glEnd();
	//--------------------------------------------------------
	//draw signal circles using circle algorithm
	//circle for red signal---------------------------------
	int sigRedX = 0;
	int radRed = 10;
	int sigRedY = radRed;
	int asp110 = 5 / 4 - radRed;
	while (sigRedX <= sigRedY)
	{
		glColor3f(redR, redG, redB);

		glBegin(GL_TRIANGLE_FAN);

		glVertex2i(500 + sigRedY, 430 + sigRedX);
		glVertex2i(500 + sigRedX, 430 + sigRedY);
		glVertex2i(500 + sigRedX, 430 - sigRedY);
		glVertex2i(500 + sigRedY, 430 - sigRedX);
		glVertex2i(500 - sigRedY, 430 - sigRedX);
		glVertex2i(500 - sigRedX, 430 - sigRedY);
		glVertex2i(500 - sigRedX, 430 + sigRedY);
		glVertex2i(500 - sigRedY, 430 + sigRedX);

		if (asp110 < 0)
		{
			asp110 = asp110 + 2 * sigRedX + 1;
			sigRedX++;
		}
		else
		{
			asp110 = asp110 + 2 * sigRedX + 1 - 2 * sigRedY;
			sigRedX++;
			sigRedY--;
		}
	}
	glEnd();
	//----------------------------------------------------------
	//circle for yellow signal-----------------------------------
	int sigYellowX = 0;
	int radYellow = 10;
	int sigYellowY = radYellow;
	int asp1010 = 5 / 4 - radYellow;
	while (sigYellowX <= sigYellowY)
	{
		glColor3f(yellowR, yellowG, yellowB);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2i(500 + sigYellowY, 400 + sigYellowX);
		glVertex2i(500 + sigYellowX, 400 + sigYellowY);
		glVertex2i(500 + sigYellowX, 400 - sigYellowY);
		glVertex2i(500 + sigYellowY, 400 - sigYellowX);
		glVertex2i(500 - sigYellowY, 400 - sigYellowX);
		glVertex2i(500 - sigYellowX, 400 - sigYellowY);
		glVertex2i(500 - sigYellowX, 400 + sigYellowY);
		glVertex2i(500 - sigYellowY, 400 + sigYellowX);

		if (asp1010 < 0)
		{
			asp1010 = asp1010 + 2 * sigYellowX + 1;
			sigYellowX++;
		}
		else
		{
			asp1010 = asp1010 + 2 * sigYellowX + 1 - 2 * sigYellowY;
			sigYellowX++;
			sigYellowY--;
		}
	}
	glEnd();
	//---------------------------------------------------------
	//circle for green signal-----------------------------------
	int sigGreenX = 0;
	int radGreen = 10;
	int sigGreenY = radGreen;
	int asp10101 = 5 / 4 - radGreen;
	while (sigGreenX <= sigGreenY)
	{
		glColor3f(greenR, greenG, greenB);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2i(500 + sigGreenY, 370 + sigGreenX);
		glVertex2i(500 + sigGreenX, 370 + sigGreenY);
		glVertex2i(500 + sigGreenX, 370 - sigGreenY);
		glVertex2i(500 + sigGreenY, 370 - sigGreenX);
		glVertex2i(500 - sigGreenY, 370 - sigGreenX);
		glVertex2i(500 - sigGreenX, 370 - sigGreenY);
		glVertex2i(500 - sigGreenX, 370 + sigGreenY);
		glVertex2i(500 - sigGreenY, 370 + sigGreenX);

		if (asp10101 < 0)
		{
			asp10101 = asp10101 + 2 * sigGreenX + 1;
			sigGreenX++;
		}
		else
		{
			asp10101 = asp10101 + 2 * sigGreenX + 1 - 2 * sigGreenY;
			sigGreenX++;
			sigGreenY--;
		}
	}
	glEnd();
	//-------------------------------------------------------------------
}

void RoadTexture()
{
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0.0, 40, 0.0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, roadTexture);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0f, 0.0f, 1.0f);

	glTexCoord2i(0, 0);
	glVertex2i(0, 0);

	glTexCoord2i(10, 0);
	glVertex2i(1000, 0);

	glTexCoord2i(10, 5);
	glVertex2i(1000, 110);

	glTexCoord2i(0, 5);
	glVertex2i(0, 110);

	glEnd();
}
void foothpath()
{
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0.0, 170, 0.0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, foothpathTexture);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0f, 0.0f, 1.0f);

	glTexCoord2i(0, 0);
	glVertex2i(0, 0);

	glTexCoord2i(30, 0);
	glVertex2i(1000, 0);

	glTexCoord2i(30, 2);
	glVertex2i(1000, 50);

	glTexCoord2i(0, 2);
	glVertex2i(0, 50);
	glEnd();
}
void foothpath2()
{
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0.0, 0.0, 0.0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, foothpathTexture);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0f, 0.0f, 1.0f);

	glTexCoord2i(0, 0);
	glVertex2i(0, 0);

	glTexCoord2i(30, 0);
	glVertex2i(1000, 0);

	glTexCoord2i(30, 2);
	glVertex2i(1000, 40);

	glTexCoord2i(0, 2);
	glVertex2i(0, 40);

	glEnd();
}
void foothpathThickness()
{
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0.0, 150, 0.0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, foothpathThicknessTexture);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0f, 0.0f, 1.0f);

	glTexCoord2i(0, 0);
	glVertex2i(0, 0);

	glTexCoord2i(20, 0);
	glVertex2i(1000, 0);

	glTexCoord2i(20, 1);
	glVertex2i(1000, 20);

	glTexCoord2i(0, 1);
	glVertex2i(0, 20);

	glEnd();
}
void grass()
{
	glMatrixMode(GL_MODELVIEW);
	glTranslated(0.0, 220, 0.0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, grassTexture);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0f, 0.0f, 1.0f);

	glTexCoord2i(0, 0);
	glVertex2i(0, 0);

	glTexCoord2i(5, 0);
	glVertex2i(1000, 0);

	glTexCoord2i(5, 1);
	glVertex2i(1000, 80);

	glTexCoord2i(0, 1);
	glVertex2i(0, 80);
	glEnd();
}

void myDisplay(void) // display all components
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// clear screen
	glClearColor(bcR, bcG, bcB, 0.0);// set background color
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	foothpath2();

	glLoadIdentity();
	RoadTexture();

	glLoadIdentity();
	foothpathThickness();
	glLoadIdentity();
	foothpath();
	
	glLoadIdentity();
	grass();

	
	glLoadIdentity();
	land();//dispaly land

	
	glLoadIdentity();
	sun();//display sun

	glLoadIdentity();
	building();//display building

	glLoadIdentity();
	trafficSignal();//dispaly traffic post
	
	//showing car1 headlight at night-------------------------
	if (xSunCenter >= 900)
	{
		glLoadIdentity();
		car1Light();
	}//-------------------------------------------------------
	//showing car2 headlight at night-------------------------
	if (xSunCenter >= 900)
	{
		glLoadIdentity();
		car2Light();
	}//--------------------------------------------------------

	glLoadIdentity();
	windowDoor();// show doors and windows
	
	glLoadIdentity();
	Car1();// display car1

	glLoadIdentity();
	Car2();//display car2
	
	glFlush();//make all the thinf=g visible
	glutSwapBuffers();//I dont know its use

}

void updateSun(int value)
{
	if (flag1)
	{
		xSunCenter += 2;
		ySunCenter += 1;
		bcR += 0.0004*1.5;
		bcG += 0.0012*1.5;
		bcB += 0.002*1.5;
		
		sunG += 0.0013*2;
		windowR = 0.3, windowG=0.3, windowB = 1.0;
		if (xSunCenter == 600 && ySunCenter == 300)
		{

			flag1 = 0;
		}
	}
	if (!flag1)
	{	
		xSunCenter += 2;
		ySunCenter -= 1;
		bcR -= 0.0004*1.5;
		bcG -= 0.0012*1.5;
		bcB -= 0.002*1.5;

		sunG -= 0.0013*2.5;
		if (xSunCenter == 900)
		{
			windowR = 1.0, windowG = 1.0, windowB = 0.0;
		}
		if (xSunCenter == 1300)
		{
			sunReset();
			flag1 = 1;
		}
	}
	glutPostRedisplay(); //Tell GLUT that the display has changed	 
	glutTimerFunc(50, updateSun, 0);//Tell GLUT to call update again in 50 milliseconds
}

void updateCar(int value)
{
	
	if (flag && (greenG == 1.0 || (redR == 1.0 || (yellowR == 1.0 && yellowG == 1.0)) && Car1X>90 || Car1X <90))
	{
		Car1X += 1;
		Car2X -= 1;
		xCenter += 1;
		xCenter1 -= 1;
		if (Car1X >= 700 && Car2X <= -200)
		{
			a = 255, b = 0, c = 0;
			d = 0, e = 0, f = 255;
			reset();
			flag = 0;
		}
	}
	if (!flag && (greenG == 1.0 || (redR == 1.0 || (yellowR == 1.0 && yellowG == 1.0)) && Car1X>90 || Car1X <90))
	{
		Car1X += 1;
		Car2X -= 1;
		xCenter += 1;
		xCenter1 -= 1;
		if (Car1X >= 700 && Car2X <= -200)
		{
			a = 0, b = 0, c = 255;
			d = 255, e = 0, f = 0;
			reset();
			flag = 1;
		}	
	}
	glutPostRedisplay(); //Tell GLUT that the display has changed
	glutTimerFunc(5, updateCar, 0);//Tell GLUT to call update again in 1 milliseconds
}

void keyboard(unsigned char key, int x, int y)// change the color of signals using keyboard
{
	if (key == 'z')// red signal
	{
		redR = 1.0, redG = 0.0, redB = 0.0;
		greenR = 0.0, greenG = 0.0, greenB = 0.0;
		yellowR = 0.0, yellowG = 0.0, yellowB = 0.0;
		glutPostRedisplay();
	}
	else if (key == 'x')// green signal
	{
		redR = 0.0, redG = 0.0, redB = 0.0;
		greenR = 0.0, greenG = 1.0, greenB = 0.0;
		yellowR = 0.0, yellowG = 0.0, yellowB = 0.0;
		glutPostRedisplay();
	}
	else if (key == 'c')// yellow signal
	{
		redR = 0.0, redG = 0.0, redB = 0.0;
		greenR = 0.0, greenG = 0.0, greenB = 0.0;
		yellowR = 1.0, yellowG = 1.0, yellowB = 0.0;
		glutPostRedisplay();
	}
}

GLuint loadTexture(Image* image)
{
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
											 //Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
		0,                            //0 for now
		GL_RGB,                       //Format OpenGL uses for image
		image->width, image->height,  //Width and height
		0,                            //The border of the image
		GL_RGB, //GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
						  //as unsigned numbers
		image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

void myInit(void)
{
	glMatrixMode(GL_PROJECTION);
	glClearDepth(1.0); // Depth
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH); // Enable Smooth Shading
	gluOrtho2D(0.0, 1000.0, 0.0, 800.0);
	
	Image* imageRoad = loadBMP("road.bmp");
	roadTexture = loadTexture(imageRoad);
	
	Image* imageFoothpath = loadBMP("footpath.bmp");
	foothpathTexture = loadTexture(imageFoothpath);
	
	Image* imageFoothpathThickness = loadBMP("thickness.bmp");
	foothpathThicknessTexture = loadTexture(imageFoothpathThickness);
	
	//Image* imageGrass = loadBMP("index.bmp");
	Image* imageGrass = loadBMP("Grass1.bmp");
	grassTexture = loadTexture(imageGrass);
	
	delete imageRoad;
	delete imageFoothpath;
	delete imageFoothpathThickness;
	delete imageGrass;

}

void lightSetting()
{

	GLfloat ambientIntensity[4] = { 0.6, 0.6, 0.6, 0.0 };

	GLfloat position[4] = { 0.0, 1.0, 0.0, 0.0 };

	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);


	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientIntensity);

	glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("City Traffic");
	glutDisplayFunc(myDisplay);
	myInit();
	lightSetting();
	glutFullScreen();
	glutKeyboardFunc(keyboard);
	glutTimerFunc(50, updateSun, 0);
	glutTimerFunc(5, updateCar, 0);
	glutMainLoop();
}