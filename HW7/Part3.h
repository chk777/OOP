#pragma once
#include <type_traits>
#include<string>
#include<vector>
#include<ostream>
#include<algorithm>


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

	
	void Add(Card* pCard); //Добавляет карту в руку. Ставит указатель на объект типа Сard
	
	void Clear(); //Очищает руку от карт. Удаляя все указатели.
	
	uint16_t GetTotal() const; //Сумма карт у игрока. При сумме туз считается или 1 или 11 в зависимости о  расклада

protected:
	std::vector<Card*> cards;
};

class Deck : public Hand
{
public:
	Deck();
	virtual ~Deck() = default;

	void Populate(); 	//Создает колоду из 52 карт

	void Shuffle(); 	//Тасует карты

	void Deal(Hand& aHand); //Раздает в руку одну карту

	void AdditionalCards(GenericPlayer& aGenerlcPlayer); //Раздает игроку дополнительные карты до тех пор, пока он может и хочет их получать

};

//Очки для комбинаций в игре
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

//Игроки
class GenericPlayer : public Hand
{
public:
	GenericPlayer(const std::string& name = "");
	virtual ~GenericPlayer() = default;

	virtual bool IsHitting() const = 0; 	// хочет ли игрок продолжать брать карты

	bool IsBoosted() const; 	//показывает если перебор

	void Bust() const; 	//объявляет, что перебор

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

	//спрашивает у пользователя, нужна ли ему еще одна карта
	virtual bool IsHitting() const override;
	void Win() const; //Выиграл
	void Lose() const; //Проиграл
	void Push() const; //Ничья
private:

};

class House : public GenericPlayer
{
public:
	House(const std::string& name = "House");
	virtual ~House() = default;

	//проверяет, нужна ли диллеру еще одна карта
	virtual bool IsHitting() const override; 
	void FlipFirstCard();
private:


};

//игра
class Game
{
public:
	Game(const std::vector<std::string>& names);
	~Game() = default;

	void Play();

private:
	Deck deck;
	House house;
	std::vector<Player> players;
};
