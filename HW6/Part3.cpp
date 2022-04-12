#include<iostream>
#include"Part3.h"

Rank operator++(Rank& den) { return den = (Rank)(std::underlying_type<Rank>::type(den) + 1); };
Rank operator*(Rank den) { return den; };
Rank begin(Rank den) { return Rank::first; };
Rank end(Rank den)
{
	Rank de = Rank::last;
	return ++de;
};

Suit operator++(Suit& suit) { return suit = (Suit)(std::underlying_type<Suit>::type(suit) + 1); };
Suit operator*(Suit suit) { return suit; };
Suit begin(Suit suit) { return Suit::first; };
Suit end(Suit suit)
{
	Suit su = Suit::last;
	return ++su;
};


Card::Card(Rank r, Suit s, bool ifu) : suit(s), rank(r), isFaceUp(ifu)//, isStayedInTheDeck{ true }
{};

void Card::SetValue(Rank den, Suit suit)
{
	rank = den;
	this->suit = suit;
};

uint16_t Card::GetValue() const
{
	uint16_t val = 0;
	if (isFaceUp)
	{
		val = std::underlying_type<Rank>::type(rank);
		if (val > 10) val = 10;
	}
	return val;
};

Deck::Deck()
{
	for (const auto& i : Suit())
	{
		for (const auto& j : Rank())
		{
			cards[(int)i - 1][(int)j - 1].SetValue(j, i);
		}
	}
}

Game::Game(const std::vector<std::string>& names)
{
}

void Game::Play()
{
}

Hand::Hand()
{
	cards.reserve(7);
}

Hand::~Hand()
{
	Clear();
}

void Hand::Add(Card* pCard)
{
	cards.push_back(pCard);
}

void Hand::Clear()
{
	for (auto& cr : cards)
	{
		delete cr;
	}
	cards.clear();
}

uint16_t Hand::GetTotal() const
{
	// если карт в руке нет, возвращает значение 0
	if (cards.empty())
	{
		return 0;
	}
	//если первая карта имеет значение 0, то она лежит рубашкой вверх:
	// вернуть значение 0
	if (cards[0]->GetValue() == 0)
	{
		return 0;
	}
	// находит сумму очков всех карт, каждый туз дает 1 очко
	uint16_t total = 0;
	for (const auto& cr : cards)
	{
		total += cr->GetValue();
	}
	// определяет, есть ли туз
	bool containsAce = false;
	for (const auto& cr : cards)
	{
		if (cr->GetValue() == static_cast<uint16_t>(Rank::ACE)) containsAce = true;
	}
	// если есть туз то и сумма маленькая, туз дает 11 очков
	if (containsAce && total <= 11)
	{
		total += 10;
	}
	return total;
}

GenericPlayer::GenericPlayer(const std::string& name) : name(name)
{}

bool GenericPlayer::IsBoosted() const
{
	return (GetTotal() > 21);
}
void GenericPlayer::Bust() const
{
	std::cout << name << " more" << std::endl;
}

House::House(const std::string& name) : GenericPlayer(name)
{}

bool House::IsHitting() const
{
	return (GetTotal() <= 16);
}

void House::FlipFirstCard()
{
	if (!(cards.empty()))
	{
		cards[0]->Flip();
	}
	else
	{
		std::cout << "all cards played!\n";
	}
}

std::ostream& operator<<(std::ostream& os, const Card& aCard)
{
	const std::string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8",
							 "9","10", "J", "Q", "K" };
	const std::string SUITS[] = { "c", "d", "h", "s" };
	if (aCard.isFaceUp)
	{
		os << RANKS[static_cast<uint16_t>(aCard.rank)] << SUITS[static_cast<uint16_t>(aCard.suit)];
	}
	else
	{
		os << "XX";
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer)
{
	os << aGenericPlayer.name << ":\t";
	//std::vector<Card*>::const_iterator pCard;
	if (!aGenericPlayer.cards.empty())
	{
		for (const auto& pCard : aGenericPlayer.cards)
		{
			os << pCard << "\t";
		}
		/*for (pCard = aGenericPlayer.cards.begin();
			pCard != aGenericPlayer.cards.end();
			++pCard)
		{
			os << *(*pCard) << "\t";
		}*/
		if (aGenericPlayer.GetTotal() != 0)
		{
			std::cout << "(" << aGenericPlayer.GetTotal() << ")";
		}
	}
	else
	{
		os << "<empty>";
	}
	return os;
}

Player::Player(const std::string& name) : GenericPlayer(name)
{}

bool Player::IsHitting() const
{
	std::cout << name << ", need another card? (Y/N): ";
	char response;
	std::cin >> response;
	return (response == 'y' || response == 'Y');
}

void Player::Win() const
{
	std::cout << name << " WIN!" << std::endl;
}

void Player::Lose() const
{
	std::cout << name << " LOSE..." << std::endl;
}

void Player::Push() const
{
	std::cout << name << " DRAW " << std::endl;
}