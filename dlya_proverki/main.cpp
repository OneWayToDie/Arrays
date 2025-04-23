#include<iostream>
#include<Windows.h>
#include<string>

using namespace std;

//#define shift_vpravo
//#define numerics
//#define unique
//#define repeat_OneD
//#define TwoD_Arrays_One
//#define TwoD_Arrays_random
//#define shift_dvumerki_vlevo
//#define shift_dvumerki_vpravo
#define TwoD_Arrays_sortirovka

void main()
{
	setlocale(LC_ALL, "");

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

#ifdef numerics
	int number; cout << "Введите десятичное число, которое хотите преобразовать: "; cin >> number;
	int system; cout << "Выберите в какую систему хотите перевести число, двоичную или шестнадцатиричную: "; cin >> system;
	if (system == 2)
	{
		int kolichestvo_znachenii = 0;
		for (int i = number; i > 0; i = i / 2)
		{
			kolichestvo_znachenii++;  // количество символов нашей цифры
		}
		/*cout << kolichestvo_znachenii;*/
		const int stroka = 100;  // переменная для создания статичного массива(максимальное количество элементов в двоичном коде)
		int arr[stroka];
		for (int j = kolichestvo_znachenii; j > 0; j--)			// инверсия для того чтобы перевернуть запись справа налево
		{
			arr[j - 1] = number % 2;				//преобразуем в нули и единицы(путём сохранения остатка от деления)
			number = number / 2;
		}
		for (int i = 0; i < kolichestvo_znachenii; i++)
		{
			if (arr[i] == 0 || arr[i] == 1)
				cout << arr[i] << "\t"; // вывод на консоль
		}
	}
	else if (system == 16)
	{
		int delenie;
		string stroka = "";
		while (number % system > 0)
		{
			delenie = number % 16;
			number = number / system;

			if (delenie != 10 && delenie != 11 && delenie != 12 && delenie != 13 && delenie != 14 && delenie != 15)
			{
				stroka = stroka + to_string(delenie);
			}
			else
			{
				switch (delenie)
				{
				case 10: stroka = stroka + "A"; break;
				case 11: stroka = stroka + "B"; break;
				case 12: stroka = stroka + "C"; break;
				case 13: stroka = stroka + "D"; break;
				case 14: stroka = stroka + "E"; break;
				case 15: stroka = stroka + "F"; break;
				}
			}
		}
		for (int i = stroka.length() - 1; i >= 0; i--)
		{
			cout << stroka[i];
		}
		/*cout << stroka;*/
	}
	else
	{
		cout << "Мы вновь и вновь должны смерять себя изнутри. Прав метрополит! Мы должны жертвовать ему десятину! Должны отказаться от роскоши! Нужно страдать что-бы обрести прощение! Человечеству не спастись, но это не значит, что надежда потеряна для всех";
	}
#endif

#ifdef unique
	int arr[10];
	int proverka;


	for (int i = 0; i < 10; i++)
	{
		proverka = rand() % 10 + 71;

		for (int j = 0; j < 10; j++)
		{
			if (arr[j] == proverka)
			{
				proverka = 0;
				break;
			}
		}
		if (proverka != 0)
		{
			arr[i] = proverka;
		}
		else
		{
			i--;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
#endif

#ifdef repeat_OneD

	int array[10];
	int maxRand = 5;
	int minRand = 0;
	int shet_zero = 0;
	int shet_one = 0;
	int shet_two = 0;
	int shet_three = 0;
	int shet_four = 0;
	int shet_five = 0;

	cout << "Массив:   ";
	for (int i = 0; i < 10; i++)
	{
		array[i] = rand() % (maxRand - minRand) + minRand; // рандомим
	}
	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << "\t"; // выводим массив
	}
	cout << endl;

	//cout << "Повторения:   ";
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (array[j] == array[i] && array[i] == 0)
			{
				//cout << array[i] << " "; 
				shet_zero++;  //делаем счётчик нулей
				array[i] = 0; // обнуляем
			}
			if (array[i] == array[j] && array[i] == 1)
			{
				//cout << array[i] << " ";
				shet_one++;		//делаем счётчик единиц
				array[i] = 0;  // обнуляем
			}
			if (array[i] == array[j] && array[i] == 2)
			{
				//cout << array[i] << " ";
				shet_two++;		//делаем счётчик двоек
				array[i] = 0; // обнуляем
			}
			if (array[i] == array[j] && array[i] == 3)
			{
				//cout << array[i] << " ";
				shet_three++;	//делаем счётчик троек
				array[i] = 0; // обнуляем
			}
			if (array[i] == array[j] && array[i] == 4)
			{
				//cout << array[i] << " ";
				shet_four++;	//делаем счётчик четвёрок
				array[i] = 0; // обнуляем
			}
			if (array[i] == array[j] && array[i] == 5)
			{
				//cout << array[i] << " ";
				shet_five++;	//делаем счётчик пятёрок
				array[i] = 0; // обнуляем
			}
		}
	}
	//cout << "\n";
	cout << "количество повторений 0 - " << shet_zero << "\n";
	cout << "количество повторений 1 - " << shet_one << "\n";
	cout << "количество повторений 2 - " << shet_two << "\n";
	cout << "количество повторений 3 - " << shet_three << "\n";
	cout << "количество повторений 4 - " << shet_four << "\n";
	cout << "количество повторений 5 - " << shet_five << "\n";
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

	cout << "Вывод двумерного массива: " << "\n";

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
		for (int i = 0; i < Rows * Cols; i++)
		{
			i + 1 < Rows * Cols ? perevod[i] = perevod[i + 1] : perevod[i] = tochka_sdviga; // делаем сдвиг влево
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
			perevod[index_massiva] = array[i][j]; // перевод в одномерный
			index_massiva++;
		}
	}
	for (int i = 0; i < Rows * Cols; i++) // счётчик i выбирает элемент, в который нужно поместить
	{
		for (int j = i + 1; j < Rows * Cols; j++) // счётчик j перебирает элементы в поисках минимального значения
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