#include <iostream>
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

float boatX = -1.2f; // Starting position (off-screen to the left)
float speed = 0.002f; // Movement speed

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void drawBoat() {
    // Draw boat body
    glColor3f(0.4f, 0.2f, 0.0f); // Brown
    glBegin(GL_POLYGON);
    glVertex2f(boatX - 0.2f, -0.4f);
    glVertex2f(boatX + 0.2f, -0.4f);
    glVertex2f(boatX + 0.15f, -0.5f);
    glVertex2f(boatX - 0.15f, -0.5f);
    glEnd();

    // Draw sail
    glColor3f(0.8f, 0.8f, 0.8f); // Light gray
    glBegin(GL_TRIANGLES);
    glVertex2f(boatX, -0.4f);
    glVertex2f(boatX, 0.1f);
    glVertex2f(boatX + 0.2f, -0.4f);
    glEnd();

    // Draw boat mast
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex2f(boatX, -0.4f);
    glVertex2f(boatX, 0.1f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Draw water
    glColor3f(0.2f, 0.6f, 1.0f); // Blue water
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    // Draw sky
    glColor3f(0.5f, 0.8f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(-1.0f, -0.5f);
    glEnd();

    // Draw the moving boat
    drawBoat();

    glutSwapBuffers();
}

void timer(int value) {
    // Move boat to the right
    boatX += speed;
    if (boatX > 1.2f) boatX = -1.2f; // Reset to left after going off-screen

    glutPostRedisplay();       // Redraw
    glutTimerFunc(16, timer, 0); // ~60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 50);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("Animated Boat - OpenGL");

    glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // Sky blue background
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0); // Start animation

    glutMainLoop();
    return 0;
}
// g++ -o triangle *ইনপুট*/triangle.cpp -framework OpenGL -framework GLUT