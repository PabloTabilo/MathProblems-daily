#include <iostream>
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
	vector<int> cnt(101, 0);
	for(int i=0;i<n;i++){
	    int v;
	    cin >> v;
	    cnt[v]++;
	}
	int mex1 = 0;
	int mex2 = 0;
	for(int i=0;i<=101;i++){
	    if(cnt[i] > 0){
		mex1 = i + 1;
		cnt[i]--;
	    }else{
		break;
	    }
	}
	for(int i=0;i<=101;i++){
	    if(cnt[i] > 0){
		mex2 = i + 1;
		cnt[i]--;
	    }else{
		break;
	    }
	}
	int ans = mex1 + mex2;
	//cout << "ans = ";
	cout << ans << endl;
    }

    return 0;
}

