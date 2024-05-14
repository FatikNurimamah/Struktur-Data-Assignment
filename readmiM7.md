# <h1 align="center">Laporan Praktikum Modul QUEUE</h1>
<p align="center">Fatik Nurimamah (2311102190)</p>

## Dasar Teori

PENJELASAN QUEUE

Queue atau antrian adalah kumpulan data yang disusun secara berurutan di mana penyisipan elemen baru dilakukan di satu ujung (biasanya di bagian belakang)[2], sedangkan penghapusan elemen dilakukan di ujung lain (biasanya di bagian depan)[2]. Elemen pertama yang dimasukkan akan menjadi yang pertama pula yang dihapus[2], sehingga prinsip ini disebut sebagai First In First Out (FIFO) atau Last In Last Out (LILO)[2]. Seperti halnya pada tumpukan (stacks), ada istilah khusus yang digunakan untuk dua operasi utama pada antrian[2]. Ketika sebuah elemen ditambahkan ke dalam antrian, operasi ini disebut EnQueue[2], sedangkan ketika sebuah elemen dikeluarkan dari antrian, operasi ini disebut DeQueue[2]. Jika mencoba menghapus elemen dari antrian yang sudah kosong, hal tersebut disebut sebagai underflow[2], sementara jika mencoba menambahkan elemen ke dalam antrian yang sudah penuh, hal tersebut disebut sebagai overflow[2]. 

Berikut merupakan visualisasi dari Queue atau antrian[1]:

![Screenshot 2024-05-10 215824](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/bf8e67a2-7cef-4713-b8dd-e0e826ef510d)

Pada gambar tersebut menunjukan 5 elemen (A,B,C,D,E) dimasukkan secara berturut-turut dari belakang[1]. Maka Elemen A yang merupakan elemen pertama masuk sehingga menempati posisi paling depan[1], Elemen E yang merupakan elemen terakhir masuk sehingga elemen E menempati posisi paling belakang[1].


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

### 1. [Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list]

```C++
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

    // Untuk mengecek apakah antrian kosong
    bool kosong() {
        return depan == nullptr;
    }

    // Untuk menambahkan elemen ke belakang antrian
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

    // Untuk menghapus elemen dari depan antrian
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

    // Untuk menampilkan seluruh elemen dalam antrian
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

    // Untuk mendapatkan jumlah elemen dalam antrian
    int hitungAntrian() {
        return ukuran;
    }

    // Untuk menghapus semua elemen dalam antrian
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

```
#### Output:
![Screenshot 2024-05-10 212837](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/af4ac4ed-0e5a-42a1-b436-e80317d513c4)

Deskripsi program:

#### Full code Screenshot:
![Screenshot 2024-05-14 205046](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/6351b690-48a4-4a1d-8e14-8a00f5c0dad0)

### 2. [Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa]

```C++
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

    // Untuk mengecek apakah antrian kosong
    bool kosong() {
        return depan == nullptr;
    }

    // Untuk menambahkan elemen ke belakang antrian
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

    // Untuk menghapus elemen dari depan antrian
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

    // Untuk menampilkan seluruh elemen dalam antrian
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

    // Untuk mendapatkan jumlah elemen dalam antrian
    int hitungAntrian() {
        return ukuran;
    }

    // Untuk menghapus semua elemen dalam antrian
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

```
#### Output:
![Screenshot 2024-05-14 195854](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/a78a948e-3cd4-44f0-917d-2ca19de85c96)


Deskripsi program:

#### Full code Screenshot:
![Screenshot 2024-05-14 205236](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/72fafc92-3640-43b7-97df-fc7c7ec303e6)

## Kesimpulan
1. Queue atau antrian adalah struktur data yang mengutamakan urutan penyisipan dan penghapusan elemen, dengan memastikan urutan pertama masuk adalah yang pertama keluar (FIFO) atau urutan yang terakhir masuk maka terakhir pula keluarnya (LILO).
   
2. Fungsi utama queue meliputi EnQueue untuk menambahkan elemen di ujung belakang dan DeQueue untuk menghapus elemen di ujung depan. Dengan demikian, queue memberikan cara efisien untuk mengelola data berurutan dalam berbagai konteks.

## Referensi
[1] Erkamim, E., Abdurrohim, I., Yuliyanti, S., Karim, R., Rahman, A., Admira, T. M. A., & Ridwan, A. (2024). Buku Ajar Algoritma dan Struktur Data. PT. Sonpedia Publishing Indonesia.

[2] Santoso, Joseph Teguh. "STRUKTUR DATA dan ALGORITMA (Bagian 1)." Penerbit Yayasan Prima Agus Teknik (2021): 1-333.
