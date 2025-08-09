#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const long long MOD = 1e9 + 7;

struct probs{
    string title;
    int diff;
};

bool cmp(const probs &A, const probs &B){
    return A.diff < B.diff;
}

long long faktorial(int n) {
    long long res = 1;
    for (int i = 2 ; i <= n ; i++){
        res *= i % MOD;
    }
    return res;
}

int main(){
    int N;
    cin >> N;
    probs Tab[N];

    for (int i = 0 ; i < N ; i++){
        cin >> Tab[i].title >> Tab[i].diff;
    } 

    vector<int> temp;

    sort(Tab, Tab + N, cmp);
    int counter = 1;
    for (int i = 0 ; i < N-1 ; i++){
        if (Tab[i + 1].diff == Tab[i].diff){
            counter++;
        }
        else{
            temp.push_back(counter);
            counter = 1;
        }
    }
    temp.push_back(counter);

    long long result = 1;
    for (int i = 0 ; i < temp.size() ; i++){
        result *= faktorial(temp[i]) % MOD;
    }

    cout << result << endl;
}