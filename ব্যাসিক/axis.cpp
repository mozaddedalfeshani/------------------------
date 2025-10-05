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
    glClearColor(1.0, 1.0, 1.0, 1.0); // সাদা ব্যাকগ্রাউন্ড
    glClear(GL_COLOR_BUFFER_BIT);
    

    // অরিজিন
    glColor3f(1.0, 0.0, 0.0); // লাল বিন্দু
    glBegin(GL_POINTS);
    glVertex2f(0.0, 0.0);
    glEnd();

    // এক্স অ্যাক্সিস (লাল)
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(1.0, 0.0);
    glVertex2f(-1.0, 0.0);
    glEnd();
    
    // ওয়াই অ্যাক্সিস (নীল)
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(0.0, 1.0);
    glVertex2f(0.0, -1.0);
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
