#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// Структура узла дерева
struct tree {
    int inf;
    tree* right;
    tree* left;
    tree* parent;
};

// Создание нового узла
tree* node(int x) {
    tree* n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

// Вставка элемента в дерево бинарного поиска
void insert(tree*& tr, int x) {
    tree* n = node(x);
    if (!tr) {
        tr = n;
    }
    else {
        tree* y = tr;
        while (y) {
            if (n->inf > y->inf) {
                if (y->right) {
                    y = y->right;
                }
                else {
                    n->parent = y;
                    y->right = n;
                    break;
                }
            }
            else if (n->inf < y->inf) {
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
                delete n;
                break;
            }
        }
    }
}

// Вычисление высоты дерева
int getHeight(tree* node) {
    if (!node) return 0;
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

// ОРИГИНАЛЬНАЯ функция вывода из task7_1.cpp
void print_Tree(tree* root) {
    if (!root) return;

    int h = getHeight(root);

    std::queue<tree*> q;
    q.push(root);

    const int MAX_SPACES = 10;

    for (int level = 0; level < h; level++) {
        int levelNodes = 1 << level;

        int spaceBetween = ((1 << (h - level)) - 1);
        int leadingSpaces = ((1 << (h - level - 1)) - 1);

        spaceBetween = std::min(spaceBetween, MAX_SPACES);
        leadingSpaces = std::min(leadingSpaces, MAX_SPACES);

        for (int i = 0; i < leadingSpaces; i++)
            std::cout << " ";

        for (int i = 0; i < levelNodes; i++) {
            tree* current = nullptr;
            if (!q.empty()) {
                current = q.front();
                q.pop();
            }

            if (current) {
                std::cout << current->inf;
                q.push(current->left);
                q.push(current->right);
            }
            else {
                std::cout << " ";
                q.push(nullptr);
                q.push(nullptr);
            }

            for (int j = 0; j < spaceBetween; j++)
                std::cout << " ";
        }

        std::cout << std::endl;
    }
}

// Поиск узла по значению
tree* find(tree* tr, int x) {
    if (!tr || tr->inf == x) return tr;
    if (x < tr->inf) return find(tr->left, x);
    else return find(tr->right, x);
}

// Поиск брата/сестры
tree* findSibling(tree* node) {
    if (!node || !node->parent) return NULL;
    tree* parent = node->parent;
    if (parent->left == node) return parent->right;
    else return parent->left;
}

// Вывод племянников
void printNephews(tree* sibling) {
    if (!sibling) {
        cout << "Племянников нет (нет брата/сестры)" << endl;
        return;
    }

    cout << "Дети брата/сестры (племянники): ";
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

// Симметричный обход
void inorder(tree* tr) {
    if (tr) {
        inorder(tr->left);
        cout << tr->inf << " ";
        inorder(tr->right);
    }
}

// Очистка дерева
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
    tree* tr = NULL;
    int n, x, target;

    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(tr, x);
    }

    // ВАШ оригинальный вывод дерева
    cout << "\nДерево бинарного поиска:\n";
    print_Tree(tr);

    // Отсортированная последовательность
    cout << "\nОтсортированная последовательность: ";
    inorder(tr);
    cout << endl;

    cout << "\nВведите значение узла X: ";
    cin >> target;

    tree* nodeX = find(tr, target);

    if (!nodeX) {
        cout << "\nУзел " << target << " не найден!" << endl;
        clearTree(tr);
        return 0;
    }

    cout << "\nУзел " << target << " найден." << endl;

    tree* sibling = findSibling(nodeX);

    if (!sibling) {
        if (!nodeX->parent) {
            cout << "Узел является корнем. У корня нет племянников." << endl;
        }
        else {
            cout << "У родителя нет второго ребенка, племянников нет." << endl;
        }
    }
    else {
        cout << "Брат/сестра узла: " << sibling->inf << endl;
        printNephews(sibling);
    }

    clearTree(tr);
    return 0;
}