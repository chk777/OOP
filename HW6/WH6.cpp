#include<iostream>
#include<windows.h>
#include<vector>
#include<set>
#include"Part1.h"
#include"Part2.h"
#include"Part3.h"

using namespace std;
using namespace myLib;


//. Создать программу, которая считывает целое число типа int.И поставить «защиту от дурака» : если пользователь вводит что
//  - то кроме одного целочисленного значения, нужно вывести сообщение об ошибке и предложить ввести число еще раз.
// Пример неправильных введенных строк :
//rbtrb
//nj34njkn
//1n

void Part1()
{
	cout << "Enter the number \"stupid protection\":" << endl;
	int64_t a = getUserInput<int64_t>(true, true, true);
	cout << "You enter: " << a << endl;
}

//2. Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает буфер.

void Part2()
{
	cout << "Youself endll:" << endl;
	cout << "Привет" << endll;
	cout << "После endll" << endl;
}

//3. Реализовать класс Player, который наследует от класса GenericPlayer.У этого класса будет 4 метода:
//• virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса.Метод спрашивает у пользователя, 
// нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
//• void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
//• void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
//• void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.

//4. Реализовать класс House, который представляет дилера.Этот класс наследует от класса GenericPlayer.У него есть 2 метода:
//• virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта.Если у дилера не больше 16 очков, то он берет еще одну карту.
//• void FlipFirstCard() - метод переворачивает первую карту дилера.

//5. Написать перегрузку оператора вывода для класса Card.Если карта перевернута рубашкой вверх(мы ее не видим), вывести ХХ, если мы ее видим, 
//вывести масть и номинал карты.Также для класса GenericPlayer написать перегрузку оператора вывода, который должен отображать имя игрока и его карты,
//а также общую сумму очков его карт.
void Part3()
{
	cout << "\t\tLets play Blackjack!" << endl << endl;
	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers > 7)
	{
		cout << "how many players are we distributing? (1 - 7): ";
		numPlayers = getUserInput<uint16_t>();
	}
	vector<string> names;
	string name;
	for (int i = 0; i < numPlayers; ++i)
	{
		cout << "Enter your name " << i + 1 << " player: ";
		name = getUserInputTxt();
		names.push_back(name);
	}
	cout << endl;
	// игровой цикл
	Game aGame(names);
	char again = 'y';
	while (again != 'n' && again != 'N')
	{
		aGame.Play();
		cout << "\nDo you want play again? (Y/N): ";
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


