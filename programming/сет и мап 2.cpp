//#include <iostream>
//#include <fstream>
//#include <map>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//int main() {
//    setlocale(LC_ALL, "RUS");
//    string filename;
//    int k;
//
//    // Ввод имени файла и числа k
//    cout << "Введите имя входного файла: "; cin >> filename;
//    cout << "Введите число k: "; cin >> k;
//
//    ifstream file(filename);
//    if (!file.is_open()) {
//        cout << "Ошибка открытия файла" << endl;
//        return 1;
//    }
//
//    map<string, int> word_count; // Для подсчета количества вхождений каждого слова
//    string word; // Читаем файл слово за словом
//
//    while (file >> word) {
//        word_count[word]++;
//    }
//    file.close();
//
//    cout << "Слова, встречающиеся ровно " << k << " раз:" << endl;
//
//    bool flag = false;
//    for (map<string, int>::iterator i = word_count.begin(); i != word_count.end(); ++i) {
//        if (i->second == k) {
//            cout << i->first << " (" << i->second << " раз)" << endl;
//            flag = true;
//        }
//    }
//    if (!flag) {
//        cout << "Таких слов нет" << endl;
//    }
//    return 0;
//}