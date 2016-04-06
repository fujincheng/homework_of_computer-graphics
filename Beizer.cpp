#include <GLUT/GLUT.h>
#define N 1

typedef struct point{
    float x;
    float y;
}point;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin( GL_LINES );
    point p0, p1, p2, p3;
    p0.x = -0.8; p0.y = 0;
    p1.x = -0.5; p1.y = 0.3;
    p2.x = 0.5; p2.y = 0.3;
    p3.x = 0.8; p3.y = 0;
    
    double t = 0;
    int count = 100;
    double dt = 1.0/100;
    glVertex2f(p0.x, p0.y);

    for (int i = 0; i < count; i++) {
        point p01, p11, p21, p02, p12, p03;
        p01.x = (1-t)*p0.x + t*p1.x;
        p01.y = (1-t)*p0.y + t*p1.y;
        
        p11.x = (1-t)*p1.x + t*p2.x;
        p11.y = (1-t)*p1.y + t*p2.y;
        
        p21.x = (1-t)*p2.x + t*p3.x;
        p21.x = (1-t)*p2.y + t*p3.y;
        
        p02.x = (1-t)*p01.x + t*p11.x;
        p02.y = (1-t)*p01.y + t*p11.y;
        
        p12.x = (1-t)*p11.x + t*p21.x;
        p12.y = (1-t)*p11.y + t*p21.y;
        
        p03.x = (1-t)*p02.x + t*p12.x;
        p03.y = (1-t)*p02.y + t*p12.y;
        
        glVertex2f(p03.x, p03.y);
        glVertex2f(p03.x, p03.y);
        t += dt;
    }
    
    glEnd();
    glFlush();
}

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(600,500);
    glutCreateWindow("de Cateljau");
    glutDisplayFunc(display);
    glutMainLoop();
}