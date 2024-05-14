#include <iostream>
using namespace std;

// Fatik Nurimamah
// 2311102190

// Node untuk merepresentasikan elemen dalam linked list
struct Node {
    string data;
    Node* next;
};

class Antrian {
private:
    Node* depan; // Node depan (pertama) dalam antrian
    Node* belakang; // Node belakang (terakhir) dalam antrian
    int ukuran; // Ukuran antrian (jumlah elemen)

public:
    // Konstruktor untuk menginisialisasi antrian
    Antrian() {
        depan = nullptr;
        belakang = nullptr;
        ukuran = 0;
    }

    // Method untuk mengecek apakah antrian kosong
    bool kosong() {
        return depan == nullptr;
    }

    // Method untuk menambahkan elemen ke belakang antrian
    void tambahkanAntrian(string data) {
        Node* simpulBaru = new Node();
        simpulBaru->data = data;
        simpulBaru->next = nullptr;
        if (kosong()) {
            depan = simpulBaru;
            belakang = simpulBaru;
        } else {
            belakang->next = simpulBaru;
            belakang = simpulBaru;
        }
        ukuran++;
    }

    // Method untuk menghapus elemen dari depan antrian
    void kurangiAntrian() {
        if (kosong()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* temp = depan;
        depan = depan->next;
        delete temp;
        ukuran--;
    }

    // Method untuk menampilkan seluruh elemen dalam antrian
    void tampilkanAntrian() {
        if (kosong()) {
            cout << "\nAntrian kosong" << endl;
            return;
        }
        cout << "\nData antrian teller:" << endl;
        Node* saatIni = depan;
        int i = 1;
        while (saatIni != nullptr) {
            cout << i << ". " << saatIni->data << endl;
            saatIni = saatIni->next;
            i++;
        }
    }

    // Method untuk mendapatkan jumlah elemen dalam antrian
    int hitungAntrian() {
        return ukuran;
    }

    // Method untuk menghapus semua elemen dalam antrian
    void hapusAntrian() {
        while (!kosong()) {
            kurangiAntrian();
        }
    }
};

int main() {
    Antrian antrianTeller;
    antrianTeller.tambahkanAntrian("Andi");
    antrianTeller.tambahkanAntrian("Maya");
    antrianTeller.tampilkanAntrian();
    cout << "Jumlah antrian = " << antrianTeller.hitungAntrian() << endl;
    antrianTeller.kurangiAntrian();
    antrianTeller.tampilkanAntrian();
    cout << "Jumlah antrian = " << antrianTeller.hitungAntrian() << endl;
    antrianTeller.hapusAntrian();
    antrianTeller.tampilkanAntrian();
    cout << "Jumlah antrian = " << antrianTeller.hitungAntrian() << endl;
    return 0;
}
