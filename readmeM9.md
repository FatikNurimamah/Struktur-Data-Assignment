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

```
#### Output:
![Screenshot 2024-05-28 222316](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/435f4cda-8709-49f3-8689-e5d7e4d85462)

Deskripsi Program: Program tersebut digunakan oleh pengguna untuk menentukan jumlah simpul dalam suatu graf dan mengisi bobot antar simpul dalam bentuk matriks. Setelah pengguna memberikan input, program akan menampilkan matriks bobot antar simpul berdasarkan informasi yang dimasukkan. Alur program dimulai dengan penggunaan jumlah simpul yang dimasukkan, kemudian nama-nama simpul dimasukkan satu per satu melalui fungsi `isiSimpul_Fatik_2311102190()`. Selanjutnya, pengguna diminta untuk memberikan bobot antar simpul menggunakan prompt yang sesuai. Setelah semua informasi terkumpul, program akan mencetak matriks bobot antar simpul, termasuk header untuk nama-nama simpul dan bobot-bobot antar simpul.


#### Full code Screenshot:
![Screenshot 2024-05-28 221700](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/607d4bf0-c485-4b77-991f-fd1ca5b34462)


### 2. [Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!]

```C++
#include <iostream>
#include <iomanip>
using namespace std;

// Fatik Nurimamah
// 2311102190

struct Node
{
    char data;
    Node *left, *right, *parent; // pointer
};

Node *root;

class Tree
{
public:
    Tree()
    {
        root = nullptr;
    }

    bool isEmpty()
    {
        return root == nullptr;
    }

    Node *makeNode(char data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->parent = nullptr;

        return newNode;
    }

    void makeBranch(char data)
    {
        if (isEmpty())
        {
            root = makeNode(data);
            cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
        }
        else
        {
            cout << "\nPohon sudah dibuat" << endl;
        }
    }

    Node *insertLeft(char data, Node *node)
    {
        if (isEmpty())
        {
            cout << "\nBuat tree terlebih dahulu!" << endl;
            return nullptr;
        }
        else
        {
            if (node == nullptr)
            {
                cout << "Node tersebut tidak valid atau tidak ada" << endl;
                return nullptr;
            }

            if (node->left != nullptr)
            {
                cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;

                return nullptr;
            }
            else
            {
                Node *newNode = makeNode(data);
                newNode->parent = node;
                node->left = newNode;
                cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
                return newNode;
            }
        }
    }

    Node *insertRight(char data, Node *node)
    {
        if (isEmpty())
        {
            cout << "\nBuat tree terlebih dahulu!" << endl;
            return nullptr;
        }
        else
        {
            if (node == nullptr)
            {
                cout << "Node tersebut tidak valid atau tidak ada" << endl;
                return nullptr;
            }

            if (node->right != nullptr)
            {
                cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;

                return nullptr;
            }
            else
            {
                Node *newNode = makeNode(data);
                newNode->parent = node;
                node->right = newNode;
                cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
                return newNode;
            }
        }
    }

