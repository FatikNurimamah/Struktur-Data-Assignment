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

2. Tree

   Tree  merupakan  salah  satu  bentuk  struktur  data tidak  linear yang  menggambarkan  hubungan  yang bersifat  hirarkis (hubungan  one  to  many)  antara elemen-elemen[2].Tree bisa didefinisikan sebagai kumpulan simpul/node dengan satu elemen khusus yang disebut Root dan node lainnya terbagi menjadi himpunan-himpunan yang saling tak berhubungan satu sama lainnya  (disebut  subtree)[2]. Berikut merupakan istilah-istilah umum dalam tree[2]:
   1. Prodecessor: node yang berada diatas node tertentu[2].
   2. Successor: node yang berada di bawah node tertentu[2].
   3. Ancestor:  seluruh node yang terletak sebelum node tertentu dan terletak pada jalur yang sama[2].
   4. Descendant: seluruh node yang terletak sesudah node tertentu dan terletak pada jalur yang sama[2].
   5. Parent: predecssor satu level di atas suatu node[2].
   6. Child: successor satu level di bawah suatu node[2].
   7. Sibling: node-node yang memiliki parent yang sama dengan suatu node[2].
   8. Subtree: bagian  dari  tree  yang  berupa suatu node beserta descendantnya dan memiliki semua karakteristik dari tree tersebut[2].
   9. Size: banyaknya node dalam suatu tree[2].
   10. Height: banyaknya tingkatan/level dalam suatu tree[2].
   11. Root:  satu-satunya  node  khusus  dalam tree yang tak punya predecssor[2].
   12. Leaf: node-node dalam tree yang tak memiliki seccessor[2].
   13. Degree: banyaknya child  yang  dimiliki suatu node[2].

   Berikut merupakan visualisasi dari tree[2]:
   ![Screenshot 2024-05-28 212910](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/5d596896-f989-4f69-b54e-3b70696a14e2)

   Binary Tree adalah tree dengan syarat bahwa tiap node hanya boleh memiliki maksimal dua sub tree dan kedua sub tree tersebut harus terpisah[2]. Sesuai dengan definisi tersebut, maka tiap node dalam binary tree hanya boleh memiliki paling banyak dua child[2]. Berikut merupakan visualisasi dari binary tree[2]:

   
   ![Screenshot 2024-05-28 213359](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/c5629bce-c713-49f6-93fb-8896fba82db7)

   

      
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

### 2. [Program Tree]

```C++
//Program Tree

#include <iostream>
using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent; //pointer
};

//pointer global
Pohon *root;

// Inisialisasi
void init()
{
    root = NULL;
}

bool isEmpty()
{
    return root == NULL;
}

Pohon *newPohon(char data)
{
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode(char data)
{
    if (isEmpty())
    {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." <<
        endl;
    } else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}

void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else
    {
        if (!node)
        cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        } else
    {
        if (!node)
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}

void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else
    {
        if (!node)
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
            cout << "Parent : (tidak punya parent)" << endl;

            else
            cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)

            cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)

            cout << "Sibling : " << node->parent->right->data << endl;

            else
            cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
            cout << "Child Kiri : (tidak punya Child kiri)" << endl;

            else
            cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
            cout << "Child Kanan : (tidak punya Child kanan)" << endl;

            else
            cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node)
{
    if (isEmpty())
    cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
    if (node != NULL)
    {
        cout << " " << node->data << ", ";
        preOrder(node->left);
        preOrder(node->right);
    }
    }
}

// inOrder
void inOrder(Pohon *node)
{
    if (isEmpty())
    cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node)
{
    if (isEmpty())
    cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
    cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                if (node->parent->left == node)
                node->parent->left = NULL;
                else if (node->parent->right == node)
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            } else
            {
                delete node;
            }
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
    cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear()
{
    if (isEmpty())
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else
    {
        if (!node)
        {
            return 0;
        } else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else
    {
        if (!node)
        {
            return 0;
        } else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            } else
            {
                return heightKanan + 1;
            }
        }
    }
}

// Karakteristik Tree
void characteristic()
{
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
    cout << "Average Node of Tree : " << s / h << endl;
    else
    cout << "Average Node of Tree : 0" << endl;
}

int main()
{
    init();
    buatNode('A');
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI,
    *nodeJ;
    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);
    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;
    cout << "InOrder :" << endl;
    inOrder(root);
    cout << "\n" << endl;
    cout << "PostOrder :" << endl;
    postOrder(root);
    cout << "\n" << endl;
    characteristic();
    deleteSub(nodeE);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n" << endl;
    characteristic();
}

```
#### Output:
![Screenshot 2024-05-28 205631](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/d8f8383b-712c-40f3-bba1-ecbedef48f8f)
![Screenshot 2024-05-28 205654](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/b8fc8cc1-9895-429e-bf76-6be9f075e940)

Deskripsi Program: Program tersebut merupakan implementasi binary tree dalam bahasa C++, yang digunakan untuk operasi pembuatan, modifikasi, penelusuran, dan penghapusan node dalam struktur data tersebut. Setiap node dalam binary tree menyimpan data karakter dan memiliki maksimal dua child: kiri dan kanan. Fungsi yang disediakan termasuk pembuatan node baru, penambahan node sebagai child kiri atau kanan, pengubahan data node, dan penelusuran tree dengan metode preOrder, inOrder, dan postOrder. Program juga menghitung ukuran dan tinggi tree, serta dapat melakukan penghapusan subtree dan seluruh tree.


## Unguided 

### 1. [Buatlah program graph dengan menggunakan inputan user untuk menghitungjarak dari sebuah kota ke kota lainnya.Output Program} 
![Screenshot 2024-05-28 213652](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/6632a479-26f8-42ca-82e5-854a29926edb)

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

2. 
## Referensi
[1] Safei, M. Rian. "PENGERTIAN STRUKTUR DATA NON LINIER." (2019).

[2] HANDISHA, CICI. "Fakultas Komputer."
