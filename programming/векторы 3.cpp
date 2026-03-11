#include <iostream>
#include <vector>
#include <numeric>    // для inner_product
#include <functional> // для plus
#include <cmath>      

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    vector<vector<double>> points; // Создаем вектор точек (каждая точка - вектор из 3 координат)
    int n;
    cout << "Введите N: "; cin >> n;
    cout << "\nВведите координаты точек (x y z):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Точка " << i + 1 << ": ";
        double x, y, z; cin >> x >> y >> z;
        vector<double> point; // Создаем вектор с координатами и добавляем в список
        point.push_back(x);
        point.push_back(y);
        point.push_back(z);
        points.push_back(point);
    }
    cout << "\nВведите координаты точки X: "; 
    double xX, yX, zX; cin >> xX >> yX >> zX;
    vector<double> X;
    X.push_back(xX);
    X.push_back(yX);
    X.push_back(zX);

    cout << "\nТочка X: (" << X[0] << ", " << X[1] << ", " << X[2] << ")" << endl;

    cout << "\nСписок точек:" << endl;
    for (int i = 0; i < points.size(); i++) {
        cout << "Точка " << i + 1 << ": (";
        cout << points[i][0] << ", " << points[i][1] << ", " << points[i][2] << ")" << endl;
    }

    vector<double> distance(points.size()); // Вектор для хранения расстояний
    for (int i = 0; i < points.size(); i++) { 
        double sum = inner_product(
            points[i].begin(),  // начало первого вектора (точка из списка)
            points[i].end(),    // конец первого вектора
            X.begin(),          // начало второго вектора (точка X)
            0.0,                // начальное значение (init)
            plus<double>(),     // внешняя операция (складывать результаты)
            [](double a, double b) -> double {
                double diff = a - b;        // находим разность координат
                return diff * diff;          // возвращаем квадрат разности
            }
        );
        distance[i] = sqrt(sum);
    }
    cout << "\nРасстояния от точки X до каждой точки:" << endl;
    for (int i = 0; i < distance.size(); i++) {
        cout << "До точки " << i + 1 << ": " << distance[i] << endl;
    }
    cout << endl;
    double maxDistance = distance[0]; 
    int maxIndex = 0; // индекс точки с максимальным расстоянием
    for (int i = 1; i < distance.size(); i++) {
        if (distance[i] > maxDistance) {
            maxDistance = distance[i];
            maxIndex = i;
        }
    }
    cout << "РЕЗУЛЬТАТ:" << endl;
    cout << "Максимальное расстояние от точки X до других точек = " << maxDistance << endl;
    cout << "Это расстояние до точки " << maxIndex + 1 << " с координатами: (";
    cout << points[maxIndex][0] << ", " << points[maxIndex][1] << ", " << points[maxIndex][2] << ")" << endl;
    return 0;
}