    void update(char data, Node *node)
    {
        if (isEmpty())
        {
            cout << "\nBuat tree terlebih dahulu!" << endl;
        }
        else
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

    void retrieve(Node *node)
    {
        if (isEmpty())
        {
            cout << "\nBuat tree terlebih dahulu!" << endl;
        }
        else
        {
            if (!node)
                cout << "\nNode yang ditunjuk tidak ada!" << endl;
            else
            {
                cout << "\nData node : " << node->data << endl;
            }
        }
    }

    void find(Node *node)
    {
        if (isEmpty())
        {
            cout << "\nBuat tree terlebih dahulu!" << endl;
        }
        else
        {
            if (!node)
                cout << "\nNode yang ditunjuk tidak ada!" << endl;
            else
            {
                cout << "\nData Node : " << node->data << endl;
                cout << "Root : " << root->data << endl;

                if (!node->parent)
                {
                    cout << "Parent : (tidak punya parent)" << endl;
                }
                else
                {
                    cout << "Parent : " << node->parent->data << endl;
                }

                if (node->parent != nullptr && node->parent->left != node && node->parent->right == node)
                {
                    cout << "Sibling : " << node->parent->left->data << endl;
                }
                else if (node->parent != nullptr && node->parent->right != node && node->parent->left == node)
                {
                    cout << "Sibling : " << node->parent->right->data << endl;
                }
                else
                {
                    cout << "Sibling : (tidak punya sibling)" << endl;
                }

                if (!node->left)
                {
                    cout << "Child Kiri : (tidak punya Child kiri)" << endl;
                }
                else
                {
                    cout << "Child Kiri : " << node->left->data << endl;
                }

                if (!node->right)
                {
                    cout << "Child Kanan : (tidak punya Child kanan)" << endl;
                }
                else
                {
                    cout << "Child Kanan : " << node->right->data << endl;
                }
            }
        }
    }

    // Penelusuran (Traversal)
    // preOrder
    void preOrder(Node *node)
    {
        if (isEmpty())
            cout << "\nBuat tree terlebih dahulu!" << endl;
        else
        {
            if (node != nullptr)
            {
                cout << " " << node->data << ", ";
                preOrder(node->left);
                preOrder(node->right);
            }
        }
    }

    // inOrder
    void inOrder(Node *node)
    {
        if (isEmpty())
            cout << "\nBuat tree terlebih dahulu!" << endl;
        else
        {
            if (node != nullptr)
            {
                inOrder(node->left);
                cout << " " << node->data << ", ";
                inOrder(node->right);
            }
        }
    }

    // postOrder
    void postOrder(Node *node)
    {
        if (isEmpty())
            cout << "\nBuat tree terlebih dahulu!" << endl;
        else
        {
            if (node != nullptr)
            {
                postOrder(node->left);
                postOrder(node->right);
                cout << " " << node->data << ", ";
            }
        }
    }

    // Hapus Node Tree
    void deleteTree(Node *node)
    {
        if (isEmpty())
            cout << "\nBuat tree terlebih dahulu!" << endl;
        else
        {
            if (node != nullptr)
            {
                if (node != root)
                {
                    if (node->parent->left == node)
                        node->parent->left = nullptr;
                    else if (node->parent->right == node)
                        node->parent->right = nullptr;
                }

                deleteTree(node->left);
                deleteTree(node->right);

                if (node == root)
                {
                    delete root;
                    root = nullptr;
                }
                else
                {
                    delete node;
                }
            }
        }
    }

    // Hapus SubTree
    void deleteSub(Node *node)
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
            cout << "\nNode berhasil dihapus." << endl;
        }
    }

    // Cek Size Tree
    int size(Node *node)
    {
        if (isEmpty())
        {
            cout << "\nBuat tree terlebih dahulu!!" << endl;
            return 0;
        }
        else
        {
            if (!node)
            {
                return 0;
            }
            else
            {
                return 1 + size(node->left) + size(node->right);
            }
        }
    }

    // Cek Height Level Tree
    int height(Node *node)
    {
        if (isEmpty())
        {
            cout << "\nBuat tree terlebih dahulu!" << endl;
            return 0;
        }
        else
        {
            if (!node)
            {
                return 0;
            }
            else
            {
                int heightKiri = height(node->left);
                int heightKanan = height(node->right);
                if (heightKiri >= heightKanan)
                {
                    return heightKiri + 1;
                }
                else
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

    // Fungsi untuk mendapatkan Node root
    Node *getRoot()
    {
        return root;
    }

    // Fungsi untuk menemukan node tertentu
    Node *findNode(char data, Node *node)
    {
        if (node == nullptr)
            return nullptr;
        if (node->data == data)
            return node;
        Node *leftResult = findNode(data, node->left);
        if (leftResult != nullptr && leftResult->data == data)
            return leftResult;
        return findNode(data, node->right);
    }

    // Fungsi untuk menampilkan semua descendant dari node yang diinputkan
    void displayDescendants(Node *node)
    {
        if (isEmpty())
        {
            cout << "\nBuat tree terlebih dahulu!" << endl;
        }
        else
        {
            if (node == nullptr)
            {
                cout << "\nNode yang ditunjuk tidak ada!" << endl;
            }
            else
            {
                cout << "\nDescendants of node " << node->data << ": ";
                displayDescendantsHelper(node);
                cout << endl;
            }
        }
    }

private:
    void displayDescendantsHelper(Node *node)
    {
        if (node != nullptr)
        {
            if (node != root)
            {
                cout << node->data << " ";
            }
            displayDescendantsHelper(node->left);
            displayDescendantsHelper(node->right);
        }
    }
};

void displayMenu()
{
    cout << "\nMenu:" << endl;
    cout << "1. Buat node root" << endl;
    cout << "2. Tambahkan child kiri" << endl;
    cout << "3. Tambahkan child kanan" << endl;
    cout << "4. Ubah node" << endl;
    cout << "5. Tampilkan data node" << endl;
    cout << "6. Cari node" << endl;
    cout << "7. Preorder traversal" << endl;
    cout << "8. Inorder traversal" << endl;
    cout << "9. Postorder traversal" << endl;
    cout << "10. Hapus subtree" << endl;
    cout << "11. Hapus seluruh tree" << endl;
    cout << "12. Tampilkan karakteristik tree" << endl;
    cout << "13. Tampilkan semua descendant dari node" << endl;
    cout << "14. Keluar" << endl;
    cout << "Pilih menu: ";
}

int main()
{
    Tree tree;
    int pilih_Fatik_2311102190;
    char data, targetData;
    Node *currentNode = nullptr, *targetNode;

    do
    {
        displayMenu();
        cin >> pilih_Fatik_2311102190;

        switch (pilih_Fatik_2311102190)
        {
        case 1:
            if (tree.isEmpty())
            {
                cout << "Masukkan data untuk root: ";
                cin >> data;
                tree.makeBranch(data);
                currentNode = tree.getRoot();
            }
            else
            {
                cout << "Tree sudah dibuat!" << endl;
            }
            break;

        case 2:
            if (!tree.isEmpty())
            {
                cout << "Masukkan pohon yang ingin ditambah child-nya: ";
                cin >> targetData;
                cout << "Masukkan data untuk child kiri: ";
                cin >> data;

                targetNode = tree.findNode(targetData, currentNode);

                tree.insertLeft(data, targetNode);
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 3:
            if (!tree.isEmpty())
            {
                cout << "Masukkan pohon yang ingin ditambah child-nya: ";
                cin >> targetData;
                cout << "Masukkan data untuk child kanan: ";
                cin >> data;

                targetNode = tree.findNode(targetData, currentNode);

                tree.insertRight(data, targetNode);
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 4:
            if (!tree.isEmpty())
            {
                cout << "Masukkan pohon yang ingin diganti: ";
                cin >> targetData;
                cout << "Masukkan data baru untuk pohon: ";
                cin >> data;

                targetNode = tree.findNode(targetData, currentNode);

                tree.update(data, targetNode);
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 5:
            if (!tree.isEmpty())
            {
                cout << "Masukkan pohon yang ingin ditampilkan: ";
                cin >> targetData;

                targetNode = tree.findNode(targetData, currentNode);

                tree.retrieve(targetNode);
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 6:
            if (!tree.isEmpty())
            {
                cout << "Masukkan pohon yang ingin dicari: ";
                cin >> targetData;

                targetNode = tree.findNode(targetData, currentNode);

                tree.find(targetNode);
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 7:
            if (!tree.isEmpty())
            {
                cout << "Preorder traversal: ";
                tree.preOrder(tree.getRoot());
                cout << endl;
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 8:
            if (!tree.isEmpty())
            {
                cout << "Inorder traversal: ";
                tree.inOrder(tree.getRoot());
                cout << endl;
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 9:
            if (!tree.isEmpty())
            {
                cout << "Postorder traversal: ";
                tree.postOrder(tree.getRoot());
                cout << endl;
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 10:
            if (!tree.isEmpty())
            {
                cout << "Masukkan pohon yang ingin di delete sub tree-nya: ";
                cin >> targetData;

                targetNode = tree.findNode(targetData, currentNode);

                tree.deleteSub(targetNode);
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 11:
            if (!tree.isEmpty())
            {
                tree.clear();
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 12:
            if (!tree.isEmpty())
            {
                tree.characteristic();
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 13:
            if (!tree.isEmpty())
            {
                cout << "Masukkan node yang ingin dilihat descendants-nya: ";
                cin >> targetData;

                targetNode = tree.findNode(targetData, currentNode);

                tree.displayDescendants(targetNode);
            }
            else
            {
                cout << "Tree belum dibuat!" << endl;
            }
            break;

        case 14:
            cout << "Keluar dari program." << endl;
            break;

        default:
            cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }
    } while (pilih_Fatik_2311102190 != 14);

    return 0;
}

```
#### Output:
![Screenshot 2024-05-28 233602](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/a760e045-81dc-4951-8efd-132df741d6fa)

![Screenshot 2024-05-28 233637](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/1ab2efaa-7f32-4648-918b-b4db5c485672)

![Screenshot 2024-05-28 233858](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/91adaf6a-8bc5-45f2-834d-9bd22a7278ed)

![Screenshot 2024-05-28 234358](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/5b6a59b4-a053-4812-ba93-66cd302b6173)

![Screenshot 2024-05-28 234426](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/b2ae1315-148a-440b-8636-a1e93d4857c6)

![Screenshot 2024-05-28 234520](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/cd7a2159-0e2d-436f-8e95-5dc3a937e3d5)

![Screenshot 2024-05-28 234558](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/f849773a-5834-4b43-bc85-6ec349a88852)

![Screenshot 2024-05-28 234650](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/497a96e8-26da-4d04-907e-36d43123870d)

![Screenshot 2024-05-28 234716](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/0fe373c4-a853-42ab-9661-53ae023728bd)

![Screenshot 2024-05-28 234755](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/dde6800e-e9cb-4d07-bb40-95f4a845dc1e)

![Screenshot 2024-05-28 234843](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/caa2910e-c8b2-47d1-bbd3-da4ef5cc06a1)

![Screenshot 2024-05-28 234918](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/7a416c12-fd06-44f9-9e0d-9d3607c1e23b)

![Screenshot 2024-05-28 234939](https://github.com/FatikNurimamah/Struktur-Data-Assignment/assets/162486157/37ff965b-d886-4503-878b-c83bc8a2ba30)

Deskripsi Program: Program ini adalah implementasi dari struktur data tree dalam bahasa C++. Program ini terdapat berbagai fungsi yaitu: membuat root, menambahkan child kiri dan kanan, memperbarui data node, menampilkan data node, mencari node, melakukan traversal preorder, inorder, dan postorder, menghapus subtree, menghapus seluruh tree, serta menampilkan karakteristik tree seperti ukuran dan tinggi, dan menampilkan semua keturunan dari node tertentu. Program ini memiliki banyak menu yang dapat digunakan oleh pengguna untuk memilih operasi yang diinginkan. Hubungan antar node dikelola dengan pointer dan rekursi digunakan untuk traversal dan penghapusan subtree.

## Kesimpulan

1. Graph: Graph adalah struktur yang terdiri dari simpul (vertex) yang dihubungkan oleh sisi (edge), , digunakan untuk menggambarkan objek-objek dan hubungan antar objeknya. Graph dilambangkan sebagai G = (V, E), di mana V adalah kumpulan vertex atau simpul dan E adalah kumpulan edge atau sisi.

2. Tree merupakan struktur data yang hierarkis, terdiri dari simpul-simpul dengan satu simpul istimewa sebagai root. Terdapat berbagai konsep dalam tree, seperti predecessor, successor, ancestor, descendant, parent, child, sibling, subtree, size, height, root, leaf, dan degree. Binary tree adalah bentuk khusus dari tree di mana setiap node memiliki paling banyak dua child yang terpisah, memfasilitasi representasi data dengan hierarki yang jelas.

   
## Referensi
[1] Safei, M. Rian. "PENGERTIAN STRUKTUR DATA NON LINIER." (2019).

[2] HANDISHA, CICI. "Fakultas Komputer."
