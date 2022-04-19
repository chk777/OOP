#include<iosfwd>
#include<windows.h>
#include<memory>
#include<ctime>
#include"Part1.h"
#include"Part2.h"
#include"Part3.h"
#include"MyLib.h"

using namespace std;
using namespace myLib;

void Part1()
{
	int64_t a, b;
	double_t aa, bb, result;
	try
	{
		cout << "enter integer number a = ";
		a = getUserInput<int64_t>(true, true);
		cout << "enter integer number b = ";
		b = getUserInput<int64_t>(true, true);
		result = div<int64_t>(a, b);
		cout << a << " / " << b << " = " << result << endl;

		cout << "enter fractional number a = ";
		aa = getUserInput<double_t>(true, true);
		cout << "enter fractional number b = ";
		bb = getUserInput<double_t>(true, true);
		result = div<double_t>(aa, bb);
		cout << aa << " / " << bb << " = " << result << endl;
	}
	catch (const std::exception& exception)
	{
		cerr << "occurred error: " << exception.what() << endl;
	}
	catch (...)
	{
		cerr << "occurred unknown error!" << endl;
	}
}

void Part2()
{
	Bar bar;
	double_t n;
	try
	{
		do
		{
			cout << "Enter n = ";
			n = getUserInput<double_t>(true, true);
			bar.set(n);
			cout << endl;
		} while (n != 0);
	}
	catch (const Ex& ex)
	{
		cerr << "occurred error: Ex have parameter (" << ex.what() << ")" << endl;
	}
	catch (...)
	{
		cerr << "occurred unknown error!" << endl;
	}
}

void Part3()
{
	system("cls");
	Robot rb;
	char c;
	do
	{
		rb.print();
		cout << endl << "use keys to move WASD, for exit Q" << endl;
		c = getUserInputKey();
		system("cls");
		try
		{
			switch (c)
			{
			case 'd':
			case 'D':
				rb.move(Direction::RIGHT);
				break;
			case 'a':
			case 'A':
				rb.move(Direction::LEFT);
				break;
			case 'w':
			case 'W':
				rb.move(Direction::UP);
				break;
			case 's':
			case 'S':
				rb.move(Direction::DOWN);
				break;
			case 'q':
			case 'Q':
				break;
			default:
				rb.move(Direction::other);
			}
		}
		catch (const OffTheField& ex)
		{
			cerr << "Attempt to go out of bounds! " << ex.what() << endl;
		}
		catch (const IllegalCommand& ex)
		{
			cerr << "Unknown direction indicated!" << endl;
		}
		catch (...)
		{
			cerr << "occurred unknown error!" << endl;
		}
	} while (c != 'q' && c != 'Q');


}


int main()
{
	unsigned short taskNumber = 0;
	while (true)
	{
		taskNumber = getUserSelectedTask(3);
		switch (taskNumber)
		{
		case 1: Part1();
			break;
		case 2: Part2();
			break;
		case 3: Part3();
			break;
		}
		cout << endl;
	}
}
