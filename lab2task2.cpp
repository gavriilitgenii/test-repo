#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a = 0.0; // начало отрезка
    double b = 1.0; // конец отрезка
    double h = 0.2; // шаг
    double e = 1e-6; // погрешность

    // шапка таблицы
    cout << setw(10) << "X"
         << setw(15) << "Y(X)"
         << setw(15) << "S(X)"
         << setw(10) << "N" << endl;

    cout << fixed << setprecision(6);

    // цикл по всем точкам x с шагом h
    for (double x = a; x <= b + 1e-9; x += h) {
        double y = cos(x); // точное значение функции

        double s = 1.0;  // первый член ряда (при n = 0)
        double t = 1.0;  // текущий член ряда
        int n = 0;       // номер слагаемого

        // суммирование ряда Тейлора через рекуррентное соотношение
        do {
            n++;
            // рекуррентный множитель для cos(x): A_n = A_{n-1} * (-x^2 / ((2n-1)*(2n)))
            t = -t * x * x / ((2.0 * n - 1.0) * (2.0 * n));
            s += t;
        } while (fabs(t) > e);

        // вывод строки таблицы
        cout << setw(10) << x
             << setw(15) << y
             << setw(15) << s
             << setw(10) << n << endl;
    }

    return 0;
}
