#include<iostream>
using namespace std;

//#define massive


void main()
{
	setlocale(LC_ALL, "");

	const int  n = 5; // элементы массива
	int arr[n] = { 3, 5, 8 }; // инициализированый массив
	arr[1] = 1024; // второй элемент массива
	cout << arr[1] << endl;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (100 - 50) + 50;
		//arr[i] = 50 + rand() % (100-50);
	}

#ifdef massive

	const int  n = 5;
	int arr[n];
	int sum = 0;
	int min = 0;
	int max = 0;
	cout << "Введите через enter значения массива: "; 

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	min = arr[0];
	max = arr[0];
	cout << "вывод массива - ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
		sum = sum+arr[i];
		if (arr[i] < min)
		{
			min = arr[i];
		}
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	cout << endl;
	cout << "инверсия массива - ";
	for (int i = n-1; i >= 0; i--)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "сумма элементов массива - " << sum << "\n"; 
	cout << "среднее арифметическое - " << sum / n << endl;
	cout << "минимальное значение массива - " << min << endl;
	cout << "максимальное значение массива - " << max << endl;
#endif


}

