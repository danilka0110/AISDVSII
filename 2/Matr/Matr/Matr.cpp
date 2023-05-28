#include <string>
#include <iostream> 
#include <ctime> 
#include <chrono>

using namespace std;

int N = 4096;

void multiply(int** A, int** B, int** result)
{
    int i, j, k;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            result[i][j] = 0;
            for (k = 0; k < N; k++)
                result[i][j] += A[i][k] * B[k][j];
        }
    }

    /*
    
    cout << endl << "Результат умножения матриц A x B: " << endl << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }

    */
}


int main()
{
    setlocale(LC_ALL, "RUS");

    srand(time(NULL));

    int** MatrA = new int* [N];
    int** MatrB = new int* [N];
    int** result = new int* [N];

    for (int j = 0; j < N; j++) {
        MatrA[j] = new int[N];
        MatrB[j] = new int[N];
        result[j] = new int[N];
        for (int k = 0; k < N; k++) {
            MatrA[j][k] = rand() % 100;
            MatrB[j][k] = rand() % 100;
        }
    }

    /*
    
    cout << "Матрица A (" << N << "x" << N << "): " << endl << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << MatrA[i][j] << " ";
        cout << endl;
    }

    cout << endl;

    cout << "Матрица B (" << N << "x" << N << "): " << endl << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << MatrB[i][j] << " ";
        cout << endl;
    }

    */

    auto begin = chrono::steady_clock::now();

    multiply(MatrA, MatrB, result);

    auto end = chrono::steady_clock::now();

    auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);


    cout << "\nВремя выполнения: " << elapsed_ms.count() << " ns\n";
}