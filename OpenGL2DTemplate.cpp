//  Includes
#include <stdio.h>
#include <math.h>
#include <random>
#include <glut.h>
#include <iostream>
#include<time.h> 
#include <iostream>
#include<windows.h>  
#include <mmsystem.h>







//  Methods Signatures
void drawRect(int x, int y, int w, int h);
void drawCircle(int x, int y, float r);
void Timer(int value);
void Display();





//  Global Variables
int keyX = 0;
int keyY = 0;
int keyC = 0;
double score;
const int numberOfLanes = 5;
double rot = 0;
int bridgeWidth = 80;
int d = 780 / numberOfLanes;
int increament;
int start[numberOfLanes - 1];
int end[numberOfLanes - 1];
const int numberOfCoins = 6;
int posOfCoins[numberOfCoins];

void print(int x, int y, char* string)
{
    int len, i;
    glRasterPos2f(95, 783);
    len = (int)strlen(string);

    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
    }
}
void drawLaneBorders() {

    increament = d;
    for (int i = 0; i <= numberOfLanes; i++) {
        glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex3f(20, increament, 0);
        glVertex3f(20, increament + 20, 0);
        glVertex3f(780, increament + 20, 0);
        glVertex3f(780, increament, 0);
        glEnd();

        end[i] = increament;
        increament = increament + d + 5;

    }
}


void drawBridges() {
    glColor3f(0.8, 0.8, 0.8);
    for (int i = 0; i <= numberOfLanes; i++) {
        drawRect(start[i], end[i], bridgeWidth, 30);

    }
}


void drawCoins() {
    srand((unsigned)time_t(16));
    int x;

    for (int i = 0; i <= 5; i++) {
         x = (rand() % 650) + 40;
        glColor3f(1.0, 1.0, 0.0);
        drawCircle(x, d + (d * i) - 80, 15);

        glBegin(GL_LINES);
        glColor3f(0, 0, 0);
        glVertex3f(x, (d + (d * i) - 80) + 16, 0);
        glVertex3f(x, (d + (d * i) - 80) - 16, 0);
        glEnd();

    }

   


    for (int i = 0; i < numberOfCoins; i++) {
        std::vector< int >  posOfCoins;
        posOfCoins.push_back(x);
      

    }
   


    

}

void powerUp() {
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(420, 100, 0);
    glVertex3f(440, 130, 0);
    glVertex3f(460, 100, 0);
    glEnd();
    glBegin(GL_QUADS);
    
   // glColor3f(1.0, 0.0, 0.0);
    glVertex3f(420, 70, 0);
    glVertex3f(420, 100, 0);
    glVertex3f(460, 100, 0);
    glVertex3f(460, 70, 0);
    glEnd();


    glBegin(GL_QUADS);

     glColor3f(1.0, 0.0, 0.0);
    glVertex3f(420, 370, 0);
    glVertex3f(420, 400, 0);
    glVertex3f(460, 400, 0);
    glVertex3f(460, 370, 0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    drawCircle(420, 400, 10);
    drawCircle(460, 400, 10);

   // glColor3f(1.0, 0.0, 0.0);
   // drawCircle(400, 400, 20);

   

    glColor3f(0.8, 0.8, 0.8);
    if (keyX==390 || keyX==385) {
        drawRect(400, d, bridgeWidth, 20);
     
    }
    //double powerUpScore = 0;
    if (keyX == 390 && keyY==330) {
       
        double powerUpScore =  15;
        glColor3f(1, 1, 1);
        char* p0s[20];
        srand((unsigned)time_t(16));
        sprintf((char*)p0s, "                 Congrarts!! Powerup Score: %d", 15);
        print(500, 300, (char*)p0s);
        glutPostRedisplay();
        
    }
   
  

}
void collectingCoins(double score) {
    int arrSize = sizeof(posOfCoins) / sizeof(posOfCoins[0]);

    for (int i = 0; i < arrSize; i++) {

        if (keyX == posOfCoins[i]) {
            score = score +1;
        }
    }


}



// draws rectangles using the (x,y) of the bottom left vertex, width (w) and height (h)
void drawRect(int x, int y, int w, int h) {
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + h);
    glVertex2f(x, y + h);
    glEnd();
}


void drawCircle(int x, int y, float r) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    GLUquadric* quadObj = gluNewQuadric();
    gluDisk(quadObj, 0, r, 50, 50);
    glPopMatrix();
}



void key(unsigned char k, int x, int y)//keyboard function, takes 3 parameters

{
    if (k == 'd') { //if the letter d is pressed, then the object will be translated in the x axis by 10 (moving to the right).
        if (keyX <= 680) {
            keyX += 10;
        }
        
    }
    if (k == 'a') {//if the letter a is pressed, then the object will be translated in the x axis by -10 (moving to the left).
        if (keyX > 20) {
            keyX -= 10;
        }
    }
    if (k == 'w') {//if the letter w is pressed, then the object will be translated in the y axis by 10. (moving upwords)
        if (keyY <= 660) {
            keyY += 10;
        }
    }
    if (k == 's') {
        if (keyY > 20) {//if the letter w is pressed, then the object will be translated in the y axis by -10. (moving downwords)
            keyY -= 10;
        }

    }
    glutPostRedisplay();//redisplay to update the screen with the changes


}
void Timer(int value) {
    for (int i = 0; i <= numberOfLanes; i++) {
        start[i] = rand() % (800 - 40 - bridgeWidth) + 20;
    }

  
    glutTimerFunc(5 * 1000, Timer, 0);
    glutPostRedisplay();
}




