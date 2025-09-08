#include <iostream>

/*
Дана арифметическая прогрессия: ak = ak−1 + d. Вывести все члены
этой прогрессии, кратные 3, которые лежат на отрезке [a, b]. Числа a, b
и d вводятся с клавиатуры(a0 = a).
*/

using namespace std;

int main()
{

    int a, b, d;
    cin >> a >> b >> d;
    for (int i = a; i <= b; i += d)
        if (!(i % 3))
            cout << i << ' ';

}
