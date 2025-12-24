#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string f1, s1;
    string f2, s2;
    cin >> f1 >> s1;
    cin >> f2 >> s2;

    if(s1 == s2){
	cout << "ARE Brothers" << endl;
    }else{
	cout << "NOT" << endl;
    }

    return 0;
}

