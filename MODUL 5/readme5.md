# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">Fatik Nurimamah (2311102190)</p>

## Dasar Teori

HASH TABLE

Hash  Table adalah Array dengan sel-sel yang ukuranya telah di tentukan dan dapat berisi data atau key yang memiliki  kesamaan  dengan  data.  Namun kita bisa juga bisa mengartikannya sebagai struktur data yang biasa diguankan untuk mengoptimasi pencarian data[1]. Biasanya hash table digunakan untuk mencari record yang sama pada suatu basis data atau tabel dengan sangat cepat[2]. Fungsi hash adalah sebuah fungsi yang dapat digunakan untuk memetakan data berukuran apapun menjadi data dengan ukuran tertentu[2]. Hashing adalah suatu cara untuk mentransformasikan sebuah string menjadi suatu nilai yang  unik dengan panjang tertentu (fixed-length) yang berfungsi sebagai penanda string tersebut[3].
Hash table dapat digambarkan sebagai berikut:

![Screenshot 2024-04-09 135314](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/38c6cabd-0115-4b45-a1a8-4575a5e38b9f)

## Guided 

### 1.

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}


// Struktur data untuk setiap node
struct Node {
   int key;
   int value;
   Node* next;
   Node(int key, int value) : key(key), value(value),
next(nullptr) {}
};


// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
}
    ~HashTable() {
       for (int i = 0; i < MAX_SIZE; i++) {
           Node* current = table[i];
           while (current != nullptr) {
               Node* temp = current;
               current = current->next;
               delete temp;
       }
}
delete[] table;
}


// Insertion
void insert(int key, int value) {
    int index = hash_func(key);
    Node* current = table[index];
    while (current != nullptr) {
       if (current->key == key) {
           current->value = value;
           return;
       }
       current = current->next;
   }
    Node* node = new Node(key, value);
    node->next = table[index];
    table[index] = node;

}


// Searching
int get(int key) {
    int index = hash_func(key);
    Node* current = table[index];
    while (current != nullptr) {
       if (current->key == key) {
           return current->value;
       }
       current = current->next;

    }
    return -1;

}


// Deletion
void remove(int key) {
   int index = hash_func(key);
   Node* current = table[index];
   Node* prev = nullptr;
   while (current != nullptr) {
      if (current->key == key) {
          if (prev == nullptr) {
              table[index] = current->next;
          } else {
              prev->next = current->next;
          }
          delete current;
          return;
       }
        prev = current;
        current = current->next;

     }
}


// Traversal
void traverse() {
     for (int i = 0; i < MAX_SIZE; i++) {
          Node* current = table[i];
          while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;

                current = current->next;
           }
      }
   }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;

    // Deletion
    ht.remove(4);

    // Traversal
    ht.traverse();

return 0;
}

```
#### Output:
![Screenshot 2024-04-09 145239](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/83f478b0-4f6e-4f50-944e-b626fc102446)

Deskripsi Program: Program tersebut menggunakan array dinamis "table" untuk menyimpan bucket dalam hash table. Masing-masing bucket direpresentasikan oleh sebuah linked list, di mana setiap node dalam linked list mewakili satu item data. Fungsi hash yang digunakan sederhana, hanya menggunakan operasi modulus untuk memetakan setiap kunci input ke indeks nilai dalam array.

### 2. 

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;
class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
             hash_val += c;
        }
    return hash_val % TABLE_SIZE;
    }
    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
table[hash_val].push_back(new HashNode(name,phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
               table[hash_val].erase(it);
               return;
            }
        }
    }
    string searchByName(string name) {
    int hash_val = hashFunc(name);
    for (auto node : table[hash_val]) {
         if (node->name == name) {
             return node->phone_number;
         }
    }
    return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
             cout << i << ": ";
                for (auto pair : table[i]) {
                if(pair != nullptr){
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";

                 }
               }
               cout << endl;
        }
     }
};

int main() {
HashMap employee_map;

employee_map.insert("Mistah", "1234");
employee_map.insert("Pastah", "5678");
employee_map.insert("Ghana", "91011");

cout << "Nomer Hp Mistah : " <<employee_map.searchByName("Mistah") << endl;
cout << "Phone Hp Pastah : " <<employee_map.searchByName("Pastah") << endl;

employee_map.remove("Mistah");
cout << "Nomer Hp Mistah setelah dihapus : " <<employee_map.searchByName("Mistah") << endl << endl;
cout << "Hash Table : " << endl;

employee_map.print();

return 0;
}

```
#### Output:
![Screenshot 2024-04-09 153812](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/b8df80b8-6bb2-48bd-804a-637e196c0921)

Deskripsi Program:  Program tersebut terdiri dari dua kelas utama, yaitu: HashNode yang merepresentasikan node dalam hash table dengan informasi nama dan nomor telepon karyawan, serta HashMap yang mengimplementasikan struktur hash table menggunakan vektor pointer ke HashNode. Fungsi hashFunc digunakan untyk menghitung nilai hash dari nama karyawan, fumgsi insert untuk menambahkan data baru, fungsi remove untuk menghapus data, dan fungsi searchByName untuk mencari nomor telepon karyawan berdasarkan nama.


## Unguided 

