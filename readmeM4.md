# <h1 align="center">Laporan Praktikum Modul LINKED LIST CIRCULAR DAN NON CIRCULAR</h1>
<p align="center">Fatik Nurimamah (2311102190)</p>

## Dasar Teori
1. CIRCULAR LINKED LIST
   
Circular Linked List Adalah double / single LL yang simpul terakhirnya menunjuk ke simpul awal, dan simpul awalnya menunjuk ke simpul akhir, atau dapat disebut LL yang dibuat seakan-akan merupakan sebuah lingkaran dengan titik awal dantitik akhir saling bersebelahan jika LL tersebut masih kosong[1].
 Circular linked list dapat digambarkan sebagai berikut:
![Screenshot 2024-04-02 204733](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/e7d845a8-6ef7-4ffc-9641-262c3e548a18)

2. NON CIRCULAR LINKED LIST

Setiap   node   pada   linked   list mempunyai  field  yang  berisi  data  dan pointer ke  node  berikutnya  &  ke  node sebelumnya. Untuk pembentukan node baru,  mulanya  pointer  next dan  prev akan menunjuk ke nilai NULL. Selanjutnya  pointer  prev  akan menunjuk  ke  node  sebelumnya,  dan pointer  next  akan menunjuk  ke  node selanjutnya pada list, dengan kata lain pointer dari node terakhir menunjuk ke NULL[2]. Non circular linked list dapat digambarkan sebagai berikut:

![Screenshot 2024-04-02 205133](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/cd1bdee2-0635-4d14-95f1-2835091f577f)

  

## Guided 

### 1. [Linked List Non Circular]

```C++
#include <iostream>
using namespace std;
/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
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
    Node *bantu, *hapus, *sebelum;
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
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}

// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == 0)
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
    if (isEmpty() == 0)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
        }
        else
        {
            cout << "Posisi bukan posisi tengah" << endl;

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
    if (isEmpty() == 0)
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
Deskripsi Program: Program menggunakan struktur data single linked list non-circular untuk menyimpan data dalam bentuk integer. Program ini memiliki fungsi-fungsi dasar untuk menambahkan dan menghapus elemen di depan, belakang, dan tengah linked list, serta untuk mengubah data pada posisi tertentu. Fungsi `main` digunakan untuk menguji operasi-operasi tersebut dan menampilkan isi linked list setelah setiap operasi.

#### Output:
![Screenshot 2024-04-02 100610](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/c1852052-b5c7-43b0-b761-a478722a0379)

### 2. [Linked List Circular]

```C++
#include <iostream>

using namespace std;

/// PROGRAM SINGLE LINKED LIST CIRCULAR

