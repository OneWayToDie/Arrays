#include<Windows.h>
#include<iostream>
#include<string>
using namespace std;

#define numerics

void main()
{
	setlocale(LC_ALL, "");

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
			if(arr[i] == 0 || arr[i] == 1)
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
}


