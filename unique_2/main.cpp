#include <iostream>
#include <windows.h>


using namespace std;

#define unique_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef unique_2

	const int Rows = 4;
	const int Cols = 4;
	int array[Rows][Cols];
	const int odnomerka = Rows * Cols;
	int perevod[odnomerka];
	int index_massiva = 0;
	int proverka;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			perevod[index_massiva] = array[i][j]; // переводим двумерный массив в одномерный
			index_massiva++;
		}
	}
	cout << "Рандомный массив: " << "\n";
	for (int i = 0; i < Rows*Cols; i++)
	{
		proverka = rand() % 16+1;
		for (int j = 0; j < Rows*Cols; j++)				// Цикл для задачи условий уникальности
		{
			if (perevod[j] == proverka)
			{
				proverka = 0;
				break;
			}
		}
		if (proverka != 0)
		{
			perevod[i] = proverka;
		}
		else
		{
			i--;
		}
	}
	for (int i = 0; i < Rows * Cols; i++) 
	{
		for (int j = i + 1; j < Rows * Cols; j++) 
		{
			if (perevod[j] < perevod[i])
			{
				int buffer = perevod[i]; // смена мест
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