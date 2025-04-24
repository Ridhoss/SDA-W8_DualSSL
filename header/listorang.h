#ifndef listorang_H
#define listorang_H

#include "boolean.h"

#define Nil NULL
#define Info(P) (P)->nama
#define Next(P) (P)->next


typedef char infotype[100];
typedef struct tElmtList *address;
typedef struct tElmtList {
	infotype nama;
	address  next;
} Node;

typedef struct Kota Kota;


boolean ListEmpty(Kota L);

address Alokasi(infotype X);

void Dealokasi(address P);

address Search(Kota L, infotype X);

address SearchPrec (Kota L, infotype X);

void InsFirst (Kota * L, infotype X);

void InsLast (Kota * L, infotype X);

void DelFirst (Kota * L, infotype * X);

void DelLast (Kota * L, infotype * X);

void InsertAfter (infotype X, address Prec);

void DelP (Kota * L, infotype X);

void DelAll (Kota * L);

void PrintInfo (Kota L);

int HitungOrang (Kota L);

#endif
