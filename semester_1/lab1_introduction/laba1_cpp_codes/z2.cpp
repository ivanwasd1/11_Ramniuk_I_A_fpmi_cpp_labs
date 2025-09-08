#include <iostream>

using namespace std;

/*
Вычислить сумму всех чётных чисел и произведение всех нечётных на
отрезке [1, n]. Число n вводится с клавиатуры.

*/

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int prod = 1;
    for (int i = 1; i <= n; i++)
        sum += i * !(i % 2), prod *= i * (i % 2) + 1 * !(i % 2);

    cout << sum << '\n' << prod;
}
