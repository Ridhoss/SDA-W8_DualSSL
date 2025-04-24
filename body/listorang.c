#include "../header/listorang.h"
#include "../header/kota.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <malloc.h>

boolean ListEmpty(Kota L) {
    return (HeadKota(&L) == Nil);
}

address Alokasi(infotype X) {
    address P = (address) malloc(sizeof(Node));

    if(P != Nil) {
        strcpy(Info(P), X); 
        Next(P) = Nil;
    }
}

void Dealokasi(address P) {
    if(P != Nil){
        free(P);
    }
}

address Search(Kota L, infotype X) {
    address P = HeadKota(&L);

    while(P != Nil) {
        if(strcmp(Info(P), X) == 0) {
            return P;
        } else {
            P = Next(P);
        }
    }

    return Nil;
}

address SearchPrec (Kota L, infotype X) {
    address P, Prec;

    P = HeadKota(&L);
    Prec = Nil;
    boolean found = false;

	while ((P != Nil) && (!found))
	{
		if (strcmp(Info(P), X) == 0)
		{	
            found = true;	
        }
		else
		{
			Prec = P;
			P = Next(P);
		}
	}

	if (found)
	{	
        return (Prec);		
    }
	else
	{	
        return (Nil);		
    }

    
    return Nil;
}

void InsFirst (Kota * L, infotype X) {
    address P;

    P = Alokasi(X);

    if(P != Nil) {
        Next(P) = HeadKota(L);
        HeadKota(L) = P;
    }
}

void InsLast (Kota * L, infotype X) {
    address P, last;

    P = Alokasi(X);

    last = HeadKota(L);

    if(P != Nil) {
        if(last != Nil){
            while (Next(last) != Nil) {
                last = Next(last);
            }
        }

        Next(P) = Next(last);
        Next(last) = P;
    }
}

void DelFirst (Kota * L, infotype * X) {
    address P;

    if(!ListEmpty(*L)) {
        P = HeadKota(L);
        strcpy(*X, Info(P));
        HeadKota(L) = Next(P);

        Dealokasi(P);
    } else {
        printf("List Kosong\n");
        printf("========================= \n");
    }
}

void DelLast (Kota * L, infotype * X) {
    address P, Prec;

    if(!ListEmpty(*L)) {
        P = HeadKota(L);

        if(Next(P) == Nil) {
            DelFirst(L, X);
        } else {
            while(Next(P) != Nil) {
                Prec = P;
                P = Next(P);
            }

            strcpy(*X, Info(P));
            Next(Prec) = Nil;
            Dealokasi(P);
        }

    } else {
        printf("List Kosong\n");
        printf("========================= \n");
    }
}

void InsertAfter (infotype X, address Prec) {
    address P = Alokasi(X);

    if(P != Nil) {
        if(Prec != Nil) {
            Next(P) = Next(Prec);
            Next(Prec) = P;
        } else {
            printf("Tidak ada elemen yang sesuai\n");
        }
    }
}

void DelP (Kota * L, infotype X) {
    address P, Prec;
    infotype temp;

    P = Search(*L, X); 
    Prec = SearchPrec(*L, X);

    if(P != Nil) {
        if(Prec == Nil) {
            DelFirst(L, &temp);
        } else if(Next(P) == Nil) {
            DelLast(L, &temp);
        } else {
            strcpy(temp, Info(P));
            Next(Prec) = Next(P);
            Dealokasi(P);
        }

        printf("Data yang dihapus : %s\n", temp);
    } else {
        printf("Data tidak ditemukan\n");
    }
}

void DelAll (Kota * L) {
    address P, NextP;

    P = HeadKota(L);

    while(P != Nil) {
        NextP = Next(P);
        Dealokasi(P);
        P = NextP;
    }

    HeadKota(L) = Nil;
}

void PrintInfo (Kota L) {
    address P = HeadKota(&L);

    if(P == Nil) {
        printf("List Kosong\n");
        printf("========================= \n");
    } else {
        while(P != Nil) {
            printf("%s -> ", Info(P));
            P = Next(P);
        }
        printf("NULL");
        printf("\n========================= \n");
    }
}

int HitungOrang (Kota L) {
    address P = HeadKota(&L);
    int count = 0;

    while(P != Nil) {
        count++;
        P = Next(P);
    }

    return count;
}