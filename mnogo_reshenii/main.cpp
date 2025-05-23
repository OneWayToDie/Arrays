#include<iostream>
#include<Windows.h>


using namespace std;

//#define numerics_binary
//#define numerics_hex
//#define unique_One_Arrays
//#define repeats_One_Arrays
//#define sortirovka
//#define unique_2
//#define repeats_2
void main()
{
	setlocale(LC_ALL, "");

#ifdef numerics_binary
	int decimal; // Эта переменная будет хранить десятичное число, введённое пользователем
	cout << "Введите десятичное число: "; cin >> decimal;
	const int n = 32; // Максимально возможная разрядность двоичного числа
	bool binary[n] = {};  //этот массив будет хранить разряды двоичного числа
	int i = 0;
	for (;decimal; decimal /= 2)
	{
		binary[i++] = decimal % 2;
	}
	for (--i; i >= 0; i--)
	{
		cout << binary[i];
		if (i % 8 == 0) cout << " ";
		if (i % 4 == 0) cout << " ";
	}
	cout << endl;
#endif

#ifdef numerics_hex

	int decimal; // Эта переменная будет хранить десятичное число, введённое пользователем
	cout << "Введите десятичное число: "; cin >> decimal;
	const int n = 8;
	char hex[n] = {};
	int i = 0;
	for (;decimal; decimal /= 16)
	{
		/*hex[i++] = decimal % 16;*/
		hex[i] = decimal % 16;
		hex[i++] += hex[i] < 10 ? 48 : 55;
	}
	for (--i; i >= 0; i--)
	{
		cout << hex[i];
		/*cout << char(hex[i] < 10 ? hex[i] + 48:hex[i]+=55);*/
	}
	cout << endl;
#endif

#ifdef unique_One_Arrays

	const int n = 10;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		bool unique;
		do {
			arr[i] = rand() % 10;
			unique = true; // предположим, что сгенерировалось уникальное случайное число
			// но это нужно проверить:
			for (int j = 0; j < i; j++)
			{
				if (arr[i] == arr[j])
				{
					unique = false;
					break; // прерывает текущую итерацию и все последующие итерации
				}
			}
		} while (!unique);
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

#endif

#ifdef repeats_One_Arrays

	const int n = 10;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;


	// поиск повторений:
	for (int i = 0; i < n; i++)
	{
		int met_before = false; // предположим, что выбранное значение раньше не встречалось,
		//но это нужно проверить:
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				met_before = true;
				break;
			}
		}
		if (met_before)continue;
		// Ключевое слово continue прерывает текущую итерацию. и переходит к следующей
		int repeats = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] == arr[j])
			{
				repeats++;
			}
		}
		if (repeats > 0) cout << "Значение " << arr[i] << " Повторяется " << repeats << " раз\n";
	}
#endif

#ifdef sortirovka

	cout << "2Darrays" << "\n";
	const int Rows = 5;
	const int Cols = 4;
	int arr[Rows][Cols] = {
							{1, 2, 3},
							{4, 5, 6},
							{7, 8, 9}
	};
	// задаём массив:
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
		 arr[i][j] = rand() % 100;
		}
	}

	//
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	//Сортировка массива:
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			for (int k = i; k < Rows; k++)
			{
				for (int l = k == i ? j+1 : 0; l < Cols; l++)		/*k > i ? j+1 : 0*/
				{
					//arr[i][j] - выбранный элемент
					//arr[k][l] - перебираемый элемент
					if (arr[k][l] < arr[i][j])
					{
						int buffer = arr[i][j];
						arr[i][j] = arr[k][l];
						arr[k][l] = buffer;
					}
				}
			}
		}
	}
	// Вывод отсортированного массива:
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
#endif

#ifdef unique_2

	const int Rows = 3;
	const int Cols = 4;
	int arr[Rows][Cols];
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			bool unique;
			do
			{
				arr[i][j] = rand() % (Rows * Cols);
				unique = true;
				for (int k = 0; k <= i; k++)
				{
					for (int l = 0; l < (k == i ? j : Cols); l++)
					{
						if (arr[i][j] == arr[k][l])
						{
							unique = false;
							break;
						}
					}
					if (!unique)break;
				}
			}while (!unique);
		}
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}
#endif

#ifdef repeats_2
	const int ROWS = 4;
	const int COLS = 4;
	int arr[ROWS][COLS];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	/*for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			bool met_before = false;
			for (int k = 0; k <= i; k++)
			{
				for (int l = 0; l < (k == i ? j : COLS); l++)
				{
					if (arr[i][j] == arr[k][l])
					{
						met_before = true;
						break;
					}
				}
				if (met_before)break;
			}
			if (met_before)continue;
			int count = 0;
			for (int k = i; k < ROWS; k++)
			{
				for (int l = k == i ? j + 1 : 0; l < COLS; l++)
				{
					if (arr[i][j] == arr[k][l])count++;
				}
			}
			if (count > 0) cout << "Значение " << arr[i][j] << " повторяется " << count << " раз." << endl;
		}
	}*/

	for (int i = 0; i < ROWS * COLS; i++)
	{
		bool met_before = false;
		for (int j = 0; j < i; j++)
		{
			if (arr[0][i] == arr[0][j])
			{
				met_before = true;
				break;
			}
		}
		if (met_before)continue;
		int count = 0;
		for (int j = i + 1; j < ROWS * COLS; j++)
		{
			if (arr[0][i] == arr[0][j])count++;
		}
		if (count) cout << "Значение " << arr[0][i] << " повторяется " << count << " раз\n";
	}
#endif
}
