#include "ParentCalon.h"

void createListCalon(List_calon &L) {
    /**
    * FS : first(L) diset NULL
    */
    first(L) = NULL;
}

address_calon alokasiCalon(string namacalon, int nomorurut, string partai, int usia) {
    /**
    * FS : mengembalikan elemen list baru dengan info Calon, next dan prev elemen = NULL
    */

    address_calon P;
    P = new elmlist_parent;
    info(P).namacalon = namacalon;
    info(P).nomorurut = nomorurut;
    info(P).partai = partai;
    info(P).vote = 0;
    info(P).usia = usia;
    next(P) = NULL;
    prev(P) = NULL;
    createList(P->pemilih);
    return P;
}

address_calon alokasiCalonUntukTemplate(string namacalon, int nomorurut, string partai, int usia, int vote) {
    /**
    * FS : mengembalikan elemen list baru dengan info Calon, next dan prev elemen = NULL
    */

    address_calon P;
    P = new elmlist_parent;
    info(P).namacalon = namacalon;
    info(P).nomorurut = nomorurut;
    info(P).partai = partai;
    info(P).vote = vote;
    info(P).usia = usia;
    next(P) = NULL;
    prev(P) = NULL;
    createList(P->pemilih);
    return P;
}

void insertFirstCalon(List_calon &L, address_calon P) {
    /**
    * IS : List_parent (calon) L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_parent L
    *      next dari last elemen menunjuk ke first elemen
    */
    address_calon Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}



void printInfoCalon(List_calon L) {
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_calon P = first(L);
    cout << "====DATA CALON===" << endl;
    if(first(L)!=NULL) {
        do {
            cout<<"Nama Calon    : " << info(P).namacalon<<endl;
            cout<<"Nomor Urut    : " << info(P).nomorurut<<endl;
            cout<<"Nama Partai   : " << info(P).partai<<endl;
            cout<<"Usia          : " << info(P).usia<<endl;
            cout<<"Jumlah Vote   : " << info(P).vote<<endl;

            printInfoRelasi(P->pemilih);
            P = next(P);
        } while(next(P)!=first(L));
    } else {
        cout << "Tidak ada data calon" << endl;
    }
}

void delete2(address_calon& a, address_calon& b) {
    if (a == b) return;
    address_calon tempPrevA = prev(a);
    address_calon tempNextA = next(a);
    address_calon tempPrevB = prev(b);
    address_calon tempNextB = next(b);

    if (tempPrevA != NULL) next(tempPrevA) = b;
    if (tempNextA != NULL) prev(tempNextA) = b;

    if (tempPrevB != NULL) next(tempPrevB) = a;
    if (tempNextB != NULL) prev(tempNextB) = a;


    swap(prev(a), prev(b));
    swap(next(a), next(b));
}

void Deletation(List_calon L){
        address_calon C = first(L);
        address_calon nextCalon = next(C);
        delete2(C, nextCalon);
}

void printInfoCalonNamaOnly(List_calon L) {
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_calon P = first(L);
    cout << "====DATA CALON===" << endl;
    if(first(L)!=NULL) {
        do {
            cout<<"Calon    : " << info(P).namacalon<<endl;
            P = next(P);
        } while(next(P)!=first(L));
    } else {
        cout << "Tidak ada data CALON" << endl;
    }
}

void UrutPartai(List_calon &L) {
    string arrBasdem[10];
    string arrJerindra[10];
    string arrBanteng[10];
    string partai[10];
    string namPar[10];
    int Bas = 0;
    int Jer = 0;
    int Ban = 0;
    int par = 0;

    address_calon P = first(L);

    if (P != NULL) {
        do {
            if (info(P).partai == "BasDem" && Bas < 10) {
                arrBasdem[Bas] = info(P).namacalon;
                Bas++;
            } else if (info(P).partai == "Jerindra" && Jer < 10) {
                arrJerindra[Jer] = info(P).namacalon;
                Jer++;
            } else if (info(P).partai == "Banteng" && Ban < 10) {
                arrBanteng[Ban] = info(P).namacalon;
                Ban++;
            } else {
                partai[par] = info(P).partai;
                namPar[par] = info(P).namacalon;
                par++;
            }
            P = next(P);
        } while (next(P) != first(L));
    } else {
        cout << "List kosong" << endl;
    }

    cout << "--Partai Basdem--" << endl;
    for (int i = 0; i < Bas; i++) {
        cout << arrBasdem[i] << endl;
    }

    cout << "--Partai Jerindra--" << endl;
    for (int i = 0; i < Jer; i++) {
        cout << arrJerindra[i] << endl;
    }

    cout << "--Partai Banteng--" << endl;
    for (int i = 0; i < Ban; i++) {
        cout << arrBanteng[i] << endl;
    }


    for (int i = 0; i < par; i++) {
        cout << "--Partai "<< partai[i] <<"--" << endl;
        cout << namPar[i] << endl;
    }
}



void tampilkanCalonTerurut(List_calon &L){
    address_calon C = first(L);
    while (next(C) != first(L)) {
        address_calon nextCalon  = next(C);
        while (next(nextCalon)  != first(L)) {
            if (info(C).vote < info(nextCalon).vote) {
                C, nextCalon = nextCalon,C;
            }
            nextCalon = next(nextCalon);
        }
        C = next(C);
    }
    cout << "Daftar Calon Terurut Berdasarkan vote: "  << endl;
    printInfoCalon(L);
};

