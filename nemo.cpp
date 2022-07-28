#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sstream>
#include <GL\glut.h>
#include <stdbool.h>
#define UNUSED(param) (void)(param)
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
void fence();
void drawFood();
void spawnFood();
bool moved = false;
bool food_available = false;
int move_speed = 5;
int score = 0;
int start = 0;
float v1, v2;
int direction = LEFT;
float x = 100, y = 0, r = 0.5, y11 = 0, y21 = 0, y31 = 0, y41 = 0, y51 = 0, y61 = 0, y71 = 0, y81 = 0, y91 = 0, y10 = 0, y12 = 0, y13 = 0, y14 = 0, x0 = 0, xo = 0, angle = 0.0, pi = 3.142;
float s = 400, ss = 140, a = 0, b = 0, aa = -70, bb = 0, flag = 0, flag1 = 0;

void delay(int k){
    for(int k=0;k<2;k++){
    for(int i=1;i<=32767;i++){
        for(int j=1;j<=32767;j++){
            
        }
    }}
}

void drawstring(float x, float y, float z, char *string, int f)
{
    char *c;
    glRasterPos3f(x, y, z);
    for (c = string; *c != '\0'; c++)
    {
        if (f == 0)
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *c);
        else
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

void screen()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    drawstring(210, 425, 0.0, "VIVEKANANDA COLLEGE OF ENGINEERING AND TECHNOOLOGY", 1);
    glColor3f(1, 1, 1);
    drawstring(245, 385, 0.0, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING", 1);
    glColor3f(1, 1, 1);
    drawstring(210, 350, 0.0, "A MINI PROJECT ON COMPUTER GRAPHICS AND VISUALIZATION", 1);
    glColor3f(0, 1, 1);
    drawstring(440, 300, 0.0, "FINDING NEMO", 1);
    glColor3f(1.0, 0.0, 0.0);
    drawstring(135, 205, 0.0, " STUDENT NAME", 0);
    glColor3f(1, 1, 1);
    drawstring(140, 170, 0.0, "AMRUTHA B", 0);
    drawstring(140, 135, 0.0, "K G VARUN RAI", 0);
    glColor3f(1.0, 0.0, 0.0);
    drawstring(710, 205, 0.0, " Under the Guidance of", 0);
    glColor3f(1, 1, 1);
    drawstring(720, 170, 0.0, "Prof KRISHNA MOHANA A J", 0);
    drawstring(720, 135, 0.0, "Prof AJAY SHASTRY C G", 0);
    glColor3f(1.0, 1.0, 0.0);
    drawstring(435, 95, 0.0, "Academic Year 2021-22", 0);
    glFlush();
}

void manual()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1, 1);
    drawstring(430, 425, 0.0, "FINDING NEMO", 1);
    glColor3f(1, 0, 0);
    drawstring(310, 385, 0.0, "HELP NEMO's FATHER TO FIND NEMO", 1);
    glColor3f(1, 1, 1);
    drawstring(260, 325, 0.0, "NEMO IS LOST. HIS FATHER IS IN SEARCH OF HIM IN THE VAST OCEAN.", 0);
    drawstring(260, 300, 0.0, "FINDS NEMO IN A TRAP AND NOW FATHER HAS TO HELP HIM TO GET OUT.", 0);
    drawstring(470, 275, 0.0, "W -> UP", 0);
    drawstring(470, 250, 0.0, "S -> DOWN", 0);
    drawstring(470, 225, 0.0, "A -> LEFT", 0);
    drawstring(470, 200, 0.0, "D -> RIGHT", 0);
    glColor3f(1, 0, 1);
    drawstring(200, 125, 0.0, "ARE YOU READY TO FIND NEMO BY COLLECTING THE FOOD.", 1);
    // glColor3f(1.0, 0.0, 0.0);
    // drawstring(135, 205, 0.0, " STUDENT NAME", 0);
    // glColor3f(1, 1, 1);
    // drawstring(140, 170, 0.0, "AMRUTHA B", 0);
    // drawstring(140, 135, 0.0, "K G VARUN RAI", 0);
    // glColor3f(1.0, 0.0, 0.0);
    // drawstring(710, 205, 0.0, " Under the Guidance of", 0);
    // glColor3f(1, 1, 1);
    // drawstring(720, 170, 0.0, "Prof KRISHNA MOHANA A J", 0);
    // drawstring(720, 135, 0.0, "Prof AJAY SHASTRY C G", 0);
    glColor3f(1.0, 1.0, 0.0);
    drawstring(400, 75, 0.0, "Press 'B' to start the game", 0);
    spawnFood();
    glFlush();
    // glutSwapBuffers();
}

