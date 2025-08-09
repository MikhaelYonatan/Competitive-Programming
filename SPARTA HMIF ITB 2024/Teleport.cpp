#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct koor_por{
    int x1;
    int y1;
    int x2;
    int y2;
};

struct koor_p{
    int x;
    int y;
};

int main(){
    int N, M, K;
    cin >> N >> M >> K;

    vector<string> map(N);
    for (int i = 0 ; i < N ; i++){
        cin >> map[i];
    }

    vector<koor_por> portal(K);
    for (int i = 0 ; i < K ; i++){
        cin >> portal[i].x1 >> portal[i].y1 >> portal[i].x2 >> portal[i].y2;
    }

    koor_p player;
    player.x = 0;
    player.y = 0;
    int step = 0;

    while(player.x != N-1 || player.y != M-1){
        bool moved = false;
        for (int i = 0; i < K; i++) {
            if (player.x == portal[i].x1 - 1 && player.y == portal[i].y1 - 1) {
                player.x = portal[i].x2 - 1;
                player.y = portal[i].y2 - 1;
                moved = true;
                break;
            }
        }

        if (moved) {
            continue;
        }
        if (player.y + 1 < M && map[player.x][player.y + 1] != '#') {
            step++;
            player.y++;
        } 
        else if (player.x + 1 < N && map[player.x + 1][player.y] != '#') {
            step++;
            player.x++;
        } 
    }
    cout << step << endl;
}