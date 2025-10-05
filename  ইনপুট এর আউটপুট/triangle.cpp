#include <iostream>
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

float x1, y1_coord, x2, y2, x3, y3;

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // Keeps coordinate range [-1,1]
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Filled red triangle
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1_coord);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();

    // Black outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1_coord);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    std::cout << "Enter x1 y1: ";
    std::cin >> x1 >> y1_coord;
    std::cout << "Enter x2 y2: ";
    std::cin >> x2 >> y2;
    std::cout << "Enter x3 y3: ";
    std::cin >> x3 >> y3;

    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 50);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Triangle Drawing - OpenGL");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(1.0, 1.0, 1.0, 1.0); // White background

    glutMainLoop();
    return 0;
}