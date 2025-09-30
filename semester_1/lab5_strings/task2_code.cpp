#include <iostream>
#include <string>
#include <vector>

int CountOfUppers(std::string str) {

    int count = 0;
    for (char c : str)
        if (c >= 'A' && c <= 'Z')
            count++;

    return count;
}

bool comp(std::string x, std::string y) {

    if (CountOfUppers(x) < CountOfUppers(y))
        return 1;
    else if (CountOfUppers(x) == CountOfUppers(y) && x < y)
        return 1;
    else
        return 0;

}

int main()
{
    using std::cout;
    using std::cin;
    using std::vector;
    using std::string;

    string str;
    getline(cin, str);

    int size_of_str = str.size();

    for (int i = 0; i < size_of_str; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;

    cout << "\nREPLACED!(changing upper case to lower case and vice versa)\n\n";
    cout << str << '\n';

    vector<string> words;
    str += ' ';

    while (str != "") {

        string temp_str = str.substr(0, str.find(' '));
        words.push_back(temp_str);

        int cnt_of_space = 0;
        while (str[str.find(' ') + 1 + cnt_of_space] == ' ')
            cnt_of_space++;

        str.erase(0, str.find(' ') + 1 + cnt_of_space);

    }
    int size_of_words = words.size();

    for (int i = 0; i < size_of_words; i++) {
        int best_idx = i;
        for (int j = i + 1; j < size_of_words; j++)
            if (comp(words[j], words[best_idx]))
                best_idx = j;
        swap(words[i], words[best_idx]);
    }

    cout << "\nREPLACED!(sorting by the counts of uppercase letters)\n\n";

    for (int i = 0; i < size_of_words; i++)
        cout << words[i] << ' ';

    return 0;
}
