#include<iostream>
using namespace std;

#define massive


void main()
{
	setlocale(LC_ALL, "");

	const int  n = 5; // �������� �������
	int arr[n] = { 3, 5, 8}; // ����������������� ������
	arr[1] = 1024; // ������ ������� �������
	cout << arr[1] << endl;
	/*for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;*/

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}
}