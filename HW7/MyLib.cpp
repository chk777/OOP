#include"MyLib.h"

namespace myLib
{
	std::string getUserInputTxt()
	{
		while (true)
		{
			std::string input;
			cin >> input;
			if (cin.fail())
			{
				cout << "Input error please try again: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return input;
			}
		}
	}

	unsigned short getUserSelectedTask(unsigned short qtyTask)
	{
		unsigned short taskNumber = 0;
		do
		{
			cout << "Enter the job number from 1 to" << qtyTask << ":" << endl;
			taskNumber = getUserInput<int>(false);
		} while (taskNumber > qtyTask || taskNumber < 1);

		cout << endl;

		return taskNumber;
	}

	void printArr(size_t size, bool NeedCnt, unsigned short* Arr)
	{
		if (NeedCnt) cout << "amount pieces = " << size << endl;
		for (size_t i = 0; i < size; i++)
		{
			cout << Arr[i] << ' ';
		}
		cout << endl;
	}

	void printArr(size_t size, bool NeedCnt, int* Arr)
	{
		if (NeedCnt) cout << "amount pieces = " << size << endl;
		for (size_t i = 0; i < size; i++)
		{
			cout << Arr[i] << ' ';
		}
		cout << endl;
	}

	void printArr(size_t size, bool NeedCnt, int* Arr, size_t medianPos)
	{
		if (NeedCnt) cout << "amount pieces = " << size << endl;
		for (size_t i = 0; i < size; i++)
		{
			if (medianPos > 0 && medianPos == i) cout << "|| ";
			cout << Arr[i] << ' ';
		}
		cout << endl;
	}

	string getNameFileFromUser(unsigned short indexF)
	{
		cout << "Enter name";
		switch (indexF)
		{
		case 0:
			break;
		case 100:
			cout << " finaly";
			break;
		default:
			cout << " " << indexF << " ";
			break;
		}
		cout << " file(without permission): ";
		string s;
		cin >> s;

		return s;
	}
}
