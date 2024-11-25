#ifndef PARENTCALON_H_INCLUDED
#define PARENTCALON_H_INCLUDED

#include <iostream>
using namespace std;

#include "listrelasi.h"

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define next(Q) Q->next
#define next(Prec) Prec->next
#define prev(Q) Q->prev
#define info(P) P->info
#define info(C) C->info

//CDLL

typedef struct elmlist_parent *address_calon;

struct infotype_parent {
    string namacalon;
    int nomorurut;
    string partai;
    int vote;
    int usia;
};

struct elmlist_parent {
    infotype_parent info;
    List_relasi pemilih;
    address_calon next;
    address_calon prev;
};

struct List_calon {
    address_calon first;
    address_calon last;
};


void createListCalon(List_calon &L);
void insertFirstCalon(List_calon &L, address_calon P);
void insertAfterCalon(List_calon &L, address_calon Prec, address_calon P);
void insertLastCalon(List_calon &L, address_calon P);
void deleteFirstCalon(List_calon &L, address_calon &P);
void deleteLastCalon(List_calon &L, address_calon &P);
void deleteAfterCalon(List_calon &L, address_calon Prec, address_calon &P);
void deleteByValueCalon(List_calon &L, string nama);



address_calon alokasiCalon(string namacalon, int nomorurut, string partai, int usia);
address_calon alokasiCalonUntukTemplate(string namacalon, int nomorurut, string partai, int usia, int vote);
void dealokasiCalon(address_calon &P);
address_calon findElmCalon(List_calon L, string nama);
void printInfoCalon(List_calon L);
void printInfoCalonNamaOnly(List_calon L);
void findElmPartai(List_calon L, string partai);
void findElmPemilihCalon(List_calon L,string cariPemilihCalon,string cariPemilih);
void tambahVote(List_calon L, string pilihCalon);
void delete2(address_calon &a, address_calon &b);
void Deletation(List_calon L);
bool threshold1(List_calon L, int usia);
bool threshold2(List_calon L, int nomorurut);
void addData(List_calon &L);
void sortCalon(List_calon L, List_calon &sortedL);
void UrutPartai(List_calon &L);
void tampilkanCalonTerurut(List_calon L);
pair<string, int> max(List_calon L);
address_calon findElmVote(List_calon L, string nama);


#endif // PARENTCALON_H_INCLUDED
