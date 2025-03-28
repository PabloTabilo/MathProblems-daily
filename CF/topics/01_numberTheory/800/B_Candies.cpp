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
	if(n % 2 == 0){
	    cout << -1 << endl;
	    continue;
	}
	vector<int> ans;
	bool isPossible = true;
	while(n > 1){
	    int op1 = n + 1;
	    op1 /= 2;
	    int op2 = n - 1;
	    op2 /= 2;
	    if(op1 % 2 == 1){
		ans.push_back(1);
		n = op1;
	    }else if(op2 % 2 == 1){
		ans.push_back(2);
		n = op2;
	    }else{
		isPossible = false;
		break;
	    }
	}
	if(isPossible){
	    cout << ans.size() << endl;
	    reverse(ans.begin(), ans.end());
	    for(int x : ans){
		cout << x << " ";
	    }
	    cout << endl;
	}else{
	    cout << -1 << endl;
	}
    }


    return 0;
}

