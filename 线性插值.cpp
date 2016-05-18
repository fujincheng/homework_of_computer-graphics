#include <GLUT/GLUT.h>
#include <time.h>
#include <unistd.h>
void display()
{
    GLfloat s_p1_x = -0.4, s_p1_y = -0.2, s_p2_x = -0.2, s_p2_y = -0.2, s_p3_x = -0.2, s_p3_y = 0.3;
    GLfloat f_p1_x = -0.2, f_p1_y = 0, f_p2_x = -0.2, f_p2_y = -0.2, f_p3_x = 0.3, f_p3_y = -0.2;
    GLfloat t_p1_x, t_p1_y, t_p2_x, t_p2_y, t_p3_x, t_p3_y;
    float n = 5;
    float t;
    for(float i = 0; i <= n+1; i++)
    {
        t = i/(n+1);
        t_p1_x = (1-t)*s_p1_x + t*f_p1_x;
        t_p1_y = (1-t)*s_p1_y + t*f_p1_y;
        t_p2_x = (1-t)*s_p2_x + t*f_p2_x;
        t_p2_y = (1-t)*s_p2_y + t*f_p2_y;
        t_p3_x = (1-t)*s_p3_x + t*f_p3_x;
        t_p3_y = (1-t)*s_p3_y + t*f_p3_y;
        
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        glVertex2f(t_p1_x, t_p1_y);
        glVertex2f(t_p2_x, t_p2_y);
        glVertex2f(t_p3_x, t_p3_y);
        glEnd();
        glFlush();
        sleep(1);
    }
}
int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 50);
    glutInitWindowSize(500, 400);
    glutCreateWindow("Demo");
    glutDisplayFunc(display);
    glutMainLoop();
}