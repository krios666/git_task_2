//#include <iostream> // Сортировкой чёт-нечет сначала по фамилии, потом по стажу, потом по зарплате. Сложность N^2
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
//    if (a.Name != b.Name) {
//        return a.Name < b.Name;
//    }
//    if (a.Experience != b.Experience) {
//        return a.Experience < b.Experience; 
//    }
//    return a.Salary < b.Salary; 
//}
//
//void chet_nechet_sort(vector<people>& x) {
//    if (x.size() <= 1) return;
//    bool sorted = false;
//    int n = x.size();
//    while (!sorted) {
//        sorted = true;
//        for (int j = 1; j <= n - 1; j += 2) { // Четный проход 
//            if (!compare(x[j - 1], x[j])) {
//                swap(x[j - 1], x[j]);
//                sorted = false;
//            }
//        }
//        for (int j = 1; j <= n - 2; j += 2) { // Нечетный проход
//            if (!compare(x[j], x[j + 1])) {
//                swap(x[j], x[j + 1]);
//                sorted = false;
//            }
//        }
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "RUS");
//    vector<people> x = inFile();
//    chet_nechet_sort(x);
//    for (int i = 0; i < x.size(); i++) {
//        print(x[i]);
//    }
//    cout << "Отсортированные данные (сначала по фамилии, потом по стажу, потом по зарплате):" << endl;
//    for (int i = 0; i < x.size(); i++) {
//        cout << x[i] << endl;
//    }
//    cout << "\nРезультат сохранен в output.txt" << endl;
//    in.close();
//    out.close();
//    system("pause");
//    return 0;
//}