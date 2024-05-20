#include <iostream>
#include <string>

using namespace std;

// Fatik Nurimamah
// 2311102190

// Fungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat
int countVokal(const string& kalimat) {
    int vokalCount = 0;
    // Daftar huruf vokal
    string vokal = "A,I,U,E,O,a,i,u,e,o";
    for (char ch : kalimat) {
        if (vokal.find(ch) != string::npos) {
            vokalCount++;
        }
    }
    return vokalCount;
}

int main() {
    // Meminta pengguna untuk memasukkan kalimat
    string kalimat;
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    // Menghitung jumlah huruf vokal dalam kalimat
    int vokalCount = countVokal(kalimat);

    // Menampilkan hasilnya
    cout << "Jumlah huruf vokal dalam kalimat \"" << kalimat << "\" adalah : " << vokalCount << endl;

    return 0;
}
