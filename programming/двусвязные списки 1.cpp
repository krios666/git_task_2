#include <iostream>
using namespace std;

struct list {
    int inf;
    list* next;
    list* prev;
};

void push(list*& h, list*& t, int x) { // Добавление элемента в конец списка
    list* r = new list;
    r->inf = x;
    r->next = NULL;

    if (!h && !t) {      // если список пуст
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

int findMin(list* h) {
    if (!h) return 0;
    int min_val = h->inf;
    list* p = h;
    while (p) {
        if (p->inf < min_val) {
            min_val = p->inf;
        }
        p = p->next;
    }
    return min_val;
}

void insertBefore(list*& h, list*& t, list* r, int x) { // Вставка элемента x ПЕРЕД узлом r
    list* newNode = new list;
    newNode->inf = x;

    if (r == h) {        // вставляем перед головой
        newNode->prev = NULL;
        newNode->next = h;
        h->prev = newNode;
        h = newNode;
    }
    else {             // вставляем в середину или перед хвостом
        newNode->prev = r->prev;
        newNode->next = r;
        r->prev->next = newNode;
        r->prev = newNode;
    }
}

void delList(list*& h) {
    while (h) {
        list* p = h;
        h = h->next;
        delete p;
    }
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

    if (!head) {
        cout << "Список пуст!" << endl;
        return 0;
    }

    int last_val = tail->inf;
    cout << "Последний элемент: " << last_val << endl;

    int min_val = findMin(head);
    cout << "Минимальный элемент: " << min_val << endl;

    list* p = head; // Проходим по списку и вставляем min_val перед каждым last_val
    while (p) {
        if (p->inf == last_val) { // Вставляем минимальный элемент перед текущим. insertBefore меняет head, если нужно, и обновляет p. Запоминаем следующий элемент перед вставкой
            list* next_node = p->next;
            insertBefore(head, tail, p, min_val);
            p = next_node;  // продолжаем со следующего элемента
        }
        else {
            p = p->next;
        }
    }
    cout << "Результат: ";
    print(head);
    delList(head);
    return 0;
}