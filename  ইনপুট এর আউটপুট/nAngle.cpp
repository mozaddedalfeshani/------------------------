#include <iostream>
#include <vector>
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

std::vector<std::pair<float,float>> vertices;

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
    glLoadIdentity();

    // Filled red polygon
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (auto &v : vertices)
        glVertex2f(v.first, v.second);
    glEnd();

    // Black outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    for (auto &v : vertices)
        glVertex2f(v.first, v.second);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    int n;
    std::cout << "Enter number of vertices (3 for triangle, 4 for quadrilateral, etc.): ";
    std::cin >> n;
    if(n < 3 && n > 10) {
        std::cout << "Number of vertices must be between 3 and 10" << std::endl;
        return 0;
    }
   
    vertices.resize(n);
    for (int i = 0; i < n; i++) {
        std::cout << "Enter x" << i+1 << " y" << i+1 << ": ";
        std::cin >> vertices[i].first >> vertices[i].second;
    }

    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 50);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Polygon Drawing - OpenGL");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(1.0, 1.0, 1.0, 1.0); // White background

    glutMainLoop();
    return 0;
}