#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {

    setlocale(LC_ALL, "RUS");

    // Запросить слова у пользователя
    std::string input;
    std::cout << "Введите слова через запятую: ";
    std::getline(std::cin, input);

    // Разбить введенную строку на слова
    std::vector<std::string> words;
    std::istringstream iss(input);
    std::string word;
    while (std::getline(iss, word, ',')) {
        // Удалить лишние пробелы в начале и конце слова
        size_t start = word.find_first_not_of(' ');
        size_t end = word.find_last_not_of(' ');
        if (start != std::string::npos && end != std::string::npos) {
            words.push_back(word.substr(start, end - start + 1));
        }
    }

    // Проверка наличия хотя бы трех слов для составления стиха
    if (words.size() < 3) {
        std::cout << "Недостаточно слов для составления стиха." << std::endl;
        return 0;
    }

    // Составление стиха
    std::cout << "Стих:" << std::endl;
    for (int i = 0; i < words.size(); i += 3) {
        std::cout << words[i] << ", " << words[i + 1] << ", " << words[i + 2] << ", " << std::endl;
    }

    return 0;
}