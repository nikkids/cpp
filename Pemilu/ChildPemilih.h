#ifndef CHILDPEMILIH_H_INCLUDED
#define CHILDPEMILIH_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define info(C) C->info


//DLL

typedef string namaPemilih;
typedef struct elmlist_child *address_pemilih;



struct elmlist_child{
    namaPemilih info;
    address_pemilih next;
    address_pemilih prev;
};

struct List_pemilih{
    address_pemilih first;
    address_pemilih last;
};

/** TIDAK PERLU MODIFIKASI */
void createListPemilih(List_pemilih &L);
void insertFirstPemilih(List_pemilih &L, address_pemilih P);
void insertLastPemilih(List_pemilih &L, address_pemilih P);
void insertAfterPemilih(address_pemilih Prec, address_pemilih P);
void deleteFirstPemilih(List_pemilih &L, address_pemilih &P);
void deleteLastPemilih(List_pemilih &L, address_pemilih &P);
void deleteAfterPemilih(address_pemilih Prec, address_pemilih &P);


/** PERLU MODIFIKASI */
address_pemilih alokasiPemilih(namaPemilih x);
void dealokasi(address_pemilih &P);
address_pemilih findElmPemilih(List_pemilih L, namaPemilih x);
void printInfoPemilih(List_pemilih L);

#endif // CHILDPEMILIH_H_INCLUDED
