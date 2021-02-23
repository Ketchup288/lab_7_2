﻿#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
void Create(int** a, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void MaxMinOddRows(int** a, const int rowCount, const int colCount, int rowNo, int& max, int row);
void MinRow(int** a, const int rowNo, const int colCount, int colNo, int& min);


int main()
{
	srand((unsigned)time(NULL));

	int Low = 0;
	int High = 31;

	int rowCount; // рядки матриці
	int colCount; // колонки матриці
	cout << "n = "; cin >> rowCount;
	cout << "k = "; cin >> colCount;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	
	int max = 0; // в цю змінну буде передаватись результат функції MaxMinOddRows
	int row = 1; // перемінна для визначення рядків в функції MaxMinOddRows
	MaxMinOddRows(a, rowCount, colCount, 0, max, row);
	cout << max << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}

void MinRow(int** a, const int rowNo, const int colCount, int colNo, int& min)
{
	if (a[rowNo][colNo] < min)
		min = a[rowNo][colNo];
	if (colNo < colCount - 1)
		MinRow(a, rowNo, colCount, colNo + 1, min);
}


void MaxMinOddRows(int** a, const int rowCount, const int colCount, int rowNo, int& max, int row)
{
	if ((row % 2) != 0) { // провірка чи рядок непарний 
		row++;
		int min = a[rowNo][0];
		MinRow(a, rowNo, colCount, 1, min); // Викликає функцію MinRow, яка визначає найменьше значення в данному рядку
		if (rowNo == 0) // Якщо це перший рядок, то для уникнення помилки max стає min
			max = min;
		if (min > max)
			max = min;
		if (rowNo < rowCount - 1) // перевірка чи ще потрібно провіряти далі, чи рядки закінчились
			MaxMinOddRows(a, rowCount, colCount, rowNo + 1, max, row);
	}
	else {
		row++;
		if (rowNo < rowCount - 1) {
			MaxMinOddRows(a, rowCount, colCount, rowNo + 1, max, row);
		}
	}
}

