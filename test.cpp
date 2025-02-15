#include <iostream> // for iostream
#include <string>   // for string
#include <vector>   // for vector


// Function to check if a string is a palindrome
bool isPalindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

// Function to find all palindromic substrings in a string
std::vector<std::string> findPalindromicSubstrings(const std::string& str) {
    std::vector<std::string> palindromes;
    int n = str.length();
    bool table[n][n];
    memset(table, false, sizeof(table));

    int maxLength = 1;
    int start = 0;
    for (int i = 0; i < n; i++) {
        table[i][i] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        if (str[i] == str[i + 1]) {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
        else {
            table[i][i + 1] = false;
        }
        palindromes.push_back(str.substr(start, maxLength));
        start = i + 2;
        maxLength = 1;
        for (int k = i + 2; k < n; k++) {
            if (table[i + 1][k - 1] && str[i] == str[k]) {
                table[i][k] = true;
                if (k - i + 1 > maxLength) {
                    start = i;
                    maxLength = k - i + 1;
                }
            }
            else {
                table[i][k] = false;
            }
            palindromes.push_back(str.substr(start, maxLength));
        }
    }
    return palindromes;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::vector<std::string> palindromes = findPalindromicSubstrings(input);
    std::cout << "Palindromic substrings:" << std::endl;
    for (const auto& palindrome : palindromes) {
        std::cout << palindrome << std::endl;
    }

    int count = 0;
    for (const auto& palindrome : palindromes) {
        if (isPalindrome(palindrome)) {
            count++;
        }
    }
    std::cout << "Number of palindromic substrings: " << count << std::endl;

    return 0;
}
