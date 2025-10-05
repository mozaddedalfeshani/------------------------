#ifdef __APPLE__ //  এটা অ্যাপল কে ডিসপ্লে রিটার্ন করার জন্য দিলাম 
#define GL_SILENCE_DEPRECATION 
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

// ডিসপ্লে ফাংশন ডিফাইন করলাম 
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(15);
    
    // 5টি রান্ডম রঙের পয়েন্ট আঁকবো
    glBegin(GL_POINTS);
    
    // পয়েন্ট 1: (0,0) - লাল
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.0, 0.0);
    
    // পয়েন্ট 2: (0.75, 0.75) - সবুজ
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.75, 0.75);
    
    // পয়েন্ট 3: (-0.75, -0.75) - নীল
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-0.75, -0.75);
    
    // পয়েন্ট 4: রান্ডম পজিশন - হলুদ
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(0.5, -0.5);
    
    // পয়েন্ট 5: রান্ডম পজিশন - ম্যাজেন্টা
    glColor3f(1.0, 0.0, 1.0);
    glVertex2f(-0.5, 0.5);
    
    glEnd();
    glFlush();
}

// মেইন ফাংশন ডিফাইন করলাম 
int main(int argc, char* argv[]){
    glutInit(&argc, argv); // গ্লাট ইনিট ফাংশন কল করলাম 
    glutInitWindowSize(800, 600); // উইন্ডো সাইজ সেট করলাম 
    glutInitWindowPosition(10, 10); // উইন্ডো পোজিশন সেট করলাম 
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // ডিসপ্লে মোড সেট করলাম 
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display); // ডিসপ্লে ফাংশন কল করলাম 
    glutMainLoop(); // গ্লাট মেইন লুপ কল করলাম 
    return 0; // রিটার্ন করলাম 
}
