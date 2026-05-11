//#include <iostream>
//#include <set>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//    setlocale(LC_ALL, "RUS");
//    int n, x;
//    cout << "Введите N: "; cin >> n;
//    set<int> digits_iz_3;  // цифры из трехзначных чисел
//    set<int> digits_ost;   // цифры из остальных чисел
//    cout << "Введите " << n << " чисел:" << endl;
//    for (int i = 0; i < n; i++) {
//        cout << "a[" << i << "] = ";
//        cin >> x;
//
//        int number = abs(x); // Проверяем, трехзначное ли число
//        bool number_iz_3 = (number >= 100 && number <= 999);
//
//        int razbienie = number; // Получаем цифры числа
//        set<int> digits;
//        if (razbienie == 0) {
//            digits.insert(0);
//        }
//        else {
//            while (razbienie > 0) {
//                digits.insert(razbienie % 10);
//                razbienie = razbienie / 10;
//            }
//        }
//        if (number_iz_3) { // Pаскладываем цифры по нужным множествам
//            for (set<int>::iterator i = digits.begin(); i != digits.end(); ++i) {
//                digits_iz_3.insert(*i);
//            }
//        }
//        else {
//            for (set<int>::iterator i = digits.begin(); i != digits.end(); ++i) {
//                digits_ost.insert(*i);
//            }
//        }
//    }
//    set<int> result; // Ищем цифры, которые есть в digits_iz_3, но нет в digits_ost
//    for (set<int>::iterator i = digits_iz_3.begin(); i != digits_iz_3.end(); ++i) {
//        int digit = *i;
//
//        if (digits_ost.find(digit) == digits_ost.end()) {
//            result.insert(digit);
//        }
//    }
//    cout << "\nЦифры, которые встречаются только в трехзначных числах: "; // Выводим результат
//    if (result.empty()) {
//        cout << "Таких цифр нет";
//    }
//    else {
//        for (set<int>::iterator i = result.begin(); i != result.end(); ++i) {
//            cout << *i << " ";
//        }
//    }
//    cout << endl;
//    return 0;
//}