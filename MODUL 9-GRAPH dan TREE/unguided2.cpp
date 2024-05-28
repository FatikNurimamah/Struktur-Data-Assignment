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

