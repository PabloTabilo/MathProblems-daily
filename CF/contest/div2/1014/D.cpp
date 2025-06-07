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
	int mxOpe = 2 * n;
	string s;
	cin >> s;
	// 0: L , 1 : I, 2: T
	int cnt[3] = {0, 0, 0};
	for(int i=0;i<n;i++){
	    char c = s[i];
	    if(c == 'L'){
		cnt[0]++;
	    }else if(c == 'I'){
		cnt[1]++;
	    }else{
		cnt[2]++;
	    }
	}
	if(cnt[0] == cnt[1] && cnt[1] == cnt[2]){
	    cout << 0 << endl;
	    continue;
	}else if((cnt[0] == 0 && cnt[1] == 0) || (cnt[0] == 0 && cnt[2] == 0) || (cnt[1] == 0 && cnt[2] == 0)){
	    cout << -1 << endl;
	    continue;
	}

	int mx = max(cnt[0], max(cnt[1], cnt[2]));
	int d1 = 0;
	int d2 = 0;
	if(cnt[0] == mx){
	    d1 = mx - cnt[1];
	    d2 = mx - cnt[2];
	}else if(cnt[1] == mx){
	    d1 = mx - cnt[0];
	    d2 = mx - cnt[2];
	}else{
	    d1 = mx - cnt[0];
	    d2 = mx - cnt[1];
	}
	int ope = d1 + d2;
	if(ope > mxOpe){
	    cout << -1 << endl;
	    continue;
	}
	
	int idx = -1;
	for(int i=1;i<n;i++){
	    if(s[i-1] != s[i]){
		if((i+1) < n && s[i] != s[i+1]){
		    idx = i;
		    break;
		}else if((i+1)>=n){
		    idx = i;
		    break;
		}
	    }
	} 
	if(idx == -1){
	    cout << -1 << endl;
	    continue;
	}
	cout << ope << endl;
	for(int i=0;i<ope;i++){
	    cout << (i + idx) << endl;
	}
    }
    return 0;
}

