#include <iostream>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

const int n = 100000;

// ------------------------------ Сортировка вставкой ------------------------------ \\


void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


// ------------------------------ Сортировка слиянием ------------------------------ \\


void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int* L = new int[n1];
    int* R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


// ------------------------------ Сортировка подсчетом ------------------------------ \\


void countingSort(int arr[], int n) {
    const int k = 200000;
    int count[k] = { 0 };

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i < k;

        i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[index] = i;
            index++;
        }
    }
}


// ------------------------------ Сортировка выбором ------------------------------ \\


void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}


// ---------------------------------- Быстрая сортировка ---------------------------------- \\


int partition(int* arr, int start, int end)
{
    int pivot = arr[end];

    int pIndex = start;

    for (int i = start; i < end; i++) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }

    swap(arr[pIndex], arr[end]);

    return pIndex;
}

void quicksort(int a[], int start, int end)
{
    if (start >= end) {
        return;
    }

    int pivot = partition(a, start, end);

    quicksort(a, start, pivot - 1);

    quicksort(a, pivot + 1, end);
}

void printArr(int* arr) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}






// ------------------------------ Main ------------------------------ \\






int main() {

    setlocale(LC_ALL, "Russian");

    // -------------------------- Сортировка вставкой -------------------------- \\

    /*

    int arr[n];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 300000);

    for (int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }

    auto start = high_resolution_clock::now();

    insertionSort(arr, n);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Отсортированный массив: ";

    for (int i = 0; i < n; i++) {
         cout << arr[i] << " ";
    }

    cout << "\nВремени потрачено: " << duration.count() << " ns" << endl;

    return 0;


    */

    // -------------------------- Сортировка слиянием -------------------------- \\
    
    /*

    int arr[n];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 300000);

    for (int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }

    auto start = high_resolution_clock::now();

    mergeSort(arr, 0, n - 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    //cout << "Отсортированный массив: ";

    //for (int i = 0; i < n; i++) {
    //    cout << arr[i] << " ";
    //}

    cout << "\nВремени потрачено: " << duration.count() << " ns" << endl;

    return 0;


    // -------------------------- Сортировка подсчетом -------------------------- \\

    */

    /*

   

    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 200000;
    }

    auto start = steady_clock::now();

    countingSort(arr, n);

    auto end = steady_clock::now();

    auto duration = duration_cast<nanoseconds>(end - start);


    //cout << "Отсортированный массив: ";

    //for (int i = 0; i < n; i++) {
    //    cout << arr[i] << " ";
    //}


    cout << "Времени потрачено: " << duration.count() << " ns." << endl;

    return 0;


    // -------------------------- Сортировка выбором -------------------------- \\


    */

    /*
   
    

    int arr[n];

    // заполнение массива случайными числами
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }

    auto start = steady_clock::now();

    selectionSort(arr, n);

    auto end = steady_clock::now();

    auto duration = duration_cast<nanoseconds>(end - start);

    //cout << "Отсортированный массив: ";

    //for (int i = 0; i < n; i++) {
    //    cout << arr[i] << " ";
    //}

    cout << "Времени потрачено: " << duration.count() << " ns." << endl;

    return 0;


    // -------------------------- Быстрая сортировка -------------------------- \\

    */
    
    /*
    
    
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }

    int N = sizeof(arr) / sizeof(arr[0]);

    auto start = std::chrono::steady_clock::now();

    quicksort(arr, 0, N-1);

    auto end = std::chrono::steady_clock::now();

    nanoseconds duration = duration_cast<nanoseconds>(end - start);

    //for (int i = 0; i < n; i++) {
    //    cout << arr[i] << " ";
    //}

    cout << "\nВремени потрачено: " << duration.count() << " ns." << endl;

    return 0;
    
    */

}