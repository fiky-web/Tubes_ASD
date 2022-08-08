// Fiky Anggara
// Teknologi Informasi

#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <time.h>
#include "admin.h"
#include "titipanak.h"
using namespace std;
titipanak::titipanak(){
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void titipanak::jadwal(){
ifstream jadwal("jadwal.txt");
while(jadwal){
jadwal.getline(buffer,1000);
cout<<buffer<<endl;
}
jadwal.close();
}
//---------------------------------------------------------------------------
