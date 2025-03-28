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
	int x;
	vector<int> ans;
	vector<int> odds;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
	    cin >> x;
	    a[i] = x;
	    if(x % 2 == 0){
		ans.push_back(i);
	    }else{
		if(odds.size() == 1){
		    ans.push_back(odds.back());
		    odds.pop_back();
		    ans.push_back(i);
		}else{
		    odds.push_back(i);
		}
	    }
	}
	if(odds.size() == 0){
	    int sz = min(int(ans.size()), 100);
	    cout << sz << endl;
	    for(int i=0;i<sz;i++){
		cout << ans[i] << " ";
	    }
	    cout << endl;
	    continue;
	}
	int tot = 0;
	//cout << "ans: ";
	for(auto x : ans){
	    tot += a[x];
	    //cout << x << " ";
	}
	//cout << endl << "tot = " << tot << endl;
	//cout << "odds: ";
	//for(auto x : odds){
	//    cout << x << " ";
	//}
	//cout << endl;
	int c1 = tot;
	int c2 = tot + a[odds[0]];
	int N = c2;
	int cnt = 0;
	//cout << "c1 = " << c1 << ", c2 = " << c2 << endl;
	for(int i=2;i*i<=N;i++){
	    //cout << "i = " << i << ", N = " << N << endl;
	    int prev = N;
	    while(N % i == 0){
		N /= i;
	    }
	    if(prev != N){
		cnt++;
	    }
	    //cout << "post while of i = " << i << ", N = " << N << endl;
	}
	//cout << "final N : " << N << endl;
	//cout << "cnt : " << cnt << endl;
	if(cnt == 0){
	    int sz = min(int(ans.size()), 100);
	    cout << sz << endl;
	    for(int i=0;i<sz;i++){
		cout << ans[i] << " ";
	    }
	    cout << endl;
	}else{
	    if(ans.size() >= 100){
		int sz = min(int(ans.size()), 100);
		cout << sz << endl;
		for(int i=0;i<sz;i++){
		    cout << ans[i] << " ";
		}
		cout << endl;
	    }else{
		cout << ans.size() + 1 << endl;
		for(auto x : ans){
		    cout << x << " ";
		}
		cout << odds[0] << endl;
	    }
	}
    }
    return 0;
}

