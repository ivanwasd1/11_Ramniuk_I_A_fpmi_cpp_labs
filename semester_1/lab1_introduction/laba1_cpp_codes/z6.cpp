#include <iostream>

/*
��������� ����� ������ n �������� �����.
���������� ����� n �������� � ����������.
*/

int main()
{
    using std::cin;
    using std::cout;
    int n, sum = 0;
    cout << "enter the n: ";
    if(!(cin >> n) || n < 1) {
        cout << "ERROR!!!";
        std::exit(1);
    }
    for (int i = 1; i <= n; i += 2)
        sum += i;

    cout << "sum is " << sum;

    return 0;
}
