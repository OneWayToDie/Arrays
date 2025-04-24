#include<Windows.h>
#include<iostream>
using namespace std;


//#define primer
//#define TwoD_Arrays_One
//#define TwoD_Arrays_random
//#define TwoD_Arrays_sortirovka_dano
//#define TwoD_Arrays_sortirovka_random
//#define TwoD_Arrays_sortirovka_dannie_polzovatelya

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

	cout << "����� ���������� ������� - ";
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			array[i][j] = rand() % 100; // ��������� ��������� �����
			cout << array[i][j] << " ";
		}
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

#ifdef TwoD_Arrays_sortirovka_dano

	const int Rows = 3;
	const int Cols = 3;
	int array[Rows][Cols] =
	{
		{3, 8, 3},
		{4, 6, 6},
		{7, 4, 9},
	};
	const int odnomerka = Rows * Cols;
	int perevod[odnomerka];
	int index_massiva = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			perevod[index_massiva] = array[i][j]; // ��������� ��������� ������ � ����������
			index_massiva++;
		}
	}
	for (int i = 0; i < Rows*Cols; i++) // ������� i �������� �������, � ������� ����� ���������
	{
		for (int j = i + 1; j < Rows*Cols; j++) // ������� j ���������� �������� � ������� ������������ ��������
		{
			if (perevod[j] < perevod[i])
			{
				int buffer = perevod[i];
				perevod[i] = perevod[j];
				perevod[j] = buffer;
			}
		}
	}
	index_massiva = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			array[i][j] = perevod[index_massiva]; // ��������� ������ ������� � ���������
			index_massiva++;
		}
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << array[i][j] << "\t"; // ������� ������
		}
		cout << "\n";
	}
#endif


#ifdef TwoD_Arrays_sortirovka_random

	const int Rows = 3;
	const int Cols = 3;
	int array[Rows][Cols];
	const int odnomerka = Rows * Cols;
	int perevod[odnomerka];
	int index_massiva = 0;


	cout << "��������� ������: " << "\n";
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols;j++)
		{
			array[i][j] = rand() % 100;
			cout << array[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << endl;
	cout << "����� ������� � ���������� ������������������: " <<"\n";
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			perevod[index_massiva] = array[i][j];
			index_massiva++;
		}
	}
	for (int i = 0; i < Rows * Cols; i++)
	{
		for (int j = i + 1; j < Rows * Cols; j++)
		{
			if (perevod[j] < perevod[i])
			{
				int buffer = perevod[i];
				perevod[i] = perevod[j];
				perevod[j] = buffer;
			}
		}
	}
	index_massiva = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			array[i][j] = perevod[index_massiva];
			index_massiva++;
		}
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << "\n";
	}
#endif

#ifdef TwoD_Arrays_sortirovka_dannie_polzovatelya
	const int Rows = 3;
	const int Cols = 3;
	int array[Rows][Cols];
	const int odnomerka = Rows * Cols;
	int perevod[odnomerka];
	int index_massiva = 0;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols;j++)
		{
			cout << "������� ������ �������: " << " "; cin >> array[i][j];
		}
	}
	cout << endl;
	cout << "����� ������� � ���������� ������������������: " << "\n";
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			perevod[index_massiva] = array[i][j];
			index_massiva++;
		}
	}
	for (int i = 0; i < Rows * Cols; i++)
	{
		for (int j = i + 1; j < Rows * Cols; j++)
		{
			if (perevod[j] < perevod[i])
			{
				int buffer = perevod[i];
				perevod[i] = perevod[j];
				perevod[j] = buffer;
			}
		}
	}
	index_massiva = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			array[i][j] = perevod[index_massiva];
			index_massiva++;
		}
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << array[i][j] << "\t";
		}
		cout << "\n";
	}
#endif
}
