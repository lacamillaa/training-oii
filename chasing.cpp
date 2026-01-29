#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void directions(int s, char dir, int *sx, int *sy) {
    switch (dir) {
        case 'U':
            *sx = 0;
            *sy = s;
            break;
        case 'D':
            *sx = 0;
            *sy = -s;
            break;
        case 'L':
            *sx = -s;
            *sy = 0;
            break;
        case 'R':
            *sx = s;
            *sy = 0;
            break;
        default:
            *sx = 0;
            *sy = 0;
            break;
    }
}

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int Dx, Dy, Ds;
    cin >> Dx >> Dy >> Ds;

    int Bx, By, Bs;
    cin >> Bx >> By >> Bs;

    char dir;
    cin >> dir;

    int T = 0;

    int Dsx, Dsy; // vettori della velocità del cane
    int Bsx, Bsy; // vettori della velocità della palla
    directions(Bs, dir, &Bsx, &Bsy);
    // cout << Bsx << " " << Bsy << endl;

    char dogDir;
    if (Bsx == 0) {
        // la palla si sta muovendo in verticale
        // decidi se fare andare il cane a sx o dx
        if (Dx > Bx) {
            dogDir = 'L';
        }
        else {
            dogDir = 'R';
        }
    }
    if (Bsy == 0) {
        if (Dy > By) {
            dogDir = 'D';
        }
        else {
            dogDir = 'U';
        }
    }
    directions(Ds, dogDir, &Dsx, &Dsy);
    // cout << Dsx << " " << Dsy << endl;

    double t1; // tempo richiesto per allineare il cane con la palla
    if (Bsx == 0) {
        t1 = (double)(Bx - Dx) / (double)Dsx;
    }
    if (Bsy == 0) {
        t1 = (double)(By - Dy) / (double)Dsy;
    }

    // cout << t1 << endl;

    double X2 = Bx + Bsx * t1;
    double Y2 = By + Bsy * t1;
    // cout << X2 << " " << Y2 << endl;

    dogDir = dir;
    directions(Ds, dogDir, &Dsx, &Dsy); // direzione cane = direzione palla

    double t2;
    if (Bsx == 0) {
        t2 = (Y2 - Dy) / (double)(Dsy - Bsy);
    }
    if (Bsy == 0) {
        t2 = (X2 - Dx) / (double)(Dsx - Bsy);
    }

    // cout << t2 << endl;

    if (t2 < 0) T = -1;
    else {
        T = ceil(t1 + t2);
    }

    cout << T << endl;

    return 0;
}
