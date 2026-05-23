#include <iostream>
#include <vector>
using namespace std;

struct tree {
    int inf;
    tree* left;
    tree* right;
    tree* parent;
};

tree* node(int x) {
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
            if (n->inf > y->inf) { // идём вправо
                if (y->right) {
                    y = y->right;
                }
                else {
                    n->parent = y;
                    y->right = n;
                    break;
                }
            }
            else if (n->inf < y->inf) { // идём влево
                if (y->left) {
                    y = y->left;
                }
                else {
                    n->parent = y;
                    y->left = n;
                    break;
                }
            }
            else {
                delete n; // элемент уже существует — удаляем новый узел
                break;
            }
        }
    }
}

bool hasOnlyOneChild(tree* node) { // Проверка: имеет ли узел только одного ребенка?
    if (!node) return false;
    bool hasLeft = (node->left != NULL);
    bool hasRight = (node->right != NULL);
    return hasLeft != hasRight; // Исключающее ИЛИ: true если ровно один ребенок
}

void findNodesWithOneChild(tree* tr, vector<int>& result) { // Обход дерева и сбор узлов с одним ребенком
    if (tr) {
        if (hasOnlyOneChild(tr)) { // Проверяем текущий узел
            result.push_back(tr->inf);
        }
        findNodesWithOneChild(tr->left, result); // Рекурсивно обходим левое и правое поддеревья
        findNodesWithOneChild(tr->right, result);
    }
}

void inorder(tree* tr) { // Симметричный обход для вывода дерева (отсортированный порядок)
    if (tr) {
        inorder(tr->left);
        cout << tr->inf << " ";
        inorder(tr->right);
    }
}

void printTree(tree* tr, int space = 0, int indent = 4) { // Вывод дерева в виде структуры 
    if (!tr) return;
    space += indent;
    printTree(tr->right, space); // Сначала правый ребенок
    cout << endl; // Текущий узел
    for (int i = indent; i < space; i++) cout << " ";
    cout << tr->inf << endl;
    printTree(tr->left, space); // Затем левый ребенок
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
    int n, x;
    cout << "Введите количество элементов: "; cin >> n;

    if (n == 0) {
        cout << "Дерево пусто!" << endl;
        return 0;
    }

    cout << "Введите " << n << " целых чисел для построения дерева: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(root, x);
    }

    cout << "\nДерево бинарного поиска (симметричный обход): ";
    inorder(root);
    cout << endl;

    cout << "\nВизуальное представление дерева:\n";
    printTree(root);

    vector<int> result;
    findNodesWithOneChild(root, result);

    cout << "\nУзлы, имеющие только одного ребенка: ";
    if (result.empty()) {
        cout << "нет таких узлов";
    }
    else {
        for (int val : result) {
            cout << val << " ";
        }
    }
    cout << endl;
    clearTree(root);
    return 0;
}