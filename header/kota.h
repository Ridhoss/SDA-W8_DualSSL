#ifndef kota_H
#define kota_H

#include "listorang.h"
#include "boolean.h"

#define Nil NULL
#define NamaKota(P) (P)->namakota
#define NextKota(P) (P)->next
#define HeadKota(P) (P)->head
#define First(P) (P).first

typedef struct Kota *addressKota;
typedef struct Kota {
	infotype namakota;
	Node *head;
	addressKota next;
} Kota;

typedef struct {
	addressKota first;
} List;

boolean ListEmptyKota(List L);

void CreateListKota(List * L);

addressKota AlokasiKota(infotype X);

void DealokasiKota(addressKota P);

addressKota SearchKota(List L, infotype X);

addressKota SearchPrecKota(List L, infotype X);

void InsFirstKota(List * L, infotype X);

void InsLastKota(List * L, infotype X);

void DelFirstKota(List * L, infotype * X);

void DelLastKota(List * L, infotype * X);

void InsertAfterKota(List * L, infotype X, addressKota Prec);

void DelPKota(List * L, infotype X);

void DelAllKota(List * L);

void PrintInfoKota(List L);

addressKota GetKotaKe(List listkota, int index);

int HitungJumlahKota(List L);





// void inisialisasiKota(Kota x[10]);

// Kota* ambilKotaKosong(Kota x[10]);

// void InsKota(Kota *x, infotype nama);

// void DelKota(Kota *x);

// void tampilkanKota(Kota x[10]);


#endif
