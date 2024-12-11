#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void generate_kartu(string cards[]){
    string lambang[] = {"Waru", "Hati", "Wajik", "Keriting"};
    string angka[] = {"As", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan", "Sepuluh", "Jack", "Queen", "King"};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            cards[i*13+j] = (angka[j] + " " + lambang[i]);
        }
    }
}

int hitungNilaiKartu(string kartu) {
    string kartuskor[] = {"As", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan", "Sepuluh", "Jack", "Queen", "King"};
    int skor[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

    for (int i = 0; i < 13; i++) {
        if (kartu.substr(0, kartuskor[i].length()) == kartuskor[i]) {
            return skor[i];
        }
    }
    return 0;
}

void acakKartu(string cards[]) {
    srand(time(0));
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        string temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

int main() {
    string deck[52];
    generate_kartu(deck);
    acakKartu(deck);

    vector<string> kartuPemain;
    vector<string> kartuDealer;
    int indexKartu = 0;

    kartuPemain.push_back(deck[indexKartu++]);
    kartuDealer.push_back(deck[indexKartu++]);
    kartuPemain.push_back(deck[indexKartu++]);
    kartuDealer.push_back(deck[indexKartu++]);

    int nilaiPemain = hitungNilaiKartu(kartuPemain[0]) + hitungNilaiKartu(kartuPemain[1]);
    int nilaiDealer = hitungNilaiKartu(kartuDealer[0]) + hitungNilaiKartu(kartuDealer[1]);

    cout << "Kartu Pemain:" << endl;
    for (const auto& kartu : kartuPemain) {
        cout << kartu << endl;
    }
    cout << "Total Nilai Pemain: " << nilaiPemain << endl;

    cout << "\nKartu Dealer:" << endl;
    cout << kartuDealer[0] << endl;
    cout << "[Kartu Tertutup]" << endl;

    char pilihan;
    while (true) {
        cout << "\nPilih (H)it atau (S)tand: ";
        cin >> pilihan;

        if (pilihan == 'H' || pilihan == 'h') {
            kartuPemain.push_back(deck[indexKartu++]);
            nilaiPemain += hitungNilaiKartu(kartuPemain.back());

            cout << "Kartu baru: " << kartuPemain.back() << endl;
            cout << "Total Nilai Pemain: " << nilaiPemain << endl;

            if (nilaiPemain > 21) {
                cout << "BUST! Anda kalah." << endl;
                return 0;
            }
        } else if (pilihan == 'S' || pilihan == 's') {
            break;
        }
    }

    cout << "\nKartu Dealer:" << endl;
    for (const auto& kartu : kartuDealer) {
        cout << kartu << endl;
    }
    cout << "Total Nilai Dealer: " << nilaiDealer << endl;

    while (nilaiDealer < 17) {
        kartuDealer.push_back(deck[indexKartu++]);
        nilaiDealer += hitungNilaiKartu(kartuDealer.back());
        cout << "Dealer mengambil kartu: " << kartuDealer.back() << endl;
        cout << "Total Nilai Dealer: " << nilaiDealer << endl;
    }

    if (nilaiDealer > 21) {
        cout << "\nDealer BUST! Anda menang!" << endl;
    } else if (nilaiPemain > nilaiDealer) {
        cout << "\nAnda menang!" << endl;
    } else if (nilaiPemain < nilaiDealer) {
        cout << "\nDealer menang!" << endl;
    } else {
        cout << "\nSeri!" << endl;
    }

    return 0;
}