#include <GL/glut.h>
#include <iostream>

using namespace std;

int x1, y1, x2, y2;

void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x = x1;
    int y = y1;
    int xIncrement = (x1 < x2) ? 1 : -1;
    int yIncrement = (y1 < y2) ? 1 : -1;

    glBegin(GL_POINTS);

    if (dx > dy)
    {
        int p = 2 * dy - dx;
        for (int i = 0; i <= dx; i++)
        {
            glVertex2f(x, y);

            if (p >= 0)
            {
                y += yIncrement;
                p -= 2 * dx;
            }

            x += xIncrement;
            p += 2 * dy;
        }
    }
    else
    {
        int p = 2 * dx - dy;
        for (int i = 0; i <= dy; i++)
        {
            glVertex2f(x, y);

            if (p >= 0)
            {
                x += xIncrement;
                p -= 2 * dy;
            }

            y += yIncrement;
            p += 2 * dx;
        }
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    drawLine(x1, y1, x2, y2);
    glFlush();
}

int main(int argc, char **argv)
{
    cout << "Masukkan koordinat (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Masukkan koordinat (x2 y2): ";
    cin >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham");
    gluOrtho2D(0, 500, 0, 500);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
