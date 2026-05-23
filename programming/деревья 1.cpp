#include <iostream>
#include <vector>
using namespace std;

struct tree {
    int inf;
    tree* left;
    tree* right;
    tree* parent;
};

tree* node(int x) { // Создание нового узла
    tree* n = new tree;
    n->inf = x;
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
    return n;
}

void insert(tree*& tr, int x) { // Вставка элемента в дерево бинарного поиска
    tree* n = node(x);
    if (!tr) {
        tr = n;
    }
    else {
        tree* y = tr;
        while (y) {
            if (n->inf > y->inf) {  // идём вправо
                if (y->right) {
                    y = y->right;
                }
                else {
                    n->parent = y;
                    y->right = n;
                    break;
                }
            }
            else if (n->inf < y->inf) {  // идём влево
                if (y->left) {
                    y = y->left;
                }
                else {
                    n->parent = y;
                    y->left = n;
                    break;
                }
            }
            else { // элемент уже существует удаляем новый узел
                delete n;
                break;
            }
        }
    }
}

tree* find(tree* tr, int x) { // Поиск узла по значению
    if (!tr || tr->inf == x) {
        return tr;
    }
    if (x < tr->inf) {
        return find(tr->left, x);
    }
    else {
        return find(tr->right, x);
    }
}

tree* findSibling(tree* node) { // Поиск брата/сестры узла
    if (!node || !node->parent) {
        return NULL;
    }
    tree* parent = node->parent;
    if (parent->left == node) {
        return parent->right;
    }
    else {
        return parent->left;
    }
}

void printNephews(tree* sibling) { // Вывод племянников (детей брата/сестры)
    if (!sibling) {
        cout << "Племянников нет (нет брата/сестры)" << endl;
        return;
    }

    cout << "Племянники узла (дети брата/сестры): ";
    bool hasNephews = false;

    if (sibling->left) {
        cout << sibling->left->inf << " ";
        hasNephews = true;
    }
    if (sibling->right) {
        cout << sibling->right->inf << " ";
        hasNephews = true;
    }

    if (!hasNephews) {
        cout << "нет (у брата/сестры нет детей)";
    }
    cout << endl;
}

void inorder(tree* tr) { // Симметричный обход для вывода дерева (отсортированный порядок)
    if (tr) {
        inorder(tr->left);
        cout << tr->inf << " ";
        inorder(tr->right);
    }
}

void clearTree(tree*& tr) {
    if (tr) {
        clearTree(tr->left);
        clearTree(tr->right);
        delete tr;
        tr = NULL;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    tree* root = NULL;
    int n, x, target;
    cout << "Введите количество элементов: "; cin >> n;

    cout << "Введите " << n << " целых чисел для построения дерева: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(root, x);
    }

    cout << "\nДерево бинарного поиска (симметричный обход): ";
    inorder(root);
    cout << endl;

    cout << "\nВведите значение узла X: "; cin >> target;

    tree* nodeX = find(root, target); // Поиск узла X в дерев

    if (!nodeX) {
        cout << "Узел со значением " << target << " не найден в дереве!" << endl;
        clearTree(root);
        return 0;
    }

    cout << "Узел " << target << " найден в дереве." << endl;

    tree* sibling = findSibling(nodeX); // Находим брата/сестру

    if (!sibling) { // Может быть два случая: нет родителя или у родителя нет второго ребенка
        if (!nodeX->parent) {
            cout << "Узел является корнем дерева. У корня нет племянников." << endl;
        }
        else {
            cout << "У родителя узла нет второго ребенка, поэтому племянников нет." << endl;
        }
    }
    else {
        cout << "Брат/сестра узла: " << sibling->inf << endl;
        printNephews(sibling);
    }
    clearTree(root);
    return 0;
}