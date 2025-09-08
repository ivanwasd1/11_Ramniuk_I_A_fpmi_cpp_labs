#include <iostream>

using namespace std;

//Вычислить так называемый «двойной факториал»:

int main()
{
    int k, prod = 1;
    cin >> k;
    for (int i = !(k % 2) + 1; i <= k; i += 2)
        prod *= i;

    cout << prod;
}

