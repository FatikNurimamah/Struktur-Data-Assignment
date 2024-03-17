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
