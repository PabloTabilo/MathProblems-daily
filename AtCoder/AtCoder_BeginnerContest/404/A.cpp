#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    
    vector<int> cnt(26);
    for(auto c : s){
	cnt[c - 'a']++;
    }

    for(int i=0;i<26;i++){
	if(cnt[i] == 0){
	    char c = i + 'a';
	    cout << c << endl;
	    break;
	}
    }

    return 0;
}

