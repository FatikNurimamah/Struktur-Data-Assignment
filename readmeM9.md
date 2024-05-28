# <h1 align="center">Laporan Praktikum Modul GRAPH DAN TREE</h1>
<p align="center">Fatik Nurimamah (2311102190)</p>

## Dasar Teori

1. Graph

   Graph atau graf adalah kumpulan noktah (simpul) di dalam bidang dua dimensi yang dihubungkan dengan sekumpulan garis (sisi)[1]. Graph dapat digunakan untuk merepresentasikan objek-objek diskrit dan hubungan antara objek-objek tersebut[1]. Representasi visual dari graph adalah dengan menyatakan objek sebagai noktah, bulatan atau titik (Vertex)[1], sedangkan hubungan antara objek dinyatakan dengan garis (Edge)[1].
   G = (V, E)[1].

   Dimana[1]:

   G = Graph

   V   =   Simpul   atau   Vertex,   atau Node, atau Titik

   E = Busur atau Edge, atau arc

   Visualisasi graph adalah sebagai berikut[1]:

   ![Screenshot 2024-05-28 200602](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/8003a21a-93fc-4532-8b79-c9f86e2441c5)

3. Tree

   Tree bisa didefinisikan sebagai kumpulan simpul/node dengan satu elemen khusus  yang  disebut  Root  dan  node lainnya terbagi menjadi himpunan-himpunan yang saling tak berhubungan satu sama lainnya (disebut subtree)[1]. Binary tree (Pohon Biner) adalah himpunan terbatas yang mungkin kosong atau terdiri dari  sebuah simpul yang disebut akar dan dua buah himpunan lain yang disebut sub pohon kiri (left) dan sub pohon kanan(right)[1].  Karakteristik pohon biner adalah setiap simpul paling banyak hanya memiliki dua buah anak dan mungkin tidak punya anak[1].
   Visualisasi dari binary tree adalah sebagai berikut[1]:

   ![Screenshot 2024-05-28 201833](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/c71a3caf-c83d-49c9-835e-3cd666fcc437)

   Ketentuan Tree Root (akar) adalah node yang memiliki derajat keluar >=0 dan derajat masuk = 0[1].

   1. Subtree/child adalah bagian salah satu node di bawah root sampai ke bawah[1].
   2. Leaf (daun) adalah semua node yang  derajat  masuknya  1  dan derajat keluarnya 0[1].
   3. Height (ketinggian) adalah level tertinggi dari tree ditambah 1[1].
   4. Weight (bobot) adalah jumlah leaf (daun) pada tree[1].

      
## Guided 

### 1. [Program Graph]

```C++
// Program Graph

#include <iostream>
#include <iomanip>
using namespace std;

string simpul[7] =
{
    "Ciamis",
    "Bandung",
    "Bekasi",
    "tasikmalaya",
    "Cianjur",
    "Purwokerto",
    "Yogyakarta"
};

int busur[7][7] =
{
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph()
{
    for (int baris = 0; baris <7; baris ++)
    {
        cout <<" " << setiosflags (ios::left) << setw (15) << simpul [baris] << " : ";
        for (int kolom = 0; kolom<7; kolom++)
        {
            if (busur[baris][kolom]!=0)
            {
                cout << " " << simpul[kolom]<< "(" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main()
{
    tampilGraph();

return 0;
}

```
#### Output:
![Screenshot 2024-05-28 204051](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/30431a76-4f76-4e7a-aa52-ee291e5417b7)

Deskripsi Program: Program tersebut menggambarkan sebuah graph yang terdiri dari tujuh simpul yang mewakili kota-kota di Indonesia. Setiap kota dihubungkan dengan kota lainnya melalui jalur dengan bobot tertentu, yang merepresentasikan jarak atau keterhubungan antara kota-kota tersebut. Implementasi menggunakan dua array: satu untuk menyimpan nama-nama kota dan satu untuk menyimpan bobot jalur antara kota-kota dalam matriks dua dimensi. Fungsi `tampilGraph` digunakan untuk menampilkan hubungan antara kota-kota dengan bobot jalurnya. Program ini kemudian dieksekusi dalam fungsi `main`.

### 2. []

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code guided praktikan" << endl;
    return 0;
}
```
#### Output:


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


Deskripsi Program: 


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


Deskripsi Program: 


#### Full code Screenshot:


## Kesimpulan

1. Graph: Graph adalah struktur yang terdiri dari simpul (vertex) yang dihubungkan oleh sisi (edge), , digunakan untuk menggambarkan objek-objek dan hubungan antar objeknya. Graph dilambangkan sebagai G = (V, E), di mana V adalah kumpulan vertex atau simpul dan E adalah kumpulan edge atau sisi.

2. Tree dan Binary Tree: Tree adalah struktur dengan satu titik utama yang disebut root dan kumpulan subtree yang tidak saling berhubungan. Binary tree adalah jenis tree di mana setiap titik memiliki maksimal dua anak. Karakteristik pentingnya meliputi root, subtree, leaf, height, dan weight.

## Referensi
[1] Safei, M. Rian. "PENGERTIAN STRUKTUR DATA NON LINIER." (2019).