void Display() {

    glClear(GL_COLOR_BUFFER_BIT);

    //Border of the maze
    glBegin(GL_QUADS); // GL_QUAD_STRIP
    glColor3f(0, 0, 0);
    //left border
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 800.0f, 0.0f);
    glVertex3f(20.0f, 800.0f, 0.0f);
    glVertex3f(20.0f, 0.0f, 0.0f);

    //top border
    glVertex3f(20.0f, 780.0f, 0.0f);
    glVertex3f(20.0f, 800.0f, 0.0f);
    glVertex3f(800.0f, 800.0f, 0.0f);
    glVertex3f(800.0f, 780.0f, 0.0f);



    //right border
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(800.0f, 0.0f, 0.0f);
    glVertex3f(800.0f, 800.0f, 0.0f);
    glVertex3f(780.0f, 800.0f, 0.0f);
    glVertex3f(780.0f, 0.0f, 0.0f);



    //bottom border
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 20.0f, 0.0f);
    glVertex3f(800.0f, 20.0f, 0.0f);
    glVertex3f(800.0f, 0.0f, 0.0f);
    glEnd();


    //circles
    glColor3f(1.0, 0.0, 0.0);
    drawCircle(50, 790, 5);
    drawCircle(65, 790, 5);
    drawCircle(80, 790, 5);




    drawLaneBorders();
    drawBridges();

    drawCoins();
    collectingCoins(score);
    powerUp();
   // glutPostRedisplay();

    glColor3f(1, 0, 0);
    char* p0s[20];
    sprintf((char*)p0s, "Score: %d", score);
    print(500, 300, (char*)p0s);
    glutPostRedisplay();
  


    //Player

    glPushMatrix();
    glColor3f(0.5, 0.0, 0.0);
    glTranslated(keyX, keyY, 0);
    drawCircle(55, 65, 25);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslated(keyX, keyY, 0);
    drawCircle(44, 65, 10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslated(keyX, keyY, 0);
    drawCircle(64, 65, 10);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(keyX, keyY, 0);
    drawCircle(44, 65, 5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(keyX, keyY, 0);
    drawCircle(64, 65, 5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(keyX, keyY, 0);
    drawCircle(44, 65, 5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslated(keyX, keyY, 0);
    glBegin(GL_LINE_STRIP);

    glVertex3f(44, 53, 0);
    glVertex3f(48, 50, 0);
    glVertex3f(52, 50, 0);
    glVertex3f(56, 50, 0);
    glVertex3f(60, 53, 0);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glColor3f(0.4, 0.4, 0.4);
    glTranslated(keyX, keyY, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(40, 89, 0);
    glVertex3f(55, 110, 0);
    glVertex3f(70, 89, 0);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glColor3f(0.5, 0.0, 0.0);
    glTranslated(keyX, keyY, 0);
    glBegin(GL_LINES);
    glVertex3f(30, 65, 0);
    glVertex3f(20, 85, 0);
    glVertex3f(80, 65, 0);
    glVertex3f(90, 85, 0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.0, 0.0);
    glTranslated(keyX, keyY, 0);
    drawRect(60, 28, 5, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.0, 0.0);
    glTranslated(keyX, keyY, 0);
    drawRect(45, 28, 5, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.4, 0.4, 0.4);
    glTranslated(keyX, keyY, 0);
    drawCircle(47, 28, 3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.4, 0.4, 0.4);
    glTranslated(keyX, keyY, 0);
    drawCircle(62, 28, 3);
    glPopMatrix();


    

    glPushMatrix();
    glColor3f(0.0, 0.25, 0.0);
    drawRect(700, 800 - (800 / numberOfLanes) + 40, 70, (800 / numberOfLanes) / 2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0, 0, 0);
    drawCircle(715, 800 - (800 / numberOfLanes) + ((800 / numberOfLanes) / 2), 5);
    glPopMatrix();

   

    glFlush();
}

void main(int argc, char** argr) {
    glutInit(&argc, argr);


    glutInitWindowSize(800, 800);
    glutInitWindowPosition(250, 25);

    


    glutCreateWindow("2D maze");
    glutDisplayFunc(Display);
    glutKeyboardFunc(key);
    glutTimerFunc(0, Timer, 0);
 //   glutIdleFunc(Anim);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glClearColor(0.8f, 0.8f, 0.8f, 0.0f);
    glShadeModel(GL_SMOOTH);
    PlaySound(TEXT("song.wav"), NULL, SND_ASYNC);
    gluOrtho2D(0, 800, 0, 800);




    glutMainLoop();
}
