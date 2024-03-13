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
