#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <stack>
#include <GLUT/GLUT.h>
#define PI 3.14159f
#define n 3

struct point{
    float x;
    float y;
    float angle;
};
std::string define_string(){
    std::string tree = "B";
    for (int j = 0; j < n; j++) {
        for(int i = 0; tree[i] != '\0'; i++){
            switch (tree[i]) {
                case 'A':
                    tree.replace(i, 1, "AA");
                    i += 1;
                    break;
                
                case 'B':
                    tree.replace(i, 1, "A[B]AA(B)");
                    i += 9;
                    break;
                
                default:
                    break;
            }
        }
    }
    return tree;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    GLfloat x = 0.0, y = -1.0, angle = 0.0;
    std::string tree = define_string();
    
    std::stack<point> mystack;
    point init, temp;
    init.x = x;
    init.y = y;
    init.angle = angle;
    mystack.push(init);
    
    for (int i = 0; tree[i] != '\0'; i++) {
        switch (tree[i]) {
            case 'A':
                glColor3f( 1.0f, 1.0f, 0.0f );
                glVertex2f(mystack.top().x, mystack.top().y);
                mystack.top().x += 0.1*sin(mystack.top().angle);
                mystack.top().y += 0.1*cos(mystack.top().angle);
                glVertex2f(mystack.top().x, mystack.top().y);
                break;
                
            case '[':
                temp.angle = mystack.top().angle - PI/4;
                temp.x = mystack.top().x;
                temp.y = mystack.top().y;
                mystack.push(temp);
                break;
                
            case 'B':
                glColor3f( 1.0f, 1.0f, 1.0f );
                glVertex2f(mystack.top().x, mystack.top().y);
                mystack.top().x += 0.1*sin(mystack.top().angle);
                mystack.top().y += 0.1*cos(mystack.top().angle);
                glVertex2f(mystack.top().x, mystack.top().y);
                break;
                
            case ']':
                mystack.pop();
                break;
                
            case '(':
                temp.angle = mystack.top().angle + PI/4;
                temp.x = mystack.top().x;
                temp.y = mystack.top().y;
                mystack.push(temp);
                break;
                
            case ')':
                mystack.pop();
                break;
        }
    }
    
    glEnd();
    glFlush();
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600,500);
    glutCreateWindow("L-SYSTEM");
    glutDisplayFunc(display);
    glutMainLoop();
}