#include<iostream>
using namespace std;


int main(){
float a,b;
float penjumlahan;
float pengurangan;
float perkalian;
float pembagian;

 cout<<"Masukkan nilai a: ";
 cin>>a;
 cout<<"Masukkan nilai b: ";
 cin>>b;

//Penjumlahan
penjumlahan = a + b;
cout<<"Hasil penjumlahan a dan b: "<<penjumlahan<<endl;

//pengurangan
pengurangan = a - b;
cout<<"Hasil pengurangan a dan b: "<<pengurangan<<endl;

//perkalian
perkalian = a * b;
cout<<"Hasil perkalian a dan b: "<<perkalian<<endl;

//pembagian
if (b == 0) {
    cout << "Error: Pembagian dengan nol tidak diperbolehkan." << endl;
} else {
pembagian = a / b;
cout<<"Hasil pembagian a dan b: "<<pembagian<<endl;
}

 return 0;
}