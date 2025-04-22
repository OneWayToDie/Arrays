#include <iostream>
#include <windows.h>


using namespace std;

#define unique

void main()
{
	setlocale (LC_ALL, "");

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
}
