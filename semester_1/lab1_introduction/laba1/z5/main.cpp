#include <iostream>
#include <cmath>

using namespace std;

/*
Даны два натуральных числа n и m(вводятся с клавиатуры). Вывести
все их общие делители
*/

int my_gcd(int a, int b) {

    if (!(a % b))
        return b;
    if (!(b % a))
        return a;

    if (a > b)
        return my_gcd(a % b, b);
    else
        return my_gcd(a, b % a);
}

int main()
{
    int n, m;
    cin >> n >> m;
    int gcd = my_gcd(n, m);

    cout << "common divisors of numbers " << n << " and " << m << ":\n";
    for (int i = 1; i <= gcd; i++)
        if (!(gcd % i))
            cout << i << ' ';


    return 0;
}
