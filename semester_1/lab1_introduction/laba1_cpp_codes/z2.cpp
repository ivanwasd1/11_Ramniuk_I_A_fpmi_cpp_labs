#include <iostream>

/*
��������� ����� ���� ������ ����� � ������������ ���� �������� ��
������� [1, n]. ����� n �������� � ����������.
*/

int main()
{
    using std::cin;
    using std::cout;

    int n;
    cout << "enter the n(=[1..INTMAX]): ";
    if (!(cin >> n) || n < 1) {
        cout << "ERROR!!!";
        std::exit(1);
    }
    int sum = 0;
    int prod = 1;
    for (int i = 1; i <= n; i++)
        sum += i * !(i % 2), prod *= i * (i % 2) + 1 * !(i % 2);

    cout << "sum: " << sum << '\n' << "product: " << prod;

    return 0;
}
