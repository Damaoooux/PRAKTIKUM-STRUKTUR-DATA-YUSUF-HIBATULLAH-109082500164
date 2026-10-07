#include<iostream>
using namespace std;

int maks3(int a, int b, int c){
   int temp_max = a;
   if(b > temp_max){
      temp_max = b;
   }
    if(c > temp_max){
        temp_max = c;
    }
    return temp_max;
}

int main(){
    int x, y, z;

    cout << "Masukkan nlai 1 : ";
    cin >> x;

    cout << "Masukkan nlai 2 : ";
    cin >> y;

    cout << "Masukkan nlai 3 : ";
    cin >> z;

    cout << "Nilai Maksimum adalah : " << maks3(x, y, z) << endl;
    return 0;
}