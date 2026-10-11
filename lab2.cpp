#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// математическая функция из задания
double f(double x) {
    return x - cos(x);
}

// метод половинного деления в отдельной функции
double s(double a, double b, double e) {
    double c = a;
    while ((b - a) / 2.0 > e) {
        c = a + (b - a) / 2.0; // середина

        if (f(c) == 0.0) {
            break;
        }

        // выбор нужного отрезка
        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return c;
}

int main() {
    double a, b; // левая и правая границы
    double e = 1e-4; // погрешность

    cout << "Введите начальные границы отрезка (a и b): ";
    cin >> a >> b;

    // проверка наличия корня на отрезке
    if (f(a) * f(b) >= 0) {
        cout << "Ошибка: на данном отрезке нет корней или их четное количество." << endl;
        return 1;
    }

    // вызов функции решения
    double r = s(a, b, e);

    // форматированный вывод результата
    cout << fixed << setprecision(5);
    cout << setw(12) << "Корень x = " << setw(10) << r << endl;

    return 0;
}
