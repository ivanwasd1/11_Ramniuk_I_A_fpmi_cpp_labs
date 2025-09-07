#include <iostream>

/*
Вычислить первые n чисел Фибоначчи.
Число n вводится с клавиатуры.
Числа Фибоначчи вычисляются по формуле:
Fn = Fn−1 + Fn−2, где F0 = 0, F1 = 1.
*/

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a = 0, b = 1;
    cout << a << ' ' << b << ' ';
    for (int i = 0; i < n - 2; i++) {

        cout << a + b << ' ';

        b = a + b;
        a = b - a;
    }

    return 0;
}
