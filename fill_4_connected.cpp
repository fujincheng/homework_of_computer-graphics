#include <GLUT/glut.h>
#include <cmath>
#include <iostream>
#include <stack>
using namespace std;

struct Vec2
{
public:
    float x, y;
    Vec2() {}
    Vec2(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
};

struct Vec2i
{
public:
    int x, y;
    Vec2i(){}
    Vec2i(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

void drawDot(Vec2 p)
{
    glBegin(GL_POINTS);
    glVertex2f(p.x, p.y);
    glEnd();
    glFlush();
}

void drawDoti(Vec2i p)
{
    glBegin(GL_POINTS);
    glVertex2i(p.x, p.y);
    glEnd();
    glFlush();
}

void drawLine(Vec2 p1, Vec2 p2)
{
    glBegin(GL_LINES);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x, p2.y);
    glEnd();
    glFlush();
}

GLubyte BoundaryColor[3] = { 0,0,0 };
GLubyte InteriorColor[3] = { 255,0,0 };
GLubyte iPixelColor[3];

bool isSameColor(GLubyte* a, GLubyte* b)
{
    int dis = 1;
    if(abs(a[0] - b[0]) <= dis && abs(a[1] - b[1]) <= dis && abs(a[2] - b[2]) <= dis)
        return true;
    else
        return false;
}

void Fill_Boundary_4_Connected(int x, int y)
{
    stack<Vec2i> vecStack;
    vecStack.push(Vec2i(x, y));
    while(!vecStack.empty())
    {
        Vec2i tempVec = vecStack.top();
        vecStack.pop();
        int xx = tempVec.x, yy = tempVec.y;
        glReadPixels(xx, yy, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &iPixelColor);
        if (!isSameColor(iPixelColor,BoundaryColor)&& !isSameColor(iPixelColor, InteriorColor))
        {
            drawDoti(Vec2i(xx,yy));
            vecStack.push(Vec2i(xx, yy+1));
            vecStack.push(Vec2i(xx, yy-1));
            vecStack.push(Vec2i(xx-1, yy));
            vecStack.push(Vec2i(xx+1, yy));
        }
    }
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.0, 0.0, 0.0);
    
    Vec2 p1(220.0, 250.0);
    Vec2 p2(300, 300.0);
    Vec2 p3(380.0, 250.0);
    Vec2 p4(300.0, 200.0);
    drawLine(p1, p2);
    drawLine(p2, p3);
    drawLine(p3, p4);
    drawLine(p1, p4);
    
    glColor3f(255, 0, 0);
    Fill_Boundary_4_Connected(300, 250);
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 600.0, 0.0, 500);
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 50);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Fill_Boundary");
    
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
}