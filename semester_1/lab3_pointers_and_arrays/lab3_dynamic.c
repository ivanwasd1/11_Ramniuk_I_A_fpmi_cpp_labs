#include <iostream>
#include <random>

const int MAX_SIZE_ARR = 100000;

int main() {

    using std::cin;
    using std::cout;

    cout << "enter 0 if you want that array consists of random numbers([1, 100])\nelse enter 1 to get array consists of entered numbers\n";
    bool flag;
    if (!(cin >> flag)) {
        cout << "ERROR!!!";
        std::exit(1);
    }

    cout << "enter the size of array (size must be from 1 to 100000) n: ";
    int n;
    if (!(cin >> n) || n < 1 || n > MAX_SIZE_ARR) {
        cout << "ERROR!!!";
        std::exit(1);
    }

    double* arr = new double[n];

    if (flag) {

        cout << "enter n elements of array (elements must be from 1 to 100000):\n";

        for (int i = 0; i < n; i++)
            if (!(cin >> arr[i])) {
                cout << "ERROR!!!";
                delete[] arr;
                std::exit(1);
            }
    }
    else {

        cout << "enter right and left border of your random numbers: ";
        double right_border, left_border;
        if (!(cin >> left_border) || !(cin >> right_border)) {
            cout << "ERROR!!!";
            delete[] arr;
            std::exit(1);
        }

        if (left_border > right_border)
            std::swap(left_border, right_border);

        std::mt19937 gen(345798);
        std::uniform_real_distribution<double> dist(left_border, right_border);

        for (int i = 0; i < n; i++)
            arr[i] = dist(gen);

        cout << "elements of an array filled with random numbers from " <<  left_border << "to " << right_border << " :\n";

        for (int i = 0; i < n; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }

    int now_left = 0, now_right = 0, best_left = 0, best_right = 0;
    double now_sum = arr[0], best_sum = arr[0];

    for (int i = 1; i < n; i++) {

        if (now_sum > 0) {
            now_sum += arr[i];
            now_right = i;
        }
        else {
            now_sum = arr[i];
            now_left = i, now_right = i;
        }

        if (now_sum > best_sum) {
            best_sum = now_sum;
            best_left = now_left;
            best_right = now_right;
        }

    }

    cout << "the chain of elements having the largest sum:\n";
    for (int i = best_left; i <= best_right; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    double sum_after_zero = 0;

    bool flag_of_zero = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 0)
            flag_of_zero = 1;
        sum_after_zero += arr[i];
    }

    if (flag_of_zero) {
        cout << "the sum of the array elements located after the last element is zero:  ";
        cout << sum_after_zero << '\n';
    }
    else
        cout << "there is not element zero\n";

    double* temp = new double[n];
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (int(arr[i]) <= 1) {
            temp[j++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (int(arr[i]) > 1) {
            temp[j++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    delete[] temp;

    cout << "Your new array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    delete[] arr;

    return 0;
}
