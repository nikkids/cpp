#include <iostream>

using namespace std;
#include "ChildPemilih.h"
#include "ParentCalon.h"

int main() {
    cout << "Relasi M-N" << endl;

    List_calon LC;
    List_pemilih LP;
    address_pemilih P;
    address_calon C;
    address_relasi R;

    createListCalon(LC);
    createListPemilih(LP);
    string menu;

    cout << "Data Awal Telah Ditambahkan" << endl;
    cout << "---------------------------" << endl;
    addData(LC);
do {
    cout << "=== Pusat Pemilu ===" << endl;
    cout << "A. Tambah Calon" << endl;
    cout << "B. Edit Calon" << endl;
    cout << "C. Hapus Calon" << endl;
    cout << "D. Tambah Pemilih" << endl;
    cout << "E. Edit Pemilih" << endl;
    cout << "F. Hapus Pemilih" << endl;
    cout << "G. Lihat Pemenang" << endl;
    cout << "H. Urut Partai" << endl;
    cout << "I. Cari Calon berdasar partai" << endl;
    cout << "J. Cari nama calon" << endl;
    cout << "K. Cari nama pemilih berdasar calon" << endl;
    cout << "L. Lihat Data Calon" << endl;
    cout << "M. Lihat Data Pemilih" << endl;
    cout << "Pilih Menu: ";

    cin >> menu;



    if (menu == "A") {
    /** insert parent **/
    string namacalon;
    int nomorurut = 0;
    string partai;
    int vote = 0;
    int usia = 0;

    cout << "Input Nama Calon: " << endl;
    cin >> namacalon;
    cout << "Nomor urut: " << endl;
    cin >> nomorurut;
    cout << "Input Nama Partai: " << endl;
    cin >> partai;
    cout << "Input Usia: " << endl;
    cin >> usia;

    bool batas1 = threshold1(LC,usia);
    bool batas2 = threshold2(LC,nomorurut);

    if (batas1 && batas2) {
        C = alokasiCalon(namacalon,nomorurut,partai,usia);
        insertFirstCalon(LC,C);
         cout<<endl;
        cout << "Data Calon telah ditambahkan" << endl;
        cout << "----------------------------"  << endl;
        cout<< endl;
    } else {
        cout << "Data Calon tidak valid" << endl;
    }
    cout<< endl;
    cout<< "..." << endl;

    } else if (menu == "B") {
        string ubah;
        cout << "Format data yang ingin diubah" << endl;
        cout << "A. Nama" << endl;
        cout << "B. Partai" << endl;
        cout << "Input: " << endl;
        cin >> ubah;

        string ubahNama;
        if (ubah == "A") {
            cout << "Nama CALON yang ingin diubah: " << endl;
            cin >> ubahNama;
            C = findElmCalon(LC, ubahNama);
            if (C != NULL) {
                string gantiNama;
                cout << "Nama CALON yang baru: " << endl;
                cin >> gantiNama;
                info(C).namacalon = gantiNama;
            } else {
                cout << "Data calon " << ubahNama << " tidak ditemukan"<< endl;
            }
        } else if (ubah == "B") {
            string ubahPartai;
            cout << "Nama CALON yang ingin ubah partai: " << endl;
            cin >> ubahPartai;
            C = findElmCalon(LC, ubahPartai);
            if (C != NULL) {
               string gantiPartai;
               cout << "Nama PARTAI yang baru: " << endl;
               cin >> gantiPartai;
                info(C).partai = gantiPartai;

            } else {
                cout << "Data calon" << ubahNama << " tidak ditemukan"<< endl;
            }
        }
        cout<< endl;
        cout<< "..." << endl;

    } else if (menu == "C") {
        //Delete before last
        Deletation(LC);
        cout << "1 Data Calon telah terhapus" << endl;
        cout<< endl;
        cout<< "..." << endl;
    } else if (menu == "D") {
         /** insert child */
        namaPemilih dataPemilih;
        cout << "Input Nama Pemilih  :" << endl;
        cin >> dataPemilih;
        P = alokasiPemilih(dataPemilih);
        insertFirstPemilih(LP,P);

        string pilihCalon;
        cout << "==List Calon Available==" << endl;
        printInfoCalonNamaOnly(LC);
        cout << "Siapa CALON yang anda pilih: " << endl;
        cin >> pilihCalon;
        tambahVote(LC,pilihCalon);
        C = findElmCalon(LC, pilihCalon);
        P = findElmPemilih(LP, dataPemilih);
        R = alokasi(P);
        insertFirst(C ->pemilih, R);


    cout<<endl;
    cout << "Data Pemilih telah ditambahkan" << endl;
    cout << "----------------------------"  << endl;
    cout<< endl;
    cout<< "..." << endl;

    } else if (menu == "E") {
        string pemilihEdit;
        cout << "Input nama PEMILIH yang ingin diubah:" << endl;
        cin >> pemilihEdit;
        P = findElmPemilih(LP, pemilihEdit);

        string gantiPemilih;
        cout << "Input nama PEMILIH yang baru:" << endl;
        cin >> gantiPemilih;
        info(P) = gantiPemilih;
        cout<< endl;
        cout<< "..." << endl;

    } else if (menu == "F") {
        address_pemilih Pe;
        deleteFirstPemilih(LP,Pe);
        cout << "Data pemilih telah terhapus" << endl;
        cout<< endl;
        cout<< "..." << endl;
    } else if (menu == "G") {
        pair<string, int> result = max(LC);
        cout << "Nama: " << result.first << "\nVote: " << result.second << endl;
        cout<< endl;
        cout<< "..." << endl;
    } else if (menu == "H") {
        UrutPartai(LC);
        cout<< endl;
        cout<< "..." << endl;
    } else if (menu == "I") {
         string cariPartai;
         cout << "Input nama PARTAI: " << endl;
         cin >> cariPartai;
         findElmPartai(LC,cariPartai);
         cout<< endl;
         cout<< "..." << endl;
    } else if (menu == "J") {
         string cariCalon;
        cout << "Input nama CALON yang ingin dicari:" << endl;
        cin >> cariCalon;
        address_calon C = findElmCalon(LC,cariCalon);
        if(C != NULL) {
            cout << "Nama: " << info(C).namacalon << endl;
            cout << "Nomor Urut: " << info(C).nomorurut << endl;
            cout << "Partai: " << info(C).partai << endl;
        } else {
            cout << "Data calon tidak ditemukan" << endl;
        }
        cout<< endl;
        cout<< "..." << endl;
    } else if (menu == "K") {
        string cariPemilihCalon;
        string cariPemilih;
        cout << "Input nama CALON: " << endl;
        cin >> cariPemilihCalon;
        cout << "Input nama PEMILIH: " << endl;
        cin >> cariPemilih;
        findElmPemilihCalon(LC,cariPemilihCalon,cariPemilih);
        cout<< endl;
        cout<< "..." << endl;
    } else if (menu == "L") {
        printInfoCalon(LC);
        cout<< endl;
        cout<< "..." << endl;
    } else if (menu == "M") {
        printInfoPemilih(LP);
        cout<< endl;
        cout<< "..." << endl;
    }


} while(menu != "Z");


    return 0;
}
