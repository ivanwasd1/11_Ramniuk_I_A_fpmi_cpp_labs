#include <iostream>

using namespace std;

/*
С клавиатуры вводится натуральное десятичное число.
Написать программу, которая конвертирует данное число
в двоичную и шестнадцатеричную системы счисления.
*/

void write_bin_num (int t) {

    if (t == 0)
        return;

    write_bin_num(t / 2);
    cout << t % 2;

}

void write_hex_num (int t) {

    if (t == 0)
        return;

    write_hex_num(t / 16);
    if (t % 16 <= 9)
        cout << t % 16;
    else
        cout << char('A' + t % 16 - 10);
}

int main()
{
    int n;
    cin >> n;
    cout << "bin number is ";
    write_bin_num(n);
    cout << '\n';
    cout << "hex number is ";
    write_hex_num(n);
}
