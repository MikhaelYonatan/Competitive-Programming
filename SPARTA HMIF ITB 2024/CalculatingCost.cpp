#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int mean(vector<int> data){
    int sum = 0;
    for (int x : data){
        sum += x;
    }
    int mean = sum/data.size();
    return mean;
}

int median(vector<int> data){
    sort(data.begin(), data.end());
    if (data.size() % 2 == 0){
        int i = data.size() / 2 - 1;
        int j = data.size() / 2;
        return ((data[i] + data[j])/2);
    }
    else{
        int j = data.size() / 2;
        return data[j];
    }
}

int mode(vector<int> data){
    sort(data.begin(), data.end());
    int counter_res = 1;
    int result;
    int counter = 1;
    for (int i = 0 ; i < data.size()-1 ; i++){
        if (data[i + 1] == data[i]){
            counter++;
        }
        else{
            counter = 1;
        }
        if (counter >= counter_res){
            counter_res = counter;
            result = data[i];
        }
    }
    return result;
}

int main (){
    int N;
    cin >> N;
    vector<int> data;

    for (int i = 0 ; i < N ; i++){
        int x;
        cin >> x;
        data.push_back(x);
    }

    cout << mean(data) << endl;
    cout << median(data) << endl;
    cout << mode(data) << endl;
}