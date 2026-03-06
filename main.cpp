#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 20;

/* ================= ФУНКЦІЇ ДЛЯ МАСИВУ ================= */

void readArray(string filename, double arr[], int &n)
{
    ifstream fin(filename);

    if (!fin)
    {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }

    fin >> n;

    for (int i = 0; i < n; i++)
        fin >> arr[i];

    fin.close();
}

void writeArray(string filename, double arr[], int n)
{
    ofstream fout(filename, ios::app);

    fout << "\nМасив:\n";

    for (int i = 0; i < n; i++)
        fout << arr[i] << " ";

    fout << endl;

    fout.close();
}

/* ================= ЗАВДАННЯ 1 ================= */

void deleteK(double arr[], int &n, int k)
{
    for (int i = k - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;
}

/* ================= СОРТУВАННЯ ================= */

void insertionSort(double arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        double key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

/* ================= ФУНКЦІЇ ДЛЯ МАТРИЦІ ================= */

void readMatrix(string filename, double matrix[MAX][MAX], int &m, int &n)
{
    ifstream fin(filename);

    if (!fin)
    {
        cout << "Помилка відкриття файлу!" << endl;
        return;
    }

    fin >> m >> n;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            fin >> matrix[i][j];

    fin.close();
}

void writeMatrix(string filename, double matrix[MAX][MAX], int m, int n)
{
    ofstream fout(filename, ios::app);

    fout << "\nМатриця:\n";

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            fout << matrix[i][j] << " ";
        fout << endl;
    }

    fout.close();
}

/* ================= ЗАВДАННЯ 2 ================= */

int countIncreasingRows(double matrix[MAX][MAX], int m, int n)
{
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        bool increasing = true;

        for (int j = 0; j < n - 1; j++)
        {
            if (matrix[i][j] > matrix[i][j + 1])
            {
                increasing = false;
                break;
            }
        }

        if (increasing)
            count++;
    }

    return count;
}

/* ================= ФУНКЦІЇ ЗАВДАНЬ ================= */

void task1()
{
    double arr[MAX];
    int n, k;
    string arrayFileIn, arrayFileOut;

    cout << "Введіть файл з масивом: ";
    cin >> arrayFileIn;

    cout << "Введіть файл для результату: ";
    cin >> arrayFileOut;

    readArray(arrayFileIn, arr, n);

    cout << "Введіть номер елемента K для видалення: ";
    cin >> k;

    deleteK(arr, n, k);

    writeArray(arrayFileOut, arr, n);

    cout << "Елемент видалено. Результат записано у файл.\n";
}

void task2()
{
    double matrix[MAX][MAX];
    int m, cols;
    string matrixFile;

    cout << "Введіть файл з матрицею: ";
    cin >> matrixFile;

    readMatrix(matrixFile, matrix, m, cols);

    int result = countIncreasingRows(matrix, m, cols);

    cout << "Кількість рядків із зростанням: " << result << endl;

    writeMatrix(matrixFile, matrix, m, cols);
}

void task3()
{
    double arr[MAX];
    int n;
    string arrayFileIn, arrayFileOut;

    cout << "Введіть файл з масивом: ";
    cin >> arrayFileIn;

    cout << "Введіть файл для результату: ";
    cin >> arrayFileOut;

    readArray(arrayFileIn, arr, n);

    insertionSort(arr, n);

    writeArray(arrayFileOut, arr, n);

    cout << "Відсортований масив записано у файл.\n";
}

/* ================= MAIN ================= */

int main()
{
    int choice;

    do
    {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1 - Видалити елемент з масиву\n";
        cout << "2 - Порахувати зростаючі рядки матриці\n";
        cout << "3 - Сортувати масив (вставками)\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                task1();
                break;

            case 2:
                task2();
                break;

            case 3:
                task3();
                break;

            case 0:
                cout << "Завершення програми.\n";
                break;

            default:
                cout << "Невірний вибір!\n";
        }

    } while (choice != 0);

    return 0;
}