// Deklarasi Struct Node
struct Node
{
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init()
{
    head = NULL;
    tail = head;
}

// pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// buat node baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// hitung list
int hitungList()
{
    bantu = head;
    int jumlah = 0;

    while (bantu !=NULL)
    {
       jumlah++;
       bantu = bantu->next;
    }

    return jumlah;
}

// tambah depan
void insertDepan (string data)
{
    // buat node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next !=head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// tambah belakang
void insertBelakang (string data)
{
    // buat node baru
    buatNode (data);

    if(isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
        tail = baru;
    }
}

// tambah tengah
void insertTengah (string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversinf
        int nomor = 1;
        bantu = head;
        while (nomor < posisi -1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;

    }
}

// hapus depan

void hapusDepan()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;

        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;

            delete hapus;
        }
        else
        {
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// hapus belakang
void hapusBelakang()
{
    if(isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;

            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// hapus tengah
void hapusTengah(int posisi)
{
    if(isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;

        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// hapus list
void clearList()
{
   if (head != NULL)
   {

        hapus - head->next;

        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
   }
   cout << "List berhasil dihapus" << endl;
}


// tampilkan list
void tampil()
{
    if(isEmpty() == 0)
    {
        tail = head;
        do
        {
          cout << tail->data << ends;
          tail = tail->next;
        }
        while (tail != head);
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
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
return 0;
}

```
Deskripsi Program: Program ini merupakan implementasi dari Single Linked List Circular. Program ini memiliki fungsi dasar seperti menambah dan menghapus node di awal, akhir, dan di tengah linked list.

#### Output:
![Screenshot 2024-04-02 100045](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/6dae108e-7460-4322-ba87-d7d4ffcb42ae)

## Unguided 

### 1. [Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa]

```C++
#include <iostream>
#include <string>
using namespace std;

//Fatik Nurimamah
//2311102190


// Node Structure
struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* next;
};

// Linked List Class
class CircularLinkedList {
private:
    Mahasiswa* head;

public:
    CircularLinkedList() : head(nullptr) {}
    Mahasiswa* getHead() const {
        return head;
    }

    // Fungsi untuk menambahkan data di depan linked list
    void tambahDepan(string nama, string nim) {
        Mahasiswa* newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Mahasiswa* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        cout << "\nData telah ditambahkan" << endl;
    }

    // Fungsi untuk menambahkan data di belakang linked list
    void tambahBelakang(string nama, string nim) {
        Mahasiswa* newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Mahasiswa* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "\nData telah ditambahkan" << endl;
    }

    // Fungsi untuk menambahkan data di tengah linked list
    void tambahTengah(string nama, string nim, int posisi) {
        Mahasiswa* newNode = new Mahasiswa();
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (posisi == 1) {
            tambahDepan(nama, nim);
            return;
        }
        Mahasiswa* temp = head;
        for (int i = 1; i < posisi - 1; ++i) {
            if (temp == nullptr || temp->next == head) {
                cout << "Posisi tidak valid" << endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "\nData telah ditambahkan" << endl;
    }

    // Fungsi untuk menghapus data di depan linked list
    void hapusDepan() {
        if (head == nullptr) {
            cout << "Linked list kosong" << endl;
            return;
        }

        Mahasiswa* temp = head;
        if (temp->next == head) {
            delete temp;
            head = nullptr;
        }
        else {
            Mahasiswa* tail = head;
            while (tail->next != head)
                tail = tail->next;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }

    // Fungsi untuk menghapus data di belakang linked list
    void hapusBelakang() {
        if (head == nullptr) {
            cout << "Linked list kosong" << endl;
            return;
        }

        Mahasiswa* temp = head;
        Mahasiswa* tail = nullptr;
        while (temp->next != head) {
            tail = temp;
            temp = temp->next;
        }
        if (temp == head) {
            delete temp;
            head = nullptr;
        }
        else {
            tail->next = head;
            delete temp;
        }
    }

    // Fungsi untuk menghapus data di tengah linked list
    void hapusTengah(int posisi) {
        if (head == nullptr) {
            cout << "Linked list kosong" << endl;
            return;
        }
        if (posisi == 1) {
            hapusDepan();
            return;
        }
        Mahasiswa* temp = head;
        Mahasiswa* prev = nullptr;
        for (int i = 1; i < posisi; ++i) {
            prev = temp;
            temp = temp->next;
            if (temp == head) {
                cout << "Posisi tidak valid" << endl;
                return;
            }
        }
        prev->next = temp->next;
        delete temp;
    }

    // Fungsi untuk menghapus seluruh data pada linked list
    void hapusList() {
        if (head == nullptr) {
            cout << "\nLinked list kosong" << endl;
            return;
        }
        Mahasiswa* temp = head;
        Mahasiswa* next;
        do {
            next = temp->next;
            delete temp;
            temp = next;
        } while (temp != head);
        head = nullptr;
        cout << "\nLinked list berhasil dihapus" << endl;
    }

    // Fungsi untuk menampilkan semua data pada linked list
    void tampilkanData() {
        if (head == nullptr) {
            cout << "Linked list kosong" << endl;
            return;
        }
        Mahasiswa* temp = head;
        cout << "DATA MAHASISWA" << endl;
        cout << "NAMA\tNIM" << endl;
        do {
            cout << temp->nama << "\t" << temp->nim << endl;
            temp = temp->next;
        } while (temp != head);
    }

    //untuk menghapus semua node
    ~CircularLinkedList() {
        if (head == nullptr)
            return;
        Mahasiswa* curr = head;
        Mahasiswa* next;
        do {
            next = curr->next;
            delete curr;
            curr = next;
        } while (curr != head);
    }
};

int main() {
    CircularLinkedList cll;
    int choice, posisi;
    string nama, nim;
    do {
    // Tampilan Menu
        cout << "\nPROGRAM SINGLE LINKED LIST CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. Tampilkan Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "\nPilih Operasi : ";
        cin >> choice;

        // Melakukan operasi sesuai dengan pilihan pengguna
        switch (choice) {
            case 1:
                cout << "-Tambah Depan-" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cll.tambahDepan(nama, nim);
                break;
            case 2:
                cout << "-Tambah Belakang-" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cll.tambahBelakang(nama, nim);
                break;
            case 3:
                cout << "-Tambah Tengah-" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                cll.tambahTengah(nama, nim, posisi);
                break;
           case 4:
                cout << "-Ubah Depan-" << endl;
                    if (cll.getHead() == nullptr) {
                        cout << "Linked list kosong" << endl;
                    break;
                    }
                {
                    string namaLama = cll.getHead()->nama;
                    string nimLama = cll.getHead()->nim;
                    cout << "Masukkan Nama Baru : ";
                    cin >> nama;
                    cout << "Masukkan NIM Baru : ";
                    cin >> nim;
                    cll.getHead()->nama = nama;
                    cll.getHead()->nim = nim;
                    cout << "Data (" << namaLama << ") telah diganti dengan data (" << nama << ")" << endl;
                }
                break;
            case 5:
                cout << "-Ubah Belakang-" << endl;
                    if (cll.getHead() == nullptr) {
                        cout << "Linked list kosong" << endl;
                    break;
                    }
                {
                    Mahasiswa* temp = cll.getHead();
                        while (temp->next != cll.getHead())
                            temp = temp->next;
                        string namaLama = temp->nama;
                        string nimLama = temp->nim;
                        cout << "Masukkan Nama Baru : ";
                        cin >> nama;
                        cout << "Masukkan NIM Baru : ";
                        cin >> nim;
                        temp->nama = nama;
                        temp->nim = nim;
                        cout << "Data (" << namaLama << ") telah diganti dengan data (" << nama << ")" << endl;
                }
                break;

            case 6:
                cout << "-Ubah Tengah-" << endl;
                    if (cll.getHead() == nullptr) {
                        cout << "Linked list kosong" << endl;
                    break;
                }
                    cout << "Masukkan Posisi : ";
                    cin >> posisi;
                {
                    Mahasiswa* temp = cll.getHead();
                    for (int i = 1; i < posisi; ++i) {
                        temp = temp->next;
                    if (temp == cll.getHead()) {
                        cout << "Posisi tidak valid" << endl;
                    }
                }
                    string namaLama = temp->nama;
                    string nimLama = temp->nim;
                    cout << "Masukkan Nama Baru : ";
                    cin >> nama;
                    cout << "Masukkan NIM Baru : ";
                    cin >> nim;
                    temp->nama = nama;
                    temp->nim = nim;
                        cout << "Data (" << namaLama << ") telah diganti dengan data (" << nama << ")" << endl;
                }
                break;
            case 7:
                cout << "\n-Hapus Depan-" << endl;
                    if (cll.getHead() == nullptr) {
                        cout << "Linked list kosong" << endl;
                    break;
                }
            {
                string namaHapus = cll.getHead()->nama;
                cout << "Data (" << namaHapus << ") berhasil dihapus" << endl;
            }
                cll.hapusDepan();
                break;

          case 8:
              cout << "-Hapus Belakang-" << endl;
                    if (cll.getHead() == nullptr) {
                        cout << "Linked list kosong" << endl;
                    break;
                }
            {
            Mahasiswa* temp = cll.getHead();
                while (temp->next != cll.getHead())
                    temp = temp->next;
                string namaHapus = temp->nama;
                cout << "Data (" << namaHapus << ") berhasil dihapus" << endl;
            }
                cll.hapusBelakang();
                break;

         case 9:
             cout << "-Hapus Tengah-" << endl;
             cout << "Masukkan Posisi : ";
             cin >> posisi;
                if (posisi < 1) {
                    cout << "Posisi tidak valid" << endl;
                break;
            }
                if (posisi == 1 && cll.getHead() != nullptr) {
                    string namaHapus = cll.getHead()->nama;
                    cout << "Data (" << namaHapus << ") berhasil dihapus" << endl;
                    cll.hapusDepan();
                    break;
                }
            {
                Mahasiswa* temp = cll.getHead();
                Mahasiswa* prev = nullptr;
                for (int i = 1; i < posisi; ++i) {
                prev = temp;
                temp = temp->next;
                if (temp == cll.getHead()) {
                cout << "Posisi tidak valid" << endl;
                }
            }
                string namaHapus = temp->nama;
                cout << "Data (" << namaHapus << ") berhasil dihapus" << endl;
                cll.hapusTengah(posisi);
           }
            break;
            case 10:
                cout << "-Hapus List-" << endl;
                cll.hapusList();
                break;
            case 11:
                cout << "-Tampilkan Data-" << endl;
                cll.tampilkanData();
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 0);

    return 0;
}

```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Deskripsi Program: Program di atas merupakan implementasi struktur data linked list circular dalam bahasa C++. Program ini dapat digunakan oleh pengguna untuk menambah, menghapus, dan mengubah data dalam linked list. Melalui menu interaktif, pengguna dapat memilih operasi sesuai keinginan sendiri untuk dilakukan pada linked list tersebut.



## Kesimpulan
Kesimpulannya adalah:
Circular Linked List dan Non-Circular Linked List adalah dua jenis struktur data linked list yang berbeda dalam cara mereka mengatur pointer antara simpul-simpulnya. Circular Linked List memiliki siklus tertutup di mana simpul terakhir menunjuk kembali ke simpul pertama, sedangkan Non-Circular Linked List tidak memiliki siklus tertutup dan setiap simpul memiliki pointer ke simpul sebelumnya dan berikutnya. Dalam Non-Circular Linked List, pointer dari node terakhir menunjuk ke NULL, menandakan akhir dari list.

## Referensi
[1] Arraffi, Adzriel. "PENGERTIAN LINIER DALAM STRUKTUR DATA MAJEMUK." (2019).

[2] kurniman Putra, Agung. "List linier (linked list) dan variasinya_struktur data."
