#include <iostream>
#include <cmath>

using namespace std;

// Перевіряє, чи належить точка (x, y) заштрихованій області D
bool inD(double x, double y) {
    // Центральний еліпс:
    // центр (2.5, 1.5), півосі 1.5 та 0.5
    double ellipse =
        pow(x - 2.5, 2) / 2.25 +
        pow(y - 1.5, 2) / 0.25;

    if (ellipse <= 1.0) {
        return true;
    }

    // Нижні кола:
    // центри (2, -1) і (4, -1), радіус 1
    if (pow(x - 2.0, 2) + pow(y + 1.0, 2) <= 1.0) {
        return true;
    }

    if (pow(x - 4.0, 2) + pow(y + 1.0, 2) <= 1.0) {
        return true;
    }

    // Верхні прямокутники
    if (x >= 0 && x <= 1 && y >= 1 && y <= 2) return true;
    if (x >= 1 && x <= 2 && y >= 2 && y <= 3) return true;
    if (x >= 4 && x <= 5 && y >= 2 && y <= 3) return true;
    if (x >= 5 && x <= 6 && y >= 1 && y <= 2) return true;

    // Нижні прямокутники
    if (x >= 0 && x <= 1 && y >= -2 && y <= -1) return true;
    if (x >= 2 && x <= 4 && y >= -3 && y <= -2) return true;
    if (x >= 5 && x <= 6 && y >= -2 && y <= -1) return true;

    return false;
}

int main() {
    double x, y, u;

    cout << "Введіть x та y: ";

    if (!(cin >> x >> y)) {
        cout << "Помилка введення даних." << endl;
        return 1;
    }

    bool pointInD = inD(x, y);

    if (pointInD) {
        u = x * x * y - sqrt(abs(y));
    } else {
        u = y * y * x - sqrt(abs(x));
    }

    cout << (pointInD ? "YES: " : "NO: ")
         << "x = " << x
         << ", y = " << y
         << ", u = " << u << endl;

    return 0;
}