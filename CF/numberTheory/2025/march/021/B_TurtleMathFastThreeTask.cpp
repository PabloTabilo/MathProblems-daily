#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int n;
	cin >> n;
	int tot = 0;
	vector<int> a(n);
	for(int i=0;i<n;i++){
	    cin >> a[i];
	    tot += a[i];
	}
	//cout << "ans = ";
	if(tot % 3 == 0){
	    cout << 0 << endl;
	    continue;
	}
	else if(tot % 3 == 2){
	    // increment 1
	    cout << 1 << endl;
	    continue;
	}
	bool exists = false;
	for(int x : a){
	    if(tot % 3 == x % 3){
		exists = true;
		break;
	    }
	}
	if(exists){
	    cout << 1 << endl;
	}else{
	    cout << 2 << endl;
	}
    }
    return 0;
}

