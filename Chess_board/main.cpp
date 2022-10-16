// Домашнее задание "Шахматная доска".
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
	//Шахматная доска
	setlocale(LC_ALL, "Russian");

	int size, i = 0;
	bool white_cell = true;
	cout << "\tПрограмма вывода шахматной доски.";
	cout << "Введите размер шахматной доски: "; cin >> size;

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
			if (white_cell)	cout << char(219) << char(219); //белая клетка - char(219)
			else cout << char(176) << char(176);			//темная клетка - char(176)
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
	//Шахматная доска из звездочек
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
	// Счастливый билет с помощью условия "if_else"
	setlocale(LC_ALL, "Russian");

	char n1, n2, n3, n4, n5, n6;
	cout << "/tПрограмма проверки счастливого билета. (С применением метода \"If - else\")\n";
	cout << "Проверка выполнится после ввода всех 6 цифр номера билета и нажатия \"Enter\"\n";
	cout << "Начальные нули вводить обязательно!\n";
	cout << "Лишние введенные цифры, начиная с седьмой, учитываться не будут.";
	cout << "Введите номер билета (6 цифр): "; cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6;
	if (n1 + n2 + n3 == n4 + n5 + n6)
	{
		cout << "Поздравляем! Ваш билет - СЧАСТЛИВЫЙ!";
	}
	else
	{
		cout << "К сожалению, Ваш билет обычный. Попробуйте в другой раз.";
	}
#endif

#if defined LUCKY_TICKET_WHILE
	// Счастливый билет с помощью цикла "while"
	setlocale(LC_ALL, "Russian");

	int ticket, sum1 = 0, sum2, count = 0;
	cout << "/tПрограмма проверки счастливого билета. (с использованием метода \"While\")\n";
	cout << "Проверка выполнится после ввода всех 6 цифр номера билета и нажатия \"Enter\"\n";
	cout << "При вводе лишних цифр будет предупреждение.\n";
	cout << "При вводе меньшего количества цифр недостающие будут считаться начальными нулями.";
	cout << "Введите номер билета (6 цифр): "; cin >> ticket;
	if (ticket > 999999)
	{
		cout << "ПРЕДУПРЕЖДЕНИЕ! В билете должно быть только 6 цифр. Вы ввели лишние цифры.";
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
		cout << "ПОЗДРАВЛЯЕМ! Ваш билет СЧАСТЛИВЫЙ.";
	}
	else
	{
		cout << "К сожалению, Ваш билет обычный. Попробуйте в другой раз.";
	}

#endif

#if defined PALINDROM
	//Палиндром
	setlocale(LC_ALL, "Russian");

	int input, number, output = 0;
	cout << "введите число, которое нужно проверить на ПАЛИНДРОМ: "; cin >> input;
	number = input;
	while (number > 0)
	{
		output = output * 10 + number % 10;
		number /= 10;
	}
	cout << "Вы ввели: " << input << " обратная запись этого числа: " << output << endl;
	if (input == output)
	{
		cout << "Число является ПАЛИНДРОМОМ.";
	}
	else
	{
		cout << "Число НЕ является палиндромом.";
	}
#endif

#if defined FACTORIAL_RECOURSE
	// Факториал рекурсивный (повторяю код из одного из старых занятий)
	setlocale(LC_ALL, "Russian");
	cout << "Задача 2 \"Факториал числа\" вариант 2\n";
	short number, number_in;
	long long factorial = 1;
	long double factorial_big = 1;
	cout << "Введите число, факториал которого требуется найти: ";
	cin >> number;
	number_in = number;
	if (number < 0)
	{
		cout << "\nФакториал отрицательного числа не может быть определён.\n";
	}
	else
	{
		if (number > 20)
			while (number != 0)
				factorial_big *= number--;
		else
			while (number != 0)
				factorial *= number--;
		cout << "\nФакториал числа " << number_in << " равен: ";
		number_in > 20 ? cout << factorial_big : cout << factorial;
		cout << ".\n";
	}
#endif

#if defined BINARY_CODE
	// Перевод десятичного числа в двоичное
	setlocale(LC_ALL, "Russian");

	int input, output = 0, input_source, size2 = 2, digit = 1;
	cout << "Введите десятичное число, которое требуется преобразовать в двоичное: "; cin >> input_source;
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
	cout << "Число " << input_source << " в двоичном представлении выглядит так: " << output << ".\n";
#endif

#if defined TASK_0
	/* Вывести в консоль фигуры, представленные ниже
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
	/* Вывести в консоль фигуры, представленные ниже
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
	/* Вывести в консоль фигуры, представленные ниже
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
	/* Вывести в консоль фигуры, представленные ниже
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
	/* Вывести в консоль фигуры, представленные ниже
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
	/* Вывести в консоль фигуры, представленные ниже
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