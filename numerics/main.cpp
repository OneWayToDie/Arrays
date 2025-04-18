#include<Windows.h>
#include<iostream>
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

	}

	else
	{
		cout << "Мы вновь и вновь должны смерять себя изнутри. Прав метрополит! Мы должны жертвовать ему десятину! Должны отказаться от роскоши! Нужно страдать что-бы обрести прощение! Человечеству не спастись, но это не значит, что надежда потеряна для всех";
	}


#endif
}