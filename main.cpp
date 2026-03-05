#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 20;

/* ================= ФУНКЦІЇ ДЛЯ МАСИВУ ================= */

// зчитування масиву з файлу
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

// запис масиву у файл
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
/* Видалити елемент з номером K */

void deleteK(double arr[], int &n, int k)
{
    for (int i = k - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;
}

/* ================= СОРТУВАННЯ (ЗАВДАННЯ 3) ================= */
/* Сортування вставками за спаданням */

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

// зчитування матриці
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

// запис матриці у файл
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
/* Знайти кількість рядків із зростанням */

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

/* ================= MAIN ================= */

int main()
{
    double arr[MAX];
    double matrix[MAX][MAX];

    int n, m, cols;
    int k;

    string arrayFileIn, arrayFileOut;
    string matrixFile;

    /* ===== ЗАВДАННЯ 1 ===== */

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


    /* ===== ЗАВДАННЯ 2 ===== */

    cout << "\nВведіть файл з матрицею: ";
    cin >> matrixFile;

    readMatrix(matrixFile, matrix, m, cols);

    int result = countIncreasingRows(matrix, m, cols);

    cout << "Кількість рядків із зростанням: " << result << endl;

    writeMatrix(matrixFile, matrix, m, cols);


    /* ===== ЗАВДАННЯ 3 ===== */

    cout << "\nСортування масиву методом вставок (за спаданням)...\n";

    insertionSort(arr, n);

    writeArray(arrayFileOut, arr, n);

    cout << "Відсортований масив записано у файл.\n";

    return 0;
}
