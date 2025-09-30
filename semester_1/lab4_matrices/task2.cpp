#include <iostream>
#include <random>

const int MAX_SIZE_matrix = 500;

void PrintOfMatrix (int matrix[MAX_SIZE_matrix][MAX_SIZE_matrix], int n) {

    std::cout << "elements of array:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout.width(5);
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';

}

void ReplaceZeroLinesOfArray(int matrix[MAX_SIZE_matrix][MAX_SIZE_matrix], int n) {

    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0) {
            std::swap(matrix[0], matrix[i]);
            break;
        }
    }
    return;

}

int SerchMaxElementOfTopRightTriangle (int matrix[MAX_SIZE_matrix][MAX_SIZE_matrix], int n) {

    int mx = matrix[0][1];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            mx = std::max(mx, matrix[i][j]);

    return mx;
}

int main()
{
    using std::cin;
    using std::cout;

    cout << "enter 0 if you want that matrixay consists of random numbers\nelse enter 1 to get matrixay consists of entered numbers\n";
    bool flag;
    if (!(cin >> flag)) {
        cout << "ERROR!!!";
        std::exit(1);
    }

    cout << "enter the size of matrix[n*n] (n from 1 to 500): ";
    int n;
    if (!(cin >> n) || n < 1 || n > MAX_SIZE_matrix) {
        cout << "ERROR!!!";
        std::exit(1);
    }

    int matrix[MAX_SIZE_matrix][MAX_SIZE_matrix];

    if (flag) {

        cout << "enter n*n elements of matrix:\n";

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!(cin >> matrix[i][j])) {
                    cout << "ERROR!!!";
                    std::exit(1);
                }
    }
    else {

        cout << "enter right and left border of your random numbers: ";
        int right_border, left_border;
        if (!(cin >> left_border) || !(cin >> right_border)) {
            cout << "ERROR!!!";
            std::exit(1);
        }

        if (left_border > right_border)
            std::swap(left_border, right_border);

        std::mt19937 gen(2345);
        std::uniform_int_distribution<int> dist(left_border, right_border);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matrix[i][j] = dist(gen);

        cout << "elements of an matrixay filled with random numbers from " <<  left_border << " to " << right_border << " :\n";

    }

    PrintOfMatrix(matrix, n);

    ReplaceZeroLinesOfArray(matrix, n);

    cout << "Replaced!\n\n";
    PrintOfMatrix(matrix, n);

    int max_element_of_TopRight_triangle = SerchMaxElementOfTopRightTriangle(matrix, n);

    cout << "max element of TopRight triangle is " << max_element_of_TopRight_triangle << '\n';

    return 0;
}
