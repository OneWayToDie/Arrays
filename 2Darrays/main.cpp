#include<Windows.h>
#include<iostream>
using namespace std;


//#define primer
//#define TwoD_Arrays_One
//#define TwoD_Arrays_random


void main()
{
	setlocale(LC_ALL, "");

#ifdef primer
	cout << "2Darrays" << endl;
	const int ROWS = 3;
	const int COLS = 4;
	int arr[ROWS][COLS] =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
#endif

#ifdef TwoD_Arrays_One

	const int Rows = 3;
	const int Cols = 4;
	int sum = 0;
	int min = 0;
	int max = 0;
	int array[Rows][Cols]; cout << "������� �������� ���������� �������: ";

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cin >> array[i][j]; // ���� ��� ����� ���������� ������
		}
	}
	min = array[0][0];
	max = array[0][0];
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			sum = sum + array[i][j]; // ���� ��� ���������� �����
			if (array[i][j] < min)
			{
				min = array[i][j]; // �����������
			}
			if (array[i][j] > max)
			{
				max = array[i][j]; // ������������
			}
		}
	}
	cout << "����� ��������� ���������� ������� - " << sum << "\n";
	cout << "������� �������������� ���������� ������� - " << (double)sum / (Rows * Cols) << "\n";
	cout << "����������� �������� ���������� ������� - " << min << endl;
	cout << "������������ �������� ���������� ������� - " << max << endl;

#endif

#ifdef TwoD_Arrays_random
	const int Rows = 3;
	const int Cols = 4;
	int sum = 0;
	int min = 0;
	int max = 0;
	int array[Rows][Cols];

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			array[i][j] = rand() % 100; // ��������� ��������� �����
		}
	}

	cout << "����� ���������� ������� - ";

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << array[i][j] << " "; // ����� �� ������� �������������� �����
		}
		cout << "\n";
	}

	//��� �������� �������� �� ���������������� �������
	cout << "\n";
	min = array[0][0];
	max = array[0][0];
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			sum = sum + array[i][j]; 
			if (array[i][j] < min)
			{
				min = array[i][j];
			}
			if (array[i][j] > max)
			{
				max = array[i][j];
			}
		}
	}
	cout << "����� ��������� ���������� ������� - " << sum << "\n";
	cout << "������� �������������� ���������� ������� - " << (double)sum / (Rows * Cols) << "\n";
	cout << "����������� �������� ���������� ������� - " << min << endl;
	cout << "������������ �������� ���������� ������� - " << max << endl;
#endif
}
