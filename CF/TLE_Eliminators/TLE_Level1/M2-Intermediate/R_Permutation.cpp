#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    unordered_map<int, int> cnt;
    int v;
    for(int i=0;i<n;i++){
	cin >> v;
	cnt[v]++;
    }
    
    for(int i=0;i<n;i++){
	cin >> v;
	cnt[v]++;
    }
    
    for(auto [k, v] : cnt){
	if(v % 2 != 0){
	    cout << "no" << endl;
	    return 0;
	}
    }
    cout << "yes" << endl;
    return 0;
}

