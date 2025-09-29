#include <iostream>
#include <random>

const int MAX_SIZE_ARR = 50002;

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
    if (!(cin >> n) || n < 1 || n > MAX_SIZE_ARR - 2) {
        cout << "ERROR!!!";
        std::exit(1);
    }



    int arr[MAX_SIZE_ARR];

    if (flag) {

        cout << "enter n elements of array (elements must be from 1 to 100000):\n";

        if (!(cin >> arr[0]) || arr[0] < 1 || arr[0] > MAX_SIZE_ARR - 2) {
            cout << "ERROR!!!";
            std::exit(1);
        }

        int mx = arr[0];

        for (int i = 1; i < n; i++) {

            if (!(cin >> arr[i]) || arr[i] < 1 || arr[i] > MAX_SIZE_ARR - 2) {
                cout << "ERROR!!!";
                std::exit(1);
            }
            if (arr[i] > mx)
                mx = arr[i];

        }
        cout << "the numbers of all maximum elements of the array:\n";
        for (int i = 0; i < n; i++)
            if (arr[i] == mx)
                cout << i + 1 << ' ';

        cout << '\n';
    }
    else {

        cout << "enter the right border of your random numbers: ";
        int right_border;
        if (!(cin >> right_border) || right_border < 1 || right_border > MAX_SIZE_ARR - 2) {
            cout << "ERROR!!!";
            std::exit(1);
        }

        std::mt19937 gen(345798);
        std::uniform_int_distribution<int> dist(1, right_border);

        for (int i = 0; i < n; i++)
            arr[i] = dist(gen);

        cout << "elements of an array filled with random numbers from 1 to " << right_border << " :\n";

        for (int i = 0; i < n; i++)
            cout << arr[i] << ' ';

        cout << '\n';

        int mx = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > mx)
                mx = arr[i];

        cout << "the numbers of all maximum elements of the array:\n";
        for (int i = 0; i < n; i++)
            if (arr[i] == mx)
                cout << i + 1 << ' ';


    }
    cout << "\n\n";

    int min_number_insnt_in_arr = 0;
    for (int i = 0; i < n; i++)
        arr[arr[i] - 1] *= -1;
    for (int i = 0; i < n + 1; i++)
        if (arr[i] > 0) {
            min_number_insnt_in_arr = i + 1;
            break;
        }

    for (int i = 0; i < n; i++)
        arr[i] = abs(arr[i]);

    cout << "the minimum number that is not in the array is " << min_number_insnt_in_arr << "\n\n";

    cout << "enter the number that will be used to convert the array: ";
    int k;
    if (!(cin >> k) || k < 1 || k > MAX_SIZE_ARR - 2) {
        cout << "ERROR!!!";
        std::exit(1);
    }

    int j = n;

    for (int i = 0; i < n; i++)
        if (arr[i] > k)
            arr[j++] = arr[i];

    for (int i = 0; i < n; i++)
        if (arr[i] <= k)
            arr[j++] = arr[i];

    for (int i = 0; i < n; i++)
        arr[i] = arr[i + n], arr[i + n] = 0;


    cout << "Your new array:\n";



    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';


    return 0;
}
