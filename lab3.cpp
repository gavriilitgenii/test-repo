#include <iostream>
#include <cstdlib>
#include <ctime>

void f(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 100;
    }
}

void p(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

void cp(int a[], int b[], int n) {
    for (int i = 0; i < n; ++i) {
        b[i] = a[i];
    }
}

void ss(int a[], int n, long long &c, long long &s, bool d) {
    c = 0;
    s = 0;
    for (int i = 0; i < n - 1; ++i) {
        int m = i;
        for (int j = i + 1; j < n; ++j) {
            c++;
            if (d ? a[j] < a[m] : a[j] > a[m]) {
                m = j;
            }
        }
        if (m != i) {
            int t = a[i];
            a[i] = a[m];
            a[m] = t;
            s++;
        }
    }
}

void bs(int a[], int n, long long &c, long long &s, bool d) {
    c = 0;
    s = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            c++;
            if (d ? a[j] > a[j + 1] : a[j] < a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                s++;
            }
        }
    }
}

int main() {
    srand(time(0));
    int n = 7;
    int o[7], x[7], y[7];
    f(o, n);

    std::cout << "Исходный массив: ";
    p(o, n);

    long long c1, s1, c2, s2;

    cp(o, x, n);
    cp(o, y, n);
    ss(x, n, c1, s1, true);
    bs(y, n, c2, s2, true);

    std::cout << "\n1) Сортировка по возрастанию:\n";
    std::cout << "Выбором:   "; p(x, n); std::cout << "Сравнений: " << c1 << " | Перестановок: " << s1 << "\n";
    std::cout << "Пузырьком: "; p(y, n); std::cout << "Сравнений: " << c2 << " | Перестановок: " << s2 << "\n";

    int r1_s[7], r1_b[7];
    cp(x, r1_s, n);
    cp(y, r1_b, n);

    cp(r1_s, x, n);
    cp(r1_b, y, n);
    ss(x, n, c1, s1, true);
    bs(y, n, c2, s2, true);

    std::cout << "\n2) Повторная сортировка по возрастанию:\n";
    std::cout << "Выбором:   "; p(x, n); std::cout << "Сравнений: " << c1 << " | Перестановок: " << s1 << "\n";
    std::cout << "Пузырьком: "; p(y, n); std::cout << "Сравнений: " << c2 << " | Перестановок: " << s2 << "\n";

    int r2_s[7], r2_b[7];
    cp(x, r2_s, n);
    cp(y, r2_b, n);

    cp(r2_s, x, n);
    cp(r2_b, y, n);
    ss(x, n, c1, s1, false);
    bs(y, n, c2, s2, false);

    std::cout << "\n3) Сортировка по убыванию:\n";
    std::cout << "Выбором:   "; p(x, n); std::cout << "Сравнений: " << c1 << " | Перестановок: " << s1 << "\n";
    std::cout << "Пузырьком: "; p(y, n); std::cout << "Сравнений: " << c2 << " | Перестановок: " << s2 << "\n";

    return 0;
}
