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

int calcola(int Dx, int Dy, int Ds, int Bx, int By, int Bs, char dir) {
    int T = 0;
    int delta, Bsx, Bsy, Dsx, Dsy;
    char dogDir;
    if (Bx == Dx && By == Dy) return 0;
    if (Bs == 0 && Ds == 0) return -1;
    if (Bs == 0) {
        int dist = abs(Bx - Dx) + abs(By - Dy);
        double t = dist / static_cast<double>(Ds);
        return ceil(t);
    }
    directions(Bs, dir, &Bsx, &Bsy);
    if (Bsx != 0) {
        // allinea Y
        if (Dy > By) dogDir = 'D';
        else dogDir = 'U';
    }
    else {
        if (Dx > Bx) dogDir = 'L';
        else dogDir = 'R';
    }
    directions(Ds, dogDir, &Dsx, &Dsy);
    if (Bsx != 0) {
        delta = By - Dy;
    }
    else {
        delta = Bx - Dx;
    }
    double t2;
    if (Ds == 0) {
        if (delta != 0) return -1;
        t2 = 0;
    }
    else {
        if (Bsx != 0) t2 = delta / (double)Dsy;
        else t2 = delta / (double)Dsx;
    }
    if (Bsx != 0) {
        if (Dx > Bx) dogDir = 'L';
        else dogDir = 'R';
    }
    if (Bsy != 0) {
        if (Dy > By) dogDir = 'D';
        else dogDir = 'U';
    }
    directions(Ds, dogDir, &Dsx, &Dsy);
    double X2 = Bx + Bsx * t2;
    double Y2 = By + Bsy * t2;
    double t1;
    if (Bsx != 0) {
        t1 = (Dx - X2) / static_cast<double>(Bsx - Dsx);
    }
    else {
        t1 = (Dy - Y2) / static_cast<double>(Bsy - Dsy);
    }
    if (t1 < 0) return -1;
    T = ceil(t1 + t2);
    return T;
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

    int T = calcola(Dx, Dy, Ds, Bx, By, Bs, dir);

    cout << T << endl;

    return 0;
}
