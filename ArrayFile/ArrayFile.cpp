﻿ // ArrayFile.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <ios>
#include <vector>

#include <time.h>

using namespace std;

typedef double* pDouble;
/*
*   ConsoleInputArrayDouble
*   
*/
int ConsoleInputSizeArray(const int sizeMax)
{
    int size = 0; 
    do {
        cout << " Input size Array ( 0< 1 < " << sizeMax << " ) ";
        cin >> size;
    } while (size <= 0 || size >= sizeMax);
    return size;
}
/*
*   ConsoleInputArrayDouble
*
*/
int ConsoleInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
        for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> A[i];
    }
    return size;
}

/*
*   RndInputArrayDouble
*
*/
int RndInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    int r1=0, r2=0;
    srand(size);

    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        A[i] = 100.0 * r1;
        A[i] = A[i] / (1.0 + r2);
        cout << A[i] << "   ";
    }
    return size;
}

int ConsoleInputDynamicArrayNew(int sizeMax, pDouble &pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = new double[size];
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

int ConsoleInputDynamicArray_calloc(int sizeMax, pDouble& pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = (double*)calloc(size, sizeof(double));      // pA = (double*)malloc(size * sizeof(double)); 
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

void ConsoleInputVector(int sizeMax, vector<double> &A)
{
    int size = ConsoleInputSizeArray(sizeMax);
    double d;
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> d; A.push_back(d);
    }
    return ;
}


/*
*  WriteArrayTextFile 
*
*/

void WriteArrayTextFile(int n, double *arr, const char *fileName )
{
    ofstream fout(fileName);
    if (fout.fail()) return;
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << "   ";
    fout.close(); //
}
/*
*  ReadArrayTextFile
*
*/


int ReadArrayTextFile(int n, double* arr, const char* fileName)
{
    int size;
    ifstream fin(fileName);
    if (fin.fail()) return 0;
    fin >> size;
    if (size <= 0) return 0;
    if (size > n) size = n;   
    for (int i = 0; i < n; i++)
       fin>> arr[i];
    fin.close();
    return size;
    
}


void WriteArrayBinFile(int n, double* arr, const char* fileName)
{
    //ios_base
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&n, sizeof(int));
    std::streamsize  cn = static_cast<std::streamsize>(n) *sizeof(double);
    bfout.write((const char*)arr, cn);
    bfout.close();
}

int ReadArrayBinFile(int n, double* arr, const char* fileName)
{
    int size=0;
    ifstream bfin(fileName, ios_base::binary);
    if (bfin.fail()) return 0;
    bfin.read((char*)&size, sizeof(int));
    if (size <= 0) return 0;
    if (size > n) size = n;
    bfin.read((char*)arr, static_cast<std::streamsize>(size) * sizeof(double));
    bfin.close();
    // ssdhs
    return size;
}

void ShowMainMenu()
{
    cout << "    Main Menu  \n";
    cout << "    1.  Task 1  \n";
    cout << "    2.  Task 2  \n";
    cout << "    3.  Task 3  \n";
    cout << "    4.  Leave the Program\n";
  }

void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Local array  \n";
    cout << "    2.  Dynamic array 1 \n";
    cout << "    3.  Dynamic array 2  new \n"; 
    cout << "    4.  Dynamic array : vector \n";
    cout << "    5.  Exit \n";
}

void MenuInput()
{
    cout << "     Menu Input   \n";
    cout << "    1.  Console all \n";
    cout << "    2.  Console - size, array - random \n";
    cout << "    3.  File 1.txt \n";
    cout << "    4.  bb    \n";
    cout << "    5.  Exit \n";
}


/*
* Задано одновимірний масив А розміру 2N. 
* Побудувати два масиви В і С розміру N, 
* включивши  у масив В елементи масиву А з парними індексами,
* а у С - з непарними.
*****************
*  A - in 
*  B, C - out 
*/
void  TestVariant(int N, double* A, double* B, double* C) {
    for (int i = 0; i < N; i++) {
        B[i] = A[2 * i];
        C[i] = A[2 * i + 1];
    }
}
/*
*  Task  Var
* 
* 
*/
void TaskV()
{
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
            switch (ch) {
             case '1': cout << " 1 "; break;
             case '2': cout << " 2 "; break;
            //
            case '5': return;
            }
        cout << " Press any key and enter\n";
        ch = getchar();
        } while (ch != 27);
    
}

