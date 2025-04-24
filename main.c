#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/kota.h"
#include "header/listorang.h"
#include "header/boolean.h"

int main() {

    Kota *pilihkota;

    infotype namakotalama, namakota;
    addressKota PrecKota;
    int jumlahkota;
    int running = 1;

    infotype nama, namalama;
    address Prec;
    int jumlah;

    int pil, indexkota, pil2;

    List listkota;

    CreateListKota(&listkota);

    while (running) {
        pilihkota = NULL;
        
        printf("\n==== Menu Kota ====\n");
        printf("Pilihlah Menu Berikut : \n");
        printf("1. Tambah Kota Depan\n");
        printf("2. Tambah Kota Belakang\n");
        printf("3. Tambah Kota After\n");
        printf("4. Hapus Kota Depan\n");
        printf("5. Hapus Kota Belakang\n");
        printf("6. Hapus Kota P\n");
        printf("7. Hapus Semua Kota\n");
        printf("8. Tampilkan Kota\n");
        printf("9. Jumlah Kota\n");
        printf("10. Manipulasi Menu Orang di Kota\n");
        printf("11. Keluar\n");
        printf("Pilih : ");
        scanf("%d", &pil);
        while (getchar() != '\n');

        printf("\n========================= \n");

        switch (pil)
        {
        case 1:
            printf("Masukkan Nama Kota: ");
            scanf("%s", nama);
            
            InsFirstKota(&listkota, nama);

            printf("\n========================= \n");

            break;
        case 2:
            printf("Masukkan Nama Kota: ");
            scanf("%s", nama);
            
            InsLastKota(&listkota, nama);

            printf("\n========================= \n");

            break;
        case 3:
            PrintInfoKota(listkota);
                            
            if(ListEmptyKota(listkota)) {
                printf("List Kosong\n");
                printf("========================= \n");

                break;
            }else {
                printf("Masukan Setelah Kota : ");
                scanf("%s", &namakotalama);
                PrecKota = SearchKota(listkota, namakotalama);

                printf("Masukkan Nama Kota : ");
                scanf("%s", namakota);

                InsertAfterKota(&listkota, namakota, PrecKota);
            }

            printf("\n========================= \n");

            break;
        case 4:
            DelFirstKota(&listkota, &namakotalama);
            printf("Data yang dihapus : %s\n", namakotalama);
            printf("========================= \n");

            break;
        case 5:
            DelLastKota(&listkota, &namakotalama);
            printf("Data yang dihapus : %s\n", namakotalama);
            printf("========================= \n");

            break;
        case 6:
            if(ListEmptyKota(listkota)) {
                printf("List Kosong\n");
                printf("========================= \n");

                break;
            } else {
                PrintInfoKota(listkota);

                printf("Masukan Nama Kota : ");
                scanf("%s", &namakota);
                DelPKota(&listkota, namakota);
                
                printf("========================= \n");
            }

            break;
        case 7:
            DelAllKota(&listkota);
            printf("Semua data berhasil dihapus\n");
            printf("========================= \n");

            break;
        case 8:
            PrintInfoKota(listkota);

            break;
        case 9:
            jumlahkota = HitungJumlahKota(listkota);
            printf("Jumlah Kota Sebanyak = %d\n", jumlahkota);
            printf("========================= \n");

            break;
        case 10:
            PrintInfoKota(listkota);

            printf("Pilih kota (1-10) : ");
            scanf("%d", &indexkota);

            if (indexkota < 1 || indexkota > 10) {
                printf("Kota tidak valid\n");
                printf("\n========================= \n");
                break;
            }

            pilihkota = GetKotaKe(listkota, indexkota);
            
            printf("========================= \n");
            printf("kota terpilih : %s\n", NamaKota(pilihkota));
            printf("========================= \n");

            int submenu = 1;

            while (submenu) {
                printf("\n==== Menu Orang ====\n");
                printf("Pilihlah Menu Berikut : \n");
                printf("1. Tambah Orang Depan\n");
                printf("2. Tambah Orang Belakang\n");
                printf("3. Tambah Orang After\n");
                printf("4. Hapus Orang Depan\n");
                printf("5. Hapus Orang Belakang\n");
                printf("6. Hapus Orang P\n");
                printf("7. Hapus Semua Orang\n");
                printf("8. Tampilkan Orang\n");
                printf("9. Jumlah Orang\n");
                printf("10. Keluar\n");
                printf("Pilih : ");
                scanf("%d", &pil2);
                while (getchar() != '\n');

                printf("\n========================= \n");
        
                switch (pil2)
                {
                    case 1:
                        printf("Masukkan Nama: ");
                        scanf("%s", nama);

                        InsFirst(pilihkota, nama);

                        printf("\n========================= \n");

                        break;
                    case 2:
                        printf("Masukkan Nama: ");
                        scanf("%s", nama);

                        InsLast(pilihkota, nama);

                        printf("\n========================= \n");
            
                        break;
                    case 3:
                        PrintInfo(*pilihkota);
                        
                        if(ListEmpty(*pilihkota)) {
                            printf("List Kosong\n");
                            printf("========================= \n");
            
                            break;
                        }else {
                            printf("Masukan Setelah : ");
                            scanf("%s", &namalama);
                            Prec = Search(*pilihkota, namalama);

                            printf("Masukkan Nama: ");
                            scanf("%s", nama);

                            InsertAfter(nama, Prec);
                        }

                        printf("\n========================= \n");
            
                        break;
                    case 4:
                        DelFirst(pilihkota, &namalama);
                        printf("Data yang dihapus : %s\n", namalama);
                        printf("========================= \n");

                        break;
                    case 5:
                        DelLast(pilihkota, &namalama);
                        printf("Data yang dihapus : %s\n", namalama);
                        printf("========================= \n");

                        break;
                    case 6:
                        PrintInfo(*pilihkota);

                        if(ListEmpty(*pilihkota)) {
                            printf("List Kosong\n");
                            printf("========================= \n");
            
                            break;
                        } else {
                            printf("Masukan Nama : ");
                            scanf("%s", &namalama);
                            DelP(pilihkota, namalama);
                            
                            printf("========================= \n");
                        }

                        break;
                    case 7:
                        DelAll(pilihkota);
                        printf("Semua data berhasil dihapus\n");
                        printf("========================= \n");

                        break;
                    case 8:
                        PrintInfo(*pilihkota);
                        
                        break;
                    case 9:
                        jumlah = HitungOrang(*pilihkota);

                        printf("Jumlah orang : %d\n", jumlah);
                        printf("========================= \n");
            
                        break;
                    case 10:
                        submenu = 0;

                        break;
                }
            }

            break;
        case 11:
            running = 0;

            break;
        }
    }

    
    return 0;
}