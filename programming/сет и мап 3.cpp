#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <cctype>

using namespace std;

string Lower(string s) {
    string result = s;
    for (int i = 0; i < result.length(); i++) {
        result[i] = tolower(result[i]);
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "RUS");
    set<string> wordsInPoint;
    set<string> wordsInExclam;

    string text;
    cout << "Введите текст (для окончания введите 'end'):" << endl;

    string line;
    while (getline(cin, line)) {
        if (line == "end") break;
        text += line + " ";
    }

    // Разбиваем текст на предложения по . ! ?
    string sentence;
    stringstream ss(text);
    char ch;

    while (ss.get(ch)) {
        sentence += ch;
        if (ch == '.' || ch == '!' || ch == '?') {
            // Обрабатываем предложение
            char sentenceType = ch;
            stringstream sentenceStream(sentence);
            string word;
            while (sentenceStream >> word) {
                // Очищаем слово от знаков препинания в конце
                while (!word.empty() && ispunct(word.back())) {
                    word.pop_back();
                }
                if (word.empty()) continue;
                word = Lower(word);

                if (sentenceType == '.') {
                    wordsInPoint.insert(word);
                }
                else if (sentenceType == '!') {
                    wordsInExclam.insert(word);
                }
            }
            sentence.clear();
        }
    }

    set<string> result;
    for (const string& w : wordsInPoint) {
        if (wordsInExclam.find(w) != wordsInExclam.end()) {
            result.insert(w);
        }
    }
    cout << "\nСлова, встречающиеся и в повествовательных, и в восклицательных предложениях:" << endl;
    if (result.empty()) {
        cout << "Таких слов нет" << endl;
    }
    else {
        for (const string& w : result) {
            cout << w << endl;
        }
    }
    return 0;
}