#include <iostream>

using namespace std;

/*
��������� ����� ���� ������ ����� � ������������ ���� �������� ��
������� [1, n]. ����� n �������� � ����������.

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
