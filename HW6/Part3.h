#pragma once
#include <type_traits>
#include<string>
#include<vector>
#include<ostream>


class GenericPlayer;

enum class Rank
{

	ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
	JACK, QUEEN, KING,
	first = ACE,
	last = KING
};

enum class Suit
{
	CLUBS = 1,	
	DIAMONDS,	
	HEARTS,		
	SPADES,		
	first = CLUBS,
	last = SPADES
};

class Card
{
public:
	Card(Rank r = Rank::ACE, Suit s = Suit::SPADES, bool ifu = true);

	void SetValue(Rank den, Suit suit);

	Rank GetRank() { return rank; };
	Suit GetSuit() { return suit; };
	void Flip() { isFaceUp = !isFaceUp; };
	uint16_t GetValue() const;

	friend std::ostream& operator<<(std::ostream& os, const Card& aCard);

private:
	Rank rank;
	Suit suit;
	bool isFaceUp;
	

};

std::ostream& operator<<(std::ostream& os, const Card& aCard);

class Hand
{
public:
	Hand();
	virtual ~Hand();

	void Add(Card* pCard);		//��������� ����� � ����. ��������� ��������� �� ������ ���� �ard � ������ cards
	void Clear();				//������� ���� �� ����. ������� ��� ��������� �� ������� cards, �������� ��� ��������� � ���� ������� � ����
	uint16_t GetTotal() const;	//���������� ����� ����� ���� ����, ���������� ���� �������� 1 ��� 11 � ����������� �� ��������

protected:
	std::vector<Card*> cards;
};

class Deck : public Hand
{
public:
	Deck();

	void Populate();		//������� ����������� ������ �� 52 ����
	void Shuffle();			//������ �����
	void Deal(Hand& aHand); //������� � ���� ���� �����
	void AddltionalCards(GenericPlayer& aGenerlcPlayer); //������� ������ �������������� ����� �� ��� ���, ���� �� ����� � ����� �� ��������

	Card GetCard(uint16_t number);
	bool CheckIsStayedCard(uint16_t number);

private:
	uint16_t numberOfCards = (int)Suit::last * (int)Rank::last;
	Card cards[(int)Suit::last][(int)Rank::last]{};
};

enum class Chip
{
	White = 1,
	Red = 5,
	Blue = 10,
	Green = 25,
	Black = 100,
	Magenta = 500,
	Orange = 1000,

	count = 7
};

class ChipsOnHand
{
public:

private:
	Chip chips[(int)Chip::count]{};
};

class GenericPlayer : public Hand
{
public:
	GenericPlayer(const std::string& name = "");
	virtual ~GenericPlayer() = default;

	// ����������, ����� �� ����� ���������� ����� �����
	virtual bool IsHitting() const = 0;
	// ���������� ��������, ���� � ������ �������
	bool IsBoosted() const;
	// ���������, ��� ����� ����� �������
	void Bust() const;

	friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

protected:
	std::string name;

};

std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

class Player : public GenericPlayer
{
public:
	Player(const std::string& name = "");
	virtual ~Player() = default;

	//���������� � ������������, ����� �� ��� ��� ���� �����
	virtual bool IsHitting() const override;
	void Win() const;
	void Lose() const;
	//������ ������
	void Push() const;
private:

};

class House : public GenericPlayer
{
public:
	House(const std::string& name = "House");
	virtual ~House() = default;

	//���������, ����� �� ������� ��� ���� �����
	virtual bool IsHitting() const override;
	void FlipFirstCard();
private:


};


class GameEntity
{
public:

private:
	std::string name;
	
};


class Game
{
public:
	Game(const std::vector<std::string>& names);
	void Play();

private:
	Deck deck;
	House house;
	std::vector<Player> players;
};

