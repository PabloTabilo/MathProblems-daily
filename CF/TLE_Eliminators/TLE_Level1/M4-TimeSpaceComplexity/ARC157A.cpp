#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

void printDouble(double d){
    // fix precision, the fixed is for evit rounding 
    // rounding can be different for each compiler
    cout << fixed << setprecision(11) << d << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    
    auto cntMe = [&](const string & s, const string & p){
	int cnt = 0;
	for(int i=0;i<N-1;i++){
	    if(s.substr(i,2) == p){
		cnt++;
	    }
	}
	return cnt;
    };
    auto validate_me = [&](const string & s){
	int cnt;
	cnt = cntMe(s, "XX");
	if(cnt != A) return false;
	cnt = cntMe(s, "XY");
	if(cnt != B) return false;
	cnt = cntMe(s, "YX");
	if(cnt != C) return false;
	cnt = cntMe(s, "YY");
	if(cnt != D) return false;
	return true;
    };

    function<bool(int, int, int, int, const string&)> fn; 

    fn = [&](int a, int b, int c, int d, const string& s)->bool{
	if(N == s.length() && a == 0 && b == 0 && c == 0 && d == 0){
	    //cout << s << '\n';
	    if(validate_me(s)){
		//cout << "this is valid!\n";
		return true;
	    }
	    return false;
	}
	if(s.length() >= N){
	    return false;
	}
	if(a < 0 || b < 0 || c < 0 || d < 0) return false;

	bool isPossible = false;
	if(s.empty()){
	    if(a > 0){
		isPossible = isPossible || fn(a-1, b, c, d, s + "XX");
	    }
	}else{
	    if(s.back() == 'X' && a > 0){
		isPossible = isPossible || fn(a-1, b, c, d, s + "X");
	    }else if(a > 0 && c > 0){
		isPossible = isPossible || fn(a-1, b, c-1, d, s + "XX");
	    }
	}
	if(isPossible) return isPossible;
	
	if(s.empty()){
	    if(b > 0){
		isPossible = isPossible || fn(a, b-1, c, d, s + "XY");
	    }
	}else{
	    if(s.back() == 'X' && b > 0){
		isPossible = isPossible || fn(a, b-1, c, d, s + "Y");
	    }else if(b > 0 && c > 0){
		isPossible = isPossible || fn(a, b-1, c-1, d, s + "XY");
	    }
	}
	if(isPossible) return isPossible;
	
	if(s.empty()){
	    if(c > 0){
		isPossible = isPossible || fn(a, b, c-1, d, s + "YX");
	    }
	}else{
	    if(s.back() == 'Y' && c > 0){
		isPossible = isPossible || fn(a, b, c-1, d, s + "X");
	    }else if(c > 0 && b > 0){
		isPossible = isPossible || fn(a, b-1, c-1, d, s + "YX");
	    }
	}
	if(isPossible) return isPossible;
	if(s.empty()){
	    if(d > 0){
		isPossible = isPossible || fn(a, b, c, d-1, s + "YY");
	    }
	}else{
	    if(s.back() == 'Y' && d > 0){
		isPossible = isPossible || fn(a, b, c, d-1, s + "Y");
	    }else if(d > 0 && b > 0){
		isPossible = isPossible || fn(a, b-1, c, d-1, s + "YY");
	    }
	}	
	return isPossible;
    };

    if(N == 1 && A == 0 && B == 0 && C == 0 && D == 0){
	cout << "No\n";
	return 0;
    }

    bool ans = fn(A, B, C, D, "");
    if(ans){
	cout << "Yes\n";
    }else{
	cout << "No\n";
    }
    return 0;
}

