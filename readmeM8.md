
# <h1 align="center">Laporan Praktikum Modul Algoritma Searching</h1>
<p align="center">Fatik Nurimamah (2311102190) </p>

## Dasar Teori

PENJELASAN ALGORITMA SEARCHING

1. Sequential Search

Sequential Search adalah cara untuk  pencarian  data  dalam  array  1 dimensi[1].  Data  yang  akan  dicari  nanti akan  ditelusuri  dalam  semua  elemen-elemen  array  dari  awal  sampai  akhir[1], dan data yang dicari tersebut tidak perlu diurutkan  terlebih  dahulu[1].
Adapun Proses Algoritma Sequential Searching adalah sebagai berikut[2]:

a. Pertama   data   melakukan perbandingan satu per satu secara berurutan dalam kumpulan  data  dengan  data  yang  dicari  sampai data  tersebut  ditemukan  atau  tidak  ditemukan[2].

b. Pada  dasarnya,  pencarian  ini  hanya  melakukan pengulangan  data  dari  1  sampai  dengan  jumlah data  (n)[2].

c. Setiap  pengulangan,  dibandingkan data  ke-i  dengan  data  yang  sedang  dicari[2].

d. Apabila data sama dengan yang dicari, berarti data telah   berhasil   di   temukan.   Sebaliknya   apabila sampai  akhir  melakukan  pengulangan  tidak  ada data  yang  sama  dengan  yang  dicari,  berarti  data tidak ada yang ditemukan. 

Urutan Algoritma Sequential Searching[2]:

a. i <- 0[2]

b. Ketemu <- false[2]

c. Selama  (  tidak ketemu  )  dan  (  i  <  n  ) kerjakan baris 4[2].

d. Jika  (  data[i]  =  key  )  maka  ketemu  <- true jika tidak i <- i + 1[2]

e. Jika  (  ketemu  )  maka  i  adalah  indeks  dari data yang dicari[2].

![Screenshot 2024-05-20 203843](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/e682e30e-1dea-4c9b-b078-eced68a887ec)

2. Binary Search

Binary Search adalah  cara  untuk pencarian  data  pada  array  yang  sudah terurut[1]. Karena salah satu syarat dalam Binary Search adalah data sudah dalam keadaan terurut[1], dengan kata lain apabila data belum dalam keadaan terurut[1], pencarian Binary tidak dapat dilakukan[1].
Sebuah list yang sudah terurut kemudian dibagi menjadi dua bagian[1]. Awalnya adalah membandingkan inputan dengan nilai tengah[1], selanjutnya dibandingkan ke kanan atau ke kiri sesuai dengan urutan listnya[1].

![Screenshot 2024-05-20 204235](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/0935add9-d0d1-4175-80f6-169479648587)



## Guided 

### 1. [Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.]

```C++
#include <iostream>
using namespace std;

int main(){
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    for (i = 0; i < n; i++){
        if(data[i] == cari){
            ketemu = true;
            break;
        }
    }
    cout << "\n\t Program Sequential Search Sederhana\n" << endl;
    cout << " data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    if (ketemu){
        cout << "\n angka "<< cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }

return 0;

}

```
#### Output:
![Screenshot 2024-05-20 204622](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/3c81d5e3-7575-4345-92eb-77c57467e8e1)

Deskripsi Program: Program ini adalah implementasi dari sequential search dalam bahasa C++. Program mencari nilai tertentu dalam sebuah array yang telah diinisialisasi dengan 10 angka. Angka yang dicari dalam program ini adalah 10. Program memeriksa setiap elemen dalam array satu per satu sampai menemukan angka yang dicari atau hingga semua elemen telah diperiksa. Jika angka ditemukan, program menampilkan indeks di mana angka tersebut berada. Jika tidak ditemukan, program akan menginformasikan bahwa angka tersebut tidak ada dalam array. Sebelum menampilkan hasil pencarian, program juga menampilkan isi dari array tersebut.

### 2. [Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search.]

```C++
#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi array dan variabel untuk pencarian
int arrayData[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort(int arr[], int n) {
     int temp, min;
     for (int i = 0; i < n - 1; i++) {
          min = i;
     for (int j = i + 1; j < n; j++) {
          if (arr[j] < arr[min]) {
              min = j;
            }
        }
        // Tukar elemen
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void binary_search(int arr[], int n, int target) {
     int awal = 0, akhir = n - 1, tengah, b_flag = 0;

     while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (arr[tengah] == target) {
            b_flag = 1;
            break;
        } else if (arr[tengah] < target) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }

    }
    if (b_flag == 1)
    cout << "\nData ditemukan pada index ke-" << tengah <<endl;
    else
    cout << "\nData tidak ditemukan\n";
}

int main() {
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData awal: ";
    // Tampilkan data awal
    for (int x = 0; x < 7; x++) {
    cout << setw(3) << arrayData[x];
    }
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;
    // Urutkan data dengan selection sort
    selection_sort(arrayData, 7);
    cout << "\nData diurutkan: ";
    // Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++) {
    cout << setw(3) << arrayData[x];
    }
    cout << endl;
    // Lakukan binary search
    binary_search(arrayData, 7, cari);
    
return 0;
}
```
#### Output:
![Screenshot 2024-05-20 205734](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/d8a416d2-ab04-4442-8363-464337ca8fca)

Deskripsi Program: 

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
[1] Religia, Yoga. "Analisis Algoritma Sequential Search Dan Binary Search Pada Big Data: Analysis Of Sequential Search And Binary Search Algorithm In Big Data." Pelita Teknologi 14.1 (2019): 74-79.
[2] Imamah, Nurul. "Perbandingan Algoritma Sequential Search Dan Algoritma Binary Search Pada Aplikasi Kamus Bahasa Indonesia Menggunakan Php Dan Jquery." COMPUTING| Jurnal Informatika 8.01 (2021): 1-6.