void mov(void)
{
    if (a + 560 >= 1200)
    {
        flag = 2;
    }
    if (a + 270 < 0)
    {
        flag = 2;
    }
    if (aa + 505 >= 600)
    {
        flag = 2;
    }
    if (aa + 300 < 0)
    {
        flag = 2;
    }
    if (score == 5)
    {
        flag = 1;
    }
}

void gameover()
{
    aa = -50;
    a = 150;
}

void win()
{
    a = 90;
    aa = -70;
    b = -350;
    bb = 200;
}

void begin()
{
    a = 0;
    b = 0;
    aa = -70;
    bb = 0;
    score = 0;
    move_speed = 5;
    flag = 0;
}

void drawControls()
{
    glColor3f(0, 0, 0);
    char *move_message = (char *)"Use WASD or the arrow keys to move";
    char *exit_message = (char *)"Press ESC or Q to exit";
    drawstring(746, 475, 0, move_message, 0);
    drawstring(840, 455, 0, exit_message, 0);
}

void drawScore()
{
    glColor3f(0, 0, 0);
    const char *score_message = (char *)"Score: ";
    std::stringstream score_string;
    score_string << score_message << score;
    drawstring(30, 470, 0, (char *)score_string.str().c_str(), 0);
}

void drawFood()
{

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2d(0 + v1, 0 + v2);
    glVertex2d(10 + v1, 0 + v2);
    glVertex2d(10 + v1, 10 + v2);
    glVertex2d(0 + v1, 10 + v2);
    glEnd();
}

void spawnFood()
{
    if (food_available)
    {
        return;
    }

    bool collides;
    do
    {
        v1 = rand() % 1200;
        v2 = rand() % 600;
    } while (v1 < 100 || v2 < 100 || v1 > 900 || v2 > 400);

    do
    {
        collides = false;
        if (((280 + a) >= v1) && ((280 + a) <= (v1 + 10)) && ((355 + aa) >= v2) && ((355 + aa) <= (v2 + 10)))
            collides = true;
    } while (collides);

    food_available = true;
}

void fence()
{
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(885.0, 0.0);
    glVertex2f(885.0, 120.0);
    glVertex2f(905.0, 0.0);
    glVertex2f(905.0, 120.0);
    glVertex2f(925.0, 0.0);
    glVertex2f(925.0, 120.0);
    glVertex2f(945.0, 0.0);
    glVertex2f(945.0, 120.0);
    glVertex2f(965.0, 0.0);
    glVertex2f(965.0, 120.0);
    glVertex2f(985.0, 0.0);
    glVertex2f(985.0, 120.0);
    glVertex2f(1005.0, 0.0);
    glVertex2f(1005.0, 120.0);
    glVertex2f(1025.0, 0.0);
    glVertex2f(1025.0, 120.0);
    glVertex2f(885.0, 120.0);
    glVertex2f(1025.0, 0.0);
    glVertex2f(885.0, 120.0);
    glVertex2f(1025.0, 120.0);

    glEnd();
}

void fish2()
{
    glColor3f(255 / 255, 153 / 255.0, 51 / 255.0);
    glBegin(GL_POLYGON);
    glVertex2f(890 + b, 55 + bb);
    glVertex2f(920 + b, 30 + bb);
    glVertex2f(990 + b, 55 + bb);
    glVertex2f(920 + b, 80 + bb);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(980 + b, 55 + bb);
    glColor3ub(rand() % 1, rand() % 1000, rand() % 1000);
    glVertex2f(1025 + b, 75 + bb);
    glVertex2f(1015 + b, 55 + bb);
    glVertex2f(1025 + b, 32 + bb);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(rand() % 1, rand() % 1000, rand() % 1000);
    glVertex2f(922 + b, 78 + bb);
    glColor3f(255 / 255, 153 / 255.0, 51 / 255.0);
    glVertex2f(960 + b, 114 + bb);
    glVertex2f(940 + b, 65 + bb);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(rand() % 1, rand() % 1000, 0);
    glVertex2f(922 + b, 33 + bb);
    glColor3f(255 / 255, 153 / 255.0, 51 / 255.0);
    glVertex2f(960 + b, 5 + bb);
    glVertex2f(940 + b, 45 + bb);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(900 + b, 60 + bb);
    glEnd();
}

