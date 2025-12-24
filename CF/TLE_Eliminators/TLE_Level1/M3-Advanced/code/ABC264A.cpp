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
    int a, b, c, d, e;
    int n = 14;
    int cnt[n] = {0};
    memset(cnt, 0, n * sizeof(int));
    cin >> a >> b >> c >> d >> e;
    cnt[a]++;
    cnt[b]++;
    cnt[c]++;
    cnt[d]++;
    cnt[e]++;
    bool existCnt3 = false;
    bool existCnt2 = false;
    for(int i=1;i<=13;i++){
	if(cnt[i] == 3){
	    existCnt3 = true;
	}
	if(cnt[i] == 2){
	    existCnt2 = true;
	}
    }
    bool isPossible = existCnt3 && existCnt2;
    if(isPossible){
	cout << "Yes\n"; 
    }else{
	cout << "No\n"; 
    }

    return 0;
}

