#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

void printDouble(double d){
    // fix precision, the fixed is for evit rounding 
    // rounding can be different for each compiler
    cout << fixed << setprecision(11) << d << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> f;
    for(int i=0;i<n;i++){
	int k;
	cin >> k;
	f[k]++;
    }
    bool isValid = true;
    for(int i=0;i<m;i++){
	int bi;
	cin >> bi;
	if(f.count(bi) == 0 || f[bi] == 0){
	    isValid = false;
	}
	if(f.count(bi) > 0 && f[bi] > 0){
	    f[bi]--;
	}
    }

    if(isValid){
	cout << "Yes\n";
    }else{
	cout << "No\n";
    }

    return 0;
}

