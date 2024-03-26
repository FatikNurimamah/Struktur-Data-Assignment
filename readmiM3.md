# <h1 align="center">Laporan Praktikum Modul Single and Double Linked List</h1>
<p align="center">Fatik Nurimamah (2311102190)</p>

## Dasar Teori
a) Single Linked List

Single Linked List Adalah sebuah LL yang menggunakan sebuah variabel pointer yang menghubungkan setiap node (satu arah “next”)[1]. Perhatikan ilustrasi dibawah ini!

![Screenshot 2024-03-25 204139](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/986bc3af-054a-4cfc-bb7e-222abedca61c)

Single Linked list Circular
  
Single Linked List yang pointer nextnya menunjuk pada dirinya sendiri. Dimana pada node terakhir atau tail yang semula menunjukkan NULL diganti dengan menunjuk ke kepala atau head dengan demikian pada intinya tail akan selalu terhubung dengan head. [1]. Dari pengertian tersebut, perhatikanlah ilustrasi dibawah ini!

![Screenshot 2024-03-25 201239](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/9c67fe26-2c0a-4349-a88c-c0113f0f066c)


b) Double Linked List

Pada dasarnya, penggunaan Double Linked List hampir sama dengan penggunaan Single Linked List. Hanya saja Double Linked List menerapkan sebuah pointer baru, yaitu prev, yang digunakan untuk menggeser mundur selain tetap mempertahankan pointer next[2]. 

![Screenshot 2024-03-25 195321](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/de4c35e4-5f6d-4093-b538-825af86e0c4a)

Double Linked List Circular

Double linked list dengan menggunakan  pointer, dimana setiap node memiliki 3 field, yaitu 1 field pointer yang menunjuk pointer berikutnya (next), 1 field menunjuk pointer sebelumnya (prev), serta sebuah field yang  berisi data untuk node tersebut. Double Linked List   Circular pointer next dan prev-nya menunjuk ke dirinya sendiri secara circular[2].

![Screenshot 2024-03-25 193105](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/1d52e82d-e9e8-45ff-ae92-bbefcb8e717c)

a. Setiap  node  pada  linked  list mempunyai field yang berisi data dan pointer ke node berikutnya dan ke node sebelumnya[2].

b. Untuk   pembentukan   node baru, mulanya pointer next dan prev  akan  menunjuk  ke  dirinya sendiri[2].

c. Jika   sudah   lebih   dari   satu node,  maka  pointer  prev  akan menunjuk ke node sebelumnya, dan pointer next akan menunjuk ke 
    node sesudahnya[2].

## Guided 

### 1. [Latihan Single Linked List]

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}

```
Deskripsi program: Program ini merupakan implementasi dari single linked list non-circular dalam bahasa C++. Linked list memungkinkan program untuk melakukan operasi penambahan, penghapusan, dan perubahan nilai pada node dalam Linked list. Program ini juga memiliki kemampuan untuk menampilkan isi linked list pada setiap tahap operasi yang dilakukan.

### 2. [Latihan Double Linked List]
 
```C++
#include <iostream>
using namespace std;


class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}

```
Deskripsi Program: Kode ini merupakan implementasi  program yang menggunakan struktur data C++ Double Linked List. Program ini memungkinkan pengguna untuk melakukan berbagai operasi pada Double Linked List, termasuk: Menambah data, menghapus data, mengubah data, menghapus semua data, dan melihat isi linked list melalui menu-menu yang disediakan dalam fungsi.



## Unguided 

### 1. [Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:]
![Screenshot 2024-03-24 145307](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/240c8c16-8e3a-4402-9ad0-64c9e99a8413)


```C++
#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string nama;
    int usia;
    Node* next;
};

// Deklarasi Kelas SingleLinkedList
class SingleLinkedList {
public:
    Node* head;
    SingleLinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambah data di depan linked list
    void insertDepan(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk menambah data di belakang linked list
    void insertBelakang(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Fungsi untuk menambah data di tengah linked list
    void insertTengah(string nama, int usia, string namaSebelumnya) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        Node* temp = head;
        while (temp != nullptr && temp->nama != namaSebelumnya) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Data " << namaSebelumnya << " tidak ditemukan!" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Fungsi untuk menghapus data berdasarkan nama
    void DeleteData(string nama) {
        Node* temp = head;
        Node* prev = nullptr;
        if (temp != nullptr && temp->nama == nama) {
            head = temp->next;
            delete temp;
            return;
        }
        while (temp != nullptr && temp->nama != nama) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Data " << nama << " tidak ditemukan!" << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    // Fungsi untuk mengubah data berdasarkan nama
    void ChangeData(string nama, string NewName, int NewAge) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != nama) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Data " << nama << " tidak ditemukan!" << endl;
            return;
        }
        temp->nama = NewName;
        temp->usia = NewAge;
    }

