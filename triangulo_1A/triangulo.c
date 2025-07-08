#include <GL/glut.h>

int init()
{
    glClearColor(0, 0, 0, 0);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 200, 0, 150);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        glColor3f(0, 0, 1); glVertex2f(100, 140);
        glColor3f(0, 1, 0); glVertex2f(20, 10);
        glColor3f(1, 0, 0); glVertex2f(180, 10);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(400, 300);
    glutInitWindowPosition(200, 200);

    glutCreateWindow("Teste OpenGL");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}