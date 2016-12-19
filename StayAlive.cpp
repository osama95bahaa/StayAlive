#include "TextureBuilder.h"
#include "glut.h" 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#define _CRT_SECURE_NO_WARNINGS

bool jmp = false;
int rep = 15;

GLuint texID;
GLuint texID1;

double sec;
//bool onground = true;
int jsec = 1;
bool midflag = true;
bool leftflag = false;
bool rightflag = false;
double hany = 0;
double hits = 0;
double level = 0;
int dislevel = 1;
double bodycameraMotion = 0;
double bodyMotionx = 0;
double bodymotiony = 0;
double hany1 = 0;
double Zcamera = 0;
double hany2 = 0;
double zposition = 0;
char str[150];
char gameOver[150];
char score[150];
char lifes[150];
char saveMe[150];
double xright = 0;
double redColor = 1;
double seconds = 0;
double gravity = -2;
double disable = 0;
int score1 = 0;
int life = 0;
bool alreadyTookLife = false;
double bulletmotionx = 0;
double bulletmotiony = 0;
double firegun = 0;

int rightHandAngle = 180; // Angle of lower right hand  
bool mouseLeftState = false; // Is left mouse clicked?  
bool mouseRightState = true; // Is right mouse clicked?  
int rightHandMove = 2; // If left mouse clicked, right hand will rotate 2 degrees.  
int leftLegMove = 1; // If right mouse clicked, left leg will move by 1.  
int rightLegMove = -1; // If right mouse clicked, right leg will move by 1.  
int leftLegAngle = 90; // If right mouse clicked, this variable will be used to rotate left leg and it initialized to 90 degrees for first position of leg.  
int rightLegAngle = 90; // If right mouse clicked, this variable will be used to rotate right leg and it initialized to 90 degrees for first position of leg.  
float zMove = 0.0; // If right mouse clicked, this variable will be used to change position of object. Object will move on z-axis.  


void drawBitmapText(char *string, float x, float y, float z)
{
	char *c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != ' '; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}


