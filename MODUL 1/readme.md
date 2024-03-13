# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Fatik Nurimamah (2311102190)</p>

## Dasar Teori
Tipe data adalah klasifikasi yang digunakan untuk menentukan nilai  suatu variabel dalam bentuk operasi matematika, hubungan, atau logika.Tipe data digunakan untuk membantu komputer menginterpretasikan nilai  variabel dengan benar dan menghindari kesalahan selama pemrograman.
Tipe data primitif
Tipe data primitif adalah adalah tipe data dasar yang tersedia secara langsung pada suatu bahasa pemrograman. Tipe data  ini merupakan tipe data dasar yang sering digunakan oleh program. 
a.	Tipe bilangan bulat (Integer) adalah tipe data numerik yang biasa digunakan apabila bertemu dengan bilangan bulat, seperti 1, 27, 100
b.	Tipe bilangan pecahan atau floating point adalah bilangan yang menangani bilangan desimal atau perhitungan secara detail.
c.	Tipe data char digunakan untuk menyimpan data dalam bentuk huruf ,simbol seperti F,H,I
d.	Tipe data boolean merupakan tipe yang memiliki dua nilai yaitu benar (true) atau salah (false)

Tipe data abstrak
ADT atau Abstract Data Type merupakan suatu tipe data yang dimana tipe data tersebut adalahan buatan diri sendiri sesuai keinginan. Dalam C++, ADT dapat dibuat dalam sebuah Class. Class dalam  C++ merupakan pengembangan dari struct dalam bahasa pemrograman C. Class memiliki data dan fungsi yang di deklarasi privat, sementara data dan fungsi pada struct di deklarasi public.

Tipe data koleksi
tipe data koleksi adalah tipe data yang digunakan untuk mengelompokkan sekumpulan elemen menjadi satu. Tipe data ini juga dapat digunakan untuk menyimpan, mengambil, memanipulasi, dan mengomunikasikan agregasi data. berikut merupakan macam-macam tipe data koleksi:
1. Array: Di C++, array adalah variabel yang dapat menyimpan beberapa nilai dengan tipe yang sama
2. Vektor: Di C++, vektor digunakan untuk menyimpan elemen dengan tipe data serupa. Namun, tidak seperti array , ukuran vektor dapat bertambah secara dinamis. Artinya, kita dapat mengubah ukuran vektor selama eksekusi suatu program sesuai kebutuhan kita.
3. Map: Di C++, peta adalah wadah terkait yang menyimpan pasangan data. Pasangan ini, yang dikenal sebagai pasangan kunci-nilai , memiliki kunci unik, sedangkan nilai terkait tidak harus unik. Elemen dalam peta diurutkan secara internal berdasarkan kuncinya . Untuk menggunakan map di C++, kita harus menyertakan (map) file header dalam program kitaa

## Guided 

### 1. [Tipe Data Primitif]

```C++
#include <iostream>
using namespace std;
// Main program
int main()
{
char op;
float num1, num2;
// It allows user to enter operator i.e. +, -, *, /
cin >> op;
// It allow user to enter the operands
cin >> num1 >> num2;
// Switch statement begins
switch (op)
{
// If user enter +
case '+':
cout << num1 + num2;
break;
// If user enter -
case '-':
cout << num1 - num2;
break;
// If user enter *
case '*':
cout << num1 * num2;
break;
// If user enter /
case '/':
cout << num1 / num2;
break;
// If the operator is other than +, -, * or /,
// error message will display
default:
cout << "Error! operator is not correct";
} // switch statement ends
return 0;
}
```

### Deskripsi Program : kode di atas  adalah  program sederhana yang meminta pengguna  memasukkan operator matematika (+, -,​, /) dan dua angka (operan). Setelah input diterima, program menggunakan pernyataan switch  untuk mengevaluasi operator yang dimasukkan oleh pengguna dan melakukan operasi aritmatika sesuai dengan operator ini.



## 2.  [Tipe Data Abstrak]

```C++
#include <stdio.h>
//Struct
struct Mahasiswa
{
const char *name;
const char *address;
int age;
};
int main()
{
// menggunakan struct
struct Mahasiswa mhs1, mhs2;
// mengisi nilai ke struct
mhs1.name = "Dian";
mhs1.address = "Mataram";
mhs1.age = 22;
mhs2.name = "Bambang";
mhs2.address = "Surabaya";
mhs2.age = 23;
// mencetak isi struct
printf("## Mahasiswa 1 ##\n");
printf("Nama: %s\n", mhs1.name);
printf("Alamat: %s\n", mhs1.address);
printf("Umur: %d\n", mhs1.age);
printf("## Mahasiswa 2 ##\n");
printf("Nama: %s\n", mhs2.name);
printf("Alamat: %s\n", mhs2.address);
printf("Umur: %d\n", mhs2.age);
return 0;
}
```

### Deskripsi Program : Program ini merupakan program sederhana yang menggunakan struct untuk menyimpan informasi tentang dua mahasiswa. Setiap mahasiswa memiliki tiga atribut: nama, alamat, dan umur. Program ini menginisialisasi dua variabel struct mahasiswa, mhs1 dan mhs2, dan mengisinya dengan nilai untuk setiap atribut.



