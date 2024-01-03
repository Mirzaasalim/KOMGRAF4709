#include <GL/gl.h>
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Atur warna garis menjadi merah
    glColor3f(1.0, 0.0, 0.0);

    // Atur lebar garis
    glLineWidth(1000.0);

    // Gambar garis koordinat (X dan Y)
    glBegin(GL_LINES);
    glVertex2f(-10.0, 0.0);  // Garis X
    glVertex2f(10.0, 0.0);
    glVertex2f(0.0, -10.0);  // Garis Y
    glVertex2f(0.0, 10.0);
    glEnd();

    // Atur ukuran titik
    glPointSize(1.0);

    // Gambar titik A(3,6)
    glBegin(GL_POINTS);
    glVertex2f(3.0, 6.0);  // Titik A
    glEnd();

    // Gambar titik B(7,1)
    glBegin(GL_POINTS);
    glVertex2f(7.0, 1.0);  // Titik B
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL Translasi");

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
