#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    unordered_map<char, int> um;
    um['m'] = 0;
    um['e'] = 1;
    um['o'] = 2;
    um['w'] = 3;
    vector<int> nxt(4,0);
    nxt[0] = 1;
    nxt[1] = 2;
    nxt[2] = 3;
    nxt[3] = -10;

    int t;
    cin >> t;
    while(t--){
	string s;
	int n;
	cin >> n;
	cin >> s;
	int prevState = -1;
	int currState = -1;
	bool isPossible = true;
	for(int i=0;i<n;i++){
	    char c = tolower(s[i]);
	    if(um.count(c) == 0){
		isPossible = false;
		break;
	    }
	    currState = um[c];
	    if(prevState == -1){
		if(c == 'm'){
		    prevState = 0;
		    continue;
		}else{
		    isPossible = false;
		    break;
		}	
	    }else if(currState == prevState){
		continue;
	    }else{
		if(nxt[prevState] != currState){
		    isPossible = false;
		    break;
		}
		prevState = currState;
	    }
	}
	if(isPossible && currState == 3){
	    cout << "YES" << endl;
	}else{
	    cout << "NO" << endl;
	}
    }
    return 0;
}

