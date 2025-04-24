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
//#define TwoD_Arrays_sortirovka_dano
//#define TwoD_Arrays_sortirovka_random
//#define TwoD_Arrays_sortirovka_dannie_polzovatelya
//#define unique_2
#define repeats_TwoD

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

		//cout << hex << number << endl; // hex - манипулятор для перевода 10-ной системы в 16-ную
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
	for (int i = 0; i < 6; i++)
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

	cout << "Вывод двумерного массива - ";
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			array[i][j] = rand() % 100; // генерация рандомных чисел
			cout << array[i][j] << " ";
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

#ifdef TwoD_Arrays_sortirovka_dano

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

#ifdef TwoD_Arrays_sortirovka_random
	const int Rows = 3;
	const int Cols = 3;
	int array[Rows][Cols];
	const int odnomerka = Rows * Cols;
	int perevod[odnomerka];
	int index_massiva = 0;


	cout << "Рандомный массив: " << "\n";
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols;j++)
		{
			array[i][j] = rand() % 100;
			cout << array[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << endl;
	cout << "Вывод массива в поочерёдной послдеовательности: " << "\n";
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			perevod[index_massiva] = array[i][j];
			index_massiva++;
		}
	}
	for (int i = 0; i < Rows * Cols; i++)
	{
		for (int j = i + 1; j < Rows * Cols; j++)
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
			array[i][j] = perevod[index_massiva];
			index_massiva++;
		}
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << "\n";
	}
#endif

#ifdef TwoD_Arrays_sortirovka_dannie_polzovatelya
	const int Rows = 3;
	const int Cols = 3;
	int array[Rows][Cols];
	const int odnomerka = Rows * Cols;
	int perevod[odnomerka];
	int index_massiva = 0;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols;j++)
		{
			cout << "Введите данные массива: " << " "; cin >> array[i][j];
		}
	}
	cout << endl;
	cout << "Вывод массива в поочерёдной послдеовательности: " << "\n";
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			perevod[index_massiva] = array[i][j];
			index_massiva++;
		}
	}
	for (int i = 0; i < Rows * Cols; i++)
	{
		for (int j = i + 1; j < Rows * Cols; j++)
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
			array[i][j] = perevod[index_massiva];
			index_massiva++;
		}
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << "\n";
	}
#endif

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
	for (int i = 0; i < Rows * Cols; i++)
	{
		proverka = rand() % 16 + 1;
		for (int j = 0; j < Rows * Cols; j++) // Цикл для задачи условий уникальности
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

#ifdef repeats_TwoD

	const int Rows = 4;
	const int Cols = 4;
	int array[Rows][Cols];
	const int odnomerka = Rows * Cols;
	int perevod[odnomerka];
	int index_massiva = 0;
	////////////// переменные для пересчёта рандомных чисел
	int shet_one = 0;
	int shet_two = 0;
	int shet_three = 0;
	int shet_four = 0;
	int shet_five = 0;
	int shet_six = 0;
	int shet_seven = 0;
	int shet_eight = 0;
	int shet_nine = 0;
	int shet_ten = 0;
	int shet_eleven = 0;
	int shet_twelve = 0;
	int shet_thirteen = 0;
	int shet_fourteen = 0;
	int shet_fifteen = 0;
	int shet_sixteen = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			array[i][j] = rand() % 16 + 1; // генерация
		}
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			perevod[index_massiva] = array[i][j]; // перевод в одномерный массив
			index_massiva++;
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
	cout << "Случайный массив: " << "\n";
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << array[i][j] << "\t"; // выводим массив
		}
		cout << "\n";
	}

	for (int i = 0; i < 16; i++)
	{
		for (int j = i + 1; j < 16; j++)
		{
			if (perevod[i] == perevod[j] && perevod[i] == 1)
			{
				shet_one++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 2)
			{
				shet_two++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 3)
			{
				shet_three++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 4)
			{
				shet_four++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 5)
			{
				shet_five++;
				perevod[i] = 0;
			}
			if (perevod[j] == perevod[i] && perevod[i] == 6)
			{
				shet_six++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 7)
			{
				shet_seven++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 8)
			{
				shet_eight++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 9)
			{
				shet_nine++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 10)
			{
				shet_ten++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 11)
			{
				shet_eleven++;
				perevod[i] = 0;
			}
			if (perevod[j] == perevod[i] && perevod[i] == 12)
			{
				shet_twelve++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 13)
			{
				shet_thirteen++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 14)
			{
				shet_fourteen++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 15)
			{
				shet_fifteen++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 16)
			{
				shet_sixteen++;
				perevod[i] = 0;
			}
		}
	}
	cout << "количество повторений 1 - " << shet_one << "\n";
	cout << "количество повторений 2 - " << shet_two << "\n";
	cout << "количество повторений 3 - " << shet_three << "\n";
	cout << "количество повторений 4 - " << shet_four << "\n";
	cout << "количество повторений 5 - " << shet_five << "\n";
	cout << "количество повторений 6 - " << shet_six << "\n";
	cout << "количество повторений 7 - " << shet_seven << "\n";
	cout << "количество повторений 8 - " << shet_eight << "\n";
	cout << "количество повторений 9 - " << shet_nine << "\n";
	cout << "количество повторений 10 - " << shet_ten << "\n";
	cout << "количество повторений 11 - " << shet_eleven << "\n";
	cout << "количество повторений 12 - " << shet_twelve << "\n";
	cout << "количество повторений 13 - " << shet_thirteen << "\n";
	cout << "количество повторений 14 - " << shet_fourteen << "\n";
	cout << "количество повторений 15 - " << shet_fifteen << "\n";
	cout << "количество повторений 16 - " << shet_sixteen << "\n";
#endif

}