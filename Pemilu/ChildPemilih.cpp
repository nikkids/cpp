#include "ChildPemilih.h"

void createListPemilih(List_pemilih &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_pemilih alokasiPemilih(namaPemilih x) {
    address_pemilih P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirstPemilih(List_pemilih &L, address_pemilih P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void deleteFirstPemilih(List_pemilih &L, address_pemilih &P) {
    if (next(first(L)) = NULL) {
        P = first(L);
        first(L) = NULL;
        free(P);
    } else if(first(L) == NULL) {
        cout << "List pemilih kosong" << endl;
    } else {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void printInfoPemilih(List_pemilih L) {
    address_pemilih P = first(L);
    cout << "====DATA PEMILIH===" << endl;
    while(P !=NULL) {
        cout<<"-> "<<info(P)<<endl;
        P = next(P);
    }
}


address_pemilih findElmPemilih(List_pemilih L, namaPemilih x) {
    address_pemilih P = first(L);
    while(P != NULL) {
        if(info(P)==x) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfterPemilih(address_pemilih &Prec, address_pemilih P) {
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}
