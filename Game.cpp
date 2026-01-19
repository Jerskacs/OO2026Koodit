#include <iostream>
#include "Game.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Game::Game(int max)
{
    maxNumber = max;
    numOfGuesses = 0;
    srand(time(0));
    randomNumber = rand() % maxNumber + 1;

}

Game::~Game() {
}

void Game::play() {
    cout << "Guess between 1 and " << maxNumber << endl;

    do {
        cout << "Type your guess: ";
        cin >> playerGuess;
        numOfGuesses++;

        if (playerGuess < randomNumber)
            cout << "Too small" << endl;
        else if (playerGuess > randomNumber)
            cout << "Too big" << endl;

    } while (playerGuess != randomNumber);

    printGameResult();
}


void Game::printGameResult() {
    cout << "\nCorrect number: " << randomNumber << endl;
    cout << "Amount of guesses: " << numOfGuesses << endl;
}

#include "Game.h"

int main() {
    Game game(100);
    game.play();
    return 0;
}
