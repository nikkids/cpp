#ifndef LISTRELASI_H_INCLUDED
#define LISTRELASI_H_INCLUDED

#include "listrelasi.h"
#include "ChildPemilih.h"

#include <iostream>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define info(P) P->info

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    address_pemilih info;
};

struct List_relasi{
    address_relasi first;
};

/** TIDAK PERLU MODIFIKASI */
void createList(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void insertAfter(address_relasi Prec, address_relasi P);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void deleteAfter(address_relasi Prec, address_relasi &P);


/** PERLU MODIFIKASI */
address_relasi alokasi(address_pemilih C);
void dealokasi(address_relasi &P);
address_relasi findElm(List_relasi L, address_pemilih C);
void printInfoRelasi(List_relasi L);
void printInfoRelasiCalonPemilih(List_relasi L, string cariPemilih);


#endif // LISTRELASI_H_INCLUDED

