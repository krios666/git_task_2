#include <iostream> // Сортировка расческой. Сложность N^2, но стремится к N log(N).
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

ifstream in("C:\\Users\\User\\Desktop\\input.txt");
ofstream out("C:\\Users\\User\\Desktop\\output.txt");

void combSort(vector<int>& arr, bool ascending) {
    int n = arr.size();
    int gap = n;
    bool swapped = true;
    while (gap > 1 || swapped) {
        gap = max(1, int(gap / 1.247));
        swapped = false;
        for (int i = 0; i + gap < n; i++) {
            if (ascending) {
                if (arr[i] > arr[i + gap]) {
                    swap(arr[i], arr[i + gap]);
                    swapped = true;
                }
            }
            else {
                if (arr[i] < arr[i + gap]) {
                    swap(arr[i], arr[i + gap]);
                    swapped = true;
                }
            }
        }
    }
}

void sortRowsComb(vector<vector<int>>& matrix, int N) {
    for (int i = 0; i < N; i++) {
        bool ascending = (i % 2 == 0); // чётные строки (0,2,4...) – по возрастанию
        combSort(matrix[i], ascending);
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

    vector<vector<int>> result = original; // Сортировка строк расчёской
    sortRowsComb(result, N);

    out << "Чётные строки по возрастанию, нечётные по убыванию (сортировка расчёской):" << endl;
    cout << "Чётные строки по возрастанию, нечётные по убыванию (сортировка расчёской):" << endl;
    printMatrix(result, out);
    printMatrix(result, cout);
    in.close();
    out.close();
    system("pause");
    return 0;
}