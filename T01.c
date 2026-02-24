#include <stdio.h>
#include <string.h>

int main() {

    char kode[10];
    char nama[50];

    char listNama[100][50];
    int listPorsi[100];
    int listHarga[100];
    int listTotal[100];

    int porsi;
    int harga;
    int total;
    int i = 0;
    int grandTotal = 0;

    while (1) {
        scanf("%s", kode);

        if (strcmp(kode, "END") == 0)
            break;

        scanf("%d", &porsi);

        // Mapping kode menu sesuai gambar
        if (strcmp(kode, "NGS") == 0) {
            strcpy(nama, "Nasi Goreng Spesial");
            harga = 15000;
        }
        else if (strcmp(kode, "AP") == 0) {
            strcpy(nama, "Ayam Penyet");
            harga = 20000;
        }
        else if (strcmp(kode, "SA") == 0) {
            strcpy(nama, "Sate Ayam");
            harga = 25000;
        }
        else if (strcmp(kode, "BU") == 0) {
            strcpy(nama, "Bakso Urat");
            harga = 18000;
        }
        else if (strcmp(kode, "MAP") == 0) {
            strcpy(nama, "Mie Ayam Pangsit");
            harga = 15000;
        }
        else if (strcmp(kode, "GG") == 0) {
            strcpy(nama, "Gado-Gado");
            harga = 15000;
        }
        else if (strcmp(kode, "SAM") == 0) {
            strcpy(nama, "Soto Ayam");
            harga = 17000;
        }
        else if (strcmp(kode, "RD") == 0) {
            strcpy(nama, "Rendang Daging");
            harga = 25000;
        }
        else if (strcmp(kode, "IB") == 0) {
            strcpy(nama, "Ikan Bakar");
            harga = 35000;
        }
        else if (strcmp(kode, "NUK") == 0) {
            strcpy(nama, "Nasi Uduk Komplit");
            harga = 20000;
        }

        total = harga * porsi;

        strcpy(listNama[i], nama);
        listPorsi[i] = porsi;
        listHarga[i] = harga;
        listTotal[i] = total;

        grandTotal += total;
        i++;
    }

    // =========================
    // HITUNG DISKON SESUAI KUPON
    // =========================
    double diskon = 0;

    if (grandTotal >= 500000) diskon = 0.25;
    else if (grandTotal >= 400000) diskon = 0.20;
    else if (grandTotal >= 300000) diskon = 0.15;
    else if (grandTotal >= 200000) diskon = 0.10;
    else if (grandTotal >= 100000) diskon = 0.05;

    int potongan = grandTotal * diskon;
    int totalAkhir = grandTotal - potongan;

    // =========================
    // CETAK STRUK SESUAI FORMAT
    // =========================
    printf("\n");
    printf("Menu                     Porsi     Harga     Total\n");
    printf("==================================================\n");

    for (int j = 0; j < i; j++) {
        printf("%-24s %5d %10d %10d\n",
               listNama[j],
               listPorsi[j],
               listHarga[j],
               listTotal[j]);
    }

    printf("==================================================\n");
    printf("Total Pembayaran%29d\n", totalAkhir);

    return 0;
}