#include <GL/glut.h>

void init()
{
    glClearColor(1, 1, 1, 0);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 200, 0, 150);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 0, 0);

    // cabeça
    glBegin(GL_QUADS);
        glVertex2f(90, 140);
        glVertex2f(90, 120);
        glVertex2f(110, 120);
        glVertex2f(110, 140);
    glEnd();

    glLineWidth(2.5);
    glBegin(GL_LINES);
        // corpo
        glVertex2f(100, 120);
        glVertex2f(100, 65);
        // braço
        glVertex2f(100, 112);
        glVertex2f(122, 100);
        glVertex2f(100, 112);
        glVertex2f(78, 100);
        // pernas
        glVertex2f(100, 65);
        glVertex2f(122, 43);
        glVertex2f(100, 65);
        glVertex2f(78, 43);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(400, 300);
    glutInitWindowPosition(200, 200);

    glutCreateWindow("Boneco 2D");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}