void sortCalon(List_calon L, List_calon &sortedL) {
    address_calon P = first(L);
    while (P != first(L)) {
        P = next(P);
    }

    address_calon Q, R;
    infotype_parent temp;

    if (first(sortedL) != first(L)) {
        for (Q = first(sortedL); next(Q) != first(L); Q = next(Q)) {
            for (R = next(Q); R != first(L); R = next(R)) {
                if (info(Q).vote < info(R).vote) {
                    temp = info(Q);
                    info(Q) = info(R);
                    info(R) = temp;
                }
            }
        }
    } else {
        cout << "List calon kosong" << endl;
    }
}

pair<string, int> max(List_calon L) {
    address_calon C = first(L);
    int max1 = 0;
    string max2;
    while (next(C) != first(L)) {
        if (info(C).vote > max1) {
            max1 = info(C).vote;
            max2 = info(C).namacalon;
        }
        C = next(C);
    }

    return make_pair(max2, max1);
}


address_calon findElmCalon(List_calon L, string nama) {
    /**
    * IS : List_parent (calon) L mungkin kosong
    * FS : mengembalikan elemen dengan info namacalon = nama,
    * FS : mengembalikan elemen dengan info = nama,
           mengembalikan NULL jika tidak ditemukan
    */
    address_calon P = first(L);
    do {
        if(info(P).namacalon == nama) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}

address_calon findElmVote(List_calon L, int v) {
    /**
    * IS : List_parent (calon) L mungkin kosong
    * FS : mengembalikan elemen dengan info namacalon = nama,
    * FS : mengembalikan elemen dengan info = nama,
           mengembalikan NULL jika tidak ditemukan
    */
    address_calon P = first(L);
    do {
        if(info(P).vote == v) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}


void findElmPartai(List_calon L, string partai) {
    address_calon P = first(L);
    int i = 0;
    bool ketemu = false;
    do {
        if(info(P).partai == partai) {
            ketemu = true;
            cout << "Calon: " << info(P).namacalon << endl;
        }
        P = next(P);
        i = i + 1;
    } while(P != first(L));
   if (ketemu == false) {
        cout << "Data partai tidak ditemukan" << endl;
   }
}

void findElmPemilihCalon(List_calon L,string cariPemilihCalon,string cariPemilih) {
    address_calon P = first(L);
    bool ketemu = false;
    do {
        if(info(P).namacalon == cariPemilihCalon) {
            ketemu = true;
            printInfoRelasiCalonPemilih(P->pemilih,cariPemilih);
        }
        P = next(P);
    } while(P != first(L));
   if (ketemu == false) {
        cout << "Data CALON tidak ditemukan" << endl;
   }
 }

bool threshold1(List_calon L,int usia) {
    if (usia >= 21) {
        return true;
    }
    return false;
}

bool threshold2(List_calon L, int nomorurut) {
    address_calon P = first(L);
    do {
        if(info(P).nomorurut == nomorurut) {
            return false;
        }
        P = next(P);
    } while(next(P) != first(L));
    return true;
}

 void tambahVote(List_calon L, string pilihCalon) {
      address_calon P = first(L);
        bool ketemu = false;
    do {
        if(info(P).namacalon == pilihCalon) {
            ketemu = true;
            info(P).vote = info(P).vote + 1;
        }
        P = next(P);
    } while(P != first(L));
   if (ketemu == false) {
        cout << "Data calon tidak ditemukan, pilih calon lain" << endl;
   }
 }

 void addData(List_calon &L) {
    address_calon P0 = alokasiCalonUntukTemplate("KingJokowi",-1,"Banteng",61,1000);
    insertFirstCalon(L,P0);
    address_calon P4 = alokasiCalonUntukTemplate("Nikki&Hawari",4,"Telyu",22,505);
    insertFirstCalon(L,P4);
    address_calon P1 = alokasiCalonUntukTemplate("AniBakwan",1,"BasDem",54,500);
    insertFirstCalon(L,P1);
    address_calon P2 = alokasiCalonUntukTemplate("PraWawa",2,"Jerindra",72,500);
    insertFirstCalon(L,P2);
    address_calon P3 = alokasiCalonUntukTemplate("Banjar",3, "Banteng",55,500);
    insertFirstCalon(L,P3);

 }

void deleteFirstCalon(List_calon &L, address_calon &P) {
    if ((next(first(L)) == first(L)) && (prev(first(L)) == first(L))) {
        P = first(L);
        next(P) = NULL;
        prev(P) = NULL;
        first(L) = NULL;
    } else {
        P = first(L);
        next(prev(first(L))) = next(first(L));
        prev(next(first(L))) = prev(first(L));
        first(L) = next(first(L));
        next(P) = NULL;
        prev(P) = NULL;
    }
}
void deleteLastCalon(List_calon &L, address_calon &P) {
    address_calon Q = prev(last(L));

    next(Q) = P;
    prev(P) = Q;
    next(Q) = first(L);
    next(prev(P)) = NULL;
    prev(next(Q)) = NULL;
}

void deleteAfterCalon(List_calon &L, address_calon Prec, address_calon &P){
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P) = NULL;
    next(P) = NULL;
}

void deleteByValueCalon(List_calon &L, string nama) {
    address_calon P, Prec, Q;
    P = findElmCalon(L, nama);
    if (P != NULL) {
        if (P == first(L)){
            deleteFirstCalon(L, P);
        } else if (P == last(L)){
            deleteLastCalon(L, P);
        } else {
            Prec = first(L);
            while (next(Prec) == P){
                Prec = next(Prec);
            }
            deleteAfterCalon(L, Prec, P);
        }
}
}
