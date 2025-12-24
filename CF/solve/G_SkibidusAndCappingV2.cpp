#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

vector<int> primes_factors(int x){
    vector<int> pf;
    for(int i=2;i*i<=x;i++){
	while(x % i == 0){
	    pf.push_back(i);
	    x /= i;
	}
    }
    if(x > 1){
	pf.push_back(x);
    }
    return pf;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    map<int, set<int>> p;
    int t;
    cin >> t;
    while(t--){
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, ll> f;
	map<int, ll> semi;
	int mx = 0;
	for(int i=0;i < n; i++){
	    cin >> a[i];
	    mx = max(mx, a[i]);
	}
	ll cnt = 0;
	ll cnt_primes = 0;
	for(int i=0;i<n;i++){
	    int x = a[i];
	    f[x]++;
	    vector<int> pf = primes_factors(x);
	    // is prime
	    if(pf.size() == 1){
		int p = pf[0];
		//cout << "x = " << x << " is prime p = " << p << endl;
		// curr = 2
		// 3, 7, 4, 15, .
		// (3, 2), (7, 2), (4, 2)
		cnt_primes++;
		cnt += cnt_primes - f[x];
		cnt += semi[p]; // all the semis of p, any multiple
	    }
	    // semi prime p*q
	    // p = q or p != q
	    else if(pf.size() == 2){
		// 4 = 2 * 2 -> lcm(4,4) = 4
		// 6 = 3 * 2 -> lcm(6,6) = 6
		// lcm(p*q, z*w) = lcm(2*2, 3*5) = lcm(4, 15) = 4 * 15 NOT INTEREST
		// lcm(p*q, p) = p*q is semi prime
		// lcm(p*p, p) = p*p is semi prime
		int p = pf[0];
		int q = pf[1];
		//cout << "x is semi prime = " << x << ", p = " << p << ", q = " << q << endl;
		if(p == q){
		    if(f.count(p) > 0){
			cnt += f[p];
		    }
		    semi[p]++;
		}else{
		    if(f.count(p) > 0){
			cnt += f[p];
		    }
		    if(f.count(q) > 0){
			cnt += f[q];
		    }
		    semi[p]++;
		    semi[q]++;
		}
		cnt += f[x]; // add it-self -> lcm(p*q, p*q) = p*q
	    }
	    //cout << "cnt = " << cnt << endl;
	    //cout << "----------------" << endl;
	    // p * q * z ...
	    // lcm(p*q*z, p*q) = p*q*z NOT INTEREST
	    // lcm(p*q*z, p) = p*q*z NOT INTEREST
	}	
	//cout << "cnt = ";
	cout << cnt << endl;
    }
    return 0;
}

