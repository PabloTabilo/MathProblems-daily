#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll a, b, k;

    cin >> a >> b >> k;

    bool aDiv = a % k == 0;
    bool bDiv = b % k == 0;

    if(aDiv && bDiv){
	cout << "Both" << endl;
    }else if(aDiv){
	cout << "Memo" << endl;
    }else if(bDiv){
	cout << "Momo" << endl;
    }else{
	cout << "No One" << endl;
    }
    return 0;
}

