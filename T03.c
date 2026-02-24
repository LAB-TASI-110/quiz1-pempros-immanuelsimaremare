#include <stdio.h>
#include <string.h>

// Struktur data untuk pesanan laundry
struct Pesanan {
    char nama[50];
    char asrama[30];
    int jumlah_pakaian;
    int tgl_jemput, bln_jemput;
    int tgl_antar, bln_antar;
    int lama_hari;
};

int main() {
    int n;

    printf("=========================================\n");
    printf("     SISTEM OPERASIONAL LAUNDRY DEL      \n");
    printf("=========================================\n");
    
    printf("Masukkan jumlah transaksi hari ini: ");
    scanf("%d", &n);
    getchar(); // Membersihkan buffer

    struct Pesanan data[n];

    // Proses Input
    for (int i = 0; i < n; i++) {
        printf("\n--- Data Mahasiswa ke-%d ---\n", i + 1);
        
        printf("Nama Mahasiswa     : ");
        fgets(data[i].nama, sizeof(data[i].nama), stdin);
        data[i].nama[strcspn(data[i].nama, "\n")] = 0; // Menghapus enter di akhir string

        printf("Asrama             : ");
        fgets(data[i].asrama, sizeof(data[i].asrama), stdin);
        data[i].asrama[strcspn(data[i].asrama, "\n")] = 0;

        printf("Total Pakaian (pcs): ");
        scanf("%d", &data[i].jumlah_pakaian);

        printf("Tanggal Penjemputan (Tgl Bln, contoh: 24 2): ");
        scanf("%d %d", &data[i].tgl_jemput, &data[i].bln_jemput);

        printf("Tanggal Pengantaran (Tgl Bln, contoh: 26 2): ");
        scanf("%d %d", &data[i].tgl_antar, &data[i].bln_antar);
        getchar(); // Membersihkan buffer untuk input selanjutnya

        // Logika Perhitungan Lama Pengerjaan
        // Rumus: (Bulan Antar - Bulan Jemput) * 30 + (Tgl Antar - Tgl Jemput)
        int total_hari_jemput = (data[i].bln_jemput * 30) + data[i].tgl_jemput;
        int total_hari_antar = (data[i].bln_antar * 30) + data[i].tgl_antar;
        data[i].lama_hari = total_hari_antar - total_hari_jemput;
    }

    // Output Hasil (Tabel Rekapitulasi)
    printf("\n\n================================ REKAPITULASI OPERASIONAL LAUNDRY DEL ================================\n");
    printf("| %-15s | %-10s | %-7s | %-12s | %-12s | %-10s |\n", 
           "Nama", "Asrama", "Pcs", "Tgl Jemput", "Tgl Antar", "Lama");
    printf("------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        char str_jemput[20], str_antar[20], str_lama[15];
        
        // Format tanggal agar mudah dibaca
        sprintf(str_jemput, "%02d/%02d", data[i].tgl_jemput, data[i].bln_jemput);
        sprintf(str_antar, "%02d/%02d", data[i].tgl_antar, data[i].bln_antar);
        sprintf(str_lama, "%d Hari", data[i].lama_hari);

        printf("| %-15s | %-10s | %-7d | %-12s | %-12s | %-10s |\n", 
               data[i].nama, 
               data[i].asrama, 
               data[i].jumlah_pakaian, 
               str_jemput, 
               str_antar, 
               str_lama);
    }
    printf("======================================================================================================\n");

    return 0;
}