### 1. [Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan : a. Setiap mahasiswa memiliki NIM dan nilai. b. Program memiliki tampilan pilihan menu berisi poin C. c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).]

```C++
#include <iostream>
#include <unordered_map>
#include <vector>

// Fatik Nurimamah
// 2311102190

using namespace std;

// Struktur data untuk menyimpan data Mahasiswa
struct Mahasiswa {
    int NIM;
    int nilai;
};

class HashTable {
private:
    unordered_map<int, Mahasiswa> data;

public:
    // Fungsi untuk menambahkan data mahasiswa
    void tambahData(int NIM, int nilai) {
        Mahasiswa mhs;
        mhs.NIM = NIM;
        mhs.nilai = nilai;
        data[NIM] = mhs;
    }

    // Fungsi untuk menghapus data mahasiswa
    void hapusData(int NIM) {
        if (data.find(NIM) != data.end()) {
            data.erase(NIM);
            cout << "Data Mahasiswa dengan NIM " << NIM << " berhasil dihapus." << endl;
        } else {
            cout << "Data Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
        }
    }

    // Fungsi untuk mencari data berdasarkan NIM
    void cariMhsBerdasarkanNIM(int NIM) {
        if (data.find(NIM) != data.end()) {
            cout << "Data Mahasiswa dengan NIM " << NIM << " ditemukan. Dengan nilai yang telah diperoleh: " << data[NIM].nilai << endl;
        } else {
            cout << "Data Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
        }
    }

    // Fungsi untuk mencari data berdasarkan rentang nilai (80 - 90)
    void cariMhsBerdasarkanNilai() {
        cout << "\nMahasiswa dengan nilai antara 80 - 90: " << endl;
        for (auto& pair : data) {
            if (pair.second.nilai >= 80 && pair.second.nilai <= 90) {
                cout << "NIM: " << pair.second.NIM << "\nNilai: " << pair.second.nilai << endl;
            }
        }
    }
};

int main() {
    HashTable hashTable;
    int pilih, NIM, nilai;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Data Mahasiswa" << endl;
        cout << "2. Hapus Data Mahasiswa" << endl;
        cout << "3. Cari Data Mahasiswa berdasarkan NIM" << endl;
        cout << "4. Cari Data Mahasiswa berdasarkan Rentang Nilai (80 - 90)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih Operasi: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "\nMasukkan NIM Mahasiswa: ";
                cin >> NIM;
                cout << "Masukkan Nilai Mahasiswa: ";
                cin >> nilai;
                hashTable.tambahData(NIM, nilai);
                break;
            case 2:
                cout << "\nMasukkan NIM Mahasiswa yang akan dihapus: ";
                cin >> NIM;
                hashTable.hapusData(NIM);
                break;
            case 3:
                cout << "\nMasukkan NIM Mahasiswa yang ingin dicari: ";
                cin >> NIM;
                hashTable.cariMhsBerdasarkanNIM(NIM);
                break;
            case 4:
                hashTable.cariMhsBerdasarkanNilai();
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
                break;
        }
    } while (pilih != 0);

    return 0;
}

```
#### Output:
![Screenshot 2024-04-11 211219](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/d336d280-3231-4e23-a5b6-edacb38406a3)

![Screenshot 2024-04-11 211351](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/deee49e0-653c-41bb-9b52-4abeb0e53486)

Deskripsi Program: Program tersebut adalah program sederhana yang berguna untuk mengelola data mahasiswa dengan menggunakan struktur data Hash Table. Pada program ini, pengguna dapat menambahkan, menghapus, dan mencari data mahasiswa berdasarkan NIM atau rentang nilai. Setelah memilih operasi yang tersedia pada menu, pengguna diminta untuk memasukkan data yang diperlukan, seperti NIM dan nilai, dan program akan memberikan respons yang sesuai dengan operasi pada menu yang telah dipilih. Program akan berjalan hingga pengguna memilih untuk keluar.

## Kesimpulan
1. Hash Table merupakan struktur data yang efisien dalam pencarian data karena mengimplementasikan waktu pencarian yang konsisten (O(1)) bahkan untuk jumlah data yang besar, berkat fungsi hash yang langsung menentukan lokasi penyimpanan.

2. Fungsi hash adalah elemen kunci dari hash table yang mengubah data berbagai ukuran menjadi nilai dengan ukuran tertentu dan memungkinkan pengindeksan yang cepat dan efisien.

## Referensi
[1] Syahrir, Moch, and Fatimatuzzahra Fatimatuzzahra. "Association Rule Integrasi Pendekatan Metode Custom Hashing dan Data Partitioning untuk Mempercepat Proses Pencarian Frekuensi Item-set pada Algoritma Apriori." Matrik: Jurnal Manajemen, Teknik Informatika Dan Rekayasa Komputer 20.1 (2020): 149-158.

[2] Alfarisy, Rizki Alif Salman. "Perbandingan Kinerja Berbagai Algoritma Fungsi Hash pada Algoritma Rabin-Karp."

[3] Putra, N. P., & Sularno, S. (2019). Penerapan Algoritma Rabin-Karp Dengan Pendekatan Synonym Recognition Sebagai Antisipasi Plagiarisme Pada Penulisan Skripsi. Jurnal Teknologi Dan Sistem Informasi Bisnis, 1(2), 130-140.
