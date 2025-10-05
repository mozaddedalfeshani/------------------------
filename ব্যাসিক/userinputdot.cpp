
// Start of Selection
#include <iostream>
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

float x1, y1_coord, x2, y2;

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3.0f);
    glColor3f(1.0, 0.0, 0.0); // Red line
    glBegin(GL_LINES);
    glVertex2f(x1, y1_coord);
    glVertex2f(x2, y2);
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    std::cout << "Enter x1 y1: ";
    std::cin >> x1 >> y1_coord;
    std::cout << "Enter x2 y2: ";
    std::cin >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Line Drawing");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
