#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>

float angle = 45.0;  // Sudut rotasi dalam derajat

void display() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Latar belakang putih (RGBA: 1.0, 1.0, 1.0, 1.0)
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Atur warna garis menjadi merah
    glColor3f(1.0, 0.0, 0.0);

    // Atur lebar garis
    glLineWidth(10.0);

    // Gambar garis dari A(3,6) ke B(7,1)
    glBegin(GL_LINES);
    glVertex2f(3.0, 6.0);  // Titik A
    glVertex2f(7.0, 1.0);  // Titik B
    glEnd();

    // Matriks translasi untuk garis koordinat
    glLoadIdentity();
    glLineWidth(1000.0);

    // Gambar garis koordinat (X dan Y)
    glColor3f(0.0, 0.0, 0.0);  // Warna hitam
    glBegin(GL_LINES);
    glVertex2f(-10.0, 0.0);  // Garis X
    glVertex2f(10.0, 0.0);
    glVertex2f(0.0, -10.0);  // Garis Y
    glVertex2f(0.0, 10.0);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL Rotasi");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
