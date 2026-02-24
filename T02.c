#include <stdio.h>

int main() {
    int n, kode, total = 0;

    printf("=== Program Penjumlahan Nilai Kelompok ===\n");

    // 1. Input jumlah data (N)
    printf("Masukkan jumlah mahasiswa (N): ");
    scanf("%d", &n);

    // Deklarasi array dengan ukuran n
    int nilai[n];

    // 2. Input deret nilai (n1, n2, ..., nN)
    for (int i = 0; i < n; i++) {
        printf("Masukkan nilai mahasiswa ke-%d: ", i + 1);
        scanf("%d", &nilai[i]);
    }

    // 3. Input Kode Kelompok
    printf("\nPilih Kode Kelompok:\n");
    printf("1. Kelompok Ganjil (Siswa ke-1, 3, 5...)\n");
    printf("2. Kelompok Genap (Siswa ke-2, 4, 6...)\n");
    printf("Masukkan kode kelompok: ");
    scanf("%d", &kode);

    // Logika perhitungan berdasarkan kode kelompok
    printf("\nMenghitung total nilai...\n");
    for (int i = 0; i < n; i++) {
        // Ingat: Indeks array dimulai dari 0 (siswa ke-1)
        if (kode == 1) {
            // Kelompok Ganjil: Indeks 0, 2, 4... (i+1 adalah ganjil)
            if ((i + 1) % 2 != 0) {
                total += nilai[i];
            }
        } else if (kode == 2) {
            // Kelompok Genap: Indeks 1, 3, 5... (i+1 adalah genap)
            if ((i + 1) % 2 == 0) {
                total += nilai[i];
            }
        }
    }

    // Menampilkan hasil akhir
    printf("------------------------------------------\n");
    printf("Total nilai untuk kelompok %d adalah: %d\n", kode, total);
    printf("------------------------------------------\n");

    return 0;
}