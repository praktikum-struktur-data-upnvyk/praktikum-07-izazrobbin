// =============================================================================
// student.cpp — Implementasi Mahasiswa
// Pertemuan 7: Binary Tree dan Traversal
// =============================================================================
// FILE YANG BOLEH DIEDIT      : src/student.cpp  ← HANYA FILE INI
// FILE YANG TIDAK BOLEH DIEDIT: src/student.h, tests/checker.cpp, tests/report.h
//
// -----------------------------------------------------------------------------
// CARA MEMBACA SOAL DI FILE INI
// -----------------------------------------------------------------------------
// Setiap soal ditulis tepat di atas fungsinya, dengan empat bagian yang sama:
//
//     Ceritanya          — apa yang sedang terjadi, dan apa yang diminta
//     Parameternya       — arti setiap parameter, satu per satu
//     Contoh             — contoh nyata beserta hasil yang benar
//     Yang perlu diingat — hal khusus yang ikut dinilai
//
// Seluruhnya ada 3 soal dan 5 fungsi:
//
//     Soal 1   Traversal      preorder, inorder, postorder    60 poin
//     Soal 2b  Membersihkan   clear                           25 poin
//     Soal 3   Soal cerita    jumlahDaun                      15 poin
//
// Nama parameter dan nama field selalu ditulis di antara tanda petik miring,
// misalnya `root` atau `left`, supaya mudah dibedakan dari kata biasa.
// =============================================================================

