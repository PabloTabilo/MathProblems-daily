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
	int n0s = 3;
	int n1s = 1;
	int n3s = 1;
	int n2s = 2;
	int n5s = 1;
	int d;
	int tot;
	bool isPossible = false;
	int ans = 1;
	for(int i=0;i<n;i++){
	    cin >> d;
	    if(d == 0){
		n0s--;
		n0s = max(n0s, 0);
	    }else if(d == 1){
		n1s--;
		n1s = max(n1s, 0);
	    }else if(d == 3){
		n3s--;
		n3s = max(n3s, 0);
	    }else if(d == 2){
		n2s--;
		n2s = max(n2s, 0);
	    }else if(d == 5){
		n5s--;
		n5s = max(n5s, 0);
	    }
	    tot = n0s + n1s + n2s + n3s + n5s;
	    if(tot == 0 && !isPossible){
		isPossible = true;
		ans = i + 1;
	    }
	}
	if(isPossible){
	    cout << ans << endl;
	}else{
	    cout << 0 << endl;
	}
	
    }

    return 0;
}

