//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main() {
//	setlocale(LC_ALL, "russian");
//	int n;
//	cout << "Размер n = "; cin >> n;
//
//	vector<int> vec;
//	int a;
//	for (int i = 0; i < n; i++) {
//		cout << "a[" << i << "] = ";
//		cin >> a;
//		vec.push_back(a);
//	}
//	cout << "\nИсходный массив: \n";
//	for (int i = 0; i < vec.size(); i++) {
//		cout << vec[i] << " ";
//	}
//	cout << endl;
//
//	int max = *max_element(vec.begin(), vec.end());
//	int X; cout << "\nВведите X: "; cin >> X;
//	for (int& x : vec) { // & - указатель на элементы
//		if (x % X == 0 && x != 0){
//			x = max;
//		}
//	}
//	cout << "\nПосле замены: \n";
//	for (int i = 0; i < vec.size(); i++) {
//		cout << vec[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}