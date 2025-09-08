#include <iostream>

using namespace std;

/*
Вычислите сумму цифр целого неотрицательного числа.
Число вводится с клавиатуры.
*/

int main()
{
    int n, s = 0;
    cin >> n;

    while (n) {
        s += n % 10;
        n /= 10;
    }

    cout << s;


    return 0;
}
