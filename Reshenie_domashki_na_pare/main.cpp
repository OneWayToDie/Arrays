#include<Windows.h>
#include<iostream>
using namespace std;

#define massive
//#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");



#ifdef massive
	const int n = 5;
	int arr[n];
	cout << "Введите элементы массива: ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		cout << arr[i] << "\t";
	}
	cout << endl;
	for (int i = n - 1; i >= 0; i--)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	int sum = 0;



	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	cout << "Сумма элементов массива: " << sum << endl;
	cout << "Среднее-арифметическое элементов массива: " << (double)sum / n << endl;

	int min = arr[0];
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	cout << "Минимальное значение в массиве: " << min << endl;
	cout << "Максимальное значение в массиве: " << max << endl;
}
#endif


#ifdef tab "\t"

	const int  n = 10;
	int arr[n] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	// Вывод исходного массива
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

	int number_of_shifts;
	cout << "Введите количество сдвигов: "; cin >> number_of_shifts;
	for (int i = 0; i < number_of_shifts; i++)
	{
		//циклический сдвиг массива
		int buffer = arr[0];
		for (int i = 1; i < n; i++)
		{
			arr[i - 1] = arr[i];
		}
		arr[n - 1] = buffer;
		Sleep(500);
		system("CLS");
		// Вывод сдвинутого массива
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << tab;
		}
		cout << endl;
	}
#endif
}