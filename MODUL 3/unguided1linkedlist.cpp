#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string nama;
    int usia;
    Node* next;
};

// Deklarasi Kelas SingleLinkedList
class SingleLinkedList {
public:
    Node* head;
    SingleLinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambah data di depan linked list
    void insertDepan(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk menambah data di belakang linked list
    void insertBelakang(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Fungsi untuk menambah data di tengah linked list
    void insertTengah(string nama, int usia, string namaSebelumnya) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        Node* temp = head;
        while (temp != nullptr && temp->nama != namaSebelumnya) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Data " << namaSebelumnya << " tidak ditemukan!" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Fungsi untuk menghapus data berdasarkan nama
    void DeleteData(string nama) {
        Node* temp = head;
        Node* prev = nullptr;
        if (temp != nullptr && temp->nama == nama) {
            head = temp->next;
            delete temp;
            return;
        }
        while (temp != nullptr && temp->nama != nama) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Data " << nama << " tidak ditemukan!" << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    // Fungsi untuk mengubah data berdasarkan nama
    void ChangeData(string nama, string NewName, int NewAge) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != nama) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Data " << nama << " tidak ditemukan!" << endl;
            return;
        }
        temp->nama = NewName;
        temp->usia = NewAge;
    }

    // Fungsi untuk menampilkan seluruh data
    void ShowData() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nama << " " << temp->usia << endl;
            temp = temp->next;
        }
    }
};

int main() {
    // Inisialisasi SingleLinkedList
    SingleLinkedList list;

    // Data pertama (nama dan usia Anda)
    string namaAnda;
    int usiaAnda;
    cout << "Masukkan Nama Anda: ";
    cin >> namaAnda;
    cout << "Masukkan Usia Anda: ";
    cin >> usiaAnda;
    list.insertDepan(namaAnda, usiaAnda);

    // Data-data lain sesuai permintaan
    list.insertBelakang("John", 19);
    list.insertBelakang("Jane", 20);
    list.insertBelakang("Michael", 18);
    list.insertBelakang("Yusuke", 19);
    list.insertBelakang("Akechi", 20);
    list.insertBelakang("Hoshino", 18);
    list.insertBelakang("Karin", 18);

    // Hapus data Akechi
    list.DeleteData("Akechi");

    // Tambahkan data Futaba di antara John dan Jane
    list.insertTengah("Futaba", 18, "John");

    // Tambahkan data Igor di awal
    list.insertDepan("Igor", 20);

    // Ubah data Michael menjadi Reyn 18
    list.ChangeData("Michael", "Reyn", 18);

    // Tampilkan seluruh data
    cout << "Seluruh data:" << endl;
    list.ShowData();

    return 0;
}
