#include <iostream>
using namespace std;

template <typename T>
T sumOfSquares(T arr[], int size) {
    if (size <= 0) {
        return 0;
    }
    return arr[size - 1] * arr[size - 1] + sumOfSquares(arr, size - 1);
}

template <typename T>
void printArray(T arr[], int size) {
    if (size <= 0) {
        cout << endl;
        return;
    }
    printArray(arr, size - 1);
    cout << arr[size - 1] << " ";
}

template <typename T>
void inputArray(T arr[], int size, int index = 0) {
    if (index >= size) {
        return;
    }
    cout << "Введіть елемент " << index + 1 << ": ";
    cin >> arr[index];
    inputArray(arr, size, index + 1);
}

int main() {
    int size;
    cout << "Введіть розмір масиву: "; cin >> size;

    double a[size];
    cout << "Введіть числа:" << endl;
    inputArray(a, size);

    cout << "Початковий масив чисел: ";
    printArray(a, size);

    double sum = sumOfSquares(a, size);
    cout << "Сума квадратів елементів масиву: " << sum << endl;

    return 0;
}
