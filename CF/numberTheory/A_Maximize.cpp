#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

vector<int> primes_factors(int x){
    set<int> s;
    for(int i=2;i*i <= x; i++){
	while(x % i == 0){
	    s.insert(i);
	    x /= i;
	}
    }
    if(x > 1){
	s.insert(x);
    }
    vector<int> a(s.begin(), s.end());
    return a;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int x;
	cin >> x;
	vector<int> primes = primes_factors(x);
	//cout << "unique primes: ";for(auto p : primes) cout << p << " ";cout << endl;
	int mn = primes[0];
	// x is prime
	//cout << "ans = ";
	if(mn == x){
	    cout << mn-1 << endl;
	}else{
	    int times = ( x % mn == 0 ? x/mn - 1 : x/mn);
	    int num = mn * times;
	    cout << num << endl;
	}
    }
    return 0;
}