    // Fungsi untuk menampilkan seluruh data
    void ShowData() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nama << " " << temp->usia << endl;
            temp = temp->next;
        }
    }
};

int main() {
    // Inisialisasi SingleLinkedList
    SingleLinkedList list;

    // Data pertama (nama dan usia Anda)
    string namaAnda;
    int usiaAnda;
    cout << "Masukkan Nama Anda: ";
    cin >> namaAnda;
    cout << "Masukkan Usia Anda: ";
    cin >> usiaAnda;
    list.insertDepan(namaAnda, usiaAnda);

    // Data-data lain sesuai permintaan
    list.insertBelakang("John", 19);
    list.insertBelakang("Jane", 20);
    list.insertBelakang("Michael", 18);
    list.insertBelakang("Yusuke", 19);
    list.insertBelakang("Akechi", 20);
    list.insertBelakang("Hoshino", 18);
    list.insertBelakang("Karin", 18);

    // Hapus data Akechi
    list.DeleteData("Akechi");

    // Tambahkan data Futaba di antara John dan Jane
    list.insertTengah("Futaba", 18, "John");

    // Tambahkan data Igor di awal
    list.insertDepan("Igor", 20);

    // Ubah data Michael menjadi Reyn 18
    list.ChangeData("Michael", "Reyn", 18);

    // Tampilkan seluruh data
    cout << "Seluruh data:" << endl;
    list.ShowData();

    return 0;
}

```
#### Output:
![Screenshot 2024-03-26 111740](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/fae05fea-0f1a-4e57-916f-c30f1733b4f7)


Deskripsi Program: Program tersebut adalah contoh implementasi struktur data linked list dalam C++ yang digunakan untuk menyimpan informasi tentang seseorang (nama dan umur). Program ini menggunakan linked list karena pengguna akan memiliki keleluasaan untuk menambah dan menghapus data tanpa  memindahkan data lainnya, serta program ini memberikan contoh penggunaan linked list dalam menyimpan dan mengelola data secara dinamis.


### 1. [Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.]
![Screenshot 2024-03-25 220414](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/c9238919-ae3d-4e81-a542-f5df1e413708)
![Screenshot 2024-03-25 220521](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/9117a86c-655a-469c-b031-56bdad1e8463)

```C++

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string nama;
    int harga;
    Node* prev;
    Node* next;
};

// Deklarasi Kelas DoubleLinkedList
class DoubleLinkedList {
public:
    Node* head;
    Node* tail;
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk menambah data di belakang linked list
    void insertBelakang(string nama, int harga) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->harga = harga;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = tail = newNode;
            newNode->prev = nullptr;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Fungsi untuk menambah data di tengah / di urutan tertentu
    void insertTengah(string nama, int harga, string namaSebelumnya) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->harga = harga;
        Node* temp = head;
        while (temp != nullptr && temp->nama != namaSebelumnya) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Produk " << namaSebelumnya << " tidak ditemukan!" << endl;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        else {
            tail = newNode;
        }
        temp->next = newNode;
    }

    // Fungsi untuk menghapus data berdasarkan nama produk
    void hapusData(string nama) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != nama) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Produk " << nama << " tidak ditemukan!" << endl;
            return;
        }
        if (temp == head) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
        }
        else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    // Fungsi untuk mengubah data berdasarkan nama produk
    void updateData(string nama, string newName, int newPrice) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != nama) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Produk " << nama << " tidak ditemukan!" << endl;
            return;
        }
        temp->nama = newName;
        temp->harga = newPrice;
    }

    // Fungsi untuk menampilkan seluruh data
    void ShowData() {
    Node* temp = head;
    cout << "==============================" << endl;
    cout << "| " << setw(14) << left << "Nama Produk" << " | " << setw(9) << left << "Harga" << " |" << endl;
    cout << "==============================" << endl;
    while (temp != nullptr) {
        cout << "| " << setw(14) << left << temp->nama << " | " << setw(9) << left << temp->harga << " |" << endl;
        temp = temp->next;
    }
    cout << "==============================" << endl;
    cout << endl;
}

    // Fungsi untuk menghapus semua data
    void hapusSemuaData() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
    }
};

