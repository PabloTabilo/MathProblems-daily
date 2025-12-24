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
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    ll tot = A + B + C + D;
    if(B == C && B == 0 && A > 0 && D > 0){
	cout << "No\n";
	return 0;
    }
    if(abs(B - C) <= 1 && (N-1) == tot){
	cout << "Yes\n";
    }else{
	cout << "No\n";
    }
    return 0;
}

