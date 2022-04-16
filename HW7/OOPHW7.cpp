#include<iosfwd>
#include<windows.h>
#include<memory>
#include<ctime>
#include"MyLib.h"
#include"Part1.h"
#include"Part2.h"
#include"Part3.h"

using namespace std;
using namespace myLib;

void Part1()
{
	cout << "Work on Class Date:" << endl << endl;
	time_t now = time(0);
	tm currTime;
	gmtime_s(&currTime, &now);

	auto today = make_unique<Date>(currTime.tm_mday, currTime.tm_mon + 1, currTime.tm_year + 1900);
	unique_ptr<Date> date;

	cout << "Today date: " << endl;
	cout << "Day: " << today.get()->getDay() << endl;
	cout << "Month: " << today.get()->getMonth() << endl;
	cout << "Year: " << today.get()->getYear() << endl << endl;
	cout << *today << endl;

	cout << "object today: " << (static_cast<bool>(today) ? "NOT null\n" : "null\n");
	cout << "object date: " << (static_cast<bool>(date) ? "NOT null\n" : "null\n");
	cout << "Move object today -> date" << endl;
	date = move(today);
	cout << "object today: " << (static_cast<bool>(today) ? "NOT null\n" : "null\n");
	cout << "object date: " << (static_cast<bool>(date) ? "NOT null\n" : "null\n");

}

void Part2()
{
	cout << "Maximum date search:" << endl << endl;
	auto date1 = make_shared<Date>(15, 4, 2022);
	auto date2 = make_shared<Date>(16, 4, 202);
	cout << "date1: " << *date1 << endl;
	cout << "date2: " << *date2 << endl;
	auto dateMax = maxDate(date1, date2);
	cout << "dateMax: " << *dateMax << endl;
	cout << "checking for the existence of objects:" << endl;
	cout << "date1: " << *date1 << endl;
	cout << "date2: " << *date2 << endl << endl;

	cout << "Swap places date1 и date2: " << endl;
	swapDate(date1, date2);
	cout << "date1: " << *date1 << endl;
	cout << "date2: " << *date2 << endl << endl;

	cout << "check that the dateMax is correct: " << endl;
	cout << "dateMax: " << *dateMax << endl;

}

void Part3()
{
	cout << "\t\tLets play Blackjack!" << endl << endl;
	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers > 7)
	{
		cout << "How many players? (1 - 7): ";
		numPlayers = getUserInput<uint16_t>();
	}
	vector<string> names;
	names.reserve(numPlayers);
	string name;
	for (int i = 0; i < numPlayers; ++i)
	{
		cout << "Enter name " << i + 1 << " player: ";
		name = getUserInputTxt();
		names.push_back(name);
	}
	cout << endl;
	// процес игры
	Game aGame(names);
	char again = 'y';
	while (again != 'n' && again != 'N')
	{
		aGame.Play();
		cout << "\nDo you want to play again? (Y/N): ";
		cin >> again;
	}
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
