#include <iostream>
using namespace std;

struct Pembayaran
{
    string namaPelanggan, nomorTagihan;
    double jumlahTagihan;
    Pembayaran *next;
};

Pembayaran *kepala, *buntut, *cur, *nodeBaru, *busek;

void ngisiLinkedList(string namaPelanggan, string nomorTagihan, double jumlahTagihan)
{
    kepala = new Pembayaran();
    kepala->namaPelanggan = namaPelanggan;
    kepala->nomorTagihan = nomorTagihan;
    kepala->jumlahTagihan = jumlahTagihan;
    kepala->next = NULL;
    buntut = kepala;
}

void tambahAwal(string namaPelanggan, string nomorTagihan, double jumlahTagihan)
{
    nodeBaru = new Pembayaran();
    nodeBaru->namaPelanggan = namaPelanggan;
    nodeBaru->nomorTagihan = nomorTagihan;
    nodeBaru->jumlahTagihan = jumlahTagihan;
    nodeBaru->next = kepala;
    kepala = nodeBaru;
}

void tambahGuri(string namaPelanggan, string nomorTagihan, double jumlahTagihan)
{
    nodeBaru = new Pembayaran();
    nodeBaru->namaPelanggan = namaPelanggan;
    nodeBaru->nomorTagihan = nomorTagihan;
    nodeBaru->jumlahTagihan = jumlahTagihan;
    nodeBaru->next = NULL;
    buntut->next = nodeBaru;
    buntut = nodeBaru;
}

void ubahAwal(string namaPelanggan, string nomorTagihan, double jumlahTagihan)
{
    kepala->namaPelanggan = namaPelanggan;
    kepala->nomorTagihan = nomorTagihan;
    kepala->jumlahTagihan = jumlahTagihan;
}

void ubahLast(string namaPelanggan, string nomorTagihan, double jumlahTagihan)
{
    buntut->namaPelanggan = namaPelanggan;
    buntut->nomorTagihan = nomorTagihan;
    buntut->jumlahTagihan = jumlahTagihan;
}

void hapusAwal()
{
    busek = kepala;
    kepala = kepala->next;
    delete busek;
}

void hapusLast()
{
    busek = buntut;
    cur = kepala;
    while (cur->next != buntut)
    {
        cur = cur->next;
    }
    buntut = cur;
    buntut->next = NULL;
    delete busek;
}

void cetakLinkedList()
{
    cur = kepala;
    while (cur != NULL)
    {
        cout << "nama Pelanggan Pembayaran : " << cur->namaPelanggan << endl;
        cout << "nomor Tagihan Pembayaran : " << cur->nomorTagihan << endl;
        cout << "Jumlah Tagihan Pembayaran : " << cur->jumlahTagihan << endl;
        cout << endl;
        cur = cur->next;
    }
}

int main()
{
    ngisiLinkedList("Yanto", "01", 100000);
    tambahAwal("Yanti", "02", 200000);
    tambahGuri("Yatno", "03", 300000);
    // hapusAwal();
    // hapusLast();
    ubahAwal("Yana", "04", 400000);
    ubahLast("Yani", "05", 500000);
    // hapusAwal();
    // hapusLast();
    cetakLinkedList();

    return 0;
}