int main() {
    // Inisialisasi DoubleLinkedList
    DoubleLinkedList list;

    // Menambahkan data awal
    list.insertBelakang("Originote", 60000);
    list.insertBelakang("Somethinc", 150000);
    list.insertBelakang("Skintific", 100000);
    list.insertBelakang("Wardah", 50000);
    list.insertBelakang("Hanasui", 30000);

    // Case:
    // 1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific
    list.insertTengah("Azarine", 65000, "Somethinc");

    // 2. Hapus produk Wardah
    list.hapusData("Wardah");

    // 3. Update produk Hanasui menjadi Cleora dengan harga 55000
    list.updateData("Hanasui", "Cleora", 55000);

    // Menampilkan menu
    while (true) {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;

        int pilih;
        cout << "\nMasukkan pilihan Anda: ";
        cin >> pilih;

        switch (pilih) {
            case 1: {
                string namaProduk;
                int hargaProduk;
                cout << "Masukkan nama produk: ";
                cin >> namaProduk;
                cout << "Masukkan harga produk: ";
                cin >> hargaProduk;
                list.insertBelakang(namaProduk, hargaProduk);
                break;
            }
            case 2: {
                string namaProduk;
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> namaProduk;
                list.hapusData(namaProduk);
                break;
            }
            case 3: {
                string namaProduk;
                string newName;
                int newPrice;
                cout << "Masukkan nama produk yang ingin diupdate: ";
                cin >> namaProduk;
                cout << "Masukkan nama produk baru: ";
                cin >> newName;
                cout << "Masukkan harga produk baru: ";
                cin >> newPrice;
                list.updateData(namaProduk, newName, newPrice);
                break;
            }
            case 4: {
                string namaProduk;
                string namaSebelumnya;
                int hargaProduk;
                cout << "Masukkan nama produk yang ingin ditambahkan: ";
                cin >> namaProduk;
                cout << "Masukkan nama produk yang berada sebelumnya: ";
                cin >> namaSebelumnya;
                cout << "Masukkan harga produk: ";
                cin >> hargaProduk;
                list.insertTengah(namaProduk, hargaProduk, namaSebelumnya);
                break;
            }
            case 5: {
                string namaProduk;
                cout << "Masukkan nama produk yang ingin dihapus: ";
                cin >> namaProduk;
                list.hapusData(namaProduk);
                break;
            }
            case 6: {
                list.hapusSemuaData();
                cout << "Semua data telah dihapus." << endl;
                break;
            }
            case 7: {
                list.ShowData();
                break;
            }
            case 8: {
                cout << "Anda telah keluar dari program." << endl;
                return 0;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
            }
        }
    }

    return 0;
}

```
#### Output:
![Screenshot 2024-03-26 113133](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/c427543a-d108-48d1-aebb-f8e5b9905538)

Deskripsi Program: Program ini merupakan implementasi dari struktur data double linked list dalam C++, yang digunakan untuk menyimpan daftar produk skincare dan harganya. Program ini dapat digunakan pengguna untuk menambah, menghapus, mengubah, dan menampilkan data produk skincare sesuai dengan pilihan menu yang disediakan. Setiap produk memiliki nama dan harga yang disimpan dalam node linked list. Program ini juga menyediakan kemampuan untuk menambahkan data antar produk tertentu.


## Kesimpulan
Linked list adalah struktur data yang fleksibel yang dapat digunakan dalam berbagai kasus.  Ada berbagai jenis linked list, seperti single linked list, single linked list circular, double linked list, dan double linked list circular, yang masing-masing memiliki karakteristik dan kegunaan  berbeda.

a. Single linked list lebih sesuai untuk penelusuran data dalam satu arah, sedangkan double linked list lebih sesuai untuk penelusuran data maju dan mundur.

b. Penggunaan circular linked list memungkinkan penelusuran data yang berlangsung terus-menerus tanpa perlu memeriksa kondisi NULL.

Setiap jenis linked list memberikan fleksibilitas dan fungsionalitas berbeda tergantung pada kebutuhan aplikasi. Penggunaan jenis daftar tertaut yang tepat  dapat meningkatkan efisiensi dan kinerja saat mengimplementasikan struktur data dan algoritma.




## Referensi
[1] Arraffi, Adzriel. "PENGERTIAN LINIER DALAM STRUKTUR DATA MAJEMUK." (2019).

[2] Nugraha, Aria Sakti. "Artikel Double Linked List Circulate." (2019).
