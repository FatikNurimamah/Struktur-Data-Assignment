#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string nama;
    int harga;
    Node* prev;
    Node* next;
};

// Deklarasi Kelas DoubleLinkedList
class DoubleLinkedList {
public:
    Node* head;
    Node* tail;
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk menambah data di belakang linked list
    void insertBelakang(string nama, int harga) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->harga = harga;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = tail = newNode;
            newNode->prev = nullptr;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Fungsi untuk menambah data di tengah / di urutan tertentu
    void insertTengah(string nama, int harga, string namaSebelumnya) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->harga = harga;
        Node* temp = head;
        while (temp != nullptr && temp->nama != namaSebelumnya) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Produk " << namaSebelumnya << " tidak ditemukan!" << endl;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        else {
            tail = newNode;
        }
        temp->next = newNode;
    }

    // Fungsi untuk menghapus data berdasarkan nama produk
    void hapusData(string nama) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != nama) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Produk " << nama << " tidak ditemukan!" << endl;
            return;
        }
        if (temp == head) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
        }
        else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    // Fungsi untuk mengubah data berdasarkan nama produk
    void updateData(string nama, string newName, int newPrice) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != nama) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Produk " << nama << " tidak ditemukan!" << endl;
            return;
        }
        temp->nama = newName;
        temp->harga = newPrice;
    }

    // Fungsi untuk menampilkan seluruh data dalam format tabel
    void ShowData() {
    Node* temp = head;
    cout << "==============================" << endl;
    cout << "| " << setw(14) << left << "Nama Produk" << " | " << setw(9) << left << "Harga" << " |" << endl;
    cout << "==============================" << endl;
    while (temp != nullptr) {
        cout << "| " << setw(14) << left << temp->nama << " | " << setw(9) << left << temp->harga << " |" << endl;
        temp = temp->next;
    }
    cout << "==============================" << endl;
    cout << endl;
}

    // Fungsi untuk menghapus semua data
    void hapusSemuaData() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
    }
};

int main() {
    // Inisialisasi DoubleLinkedList
    DoubleLinkedList list;

    // Menambahkan data awal
    list.insertBelakang("Originote", 60000);
    list.insertBelakang("Somethinc", 150000);
    list.insertBelakang("Skintific", 100000);
    list.insertBelakang("Wardah", 50000);
    list.insertBelakang("Hanasui", 30000);

    // Case:
    // 1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific
    list.insertTengah("Azarine", 65000, "Somethinc");

    // 2. Hapus produk Wardah
    list.hapusData("Wardah");

    // 3. Update produk Hanasui menjadi Cleora dengan harga 55000
    list.updateData("Hanasui", "Cleora", 55000);

    // Menampilkan menu
    while (true) {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;

        int pilih;
        cout << "\nMasukkan pilihan Anda: ";
        cin >> pilih;

        switch (pilih) {
            case 1: {
                string namaProduk;
                int hargaProduk;
                cout << "Masukkan nama produk: ";
                cin >> namaProduk;
                cout << "Masukkan harga produk: ";
                cin >> hargaProduk;
                list.insertBelakang(namaProduk, hargaProduk);
                break;
            }
            case 2: {
                string namaProduk;
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> namaProduk;
                list.hapusData(namaProduk);
                break;
            }
            case 3: {
                string namaProduk;
                string newName;
                int newPrice;
                cout << "Masukkan nama produk yang ingin diupdate: ";
                cin >> namaProduk;
                cout << "Masukkan nama produk baru: ";
                cin >> newName;
                cout << "Masukkan harga produk baru: ";
                cin >> newPrice;
                list.updateData(namaProduk, newName, newPrice);
                break;
            }
            case 4: {
                string namaProduk;
                string namaSebelumnya;
                int hargaProduk;
                cout << "Masukkan nama produk yang ingin ditambahkan: ";
                cin >> namaProduk;
                cout << "Masukkan nama produk yang berada sebelumnya: ";
                cin >> namaSebelumnya;
                cout << "Masukkan harga produk: ";
                cin >> hargaProduk;
                list.insertTengah(namaProduk, hargaProduk, namaSebelumnya);
                break;
            }
            case 5: {
                string namaProduk;
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> namaProduk;
                list.hapusData(namaProduk);
                break;
            }
            case 6: {
                list.hapusSemuaData();
                cout << "Semua data telah dihapus." << endl;
                break;
            }
            case 7: {
                list.ShowData();
                break;
            }
            case 8: {
                cout << "Anda telah keluar dari program." << endl;
                return 0;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
            }
        }
    }

    return 0;
}

