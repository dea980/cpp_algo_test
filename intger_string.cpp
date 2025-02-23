#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<std::string> reverseWords(const std::string& input) {
    std::vector<std::string> words;
    std::string word;

    for (char c : input) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        else {
            word += c;
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    std::reverse(words.begin(), words.end());

    return words;
}

int main() {
    std::string input;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    std::vector<std::string> reversedWords = reverseWords(input);
    std::cout << "Reversed sentence: ";
    for (const auto& word : reversedWords) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}