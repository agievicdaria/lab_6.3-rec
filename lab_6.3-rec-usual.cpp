#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int sumOfSquares(int arr[], int size, int index = 0) {
    if (index >= size) {
        return 0;
    }
    return arr[index] * arr[index] + sumOfSquares(arr, size, index + 1);
}

void printArray(int arr[], int size, int index = 0) {
    if (index >= size) {
        cout << endl;
        return;
    }
    cout << arr[index] << " ";
    printArray(arr, size, index + 1);
}

void generateArray(int arr[], int size, int lower, int upper, int i) {
    arr[i] = lower + rand() % (upper - lower + 1);
    if (i < size - 1) {
        generateArray(arr, size, lower, upper, i + 1);
    }
}

int main() {
    srand((unsigned)time(NULL)); 

    int size, min, max;

    cout << "Введіть розмір масиву: "; cin >> size;
    cout << "Введіть мінімальне значення масиву: "; cin >> min;
    cout << "Введіть максимальне значення масиву: "; cin >> max;

    int a[size];

    generateArray(a, size, min, max, 0);

    cout << "Згенерований масив: ";
    printArray(a, size);

    int sum = sumOfSquares(a, size);
    cout << "Сума квадратів елементів масиву: " << sum << endl;

    return 0;
}