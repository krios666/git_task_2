#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

ifstream in("C:\\Users\\User\\Desktop\\input.txt");
ofstream out("C:\\Users\\User\\Desktop\\output.txt");

struct date {
    int dd, mm, yy;
};

struct people {
    string Name;
    string Position;
    date DOB;
    int Salary;
    int Experience;
};

date Str_to_Date(string str) {
    date x;
    x.dd = 1;
    x.mm = 1;
    x.yy = 2000;
    if (str.length() >= 10) { // Проверяем, что строка не пустая и есть точки
        x.dd = atoi(str.substr(0, 2).c_str());
        x.mm = atoi(str.substr(3, 2).c_str());
        x.yy = atoi(str.substr(6, 4).c_str());
    }
    return x;
}

vector<people> inFile() {
    vector<people> x;
    people temp;
    string tmp_date;
    while (in >> temp.Name >> temp.Position >> tmp_date >> temp.Salary >> temp.Experience) {
        temp.DOB = Str_to_Date(tmp_date);
        x.push_back(temp);
    }
    return x;
}

void print(people x) {
    out << setw(12) << left << x.Name;
    out << setw(30) << left << x.Position;
    if (x.DOB.dd < 10) out << '0';
    out << x.DOB.dd << '.';
    if (x.DOB.mm < 10) out << '0';
    out << x.DOB.mm << '.';
    out << x.DOB.yy << "   ";
    out << setw(6) << left << x.Experience;
    out << setw(10) << left << x.Salary << endl;
}

ostream& operator<<(ostream& os, const people& x) {
    os << setw(12) << left << x.Name;
    os << setw(30) << left << x.Position;
    if (x.DOB.dd < 10) os << '0';
    os << x.DOB.dd << '.';
    if (x.DOB.mm < 10) os << '0';
    os << x.DOB.mm << '.';
    os << x.DOB.yy << "   ";
    os << setw(6) << left << x.Experience;
    os << setw(10) << left << x.Salary;
    return os;
}

bool operator < (const people& a, const people& b) {
    return a.Position < b.Position;
}

void Sifting(vector<people>& x, int n, int i) {
    int largest = i;        // корень
    int left = 2 * i + 1;   // левый потомок
    int right = 2 * i + 2;  // правый потомок

    if (left < n && x[left].Position > x[largest].Position) {// Так как строим max-кучу, ищем больший элемент
        largest = left;
    }
    if (right < n && x[right].Position > x[largest].Position) {
        largest = right;
    }
    if (largest != i) { // Если наибольший элемент не корень
        swap(x[i], x[largest]);
        Sifting(x, n, largest);  // рекурсивно просеиваем дальше
    }
}

void piramidal_sort(vector<people>& x) {
    int n = x.size();
    for (int i = n / 2 - 1; i >= 0; i--) { // Построение кучи (max-heap). Начинаем с последнего нелистового элемента
        Sifting(x, n, i);
    }
    for (int i = n - 1; i > 0; i--) { // Извлечение элементов из кучи
        swap(x[0], x[i]); // Перемещаем корень (максимальный элемент) в конец
        Sifting(x, i, 0); // Вызываем просеивание на уменьшенной куче
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    vector<people> x = inFile();
    piramidal_sort(x);
    for (int i = 0; i < x.size(); i++) {
        print(x[i]);
    }
    cout << "Отсортированные данные (по должности):" << endl;
    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << endl;
    }
    cout << "\nРезультат сохранен в output.txt" << endl;
    in.close();
    out.close();
    system("pause");
    return 0;
}