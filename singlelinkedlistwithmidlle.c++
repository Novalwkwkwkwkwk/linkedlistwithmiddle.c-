#include <iostream>
using namespace std;

struct Buku
{
    string judul, pengarang;
    int thn;
    Buku *next;
};

Buku *kepala = NULL, *tail = NULL, *cur = NULL, *nodeBaru = NULL, *busek = NULL, *sebelum = NULL;

void ngisiLinkedlist(string judul, string pengarang, int thn)
{
    kepala = new Buku();
    kepala->judul = judul;
    kepala->pengarang = pengarang;
    kepala->thn = thn;
    kepala->next = NULL;
    tail = kepala;
}
int hitungLinkedlist()
{
    cur = kepala;
    int jumlah = 0;
    while (cur != NULL)
    {
        jumlah++;
        cur = cur->next;
    }
    return jumlah;
}

void tambahAwal(string judul, string pengarang, int thn)
{
    nodeBaru = new Buku();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->thn = thn;
    nodeBaru->next = kepala;
    kepala = nodeBaru;
    if (tail == NULL)
    {
        tail = kepala;
    }
}

void tambahAkhir(string judul, string pengarang, int thn)
{
    nodeBaru = new Buku();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->thn = thn;
    nodeBaru->next = NULL;
    if (tail != NULL)
    {
        tail->next = nodeBaru;
        tail = nodeBaru;
    }
    else
    {
        kepala = tail = nodeBaru;
    }
}

void tambahTengah(string judul, string pengarang, int thn, int posisi)
{
    int jumlah = hitungLinkedlist();
    if (posisi < 1 || posisi > jumlah + 1)
    {
        cout << "Posisi berada di luar jangkauan" << endl;
        return;
    }

    nodeBaru = new Buku();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->thn = thn;

    if (posisi == 1)
    {
        nodeBaru->next = kepala;
        kepala = nodeBaru;
        if (tail == NULL)
        {
            tail = kepala;
        }
        return;
    }

    cur = kepala;
    int nomor = 1;
    while (nomor < posisi - 1)
    {
        cur = cur->next;
        nomor++;
    }
    nodeBaru->next = cur->next;
    cur->next = nodeBaru;

    if (nodeBaru->next == NULL)
    {
        tail = nodeBaru;
    }
}

void ubahAwal(string judul, string pengarang, int thn)
{
    if (kepala != NULL)
    {
        kepala->judul = judul;
        kepala->pengarang = pengarang;
        kepala->thn = thn;
    }
}

void ubahLast(string judul, string pengarang, int thn)
{
    if (tail != NULL)
    {
        tail->judul = judul;
        tail->pengarang = pengarang;
        tail->thn = thn;
    }
}

void ubahTengah(string judul, string pengarang, int thn, int posisi)
{
    if (posisi < 1 || posisi > hitungLinkedlist())
    {
        cout << "Posisi berada di luar jangkauan" << endl;
        return;
    }
    else if (posisi == 1 || posisi == hitungLinkedlist())
    {
        cout << "Posisi bukan posisi tengah" << endl;
        return;
    }
    cur = kepala;
    int nomor = 1;
    while (nomor < posisi)
    {
        cur = cur->next;
        nomor++;
    }
    cur->judul = judul;
    cur->pengarang = pengarang;
    cur->thn = thn;
}


void cetakLinkedlist()
{
    cout << "Jumlah data ada: " << hitungLinkedlist() << endl;
    cur = kepala;
    while (cur != NULL)
    {
        cout << "Judul Buku: " << cur->judul << endl;
        cout << "Pengarang Buku: " << cur->pengarang << endl;
        cout << "Tahun terbit Buku: " << cur->thn << endl;
        cur = cur->next;
    }
}

void hapusAwal()
{
    if (kepala != NULL)
    {
        busek = kepala;
        kepala = kepala->next;
        delete busek;
        if (kepala == NULL)
        {
            tail = NULL;
        }
    }
}

void hapusLast()
{
    if (tail != NULL)
    {
        busek = tail;
        if (kepala == tail)
        {
            kepala = tail = NULL;
        }
        else
        {
            cur = kepala;
            while (cur->next != tail)
            {
                cur = cur->next;
            }
            tail = cur;
            tail->next = NULL;
        }
        delete busek;
    }
}

void hapusTengah(int posisi)
{
    if (posisi < 1 || posisi > hitungLinkedlist())
    {
        cout << "Posisi berada di luar jangkauan" << endl;
        return;
    }
    else if (posisi == 1 || posisi == hitungLinkedlist())
    {
        cout << "Posisi bukan posisi tengah" << endl;
        return;
    }
    int nomor = 1;
    cur = kepala;
    while (nomor < posisi)
    {
        if (nomor == posisi - 1)
        {
            sebelum = cur;
        }
        cur = cur->next;
        nomor++;
    }
    busek = cur;
    sebelum->next = cur->next;
    delete busek;

    if (sebelum->next == NULL)
    {
        tail = sebelum;
    }
}

int main()
{
    ngisiLinkedlist("nganco", "yanto", 2024);
    tambahAwal("Mancing", "yanti", 2033);
    tambahAkhir("Sekolah", "walker", 2021);
    ubahAwal("kamu oke", "uden", 1923);
    cetakLinkedlist();
    cout << "\n\n" << endl;

    tambahTengah("telo godok", "cemek", 2024, 2);
    tambahTengah("telo goreng", "nana", 2023, 3);
    hapusTengah(2);
    cetakLinkedlist();
    cout << "\n\n" << endl;
    ubahTengah("sego ndok", "jefri", 2020,2);
    cetakLinkedlist();
    cout << "\n\n" << endl;

    return 0;
}
