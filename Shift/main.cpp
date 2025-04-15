#include<iostream>
using namespace std;


//#define shift

void main()
{
	setlocale(LC_ALL, "");

#ifdef shift
	const int  n = 10;
	int kolichestvo_sdvigov;
	cout << "¬ведите количество сдвигов: "; cin >> kolichestvo_sdvigov;
	int arr[n] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int zero;
	for (int j = 0; j <	kolichestvo_sdvigov; j++)
	{
		zero = arr[0];
		for (int i = 0; i < n; i++)
		{
			i + 1 < n ? arr[i] = arr[i + 1] : arr[i] = zero;
		}
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
#endif
}