#include <iostream>

using namespace std;

#define repeats_TwoD

void main()
{
	setlocale(LC_ALL, "");


#ifdef repeats_TwoD

	const int Rows = 4;
	const int Cols = 4;
	int array[Rows][Cols];
	const int odnomerka = Rows * Cols;
	int perevod[odnomerka];
	int index_massiva = 0;
	////////////// ���������� ��� ��������� ��������� �����
	int shet_one = 0;
	int shet_two = 0;
	int shet_three = 0;
	int shet_four = 0;
	int shet_five = 0;
	int shet_six = 0;
	int shet_seven = 0;
	int shet_eight = 0;
	int shet_nine = 0;
	int shet_ten = 0;
	int shet_eleven = 0;
	int shet_twelve = 0;
	int shet_thirteen = 0;
	int shet_fourteen = 0;
	int shet_fifteen = 0;
	int shet_sixteen = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			array[i][j] = rand() % 16 + 1; // ���������
		}
	}
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			perevod[index_massiva] = array[i][j]; // ������� � ���������� ������
			index_massiva++;
		}
	}
	for (int i = 0; i < Rows * Cols; i++)
	{
		for (int j = i + 1; j < Rows * Cols; j++)
		{
			if (perevod[j] < perevod[i])
			{
				int buffer = perevod[i]; // ����� ����
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
	cout << "��������� ������: " << "\n";
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << array[i][j] << "\t"; // ������� ������
		}
		cout << "\n";
	}

	for (int i = 0; i < 16; i++)
	{
		for (int j = i + 1; j < 16; j++)
		{
			if (perevod[i] == perevod[j] && perevod[i] == 1)
			{
				shet_one++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 2)
			{
				shet_two++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 3)
			{
				shet_three++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 4)
			{
				shet_four++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 5)
			{
				shet_five++;
				perevod[i] = 0;
			}
			if (perevod[j] == perevod[i] && perevod[i] == 6)
			{
				shet_six++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 7)
			{
				shet_seven++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 8)
			{
				shet_eight++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 9)
			{
				shet_nine++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 10)
			{
				shet_ten++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 11)
			{
				shet_eleven++;
				perevod[i] = 0;
			}
			if (perevod[j] == perevod[i] && perevod[i] == 12)
			{
				shet_twelve++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 13)
			{
				shet_thirteen++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 14)
			{
				shet_fourteen++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 15)
			{
				shet_fifteen++;
				perevod[i] = 0;
			}
			if (perevod[i] == perevod[j] && perevod[i] == 16)
			{
				shet_sixteen++;
				perevod[i] = 0;
			}
		}
	}
	cout << "���������� ���������� 1 - " << shet_one << "\n";
	cout << "���������� ���������� 2 - " << shet_two << "\n";
	cout << "���������� ���������� 3 - " << shet_three << "\n";
	cout << "���������� ���������� 4 - " << shet_four << "\n";
	cout << "���������� ���������� 5 - " << shet_five << "\n";
	cout << "���������� ���������� 6 - " << shet_six << "\n";
	cout << "���������� ���������� 7 - " << shet_seven << "\n";
	cout << "���������� ���������� 8 - " << shet_eight << "\n";
	cout << "���������� ���������� 9 - " << shet_nine << "\n";
	cout << "���������� ���������� 10 - " << shet_ten << "\n";
	cout << "���������� ���������� 11 - " << shet_eleven << "\n";
	cout << "���������� ���������� 12 - " << shet_twelve << "\n";
	cout << "���������� ���������� 13 - " << shet_thirteen << "\n";
	cout << "���������� ���������� 14 - " << shet_fourteen << "\n";
	cout << "���������� ���������� 15 - " << shet_fifteen << "\n";
	cout << "���������� ���������� 16 - " << shet_sixteen << "\n";
#endif
}