#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include "admin.h"
#include "titipanak.h"
using namespace std;
// Fiky Anggara
// Teknologi Informasi

admin::admin(){
}
int admin :: ketemu_data(int kode_ibu){
admin isi_data;
fstream file;
int nketemu=0;
file.open("data.file",ios::binary|ios::in|ios::app|ios::out);
while(file.read((char*)&isi_data,sizeof(isi_data))){
if(isi_data.id_ibu==kode_ibu){
nketemu=1;
break;
}
}
return nketemu;
}
//-----------------------------------------------------------------------------------------------------------------
void admin :: tambah_data(int kode_ibu){
admin isi_data;
time(&ambil_waktu);
fstream file;
file.open("data.file",ios::binary|ios::in|ios::app|ios::out);
if(ketemu_data(kode_ibu)){
cout<<"Maaf Data Tersebut sudah ada"<<endl;
}
else{
cout<<"Data itu belum ada siap untuk ditambahkan......"<<endl;
isi_data.id_ibu=kode_ibu;
cout<<"Masukkan Nama Ibu : ";cin.ignore();cin.getline(isi_data.nama_ibu,sizeof(isi_data.nama_ibu));
cout<<"Masukkan Nama Anak : ";cin.getline(isi_data.nama_anak,sizeof(isi_data.nama_anak));
cout<<"Masukkan Usia Anak : ";cin>>isi_data.usia_anak;
if (isi_data.usia_anak >=1 && isi_data.usia_anak <= 3 ){
isi_data.tambahan=150000;
cout<<"Anda Mendapat Biaya Tambahan : "<<isi_data.tambahan<<endl;
}
else if(isi_data.usia_anak >=3 && isi_data.usia_anak <6){
isi_data.tambahan=50000;
cout<<"Anda Mendapat Biaya Tambahan : "<<isi_data.tambahan<<endl;
}
else {
cout<<"Maaf Batas Usia Penitipan Anak Adalah 1-6 Tahun Saja" <<endl;
}

cout<<"Masukkan Alamat : ";cin.ignore();cin.getline(isi_data.alamat,sizeof(isi_data.alamat));
cout<<"Masukkan Tanggal : ";cin>>isi_data.tanggal;
cout<<"Pilihan Pembayaran ";
cout<<"\n1.Bulanan\n2.Mingguan\n3.Harian"<<endl;
cout<<"Masukkan Pilihan : ";cin>>isi_data.paket;
cout<<"Pilih Paket Penitipan Anak"<<endl;
cout<<"Tekan Enter"<<endl;
system("cls");
centerstring( "+------------------------------------------------------------------------+\n");
centerstring( "| PAKET PENITIPAN ANAK |\n");
centerstring( "+------------------------------------------------------------------------+\n");
centerstring( "| 1.VIP : Rp 300.000,- || 2.Ekonomi : Rp 200.000 |\n");
centerstring( "| A.1 X 24 Jam Pengawasan || A.1 X 24 Jam Pengawasan |\n");
centerstring( "| B.Antar Jemput Anak || B.Makan 3X Sehari + Buah |\n");
centerstring( "| C.Makan 3X Sehari + Buah || C.Pendidikan |\n");
centerstring( "| D.Pendidikan || D.Hiburan |\n");
centerstring( "| E.Hiburan || E.Tidur Siang |\n");
centerstring( "| F.Tidur Siang || |\n");
centerstring( "+------------------------------------------------------------------------+\n");
centerstring( "Waktu/Hari : ");
cout<<ctime(&ambil_waktu)<< endl;
cout << " Masukkan Pilihan Paket :: ";cin>>isi_data.pilih;
cout<<"Anda Memilih Paket : "<<endl;
if (isi_data.pilih==1){
cout<<"Paket VIP :: Rp 300.000,-"<<endl;
//------------------------------------------------
cout<<"Anda Memilih Pembayaran Secara ";
if(isi_data.paket==1){
cout<<" Bulanan = 30 Hari"<<endl;
cout<<"Anda Mendapat Biaya Tambahan Sebesar :: "<<isi_data.tambahan <<endl;
isi_data.total=isi_data.vip+isi_data.tambahan;
cout<<"Total Paket :: "<<isi_data.total <<endl;
isi_data.jml=isi_data.total*isi_data.bulan;
cout<<"Total Membayar Anda :: "<<isi_data.jml <<endl;
}
else if(isi_data.paket==2){
cout<<" Mingguan = 7 Hari"<<endl;
cout<<"Anda Mendapat Biaya Tambahan Sebesar :: "<<isi_data.tambahan <<endl;
isi_data.total=isi_data.vip+isi_data.tambahan;
cout<<"Total Paket :: "<<isi_data.total <<endl;
isi_data.jml=isi_data.total*isi_data.minggu;
cout<<"Total Membayar Anda :: "<<isi_data.jml <<endl;
}
else{
cout<<" Harian = 1 Hari"<<endl;
cout<<"Anda Mendapat Biaya Tambahan Sebesar :: "<<isi_data.tambahan <<endl;
isi_data.total=isi_data.vip+isi_data.tambahan;
cout<<"Total Paket :: "<<isi_data.total <<endl;
isi_data.jml=isi_data.total*isi_data.hari;
cout<<"Total Membayar Anda :: "<<isi_data.jml <<endl;
}
cout<<"Masukkan Uang Untuk Membayar Rp. :: ";cin>>isi_data.uang;
isi_data.kembalian=isi_data.uang-isi_data.jml;
cout<<"Kembalian Uang Anda Rp. :: "<<isi_data.kembalian <<endl;
cout<<"-------------------------------------------------------"<<endl;
cout<<endl;
}

else if (isi_data.pilih==2){
cout<<"Paket Ekonomi :: Rp 200.000,-"<<endl;
cout<<"Anda Memilih Pembayaran secara ";
if(isi_data.paket==1){
cout<<" Bulanan = 30 Hari"<<endl;
cout<<"Anda Mendapat Biaya Tambahan Sebesar :: "<<isi_data.tambahan <<endl;
isi_data.total=isi_data.ekonomi+isi_data.tambahan;
cout<<"Total Paket :: "<<isi_data.total <<endl;
isi_data.jml=isi_data.total*isi_data.bulan;
cout<<"Total Membayar Anda :: "<<isi_data.jml <<endl;
}
else if(isi_data.paket==2){
cout<<" Mingguan = 7 Hari"<<endl;
cout<<"Anda Mendapat Biaya Tambahan Sebesar :: "<<isi_data.tambahan <<endl;
isi_data.total=isi_data.ekonomi+isi_data.tambahan;
cout<<"Total Paket :: "<<isi_data.total <<endl;
isi_data.jml=isi_data.total*isi_data.minggu;
cout<<"Total Membayar Anda :: "<<isi_data.jml <<endl;
}
else{
cout<<" Harian = 1 Hari"<<endl;
cout<<"Anda Mendapat Biaya Tambahan Sebesar :: "<<isi_data.tambahan <<endl;
isi_data.total=isi_data.ekonomi+isi_data.tambahan;
cout<<"Total Paket :: "<<isi_data.total <<endl;
isi_data.jml=isi_data.total*isi_data.hari;
cout<<"Total Membayar Anda :: "<<isi_data.jml <<endl;
}
cout<<"Masukkan Uang Untuk Membayar Rp. :: ";cin>>isi_data.uang;
isi_data.kembalian=isi_data.uang-isi_data.jml;
cout<<"Kembalian Uang Anda Rp. :: "<<isi_data.kembalian <<endl;
cout<<"-------------------------------------------------------"<<endl;
cout<<endl;
}
//--------------------------------
file.write((char*)&isi_data,sizeof(isi_data));
file.close();
cout<<"Selamat Anda Berhasil Registrasi !!!"<<endl;
}
}
//-----------------------------------------------------------------------------------------------------------------
void admin :: tampil_data(int kode_ibu){
admin isi_data;
ifstream file;
int nrecord=1;
file.open("data.file",ios::binary|ios::in|ios::app|ios::out);
while (file.read((char*)&isi_data,sizeof(isi_data))){
cout<<setiosflags(ios::left)<<setw(5)<<"";
cout<<setiosflags(ios::left)<<setw(5)<<nrecord;
cout<<setiosflags(ios::left)<<setw(10)<<isi_data.id_ibu;
cout<<setiosflags(ios::left)<<setw(15)<<isi_data.nama_ibu;
cout<<setiosflags(ios::left)<<setw(20)<<isi_data.nama_anak;
cout<<setiosflags(ios::left)<<setw(10)<<isi_data.usia_anak;
cout<<setiosflags(ios::left)<<setw(12)<<isi_data.alamat;
cout<<setiosflags(ios::left)<<setw(13)<<isi_data.tanggal;
cout<<setiosflags(ios::left)<<setw(10);

if (isi_data.paket==1){
cout<<"Bulan";
}
else if (isi_data.paket==2) {
cout<<"Minggu";
}
else{
cout<<"Hari";
}
cout<<setiosflags(ios::left)<<setw(10);
if (isi_data.pilih==1){
cout<<"VIP";
}
else {
cout<<"Ekonomi";
}
cout<<setiosflags(ios::left)<<setw(7);
if (isi_data.uang==0 || isi_data.uang<isi_data.jml){
cout<<"BELUM LUNAS ";
}
else if(isi_data.uang==isi_data.jml || isi_data.uang>=isi_data.jml){
cout<<"LUNAS";
}
else if(isi_data.uang==isi_data.jml || isi_data.uang<=isi_data.jml){
cout<<"LUNAS" ;
}
else{
cout<<"LUNAS";
}
cout<<setiosflags(ios::left)<<setw(17);
if(isi_data.kembalian<0){
cout<<isi_data.kembalian;
}
else if(isi_data.kembalian!=0){
cout<<" - ";
}
else{
cout<<" - ";
}
cout<<endl;
//
nrecord++;
}
file.close();
}
//-----------------------------------------------------------------------------------------------------------------
void admin :: update_data(int kode_ibu){
admin isi_data;
int sudah=0;
fstream file,temporer;
file.open("data.file",ios::binary|ios::in|ios::app|ios::out);
temporer.open("cdg.tem",ios::binary|ios::in|ios::app|ios::out);
if(ketemu_data(kode_ibu)==0){
cout<<"\n\tMaaf Data Tersebut Tidak Ada...."<<endl;
}

else {
file.seekg(0,ios::beg);
while(file.read((char*)&isi_data,sizeof(isi_data))){
if((isi_data.id_ibu==kode_ibu)&&(sudah==0)){
cout<<"Data Asli"<<endl;
cout<<"Id Ibu : "<<isi_data.id_ibu<<endl;
cout<<"Nama Ibu : "<<isi_data.nama_ibu<<endl;
cout<<"Nama Anak : "<<isi_data.nama_anak<<endl;
cout<<"Usia Anak : "<<isi_data.usia_anak<<endl;
cout<<"Alamat : "<<isi_data.alamat<<endl;
cout<<"Tanggal : "<<isi_data.tanggal<<endl;
cout<<"Pilihan Paket : ";
if (isi_data.pilih==1){
cout<<"Paket VIP";
}
else {
cout<<"Paket Ekonomi";
}
cout<<endl;
cout<<"Pembayaran Anda : "<<isi_data.uang<<endl;
cout<<"Tunggakan Anda Sebesar : ";
if(isi_data.kembalian<0){
cout<<isi_data.kembalian;
}
else if(isi_data.kembalian!=0){
cout<<" - ";
}
else{
cout<<" - ";
}
cout<<endl;
cout<<"============================================================"<<endl;
cout<<endl;
cout<<"\n\t\tData Baru"<<endl;
cout<<"Id Ibu : "<<isi_data.id_ibu<<endl;
cout<<"Nama Ibu : "<<isi_data.nama_ibu<<endl;
cout<<"Nama Anak : "<<isi_data.nama_anak<<endl;
cout<<"Usia Anak : "<<isi_data.usia_anak<<endl;
cout<<"Alamat : "<<isi_data.alamat<<endl;
cout<<"Tanggal : "<<isi_data.tanggal<<endl;
cout<<"Pilihan Paket : ";
if (isi_data.pilih==1){
cout<<"Paket VIP";
}
else {
cout<<"Paket Ekonomi";
}
cout<<endl;
cout<<"Tunggakan Anda Sebesar : ";cin>>isi_data.kembalian;
cout<<endl;
cout<<"Total Membayar Anda : ";cin>>isi_data.jml;
temporer.write((char*)&isi_data,sizeof(isi_data));
break;
}
}

file.seekg(0,ios::beg);
while(file.read((char*)&isi_data,sizeof(isi_data))){
if(isi_data.id_ibu!=kode_ibu){
temporer.write((char*)&isi_data,sizeof(isi_data));
}
}
file.close();
temporer.close();
remove("data.file");
rename("cdg.tem","data.file");
cout<<"Data dengan Id Ibu : " <<isi_data.id_ibu <<" Sudah Dibayar "<<endl<<endl;
}
}
//-----------------------------------------------------------------------------------------------------------------
void admin :: hapus_data(int kode_ibu){
admin isi_data;
fstream file,temporer;
file.open("data.file",ios::binary|ios::in|ios::app|ios::out);
temporer.open("cdg.tem",ios::binary|ios::in|ios::app|ios::out);
if (ketemu_data(kode_ibu)==0){
cout<<"Maaf Data yang anda cari tidak ada "<<endl;
}
else{
while(file.read((char*)&isi_data,sizeof(isi_data))){
if(isi_data.id_ibu!=kode_ibu){
temporer.write((char*)&isi_data,sizeof(isi_data));
}
}
cout<<"Data Telah Dihapus....."<<endl;
file.close();
temporer.close();
remove("data.file");
rename("cdg.tem","data.file");
}
}
//-----------------------------------------------------------------------------------------------------------------
void admin :: centerstring(char* s){
int l=strlen(s);
int pos=(int)((134-l)/2);
for(int i=0;i<pos;i++)
cout<<" ";
cout<<s;
}
void admin :: peraturan(){
ifstream tatib("peraturan.txt");
while(tatib){
tatib.getline(buffer,1000);
cout<<buffer<<endl;
}
tatib.close();
}
