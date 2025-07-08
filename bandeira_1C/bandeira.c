#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926

float rgb(float valor) {
    return valor / 255;
}

void circulo(float cx, float cy, float r, int segm) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < segm; i++) {
        float theta = 2.0f * PI * (float)i / (float)segm;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void escreverTexto(float x, float y, void *fonte, const char *texto) {
    glRasterPos2f(x, y);
    while (*texto) {
        glutBitmapCharacter(fonte, *texto);
        texto++;
    }
}

void init() {
    // Definindo cor de fundo
    glClearColor(rgb(16), rgb(158), rgb(76), 0);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 288, 0, 162);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(rgb(251), 1, rgb(6));
    glBegin(GL_QUADS);
        glVertex2f(20, 81);
        glVertex2f(144, 142);
        glVertex2f(268, 81);
        glVertex2f(144, 20);
    glEnd();

    glColor3f(rgb(36), rgb(50), rgb(113));
    circulo(144, 81, 42, 100);

    glLineWidth(8);
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
        glVertex2f(102, 79);
        glVertex2f(186, 79);
        glVertex2f(102, 83);
        glVertex2f(186, 83);
    glEnd();

    glColor3f(rgb(25), rgb(172), rgb(102));
    escreverTexto(109, 79.5, GLUT_BITMAP_HELVETICA_10, "ORDEM E PROGRESSO");

    glColor3f(1, 1, 1);
    glPointSize(3.5); 

    glBegin(GL_POINTS);
        glVertex2f(130, 65);
        glVertex2f(135, 60);
        glVertex2f(140, 70);
        glVertex2f(150, 60);
        glVertex2f(155, 68);
        glVertex2f(160, 64);
        glVertex2f(165, 62);
        glVertex2f(170, 66);
        glVertex2f(158, 90);
        glVertex2f(144, 81);
    glEnd();

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(480, 270);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bandeira do Brasil");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}