#include <iostream>

using namespace std;

// Функція для заміни всіх елементів E1 на E2
void replaceElements(int arr[], int size, int E1, int E2) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == E1) arr[i] = E2;
    }
}

// Функція для видалення від’ємних елементів між мінімальним і максимальним
void removeNegativeBetweenMinMax(int arr[], int& size) {
    if (size == 0) return;

    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) minIndex = i;
        if (arr[i] > arr[maxIndex]) maxIndex = i;
    }

    if (minIndex > maxIndex) swap(minIndex, maxIndex);

    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (i > minIndex && i < maxIndex && arr[i] < 0) continue;
        arr[newSize++] = arr[i];
    }
    size = newSize;
}

// Функція для впорядкування масиву методом бульбашки
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

// Функція для об'єднання двох впорядкованих списків
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[], int& mergedSize) {
    int i = 0, j = 0, k = 0;
    
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    
    while (i < size1) merged[k++] = arr1[i++];
    while (j < size2) merged[k++] = arr2[j++];
    
    mergedSize = k;
}

// Функція для виведення масиву
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size1;
    cout << "Введіть кількість елементів у ПЕРШОМУ масиві: ";
    cin >> size1;

    int arr1[100];  
    cout << "Введіть " << size1 << " елементів: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cout << "Початковий ПЕРШИЙ масив: ";
    printArray(arr1, size1);

    int E1, E2;
    cout << "Введіть E1 (що замінити) та E2 (на що замінити): ";
    cin >> E1 >> E2;
    replaceElements(arr1, size1, E1, E2);
    cout << "Після заміни у ПЕРШОМУ списку: ";
    printArray(arr1, size1);

    removeNegativeBetweenMinMax(arr1, size1);
    cout << "Після видалення від’ємних між min і max у ПЕРШОМУ списку: ";
    printArray(arr1, size1);

    bubbleSort(arr1, size1);
    cout << "Відсортований ПЕРШИЙ масив: ";
    printArray(arr1, size1);

    // Введення другого масиву
    int size2;
    cout << "Введіть кількість елементів у ДРУГОМУ списку: ";
    cin >> size2;

    int arr2[100];  
    cout << "Введіть " << size2 << " елементів: ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    cout << "Початковий ДРУГИЙ список: ";
    printArray(arr2, size2);

    bubbleSort(arr2, size2);
    cout << "Відсортований ДРУГИЙ список: ";
    printArray(arr2, size2);

    // Об'єднання двох відсортованих масивів
    int merged[200], mergedSize;
    mergeArrays(arr1, size1, arr2, size2, merged, mergedSize);

    cout << "Об'єднаний відсортований список: ";
    printArray(merged, mergedSize);

    return 0;
}