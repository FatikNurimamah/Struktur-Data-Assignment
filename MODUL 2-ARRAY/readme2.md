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
#include <iostream>

using namespace std;

int main() {
    int x_ukuran, y_ukuran, z_ukuran;

    // Meminta pengguna untuk memasukkan ukuran array
    cout << "Masukkan ukuran array (x y z): ";
    cin >> x_ukuran >> y_ukuran >> z_ukuran;

    // Deklarasi array dengan ukuran yang dimasukkan pengguna
    int arr[x_ukuran][y_ukuran][z_ukuran];

    // Input elemen array
    for (int x = 0; x < x_ukuran; ++x) {
        for (int y = 0; y < y_ukuran; ++y) {
            for (int z = 0; z < z_ukuran; ++z) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "]: ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Output array
    cout << "Elemen-elemen array:" << endl;
    for (int x = 0; x < x_ukuran; ++x) {
        for (int y = 0; y < y_ukuran; ++y) {
            for (int z = 0; z < z_ukuran; ++z) {
                cout << "Array[" << x << "][" << y << "][" << z << "]: " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
// tampilan array
    for (int x = 0; x < x_ukuran; x++)
    {
        for (int y = 0; y < y_ukuran; y++)
        {
            for (int z = 0; z < z_ukuran; z++)
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
#### Output:
![Screenshot 2024-03-17 205010](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/e0dce9b1-9a85-4d41-9dd6-1fbcad753932)
![Screenshot 2024-03-17 205150](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/84a87d0b-eeb0-4ff8-80de-a112cf589863)

Deskripsi Program : Program ini merupakan program C++ yang memungkinkan pengguna memasukkan input array tiga dimensi (x, y, z) dan ukuran elemennya. Program ini memungkinkan pengguna untuk dengan mudah mengelola array tiga dimensi dan menampilkan elemennya secara terstruktur.
 
#### Full code Screenshot:
![Screenshot 2024-03-17 210613](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/3285a925-482f-4098-9c1b-067bfb2b2525)

### 3. [Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!]

```C++
#include <iostream>
#include <climits>
#include <iomanip>

using namespace std;

int main() {
    int n;

    // Meminta pengguna untuk memasukkan ukuran array
    cout << "Masukkan jumlah array: ";
    cin >> n;

    // Deklarasi array dengan ukuran yang dimasukkan pengguna
    int arr[n];

    // Input elemen array
    cout << "Masukkan elemen-elemen array:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Array ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    // Mencari nilai maksimum, minimum, dan rata-rata
    int max_arr = INT_MIN;
    int min_arr = INT_MAX;
    int mean = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > max_arr) {
            max_arr = arr[i];
        }
        if (arr[i] < min_arr) {
            min_arr = arr[i];
        }
        mean += arr[i];
    }
    double average = static_cast<double>(mean) / n;

    // Menampilkan nilai maksimum, minimum, dan rata-rata
    cout << "\nNilai maksimum: " << max_arr << endl;
    cout << "Nilai minimum: " << min_arr << endl;
    cout << "Nilai rata-rata: " << fixed << setprecision(2) << average << endl;

    return 0;
}
```
#### Output:
![Screenshot 2024-03-17 211940](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/5a5e7dbc-2ad5-4377-a909-48471dc1923e)

Deskripsi Program : Program ini merupakan program C++ yang meminta pengguna untuk menginputkan elemen-elemen  array dan kemudian akan dicari nilai maksimum, minimum, dan rata-rata dari array tersebut.

#### Full code Screenshot:
![Screenshot 2024-03-17 212518](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/d4549999-9916-4d4f-9870-bd330a3e897d)

## Kesimpulan
kesimpulan yang dapat saya ambil adalah :
Array adalah struktur data untuk menyimpan kumpulan nilai dari tipe data yang sama.

Ada tiga jenis array: 
   1. Array satu dimensi: elemen disusun dalam baris dan diakses melalui satu indeks.
   2. Array dua dimensi: elemen disusun dalam matriks dan dapat diakses melalui dua indeks (baris dan kolom).
   3. Array multidimensi: Array dengan tiga dimensi atau lebih yang digunakan untuk struktur data  kompleks.

Array memungkinkan pengelolaan data yang efisien dan berguna untuk pemrograman perulangan, pengurutan, pencarian, dan operasi data lainnya. Array juga merupakan alat yang sangat penting dalam pemrograman karena memungkinkan pengguna untuk mengatur dan mengakses data secara efisien, terutama ketika berhadapan dengan data dalam jumlah  besar atau  struktur data  kompleks seperti matriks.

## Referensi
[1] https://dosenit.com/kuliah-it/array
