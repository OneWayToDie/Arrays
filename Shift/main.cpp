#include<iostream>
#include<Windows.h>
using namespace std;


//#define shift
//#define shift_vpravo
//#define shift_debila // инверсия........... ne sprashivaite zachem, sam ne znayou

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

	for (int i = n-1; i >= 0; i--)
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
	for (int i = n-1; i >= 0; i--)
	{
		cout << arr[i] << "\t";
	}
	cout << "\n";
	

	/*for (int i = n - 1; i >= 0; i--)*/
#endif
}
