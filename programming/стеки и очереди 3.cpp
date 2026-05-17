//#include <iostream>
//#include <queue>
//using namespace std;
//
//void printQueue(queue<int> q) {
//    while (!q.empty()) {
//        cout << q.front() << " ";
//        q.pop();
//    }
//    cout << endl;
//}
//
//int findMax(queue<int> q) { // Функция для поиска максимального элемента в очереди
//    if (q.empty()) return 0;
//
//    int max_val = q.front();
//    while (!q.empty()) {
//        if (q.front() > max_val) {
//            max_val = q.front();
//        }
//        q.pop();
//    }
//    return max_val;
//}
//
//int findLastOdd(queue<int> q) { // Функция для поиска последнего нечётного элемента
//    if (q.empty()) return 0;
//
//    int last_odd = 0;
//    bool found = false;
//
//    while (!q.empty()) {
//        int current = q.front();
//        if (current % 2 != 0) {  // если нечётный
//            last_odd = current;
//            found = true;
//        }
//        q.pop();
//    }
//
//    return found ? last_odd : 0;
//}
//
//int main() {
//    setlocale(LC_ALL, "RUS");
//    queue<int> q;      
//    queue<int> result; 
//    int n, x;
//
//    cout << "Введите количество элементов: "; cin >> n;
//
//    cout << "Введите " << n << " целых чисел: ";
//    for (int i = 0; i < n; i++) {
//        cin >> x;
//        q.push(x);
//    }
//
//    if (q.empty()) {
//        cout << "Очередь пуста!" << endl;
//        return 0;
//    }
//
//    int max_val = findMax(q); 
//    cout << "Максимальный элемент: " << max_val << endl;
//
//    int last_odd = findLastOdd(q); // Находим последний нечётный элемент
//    if (last_odd == 0) {
//        cout << "В очереди нет нечётных элементов!" << endl;
//        cout << "Результат: ";
//        printQueue(q);
//        return 0;
//    }
//
//    cout << "Последний нечётный элемент: " << last_odd << endl;
//
//    while (!q.empty()) { 
//        int current = q.front();
//        q.pop();
//        result.push(current); // Добавляем текущий элемент
//        if (current == max_val) { // Если текущий элемент - максимальный, добавляем последний нечётный
//            result.push(last_odd);
//        }
//    }
//    cout << "Результат: ";
//    printQueue(result);
//    return 0;
//}