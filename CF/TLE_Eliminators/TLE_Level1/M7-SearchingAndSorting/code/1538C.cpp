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
	ll n, l, r;
	cin >> n >> l >> r;
	ll * A = new ll[n];
	for(int i=0;i<n;i++){
	    cin >> A[i];
	}
	sort(A, A + n);
	
	//cout << "A (sorted) = ";
	//for(int i=0;i<n;i++){
	//    cout << A[i] << " ";
	//}
	//cout << endl;

	ll ans = 0;
	for(int i=n-1;i >=0; i--){
	    ll li = l - A[i];
	    ll ri = r - A[i];
	    li = max(li, 1LL);
	    auto it_l = lower_bound(A, A+i, li);
	    auto it_r = upper_bound(A, A+i, ri);
	    //cout << "A[i] = A["<<i<<"] = " << A[i] << endl;
	    //cout << "li = " << li << ", ri = " << ri << endl;
	    int leftIdx = 0;
	    int rightIdx = 0;
	    if(it_l != A+n){
		leftIdx = it_l - A;
	    }
	    if(it_r != A+n){
		rightIdx = it_r - A;
	    }
	    //cout << "leftIdx = " << leftIdx << " -> rightIdx = " << rightIdx << endl;
	    if(leftIdx >= rightIdx){
		continue;
	    }
	    rightIdx--;
	    ll diff = rightIdx - leftIdx + 1;
	    //cout << "diff = " << diff << endl;
	    ans += diff;
	    //cout << "***************" << endl;
	}
	//cout << "ans = ";
	cout << ans;
	//cout << endl;
	cout << '\n';
	//cout << "------------------------" << endl;
    }
    return 0;
}

