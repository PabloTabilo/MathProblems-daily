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
class Solution {
  public:
      void pv(vector<ll> v){
	for(auto x : v){
	    cout << x << " ";
	}
	cout << endl;
      }
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int n = gas.size();
        vector<ll> diff(n, 0LL);
        vector<ll> prefix(n, 0LL);
        vector<ll> suffix(n, 0LL);
	for(int i=0;i<n;i++){
            diff[i] = (ll)gas[i] - (ll)cost[i];
            prefix[i] = diff[i] + ((i-1)>=0 ? prefix[i-1] : 0LL);
        }

	for(int i=n-1;i>=0;i--){
	    suffix[i] = diff[i] + ((i+1)<n ? suffix[i+1] : 0LL);
	}
	
	cout << "diff = ";pv(diff);
	cout << "prefix = ";pv(prefix);
	cout << "suffix = ";pv(suffix);
        
	int ans = -1;
	ll best = 0;
        for(int i=0;i<n;i++){
	    ll local = 0LL;
	    int start = i;
            while(i < n && diff[i] > 0){
		local += diff[i];
		i++;
            }
	    /*
	    cout << "i = " << i << endl;
	    cout << "start = " << start << endl;
	    cout << "local = " << local << endl;
	    cout << "best = " << best << endl;
	    */
	    ll prev = ((i-1)>=0? prefix[i-1] : 0LL);
	    ll post = suffix[i];
	    if(local > 0 && local > best && (prev+post)>=0){
		ans = start;
		best = local;
	    }
	    //cout << "------------------" << endl;
        }
	cout << "ans = " << ans << endl;
        return ans;
    }
};
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    {
	Solution sol;
	vector<int>gas={4, 5, 7, 4};
	vector<int>cost={6, 6, 3, 5};
	sol.startStation(gas, cost);
    }
    {
	Solution sol;
	vector<int>gas={3, 9};
	vector<int>cost={7, 6};
	sol.startStation(gas, cost);
    }
    {
	Solution sol;
	vector<int>gas={3, 7, 5, 2, 6, 16, 5, 5, 38, 4, 4, 9, 7, 4, 3, 5, 7};
	vector<int>cost={6, 5, 9, 3, 14, 9, 13, 3, 1, 14, 11, 8, 10, 7, 4, 4, 9};
	sol.startStation(gas, cost);
    }
    return 0;
}

