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
    void pdq(deque<int> dq){
        for(auto x : dq){
            cout << x << " ";
        }
        cout << endl;
    }
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int left = 0;
        int i = 0;
        int n = arr.size();
        deque<int> dq;
        int state = -1;
	int ans = 0;
        while(i < n){
	    // the window is clean
	    while(i<n && arr[i] == 1 && dq.size() == 0){
		i++;
	    }
	    // fill the window
            while(i < n && dq.size() != k){
                dq.push_back(arr[i]);
                i++;
            }
	    if(dq.size() == k){
		ans++;
	    }
            cout << "start:";
            pdq(dq);
            state = 1 - dq.front();
            cout << "i = " << i << " and state = " << state << endl;
	    // process the window + persist state prev
            while(dq.size() > 0){
                int nxt = dq.front();
                cout << "nxt = " << nxt << endl;
                if((nxt ^ state) == 1){
                    cout << "xor is 1" << endl;
                    dq.pop_front();
                }else{
		    dq.pop_front();
		    dq.push_front(1-nxt);
                    cout << "xor is 0, new state = " << state << endl;
                    break;
                }
            }
	    cout << "lastState dq: ";
            pdq(dq);
	    cout << "-------------------------" << endl;
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solution sol;
    {
	vector<int> arr = {1,1,0,0,0,1,1,0,1,1,1};
	int ans = sol.kBitFlips(arr, 2);
	cout << "ans = " << ans << endl;
    }
    {
	vector<int> arr = {0,0,1,1,1,0,0};
	int ans = sol.kBitFlips(arr, 3);
	cout << "ans = " << ans << endl;
    }

    return 0;
}

