#include <iostream>
#include <string>

using namespace std;

// Struktur untuk data kursi
struct Kursi {
    string nomor;
    bool tersedia;
};

// Struktur untuk data film
struct Film {
    string judul;
    int harga;
};

// Fungsi untuk menampilkan daftar kursi
void tampilkanDaftarKursi(Kursi daftarKursi[], int jumlahKursi) {
    cout << "Daftar kursi yang tersedia:" << endl;
    for (int i = 0; i < jumlahKursi; ++i) {
        cout << "Kursi " << daftarKursi[i].nomor;
        if (daftarKursi[i].tersedia) {
            cout << " - Tersedia" << endl;
        } else {
            cout << " - Sudah Dipesan" << endl;
        }
    }
}

// Fungsi untuk menampilkan menu film
void tampilkanMenuFilm(Film daftarFilm[], int jumlahFilm) {
    cout << "Daftar film yang tersedia:" << endl;
    for (int i = 0; i < jumlahFilm; ++i) {
        cout << i+1 << ". " << daftarFilm[i].judul << " - Rp" << daftarFilm[i].harga << endl;
    }
}

// Fungsi untuk menghitung total harga tiket film
int hitungTotalHargaFilm(Film daftarFilm[], int jumlahFilm, int beli[]) {
    int totalHarga = 0;
    for (int i = 0; i < jumlahFilm; ++i) {
        totalHarga += daftarFilm[i].harga * beli[i];
    }
    return totalHarga;
}

int main() {
    // Inisialisasi daftar kursi
    const int JUMLAH_KURSI = 10;
    Kursi daftarKursi[JUMLAH_KURSI];
    for (int i = 0; i < JUMLAH_KURSI; ++i) {
        daftarKursi[i].nomor = "A" + to_string(i+1);
        daftarKursi[i].tersedia = true;
    }

    // Inisialisasi daftar film
    const int JUMLAH_FILM = 3;
    Film daftarFilm[JUMLAH_FILM] = {
        {"Inside Out 2", 45000},
        {"Agak Laen", 45000},
        {"Exhuma", 50000},
    };

    // Inisialisasi jumlah tiket yang dibeli untuk film
    int beliFilm[JUMLAH_FILM] = {0};

    // Menampilkan daftar kursi
    tampilkanDaftarKursi(daftarKursi, JUMLAH_KURSI);

    // Memilih kursi
    string nomorKursi;
    cout << "\nMasukkan nomor kursi yang ingin dipesan: ";
    cin >> nomorKursi;

    // Memeriksa ketersediaan kursi
    for (int i = 0; i < JUMLAH_KURSI; ++i) {
        if (daftarKursi[i].nomor == nomorKursi) {
            if (daftarKursi[i].tersedia) {
                cout << "Kursi " << nomorKursi << " berhasil dipesan." << endl;
                daftarKursi[i].tersedia = false;
            } else {
                cout << "Maaf, kursi " << nomorKursi << " sudah dipesan. Silakan pilih kursi lain." << endl;
            }
            break;
        }
        if (i == JUMLAH_KURSI - 1) {
            cout << "Nomor kursi tidak valid." << endl;
        }
    }

    // Menampilkan daftar kursi setelah memesan
    cout << "\nDaftar kursi setelah pemesanan:" << endl;
    tampilkanDaftarKursi(daftarKursi, JUMLAH_KURSI);

    // Menampilkan menu film
    tampilkanMenuFilm(daftarFilm, JUMLAH_FILM);

    // Meminta pengguna untuk memilih film
    int pilihan;
    do {
        cout << "\nMasukkan nomor film yang ingin ditonton (0 untuk selesai): ";
        cin >> pilihan;
        if (pilihan >= 1 && pilihan <= JUMLAH_FILM) {
            int jumlah;
            cout << "Masukkan jumlah tiket untuk " << daftarFilm[pilihan-1].judul << ": ";
            cin >> jumlah;
            beliFilm[pilihan-1] += jumlah;
        } else if (pilihan != 0) {
            cout << "Nomor film tidak valid. Silahkan coba lagi." << endl;
        }
    } while (pilihan != 0);

    // Menghitung total harga tiket film
    int totalHargaFilm = hitungTotalHargaFilm(daftarFilm, JUMLAH_FILM, beliFilm);

    // Meminta pengguna untuk memberikan uang
    int uang;
    cout <<"\nTotal harga tiket film: Rp" << totalHargaFilm << endl;
    do {
        cout << "Masukkan uang Anda: Rp";
        cin >> uang;
        if (uang < totalHargaFilm) {
            cout << "Uang Anda kurang. Silahkan masukkan uang yang cukup.";
        }
    } while (uang < totalHargaFilm);

    // Menghitung kembalian
    int kembalian = uang - totalHargaFilm;
    cout << "Kembalian Anda: Rp" << kembalian << endl;

    return 0;
}