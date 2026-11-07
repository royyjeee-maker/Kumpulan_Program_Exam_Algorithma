#include <stdio.h>

int main() {
    int nilai[6];
    int total = 0;
    int jumlahAB = 0;
    float rataRata;
    int i;
    char grade;

    // Memasukkan nilai 6 mahasiswa
    printf("=== PROGRAM NILAI UJIAN MAHASISWA ===\n");

    for (i = 0; i < 6; i++) {
        printf("Masukkan nilai mahasiswa ke-%d: ", i + 1);
        scanf("%d", &nilai[i]);
    }

    // Memproses nilai dan menentukan grade
    printf("\n=== HASIL NILAI MAHASISWA ===\n");

    
for (i = 0; i < 6; i++) {  // Mengulang proses untuk 6 mahasiswa.
    total += nilai[i];     // Menambahkan nilai mahasiswa ke total.

    if (nilai[i] >= 85) {  // Memeriksa apakah nilai minimal 85.
        grade = 'A';       // Memberikan grade A.
    }
    else if (nilai[i] >= 70) { // Memeriksa apakah nilai minimal 70.
        grade = 'B';           // Memberikan grade B.
    }
    else if (nilai[i] >= 55) { // Memeriksa apakah nilai minimal 55.
        grade = 'C';           // Memberikan grade C.
    }
    else if (nilai[i] >= 40) { // Memeriksa apakah nilai minimal 40.
        grade = 'D';           // Memberikan grade D.
    }
    else {                     // Jika tidak memenuhi kondisi sebelumnya.
        grade = 'E';           // Memberikan grade E.
    }

    if (grade == 'A' || grade == 'B') { // Memeriksa grade A atau B.
        jumlahAB++;                     // Menambah jumlah mahasiswa A/B.
    }

    printf("Mahasiswa %d: Nilai = %d, Grade = %c\n",
           i + 1, nilai[i], grade); // Menampilkan nomor, nilai, dan grade.
}


    // Menghitung rata-rata
    rataRata = (float) total / 6;

    // Menampilkan hasil akhir
    printf("\n=== HASIL PERHITUNGAN ===\n");
    printf("Total nilai       : %d\n", total);
    printf("Rata-rata nilai   : %.2f\n", rataRata);
    printf("Jumlah grade A/B  : %d mahasiswa\n", jumlahAB);

    return 0;
}