void fish1()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(270 + a, 350 + aa);
    glVertex2f(300 + a, 325 + aa);
    glVertex2f(370 + a, 350 + aa);
    glVertex2f(300 + a, 375 + aa);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(360 + a, 350 + aa);
    glColor3ub(rand() % 1, rand() % 1000, rand() % 1000);
    glVertex2f(405 + a, 370 + aa);
    glVertex2f(395 + a, 350 + aa);
    glVertex2f(405 + a, 327 + aa);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(rand() % 1, rand() % 1000, rand() % 1000);
    glVertex2f(302 + a, 373 + aa);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(340 + a, 409 + aa);
    glVertex2f(320 + a, 360 + aa);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(rand() % 1, rand() % 1000, 0);
    glVertex2f(302 + a, 328 + aa);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(340 + a, 300 + aa);
    glVertex2f(320 + a, 340 + aa);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(6.0);
    glBegin(GL_POINTS);
    glVertex2f(280 + a, 355 + aa);
    glEnd();
}

void moveFish(int new_direction)
{
    direction = new_direction;
    switch (direction)
    {
    case UP:
    {
        aa += 1;
        break;
    }
    case DOWN:
    {
        aa -= 1;
        break;
    }
    case RIGHT:
    {
        a += 1;
        break;
    }
    case LEFT:
    {
        a -= 1;
        break;
    }
    }
    food_available = true;
    if (((280 + a) >= v1) && ((280 + a) <= (v1 + 10)) && ((355 + aa) >= v2) && ((355 + aa) <= (v2 + 10)))
    {
        score += 1;
        printf("%d", score);
        food_available = false;
    }
    glutPostRedisplay();
}

void pbSmall()
{

    glBegin(GL_TRIANGLE_FAN);
    for (angle = 0; angle < 360.0; angle += .1)
    {
        glColor3ub(46, 47, 47);
        y = (sin(angle * pi / 180) * 30);
        x = (cos(angle * pi / 180) * 50);
        glVertex2f(x + 150, y - 5);
    }
    glEnd();
}

void pb()
{

    pbSmall();
    glBegin(GL_TRIANGLE_FAN);
    for (angle = 0; angle < 360.0; angle += .1)
    {
        glColor3ub(142, 20, 30);
        y = (sin(angle * pi / 180) * 45);
        x = (cos(angle * pi / 180) * 75);
        glVertex2f(x + 250, y - 10);
    }
    glEnd();
}

void pb1()
{

    glBegin(GL_TRIANGLE_FAN);
    for (angle = 0; angle < 360.0; angle += .1)
    {
        glColor3ub(20, 20, 20);
        y = (sin(angle * pi / 180) * 35);
        x = (cos(angle * pi / 180) * 65);
        glVertex2f(x + 370, y - 5);
    }
    glEnd();
}

void pb2()
{

    glBegin(GL_TRIANGLE_FAN);
    for (angle = 0; angle < 360.0; angle += .1)
    {
        glColor3ub(36, 60, 2);
        y = (sin(angle * pi / 180) * 40);
        x = (cos(angle * pi / 180) * 75);
        glVertex2f(x + 610, y + 10);
    }
    glEnd();
}

void special(int key, int x, int y)
{
    UNUSED(x);
    UNUSED(y);

    switch (key)
    {
    case GLUT_KEY_UP:
    {
        if (direction == LEFT || direction == RIGHT || direction == DOWN)
        {
            moved = true;
            moveFish(UP);
        }
        break;
    }
    case GLUT_KEY_DOWN:
    {
        if (direction == LEFT || direction == RIGHT || direction == UP)
        {
            moved = true;
            moveFish(DOWN);
        }
        break;
    }
    case GLUT_KEY_LEFT:
    {
        if (direction == UP || direction == DOWN || direction == RIGHT)
        {
            moved = true;
            moveFish(LEFT);
        }
        break;
    }
    case GLUT_KEY_RIGHT:
    {
        if (direction == UP || direction == DOWN || direction == LEFT)
        {
            moved = true;
            moveFish(RIGHT);
        }
    }
    }
}

