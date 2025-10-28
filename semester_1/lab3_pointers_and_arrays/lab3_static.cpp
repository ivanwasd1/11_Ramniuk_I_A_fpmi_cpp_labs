#include <iostream>
#include <random>

const int MAX_SIZE_ARR = 50002;

void read_arr(int* arr, int sizeArr) {

    std::cout << "enter n elements of array (elements must be from 1 to 100000):\n";

    if (!(std::cin >> arr[0]) || arr[0] < 1 || arr[0] > MAX_SIZE_ARR - 2) {
        std::cout << "ERROR!!!";
        std::exit(1);
    }

    for (int i = 1; i < sizeArr; i++) {
        if (!(std::cin >> arr[i]) || arr[i] < 1 || arr[i] > sizeArr) {
            std::cout << "ERROR!!!";
            std::exit(1);
        }
    }
}

void fill_rand(int* arr, int sizeArr) {

    std::cout << "enter the right border of your random numbers(sizeArr or less then your sizeArr): ";
    int right_border;
    if (!(std::cin >> right_border) || right_border < 1 || right_border > MAX_SIZE_ARR - 2) {
        std::cout << "ERROR!!!";
        std::exit(1);
    }

    std::mt19937 gen(345798);
    std::uniform_int_distribution<int> dist(1, std::min(right_border, sizeArr));

    for (int i = 0; i < sizeArr; i++)
        arr[i] = dist(gen);

    std::cout << "elements of an array filled with random numbers from 1 to " << right_border << " :\n";

    for (int i = 0; i < sizeArr; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

void find_max_elements(int* arr, int sizeArr) {
    int mx = arr[0];
    for (int i = 1; i < sizeArr; i++)
        if (arr[i] > mx)
            mx = arr[i];

    std::cout << "the numbers of all maximum elements of the array:\n";
    for (int i = 0; i < sizeArr; i++)
        if (arr[i] == mx)
            std::cout << i + 1 << ' ';
    std::cout << "\n\n";
}

void find_min_missing_number(int* arr, int sizeArr) {

    for (int i = 0; i < sizeArr; i++)
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] *= -1;

    int min_number = sizeArr + 1;
    for (int i = 0; i <= sizeArr; i++)
        if (arr[i] > 0) {
            min_number = i + 1;
            break;
        }

    for (int i = 0; i < sizeArr; i++)
        arr[i] = abs(arr[i]);

    std::cout << "the minimum number that is not in the array is " << min_number << "\n\n";
}

void transform_array(int* arr, int sizeArr) {

    std::cout << "enter the number that will be used to convert the array: ";
    int k;
    if (!(std::cin >> k) || k < 1 || k > MAX_SIZE_ARR - 2) {
        std::cout << "ERROR!!!";
        std::exit(1);
    }
    int j = 0;
    for (int i = 0; i < sizeArr; i++) {
        if (arr[i] > k) {
            std::swap(arr[i], arr[j]);
            j++;
        }
    }
}

void print_array(int* arr, int sizeArr) {

    std::cout << "Your new array:\n";
    for (int i = 0; i < sizeArr; i++)
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
    int sizeArr;
    if (!(cin >> sizeArr) || sizeArr < 1 || sizeArr > MAX_SIZE_ARR - 2) {
        cout << "ERROR!!!";
        std::exit(1);
    }

    int arr[MAX_SIZE_ARR];

    if (flag)
        read_arr(arr, sizeArr);
    else
        fill_rand(arr, sizeArr);

    find_max_elements(arr, sizeArr);

    find_min_missing_number(arr, sizeArr);

    transform_array(arr, sizeArr);

    print_array(arr, sizeArr);

    return 0;
}
