#include <iostream>
using namespace std;

int main(){
    int N, M, Q;
    cin >> N >> M >> Q;
    int lawn[N][M];

    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j < M ; j++){
            cin >> lawn[i][j];
        }
    }

    for (int c = 0 ; c < Q ; c++){
        int x, y;
        cin >> x >> y;

        int min = lawn[0][0];
        for (int i = 0 ; i <= x-1 ; i++){
            for (int j = 0 ; j <= y-1 ; j++){
                if (lawn[i][j] < min){
                    min = lawn[i][j];
                }
            }
        }
        cout << min << endl;
    }
}