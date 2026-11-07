#include <stdio.h>

// Membuat struktur data karyawan
struct Karyawan {
    char nama[30];
    int gaji;
};

int main() {
    struct Karyawan data[8];

    FILE *fileInput;
    FILE *fileOutput;

    int i;
    int totalData = 0;
    int jumlahMemenuhi = 0;
    int jumlahTidakMemenuhi = 0;
    int totalGaji = 0;

    int gajiTertinggi;
    int gajiTerendah;

    float rataRata;

    // Membuka file karyawan.txt untuk dibaca
    fileInput = fopen("karyawan.txt", "r");

    // Memeriksa apakah file input berhasil dibuka
    if (fileInput == NULL) {
        printf("Error: File karyawan.txt tidak ditemukan!\n");
        return 1;
    }

    // Membuka file gaji_tinggi.txt untuk ditulis
    fileOutput = fopen("gaji_tinggi.txt", "w");

    // Memeriksa apakah file output berhasil dibuka
    if (fileOutput == NULL) {
        printf("Error: File gaji_tinggi.txt gagal dibuat!\n");
        fclose(fileInput);
        return 1;
    }

    // Membaca dan memproses 8 data karyawan
    for (i = 0; i < 8; i++) {

        // Membaca nama dan gaji dari file
        if (fscanf(fileInput, "%29s %d",
                   data[i].nama, &data[i].gaji) != 2) {
            printf("Error: Data karyawan tidak lengkap!\n");
            fclose(fileInput);
            fclose(fileOutput);
            return 1;
        }

        // Menghitung total seluruh gaji
        totalGaji += data[i].gaji;

        // Menghitung jumlah data karyawan
        totalData++;

        // Menentukan gaji tertinggi dan terendah
        if (i == 0) {
            gajiTertinggi = data[i].gaji;
            gajiTerendah = data[i].gaji;
        } else {
            if (data[i].gaji > gajiTertinggi) {
                gajiTertinggi = data[i].gaji;
            }

            if (data[i].gaji < gajiTerendah) {
                gajiTerendah = data[i].gaji;
            }
        }

        // Memeriksa karyawan dengan gaji minimal 5 juta
        if (data[i].gaji >= 5000000) {

            // Menulis data yang memenuhi syarat ke file output
            fprintf(fileOutput, "%s %d\n",
                    data[i].nama, data[i].gaji);

            jumlahMemenuhi++;

        } else {
            jumlahTidakMemenuhi++;
        }
    }

    // Menghitung rata-rata gaji seluruh karyawan
    rataRata = (float) totalGaji / totalData;

    // Menampilkan hasil pengolahan data
    printf("=== HASIL DATA KARYAWAN ===\n");
    printf("Total data karyawan       : %d\n", totalData);
    printf("Memenuhi syarat           : %d\n", jumlahMemenuhi);
    printf("Tidak memenuhi syarat     : %d\n", jumlahTidakMemenuhi);
    printf("Gaji tertinggi             : Rp%d\n", gajiTertinggi);
    printf("Gaji terendah              : Rp%d\n", gajiTerendah);
    printf("Rata-rata gaji             : Rp%.2f\n", rataRata);

    printf("\nData gaji tinggi berhasil disimpan!\n");

    // Menutup kedua file
    fclose(fileInput);
    fclose(fileOutput);

    return 0;
}
