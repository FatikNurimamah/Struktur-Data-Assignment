# <h1 align="center">Laporan Praktikum Modul QUEUE</h1>
<p align="center">Fatik Nurimamah (2311102190)</p>

## Dasar Teori

PENJELASAN QUEUE

Queue atau antrian adalah kumpulan data yang disusun secara berurutan di mana penyisipan elemen baru dilakukan di satu ujung (biasanya di bagian belakang)[2], sedangkan penghapusan elemen dilakukan di ujung lain (biasanya di bagian depan)[2]. Elemen pertama yang dimasukkan akan menjadi yang pertama pula yang dihapus[2], sehingga prinsip ini disebut sebagai First In First Out (FIFO) atau Last In Last Out (LILO)[2]. Seperti halnya pada tumpukan (stacks), ada istilah khusus yang digunakan untuk dua operasi utama pada antrian[2]. Ketika sebuah elemen ditambahkan ke dalam antrian, operasi ini disebut EnQueue[2], sedangkan ketika sebuah elemen dikeluarkan dari antrian, operasi ini disebut DeQueue[2]. Jika mencoba menghapus elemen dari antrian yang sudah kosong, hal tersebut disebut sebagai underflow[2], sementara jika mencoba menambahkan elemen ke dalam antrian yang sudah penuh, hal tersebut disebut sebagai overflow[2]. 

Berikut merupakan visualisasi dari Queue atau antrian[1]:

![Screenshot 2024-05-10 215824](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/bf8e67a2-7cef-4713-b8dd-e0e826ef510d)


Operasi utama pada Queue[2]:
1. EnQueue: Menyisipkan elemen di akhir antrian[2].
2. DeQueue: Menghapus dan mengembalikan elemen di depan antrian[2].

Operasi bantuan pada Queue[2]:
1. Front: Mengembalikan elemen di depan tanpa menghapusnya[2].
2. QueueSize: Mengembalikan jumlah elemen yang disimpan dalam antrian[2].
3. IsEmptyQueueQ:  Menunjukkan  apakah  tidak  ada  elemen  yang  disimpan  dalam antrian atau tidak[2].



## Guided 

### 1.

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda antrain
int back = 0; // Penanda
string queueTeller[5]; // Fungsi pengecekan

bool isFull () { // Pengecekan antrainpenuh atau tidak
     if (back == maksimalQueue){
        return true; // =1
     } else {
        return false;
     }
}

bool isEmpty () { // Antriannya kosong atau tidak
     if (back == 0) {
        return true;
     } else {
        return false;
     }
}

void enqueueAntrian (string data) { //fungsi menambahkan antrian
     if (isFull()) {
        cout << "Antrian penuh" << endl; 
     } else {
        if (isEmpty()) { // Kondisi ketika queue kosong
           queueTeller[0] = data;
           front++;
           back++;
        } else { // Antriannya ada isi
           queueTeller[back] = data;
           back++;
        }
     }

}

void dequeueAntrian() { // Fungsi mengurangi antrian
     if (isEmpty()) {
        cout << "Antrian kosong" << endl;
     } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
     }
}

int countQueue() { // Fungsi menghitung banyak antrian
    return back;
}

void clearQueue() { // Fungsi menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Fungsi melihat antrian
     cout << "Data antrian teller:" << endl;
     for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
#### Output:
![Screenshot 2024-05-10 201648](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/761ade09-3aa8-4a4f-8b57-7ce2d2569fa1)

Deskripsi program: Program tersebut merupakan contoh sederhana penggunaan struktur data antrian (queue) dalam bahasa C++. Dalam program ini, sebuah array bernama `queueTeller` digunakan untuk menampung elemen-elemen antrian. Fungsi-fungsi seperti `enqueueAntrian()` digunakan untuk menambahkan elemen ke dalam antrian, `dequeueAntrian()` untuk menghapus elemen dari antrian, `countQueue()` untuk menghitung jumlah elemen dalam antrian, `clearQueue()` untuk mengosongkan antrian, dan `viewQueue()` untuk menampilkan isi antrian. Penanda `front` dan `back` digunakan untuk mengindikasikan elemen depan dan belakang antrian. Program ini memberikan contoh penggunaan dengan data "Andi" dan "Maya", menggambarkan operasi dasar yang dapat dilakukan pada struktur data antrian.


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

Deskripsi program:

#### Full code Screenshot:

### 2. [Soal]

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:

Deskripsi program:

#### Full code Screenshot:



## Kesimpulan


## Referensi
[1] Erkamim, E., Abdurrohim, I., Yuliyanti, S., Karim, R., Rahman, A., Admira, T. M. A., & Ridwan, A. (2024). Buku Ajar Algoritma dan Struktur Data. PT. Sonpedia Publishing Indonesia.

[2] Santoso, Joseph Teguh. "STRUKTUR DATA dan ALGORITMA (Bagian 1)." Penerbit Yayasan Prima Agus Teknik (2021): 1-333.
