# <h1 align="center">Laporan Praktikum MODUL STACK</h1>
<p align="center">Fatik Nurimamah (2311102190)</p>

## Dasar Teori
PENGERTIAN STACK

Stack atau tumpukan, merupakan struktur data yang memiliki peran penting dalam pemrograman dengan metode pemrosesan LIFO (Last In First Out). Artinya, objek yang terakhir dimasukkan ke dalam tumpukan akan menjadi yang pertama dikeluarkan. Dengan model ini, hanya elemen teratas dari stack (TOP) yang dapat diakses atau dikeluarkan. Salah satu keunggulan dari stack adalah kemampuannya untuk diimplementasikan baik menggunakan array maupun linked list.
Berikut merupakan visualisasi dari stack: 

![Screenshot 2024-05-04 220121](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/6faa1469-b064-400a-92cd-bd146f67f19a)

Adapun operasi-operasi/fungsi yang dapat dilakukan pada stack adalah sebagai berikut : 

1) Push  : digunakan  untuk menambah item pada stack pada tumpukan paling atas.
  
2) Pop  : digunakan  untuk  mengambil item pada stack pada tumpukan paling atas.
  
3) Clear  : digunakan untuk mengosongkan stack.

4) IsEmpty  : fungsi  yang  digunakan  untuk mengecek apakah stack sudah kosong.

5) IsFull   : fungsi   yang   digunakan   untuk mengecek apakah stack sudah penuh.


