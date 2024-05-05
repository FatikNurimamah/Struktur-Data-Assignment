#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

//Fatik Nurimamah
//2311102190

bool cekPalindrom(string kalimat) {
    stack<char> tumpukan;
    string kalimatBersih;

    // Membersihkan kalimat dari karakter non-alfanumerik dan mengonversi huruf kecil
    for (char karakter : kalimat) {
        if (isalnum(karakter)) {
            kalimatBersih += tolower(karakter);
        }
    }

    // Menambahkan setengah karakter pertama ke dalam tumpukan
    int setengahPanjangKata = kalimatBersih.length() / 2;
    for (int i = 0; i < setengahPanjangKata; i++) {
        tumpukan.push(kalimatBersih[i]);
    }

    // Membandingkan setengah karakter kedua dengan setengah karakter pertama yang telah di-pop dari tumpukan
    int indeksAwal = (kalimatBersih.length() % 2 == 0) ? setengahPanjangKata : setengahPanjangKata + 1;
    for (int i = indeksAwal; i < kalimatBersih.length(); i++) {
        if (kalimatBersih[i] != tumpukan.top()) {
            return false;
        }
        tumpukan.pop();
    }

    return true;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    if (cekPalindrom(kalimat)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}
