// �������� ������� "��������� �����".
#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

void main()
{
//#define ASCII
//#define CHESS_BOARD
#define CHESS_BOARD_BY_STARS
//#define LUCKY_TICKET_IF_ELSE
//#define LUCKY_TICKET_WHILE
//#define PALINDROM
//#define FACTORIAL_RECOURSE
//#define BINARY_CODE
//#define TASK_0
//#define TASK_1
//#define TASK_2
//#define TASK_3
//#define TASK_4
//#define TASK_5

#if defined ASCII
	//ASCII-table
	int i = 0;
	while (i < 256)
	{
		cout << i << '-' << char(i) << endl;
		i++;
	}
#endif

#if defined CHESS_BOARD
	//��������� �����
	setlocale(LC_ALL, "Russian");

	int size, i = 0;
	bool white_cell = true;
	cout << "\t��������� ������ ��������� �����.";
	cout << "������� ������ ��������� �����: "; cin >> size;

	// 1 raw
	cout << '\t' << char(201);
	for (int i = 1; i < (size + 2); i++) cout << char(205) << char(205);
	cout << char(205) << char(187) << endl;
	// 2 raw
	cout << '\t' << char(186) << ' ';
	for (int i = 1; i < (size + 1); i++) cout << ' ' << char(64 + i);
	cout << "  " << char(186) << endl;
	// raws
	for (int i = 0; i < size; i++)
	{
		cout << '\t' << char(186) << size - i << ' ';
		for (int j = 1; j <= size; j++)
		{
			if (white_cell)	cout << char(219) << char(219); //����� ������ - char(219)
			else cout << char(176) << char(176);			//������ ������ - char(176)
			white_cell = !white_cell;
		}
		cout << " " << char(186);
		cout << endl;
		if (!(size % 2)) white_cell = !white_cell;
	}
	// last raw
	cout << '\t' << char(200);
	for (int i = 1; i < (size + 2); i++) cout << char(205) << char(205);
	cout << char(205) << char(188) << endl;
#endif

#if defined CHESS_BOARD_BY_STARS
	//��������� ����� �� ���������
	int size, sizeCell, i = 0;
	char dark = '*', light = ' ', cell;//char 219 - light, ' ' - dark
	cout << "\tChess board by stars.\n";
	cout << "Input size of board: "; cin >> size;
	cell = (size % 2) ? light : dark;
	sizeCell = size;
	// 1 raw - frame
	cout << char(201);
	for (int i = 0; i < (2 * sizeCell * size + 2); i++) cout << char(205);
	cout << char(187) << endl;
	// 2 raw
	cout << char(186) << ' ';
	//(j == size / 2) ? cout << (size - i) : cout << ' ';
	for (int i = 0; i < (2 * sizeCell * size + 1); i++)
	{
		((i) % (2 * size) == sizeCell) ? cout << char(65 + i /(2 * size)) : cout << ' ';
	}
	cout << char(186) << endl;
	// raws of cells
	for (int i = 0; i < size; i++) //all board
	{
		for (int j = 0; j < size; j++) // raws of cells
		{
			cout << char(186);
			(j == size / 2) ? cout << (size - i) : cout << ' ';
			for (int m = 0; m < sizeCell; m++) //raws of pixels
			{
				for (int k = 0; k < sizeCell; k++) // pixels of cells
				{
					cout << cell << cell;
				}
				cell = (cell == dark) ? light : dark;
			}
		cout << " " << char(186);
		cout << endl;
		cell = ((sizeCell % 2 && cell == dark) || (!(sizeCell % 2) && cell == light)) ? light : dark;
		}
		cell = ((size % 2 && cell == light) || (!(size % 2) && cell == light)) ? dark : light;
	}
	// last raw - frame
	cout << char(200);
	for (int i = 0; i < (2 * sizeCell * size + 2); i++) cout << char(205);
	cout << char(188) << endl;
#endif

#if defined LUCKY_TICKET_IF_ELSE
	// ���������� ����� � ������� ������� "if_else"
	setlocale(LC_ALL, "Russian");

	char n1, n2, n3, n4, n5, n6;
	cout << "/t��������� �������� ����������� ������. (� ����������� ������ \"If - else\")\n";
	cout << "�������� ���������� ����� ����� ���� 6 ���� ������ ������ � ������� \"Enter\"\n";
	cout << "��������� ���� ������� �����������!\n";
	cout << "������ ��������� �����, ������� � �������, ����������� �� �����.";
	cout << "������� ����� ������ (6 ����): "; cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6;
	if (n1 + n2 + n3 == n4 + n5 + n6)
	{
		cout << "�����������! ��� ����� - ����������!";
	}
	else
	{
		cout << "� ���������, ��� ����� �������. ���������� � ������ ���.";
	}
#endif

#if defined LUCKY_TICKET_WHILE
	// ���������� ����� � ������� ����� "while"
	setlocale(LC_ALL, "Russian");

	int ticket, sum1 = 0, sum2, count = 0;
	cout << "/t��������� �������� ����������� ������. (� �������������� ������ \"While\")\n";
	cout << "�������� ���������� ����� ����� ���� 6 ���� ������ ������ � ������� \"Enter\"\n";
	cout << "��� ����� ������ ���� ����� ��������������.\n";
	cout << "��� ����� �������� ���������� ���� ����������� ����� ��������� ���������� ������.";
	cout << "������� ����� ������ (6 ����): "; cin >> ticket;
	if (ticket > 999999)
	{
		cout << "��������������! � ������ ������ ���� ������ 6 ����. �� ����� ������ �����.";
	}
	while (ticket > 0 && ticket < 1000000)
	{
		sum1 += ticket % 10;
		ticket /= 10;
		count++;
		if (count == 3)
		{
			sum2 = sum1;
			sum1 = 0;
		}
	}
	if (sum1 == sum2)
	{
		cout << "�����������! ��� ����� ����������.";
	}
	else
	{
		cout << "� ���������, ��� ����� �������. ���������� � ������ ���.";
	}

#endif

#if defined PALINDROM
	//���������
	setlocale(LC_ALL, "Russian");

	int input, number, output = 0;
	cout << "������� �����, ������� ����� ��������� �� ���������: "; cin >> input;
	number = input;
	while (number > 0)
	{
		output = output * 10 + number % 10;
		number /= 10;
	}
	cout << "�� �����: " << input << " �������� ������ ����� �����: " << output << endl;
	if (input == output)
	{
		cout << "����� �������� �����������.";
	}
	else
	{
		cout << "����� �� �������� �����������.";
	}
#endif

#if defined FACTORIAL_RECOURSE
	// ��������� ����������� (�������� ��� �� ������ �� ������ �������)
	setlocale(LC_ALL, "Russian");
	cout << "������ 2 \"��������� �����\" ������� 2\n";
	short number, number_in;
	long long factorial = 1;
	long double factorial_big = 1;
	cout << "������� �����, ��������� �������� ��������� �����: ";
	cin >> number;
	number_in = number;
	if (number < 0)
	{
		cout << "\n��������� �������������� ����� �� ����� ���� ��������.\n";
	}
	else
	{
		if (number > 20)
			while (number != 0)
				factorial_big *= number--;
		else
			while (number != 0)
				factorial *= number--;
		cout << "\n��������� ����� " << number_in << " �����: ";
		number_in > 20 ? cout << factorial_big : cout << factorial;
		cout << ".\n";
	}
#endif

#if defined BINARY_CODE
	// ������� ����������� ����� � ��������
	setlocale(LC_ALL, "Russian");

	int input, output = 0, input_source, size2 = 2, digit = 1;
	cout << "������� ���������� �����, ������� ��������� ������������� � ��������: "; cin >> input_source;
	input = input_source;
	while (input / size2 > 0)
	{
		output = input % size2 * digit + output;
		input /= size2;
		digit *= 10;
	}
	output = input % size2 * digit + output;
	input /= size2;
	digit *= 10;
	cout << "����� " << input_source << " � �������� ������������� �������� ���: " << output << ".\n";
#endif

#if defined TASK_0
	/* ������� � ������� ������, �������������� ����
	*****
	*****
	*****
	*****
	*****
	*/
	int size = 5;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << '*';
		}
		cout << endl;
	}

