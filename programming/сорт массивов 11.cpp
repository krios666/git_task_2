#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

ifstream in("C:\\Users\\User\\Desktop\\input.txt");
ofstream out("C:\\Users\\User\\Desktop\\output.txt");

void bubbleSort(vector<int>& arr) { // Сортировка пузырьком диагоналей, параллельных побочной? по убыванию (в среднем и хужшем случае N^2. с лучшем N)
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void sortDiagonalsParallelToSecondaryBubble(vector<vector<int>>& matrix, int N) {
    // Всего диагоналей, параллельных побочной: 2*N - 1
    // Индексы: сумма i + j = const от 0 до 2*(N-1)
    for (int sum = 0; sum <= 2 * (N - 1); sum++) {
        vector<int> diag;
        // Собираем элементы
        for (int i = 0; i < N; i++) {
            int j = sum - i;
            if (j >= 0 && j < N) {
                diag.push_back(matrix[i][j]);
            }
        }
        // Сортируем пузырьком
        bubbleSort(diag);
        // Записываем обратно
        int idx = 0;
        for (int i = 0; i < N; i++) {
            int j = sum - i;
            if (j >= 0 && j < N) {
                matrix[i][j] = diag[idx++];
            }
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix, ostream& os) {
    int N = matrix.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            os << setw(5) << matrix[i][j] << " ";
        }
        os << endl;
    }
}

vector<vector<int>> readMatrixFromFile(int& N) {
    if (!in.is_open()) {
        cerr << "Не удалось открыть файл input.txt" << endl;
        return {};
    }
    in >> N;
    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            in >> matrix[i][j];
        }
    }
    return matrix;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int N;
    vector<vector<int>> original = readMatrixFromFile(N);

    out << "Исходная матрица:" << endl;
    cout << "Исходная матрица:" << endl;
    printMatrix(original, out);
    printMatrix(original, cout);
    out << endl;
    cout << endl;

    vector<vector<int>> result = original; // Сортировка диагоналей, параллельных побочной
    sortDiagonalsParallelToSecondaryBubble(result, N);

    out << "Диагонали, параллельные побочной, по убыванию (сортировка пузырьком):" << endl;
    cout << "Диагонали, параллельные побочной, по убыванию (сортировка пузырьком):" << endl;
    printMatrix(result, out);
    printMatrix(result, cout);
    in.close();
    out.close();
    system("pause");
    return 0;
}