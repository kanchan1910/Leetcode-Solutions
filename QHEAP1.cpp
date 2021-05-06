// https://www.hackerrank.com/challenges/qheap1/problem
#include <bits/stdc++.h>
using namespace std;


int main() {
    priority_queue<int,vector<int>,greater<int>> pq;
    int q;
    unordered_set<int> s;
    cin>>q;
    for(int i=0;i<q;i++){
        int x,y;
        cin >> x;
        if(x==1){
            cin >> y;
            pq.push(y);
        }
        if(x==2){
            cin >> y;
            s.insert(y);
        }
        if(x==3){
            while(!pq.empty() && s.find(pq.top())!=s.end()){
                pq.pop();
            }
            cout << pq.top() << endl;
        }
    }
    return 0;
}