void moveFishAuto(int value)
{
    if (!moved)
    {
        UNUSED(value);
        moveFish(direction);
    }
    else
    {
        moved = false;
    }
    glutTimerFunc(move_speed, moveFishAuto, 0);
}

void circleFunc(float yc, int d, int x1, int y1)
{
    for (angle = 0; angle < 360.0; angle += .1)
    {
        y = yc + (sin(angle * pi / 180) * d);
        x = (cos(angle * pi / 180) * d);
        glVertex2f(x + x1, y - y1);
    }
}

float checkBubPos(float y, float c)
{
    if (y < 500)
    {
        return y + c;
    }
    else
    {
        return 0;
    }
}

void circle(int x)
{
    glBegin(GL_POINTS);
    circleFunc(y21, 15, x + 10, 30);
    circleFunc(y31, 5, x, 60);
    circleFunc(y41, 7, x + 10, 90);
    circleFunc(y51, 12, x, 120);
    circleFunc(y61, 15, x + 10, 150);
    circleFunc(y71, 5, x, 180);
    circleFunc(y81, 3, x + 10, 210);
    circleFunc(y81, 15, x, 240);
    circleFunc(y91, 12, x + 10, 270);
    circleFunc(y10, 10, x, 300);
    circleFunc(y12, 16, x + 10, 330);
    circleFunc(y13, 15, x, 360);
    circleFunc(y14, 10, x + 10, 400);
    glEnd();
    y11 = checkBubPos(y11, 2.0);
    y21 = checkBubPos(y21, 3.0);
    y31 = checkBubPos(y31, 4.5);
    y41 = checkBubPos(y41, 7.0);
    y51 = checkBubPos(y51, 6.5);
    y61 = checkBubPos(y61, 18.0);
    y71 = checkBubPos(y71, 17.5);
    y81 = checkBubPos(y81, 8.0);
    y91 = checkBubPos(y91, 7.5);
    y10 = checkBubPos(y10, 10.0);
    y12 = checkBubPos(y12, 11.0);
    y14 = checkBubPos(y14, 8.0);
    y12 = checkBubPos(y12, 9.0);
    y13 = checkBubPos(y13, 1.0);
    glutPostRedisplay();
}

void plant3L(int x1, int x2, int m)
{
    int dis = x2 - x1;
    dis = dis / 3;
    glLoadIdentity();
    glColor3ub(40, 170, 5);
    glBegin(GL_POLYGON);
    glVertex2f(x1, 0);
    glVertex2f(x1 - 10, m - 10);
    glColor3f(0.0, 0.5, 0.0);
    glVertex2f(x1 + dis, 15);
    glVertex2f(x1 + ((x2 - x1) / 2), m);
    glVertex2f(x2 - dis, 15);
    glVertex2f(x2 + 12, m + 10);
    glVertex2f(x2, 0);
    glEnd();
}

void plant2L(int x1, int x2, int h1, int h2)
{

    glColor3ub(60, 170, 15);
    glBegin(GL_POLYGON);
    glVertex2f(x1, 0);
    glVertex2f(x1 - 20, h1);
    glColor3f(0.0, 0.3, 0.0);
    glVertex2f(x2, 0);
    glVertex2f(x1 + 15, h2);
    glEnd();
}

