#include <iostream>
#include <iomanip>
#include <time.h>


using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
int MaxMinOdd(int** a, const int rowCount, const int colCount);

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
	int minMax = MaxMinOdd(a, rowCount, colCount);
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

int MaxMinOdd(int** a, const int rowCount, const int colCount) 
{
	int min, max; 
	for (int i = 0; i < rowCount; i++)
	{
		if (i % 2 == 0 || i == 0) // визначає непарні рядки
		{
			min = a[i][0];
			for (int j = 1; j < colCount; j++) {
				if (a[i][j] < min) {
					min = a[i][j];
				}
			}
			if (i == 0) { // для уникнення помилок при першій ітерації
				max = min;
		}
			if (min > max) {
				max = min;
			}
		} // *примітка: початок рахунку рядків матриці починається з 1, а не з 0
	} 
	return max;
}
