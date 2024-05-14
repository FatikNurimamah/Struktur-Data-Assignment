#include <iostream>
using namespace std;

// Fatik Nurimamah
// 2311102190

// Node untuk merepresentasikan elemen dalam linked list
struct Node {
    string nama;
    string nim;
    Node* next;
};

class AntrianMahasiswa {
private:
    Node* depan; // Node depan (pertama) dalam antrian
    Node* belakang; // Node belakang (terakhir) dalam antrian
    int ukuran; // Ukuran antrian (jumlah elemen)

public:
    // Konstruktor untuk menginisialisasi antrian
    AntrianMahasiswa() {
        depan = nullptr;
        belakang = nullptr;
        ukuran = 0;
    }

    // Method untuk mengecek apakah antrian kosong
    bool kosong() {
        return depan == nullptr;
    }

    // Method untuk menambahkan elemen ke belakang antrian
   void tambahkanAntrian(string nama, string nim) {
        Node* simpulBaru = new Node();
        simpulBaru->nama = nama;
        simpulBaru->nim = nim;
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
        cout << "\nData antrian mahasiswa:" << endl;
        Node* saatIni = depan;
        int i = 1;
        while (saatIni != nullptr) {
            cout << i << ". Nama: " << saatIni->nama << ", NIM: " << saatIni->nim <<endl;
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
    AntrianMahasiswa antrian;
    antrian.tambahkanAntrian("Andi", "12345");
    antrian.tambahkanAntrian("Maya", "67890");
    antrian.tampilkanAntrian();
    cout << "Jumlah antrian = " << antrian.hitungAntrian() << endl;
    antrian.kurangiAntrian();
    antrian.tampilkanAntrian();
    cout << "Jumlah antrian = " << antrian.hitungAntrian() << endl;
    antrian.hapusAntrian();
    antrian.tampilkanAntrian();
    cout << "Jumlah antrian = " << antrian.hitungAntrian() << endl;
    return 0;
}