void plant()
{

    plant2L(50, 40, 40, 60);
    plant2L(95, 85, 50, 60);
    plant2L(120, 110, 45, 65);
    plant2L(70, 60, 60, 40);
    plant2L(140, 130, 43, 60);
    plant2L(950, 940, 40, 50);
    plant2L(870, 860, 50, 60);
    plant2L(470, 460, 40, 50);
    plant2L(490, 480, 55, 65);
    plant2L(520, 510, 40, 50);
    plant2L(540, 530, 50, 60);
    plant2L(700, 690, 40, 50);
    plant2L(730, 720, 55, 65);
    plant2L(795, 785, 40, 50);
    plant3L(10, 20, 60);
    plant3L(160, 170, 50);
    plant3L(310, 320, 70);
    plant3L(435, 445, 60);
    plant3L(750, 760, 55);
    plant3L(820, 830, 80);
    plant3L(900, 910, 55);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.6, 0.9, 0.0);
    glMatrixMode(GL_MODELVIEW);
    fish1();
    mov();
    plant();
    pbSmall();
    pb1();
    pb2();
    pb();
    fish2();
        if (flag == 0)
    {
        spawnFood();
        drawFood();
        fence();
    }
    if (flag == 1)
    {
        win();
        fish1();
        fish2();
        plant();
        pbSmall();
        pb1();
        pb2();
        pb();
        char *over = (char *)"CONGRATULATIONS!!! NEMO FOUND";
        drawstring(330, 400, 0, over, 1);
        char *replay = (char *)"PLAY AGAIN PRESS T";
        drawstring(420, 150, 0, replay, 1);
        char *quit = (char *)"QUIT PRESS Q";
        drawstring(450, 100, 0, quit, 1);
    }
    if (flag == 2)
    {
        gameover();
        fish1();
        plant();
        pbSmall();
        pb1();
        pb2();
        pb();
        char *over = (char *)"GAME OVER";
        drawstring(420, 400, 0, over, 1);
        char *replay = (char *)"PLAY AGAIN PRESS R";
        drawstring(380, 200, 0, replay, 1);
        char *quit = (char *)"QUIT PRESS Q";
        drawstring(420, 130, 0, quit, 1);
    }
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2.0);
    circle(30);
    circle(930);
    drawScore();
    drawControls();
    glFlush();
    glutSwapBuffers();
}

void reshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (h > w)
        gluOrtho2D(0, 500, ((float)h / (float)w) * (0), ((float)h / (float)w) * 500);
    else
        gluOrtho2D(((float)w / (float)h) * (0), ((float)w / (float)h) * (520), 0, 500);
    glMatrixMode(GL_MODELVIEW);
    glutReshapeWindow(1200, 600);
    glutPostRedisplay();
}

void displaynew(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    // glClearColor(0.0, 0.5, 0.3, 0.0);
    glMatrixMode(GL_MODELVIEW);
    if (start == 0)
    {
        screen();
        delay(10);
        manual();
    }
    else if (start == 1)
    {
                //glutReshapeFunc(reshape);
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);

        glutTimerFunc(move_speed, moveFishAuto, 0);
    }
    // glFlush();
    // glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    UNUSED(x);
    UNUSED(y);
    switch (key)
    {
    case 'w':
    {
        if (direction == LEFT || direction == RIGHT || direction == DOWN)
        {
            moved = true;
            moveFish(UP);
        }
        break;
    }
    case 's':
    {
        if (direction == LEFT || direction == RIGHT || direction == UP)
        {
            moved = true;
            moveFish(DOWN);
        }
        break;
    }
    case 'a':
    {
        if (direction == UP || direction == DOWN || direction == RIGHT)
        {
            moved = true;
            moveFish(LEFT);
        }
        break;
    }
    case 'd':
    {
        if (direction == UP || direction == DOWN || direction == LEFT)
        {
            moved = true;
            moveFish(RIGHT);
        }
        break;
    }
    case 'r':
    {
        flag = 0;
        score = 0;
        break;
    }
    case 't':
    {
        begin();
        direction = UP;
        if (direction == UP)
        {
            moveFish(LEFT);
        }
        break;
    }
    case 'b':
    {
        start = 1;

        direction = UP;
        if (direction == UP)
        {
            moveFish(LEFT);
        }
        break;
    }
    // Escape key
    case 27:
    case 'q':
    {
        exit(0);
    }
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitWindowPosition(400, 200);
    glutInitWindowSize(1200, 600);
    glutCreateWindow("FINDING NEMO");
    //glutTimerFunc(move_speed, moveFishAuto, 0);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutSpecialFunc(special);
    glutDisplayFunc(displaynew);
    glutMainLoop();
}
