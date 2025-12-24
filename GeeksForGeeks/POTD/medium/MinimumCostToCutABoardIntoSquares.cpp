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
    void pv(vector<int> & v){
        for(auto x : v){
            cout << x << " ";
        }
        cout << endl;
    }
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        ll hs = 1; // horizontal segments
        ll vs = 1; // vertical segments
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        ll cost = 0;
        while(!x.empty() && !y.empty()){
            if(x.back() >= y.back()){
                cost += (ll)x.back()*hs;
                vs++;
                x.pop_back();
            }else{
                cost += (ll)y.back()*vs;
                hs++;
                y.pop_back();
            }
            cout << "hs = " << hs << ", vs = " << vs << endl;
            cout << "x: ";
            pv(x);
            cout << "y: ";
            pv(y);
            cout << "cost = " << cost << endl;
            cout << "---------------------" << endl;
        }
        while(!x.empty()){
            cost += (ll)x.back()*hs;
            vs++;
            x.pop_back();
            cout << "x: ";
            pv(x);
            cout << "cost = " << cost << endl;
            cout << "---------------------" << endl;
        }
        while(!y.empty()){
            cost += (ll)y.back()*vs;
            hs++;
            y.pop_back();
            cout << "y: ";
            pv(y);
            cout << "cost = " << cost << endl;
            cout << "---------------------" << endl;
        }
        return cost;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solution sol;
    {
	vector<int>x={2,1,3,1,4};
	vector<int>y={4, 1, 2};
	sol.minCost(4, 6, x, y);
    }
    return 0;
}

