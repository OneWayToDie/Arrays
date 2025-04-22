#include<iostream>
#include<Windows.h>
using namespace std;


//#define shift
//#define shift_vpravo
//#define shift_debila // инверсия........... ne sprashivaite zachem, sam ne znayou
//#define shift_dvumerki_vlevo
#define shift_dvumerki_vpravo

void main()
{
	setlocale(LC_ALL, "");

#ifdef shift
	const int  n = 10;
	int kolichestvo_sdvigov;
	cout << "Введите количество сдвигов: "; cin >> kolichestvo_sdvigov;
	int arr[n] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int zero;
	for (int j = 0; j < kolichestvo_sdvigov; j++)
	{
		zero = arr[0];
		for (int i = 0; i < n; i++)
		{
			i + 1 < n ? arr[i] = arr[i + 1] : arr[i] = zero;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << "\n";

#endif

#ifdef shift_vpravo
	const int  n = 10;
	int number_of_shifts; cout << "Введите количество сдвигов: "; cin >> number_of_shifts;
	int arr[n] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < number_of_shifts; i++)
	{
		int buffer = arr[n - 1];
		for (int i = n - 1; i >= 0; i--)
		{
			i - 1 >= 0 && i < n ? arr[i] = arr[i - 1] : arr[i] = buffer;
		}
		Sleep(1000);
		system("CLS");
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << "\t";
		}
		cout << endl;
	}
#endif

#ifdef shift_debila
	const int  n = 10;
	int kolichestvo_sdvigov;
	cout << "Введите количество сдвигов: "; cin >> kolichestvo_sdvigov;
	int arr[n] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int zero;

	for (int i = n - 1; i >= 0; i--)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	for (int j = 0; j < kolichestvo_sdvigov; j++)
	{
		zero = arr[0];
		for (int i = 0; i < n; i++)
		{
			i + 1 < n ? arr[i] = arr[i + 1] : arr[i] = zero;
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		cout << arr[i] << "\t";
	}
	cout << "\n";
#endif

#ifdef shift_dvumerki_vlevo

	const int Rows = 3;
	const int Cols = 3;
	int kolichestvo_sdvigov; cout << "Введите количество сдвигов: "; cin >> kolichestvo_sdvigov;
	int array[Rows][Cols] =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	};
	int tochka_sdviga;
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
	for (int j = 0; j < kolichestvo_sdvigov; j++)
	{
		tochka_sdviga = perevod[0];
		for (int i = 0; i < Rows*Cols; i++)
		{
			i + 1 < Rows*Cols ? perevod[i] = perevod[i + 1] : perevod[i] = tochka_sdviga; // делаем сдвиг влево
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

#ifdef shift_dvumerki_vpravo
	const int Rows = 3;
	const int Cols = 3;
	int kolichestvo_sdvigov; cout << "Введите количество сдвигов: "; cin >> kolichestvo_sdvigov;
	int array[Rows][Cols] =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	};
	int tochka_sdviga;
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
	for (int j = 0; j < kolichestvo_sdvigov; j++)
	{
		tochka_sdviga = perevod[odnomerka - 1];
		for (int i = odnomerka - 1; i >= 0; i--)
		{
			i - 1 >= 0 && i < odnomerka ? perevod[i] = perevod[i - 1] : perevod[i] = tochka_sdviga; // сдвигаем одномерный массив вправо
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

