#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

ifstream in("C:\\Users\\User\\Desktop\\input.txt");
ofstream out("C:\\Users\\User\\Desktop\\output.txt");

int partition(vector<int>& arr, int low, int high) { // Быстрая сортировка столбцов по возрастанию. Сложность N log(N).
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sortColumnsQuick(vector<vector<int>>& matrix, int N) {
    for (int j = 0; j < N; j++) {
        vector<int> column(N);
        for (int i = 0; i < N; i++) {
            column[i] = matrix[i][j];
        }
        quickSort(column, 0, N - 1);
        for (int i = 0; i < N; i++) {
            matrix[i][j] = column[i];
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
    out << "Исходная матрица:" << endl; // Вывод исходной матрицы
    cout << "Исходная матрица:" << endl;
    printMatrix(original, out);
    printMatrix(original, cout);
    out << endl;
    cout << endl;
    vector<vector<int>> result = original; // Сортировка столбцов по возрастанию
    sortColumnsQuick(result, N);
    out << "Столбцы по возрастанию (быстрая сортировка):" << endl;
    cout << "Столбцы по возрастанию (быстрая сортировка):" << endl;
    printMatrix(result, out);
    printMatrix(result, cout);
    in.close();
    out.close();
    system("pause");
    return 0;
}