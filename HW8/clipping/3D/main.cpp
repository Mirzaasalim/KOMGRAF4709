#include <GL/glut.h>
#include <cmath>

float translationX = 0.0f; // Translasi dalam sumbu X

void drawTriangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3) {
    glBegin(GL_TRIANGLES);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x3, y3, z3);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    // Warna sebelum translasi (merah)
    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f); // Translasi awal
    drawTriangle(0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f, 1.0f, 0.0f);
    glPopMatrix();

    // Warna setelah translasi (hijau)
    glColor3f(0.0f, 1.0f, 0.0f);
    glPushMatrix();
    glTranslatef(translationX, 0.0f, 0.0f); // Translasi sepanjang sumbu X
    drawTriangle(0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.5f, 1.0f, 0.0f);
    glPopMatrix();

    glutSwapBuffers();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0f, 1.0f, 1.0f, 10.0f); // Proyeksi perspektif

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(3.0f, 3.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f); // Atur matriks pandangan
}

void update(int value) {
    translationX += 0.01f; // Pergeseran sepanjang sumbu X
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Tambahkan GLUT_DEPTH untuk buffer kedalaman
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL 3D Segitiga dengan Translasi dan Warna");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0); // Set timer untuk update secara periodik

    glutMainLoop();

    return 0;
