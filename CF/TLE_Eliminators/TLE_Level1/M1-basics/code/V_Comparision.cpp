#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b;
    char comp;
    cin >> a >> comp >> b;
    if(comp == '>'){
	cout << (a > b ? "Right" : "Wrong") << endl;
    }else if(comp == '<'){
	cout << (a < b ? "Right" : "Wrong") << endl;
    }else{
	cout << (a == b ? "Right" : "Wrong") << endl;
    }
    return 0;
}

