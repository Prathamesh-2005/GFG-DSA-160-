#include <GL/glut.h>

float angle = 0.0f;  // Rotation angle

void init() {
    glEnable(GL_DEPTH_TEST);  // Enable depth testing for 3D rendering
    glClearColor(1.0, 1.0, 1.0, 1.0);  // White background
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Move cube back a bit and apply rotation
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);  // Rotate about Y-axis

    // Draw cube with different colored faces
    glBegin(GL_QUADS);

    // Front face (red)
    glColor3f(1, 0, 0);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(-1, 1, 1);

    // Back face (green)
    glColor3f(0, 1, 0);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, -1);

    // Left face (blue)
    glColor3f(0, 0, 1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);

    // Right face (yellow)
    glColor3f(1, 1, 0);
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, 1);

    // Top face (cyan)
    glColor3f(0, 1, 1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);

    // Bottom face (magenta)
    glColor3f(1, 0, 1);
    glVertex3f(-1, -1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);

    glEnd();
    glutSwapBuffers();
}

void rotateCube() {
    angle += 0.2f;  // Increase angle
    if (angle > 360) angle -= 360;
    glutPostRedisplay();  // Redisplay
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    float ratio = (float)w / (float)h;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, ratio, 1, 100);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Cube Rotation about Vertical Axis");

    init();
    glutDisplayFunc(display);
    glutIdleFunc(rotateCube);  // Continuous rotation
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
