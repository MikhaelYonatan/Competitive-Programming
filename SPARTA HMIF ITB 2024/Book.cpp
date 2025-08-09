#include <iostream>
#include <cstring>
using namespace std;

struct Buku {
    char judul[13];
    int tahun;
};

int main(){
    int N;
    cin >> N;
    Buku shelf[N];

    for (int i = 0 ; i < N ; i++){
        cin >> shelf[i].judul >> shelf[i].tahun;
    }

    if (N > 1){
        for (int pass = 0 ; pass < N-1 ; pass++){
            int IMin = pass;
            for (int i = pass + 1 ; i < N ; i++){
                char hurufA = shelf[IMin].judul[0];
                char hurufB = shelf[i].judul[0];
                if (hurufA > hurufB || (hurufA == hurufB && shelf[IMin].tahun > shelf[i].tahun)){
                    IMin = i;
                }
            }
            Buku temp = shelf[IMin];
            shelf[IMin] = shelf[pass];
            shelf[pass] = temp;
        }
    }

    for (int i = 0 ; i < N ; i++){
        cout << shelf[i].judul << endl;
    }
}