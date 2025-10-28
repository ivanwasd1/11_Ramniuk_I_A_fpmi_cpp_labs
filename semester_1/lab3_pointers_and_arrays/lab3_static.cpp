#include <iostream>
#include <random>

const int MAX_SIZE_ARR = 50002;

void read_arr(int* arr, int n) {
    std::cout << "enter n elements of array (elements must be from 1 to 100000):\n";

    if (!(std::cin >> arr[0]) || arr[0] < 1 || arr[0] > MAX_SIZE_ARR - 2) {
        std::cout << "ERROR!!!";
        std::exit(1);
    }

    for (int i = 1; i < n; i++) {
        if (!(std::cin >> arr[i]) || arr[i] < 1 || arr[i] > MAX_SIZE_ARR - 2) {
            std::cout << "ERROR!!!";
            std::exit(1);
        }
    }
}

void fill_rand(int* arr, int n) {
    std::cout << "enter the right border of your random numbers: ";
    int right_border;
    if (!(std::cin >> right_border) || right_border < 1 || right_border > MAX_SIZE_ARR - 2) {
        std::cout << "ERROR!!!";
        std::exit(1);
    }

    std::mt19937 gen(345798);
    std::uniform_int_distribution<int> dist(1, right_border);

    for (int i = 0; i < n; i++)
        arr[i] = dist(gen);

    std::cout << "elements of an array filled with random numbers from 1 to " << right_border << " :\n";

    for (int i = 0; i < n; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

void find_max_elements(int* arr, int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];

    std::cout << "the numbers of all maximum elements of the array:\n";
    for (int i = 0; i < n; i++)
        if (arr[i] == mx)
            std::cout << i + 1 << ' ';
    std::cout << "\n\n";
}

int find_min_missing_number(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        int val = abs(arr[i]);
        if (val <= n && val > 0) {
            arr[val - 1] = -abs(arr[val - 1]);
        }
    }

    int min_number = n + 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            min_number = i + 1;
            break;
        }
    }

    for (int i = 0; i < n; i++)
        arr[i] = abs(arr[i]);

    std::cout << "the minimum number that is not in the array is " << min_number << "\n\n";
    return min_number;
}

void transform_array(int* arr, int n, int k) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > k) {
            for (int m = i; m > j; m--) {
                std::swap(arr[m], arr[m - 1]);
            }
            j++;
        }
    }
}

void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

int main() {
    using std::cin;
    using std::cout;

    cout << "enter 0 if you want that array consists of random numbers\nelse enter 1 to get array consists of entered numbers\n";
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

    if (flag)
        read_arr(arr, n);
    else
        fill_rand(arr, n);

    find_max_elements(arr, n);
    find_min_missing_number(arr, n);

    cout << "enter the number that will be used to convert the array: ";
    int k;
    if (!(cin >> k) || k < 1 || k > MAX_SIZE_ARR - 2) {
        cout << "ERROR!!!";
        std::exit(1);
    }

    transform_array(arr, n, k);

    cout << "Your new array:\n";
    print_array(arr, n);

    return 0;
}
