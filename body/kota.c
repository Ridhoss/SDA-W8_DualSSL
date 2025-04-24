#include "../header/kota.h"
#include "../header/listorang.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

boolean ListEmptyKota(List L) {
    return (First(L) == Nil);
}

void CreateListKota(List * L) {
    First(* L) = Nil;
}

addressKota AlokasiKota(infotype X) {
    addressKota P = (addressKota) malloc(sizeof(Kota));

    if(P != Nil) {
        strcpy(NamaKota(P), X);
        NextKota(P) = Nil;
        HeadKota(P) = Nil;
    }
}

void DealokasiKota(addressKota P) {
    if(P != Nil){
        free(P);
    }
}

addressKota SearchKota(List L, infotype X) {
    addressKota P = First(L);

    while(P != Nil) {
        if(strcmp(NamaKota(P), X) == 0) {
            return P;
        } else {
            P = NextKota(P);
        }
    }
}

addressKota SearchPrecKota(List L, infotype X) {
    addressKota P, Prec;

    P = First(L);
    Prec = Nil;
    boolean found = false;

	while ((P != Nil) && (!found))
	{
		if (strcmp(NamaKota(P), X) == 0)
		{	
            found = true;	
        }
		else
		{
			Prec = P;
			P = NextKota(P);
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
}

void InsFirstKota(List * L, infotype X) {
    addressKota P;

    P = AlokasiKota(X);

    if(P != Nil) {
        NextKota(P) = First(*L);
        First(*L) = P;
    }
}

void InsLastKota(List * L, infotype X) {
    addressKota P, last;

    P = AlokasiKota(X);

    last = First(*L);

    if(P != Nil) {
        if(last != Nil){
            while (NextKota(last) != Nil) {
                last = NextKota(last);
            }
        }

        NextKota(P) = NextKota(last);
        NextKota(last) = P;
    }
}

void DelFirstKota(List * L, infotype * X) {
    addressKota P;

    if(!ListEmptyKota(*L)) {
        P = First(*L);
        strcpy(*X, NamaKota(P));
        First(*L) = NextKota(P);

        DealokasiKota(P);
    } else {
        printf("List Kosong\n");
        printf("========================= \n");
    }
}

void DelLastKota(List * L, infotype * X) {
    addressKota P, Prec;

    if(!ListEmptyKota(*L)) {
        P = First(*L);

        if(NextKota(P) == Nil) {
            DelFirstKota(L, X);
        } else {
            while(NextKota(P) != Nil) {
                Prec = P;
                P = NextKota(P);
            }

            strcpy(*X, NamaKota(P));
            NextKota(Prec) = Nil;
            DealokasiKota(P);
        }

    } else {
        printf("List Kosong\n");
        printf("========================= \n");
    }
}

void InsertAfterKota(List * L, infotype X, addressKota Prec) {
    addressKota P = AlokasiKota(X);

    if(P != Nil) {
        if(Prec != Nil) {
            NextKota(P) = NextKota(Prec);
            NextKota(Prec) = P;
        } else {
            printf("Tidak ada elemen yang sesuai\n");
            printf("========================= \n");
        }
    }
}

void DelPKota(List * L, infotype X) {
    addressKota P, Prec;
    infotype temp;

    P = SearchKota(*L, X); 
    Prec = SearchPrecKota(*L, X);

    if(P != Nil) {
        if(Prec == Nil) {
            DelFirstKota(L, &temp);
        } else if(NextKota(P) == Nil) {
            DelLastKota(L, &temp);
        } else {
            strcpy(temp, NamaKota(P));
            NextKota(Prec) = NextKota(P);
            DealokasiKota(P);
        }

        printf("Data yang dihapus : %s\n", temp);
    } else {
        printf("Data tidak ditemukan\n");
        printf("========================= \n");
    }
}

void DelAllKota(List * L) {
    addressKota P, NextP;

    P = First(*L);

    while(P != Nil) {
        NextP = NextKota(P);
        DealokasiKota(P);
        P = NextP;
    }

    First(*L) = Nil;
}

void PrintInfoKota(List L) {
    addressKota P = First(L);
    int i = 1;

    if(P == Nil) {
        printf("List Kosong\n");
        printf("========================= \n");
        printf("\n");
    } else {
        while(P != Nil) {
            printf("Kota %d : %s\n", i, NamaKota(P));
            PrintInfo(*P);
            P = NextKota(P);
            i++;
        }
        printf("NULL");
        printf("\n========================= \n");
    }
}

addressKota GetKotaKe(List listkota, int index) {
    addressKota P = First(listkota);
    int i = 1;

    while (P != NULL && i < index) {
        P = NextKota(P);
        i++;
    }

    return P;
}

int HitungJumlahKota(List L) {
    addressKota P = First(L);
    int count = 0;

    while(P != Nil) {
        count++;
        P = NextKota(P);
    }

    return count;
}