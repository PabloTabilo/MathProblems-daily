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
    int n, k;
    cin >> n >> k;
    bool * dp = new bool[n+1];
    memset(dp, true, (n+1) * sizeof(bool));
    dp[0] = dp[1] = false;
    for(int i=2;i<=n;i++){
	if(dp[i]){
	    for(int j=2;j*i<=n;j++){
		dp[i*j] = false;
	    }
	}
    }
    int p1 = 2;
    int p2 = 3;
    int cnt = 0;
    while(p1 <= n && p2 <= n && cnt < k){
	while(!dp[p1]){
	    p1++;
	}
	p2 = p1+1;
	while(!dp[p2]){
	    p2++;
	}
	int v = p1 + p2 + 1;
	if(v <= n && dp[v]){
	    cnt++;
	}
	p1 = p2;
    }

    if(cnt < k){
	cout << "NO\n";
    }else{
	cout << "YES\n";
    }


    return 0;
}