void drawBitmapText1(char *string, float x, float y, float z)
{
	char *c;
	glRasterPos3f(x, y, z);

	for (c = string; *c != ','; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<< displayWire >>>>>>>>>>>>>>>>>>>>>>
void displayWire(void) {

	glMatrixMode(GL_PROJECTION); // set the view volume shape
	glLoadIdentity();

	gluPerspective(60, 640 / 480, 0.001, 100);
	glMatrixMode(GL_MODELVIEW); // position and aim the camera
	glLoadIdentity();
	//gluLookAt(0.0 + hany2, 0.0 + hany, 2.0, 0.0, 0.0, 0.0 , 0.0, 1.0, 0.0 );

	gluLookAt(0.0 + hany2, 0.0 + hany, 2.0 + bodycameraMotion, 0.0, 0.0, 0.0 + bodycameraMotion, 0.0, 1.0, 0.0 + bodycameraMotion);


	glClear(GL_COLOR_BUFFER_BIT); // clear the screen  



								  ////////////////////////// front
	glPushMatrix();
	glTranslated(0, 0.0, -47);
	glRotated(90, 1, 0, 0);
	glScaled(2, 1, 100);
	glColor3d(1, 1, 1);

	/*glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texID2);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1, -1, 0);
	glTexCoord2f(rep, 0.0f); glVertex3f(-1, 1, 0);
	glTexCoord2f(rep, rep); glVertex3f(1, 1, 0);
	glTexCoord2f(0.0f, rep); glVertex3f(1, -1, 0);
	glEnd();
	glPopMatrix();*/
	glutSolidCube(.6);
	glPopMatrix();


	/////////////////////////////////   side right
	glPushMatrix();
	glTranslated(0.6, 0.0, bodycameraMotion);
	glRotated(90, 0, 0, 1);
	glScaled(2, 1, 100);
	glColor3f(1, 0, 0);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texID);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1, -1, 0);
	glTexCoord2f(rep, 0.0f); glVertex3f(-1, 1, 0);
	glTexCoord2f(rep, rep); glVertex3f(1, 1, 0);
	glTexCoord2f(0.0f, rep); glVertex3f(1, -1, 0);
	glEnd();
	glPopMatrix();
	//glutSolidCube(.6);
	glPopMatrix();


	////////////////////   side left
	glPushMatrix();
	glTranslated(-0.6, 0.0, bodycameraMotion);
	glRotated(90, 0, 0, 1);
	glScaled(2, 1, 100);
	glColor3f(1, 0, 0);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texID);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1, -1, 0);
	glTexCoord2f(rep, 0.0f); glVertex3f(-1, 1, 0);
	glTexCoord2f(rep, rep); glVertex3f(1, 1, 0);
	glTexCoord2f(0.0f, rep); glVertex3f(1, -1, 0);
	glEnd();
	glPopMatrix();
	//glutSolidCube(.6);
	glPopMatrix();


	//////////////////////////////////////////////////////////////////////// bottom
	glPushMatrix();
	glTranslated(0.0, -0.6, bodycameraMotion);
	glRotated(90, 0, 0, 1);
	glRotated(90, 0, 1, 0);
	glScaled(4, 1, 100);
	glColor3f(0.6, 0.5, 0.7);

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texID1);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1, -1, 0);
	glTexCoord2f(rep, 0.0f); glVertex3f(-1, 1, 0);
	glTexCoord2f(rep, rep); glVertex3f(1, 1, 0);
	glTexCoord2f(0.0f, rep); glVertex3f(1, -1, 0);
	glEnd();
	glPopMatrix();
	//glutSolidCube(.6);
	glPopMatrix();


	////////  top 
	glPushMatrix();
	glTranslated(0.0, 0.6, -23);
	glScaled(2, .05, 80);	
	glColor3f(0.6, 0.7, 0.5);
	glutSolidCube(.6);
	glPopMatrix();

	if (dislevel % 2 == 0) {
		redColor = redColor = 1 - level / 3;
	}
	else {
		redColor = 0 + level / 3;
	}

	//////////////////////////////obstacle 1 jump 
	if ((-1)*bodycameraMotion < 6) {
		glPushMatrix();
		glTranslated(0, -0.28, -5);
		glRotated(90, 1, 0, 0);
		glScaled(2, .05, 0.8);
		glColor3d(redColor, 0.3, 0.2);
		glutSolidCube(.6);
		glPopMatrix();
	}

	///////////////////////////////////////////// obstacle 2 dodge left
	if ((-1)*bodycameraMotion > 5 && (-1)*bodycameraMotion < 10) {
		glPushMatrix();
		glTranslated(0.3, 0, -9);
		glRotated(90, 1, 0, 0);
		glScaled(1, .05, 2);
		glColor3d(redColor, 0.3, 0.2);
		glutSolidCube(.6);
		glPopMatrix();

	}
	///////////////////////////////////////////// obstacle 2 dodge right
	if ((-1)*bodycameraMotion > 9 && (-1)*bodycameraMotion < 13) {
		glPushMatrix();
		glTranslated(-0.3, 0, -12);
		glRotated(90, 1, 0, 0);
		glScaled(1, .05, 2);
		glColor3d(redColor, 0.3, 0.2);
		glutSolidCube(.6);
		glPopMatrix();
	}


	/////////////////////////////////  obstacle dodge and jump 
	if (((-1)*bodycameraMotion) > 9.7 && ((-1)*bodycameraMotion) < 30) {
		glPushMatrix();

		glTranslated(0, 0, -17);
		glPushMatrix();
		glTranslated(-0.3, 0, 0);
		glRotated(90, 1, 0, 0);
		glScaled(1, .05, 2);
		glColor3d(redColor, 0.3, 0.2);
		glutSolidCube(.6);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0, -0.36, 0);
		glRotated(90, 1, 0, 0);
		glScaled(2, .05, 0.8);
		glColor3d(redColor, 0.3, 0.2);
		glutSolidCube(.6);
		glPopMatrix();


		glPopMatrix();

	}

	/////////////////////////////////  obstacle dodge and jump 
	if ((-1)*bodycameraMotion > 19 && (-1)*bodycameraMotion < 23) {
		glPushMatrix();

		glTranslated(0, 0, -22);

		glPushMatrix();
		glTranslated(0.3, 0, 0);
		glRotated(90, 1, 0, 0);
		glScaled(1, .05, 2);
		glColor3d(redColor, 0.3, 0.2);
		glutSolidCube(.6);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0, -0.36, 0);
		glRotated(90, 1, 0, 0);
		glScaled(2, .05, 0.8);
		glColor3d(redColor, 0.3, 0.2);
		glutSolidCube(.6);
		glPopMatrix();


		glPopMatrix();
	}
	///////////////////////////////////////////// obstacle 2 dodge right

	if ((-1)*bodycameraMotion > 21 && (-1)*bodycameraMotion < 27) {
		glPushMatrix();
		glTranslated(-0.3, 0, -26);
		glRotated(90, 1, 0, 0);
		glScaled(1, .05, 2);
		glColor3d(redColor, 0.3, 0.2);
		glutSolidCube(.6);
		glPopMatrix();

	}

	///////////////////////////////////////////// obstacle 2 dodge right harder 
	if ((-1)*bodycameraMotion > 25 && (-1)*bodycameraMotion < 31) {
		glPushMatrix();
		glTranslated(0.24, 0, -30);
		glRotated(90, 1, 0, 0);
		glScaled(1.2, .05, 2);
		glColor3d(redColor, 0.3, 0.2);
		glutSolidCube(.6);
		glPopMatrix();
	}
	/////////////////////////////////////////////////////  obstacle godown
	if ((-1)*bodycameraMotion > 30 && (-1)*bodycameraMotion < 38) {
		glPushMatrix();
		glTranslated(0, 0.34, -37);
		glRotated(90, 1, 0, 0);
		glScaled(2, .05, 0.8);
		glColor3d(redColor, 0.3, 0.2);
		glutSolidCube(.6);
		glPopMatrix();
	}

	/////////////////////////////////////////////   move to the middle
	if ((-1)*bodycameraMotion > 37 && (-1)*bodycameraMotion < 44) {
		glPushMatrix();
		glTranslated(0.39, 0, -43);
		glRotated(90, 1, 0, 0);
		glScaled(0.7, .05, 2);
		glColor3d(redColor, 0.3, 0.2);
		glutSolidCube(.6);
		glPopMatrix();

		glPushMatrix();
		glTranslated(-0.39, 0, -43);
		glRotated(90, 1, 0, 0);
		glScaled(0.7, .05, 2);
		glColor3d(redColor, 0.3, 0.2);
		glutSolidCube(.6);
		glPopMatrix();


	}


	///////////////////////////////////////////////////////////////////  ROBOT/////////////////////////////////////////////
	glPushMatrix();
	glTranslatef(0 + bodyMotionx, -0.55 + bodymotiony, 0.5 + bodycameraMotion);
	glScaled(0.0005, 0.0005, 0.0005);
	glPushMatrix(); //BODY  
	glColor3f(1.0, 0.647, 0.0);
	glTranslatef(0.0, 221, zMove);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj* body = gluNewQuadric();
	gluQuadricDrawStyle(body, GLU_FILL);
	gluCylinder(body, 120, 120, 300, 30, 30);
	glPopMatrix();

	glPushMatrix(); //LEFT UPPER ARM  
	glColor3f(0.180f, 0.545f, 0.341f);
	glTranslatef(-80, 160, zMove);

	glRotatef(-45, 0.0, 0.0, 1.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj* leftUpperArm = gluNewQuadric();
	gluQuadricDrawStyle(leftUpperArm, GLU_FILL);
	gluCylinder(leftUpperArm, 16, 16, 200, 30, 30);
	glPopMatrix();

	glPushMatrix(); // LEFT UPPER ARM AND BODY CONNECTION  
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(-80.0, 160, zMove);
	glutSolidSphere(16, 30, 30);
	glPopMatrix();

	glPushMatrix(); //LEFT LOWER ARM  
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(-221.5, 19.5, zMove);
	glRotatef(225, 0.0, 0.0, 1.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj* leftLowerArm = gluNewQuadric();
	gluQuadricDrawStyle(leftLowerArm, GLU_FILL);
	gluCylinder(leftLowerArm, 16, 16, 200, 30, 30);
	glPopMatrix();

	glPushMatrix(); // LEFT LOWER ARM AND LEFT UPPER ARM CONNECTION  
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(-221.5, 19.5, zMove);
	glutSolidSphere(16, 30, 30);
	glPopMatrix();

	glPushMatrix(); //RIGHT UPPER ARM  
	glColor3f(0.180f, 0.545f, 0.341f);
	glTranslatef(80, 160, zMove);
	glRotatef(90, 0.0, 0.0, 1.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj* rightUpperArm = gluNewQuadric();
	gluQuadricDrawStyle(rightUpperArm, GLU_FILL);
	gluCylinder(rightUpperArm, 16, 16, 200, 30, 30);
	glPopMatrix();

	glPushMatrix(); // RIGHT UPPER ARM AND BODY CONNECTION  
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(80, 160, zMove);
	glutSolidSphere(16, 30, 30);
	glPopMatrix();

	glPushMatrix(); //RIGHT LOWER ARM  
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(280, 160, zMove);
	glRotatef((GLfloat)rightHandAngle, 0.0, 0.0, 1.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj* rightLowerArm = gluNewQuadric();
	gluQuadricDrawStyle(rightLowerArm, GLU_FILL);
	gluCylinder(rightLowerArm, 16, 16, 200, 30, 30);
	glPopMatrix();

	glPushMatrix(); // RIGHT LOWER ARM AND RIGHT UPPER ARM CONNECTION  
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(280, 160, zMove);
	glutSolidSphere(16, 30, 30);
	glPopMatrix();

	glPushMatrix(); //LEFT LEG  
	glColor3f(0.180f, 0.545f, 0.341f);
	glTranslatef(-35, -20, zMove);
	glRotatef(-15, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)leftLegAngle, 1.0, 0.0, 0.0);
	GLUquadricObj* leftLeg = gluNewQuadric();
	gluQuadricDrawStyle(leftLeg, GLU_FILL);
	gluCylinder(leftLeg, 16, 16, 400, 30, 30);
	glPopMatrix();

	glPushMatrix(); // LEFT LEG AND BODY CONNECTION  
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(-35, -20, zMove);
	glutSolidSphere(16, 30, 30);
	glPopMatrix();

	glPushMatrix(); //RIGHT LEG  
	glColor3f(0.180f, 0.545f, 0.341f);
	glTranslatef(35, -20, zMove);
	glRotatef(15, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)rightLegAngle, 1.0, 0.0, 0.0);
	GLUquadricObj* rightLeg = gluNewQuadric();
	gluQuadricDrawStyle(rightLeg, GLU_FILL);
	gluCylinder(rightLeg, 16, 16, 400, 30, 30);
	glPopMatrix();

	glPushMatrix(); // RIGHT LEG AND BODY CONNECTION  
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(35, -20, zMove);
	glutSolidSphere(16, 30, 30);
	glPopMatrix();

	glPushMatrix(); //NECK  
	glColor3f(0.0, 0.0, 0.545);
	glTranslatef(0.0, 251, zMove);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj* neck = gluNewQuadric();
	gluQuadricDrawStyle(neck, GLU_FILL);
	gluCylinder(neck, 20, 20, 30, 30, 30);
	glPopMatrix();

	glPushMatrix(); // HEAD  
	glColor3f(1.0, 0.647, 0.0);
	glPushMatrix();
	glTranslatef(0.0, 350, zMove);
	glutSolidSphere(100, 30, 30);
	glPopMatrix();
	glPopMatrix();






	if (mouseRightState == true) { // If right mouse clicked the object will ve moved and legs' angles will be changed.  
		if (leftLegAngle > 110) {
			leftLegMove = -leftLegMove;
		}
		else if (leftLegAngle < 70) {
			leftLegMove = -leftLegMove;
		}
		leftLegAngle = (leftLegAngle + leftLegMove) % 360; // Changing angle of left leg  

		if (rightLegAngle > 110) {
			rightLegMove = -rightLegMove;
		}
		else if (rightLegAngle < 70) {
			rightLegMove = -rightLegMove;
		}
		rightLegAngle = (rightLegAngle + rightLegMove) % 360; // Changing angle of right leg  

	}

	////////  zombie 

	///////////////////////////////////////////////////////////////////  ROBOT/////////////////////////////////////////////
	if (disable == 0) {
		if ((-1)*bodycameraMotion > 43 && (-1)*bodycameraMotion < 47.6) {
			glPushMatrix();
			glTranslatef(0 + bodyMotionx, -0.55, -47);
			glScaled(0.0005, 0.0005, 0.0005);
			glPushMatrix(); //BODY  
			glColor3f(1.0, 1, 0.0);
			glTranslatef(0.0, 221, zMove);
			glRotatef(90, 1.0, 0.0, 0.0);
			GLUquadricObj* body1 = gluNewQuadric();
			gluQuadricDrawStyle(body1, GLU_FILL);
			gluCylinder(body1, 120, 120, 300, 30, 30);
			glPopMatrix();

			glPushMatrix(); //LEFT UPPER ARM  
			glColor3f(0.180f, 0.545f, 0.341f);
			glTranslatef(-80, 160, zMove);

			glRotatef(-45, 0.0, 0.0, 1.0);
			glRotatef(90, 1.0, 0.0, 0.0);
			GLUquadricObj* leftUpperArm1 = gluNewQuadric();
			gluQuadricDrawStyle(leftUpperArm1, GLU_FILL);
			gluCylinder(leftUpperArm1, 16, 16, 200, 30, 30);
			glPopMatrix();

			glPushMatrix(); // LEFT UPPER ARM AND BODY CONNECTION  
			glColor3f(1.0, 0.0, 0.0);
			glPushMatrix();
			glTranslatef(-80.0, 160, zMove);
			glutSolidSphere(16, 30, 30);
			glPopMatrix();

			glPushMatrix(); //LEFT LOWER ARM  
			glColor3f(1.0, 1.0, 0.0);
			glTranslatef(-221.5, 19.5, zMove);
			glRotatef(225, 0.0, 0.0, 1.0);
			glRotatef(90, 1.0, 0.0, 0.0);
			GLUquadricObj* leftLowerArm1 = gluNewQuadric();
			gluQuadricDrawStyle(leftLowerArm1, GLU_FILL);
			gluCylinder(leftLowerArm1, 16, 16, 200, 30, 30);
			glPopMatrix();

			glPushMatrix(); // LEFT LOWER ARM AND LEFT UPPER ARM CONNECTION  
			glColor3f(1.0, 0.0, 0.0);
			glPushMatrix();
			glTranslatef(-221.5, 19.5, zMove);
			glutSolidSphere(16, 30, 30);
			glPopMatrix();

			glPushMatrix(); //RIGHT UPPER ARM  
			glColor3f(0.180f, 0.545f, 0.341f);
			glTranslatef(80, 160, zMove);
			glRotatef(90, 0.0, 0.0, 1.0);
			glRotatef(90, 1.0, 0.0, 0.0);
			GLUquadricObj* rightUpperArm1 = gluNewQuadric();
			gluQuadricDrawStyle(rightUpperArm1, GLU_FILL);
			gluCylinder(rightUpperArm1, 16, 16, 200, 30, 30);
			glPopMatrix();

			glPushMatrix(); // RIGHT UPPER ARM AND BODY CONNECTION  
			glColor3f(1.0, 0.0, 0.0);
			glPushMatrix();
			glTranslatef(80, 160, zMove);
			glutSolidSphere(16, 30, 30);
			glPopMatrix();

			glPushMatrix(); //RIGHT LOWER ARM  
			glColor3f(1.0, 1.0, 0.0);
			glTranslatef(280, 160, zMove);
			glRotatef((GLfloat)rightHandAngle, 0.0, 0.0, 1.0);
			glRotatef(90, 1.0, 0.0, 0.0);
			GLUquadricObj* rightLowerArm1 = gluNewQuadric();
			gluQuadricDrawStyle(rightLowerArm1, GLU_FILL);
			gluCylinder(rightLowerArm1, 16, 16, 200, 30, 30);
			glPopMatrix();

			glPushMatrix(); // RIGHT LOWER ARM AND RIGHT UPPER ARM CONNECTION  
			glColor3f(1.0, 0.0, 0.0);
			glPushMatrix();
			glTranslatef(280, 160, zMove);
			glutSolidSphere(16, 30, 30);
			glPopMatrix();

			glPushMatrix(); //LEFT LEG  
			glColor3f(0.180f, 0.545f, 0.341f);
			glTranslatef(-35, -20, zMove);
			glRotatef(-15, 0.0, 0.0, 1.0);
			glRotatef((GLfloat)leftLegAngle, 1.0, 0.0, 0.0);
			GLUquadricObj* leftLeg1 = gluNewQuadric();
			gluQuadricDrawStyle(leftLeg1, GLU_FILL);
			gluCylinder(leftLeg1, 16, 16, 400, 30, 30);
			glPopMatrix();

			glPushMatrix(); // LEFT LEG AND BODY CONNECTION  
			glColor3f(1.0, 0.0, 0.0);
			glPushMatrix();
			glTranslatef(-35, -20, zMove);
			glutSolidSphere(16, 30, 30);
			glPopMatrix();

			glPushMatrix(); //RIGHT LEG  
			glColor3f(0.180f, 0.545f, 0.341f);
			glTranslatef(35, -20, zMove);
			glRotatef(15, 0.0, 0.0, 1.0);
			glRotatef((GLfloat)rightLegAngle, 1.0, 0.0, 0.0);
			GLUquadricObj* rightLeg1 = gluNewQuadric();
			gluQuadricDrawStyle(rightLeg1, GLU_FILL);
			gluCylinder(rightLeg1, 16, 16, 400, 30, 30);
			glPopMatrix();

			glPushMatrix(); // RIGHT LEG AND BODY CONNECTION  
			glColor3f(1.0, 0.0, 0.0);
			glPushMatrix();
			glTranslatef(35, -20, zMove);
			glutSolidSphere(16, 30, 30);
			glPopMatrix();

			glPushMatrix(); //NECK  
			glColor3f(0.0, 0.0, 0.545);
			glTranslatef(0.0, 251, zMove);
			glRotatef(90, 1.0, 0.0, 0.0);
			GLUquadricObj* neck1 = gluNewQuadric();
			gluQuadricDrawStyle(neck1, GLU_FILL);
			gluCylinder(neck1, 20, 20, 30, 30, 30);
			glPopMatrix();

			glPushMatrix(); // HEAD  
			glColor3f(1.0, 0.647, 0.0);
			glPushMatrix();
			glTranslatef(0.0, 350, zMove);
			glutSolidSphere(100, 30, 30);
			glPopMatrix();
			glPopMatrix();

		}
	}




	////bullet


	/////////////////////////////////////   bullet first cylinder 
	if (((-1)*bodycameraMotion) > 43 && ((-1)*bodycameraMotion) < 48) {
		glPushMatrix();
		glTranslated(0 + (bulletmotionx / 1000) - 0.7, -0.2, 1 + bodycameraMotion);
		glRotated(90, 0, 0, 1);
		glRotated(270, 1, 0, 0);
		glScaled(0.2, 0.2, 0.2);
		glPushMatrix();
		glTranslated(0, 0.15, 1);
		glRotated(90, 1, 0, 0);
		glColor3d(0, 0, 1);


		GLUquadricObj* qobja = gluNewQuadric();
		gluQuadricDrawStyle(qobja, GLU_LINE);  //GLU_FILL, GLU_SILHOUETTE ,GLU_POINT
		gluCylinder(qobja, 0.05, 0.05, 0.20, 30, 220);
		glPopMatrix();

		///////////////////////////   cylinder 2 wide to narrow
		glPushMatrix();
		glTranslated(0, 0.20, 1);
		glRotated(90, 1, 0, 0);
		glColor3d(0, 0, 1);


		GLUquadricObj* qob = gluNewQuadric();
		gluQuadricDrawStyle(qob, GLU_LINE);  //GLU_FILL, GLU_SILHOUETTE ,GLU_POINT
		gluCylinder(qob, 0.03, 0.05, 0.05, 30, 220);
		glPopMatrix();
		//////////////////////////////////  cylinder 3 

		glPushMatrix();
		glTranslated(0, 0.25, 1);
		glRotated(90, 1, 0, 0);
		glColor3d(0, 1, 1);


		GLUquadricObj* qobj4 = gluNewQuadric();
		gluQuadricDrawStyle(qobj4, GLU_LINE);  //GLU_FILL, GLU_SILHOUETTE ,GLU_POINT
		gluCylinder(qobj4, 0.03, 0.03, 0.05, 30, 220);
		glPopMatrix();

		///////////////////////// cylsinder 4

		glPushMatrix();
		glTranslated(0, 0.28, 1);
		glRotated(90, 1, 0, 0);
		glColor3d(0.3, 0, 1);


		GLUquadricObj* qobj3 = gluNewQuadric();
		gluQuadricDrawStyle(qobj3, GLU_LINE);  //GLU_FILL, GLU_SILHOUETTE ,GLU_POINT
		gluCylinder(qobj3, 0.015, 0.03, 0.02, 30, 220);
		glPopMatrix();
		////////////////////////////// sphere 
		glPushMatrix();
		//glColor3d(0.8, 1, 1);
		glTranslated(0, 0.28, 1);
		glutSolidSphere(0.025, 100, 50);

		glPopMatrix();

		///////////////////////////////Torus for the bullet
		glPushMatrix();
		glTranslated(0, -0.05, 1);
		glRotated(90, 1, 0, 0);
		glColor3d(1, 1, 1);
		glutSolidTorus(0.01, 0.05, 10, 10);
		glPopMatrix();

		//////////////////////////////////   disk for the bullet

		glPushMatrix();
		glColor3d(1, 0, 0);
		glTranslated(0, -0.05, 1);
		glRotated(90, 1, 0, 0);
		GLUquadricObj* qobj1 = gluNewQuadric();
		gluQuadricDrawStyle(qobj1, GLU_LINE);  //GLU_FILL, GLU_SILHOUETTE ,GLU_POINT
		gluDisk(qobj1, 0, 0.025, 50, 100);

		glColor3d(1, 0, 1);
		GLUquadricObj* qobj2 = gluNewQuadric();
		gluQuadricDrawStyle(qobj2, GLU_LINE);
		gluDisk(qobj2, 0.025, 0.055, 50, 100);

		glPopMatrix();
		glPopMatrix();
	}


	if (hits == 0)
	{
		glColor3f(1, 1, 1);

		drawBitmapText(str, 1, 1, 0 + bodycameraMotion);
		sprintf_s(str, "Level=%i ", dislevel);
		puts(str);

		drawBitmapText(score, 0.85, 1, 0 + bodycameraMotion);
		sprintf_s(score, "Score=%i ", score1);
		puts(score);

		drawBitmapText(lifes, 0.65, 1, 0 + bodycameraMotion);
		sprintf_s(lifes, "SaveMe=%i ", life);
		puts(lifes);



	}
	if (hits)
	{
		zMove = 0;
		rightLegMove = 0;
		leftLegMove = 0;

		glColor3f(0.5, 0.9, 0.2);
		drawBitmapText(gameOver, 0, 0, bodycameraMotion);
		sprintf_s(gameOver, "GameOver ", score1);
		puts(gameOver);


		drawBitmapText(str, 0, -0.2, 0 + bodycameraMotion);
		sprintf_s(str, "level=%i ", dislevel);
		puts(str);

		drawBitmapText(score, 0, -0.1, 0 + bodycameraMotion);
		sprintf_s(score, "Score=%i ", score1);
		puts(score);

	}
	if (life) {

		drawBitmapText1(saveMe, -1, 1, 0 + bodycameraMotion);
		sprintf_s(saveMe, "Press 'r' to activate your bonus life if available OR 'n' to restart,");
		puts(saveMe);
	}

	glFlush();

}


void key(unsigned char k, int x, int y)
{


	if (k == '1') {
		Zcamera += 1;
	}
	if (k == '2') {

	}

	if (k == '4') {
		hany += 1;
	}

	if (k == '5') {
		hany -= 1;
	}
	if (k == '6') {
		hany1 += 5;
	}
	if (k == '7') {
		hany1 -= 5;
	}
	if (k == '8') {
		hany2 += 0.5;
	}
	if (k == '9') {
		hany2 -= 0.5;
	}
	if (k == 'q') {
		exit(0);
	}
	if (k == 't') {
		zposition = 1;
	}
	if (hits == 1 && life == 1 && alreadyTookLife == true && k == 'r')
	{
		hits = 0;
		life = 0;
		rightLegMove = 1;
		leftLegMove = 1;
		sec = 200;
		bodycameraMotion -= 0.1;
		bodymotiony = 0;
	}

	if (k == 'n') {

		hits = 0;
		score1 = 0;
		level = 0;
		life = 0;
		sec = 200;
		bodymotiony = 0;
		bodycameraMotion = 0;
		dislevel = 1;
		rightLegMove = 1;
		leftLegMove = 1;

	}
	glutPostRedisplay();
}



void passM(int x, int y)

{

	if (firegun == 0) {
		bulletmotionx = x;
		bulletmotiony = y;
	}
}

void actM(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON) {
		if ((-1)*bodycameraMotion > 43 && (-1)*bodycameraMotion < 47) {
			disable = 1;
		}
	}
}

