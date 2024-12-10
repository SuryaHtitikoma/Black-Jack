#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    // Inisialisasi deck kartu
    string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    string deck[52];

    // Membuat deck kartu
    int index = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            deck[index++] = ranks[j] + " of " + suits[i];
        }
    }

    // Mengacak deck secara manual
    srand(time(0)); // Seed untuk random
    for (int i = 0; i < 52; ++i) {
        int randomIndex = rand() % 52;
        // Tukar posisi deck[i] dengan deck[randomIndex]
        string temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }

    // Memilih kartu acak untuk ditebak
    string selectedCard = deck[rand() % 52];

    // Fitur menebak kartu
    cout << "Tebak kartu (format: 'Rank of Suit', contoh: 'Ace of Spades'): ";
    string userGuess;
    getline(cin, userGuess);

    // Cek apakah tebakan benar
    if (userGuess == selectedCard) {
        cout << "Tebakanmu benar! Kartunya adalah " << selectedCard << "." << endl;
    } else {
        cout << "Tebakanmu salah. Kartunya adalah " << selectedCard << "." << endl;
    }

    return 0;
}
