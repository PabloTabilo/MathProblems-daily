#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<string> s, t;
    string temp;
    for(int i=0;i<n;i++){
	cin >> temp;
	s.push_back(temp);
    }
    
    for(int i=0;i<n;i++){
	cin >> temp;
	t.push_back(temp);
    }
    int ans = 100000;
    for(int rot = 0; rot < 4; rot++){
	int missMatch = 0;
	if(rot > 0){
	    vector<vector<char>> st(n, vector<char>(n));
	    for(int i=0;i<n;i++){
		temp = s[i];
		for(int j=0;j<n;j++){
		    st[j][n-1-i] = temp[j];
		}
	    }
	    missMatch += rot;
	    vector<string> s2;
	    for(int i=0;i<n;i++){
		temp = "";
		for(int j=0;j<n;j++){
		    temp.push_back(st[i][j]);
		}
		s2.push_back(temp);
	    }
	    s = s2;
	}

	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
		if(s[i][j] != t[i][j]){
		    missMatch++;
		}
	    }
	}
	ans = min(ans, missMatch);
    }

    cout << ans << endl;

    return 0;
}

