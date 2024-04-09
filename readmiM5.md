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


## Unguided 

### 1. [Soal]

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] Syahrir, Moch, and Fatimatuzzahra Fatimatuzzahra. "Association Rule Integrasi Pendekatan Metode Custom Hashing dan Data Partitioning untuk Mempercepat Proses Pencarian Frekuensi Item-set pada Algoritma Apriori." Matrik: Jurnal Manajemen, Teknik Informatika Dan Rekayasa Komputer 20.1 (2020): 149-158.

[2] Alfarisy, Rizki Alif Salman. "Perbandingan Kinerja Berbagai Algoritma Fungsi Hash pada Algoritma Rabin-Karp."

[3] Putra, N. P., & Sularno, S. (2019). Penerapan Algoritma Rabin-Karp Dengan Pendekatan Synonym Recognition Sebagai Antisipasi Plagiarisme Pada Penulisan Skripsi. Jurnal Teknologi Dan Sistem Informasi Bisnis, 1(2), 130-140.
