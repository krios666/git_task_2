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
//int main() {
//    setlocale(LC_ALL, "RUS");
//    queue<int> q;      // исходная очередь
//    queue<int> result; // результирующая очередь
//    int n, x;
//
//    cout << "Введите количество элементов: "; cin >> n;
//
//    if (n == 0) {
//        cout << "Очередь нулевого размера";
//        return 0;
//    }
//
//    cout << "Введите " << n << " целых чисел: ";
//
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
//    int first = q.front();  // запоминаем первый элемент
//    result.push(first);     // добавляем его в результат
//    q.pop();               // удаляем из исходной очереди
//    while (!q.empty()) {
//        int current = q.front();
//        q.pop();
//        if (current != first) {  // если элемент отличается от предыдущего
//            result.push(current); // добавляем в результат
//            first = current;       // обновляем предыдущий элемент
//        } 
//    }
//
//    cout << "Результат: ";
//    printQueue(result);
//    return 0;
//}