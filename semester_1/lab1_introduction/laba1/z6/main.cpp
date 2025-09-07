#include <iostream>

using namespace std;

/*
Вычислить сумму первых n нечётных чисел.
Количество чисел n вводится с клавиатуры.
*/

int main()
{
    int n, sum = 0;
    cin >> n;

    for (int i = 1; i <= n; i+=2)
        sum += i;

    cout << sum;

    return 0;
}