#endif

#if defined TASK_1
	/* ������� � ������� ������, �������������� ����
	*
	**
	***
	****
	*****
	*/
	int size = 5;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << '*';
		}
		cout << endl;
	}
#endif

#if defined TASK_2
	/* ������� � ������� ������, �������������� ����
	*****
	****
	***
	**
	*
	*/
	int size = 5;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			cout << '*';
		}
		cout << endl;
	}
#endif

#if defined TASK_3
	/* ������� � ������� ������, �������������� ����
	*****
	 ****
	  ***
	   **
		*
	*/
	int size = 5;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << ' ';
		}
		for (int k = i; k < size; k++)
		{
			cout << '*';
		}
		cout << endl;
	}
#endif

#if defined TASK_4
	/* ������� � ������� ������, �������������� ����
		*
	   **
	  ***
	 ****
	*****
	*/
	int size = 5;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			cout << ' ';
		}
		for (int k = size - i; k <= size; k++)
		{
			cout << '*';
		}
		cout << endl;
	}
#endif

#if defined TASK_5
	/* ������� � ������� ������, �������������� ����
		/\
	   /  \
	  /    \
	 /      \
	/        \
	\        /
	 \      /
	  \    /
	   \  /
		\/
	*/
	int size = 5;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			cout << ' ';
		}
		cout << '/';
		for (int k = 0; k < 2 * i; k++)
		{
			cout << ' ';
		}
		cout << '\\' << endl;
	}
	for (int l = 0; l < size; l++)
	{
		for (int m = 0; m < l; m++)
		{
			cout << ' ';
		}
		cout << '\\';
		for (int n = 0; n < 2 * (size - l - 1); n++)
		{
			cout << ' ';
		}
		cout << '/' << endl;
	}
#endif
}