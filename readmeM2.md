# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Fatik Nurimamah (231102190)</p>

## Dasar Teori

Array adalah struktur data yang digunakan untuk menyimpan kumpulan nilai atau elemen dari tipe data yang sama. Dalam bahasa Indonesia, “array” dapat diartikan sebagai “larik” atau “tabel”. Setiap elemen dalam array memiliki indeks, yang memungkinkan pengguna mengakses nilai atau datanya satu per satu. Array adalah alat yang berguna dalam pemrograman karena memungkinkan pengguna mengelola data dalam jumlah besar secara efisien. Array dapat digunakan untuk menyimpan data seperti angka, string, dan bahkan objek  kompleks. Array memungkinkan Anda memproses data secara efisien. Misalnya, melakukan operasi secara berulang pada setiap elemen, mengurutkan data, mencari elemen tertentu, dll.

Jenis-jenis Array
1. Array Satu Dimensi (One-Dimensional Array)

   Array satu dimensi adalah tipe array yang elemen-elemennya bertipe data yang sama disusun dalam  baris. Setiap elemen diakses melalui satu indeks.
   contoh: int arr[5] = {9, 3, 5, 2, 1};
3. Array Dua Dimensi (Two-Dimensional Array)

   Array dua dimensi adalah jenis array yang berisi elemen-elemen bertipe data yang sama,  disusun dalam bentuk matriks atau tabel dua dimensi. Elemen diakses melalui dua indeks: indeks baris dan indeks kolom.
   contoh: int arr[2][2] = {{3, 2}, {2, 5}};
5. Array Multidimensi (Multidimensional Array)

    Array multidimensi adalah jenis array dengan tiga dimensi atau lebih. Digunakan untuk merepresentasikan data dengan struktur yang lebih kompleks. Elemen diakses melalui indeks di setiap dimensi.
   contoh: int arr[2][2][3] = {{{2, 8, 7}, {6, 5, 1}}, {{8, 5, 2}, {9, 2 ,7}}};


## Guided 

### 1. [Program Input Array Tiga Dimensi]

```C++

#include <iostream>

using namespace std;
// program input array 3 dimensi
int main()
{
    // deklarasi array
    int arr[2][3][3];
    // input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "]: ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // output array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Array[" << x << "][" << y << "][" << z << "]: " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

```
Deskripsi Program : Program di atas adalah program C++ yang mengilustrasikan penggunaan array tiga dimensi. Program ini meminta pengguna untuk menginputkan nilai ke dalam array tiga dimensi dan menampilkan nilai-nilai tersebut di layar dalam berbagai format  untuk memvisualisasikan struktur array tiga dimensi.

 ### 2. [Program Mencari Nilai Maksimal pada Array]
 
```C++

#include <iostream>

using namespace std;

int main()
{
    int maks, a, i=1, lokasi;
    cout << "masukkan panjang array: ";
    cin>>a;
    int array [a];
    cout << "masukkan " <<a<< " angka\n";
    for(i=0; i<a; i++){
        cout << "array ke-" << (i) << ": ";
        cin>>array[i];
    }
    maks=array[0];
    for (i=0; i<a; i++){
            if (array[i]>maks){
        maks=array[i];
        lokasi=i;
    }
}
cout<< "nilai maksimum adalah "<<maks<< " berada di array ke "<<lokasi<<endl;
    return 0;
}
```
Deskripsi Program : Ini adalah program sederhana dalam  C++ untuk mencari nilai maksimum dari sebuah array yang diinputkan oleh pengguna.
 Program ini meminta pengguna untuk menginputkan panjang array dan nilai setiap elemen dalam array dan menemukan nilai maksimum dalam array.
 Setelah menemukan nilai maksimum, program mencetak nilai ini beserta indeksnya dalam array.
 

## Unguided 

### 1. [Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!]
![Screenshot 2024-03-17 140913](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/b58410ad-27d6-4e09-8468-2d963cb6fa43)

```C++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Array yang diberikan
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]); // Mendapatkan panjang array

    // Menampilkan seluruh elemen array
    cout << "Data array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Vektor untuk menyimpan bilangan ganjil dan genap
    vector<int> Nomganjil;
    vector<int> Nomgenap;

    // Memproses array
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 0) {
            Nomgenap.push_back(arr[i]); // Menyimpan bilangan genap ke vektor genap
        } else {
            Nomganjil.push_back(arr[i]); // Menyimpan bilangan ganjil ke vektor ganjil
        }
    }


    // Menampilkan bilangan genap
    cout << "Nomor Genap: ";
    for (int bil : Nomgenap) {
        cout << bil << " " << ",";
    }
    cout << endl;

    // Menampilkan bilangan ganjil
    cout << "Nomor Ganjil: ";
    for (int bil : Nomganjil) {
        cout << bil << " " << ",";
    }
    cout << endl;

    return 0;
}

```
#### Output:
![Screenshot 2024-03-17 144637](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/2379e89e-d4bf-4a51-94c4-545a7d0d77b3)

Deskripsi Program : Program di atas merupakan program C++ yang menginisialisasi  array dengan nilai tertentu dan membagi nilai tersebut menjadi dua vektor terpisah, yaitu: satu untuk nilai genap dan satu lagi untuk nilai ganjil.

#### Full code Screenshot:
![Screenshot 2024-03-17 152201](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/133bd153-a7a7-4c83-8c12-3c2e866a40e8)


### 2. [Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!]

```C++



## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