## 3.  [Tipe Data koleksi ]

```C++
#include <iostream>
using namespace std;
int main()
{
//deklarasi dan inisialisasi array
int nilai[5];
nilai[0] = 23;
nilai[1] = 50;
nilai[2] = 34;
nilai[3] = 78;
nilai[4] = 90;
//mencetak array
cout << "Isi array pertama :" << nilai[0] << endl;
cout << "Isi array kedua :" << nilai[1] << endl;
cout << "Isi array ketiga :" << nilai[2] << endl;
cout << "Isi array keempat :" << nilai[3] << endl;
cout << "Isi array kelima :" << nilai[4] << endl;
return 0;
}
```

### Deskripsi Program : Program ini merupakan program  C++ yang menggunakan array untuk menyimpan serangkaian nilai integer. Program kemudian menampilkan nilai-nilai ini di layar.



## Unguided 

### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!]

```C++
#include <iostream>
using namespace std;

// Fungsi untuk pengurangan dua bilangan
int pengurangan(int x, int y) {
    return x - y;
}

// Fungsi untuk menghitung rata-rata tiga bilangan
float mean(int x, int y, int z) {
    float jumlah = x + y + z;
    return jumlah / 3;
}

int main() {
    // Input
    int bilangan1 = 25;
    int bilangan2 = 18;
    int bilangan3 = 22;

    // Memanggil fungsi untuk pengurangan dua bilangan
    int hasil_pengurangan = pengurangan(bilangan1, bilangan2);
    cout << "Hasil pengurangan: " << hasil_pengurangan << endl;

    // Memanggil fungsi untuk menghitung rata-rata tiga bilangan
    float hasil_mean = mean(bilangan1, bilangan2, bilangan3);
    cout << "Rata-rata bilangan tersebut adalah: " << hasil_mean << endl;
return 0;
}

```
#### Output:
![Screenshot 2024-03-13 110936](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/847589bf-d31d-4c82-9489-9e2824435438)

#### Deskripsi Program : Program ini adalah  program  C++ yang mendefinisikan dua fungsi, satu fungsi menghitung pengurangan dua bilangan, dan satu lagi menghitung rata-rata  tiga bilangan , dan  memanggil fungsi tersebut dengan  bilangan yang  ditentukan.

#### Full code Screenshot:
![Screenshot 2024-03-13 115317](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/ebcbd3e4-11a7-423b-bab9-d020de270017)


### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya
a. Struktur atau struct adalah tipe data yang menyimpan beberapa data dengan default public. Struktur digunakan untuk mengelompokkan kumpulan tipe data  yang berbeda, serta Struktur mendefinisikan tipe data dan memberitahu Visual C++ untuk memperlakukan kumpulan tipe data dasar sebagai  tipe data tunggal yang  dapat digunakan untuk mendefinisikan variabel dan array variabel.

```C++
#include <iostream>
#include <string>
using namespace std;

// Deklarasi struct
struct Novel {
    string judul;
    string pengarang;
    int tahunTerbit;
};

int main() {
    // Mendefinisikan objek Novel
    Novel Novel1 = {"Dikta dan Hukum", "Dhia'an Farah", 2021};
    Novel Novel2 = {"Septihan", "Poppi Pertiwi", 2020};

    // Menampilkan informasi Novel
    cout << "Informasi Novel 1:" << endl;
    cout << "Judul: " << Novel1.judul << endl;
    cout << "Pengarang: " << Novel1.pengarang << endl;
    cout << "Tahun Terbit: " << Novel1.tahunTerbit << endl;

    cout << "\nInformasi Novel 2:" << endl;
    cout << "Judul: " << Novel2.judul << endl;
    cout << "Pengarang: " << Novel2.pengarang << endl;
    cout << "Tahun Terbit: " << Novel2.tahunTerbit << endl;

    return 0;
}

```
#### Output:
![Screenshot 2024-03-13 114719](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/de2e39b3-25e7-44e8-bdcd-6f5a8a99d342)

#### Deskripsi Program : Program ini merupakan program  C++ yang menggunakan struct untuk merepresentasikan informasi tentang novel.Program ini mendefinisikan struct yang disebut Novel.Struktur ini mempunyai tiga anggota: Judul (judul novel), Pengarang (nama novelis), dan Tahun Terbit (tahun terbitnya novel).

#### Full code Screenshot:
![Screenshot 2024-03-13 115501](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/af12b2f3-2646-45c9-890c-1e6394d2785d)

b. Class adalah tipe data default dan bersifat privat. Oleh karena itu, jika ingin objek anggota kelas itu sendiri menjadi publik, maka harus menggunakan (public). Sebuah kelas memiliki data (properti) dan fungsi (perilaku) yang menggambarkan suatu objek.

