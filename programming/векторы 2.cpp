//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    setlocale(LC_ALL, "RUS");
//    int n; 
//    cout << "Введите N: "; cin >> n;
//    vector<int> vec;
//    int x;
//    for (int i = 0; i < n; i++) {
//        cout << "a[" << i << "] = ";
//        cin >> x;
//        vec.push_back(x);
//    }
//    cout << "Исходный массив: ";
//    for (int i = 0; i < vec.size(); i++) {
//        cout << vec[i] << " ";
//    }
//    cout << endl;
//
//    vector<int> vec2 = vec; //Создаем новую послед. с заменой
//    int first_chet = -1; // Ищем первое четное число
//    for (int i = 0; i < vec2.size(); i++) {
//        if (vec2[i] % 2 == 0) {
//            first_chet = i;
//            break;
//        }
//    }
//    int last_nchet = -1; // Ищем последнее нечетное число
//    for (int i = vec2.size() - 1; i >= 0; i--) {
//        if (vec2[i] % 2 != 0) {
//            last_nchet = i;
//            break;
//        }
//    }
//    cout << "Пункт 1 (Заменяем между первым четным и последним нечётным на минимальное): " << endl;
//    cout << "Первое четное число: " << vec2[first_chet] << endl;
//    cout << "Последнее нечетное число: " << vec2[last_nchet] << endl;
//    if (first_chet != -1 && last_nchet != -1 && first_chet < last_nchet) { // Если нашли оба индекса
//        int minNumber = vec2[first_chet]; // Ищем минимальное число в этом диапазоне
//        for (int i = first_chet + 1; i <= last_nchet; i++) {
//            if (vec2[i] < minNumber) {
//                minNumber = vec2[i];
//            }
//        }
//        cout << "Минимальное число в диапазоне: " << minNumber << endl; 
//        for (int i = first_chet + 1; i < last_nchet; i++) { // Заменяем все числа в диапазоне на минимальное
//            vec2[i] = minNumber;
//        }
//    }
//    cout << "Результат: ";
//    for (int i = 0; i < vec2.size(); i++) {
//        cout << vec2[i] << " ";
//    }
//    cout << endl;
//
//    vector<int> vec3 = vec2;
//    int maxIndex = 0; // Ищем максимальный элемент
//    for (int i = 1; i < vec3.size(); i++) {
//        if (vec3[i] > vec3[maxIndex]) {
//            maxIndex = i;
//        }
//    }
//
//    cout << "Пункт 2 (Циклом переносим максимальный элемент на 0 индекс):" << endl;
//    cout << "Максимальный элемент: " << vec3[maxIndex] << endl;
//    vector<int> vec4; // Делаем циклический сдвиг
//    for (int i = maxIndex; i < vec3.size(); i++) { // Сначала добавляем элементы с maxIndex до конца
//        vec4.push_back(vec3[i]);
//    }
//    for (int i = 0; i < maxIndex; i++) { // Потом добавляем элементы с начала до maxIndex
//        vec4.push_back(vec3[i]);
//    }
//    cout << "Результат 2: ";
//    for (int i = 0; i < vec4.size(); i++) {
//        cout << vec4[i] << " ";
//    }
//    cout << endl;
//
//    vector<int> vec5 = vec4;
//    cout << "Пункт 3 (Удаляем повторы):" << endl; // Сортировка пузырьком
//    for (int i = 0; i < vec5.size() - 1; i++) {
//        for (int j = 0; j < vec5.size() - i - 1; j++) {
//            if (vec5[j] > vec5[j + 1]) { // Меняем местами
//                int temp = vec5[j];
//                vec5[j] = vec5[j + 1];
//                vec5[j + 1] = temp;
//            }
//        }
//    }
//    cout << "После сортировки: ";
//    for (int i = 0; i < vec5.size(); i++) {
//        cout << vec5[i] << " ";
//    }
//    cout << endl;
//
//    vector<int> vec6; // Удаляем повторяющиеся элементы
//    for (int i = 0; i < vec5.size(); i++) {
//        if (i == 0 || vec5[i] != vec5[i - 1]) { // Если это первый элемент или он отличается от предыдущего
//            vec6.push_back(vec5[i]);
//        }
//    }
//    cout << "Результат: ";
//    for (int i = 0; i < vec6.size(); i++) {
//        cout << vec6[i] << " ";
//    }
//    cout << endl;
//    return 0;
//}