// #include <iostream>
// using namespace std;

// yang ini kena time limit
// struct worker{
//     int start;
//     int time;
// };

// int main(){
//     int N, X;
//     cin >> N >> X;

//     worker list[N];
//     for (int i = 0 ; i < N ; i++){
//         cin >> list[i].start >> list[i].time;
//     }

//     int result = 0, hour = 0;

//     while (result < X){
//         for (worker x : list){
//             if(hour <= x.start){
//                 continue;
//             }
//             else{
//                 if (x.time == 1){
//                     result++;
//                 }
//                 else if ((hour == x.start + x.time) || (hour % x.time == (x.start + x.time) % x.time)){
//                     result++;
//                 }
//             }
//         }
//         hour++;
//     }

//     cout << hour - 1 << endl;
// }


// #include <iostream>
// using namespace std;

// struct worker{
//     int start;
//     int time;
// };

// bool completed(long long hour, worker *list, int N, int X){
//     long long total = 0;
//     for (int i = 0 ; i < N ; i++){
//         if (hour >= list[i].start){
//             total += (hour - list[i].start) / list[i].time;
//         }
//     }
//     return total >= X;
// } 

// int main(){
//     int N, X;
//     cin >> N >> X;

//     worker list[N];
//     for (int i = 0 ; i < N ; i++){
//         cin >> list[i].start >> list[i].time;
//     }

//     long long left = 0, right = 1e18;
//     while (left < right){
//         long long mid = left + (right - left) / 2;
//         if (completed(mid, list, N, X)){
//             right = mid;
//         }
//         else{
//             left = mid + 1;
//         }
//     }
//     cout << left << endl;
// }


#include <iostream>
#include <vector>
using namespace std;

struct worker {
    int start;
    int time;
};

bool completed(long long hour, vector<worker>& list, long long X) {
    long long total = 0;
    for (worker x : list) {
        if (hour > x.start) {
            total += (hour - x.start) / x.time;
        }
        if (total >= X) {
            return true;
        }
    }
    return total >= X;
}

int main() {
    int N;
    long long X;
    cin >> N >> X;

    vector<worker> list(N); 

    for (int i = 0; i < N; i++) {
        cin >> list[i].start >> list[i].time;
    }

    long long left = 0, right = 1e18;
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (completed(mid, list, X)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << left << endl;
}


