#include <iostream>
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

void removeDuplicates(list*& h, list*& t) { // Удаление повторяющихся идущих подряд элементов
    if (!h) return;  // если список пуст
    list* p = h;
    while (p && p->next) { // Если текущий элемент равен следующему
        if (p->inf == p->next->inf) { // Удаляем следующий элемент
            delNode(h, t, p->next); // НЕ переходим дальше, потому что на месте p->next теперь новый элемент и его нужно снова сравнить с p
        }
        else {
            p = p->next; // Если не равны, переходим к следующему
        }
    }
}

void delList(list*& h, list*& t) {
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
    cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        push(head, tail, x);
    }

    cout << "Исходный список: ";
    print(head);
    removeDuplicates(head, tail); // Удаляем повторяющиеся идущие подряд элементы
    cout << "Результат: ";
    print(head);
    delList(head, tail);
    return 0;
}