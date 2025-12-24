#include <iostream>
#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace chrono;

/* -- Red black tree for build a set that can get kth position -- */
/* -- not accept duplicates, its possible to implement? -- */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;


using ll = long long;
using pii = pair<int,int>;

void printDouble(double d){
    // fix precision, the fixed is for evit rounding 
    // rounding can be different for each compiler
    cout << fixed << setprecision(11) << d << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	ll n, k;
	cin >> n >> k;
	vector<ll>A(n);
	vector<ll>B(n);
	for(int i=0;i<n;i++){
	    cin >> A[i];
	}
	ll x = -1;
	bool isPossible = true;
	
	ll mn = INT_MAX;
	ll mx = INT_MIN;
	
	for(int i=0;i<n;i++){
	    cin >> B[i];
	    if(B[i] != -1){
		if(x == -1){
		    x = A[i] + B[i]; 
		    //cout << "possible x = " << x << '\n';
		}else{
		    //cout << "this is ok? : " << (A[i] + B[i]) << '\n';
		    if(x != (A[i]+B[i])){
			isPossible = false;
		    }
		}
	    }else{
		if(mn > A[i]){
		    mn = A[i];
		}
		if(mx < A[i]){
		    mx = A[i];
		}
	    }
	}
	if(!isPossible){
	    cout << 0 << '\n';
	    //cout << "------------------------" << '\n';
	    continue;
	}
	if(x != -1){
	    for(auto a : A){
		ll bi = x - a;
		if(bi > k || bi < 0){
		    isPossible = false;
		    break;
		}
	    }
	    if(isPossible){
		cout << 1 << '\n';
	    }else{
		cout << 0 << '\n';
	    }
	    //cout << "------------------------" << '\n';
	    continue;
	}
	//cout << "mn = " << mn << '\n';
	//cout << "mx = " << mx << '\n';
	ll upperVal = mn + k;
	ll bi = upperVal - mx;
	//cout << "upperVal = " << upperVal << '\n';
	if(bi >= 0){
	    cout << (bi+1) << '\n';
	}else{
	    cout << 0 << '\n';
	}
	//cout << "------------------------" << '\n';
    }

    return 0;
}

