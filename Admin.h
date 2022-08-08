#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

// Fiky Anggara
// Teknologi Informasi

class admin
{
public:
int id_ibu;
int jumlah;
char nama_ibu[20];
char nama_anak[50];
int usia_anak;
char alamat[50];
char tanggal[20];
char buffer[1000];
int tambahan,total;
int pilih,vip=300000,ekonomi=200000,kembalian;
int uang=0,tunggakan=0;
time_t ambil_waktu;
void centerstring(char* s);
int paket,bulan=30,minggu=7,hari=1,jml;
admin();
int ketemu_data(int kode_ibu);
void tambah_data(int kode_ibu);
void tampil_data(int kode_ibu);
void hapus_data(int kode_ibu);
void update_data(int kode_ibu);
void peraturan();
};



#endif // ADMIN_H_INCLUDED
