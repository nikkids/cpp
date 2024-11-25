#include "listrelasi.h"

void createList(List_relasi &L) {
    first(L) = NULL;
}

address_relasi alokasi(address_pemilih C) {
    address_relasi P = new elmlist_relasi;
    info(P) = C;
    next(P) = NULL;
    return P;
}

void insertFirst(List_relasi &L, address_relasi P) {
    next(P) = first(L);
    first(L) = P;
}

void printInfoRelasi(List_relasi L) {
    address_relasi P = first(L);
    cout << "--Data Pemilih--" << endl;
    while(P != NULL) {
        cout<<"-> "<<info(info(P))<<endl;
        P = next(P);
    }
}

void deleteFirstRelasi(List_relasi &L, address_relasi &P) {
    if (next(first(L)) = NULL) {
        P = first(L);
        first(L) = NULL;
        free(P);
    } else if(first(L) == NULL) {
        cout << "Kosong" << endl;
    } else {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void printInfoRelasiCalonPemilih(List_relasi L, string cariPemilih) {
    address_relasi P = first(L);
    bool ketemu = false;
    while(P != NULL) {
            if (info(info(P)) == cariPemilih) {
                ketemu = true;
                cout <<"Benar bahwa " << info(info(P)) << " memilih calon ini" << endl;
            }

        P = next(P);
    }
    if (ketemu == false) {
        cout << "PEMILIH tidak memilih calon ini" << endl;
    }
}


address_relasi findElm(List_relasi L, address_pemilih C) {
    address_relasi P = first(L);
    while(P != NULL) {
        if(info(P)== C) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_relasi &Prec, address_relasi P) {
    next(P) = next(Prec);
    next(Prec) = P;
}
