#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

const vector<string> Words = {
    "программист", "компьютер", "алгоритм",
    "разработчик", "клавиатура", "монитор",
    "процессор", "интерфейс", "операционная",
    "виселица", "программа", "документация"
};

const string Hangman[] = { // Рисунки виселицы
    "   +---+\n       |\n       |\n       |\n       |\n       |\n=========",
    "   +---+\n   |   |\n       |\n       |\n       |\n       |\n=========",
    "   +---+\n   |   |\n   O   |\n       |\n       |\n       |\n=========",
    "   +---+\n   |   |\n   O   |\n   |   |\n       |\n       |\n=========",
    "   +---+\n   |   |\n   O   |\n  /|   |\n       |\n       |\n=========",
    "   +---+\n   |   |\n   O   |\n  /|\\  |\n       |\n       |\n=========",
    "   +---+\n   |   |\n   O   |\n  /|\\  |\n  /    |\n       |\n=========",
    "   +---+\n   |   |\n   O   |\n  /|\\  |\n  / \\  |\n       |\n========="
};

void showWord(string word, vector<bool>& guessed) {
    for (int i = 0; i < word.length(); i++) {
        if (guessed[i]) cout << word[i] << " ";
        else cout << "_ ";
    }
    cout << endl;
}

void showAlphabet(vector<char>& letters, vector<bool>& used) {
    cout << "Буквы: ";
    for (int i = 0; i < letters.size(); i++) {
        if (used[i]) cout << letters[i] << " ";
        else cout << "X ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    string word = Words[rand() % Words.size()]; // Выбор слова
    vector<bool> guessed(word.length(), false);

    vector<char> letters; // Русский алфавит
    string alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    for (int i = 0; i < alphabet.length(); i++) {
        letters.push_back(alphabet[i]);
    }
    vector<bool> usedLetters(letters.size(), true);

    cout << "=== ВИСЕЛИЦА ===\n\n";
    int mode; // Выбор режима
    cout << "1 - 10 попыток\n2 - Виселица\nВыбор: ";
    cin >> mode;

    int mistakes = 0;
    int maxMistakes = (mode == 1) ? 10 : 7;

    while (mistakes < maxMistakes) {
        if (mode == 2) cout << Hangman[mistakes] << endl; // Показываем виселицу в режиме 2
        else cout << "Ошибок: " << mistakes << "/" << maxMistakes << endl;

        cout << "\nСлово: ";
        showWord(word, guessed);
        showAlphabet(letters, usedLetters);

        cout << "\n1 - буква\n2 - слово\nВыбор: "; // Меню
        int choice;
        cin >> choice;

        if (choice == 1) {
            char letter;
            cout << "Буква: ";
            cin >> letter;
            letter = tolower(letter);

            int idx = -1; // Ищем букву в русском алфавите
            for (int i = 0; i < letters.size(); i++) {
                if (letters[i] == letter) {
                    idx = i;
                    break;
                }
            }
            if (idx == -1 || !usedLetters[idx]) {
                cout << "Буква уже использована или не существует!\n";
                continue;
            }
            usedLetters[idx] = false;

            bool found = false; // Проверяем угадал или нет
            for (int i = 0; i < word.length(); i++) {
                if (word[i] == letter) {
                    guessed[i] = true;
                    found = true;
                }
            }
            if (found) {
                cout << "Правильно!\n";
            }
            else {
                cout << "Неправильно!\n";
                mistakes++;
            }
            bool win = true; // Проверка победы
            for (int i = 0; i < word.length(); i++) {
                if (!guessed[i]) win = false;
            }
            if (win) {
                cout << "\nПОБЕДА! Слово: " << word << endl;
                return 0;
            }
        }
        else if (choice == 2) {
            string guess;
            cout << "Ваше слово: ";
            cin >> guess;
            transform(guess.begin(), guess.end(), guess.begin(), ::tolower); // Приводим к нижнему регистру для сравнения
            if (guess == word) {
                cout << "\nПОБЕДА! Слово: " << word << endl;
                return 0;
            }
            else {
                cout << "\nНеправильно! Загаданное слово: " << word << endl;
                return 0;
            }
        }
        cout << "\n-------------------\n";
    }
    if (mode == 2) cout << Hangman[maxMistakes] << endl; // Проигрыш
    cout << "\nВЫ ПРОИГРАЛИ! Загаданное слово: " << word << endl;
    return 0;
}