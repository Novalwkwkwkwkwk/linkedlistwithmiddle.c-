#include <iostream>

using namespace std;

struct Buku
{
    string judul, pengarang;
    int thn;

    Buku *next;
};

Buku *kepala, *bt, *ini, *nodeBaru, *busek;

void ngisiLinkedlist (string judul, string pengarang, int thn) {
    kepala = new Buku();
    kepala->judul = judul;
    kepala->pengarang = pengarang;
    kepala->thn = thn;
    kepala->next = NULL;
    bt = kepala;    
}

void tambahAwal (string judul, string pengarang, int thn) {
    nodeBaru = new Buku();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->thn = thn;
    nodeBaru->next = kepala;
    kepala = nodeBaru;
}

void tambahGuri (string judul, string pengarang, int thn) {
    nodeBaru = new Buku();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->thn = thn;
    nodeBaru->next = NULL;
    bt->next = nodeBaru;
    bt = nodeBaru;
}

void ubahAwal(string judul, string pengarang, int thn){
    kepala->judul = judul;
    kepala->pengarang = pengarang;
    kepala->thn = thn;
}
void ubahLast(string judul, string pengarang, int thn){
    bt->judul = judul;
    bt->pengarang = pengarang;
    bt->thn = thn;
}

void hapusAwal () {
    busek = kepala;
    kepala = kepala->next;
    delete busek;
}

void hapusLast () {
    busek = bt;
    ini = kepala;
    while (ini->next != bt)
    {
        ini = ini->next;
    }
    bt = ini;
    bt->next = NULL;
    delete busek;  
}

void cetakLinkedlist(){
    ini = kepala;
    while (ini != NULL)
    {
        cout << "Judul Buku : " << ini->judul << endl;
        cout << "Pengarang Buku : " << ini->pengarang << endl;
        cout << "Tahun terbit Buku : " << ini->thn << endl;
        cout << endl;
    ini = ini->next;
    }
    
}

int main () {
 ngisiLinkedlist("Ngoding", "bagus", 2025);
 tambahAwal("Mancing", "eko", 2033);
 tambahGuri("Sekolah", "wijayanto", 2021);
//  hapusAwal();
//  hapusLast();
 ubahAwal("Senja pagi buta", "uden", 1923);
 ubahLast("Fajar sore itu", "gamblok", 2000);
 cetakLinkedlist();

 return 0;
}
