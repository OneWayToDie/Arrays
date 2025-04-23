#include<Windows.h>
#include<iostream>
using namespace std;


//#define primer
//#define TwoD_Arrays_One
//#define TwoD_Arrays_random
#define TwoD_Arrays_sortirovka

void main()
{
	setlocale(LC_ALL, "");

#ifdef primer
	cout << "2Darrays" << endl;
	const int ROWS = 3;
	const int COLS = 4;
	int arr[ROWS][COLS] =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
#endif

#ifdef TwoD_Arrays_One

	const int Rows = 3;
	const int Cols = 4;
	int sum = 0;
	int min = 0;
	int max = 0;
	int array[Rows][Cols]; cout << "Введите значения двумерного массива: ";

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cin >> array[i][j]; // Цикл для ввода двумерного масива
		}
	}
	min = array[0][0];
	max = array[0][0];
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			sum = sum + array[i][j]; // Цикл для нахождения суммы
			if (array[i][j] < min)
			{
				min = array[i][j]; // минималОЧКА
			}
			if (array[i][j] > max)
			{
				max = array[i][j]; // максималОЧКА
			}
		}
	}
	cout << "сумма элементов двумерного массива - " << sum << "\n";
	cout << "Среднее арифметическое двумерного массива - " << (double)sum / (Rows * Cols) << "\n";
	cout << "минимальное значение двумерного массива - " << min << endl;
	cout << "максимальное значение двумерного массива - " << max << endl;

#endif

#ifdef TwoD_Arrays_random
	const int Rows = 3;
	const int Cols = 4;
	int sum = 0;
	int min = 0;
	int max = 0;
	int array[Rows][Cols];

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			array[i][j] = rand() % 100; // генерация рандомных чисел
		}
	}

	cout << "Вывод двумерного массива - ";

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << array[i][j] << " "; // вывод на консоль сгенерированых чисел
		}
		cout << "\n";
	}

	//Все заданные действия со сгенерированными числами
	cout << "\n";
	min = array[0][0];
	max = array[0][0];
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			sum = sum + array[i][j]; 
			if (array[i][j] < min)
			{
				min = array[i][j];
			}
			if (array[i][j] > max)
			{
				max = array[i][j];
			}
		}
	}
	cout << "сумма элементов двумерного массива - " << sum << "\n";
	cout << "Среднее арифметическое двумерного массива - " << (double)sum / (Rows * Cols) << "\n";
	cout << "минимальное значение двумерного массива - " << min << endl;
	cout << "максимальное значение двумерного массива - " << max << endl;
#endif

#ifdef TwoD_Arrays_sortirovka

	const int Rows = 3;
	const int Cols = 3;
	int array[Rows][Cols] =
	{
		{3, 8, 3},
		{4, 6, 6},
		{7, 4, 9},
	};
	const int odnomerka = Rows * Cols;
	int perevod[odnomerka];
	int index_massiva = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			perevod[index_massiva] = array[i][j]; // переводим двумерный массив в одномерный
			index_massiva++;
		}
	}
	for (int i = 0; i < Rows*Cols; i++) // счётчик i выбирает элемент, в который нужно поместить
	{
		for (int j = i + 1; j < Rows*Cols; j++) // счётчик j перебирает элементы в поисках минимального значения
		{
			if (perevod[j] < perevod[i])
			{
				int buffer = perevod[i];
				perevod[i] = perevod[j];
				perevod[j] = buffer;
			}
		}
	}
	index_massiva = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			array[i][j] = perevod[index_massiva]; // переводим массив обратно в двумерный
			index_massiva++;
		}
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << array[i][j] << "\t"; // выводим массив
		}
		cout << "\n";
	}
#endif
}
