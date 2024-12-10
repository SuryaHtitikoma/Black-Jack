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

    int random_kartu_rahasia = rand() % total_kartu;
    string kartu_rahasia = cards[random_kartu_rahasia];

    cout << "Ada sebuah kartu yang dipilih secara acak. Coba tebak kartu tersebut!" << endl;

    string tebakan_angka, tebakan_lambang;
    while (true) {
        cout << "Masukkan tebakan Anda: ";
        cin >> tebakan_angka >> tebakan_lambang;

        if ((tebakan_angka + " " + tebakan_lambang) == kartu_rahasia) {
            cout << "Selamat! Tebakan Anda benar. Kartu yang dipilih adalah: " << kartu_rahasia << endl;
            break;
        } else {
            cout << "Tebakan Anda salah. Jawaban yang benar adalah: " << kartu_rahasia << endl;
            break;
        }
    }

    return 0;
}
