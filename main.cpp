#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int t, h, d, k;

    // Ввод
    cout << "Введите данные звонка:\n";
    cout << "Длительность (мин): ";
    cin >> t;
    if (t <= 0) {
        cout << "Ошибка длительности!\n";
        return 1;
    }

    cout << "Час начала (0-23): ";
    cin >> h;
    if (h < 0 || h > 23) {
        cout << "Ошибка часа!\n";
        return 1;
    }

    cout << "День недели (1-7, 1-пн): ";
    cin >> d;

    cout << "Постоянный клиент (1-да/0-нет): ";
    cin >> k;

    // Тариф
    double p = 0;
    if (d == 6 || d == 7) {
        p = 2.0;
    } else if (h >= 8 && h < 22) {
        p = 5.0;
    } else {
        p = 3.0;
    }

    // Расчет
    double s = t * p; // База
    double s1 = (t > 60) ? s * 0.10 : 0; // Скидка время
    double s2 = (k == 1) ? (s - s1) * 0.05 : 0; // Скидка клиент
    double it = s - s1 - s2; // Без НДС
    double nds = it * 0.20; // НДС
    double v = it + nds; // Итого

    // Вывод
    cout << fixed << setprecision(2);
    cout << "\n=== РАСЧЕТ СТОИМОСТИ ===\n";
    if (d == 6 || d == 7) cout << "Тариф: выходные (" << p << " руб/мин)\n";
    else if (h >= 8 && h < 22) cout << "Тариф: будни-день (" << p << " руб/мин)\n";
    else cout << "Тариф: будни-ночь (" << p << " руб/мин)\n";

    cout << "Базовая стоимость: " << s << " руб\n";
    cout << "Скидки:\n";
    cout << "- За длительность: " << s1 << " руб\n";
    cout << "- Постоянный клиент: " << s2 << " руб\n";
    cout << "Итого без НДС: " << it << " руб\n";
    cout << "НДС 20%: " << nds << " руб\n";
    cout << "К ОПЛАТЕ: " << v << " руб\n";

    return 0;
}
