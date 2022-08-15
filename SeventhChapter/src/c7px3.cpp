#include <iostream>
#include <random>




namespace Random // captial R to avid conflicts with functions named random()
{
    
    std::random_device rd;
    std::seed_seq ss {rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};

    std::mt19937 mt { ss };

    int get( int min, int max )
    { 
        std::uniform_int_distribution die{ min, max };
        return die(mt);

    }
}


int guessInteger()
{
    int guess{};
    std::cin >> guess;
    return guess;
}

bool playAgain()
{
    while(true)
    {
        std::cout << "Would you like to play again? (y/n)";
        char decision {};
        std::cin >> decision;
        if (decision == 'y')
            return true;
            
        else if (decision == 'n')
            return false;
    }
}

void playHiLo()
{
    int randomInteger { Random::get( 1, 100 ) };
    for (int counter{ 1 }; counter <= 7; ++counter)
    {   
        std::cout << "Guess #" << counter << ": ";
        int guess { guessInteger() };
        if (guess == randomInteger)
        {
            std::cout << "Correct! You win!" << "\n";
            break;
        }
        else if (guess < randomInteger)
        {
            std::cout << "Your guess is too small." << "\n";
        }
        else 
        {
            std::cout << "Your guess is too high." << "\n";
        }
        if (counter == 7)
        {
            std::cout << "Sorry, you lose. The correct number was " << randomInteger << ".\n";
        }
    }

}

int main()
{
    std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is." << "\n";
    bool playing { true };
    while (playing)
    {
        playHiLo();
        playing = playAgain();
    }


    return 0;
}
