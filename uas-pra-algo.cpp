#include <iostream>
#include <string>
using namespace std;

// Struk informasi mahasiswa
struct Mahasiswa {
    int nim;
    string nama;
    string jurusan;
    int semester;
};
// Konstanta
const int MAX_MAHASISWA = 100;

// menambah
void tambahMahasiswa(Mahasiswa dataMahasiswa[][MAX_MAHASISWA], int& jumlahMahasiswa) ;
// menampilkan
void tampilkanDataMahasiswa(const Mahasiswa dataMahasiswa[][MAX_MAHASISWA], int jumlahMahasiswa) ;
// mencari
void cariMahasiswa(const Mahasiswa dataMahasiswa[][MAX_MAHASISWA], int jumlahMahasiswa, int nimCari) ;
// menghapus
void hapusMahasiswa(Mahasiswa dataMahasiswa[][MAX_MAHASISWA], int& jumlahMahasiswa, int nimHapus) ;


int main() {
    Mahasiswa dataMahasiswa[2][MAX_MAHASISWA];  // Array 2 dimensi untuk menyimpan data mahasiswa
    int jumlahMahasiswa = 0;  // Jumlah mahasiswa yang saat ini ada

    char pilihan;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Tampilkan Data Mahasiswa\n";
        cout << "3. Cari Mahasiswa\n";
        cout << "4. Hapus Mahasiswa\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case '1':
                tambahMahasiswa(dataMahasiswa, jumlahMahasiswa);
                break;
            case '2':
                tampilkanDataMahasiswa(dataMahasiswa, jumlahMahasiswa);
                break;
            case '3': {
                int nimCari;
                cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
                cin >> nimCari;
                cariMahasiswa(dataMahasiswa, jumlahMahasiswa, nimCari);
                break;
            }
            case '4': {
                int nimHapus;
                cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
                cin >> nimHapus;
                hapusMahasiswa(dataMahasiswa, jumlahMahasiswa, nimHapus);
                break;
            }
            case '5':
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

    } while (pilihan != '5');

    return 0;
}


// Fungsi untuk menambahkan data mahasiswa
void tambahMahasiswa(Mahasiswa dataMahasiswa[][MAX_MAHASISWA], int& jumlahMahasiswa) {
    if (jumlahMahasiswa < MAX_MAHASISWA) {
        Mahasiswa mahasiswaBaru;

        cout << "Masukkan NIM mahasiswa: ";
        cin >> mahasiswaBaru.nim;
        cin.ignore();

        cout << "Masukkan nama mahasiswa: ";
        getline(cin, mahasiswaBaru.nama);

        cout << "Masukkan jurusan mahasiswa: ";
        getline(cin, mahasiswaBaru.jurusan);

        cout << "Masukkan semester mahasiswa: ";
        cin >> mahasiswaBaru.semester;

        dataMahasiswa[jumlahMahasiswa / MAX_MAHASISWA][jumlahMahasiswa % MAX_MAHASISWA] = mahasiswaBaru;
        jumlahMahasiswa++;

        cout << "Data mahasiswa berhasil ditambahkan.\n";
    } else {
        cout << "Jumlah mahasiswa sudah mencapai batas maksimum.\n";
    }
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanDataMahasiswa(const Mahasiswa dataMahasiswa[][MAX_MAHASISWA], int jumlahMahasiswa) {
    cout << "Data Mahasiswa:\n";
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        cout << "NIM: " << dataMahasiswa[i / MAX_MAHASISWA][i % MAX_MAHASISWA].nim
             << ", Nama: " << dataMahasiswa[i / MAX_MAHASISWA][i % MAX_MAHASISWA].nama
             << ", Jurusan: " << dataMahasiswa[i / MAX_MAHASISWA][i % MAX_MAHASISWA].jurusan
             << ", Semester: " << dataMahasiswa[i / MAX_MAHASISWA][i % MAX_MAHASISWA].semester << "\n";
    }
}

// Fungsi untuk mencari mahasiswa berdasarkan NIM
void cariMahasiswa(const Mahasiswa dataMahasiswa[][MAX_MAHASISWA], int jumlahMahasiswa, int nimCari) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        if (dataMahasiswa[i / MAX_MAHASISWA][i % MAX_MAHASISWA].nim == nimCari) {
            cout << "Mahasiswa ditemukan:\n";
            cout << "NIM: " << dataMahasiswa[i / MAX_MAHASISWA][i % MAX_MAHASISWA].nim
                 << ", Nama: " << dataMahasiswa[i / MAX_MAHASISWA][i % MAX_MAHASISWA].nama
                 << ", Jurusan: " << dataMahasiswa[i / MAX_MAHASISWA][i % MAX_MAHASISWA].jurusan
                 << ", Semester: " << dataMahasiswa[i / MAX_MAHASISWA][i % MAX_MAHASISWA].semester << "\n";
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Mahasiswa dengan NIM " << nimCari << " tidak ditemukan.\n";
    }
}

// Fungsi untuk menghapus data mahasiswa berdasarkan NIM
void hapusMahasiswa(Mahasiswa dataMahasiswa[][MAX_MAHASISWA], int& jumlahMahasiswa, int nimHapus) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        if (dataMahasiswa[i / MAX_MAHASISWA][i % MAX_MAHASISWA].nim == nimHapus) {
            for (int j = i; j < jumlahMahasiswa - 1; ++j) {
                dataMahasiswa[j / MAX_MAHASISWA][j % MAX_MAHASISWA] = dataMahasiswa[(j + 1) / MAX_MAHASISWA][(j + 1) % MAX_MAHASISWA];
            }
            jumlahMahasiswa--;
            cout << "Data mahasiswa dengan NIM " << nimHapus << " berhasil dihapus.\n";
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Mahasiswa dengan NIM " << nimHapus << " tidak ditemukan.\n";
    }
}
