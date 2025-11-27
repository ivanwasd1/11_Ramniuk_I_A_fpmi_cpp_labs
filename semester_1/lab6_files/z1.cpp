#include <fstream>
#include <iostream>
#include <string>

const int MAX_SIZE = 1000;

struct word {
    int cnt = 0;
    std::string s;
};

word mostCounter(const std::string *arr, int n) {

    if (n <= 0)
        throw "Empty array in mostCounter";

    word best{0, arr[0]};
    for (int i = 0; i < n; i++) {
        word now{0, arr[i]};
        for (int j = 0; j < n; j++) {
            if (arr[j] == now.s)
                now.cnt++;
        }
        if (best.cnt < now.cnt)
            best = now;
    }
    return best;

}

int main() {


    try {

        std::ifstream in("input.txt");

        if (!in.is_open())
            throw "We can't open file!!!";
        else if (in.peek() == EOF)
            throw "file is empty!!!";

        std::string *arrStr = new std::string[MAX_SIZE];
        int arrSize = 0;
        std::string temp;
        while (in >> temp){
            if (arrSize >= MAX_SIZE)
                throw "Too many words in file!!!";
            arrStr[arrSize++] = temp;
        }

        word counter = mostCounter(arrStr, arrSize);
        std::cout << "the most common word is " << counter.s << '\n';
        std::cout << "It appeared " << counter.cnt << " times in the text\n";

        delete[] arrStr;
    }
    catch (const char* error)
    {
        std::cout << "error - " << error << '\n';
    }
    std::cout << "Program is finished";

    return 0;

}