void spe(int k, int x, int y)
{
	if (hits == 0) {
		if (k == GLUT_KEY_RIGHT && midflag) {
			bodyMotionx += 0.45;
			midflag = false;
			rightflag = true;
			leftflag = false;

		}
		if (k == GLUT_KEY_RIGHT && leftflag) {
			bodyMotionx += 0.45;
			midflag = true;
			rightflag = false;
			leftflag = false;

		}
		if (k == GLUT_KEY_RIGHT && rightflag) {

			midflag = false;
			rightflag = true;
			leftflag = false;

		}
		if (k == GLUT_KEY_LEFT && midflag) {
			bodyMotionx -= 0.45;
			midflag = false;
			rightflag = false;
			leftflag = true;

		}

		if (k == GLUT_KEY_LEFT && rightflag) {
			bodyMotionx -= 0.45;
			midflag = true;
			rightflag = false;
			leftflag = false;

		}
		if (k == GLUT_KEY_LEFT && leftflag) {

			midflag = false;
			rightflag = false;
			leftflag = true;

		}
		if (k == GLUT_KEY_UP && bodymotiony < 0.1) {

			sec = 0;
			//if (onground) {
			jmp = true;
		
			//}

		}

		if (k == GLUT_KEY_DOWN)
			if (bodymotiony > 0) {
				bodymotiony -= 0.01;
			}
	}
	glutPostRedisplay();
}

