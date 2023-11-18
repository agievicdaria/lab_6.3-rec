#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
T sumOfSquaresTmpl(T arr[], int size) {
    if (size <= 0) {
        return 0;
    }
    return arr[size - 1] * arr[size - 1] + sumOfSquaresTmpl(arr, size - 1);
}

template <typename T>
void printArrayTmpl(T arr[], int size) {
    if (size <= 0) {
        cout << endl;
        return;
    }
    printArrayTmpl(arr, size - 1);
    cout << arr[size - 1] << " ";
}

template <typename T>
void generateArrayTmpl(T* a, const int size, T Low,  T High, int i) {
    a[i] = Low + rand() % (High-Low+1);
    if (i<size-1) {
        generateArrayTmpl(a, size, Low, High, i+1);
    }
}

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
    generateArrayTmpl(a, size, min, max, 0);

    cout << "Згенерований 1 масив: "; cout << endl;
    printArray(a, size);
    cout << "Згенерований 2 масив: ";
    printArrayTmpl(a, size); cout << endl;

    int sum = sumOfSquares(a, size);
    cout << "Сума квадратів елементів 1 масиву: " << sum << endl;
    int sumTmpl = sumOfSquaresTmpl(a, size);
    cout << "Сума квадратів елементів 2 масиву: " << sumTmpl << endl;

    return 0;
}