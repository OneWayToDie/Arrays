#include<iostream>
using namespace std;

//#define massive
#define random
//#define algoritm_sortirovki

void main()
{
	setlocale(LC_ALL, "");
#ifdef random
	const int  n = 5; // элементы массива
	int arr[n] = { 3, 5, 8 }; // инициализированый массив
	arr[1] = 1024; // второй элемент массива
	cout << arr[1] << endl;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (100 - 50) + 50;
		//arr[i] = 50 + rand() % (100-50);
	}
	int minRand, maxRand;
	do {
		cout << "Введите минимальное случайное число: "; cin >> minRand;
		cout << "Введите максимальное случайное число: "; cin >> maxRand;
		if (minRand > maxRand)cout << "Минимальное должно быть меньше максимального" << endl;
		if (minRand == maxRand)cout << "Числа должны быть разные" << endl;
	} while (minRand >= maxRand);
	/*if (maxRand < minRand)
	{
		int buffer = minRand;
		minRand = maxRand;
		maxRand = buffer;
	}*/
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}

	for (int i = 0; i < n; i++) // счётчик i выбирает элемент, в который нужно поместить
	{
		for (int j = i + 1; j < n; j++) // счётчик j перебирает элементы в поисках минимального значения
		{
			//arr[i] - выбранный элемент
			// arr[j] - перебираемый элемент
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
#endif


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

#ifdef algoritm_sortirovki
	

	for (int i = 0; i < n; i++) // счётчик i выбирает элемент, в который нужно поместить
	{
		for (int j = i + 1; j < n; j++) // счётчик j перебирает элементы в поисках минимального значения
		{
			//arr[i] - выбранный элемент
			// arr[j] - перебираемый элемент
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
#endif


}

