#include <iostream>
#include <Windows.h>


using namespace std;

#define repeat_OneD

void main()
{
	setlocale(LC_ALL, "");

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
			if (array[j] == array[i] && array[i]==0)
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
}