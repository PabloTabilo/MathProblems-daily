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
    int n;
    cin >> n;
    vector<ll> A(n);
    for(int i=0;i<n;i++){
	cin >> A[i];
    }
    ll mn = LLONG_MAX;
    for(int i=0;i<n;i++){
	ll mo = 0;
	int p1 = i - 1;
	ll last = 0LL;
	while(p1 >= 0){
	    //cout << "last = " << last << endl;
	    ll k = last / A[p1];
	    mo += (k+1);
	    last = (A[p1]*(k+1));
	    //cout << "k = " << k << endl;
	    //cout << "current mo = " << mo << endl;
	    //cout << "new last = " << last << endl;
	    p1--;
	}
	int p2 = i + 1;
	last = 0LL;
	while(p2 < n){
	    //cout << "last = " << last << endl;
	    ll k = last / A[p2];
	    mo += (k+1);
	    last = (A[p2]*(k+1));
	    //cout << "k = " << k << endl;
	    //cout << "current mo = " << mo << endl;
	    //cout << "new last = " << last << endl;
	    p2++;
	}
	mn = min(mn, mo);
    }
    cout << mn << "\n";
    return 0;
}

