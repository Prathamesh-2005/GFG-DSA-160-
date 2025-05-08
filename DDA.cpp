#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;
void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
struct point
{
    int x, y;
};
void dda(point p1, point p2)
{
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int steps = max(abs(dx), abs(dy));
    float xinc = dx/ (float)steps;
    float yinc = dy / (float)steps;
    float x = p1.x;
    float y = p1.y;
    plot(round(x), round(y));
    for (int i = 0; i <= steps; i++)
    {
        plot(round(x), round(y));
        x += xinc;
        y += yinc;
    }
}
void init()
{
    glClearColor(1, 1, 1, 1);
    glColor3f(0, 0, 0);
    glPointSize(2);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-360, 360, -270, 270);
}
vector<point> points;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    for (size_t i = 0; i + 1 < points.size(); i+=2)
    {
        dda(points[i], points[i + 1]);
    }
    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        point p = {x - 360, 270- y};
        points.push_back(p);
        glutPostRedisplay();
    }
    if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
    {
       points.clear();
       glutPostRedisplay();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(720, 540);
    glutCreateWindow("GOOD NIGHT");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
