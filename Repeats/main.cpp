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

	cout << "������:   ";
	for (int i = 0; i < 10; i++)
	{
		array[i] = rand() % (maxRand - minRand) + minRand; // ��������
	}
	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << "\t"; // ������� ������
	}
	cout << endl;

	//cout << "����������:   ";
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (array[j] == array[i] && array[i]==0)
			{
				//cout << array[i] << " "; 
				shet_zero++;  //������ ������� �����
				array[i] = 0; // ��������
			}
			if (array[i] == array[j] && array[i] == 1)
			{
				//cout << array[i] << " ";
				shet_one++;		//������ ������� ������
				array[i] = 0;  // ��������
			}
			if (array[i] == array[j] && array[i] == 2)
			{
				//cout << array[i] << " ";
				shet_two++;		//������ ������� �����
				array[i] = 0; // ��������
			}
			if (array[i] == array[j] && array[i] == 3)
			{
				//cout << array[i] << " ";
				shet_three++;	//������ ������� �����
				array[i] = 0; // ��������
			}
			if (array[i] == array[j] && array[i] == 4)
			{
				//cout << array[i] << " ";
				shet_four++;	//������ ������� �������
				array[i] = 0; // ��������
			}
			if (array[i] == array[j] && array[i] == 5)
			{
				//cout << array[i] << " ";
				shet_five++;	//������ ������� ������
				array[i] = 0; // ��������
			}
		}
	}
	//cout << "\n";
	cout << "���������� ���������� 0 - " << shet_zero << "\n";
	cout << "���������� ���������� 1 - " << shet_one << "\n";
	cout << "���������� ���������� 2 - " << shet_two << "\n";
	cout << "���������� ���������� 3 - " << shet_three << "\n";
	cout << "���������� ���������� 4 - " << shet_four << "\n";
	cout << "���������� ���������� 5 - " << shet_five << "\n";
#endif
}