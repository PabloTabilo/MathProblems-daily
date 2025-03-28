#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int x;
	cin >> x;
	if(x % 33 == 0){
	    cout << "YES" << endl;
	}else{
	    cout << "NO" << endl;
	}
    }
    return 0;
}