## Guided 

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}
bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = ' ';
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang dapat di lihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void chargeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArrayBuku() {
    for (int i = top - 1; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang di cetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {

    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();

    cout << "\n" << endl;
    cout << "apakah data stack penuh? " << isFull() << endl;
    cout << "apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);

    popArrayBuku();

    cout << "banyaknya data = " << countStack() << endl;

    chargeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n" << endl;

    destroyArrayBuku();
    cout << "Jumlah data setelah di hapus : " << top << endl;

    cetakArrayBuku();
    return 0;
}
```
#### Output:
![Screenshot 2024-05-02 090820](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/053d5952-7c3b-4219-920d-5fe589985216)

Deskripsi Program: Program di atas merupakan contoh implementasi sederhana dari struktur data tumpukan menggunakan array dalam bahasa C++. Program tersebut memungkinkan pengguna untuk menambah, menghapus, dan mengelola daftar buku yang tersimpan dalam tumpukan. Fungsi-fungsi utama dalam program, seperti menambah (`push`), menghapus (`pop`), melihat nilai pada posisi tertentu (`peek`), menghitung jumlah elemen, dan mengosongkan tumpukan, memberikan kemampuan dasar untuk mengatur data dalam tumpukan buku. Program ini menggunakan variabel `top` untuk mengindikasikan elemen teratas dalam tumpukan, serta fungsi-fungsi bantuan seperti `isFull` dan `isEmpty` untuk memeriksa status tumpukan. Selain itu, program mencetak status tumpukan dan isi tumpukan pada titik-titik tertentu untuk memberikan informasi tentang operasi yang sedang dilakukan kepada pengguna. 

## Unguided 

### 1. [Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.]

```C++
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

//Fatik Nurimamah
//2311102190

bool cekPalindrom(string kalimat) {
    stack<char> tumpukan;
    string kalimatBersih;

    // Membersihkan kalimat dari karakter non-alfanumerik dan mengonversi huruf kecil
    for (char karakter : kalimat) {
        if (isalnum(karakter)) {
            kalimatBersih += tolower(karakter);
        }
    }

    // Menambahkan setengah karakter pertama ke dalam tumpukan
    int setengahPanjangKata = kalimatBersih.length() / 2;
    for (int i = 0; i < setengahPanjangKata; i++) {
        tumpukan.push(kalimatBersih[i]);
    }

    // Membandingkan setengah karakter kedua dengan setengah karakter pertama yang telah di-pop dari tumpukan
    int indeksAwal = (kalimatBersih.length() % 2 == 0) ? setengahPanjangKata : setengahPanjangKata + 1;
    for (int i = indeksAwal; i < kalimatBersih.length(); i++) {
        if (kalimatBersih[i] != tumpukan.top()) {
            return false;
        }
        tumpukan.pop();
    }

    return true;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    if (cekPalindrom(kalimat)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}

```
#### Output:
![Screenshot 2024-05-04 230526](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/e477c5a5-2ec3-4864-b5f1-a005cab5d5ca)

![Screenshot 2024-05-04 231858](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/5028751e-84f0-4bd1-849c-27c75eaf5304)


Cara kerja program: Program tersebut merupakan sebuah program C++ yang bertujuan untuk menentukan apakah sebuah kalimat yang dimasukkan oleh pengguna merupakan palindrom atau tidak. Pertama-tama, program melakukan proses pembersihan terhadap kalimat tersebut dari karakter-karakter yang bukan huruf atau angka, dan mengubah semua huruf menjadi huruf kecil. Selanjutnya, program mengambil setengah karakter pertama dari kalimat yang telah dibersihkan dan menyimpannya ke dalam tumpukan. Kemudian, program membandingkan setengah karakter kedua dari kalimat dengan setengah karakter pertama yang telah diambil dari tumpukan secara berurutan. Apabila semua karakter yang dibandingkan sama, program akan menghasilkan output bahwa kalimat tersebut merupakan palindrom. Namun, jika terdapat perbedaan antara karakter yang dibandingkan, program akan menyatakan bahwa kalimat tersebut bukan palindrom. Dengan menggunakan struktur data tumpukan, program ini efektif dalam menentukan palindromitas suatu kalimat.

#### Full code Screenshot:
![Screenshot 2024-05-05 171213](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/fe20a22e-bd49-4b79-8bdc-14da9c5d8298)

![Screenshot 2024-05-05 171511](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/aee29d8f-8e0b-4f5a-a812-fc5439f18c91)


### 2. [Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?]

```C++
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
```
#### Output:
![Screenshot 2024-05-04 224932](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/3dc182e5-8ace-4840-b0ad-f6695c73e2f5)

Penjelasan program: Program ini bertujuan untuk mengolah tiga kata yang dimasukkan pengguna dengan membalikkan urutan kata dan huruf dalam kalimat, lalu mencetak hasilnya. Setelah meminta input dari pengguna, program memeriksa apakah kalimat tersebut mengandung minimal tiga kata. Jika ya, program menggunakan fungsi `BalikKalimat` untuk melakukan proses pembalikan urutan kata dan huruf. Fungsi ini bekerja dengan cara memisahkan kalimat menjadi kata-kata, mengubah setiap kata menjadi huruf kecil, menambahkannya ke dalam tumpukan, dan kemudian membangun kembali kalimat terbalik dengan mengambil kata-kata dari tumpukan. Hasil akhirnya, berupa kalimat yang telah dibalik, dicetak oleh program. Namun, jika kalimat yang dimasukkan tidak mengandung minimal tiga kata, program akan memberikan pesan kesalahan. Dengan demikian, output dari program ini adalah kalimat yang telah diolah dengan urutan kata dan huruf yang dibalik.

#### Full code Screenshot:


## Kesimpulan
1. Stack adalah struktur data yang mengikuti prinsip LIFO (Last In First Out), di mana objek terakhir yang dimasukkan akan menjadi yang pertama dikeluarkan. Hanya elemen paling atas dari stack yang dapat diakses, memberikan fleksibilitas dalam pengelolaan urutan data.

2. Implementasi stack dapat dilakukan menggunakan array atau linked list, sesuai dengan kebutuhan aplikasi. Operasi dasar seperti Push (penambahan item), Pop (penghapusan item), Clear (pengosongan stack), IsEmpty (pengecekan apakah stack kosong), dan IsFull (pengecekan apakah stack penuh) merupakan fungsi utama yang mendukung penggunaan stack dalam pemrograman. Dengan memahami konsep dan operasi-operasi ini, pengguna dapat memanfaatkan stack secara efisien dalam berbagai aplikasi pemrograman.


## Referensi
[1] Sihombing, Johnson. "Penerapan Stack Dan Queue Pada Array Dan Linked List Dalam Java." INFOKOM (Informatika & Komputer) 7.2 (2019): 15-24.