#include "student.h"

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// =============================================================================
// SOAL 1a — preorder                                                   20 poin
// =============================================================================
// Urutan: root, subtree kiri, subtree kanan.
// Contoh hasil: 50 80 10 70 30 20 90
// =============================================================================
void preorder(const Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// =============================================================================
// SOAL 1b — inorder                                                    20 poin
// =============================================================================
// Urutan: subtree kiri, root, subtree kanan.
// Contoh hasil: 10 80 30 70 50 20 90
// =============================================================================
void inorder(const Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// =============================================================================
// SOAL 1c — postorder                                                  20 poin
// =============================================================================
// Urutan: subtree kiri, subtree kanan, root.
// Contoh hasil: 10 30 70 80 90 20 50
// =============================================================================
void postorder(const Node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// =============================================================================
// SOAL 2b — clear                                                      25 poin
// =============================================================================
// Menghapus semua node dari memori dan mengubah root menjadi NULL.
// Aman dipanggil pada tree kosong maupun dipanggil berulang kali.
// =============================================================================
void clear(Node*& root) {
    if (root == NULL) {
        return;
    }

    clear(root->left);
    clear(root->right);

    delete root;
    root = NULL;
}

// =============================================================================
// SOAL 3 — jumlahDaun                          SOAL CERITA             15 poin
// =============================================================================
// Daun adalah node yang tidak mempunyai anak kiri maupun anak kanan.
// =============================================================================
int jumlahDaun(const Node* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    return jumlahDaun(root->left) + jumlahDaun(root->right);
}

// =============================================================================
// MAIN() — program Anda sendiri. TIDAK dinilai, bebas diubah.
// =============================================================================

#ifndef ADA_MAIN_LAIN

// Membangun tree contoh yang dipakai di seluruh soal:
//
//               50
//              /  \
//            80    20
//           /  \     \
//         10    70    90
//              /
//            30

static Node* buatTreeContoh() {
    Node* root              = new Node{50, NULL, NULL};
    root->left              = new Node{80, NULL, NULL};
    root->right             = new Node{20, NULL, NULL};
    root->left->left        = new Node{10, NULL, NULL};
    root->left->right       = new Node{70, NULL, NULL};
    root->right->right      = new Node{90, NULL, NULL};
    root->left->right->left = new Node{30, NULL, NULL};
    return root;
}

// Membangun tree yang menjulur lurus ke bawah: 5 -> 4 -> 3.
static Node* buatTreeMiring() {
    Node* root       = new Node{5, NULL, NULL};
    root->left       = new Node{4, NULL, NULL};
    root->left->left = new Node{3, NULL, NULL};
    return root;
}

// Menulis satu baris keterangan dengan lebar label yang seragam.
static ostream& baris(const string& label) {
    return cout << "    " << left << setw(12) << label << ": ";
}

// Menjalankan ketiga traversal pada satu tree.
static void tampilkanTraversal(const Node* root) {
    baris("preorder");
    preorder(root);
    cout << "\n";

    baris("inorder");
    inorder(root);
    cout << "\n";

    baris("postorder");
    postorder(root);
    cout << "\n";
}

// Menampilkan hitungan daun pada satu tree.
static void tampilkanHitungan(const Node* root) {
    baris("jumlahDaun") << jumlahDaun(root) << "\n";
}

int main() {
    cout << "==========================================\n";
    cout << " Latihan — Binary Tree dan Traversal\n";
    cout << " (bagian ini tidak ikut dinilai)\n";
    cout << "==========================================\n";

    // Tree contoh.
    Node* root = buatTreeContoh();

    cout << "\n[1] Tree contoh\n\n";
    cout << "              50\n";
    cout << "             /  \\\n";
    cout << "           80    20\n";
    cout << "          /  \\     \\\n";
    cout << "        10    70    90\n";
    cout << "             /\n";
    cout << "           30\n\n";

    // Soal 1 — ketiga traversal.
    cout << "[2] Soal 1 — ketiga traversal\n";
    tampilkanTraversal(root);

    cout << "\n";
    cout << "    Jawaban yang benar menurut modul:\n";
    cout << "      preorder    : 50 80 10 70 30 20 90\n";
    cout << "      inorder     : 10 80 30 70 50 20 90\n";
    cout << "      postorder   : 10 30 70 80 90 20 50\n";

    // Soal 3 — menghitung jumlah daun.
    cout << "\n[3] Soal 3 — menghitung jumlah daun\n";
    tampilkanHitungan(root);

    cout << "\n";
    cout << "    Jawaban yang benar: jumlahDaun = 3\n";

    // Tree kosong.
    cout << "\n[4] Tree kosong (root = NULL)\n";
    Node* kosong = NULL;
    tampilkanTraversal(kosong);
    tampilkanHitungan(kosong);

    cout << "\n    Yang benar: ketiga traversal tidak mencetak apa pun,\n";
    cout << "                jumlahDaun = 0\n";

    // Tree satu node.
    cout << "\n[5] Tree berisi satu node (42)\n";
    Node* satu = new Node{42, NULL, NULL};
    tampilkanTraversal(satu);
    tampilkanHitungan(satu);

    cout << "\n    Yang benar: ketiganya mencetak 42,\n";
    cout << "                jumlahDaun = 1\n";

    // Tree miring.
    cout << "\n[6] Tree yang menjulur lurus ke bawah (5 -> 4 -> 3)\n";
    Node* miring = buatTreeMiring();
    tampilkanTraversal(miring);
    tampilkanHitungan(miring);

    cout << "\n    Yang benar: preorder 5 4 3, inorder 3 4 5, postorder 3 4 5,\n";
    cout << "                jumlahDaun = 1\n";

    // Soal 2b — membuang seluruh isi tree.
    cout << "\n[7] Soal 2b — clear(root)\n";
    clear(root);
    baris("root") << (root == NULL ? "NULL" : "masih terisi") << "\n";

    cout << "\n    Yang benar: root = NULL\n";

    cout << "\n==========================================\n";
    cout << " Selesai. Silakan ubah bagian ini untuk\n";
    cout << " mencoba percobaan Anda sendiri.\n";
    cout << "==========================================\n";

    // Membersihkan sisa tree sebelum program berakhir.
    clear(satu);
    clear(miring);
    clear(root);

    return 0;
}
#endif
```