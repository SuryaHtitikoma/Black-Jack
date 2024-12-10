#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void generate_kartu(string cards[]) {
    string lambang[] = {"Waru", "Hati", "Wajik", "Keriting"};
    string angka[] = {"As", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan", "Sepuluh", "Jack", "Queen", "King"};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            cards[i * 13 + j] = angka[j] + " " + lambang[i];
        }
    }
}

void shuffle_kartu(string cards[], int n) {
    srand(time(0));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        string temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

int main() {
    const int total_kartu = 52;
    string cards[total_kartu];

    generate_kartu(cards);
    shuffle_kartu(cards, total_kartu);

    for (int i = 0; i < total_kartu; i++) {
        cout << cards[i] << endl;
    }

    return 0;
}