void Anim()
{
	if (sec > 0 && sec < 35) {
		bodymotiony += 0.008;
	}
	if (sec > 35 && sec <70) {
		bodymotiony -= 0.008;
	}

	if (sec > 200) {
		jmp = false;
		sec = 0;
	}

	if (hits == 0) {
		if (level >= 1 && (alreadyTookLife == false))
		{
			life = 1;
			alreadyTookLife = true;
		}

		bodycameraMotion -= (0.01 + level / 500);


		if (((-1)*bodycameraMotion) > 48) {
			bodycameraMotion = 0;
			level += 1;
			dislevel += 1;
			disable = 0;
		}


		if (((-1)*bodycameraMotion) > 5.7 && ((-1)*bodycameraMotion) < 5.8) {
			score1++;
			if (bodymotiony < 0.7) {
				hits = 1;
			}

		}

		if (((-1)*bodycameraMotion) > 9.7 && ((-1)*bodycameraMotion) < 9.8) {
			score1++;
			if (bodyMotionx > -0.1) {

				hits = 1;
			}

		}


		if (((-1)*bodycameraMotion) > 12.7 && ((-1)*bodycameraMotion) < 12.8) {
			score1++;
			if (bodyMotionx < 0.05) {
				hits = 1;
			}

		}


		if (((-1)*bodycameraMotion) > 17.7 && ((-1)*bodycameraMotion) < 17.8) {
			score1++;
			if (bodyMotionx < 0.05 || bodymotiony < 0.6) {
				hits = 1;
			}

		}


		if (((-1)*bodycameraMotion) > 22.7 && ((-1)*bodycameraMotion) < 22.8) {
			score1++;
			if (bodyMotionx > -0.02 || bodymotiony < 0.6) {
				hits = 1;
			}

		}


		if (((-1)*bodycameraMotion) > 26.7 && ((-1)*bodycameraMotion) < 26.8) {
			score1++;
			if (bodyMotionx < 0.05) {
				hits = 1;
			}
		}

		if (((-1)*bodycameraMotion) > 30.7 && ((-1)*bodycameraMotion) < 30.8) {
			score1++;
			if (bodyMotionx > -0.2) {
				hits = 1;
			}

		}


		if (((-1)*bodycameraMotion) > 37.7 && ((-1)*bodycameraMotion) < 37.8) {
			score1++;
			if (bodymotiony > 0.4) {
				hits = 1;
			}

		}

		if (((-1)*bodycameraMotion) > 43.7 && ((-1)*bodycameraMotion) < 43.8) {
			score1++;
			if (bodyMotionx > 0.04 || bodyMotionx <-0.04) {
				hits = 1;
			}

		}

		if (((-1)*bodycameraMotion) > 47.5 && ((-1)*bodycameraMotion) < 47.6) {
			score1 += 5;
			if (disable == 0) {
				hits = 1;
			}
		}



		for (int i = 0; i < 500000; i++) {
		}

	}

	glutPostRedisplay();
}

void time(int val) {

	seconds++;
	glutPostRedisplay();
	glutTimerFunc(1000, time, 0);
}
void timer4(int val)
{

	if (jmp) {
		sec += 0.5;
	}

	glutPostRedisplay();
	glutTimerFunc(10, timer4, 0);

}
//<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 
void main(int argc, char **argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("");
	glutDisplayFunc(displayWire);
	glutMouseFunc(actM);
	glutKeyboardFunc(key);
	glutTimerFunc(0, time, 0);
	glutTimerFunc(0, timer4, 0);
	glutSpecialFunc(spe);
	glutIdleFunc(Anim);
	glutPassiveMotionFunc(passM);
	glEnable(GL_TEXTURE_2D);
	loadPPM(&texID, "textures/frontend-large.ppm", 398, 265, true);
	loadPPM(&texID1, "textures/street.ppm", 600, 398, true);
	//loadPPM(&texID2, "textures/bat-img1.ppm", 558, 343, true);
	glutSetCursor(GLUT_CURSOR_NONE);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);  // background is white  
	glViewport(0, 0, 640, 480);  // x y width height
	glutFullScreen();
	glutMainLoop();
}