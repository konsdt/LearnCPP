#include<iostream>
#include<array>
#include<random>
#include<algorithm>

// Question 6

// 13 card ranks

enum class CardRank {
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    Jack,
    Queen,
    King,
    Ace,

    maxRanks
};


enum class CardSuit {
    clubs,
    diamonds,
    hearts,
    spades,

    maxSuits
};


struct Card {
    CardRank rank {};
    CardSuit suit {};
};

void printCard(const Card& card) {
    using enum CardRank;
    using enum CardSuit;

    switch (card.rank)
    {
    case two: std::cout << "2"; break;
    case three: std::cout << "3"; break;
    case four: std::cout << "4"; break;
    case five: std::cout << "5"; break;
    case six: std::cout << "6"; break;
    case seven: std::cout << "7"; break;
    case eight: std::cout << "8"; break;
    case nine: std::cout << "9"; break;
    case ten: std::cout << "10"; break;
    case Jack: std::cout << "J"; break;
    case Queen: std::cout << "Q"; break;
    case King: std::cout << "K"; break;
    case Ace: std::cout << "A"; break;
    default:
        std::cout << "Unknown rank!!" << '\n';
        break;
    }

    switch (card.suit)
    {
    case clubs: std::cout << "C"; break;
    case diamonds: std::cout << "D"; break;
    case hearts: std::cout << "H"; break;
    case spades: std::cout << "S"; break;
    default:
        std::cout << "Unknown suit!!" << '\n'; 
        break;
    }

    std::cout << '\n';

}

std::array<Card, 52> createDeck() 
{
    std::array<Card, 52> card_deck {};
    int array_index {0};
    for (int i{0}; i < 13; ++i)
    {
        for (int j {0}; j < 4; ++j)
        {   
            card_deck[array_index].rank = static_cast<CardRank>(i);
            card_deck[array_index].suit = static_cast<CardSuit>(j);

            ++array_index;
        }
    }
    return card_deck;
}



void shuffleDeck(std::array<Card, 52>& card_deck)
{   
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(card_deck.begin(), card_deck.end(), mt);
}

int getCardValue(const Card& card)
{
    using enum CardRank;
    switch (card.rank)
    {
    case two:
        return 2;
    case three:
        return 3;
    case four:
        return 4;
    case five:
        return 5;
    case six:
        return 6;
    case seven:
        return 7;
    case eight:
        return 8;
    case nine:
        return 9;
    case ten:
    case Jack:
    case Queen:
    case King:
        return 10;
    case Ace:
        return 11;
    default:
        return 0;
    }

}
void printDeck(const std::array<Card, 52>& card_deck)
{
    for (int card {0}; card < 52; ++card)
    {
        printCard(card_deck[card]);
        //std::cout << getCardValue(card_deck[card]) << " ";
    }
        
}

// Question 7: Black Jack
bool playBlackjack(const std::array<Card, 52>& shuffled_deck) {
    int dealer_score {getCardValue(shuffled_deck[0])};
    int player_score {getCardValue(shuffled_deck[1]) + getCardValue(shuffled_deck[2])};
    char answer {};
    size_t current_card {3};
    
    bool stand {false};

    while (not stand) {
        std::cout << "Your score is: " << player_score << '\n';
        std::cout << "Do you want to stand? (Y/N)" << '\n';
        std::cin >> answer;
        if (answer == 'Y') {
            stand = true;
        } else {
            player_score += getCardValue(shuffled_deck[current_card]);
            if (player_score > 21) {
                std::cout << "You lost, you have too many points: " << player_score << '\n';
                return false;
            }
            ++current_card;
        }
            
    };

    while (dealer_score < 17) {
        dealer_score += getCardValue(shuffled_deck[current_card]);
        ++current_card;
    };

    if (dealer_score > 21) {
        std::cout << "You win because the dealer got more than 21 points." << '\n';
        return true;
    } else if (dealer_score < player_score) {
        std::cout << "You win because you got more points than the dealer." << '\n';
        return true;
    } else {
        std::cout << "The dealer wins since he got more or the same amount of points." << '\n';
        return false;
    }

}


int main()
{
   
    //std::cout << static_cast<int>(CardRank::two);
    std::array<Card, 52> card_deck {createDeck()};
    shuffleDeck(card_deck);
    printDeck(card_deck);
    playBlackjack(card_deck);
    return 0;
}