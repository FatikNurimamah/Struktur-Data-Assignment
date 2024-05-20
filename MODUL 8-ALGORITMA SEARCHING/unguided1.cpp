#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

// Fatik Nurimamah
// 2311102190

// Fungsi untuk melakukan binary search pada array
bool binarySearch(char arr[], int size, char key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return true;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int main() {
    // Meminta user untuk memasukkan kalimat
    string kalimat;
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    // Menghapus spasi dari kalimat
    kalimat.erase(remove(kalimat.begin(), kalimat.end(), ' '), kalimat.end());

    // Mengubah kalimat menjadi array 
    int size = kalimat.size();
    char* charArray = new char[size + 1];
    strcpy(charArray, kalimat.c_str());

    // Mengurutkan array 
    sort(charArray, charArray + size);

    // Meminta user untuk memasukkan huruf yang ingin dicari
    char key;
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> key;

    // Mencari huruf menggunakan binary search
    bool ketemu = binarySearch(charArray, size, key);

    if (ketemu) {
        cout << "Huruf '" << key << "' ditemukan dalam kalimat." << endl;
    } else {
        cout << "Huruf '" << key << "' tidak ditemukan dalam kalimat." << endl;
    }

    // Menghapus array dinamis untuk menghindari memory leak
    delete[] charArray;

    return 0;
}
