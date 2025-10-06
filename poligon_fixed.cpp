#include <iostream>
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

float x[10], y[10];
int n;

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
    
    // Draw outline
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < n; i++) {
        glVertex2f(x[i], y[i]);
    }
    glEnd();

    // Draw filled polygon
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++) {
        glVertex2f(x[i], y[i]);
    }
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    std::cout << "Enter number of vertices: ";
    std::cin >> n;
    if(n < 3 || n > 10) {
        std::cout << "Number of vertices must be between 3 and 10" << std::endl;
        return 0;
    }
    std::cout << "Enter the vertices: (x y) in range -1 to 1" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Enter x" << i+1 << " y" << i+1 << ": ";
        std::cin >> x[i] >> y[i];
    }

    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Polygon Drawing");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

