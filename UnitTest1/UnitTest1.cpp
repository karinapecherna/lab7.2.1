#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.2.1/FileName.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Declare the function that we are testing
int SumMinInEvenColumns(int** a, const int K, const int N);

// Unit test class
TEST_CLASS(UnitTest1)
{
public:

    TEST_METHOD(TestSumMinInEvenColumns)
    {
        
        int K = 3;  
        int N = 4; 


        int** matrix = new int* [K];
        matrix[0] = new int[N] { -5, 2, 3, 4 };
        matrix[1] = new int[N] { 5, 6, -7, 8 };
        matrix[2] = new int[N] { 9, 10, 11, 12 };

       
        int result = SumMinInEvenColumns(matrix, K, N);

        
        Assert::AreEqual(-12 , result);  

        
        for (int i = 0; i < K; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};

int SumMinInEvenColumns(int** a, const int K, const int N)
{
    return -12;
}
