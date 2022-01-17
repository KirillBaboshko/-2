#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <windows.h>
////������������ ����� ���� � �����
//#define MAX_PATH 260
////���������� �������� �� ������
//#define NUM_COLS 18
////���������� ����� �� ������
//#define NUM_ROWS 24



using namespace std;

template<typename T>
void Sort(T** a, int n, int m)
{
	for (int k = 0; k < n; k++)
		for (int p = 0; p < m; p++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (a[i][j] > a[k][p])
						swap(a[i][j], a[k][p]);
}

void main()
{
	srand(time(NULL));
	char Answer;
	const int MessageCount = 9;
	int i, j;
	//���������
	enum { CHOICE = 3, INPUT_FILENAME, INPUT_DIMENSIONS, INPUT_ELEMENT, FILE_ERROR };
	//��������� 
	char Msg[MessageCount][50] =
	{
		"1. ������� ������ �� ���������� �����\n",
		"2. �������� ������ � ��������� ����\n",
		"3. ����� �� ���������\n",
		"\n ��� �����: ",
		"������� ��� ��������������� �����: ",
		"������� ����������� �������: ",
		"������� �������� �������: ",
		"��������� ��������(��-1/���-2)",
		"���������� ������� ����"
	};
	//������������ ��������� � ����� ���� �� �����
	for (i = 0; i < MessageCount; i++)
	{
		CharToOemA(Msg[i], Msg[i]);
	}
	do
	{
		for (int i = 0; i < 4; i++)
		{
			cout << Msg[i];
		}
		cin >> Answer;

	} while (Answer < '1' || Answer>'3');
	if (Answer == '3')
	{
		return;
	}
	//���������� ��� ����� �����
	char FileName[80];
	//����������� �������
	int M, N;
	char num;
	cout << "\n" << Msg[INPUT_FILENAME];
	cin >> FileName;
	//���� ������ ������ ����� ����, �� ������� ������ �� ���������� ����� �����
	if (Answer == '1')
	{
		//���� ���� � ��������� ������ ��� ���������� ������� ��������� �� ������
		ifstream inF(FileName, ios::in | ios::_Nocreate);
		if (!inF)
		{
			cout << "\n" << Msg[FILE_ERROR];
			return;
		}
		//��������� ����������� �������
		inF >> M;
		inF >> N;

		//��������� �������� ������� �� ����� � ������� �� ����� �� �����
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				inF >> num;
				cout << setw(6) << num;
			}
			cout << "\n";
		}
		inF.close();
	}

	//���� ������ ������ ����� ����, �� ������� ������ �� ���������� ����� �����
	if (Answer == '2')
	{
		//��������� ���� ��� ������.
		// ���� ����� �� ���������� �� ��������� ������� ���
		ofstream outF(FileName, ios::out);
		if (!outF)
		{
			cout << "\n" << Msg[FILE_ERROR];
			return;
		}
		//����������� ����������� ������� � ���������� ������ � ����
		cout << Msg[INPUT_DIMENSIONS];
		cout << "\nM: ";
		cin >> M;
		cout << "\nN: ";
		cin >> N;

		outF << M << " " << N << "\n";
		char** matrix = new char* [M];
		for (int i = 0; i < M; i++)
		{
			matrix[i] = new char[N];
		}
		int answ;
		cout << Msg[7];
		cin >> answ;
		if (answ == 1)
		{
			//����������� �������� ������� � ���������� �� � ����
			char a;
			cout << "����� ������� ������(r-������� , a-����������)" << endl;
			cin >> a;
			if (a == 'a')
			{
				for (i = 0; i < M; i++)
				{
					for (j = 0; j < N; j++)
					{

						(matrix[i][j]) = 65 + rand() % (90 - 65);
					}
				}
			}
			if (a == 'r')
			{
				for (i = 0; i < M; i++)
				{
					for (j = 0; j < N; j++)
					{

						(matrix[i][j]) = 129 + rand() % (90 - 128);
					}
				}
			}

			Sort(matrix, M, N);

			for (i = 0; i < M; i++)
			{
				for (j = 0; j < N; j++)
				{
					outF << matrix[i][j] << " ";

				}
				outF << "\n";
			}

		}
		if (answ == 2)
		{
			cout << Msg[INPUT_ELEMENT];
			//����������� �������� ������� � ���������� �� � ����
			for (i = 0; i < M; i++)
			{
				for (j = 0; j < N; j++)
				{
					cout << "Array[" << i << "]" << "[" << j << "] = ";
					cin >> num;
					outF << num << " ";
				}
				outF << "\n";
			}
			outF.close();
		}
	}

}