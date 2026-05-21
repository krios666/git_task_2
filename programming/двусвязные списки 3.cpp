#include <iostream>
#include <vector>
using namespace std;

struct list {
    int inf;
    list* next;
    list* prev;
};

void push(list*& h, list*& t, int x) {
    list* r = new list;
    r->inf = x;
    r->next = NULL;

    if (!h && !t) {
        r->prev = NULL;
        h = r;
    }
    else {
        t->next = r;
        r->prev = t;
    }
    t = r;
}

void print(list* h) {
    list* p = h;
    while (p) {
        cout << p->inf << " ";
        p = p->next;
    }
    cout << endl;
}

void delNode(list*& h, list*& t, list* r) {
    if (r == h && r == t) {
        h = t = NULL;
    }
    else if (r == h) {
        h = h->next;
        h->prev = NULL;
    }
    else if (r == t) {
        t = t->prev;
        t->next = NULL;
    }
    else {
        r->prev->next = r->next;
        r->next->prev = r->prev;
    }
    delete r;
}

void clearList(list*& h, list*& t) {
    while (h) {
        list* p = h;
        h = h->next;
        delete p;
    }
    t = NULL;
}

int main() {
    setlocale(LC_ALL, "RUS");
    list* head = NULL;
    list* tail = NULL;
    int n, x;

    cout << "Введите количество элементов: "; cin >> n;

    vector<int> original;  // сохраняем исходные значения

    cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        original.push_back(x);
        push(head, tail, x);
    }

    cout << "Исходный список: ";
    print(head);

    vector<bool> toDelete(n, false); // Вычисляем средние для каждого элемента (по исходным данным)

    for (int i = 0; i < n; i++) { // Проходим по всем элементам
        int sum = 0; // Вычисляем сумму и количество элементов ПОСЛЕ текущего
        int count = 0;

        for (int j = i + 1; j < n; j++) {
            sum += original[j];
            count++;
        }

        if (count == 0) { // Если нет элементов после, то условие выполняется всегд
            continue;
        }

        double avg = (double)sum / count;

        if (original[i] < avg) { // Если текущий элемент меньше среднего → помечаем на удаление
            toDelete[i] = true;
        }
    }

    list* p = head; // Удаляем помеченные элементы из списка
    int index = 0;

    while (p && index < n) {
        list* nextNode = p->next;  // сохраняем следующий ДО возможного удаления
        if (toDelete[index]) {
            delNode(head, tail, p);
        }
        p = nextNode;
        index++;
    }
    cout << "Результат: ";
    print(head);
    clearList(head, tail);
    return 0;
}