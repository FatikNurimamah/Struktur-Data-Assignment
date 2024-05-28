#include <iostream>
#include <iomanip>

using namespace std;

//Fatik Nurimamah
//2311102190

// Fungsi untuk mengisi nama-nama simpul
void isiSimpul_Fatik_2311102190(string simpul[], int jumlah_Simpul)
{
    string namaSimpul;
    for (int i = 0; i < jumlah_Simpul; i++)
    {
        cout << "Simpul " << i + 1 << " : ";
        cin >> namaSimpul;
        simpul[i] = namaSimpul;
    }
    cout << endl;
}

int main()
{
    // Penginputan jumlah simpul oleh pengguna
    int jumlah_Simpul;
    cout << "Masukkan jumlah simpul : ";
    cin >> jumlah_Simpul;

    // Deklarasi array untuk menyimpan nama simpul dan matriks bobot
    string simpul[jumlah_Simpul];
    int bobotSimpul[jumlah_Simpul][jumlah_Simpul];

    // Mengisi nama-nama simpul
    isiSimpul_Fatik_2311102190(simpul, jumlah_Simpul);

    cout << "Silahkan masukkan bobot antar simpul" << endl;

    // Mengisi bobot antar simpul
    for (int i = 0; i < jumlah_Simpul; i++)
    {
        for (int j = 0; j < jumlah_Simpul; j++)
        {
            cout << simpul[i] << " ---> " << simpul[j] << " = ";
            cin >> bobotSimpul[i][j];
        }
        cout << endl;
    }

    cout << endl;

    cout << "Matriks bobot antar simpul" << endl;
    cout << setw(12) << "";

    // Cetak header untuk nama-nama simpul
    for (int i = 0; i < jumlah_Simpul; i++)
    {
        cout << setw(12) << simpul[i];
    }
    cout << endl;

    // Cetak bobot setiap simpul
    for (int i = 0; i < jumlah_Simpul; i++)
    {
        // Cetak kolom untuk nama simpul
        cout << setw(12) << simpul[i];
        for (int j = 0; j < jumlah_Simpul; j++)
        {
            cout << setw(12) << bobotSimpul[i][j];
        }
        cout << endl;
    }
}
