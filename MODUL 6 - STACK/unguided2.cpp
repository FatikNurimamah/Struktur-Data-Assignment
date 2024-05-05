#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;


//Fatik Nurimamah
//2311102190


// Fungsi untuk membalikkan urutan kata dan huruf dalam kalimat
string BalikKalimat(string kalimat) {
    stack<string> tumpukan;
    string kata = "";
    string KalimatTerbalik = "";

    // Memisahkan kalimat menjadi kata-kata dan menambahkannya ke dalam tumpukan
    for (char ch : kalimat) {
        if (ch == ' ') {
            // Mengonversi kata menjadi huruf kecil dan menambahkannya ke dalam tumpukan
            for (char &c : kata) {
                c = tolower(c);
            }
            tumpukan.push(kata);
            kata = "";
        } else {
            kata += ch;
        }
    }

    // Mengonversi kata terakhir menjadi huruf kecil dan menambahkannya ke dalam tumpukan
    for (char &c : kata) {
        c = tolower(c);
    }
    tumpukan.push(kata);

    // Membangun kalimat terbalik dengan mengeluarkan kata-kata dari tumpukan
    while (!tumpukan.empty()) {
        string kata = tumpukan.top();
        for (int i = kata.length() - 1; i >= 0; i--) {
            KalimatTerbalik += kata[i];
        }
         KalimatTerbalik += " ";
        tumpukan.pop();
    }

    return KalimatTerbalik;
}

int main() {
    string kalimat;

    cout << "Masukkan tiga kata: ";
    getline(cin, kalimat);

    // Memeriksa apakah kalimat mengandung minimal 3 kata
    int count = 0;
    for (char ch : kalimat) {
        if (ch == ' ') {
            count++;
        }
    }

    if (count >= 2) {
        string  KalimatTerbalik = BalikKalimat(kalimat);
        cout << "\nData stack array: " << endl;
        cout << "Data: " <<  KalimatTerbalik << endl;
    } else {
        cout << "Kalimat tidak mengandung minimal 3 kata." << endl;
    }

    return 0;
}
