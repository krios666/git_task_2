//#include <iostream>
//#include <stack>
//using namespace std;
//
//void reverseStack(stack<int>& s) { // Функция для переворачивания стека
//    stack<int> tmp;
//    while (!s.empty()) {
//        tmp.push(s.top());
//        s.pop();
//    }
//    s = tmp;
//}
//
//void printStack(stack<int> s) { // Функция для вывода стека
//    while (!s.empty()) {
//        cout << s.top() << " ";
//        s.pop();
//    }
//    cout << endl;
//}
//
//int main() {
//    setlocale(LC_ALL, "RUS");
//    stack<int> st;
//    int n, x;
//    cout << "Введите количество элементов: ";
//    cin >> n;
//    if (n == 0) {
//        cout << "Стек имеет нулевой размер";
//        return 0;
//    }
//    cout << "Введите " << n << " целых чисел: ";
//    for (int i = 0; i < n; i++) {
//        cin >> x;
//        st.push(x);
//    }
//
//    reverseStack(st); // Переворачиваем стек, чтобы порядок на вершине стал как ввод
//
//    stack<int> temp = st; // Находим min и max
//    int max_val = temp.top(), min_val = temp.top();
//    while (!temp.empty()) { //пока есть элементы в копии исходного стека
//        int val = temp.top(); // val - вершина стека
//        if (val > max_val) max_val = val; // если число больше максимума, то он становится максимальным
//        if (val < min_val) min_val = val; // тоже самое что и с максимумом
//        temp.pop(); // удаляем элемент который сравнивали и переходим к следующему.
//    }
//
//    cout << "Максимальный элемент: " << max_val << endl;
//    cout << "Минимальный элемент: " << min_val << endl;
//
//    stack<int> result; // Собираем результат с вставками
//    while (!st.empty()) {
//        int val = st.top();
//        st.pop();
//        if (val == max_val) {
//            result.push(min_val);  // вставляем минимум перед максимумом
//        }
//        result.push(val);
//    }
//
//    reverseStack(result); // Переворачиваем результат в правильный порядок
//
//    cout << "Результат: ";
//    printStack(result);
//    return 0;
//}