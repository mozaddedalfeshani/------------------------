#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(20);
    glBegin(GL_POINTS);

    glColor3f(1.0, 0.0, 1.0);
    glVertex2f(0.75, 0.75);

    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(-0.75, 0.75);

    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.75, -0.75);

    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.75, -0.75);

    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.0, 0.0);

    glEnd();

    glBegin(GL_LINES);
    glVertex2f(1.0, 0.0);
    glVertex2f(-1.0, 0.0);
    glVertex2f(0.0, 1.0);
    glVertex2f(0.0, -1.0);

    glVertex2f(0.75, 0.75);
    glVertex2f(-0.75, 0.75);
    glVertex2f(-0.75, 0.75);
    glVertex2f(-0.75, -0.75);
    glVertex2f(-0.75, -0.75);
    glVertex2f(0.75, -0.75);
    glVertex2f(0.75, -0.75);
    glVertex2f(0.75, 0.75);
    glEnd();

    glBegin(GL_POINTS);
    for (float x = 0.0; x <= 0.75; x += 0.001) {
        for (float y = 0.0; y >= -0.75; y -= 0.001) {
            glColor3f(1.0, 0.0, 0.0);
            glVertex2f(x, y);
        }
    }
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}