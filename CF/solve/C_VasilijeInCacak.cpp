#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, k, x;
        cin >> n >> k >> x;
        // this is somehard
        // you need to understand that you can create
        // any sum of size k from minSum to maxSum
        // where minSum is 1+2+3+... take k elements
        // and maxSum is n + n-1 + n-2 + ... + n-k+1 from top
        //
        // So any number that's a sum and is on the range [minSum, maxSum]
        // always is possible to create an sum of size k distinct elements
        // because, [minSum, minSum + 1, minSum + 2, ..., maxSum] that's the idea and the probe
        ll mnSum = k * (k+1) / 2;
        ll mxSum = n*(n+1) / 2;
        mxSum -= (n-k)*(n-k+1) / 2;
        if(x >= mnSum && x <= mxSum){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

