#include<iostream>
using namespace std;

//#define massive


void main()
{
	setlocale(LC_ALL, "");

	/*const int  n = 5; // �������� �������
	int arr[n] = { 3, 5, 8}; // ����������������� ������
	arr[1] = 1024; // ������ ������� �������
	cout << arr[1] << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;*/


#ifdef massive

	const int  n = 5;
	int arr[n];
	int sum = 0;
	int min = 0;
	int max = 0;
	cout << "������� ����� enter �������� �������: "; 

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	min = arr[0];
	max = arr[0];
	cout << "����� ������� - ";
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
	cout << "�������� ������� - ";
	for (int i = n-1; i >= 0; i--)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "����� ��������� ������� - " << sum << "\n"; 
	cout << "������� �������������� - " << sum / n << endl;
	cout << "����������� �������� ������� - " << min << endl;
	cout << "������������ �������� ������� - " << max << endl;
#endif
}

