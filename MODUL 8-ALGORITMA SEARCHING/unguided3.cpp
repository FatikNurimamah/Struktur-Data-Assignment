#include <iostream>
using namespace std;

// Fatik Nurimamah
// 2311102190

// Fungsi untuk menghitung jumlah angka 4 dalam array menggunakan sequential search
int countAngka(int data[], int size) {
    int count = 0;

    // Melakukan iterasi melalui setiap elemen dalam array
    for (int i = 0; i < size; i++) {
        if (data[i] == 4) {
            count++;
        }
    }

    return count;  // Kembalikan jumlah angka 4 yang ditemukan
}

int main() {
    // Array data yang diberikan
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int size = sizeof(data) / sizeof(data[0]);

    // Menampilkan data array
    cout << "Data Array: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    // Menghitung jumlah angka 4 dalam array
    int count = countAngka(data, size);

    // Menampilkan hasil perhitungan
    cout << "Jumlah angka 4 dalam array di atas adalah : " << count << endl;

    return 0;
}
