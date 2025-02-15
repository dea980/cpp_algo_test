#include <iostream>
#include <string>
#include <vector>
#include <vector>

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
    
    // Create a dynamic 2D vector instead of VLA
    std::vector<std::vector<bool>> table(n, std::vector<bool>(n, false));

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++) {
        table[i][i] = true;
        palindromes.push_back(str.substr(i, 1));
    }

    // Check for substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (str[i] == str[i + 1]) {
            table[i][i + 1] = true;
            palindromes.push_back(str.substr(i, 2));
        }
    }

    // Check for lengths greater than 2
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            if (str[i] == str[j] && table[i + 1][j - 1]) {
                table[i][j] = true;
                palindromes.push_back(str.substr(i, len));
            }
        }
    }

    return palindromes;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (input.empty()) {
        std::cout << "Empty string provided." << std::endl;
        return 1;
    }

    std::vector<std::string> palindromes = findPalindromicSubstrings(input);
    std::cout << "Palindromic substrings:" << std::endl;
    for (const auto& palindrome : palindromes) {
        std::cout << palindrome << std::endl;
    }

    std::cout << "Number of palindromic substrings: " << palindromes.size() << std::endl;

    return 0;
}
