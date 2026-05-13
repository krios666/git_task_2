//#include <iostream> // Сортировкой слиянием по зарплате, затем по году рождения. Сложность N log(N)
//#include <vector>
//#include <string>
//#include <fstream>
//#include <iomanip>
//#include <algorithm>
//using namespace std;
//
//ifstream in("C:\\Users\\User\\Desktop\\input.txt");
//ofstream out("C:\\Users\\User\\Desktop\\output.txt");
//
//struct date {
//    int dd, mm, yy;
//};
//
//struct people {
//    string Name;
//    string Position;
//    date dob;
//    int Salary;
//    int Experience;
//};
//
//date Str_to_Date(string str) {
//    date x = { 1, 1, 2000 };
//    if (str.length() >= 10 && str[2] == '.' && str[5] == '.') {
//        x.dd = atoi(str.substr(0, 2).c_str());
//        x.mm = atoi(str.substr(3, 2).c_str());
//        x.yy = atoi(str.substr(6, 4).c_str());
//    }
//    return x;
//}
//
//vector<people> inFile() {
//    vector<people> x;
//    people temp;
//    string tmp_date;
//    while (in >> temp.Name >> temp.Position >> tmp_date >> temp.Salary >> temp.Experience) {
//        temp.dob = Str_to_Date(tmp_date);
//        x.push_back(temp);
//    }
//    return x;
//}
//
//void print(people x) {
//    out << setw(12) << left << x.Name;
//    out << setw(30) << left << x.Position;
//    if (x.dob.dd < 10) out << '0';
//    out << x.dob.dd << '.';
//    if (x.dob.mm < 10) out << '0';
//    out << x.dob.mm << '.';
//    out << x.dob.yy << "   ";
//    out << setw(6) << left << x.Experience;
//    out << setw(10) << left << x.Salary << endl;
//}
//
//ostream& operator<<(ostream& os, const people& x) {
//    os << setw(12) << left << x.Name;
//    os << setw(30) << left << x.Position;
//    if (x.dob.dd < 10) os << '0';
//    os << x.dob.dd << '.';
//    if (x.dob.mm < 10) os << '0';
//    os << x.dob.mm << '.';
//    os << x.dob.yy << "   ";
//    os << setw(6) << left << x.Experience;
//    os << setw(10) << left << x.Salary;
//    return os;
//}
//
//bool compare(const people& a, const people& b) {
//    if (a.Salary != b.Salary) {
//        return a.Salary < b.Salary;
//    }
//    if (a.dob.yy != b.dob.yy) {
//        return a.dob.yy < b.dob.yy;
//    }
//    if (a.dob.mm != b.dob.mm) {
//        return a.dob.mm < b.dob.mm;
//    }
//    return a.dob.dd < b.dob.dd; 
//}
//
//void merge(vector<people>& x, int left, int mid, int right) {
//    int n1 = mid - left + 1;
//    int n2 = right - mid;
//
//    vector<people> leftArr(n1);
//    vector<people> rightArr(n2);
//
//    for (int i = 0; i < n1; i++)
//        leftArr[i] = x[left + i];
//    for (int j = 0; j < n2; j++)
//        rightArr[j] = x[mid + 1 + j];
//
//    int i = 0, j = 0, k = left;
//
//    while (i < n1 && j < n2) {
//        if (compare(leftArr[i], rightArr[j])) {
//            x[k] = leftArr[i];
//            i++;
//        }
//        else {
//            x[k] = rightArr[j];
//            j++;
//        }
//        k++;
//    }
//    while (i < n1) {
//        x[k] = leftArr[i];
//        i++;
//        k++;
//    }
//    while (j < n2) {
//        x[k] = rightArr[j];
//        j++;
//        k++;
//    }
//}
//
//void merge_sort(vector<people>& x, int left, int right) {
//    if (left < right) {
//        int mid = left + (right - left) / 2;
//        merge_sort(x, left, mid);
//        merge_sort(x, mid + 1, right);
//        merge(x, left, mid, right);
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "RUS");
//    vector<people> x = inFile();
//    if (x.size() > 0) {
//        merge_sort(x, 0, x.size() - 1);
//    }
//    for (int i = 0; i < x.size(); i++) {
//        print(x[i]);
//    }
//    cout << "Отсортированные данные (сначала по зарплате, потом по году рождения):" << endl;
//    for (int i = 0; i < x.size(); i++) {
//        cout << x[i] << endl;
//    }
//    cout << "\nРезультат сохранен в output.txt" << endl;
//    in.close();
//    out.close();
//    system("pause");
//    return 0;
//}