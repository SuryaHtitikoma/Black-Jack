#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    string deck[52];

    int index = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            deck[index++] = ranks[j] + " of " + suits[i];
        }
    }

    srand(time(0));
    for (int i = 0; i < 52; ++i) {
        int randomIndex = rand() % 52;
        string temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
        cout << deck[randomIndex] << endl;
    }

    string selectedCard = deck[rand() % 52];

    cout << "Tebak kartu (format: 'Rank of Suit', contoh: 'Ace of Spades'): ";
    string userGuess;
    getline(cin, userGuess);

    if (userGuess == selectedCard) {
        cout << "Tebakanmu benar! Kartunya adalah " << selectedCard << "." << endl;
    } else {
        cout << "Tebakanmu salah. Kartunya adalah " << selectedCard << "." << endl;
    }

    return 0;
}
