#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int K, const int N, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, N, Low, High, 0);
    if (rowNo < K - 1)
        CreateRows(a, K, N, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int K, const int N, int rowNo)
{
    PrintRow(a, rowNo, N, 0);
    if (rowNo < K - 1)
        PrintRows(a, K, N, rowNo + 1);
    else
        cout << endl;
}


void FindMinInEvenCol(int** a, const int K, int colNo, int rowNo, int& minVal)
{
    if (rowNo < K) {
        if (a[rowNo][colNo] < minVal)
            minVal = a[rowNo][colNo];
        FindMinInEvenCol(a, K, colNo, rowNo + 1, minVal);
    }
}


int SumMinInEvenColumns(int** a, const int K, const int N, int colNo)
{
    if (colNo >= N) {
        return 0;  
    }

    int minVal = a[0][colNo];  
    FindMinInEvenCol(a, K, colNo, 1, minVal);  

    
    return minVal + SumMinInEvenColumns(a, K, N, colNo + 2);  
}

int main()
{
    srand((unsigned)time(NULL));
    int K, N;
    cout << "K (rows) = "; cin >> K;
    cout << "N (columns) = "; cin >> N;
    cout << endl;

    
    int** a = new int* [K];
    for (int i = 0; i < K; i++)
        a[i] = new int[N];

    int Low = -9, High = 9;
    CreateRows(a, K, N, Low, High, 0);  
    PrintRows(a, K, N, 0);  

   
    int sumMin = SumMinInEvenColumns(a, K, N, 0); 
    cout << "Sum of minimums in even columns = " << sumMin << endl;

    
    for (int i = 0; i < K; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
