#include <iostream>
#include <iomanip>
#include <time.h>


using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int MaxMin(int** a, const int rowCount, const int colCount);

int main()
{
	srand((unsigned)time(NULL));

	int Low = -6; // мінімальне число в массиві
	int High = 31; // максимальне число в массиві
	int rowCount; // рядки масиву
	int colCount; // колонки масиву
	cout << "n = "; cin >> rowCount;
	cout << "k = "; cin >> colCount;


	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	int minMax = MaxMin(a, rowCount, colCount);
	cout << minMax << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int MaxMin(int** a, const int rowCount, const int colCount)
{
	int min = 0, max = 0;
	int row = 1; // допоміжна змінна строки, яка потрібна, щоб не починати цикл, як i = 1;
	for (int i = 0; i < rowCount; i++)
	{
		if ((row % 2) != 0) { // цикл провіряє тільки непарні строки матриці
			row++;
			min = a[i][0];
			for (int j = 1; j < colCount; j++) {
				if (a[i][j] < min) {
					min = a[i][j];
				}
				if (i == 0) { // для уникнення помилки в першій строці 
					max = min;
				}
				if (min > max) { // якщо мінімальний елемент більший за минулий мінімальний, то він стає максимальним з мінімальних
					max = min;
				}
			}
		}
		else {
			row++; // якщо строка парна, то вона просто пропускається і переходить на нову
		}
	}
	return max; // виводить максимальний з мінімальних елементів
}