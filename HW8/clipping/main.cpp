#include <iostream>
using namespace std;

// Fungsi untuk menentukan kode Cohen-Sutherland untuk suatu titik
int computeCode(int x, int y, int xmin, int ymin, int xmax, int ymax) {
    int code = 0;

    if (x < xmin)
        code |= 1; // Kode untuk batas kiri
    else if (x > xmax)
        code |= 2; // Kode untuk batas kanan

    if (y < ymin)
        code |= 4; // Kode untuk batas bawah
    else if (y > ymax)
        code |= 8; // Kode untuk batas atas

    return code;
}

// Fungsi untuk mengimplementasikan algoritma Cohen-Sutherland
void cohenSutherlandClip(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
    // Menghitung kode untuk kedua titik
    int code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
    int code2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);

    bool accept = false;

    while (true) {
        // Cek apakah kedua titik berada dalam viewport (kode AND dari keduanya adalah 0)
        if (!(code1 | code2)) {
            accept = true;
            break;
        }
        // Cek apakah terdapat titik potong
        else if (code1 & code2) {
            break;
        } else {
            // Pilih salah satu titik yang berada di luar viewport
            int x = 0, y = 0;
            int code_out = code1 ? code1 : code2;

            // Temukan titik potong dengan batas viewport
            if (code_out & 1) {      // Batas kiri
                x = xmin;
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
            } else if (code_out & 2) { // Batas kanan
                x = xmax;
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
            } else if (code_out & 4) { // Batas bawah
                y = ymin;
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
            } else if (code_out & 8) { // Batas atas
                y = ymax;
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
            }

            // Ganti titik yang berada di luar viewport dengan titik potong
            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);
            }
        }
    }

    if (accept) {
        cout << "Garis Diterima:\nBatas X1=" << x1 << "\nBatas Y1=" << y1 << "\nBatas X2=" << x2 << "\nBatas Y2=" << y2 << endl;
    } else {
        cout << "Garis Ditolak" << endl;
    }
}

int main() {
    // Contoh pemanggilan fungsi cohenSutherlandClip
    int x1 = -1, y1 = -2, x2 = 5, y2 = 6;
    int xmin = 1, ymin = 1, xmax = 4, ymax = 5; // Batas viewport

    cohenSutherlandClip(x1, y1, x2, y2, xmin, ymin, xmax, ymax);

    return 0;
}
