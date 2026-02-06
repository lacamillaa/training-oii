#include <array>
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

double select(array<double, 2>& from) {
    // -1, -1 => -1
    // 0, -1 => 0
    // -1, 0 => 0
    // 3, 2 => 2
    if (max(from[0], from[1]) < 0) return -1;
    if (from[0] < 0) return from[1];
    if (from[1] < 0) return from[0];
    return min(from[0], from[1]);
}

int calcola(int Dx, int Dy, int Ds, int Bx, int By, int Bs, char dir) {
    int T = 0;
    int delta, Bsx, Bsy, Dsx, Dsy;
    int *ds;
    char dogDir;
    directions(Bs, dir, &Bsx, &Bsy);
    if (Bsx == 0 && Bsy == 0) {
        double r = 0;
        r += abs(Dx - Bx) + abs(Dy - By);
        r /= static_cast<double>(Ds);
        return ceil(r);
    }
    if (Bsx == 0) {
        delta = Bx - Dx;
        if (delta >= 0) dogDir = 'R';
        else dogDir = 'L';
        ds = &Dsx;
    } else {
        delta = By - Dy;
        if (delta >= 0) dogDir = 'U';
        else dogDir = 'D';
        ds = &Dsy;
    }
    directions(Ds, dogDir, &Dsx, &Dsy);
    double t2;
    if (*ds == 0) {
        if (delta != 0) return -1;
        t2 = 0;
    }
    else {
        t2 = delta / static_cast<double>(*ds);
    }
    double t1;
    if (Bsx == 0) {
        array<char, 2> dirs = {'U', 'D'};
        array<double, 2> dt = {0, 0};
        for (int i = 0; i < 2; i++) {
            double t1;
            directions(Ds, dirs[i], &Dsx, &Dsy);
            if (Bsy == Dsy) {
                if (Dy - By == t2 * Bsy) t1 = 0;
                else t1 = -1;
            }
            else {
                t1 = (Dy - By - t2 * Bsy) / (Bsy - Dsy);
            }
            dt[i] = t1;
        }
        t1 = select(dt);
    }
    else {
        array<char, 2> dirs = {'L', 'R'};
        array<double, 2> dt = {0, 0};
        for (int i = 0; i < 2; i++) {
            double t1;
            directions(Ds, dirs[i], &Dsx, &Dsy);
            if (Bsx == Dsx) {
                if (Dx - Bx == t2 * Bsx) t1 = 0;
                else t1 = -1;
            }
            else {
                t1 = (Dx - Bx - t2 * Bsx) / (Bsx - Dsx);
            }
            dt[i] = t1;
        }
        t1 = select(dt);
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
