#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, d;

    cout << "Введіть a, b, c та d: ";

    if (!(cin >> a >> b >> c >> d)) {
        cout << "Помилка введення даних." << endl;
        return 1;
    }

    double value = a * a * (c + 1);

    if (!(d < value)) {
        cout << "За умовою методички формулу x для цього випадку не задано."
             << endl;
        return 0;
    }

    double x = sqrt(value - d);
    double y = b - c * sqrt(4 + exp(d));
    double z;

    if (x > 0) {
        z = y * x * x - 1 / x;
    } else {
        z = y * y * y - x * x * x * x + 1;
    }

    cout << "x = " << x << ", y = " << y << endl;
    cout << "Algorithm 1: z = " << z << endl;

    return 0;
}
