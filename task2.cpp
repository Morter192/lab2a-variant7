#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double h;

    cout << "Введіть дійсне число h: ";

    if (!(cin >> h)) {
        cout << "Помилка введення даних." << endl;
        return 1;
    }

    // Перевіряємо, чи визначений tg(h)
    if (abs(cos(h)) < 1e-12) {
        cout << "No real coefficient" << endl;
        return 0;
    }

    double a = sqrt(pow(sin(h + 1), 2) + 17);
    double radicand = 4 + tan(h);

    // Перевіряємо, чи можна обчислити квадратний корінь для b
    if (radicand < 0) {
        cout << "No real coefficient" << endl;
        return 0;
    }

    double b = 10 - sqrt(radicand);
    double c = a * h * cos(b * h) + b * h * sin(a * h);

    // Перевіряємо, чи коефіцієнти скінченні
    if (!isfinite(a) || !isfinite(b) || !isfinite(c)) {
        cout << "No real coefficient" << endl;
        return 0;
    }

    double discriminant = b * b - 4 * a * c;

    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    if (discriminant < 0) {
        cout << "No real roots" << endl;
    } else if (abs(discriminant) < 1e-12) {
        double x = -b / (2 * a);
        cout << "Один дійсний корінь: x = " << x << endl;
    } else {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Два дійсні корені: x1 = " << x1
             << ", x2 = " << x2 << endl;
    }

    return 0;
}