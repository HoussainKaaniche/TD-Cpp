#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <cctype>

using namespace std;

bool isPalindrome(const string& input) {
    queue<char> file;
    stack<char> pile;

    for (unsigned char c : input) {
        if (isalnum(c)) {
            char lettre = static_cast<char>(tolower(c));

            file.push(lettre);
            pile.push(lettre);
        }
    }

    while (!file.empty()) {
        if (file.front() != pile.top()) {
            return false;
        }

        file.pop();
        pile.pop();
    }

    return true;
}

int main() {
    cout << boolalpha;

    cout << "Is 'racecar' a palindrome? "
         << isPalindrome("racecar") << endl;

    cout << "Is 'hello' a palindrome? "
         << isPalindrome("hello") << endl;

    return 0;
}