#include <GL/glut.h>
#include <cmath>

float sunY = -0.8f; // Initial Y position of the sun

void init() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // Sky blue background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1, 1, -1, 1); // Coordinate system from -1 to 1 in both axes
}

void drawSun() {
    glColor3f(1.0f, 0.5f, 0.0f); // Orange color for the sun
    float angle;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        angle = i * 3.1416 / 180;
        glVertex2f(0.2f * cos(angle), sunY + 0.2f * sin(angle));
    }
    glEnd();
}

void drawGround() {
    glColor3f(0.2f, 0.8f, 0.2f); // Green color for the ground
    glBegin(GL_POLYGON);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(1.0f, -0.2f);
        glVertex2f(-1.0f, -0.2f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawSun();      // Draw the sun first (behind the ground)
    drawGround();   // Draw ground on top
    glFlush();
}

void update(int value) {
    if (sunY < 0.6f) sunY += 0.002f; // Sun moves up gradually
    glutPostRedisplay();            // Redraw the scene
    glutTimerFunc(30, update, 0);   // Call update again after 30ms
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Sunrise Animation");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
