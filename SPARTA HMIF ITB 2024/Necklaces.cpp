#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct command{
    string action;
    int bead;
};

struct bead{
    bool left;
    bool right;
};

int main(){
    int N, M;
    cin >> N >> M;
    vector<bead> kalung(N);
    vector<command> perintah(M);

    for (int i = 0; i < N; i++) {
        kalung[i].left = true;
        kalung[i].right = true;
    }
    for (int i = 0 ; i < M ; i++){
        // Tidak butuh push_back kalau udah ada deklarasi ukurannya, tinggal akses indeks
        cin >> perintah[i].action >> perintah[i].bead;
    }

    // // Kalau gak ada deklarasi ukuran, pake push_back kayak gini
    // vector<command> perintah;
    // for (int i = 0; i < M; i++) {
    //     command temp;
    //     cin >> temp.action >> temp.bead;
    //     perintah.push_back(temp);  // untuk vektor yang belum diisi
    // }


    for (int i = 0 ; i < M ; i++){
        if (perintah[i].action == "R"){
            kalung[perintah[i].bead - 1].right = false;
            kalung[perintah[i].bead].left = false;
        }
        else if (perintah[i].action == "Q"){
            int res = 1;
            // Cek kiri
            for (int j = perintah[i].bead - 2 ; j >= 0 ; j--){
                if (kalung[j].right == true){
                    res++;
                }
                else{
                    break;
                }
            }
            // Cek kanan
            for (int j = perintah[i].bead ; j < N ; j++){
                if (kalung[j].left == true){
                    res++;
                }
                else{
                    break;
                }
            }
            cout << res << endl;
        }
    }
}