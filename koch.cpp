#include <bits/stdc++.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

int n;

void init() {
    glClearColor(1, 1, 1, 1);
    glColor3f(0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-360, 360, -270, 270);
}

float ang(float d) {
    return (d * M_PI) / 180;
}

void draw_koch(float xa, float ya, float xb, float yb, int n) {
    // Calculate the coordinates of points that divide the line into three parts
    float xc = xa + (xb - xa) / 3;
    float yc = ya + (yb - ya) / 3;
    
    float xd = xa + 2 * (xb - xa) / 3;
    float yd = ya + 2 * (yb - ya) / 3;

    // Calculate the coordinates of the apex of the equilateral triangle
    float midx = xc + (xd - xc) * cos(ang(60)) - (yd - yc) * sin(ang(60));
    float midy = yc + (xd - xc) * sin(ang(60)) + (yd - yc) * cos(ang(60));

    if (n > 0) {
        // Recursive calls for the four parts of Koch curve
        draw_koch(xa, ya, xc, yc, n - 1);
        draw_koch(xc, yc, midx, midy, n - 1);
        draw_koch(midx, midy, xd, yd, n - 1);
        draw_koch(xd, yd, xb, yb, n - 1);
    }
    else {
        // Draw the four line segments
        glVertex2f(xa, ya);
        glVertex2f(xc, yc);
        
        glVertex2f(xc, yc);
        glVertex2f(midx, midy);
        
        glVertex2f(midx, midy);
        glVertex2f(xd, yd);
        
        glVertex2f(xd, yd);
        glVertex2f(xb, yb);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    // Draw Koch snowflake (triangle)
    draw_koch(0, -200, 173.2, 100, n);
    draw_koch(173.2, 100, -173.2, 100, n);
    draw_koch(-173.2, 100, 0, -200, n);
    glEnd();
    glFlush();
}

int main(int argc, char **argv) {
    cout << "\n[Koch Curve]" << endl;
    cout << "Enter the number of iterations: ";
    
    cin >> n;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(720, 540);
    glutCreateWindow("Koch Snowflake");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
