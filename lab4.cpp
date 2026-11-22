#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    double a[10][12];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        double s = 0.0;
        for (int j = 0; j < n; ++j) {
            s += log(fabs(a[i][j]));
        }
        double g = exp(s / n);

        double d = a[i][0];
        double r = fabs(d - g);
        for (int j = 1; j < n; ++j) {
            double c = fabs(a[i][j] - g);
            if (c > r) {
                r = c;
                d = a[i][j];
            }
        }

        for (int j = 0; j < n; ++j) {
            cout << setw(10) << a[i][j] << " ";
        }
        cout << " | " << setw(10) << d << " " << setw(10) << r << "\n";
    }

    return 0;
}