void ArrayLocal()
{
    double A[1000], B[500], C[500];
    int n;
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
        switch (ch) {
        case '1': cout << " 1 "; break;
        case '2': cout << " 2 "; break;
            //
        case '5': return;
        }
        cout << " Press any key and enter\n";
        ch = getchar();
    } while (ch != 27);

}

void Task1() {

    // Task #1
    int N;
    std::cout << "Enter the size of the arrays: ";
    std::cin >> N;

    int* A = new int[N];
    int* B = new int[N];
    int* C = new int[N];

    // Введення данних масивів

    std::cout << "Enter elements of array A: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    std::cout << "Enter elements of array B: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i];
    }

    // Обрахування масиву С
    for (int i = 0; i < N; ++i) {
        C[i] = A[i] * B[i];
    }

    // Виведення новоствореного масиву С
    std::cout << "Array C (A * B): ";
    for (int i = 0; i < N; ++i) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    delete[] A;
    delete[] B;
    delete[] C;
}

int FindMaxBeforeFirstOdd(int* arr, int size) {
    int max = arr[0];
    for (int i = 2; i < size; i += 2) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i - 1] % 2 != 0) {
            break;
        }
    }
    return max; // Повернення максимального знайдене значення
}

void Task2() {
    int N;

    // Введення розміру масиву
    cout << "Enter the size of the array: ";
    cin >> N;

    int* array = new int[N];

    // Введенння значень одновимірного масиву
    cout << "Enter elements of the array: ";
    for (int i = 0; i < N; ++i) {
        cin >> array[i];
    }

    // Знаходження максимального елемента серед парних (за значенням) елементів, розташованих до першого непарного елемента.
    int maxBeforeFirstOdd = FindMaxBeforeFirstOdd(array, N);

    // Виведення результату
    cout << "Maximum element among pairs before the first odd element: " << maxBeforeFirstOdd << endl;

    delete[] array;
}
}

void Task3() {
    int n;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Create arrays A and B
    vector<int> A(n);
    vector<int> B;

    // Input elements of array A
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Calculate and add elements to array B
    for (int i = 0; i < n; ++i) {
        // Calculate the discriminant
        int discriminant = 9 * A[i] * A[i] - 20;
        if (discriminant >= 0) { // Discriminant is non-negative
            // Calculate the roots
            double root1 = (-3 * A[i] + sqrt(discriminant)) / 2;
            double root2 = (-3 * A[i] - sqrt(discriminant)) / 2;
            if (root1 > 0 && floor(root1) == root1) { // Check if root1 is positive and integer
                B.push_back(A[i]);
            }
            if (root2 > 0 && floor(root2) == root2 && root2 != root1) { // Check if root2 is positive, integer, and distinct from root1
                B.push_back(A[i]);
            }
        }
    }

    // Output array B with five numbers in a row
    cout << "Array B with elements whose roots of the equation are real and positive: ";
    for (int i = 0; i < B.size(); ++i) {
        cout << B[i] << " ";
        if ((i + 1) % 5 == 0) { // Print a newline after every five elements
            cout << endl;
        }
    }
    cout << endl;
}

int main()
{ 
    char choice;
    do {
        ShowMainMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case '1':
            Task1();
            break;
        case '2':
            Task2();
            break;
        case '3':
            Task3();
            break;
        case '4':
            cout << "Leaving the program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (true);
    
    
    



    /*
    double A[MAX_SIZE], B[MAX_SIZE],C[MAX_SIZE];
    int n,m;
    n = RndInputArray(MAX_SIZE, A);
    WriteArrayTextFile(n, A, "1.txt");
    m = ReadArrayTextFile(MAX_SIZE, B, "1.txt");
    cout << " \n m= " << m << endl;
    for (int i = 0; i < m; i++)
        cout << B[i] << "   ";
    WriteArrayBinFile(n, A, "1.bin");
    m = ReadArrayBinFile(MAX_SIZE, C, "1.bin");
    cout << " \n m= " << m << endl;
    for (int i = 0; i < m; i++)
        cout << C[i] << "   ";
    cout << "\n  Vector \n";
    vector<double> vA;
    ConsoleInputVector(MAX_SIZE, vA);
    for (auto v : vA) {
        cout << v << "   ";
    }
    */

    TaskV();
    return 1;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
