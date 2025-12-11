#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

int CountUpper(const std::string& str) {
    int count = 0;
    for (unsigned char ch : str) {
        if (std::isupper(ch)) {
            ++count;
        }
    }
    return count;
}

void  ChangeRegistr(std::string& str) {
    for (char& ch : str) {
        if (std::islower(ch)) {
            ch = std::toupper(ch);
        } else if (std::isupper(ch)) {
            ch = std::tolower(ch);
        }
    }
}

std::vector<std::string> toWords(const std::string& str) {
    std::vector<std::string> words;
    std::string temp;

    for (unsigned char ch : str) {
        if (ch == ' ') {
            if (!temp.empty()) {
                words.push_back(temp);
                temp.clear();
            }
        } else {
            temp.push_back(static_cast<char>(ch));
        }
    }

    if (!temp.empty()) {
        words.push_back(temp);
    }

    return words;
}

int main() {

    using std::string;
    using std::vector;
    using std::cout;
    using std::cin;

    string line;
    std::getline(cin, line);

    ChangeRegistr(line);

    cout << "\nREPLACED! (changing upper case to lower case and vice versa)\n\n";
    cout << line << '\n';

    vector<string> words = toWords(line);

    std::sort(words.begin(), words.end(),
              [](const string& a, const string& b) {
                  int ca = CountUpper(a);
                  int cb = CountUpper(b);
                  if (ca != cb) {
                      return ca < cb;
                  }
                  return a < b;
              });

    cout << "\nREPLACED! (sorting by the counts of uppercase letters)\n\n";
    for (const auto& w : words) {
        cout << w << ' ';
    }
    cout << '\n';

    return 0;
}