```C++
#include <iostream>
#include <string>
using namespace std;

// Deklarasi class
class Novel {
public:
    // Atribut
    string judul;
    string pengarang;
    int tahunTerbit;

    // Metode untuk menampilkan informasi Novel
    void tentangNovel() {
        cout << "Judul: " << judul << endl;
        cout << "Pengarang: " << pengarang << endl;
        cout << "Tahun Terbit: " << tahunTerbit << endl;
    }
};

int main() {
    // Membuat objek dari class Novel
    Novel Novel1, Novel2;

    // Mengisi informasi Novel1
    Novel1.judul = "Dikta dan Hukum";
    Novel1.pengarang = "Dhia'an Farah";
    Novel1.tahunTerbit = 2021;

    // Mengisi informasi Novel2
    Novel2.judul = "Septihan";
    Novel2.pengarang = "Poppi Pertiwi";
    Novel2.tahunTerbit = 2020;

    // Menampilkan informasi Novel
    cout << "Informasi Novel 1:" << endl;
    Novel1.tentangNovel();

    cout << "\nInformasi Novel 2:" << endl;
    Novel2.tentangNovel();

    return 0;
}

```
#### Output: 
![Screenshot 2024-03-13 120123](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/a4a1064a-b9a9-48a4-94da-12b8db5014b0)

#### Deskripsi Program : Program ini merupakan program  C++ yang mendefinisikan class bernama Novel. Kelas ini memiliki tiga atribut:  judul, pengarang, dan tahun terbit. Selain itu, kelas Novel juga memiliki  metode publik bernama tentangNovel yang digunakan untuk menampilkan informasi tentang novel.

#### Full code Screenshot:
![Screenshot 2024-03-13 120833](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/35e854c5-7667-4922-bfb5-6ffde116a857)


### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.

```C++
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Membuat map untuk menyimpan nama dan tinggi
    map<string,int> data;

    // Memasukkan data ke dalam map
    data["Wonwoo"] = 182;
    data["Mingyu"] = 187;
    data["Heeseung"] = 183;

    // Menampilkan informasi dari map
    cout << "Informasi Data:" << endl;
    for (auto it = data.begin(); it != data.end(); ++it) {
        cout << "Nama: " << it->first << ", tinggi: " << it->second << endl;
    }
    return 0;
}
```
#### Output: 
![Screenshot 2024-03-13 121314](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/320dd951-c101-4bf3-b152-a09b73684253)

#### Deskripsi Program : Program ini menggunakan map untuk menyimpan pasangan kunci-nilai yang merepresentasikan data nama dan tinggi, Program kemudian menggunakan iterator untuk menelusuri map guna mencetak informasi ke layar.

#### Full code Screenshot:
![Screenshot 2024-03-13 121807](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/932a2985-a5ef-464b-ad25-713a2b694c34)

Perbedaan array dengan map adalah:
1. Struktur data

   a. Array: Array adalah struktur data statis yang menyimpan elemen tetap dari tipe data yang sama dan memiliki ukuran tetap yang ditentukan saat deklarasi. Setelah array dideklarasikan, ukurannya tidak dapat diubah.

   b. Map : adalah struktur data dinamis yang memetakan kunci ke nilai. Hal ini memungkinkan pengguna untuk menyimpan pasangan nilai kunci dengan kunci  tipe data apa pun, bukan hanya bilangan bulat seperti  array.
3. Penggunaan Indeks

    a. Array:  Elemen dalam array diakses melalui indeks numerik mulai dari 0.

    b. Map: menggunakan kunci sebagai indeks untuk mengakses nilai terkait.
5. Ukuran dan Fleksibilitas

    a. Array: kuran array harus ditentukan pada waktu deklarasi dan tidak dapat diubah setelahnya. Hal ini membuat array cocok digunakan ketika pengguna mengetahui secara pasti berapa banyak elemen yang akan disimpan dalam array.

    b. Map:  Map tidak memiliki batasan ukuran yang tetap. Pengguna dapat dengan bebas menambahkan atau menghapus pasangan nilai kunci selama eksekusi program, membuat penyimpanan dan pengelolaan data dinamis menjadi lebih fleksibel.
## Kesimpulan
kesimpulan yang dapat saya ambil adalah:
Tipe data dalam pemrograman dibagi menjadi tiga kategori, yaitu:
1. Primitif: Tipe data bawaaan dari sistem seperti int, float, char, bool, dll.
 Digunakan untuk menyimpan nilai sederhana seperti bilangan bulat, angka desimal, karakter dan nilai boolean.
2. Abstrak : Tipe data yang dibuat sendiri oleh programmer, seperti class.
3. Koleksi : Tipe data yang digunakan untuk menyimpan beberapa nilai atau objek secara bersamaan.
 Contohnya termasuk array, vektor, dan map.

## Referensi
[1] https://www.dewaweb.com/blog/tipe-data-pemrograman/
[2] https://www.dicoding.com/blog/macam-macam-tipe-data/
[3] https://www.programiz.com/cpp-programming/arrays
[4] https://www.programiz.com/cpp-programming/map
[5] https://www.programiz.com/cpp-programming/vectors
[6] https://www.slideshare.net/KuliahKita/oop-collections
[7] Pratama, Yogga. "Jenis-jenis tipe data."
