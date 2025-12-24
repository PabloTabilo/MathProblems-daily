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

#ifdef debugcoding
#define debug(x) _print(x); cerr<<endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair<T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v){_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v){_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v){_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (T i : v){_print(i); cerr << " ";} cerr << "]";}

void printDouble(double d){
    // fix precision, the fixed is for evit rounding 
    // rounding can be different for each compiler
    cout << fixed << setprecision(11) << d << '\n';
}
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones) {
	cout << "CALL" << endl;
        // Code here
        // with how many match?
        // if match with one has preference
        // else if match with none, its impossible to out
        unordered_map<int, int> matchRows, matchCols;
        int n = stones.size();
        for(int i=0;i<n;i++){
            int x = stones[i][0];
            int y = stones[i][1];
            matchRows[x]++;
            matchCols[y]++;
        }
        vector<bool> vis(n , false);
        function<int(void)> f = [&](void){
	    cout << "F is call" << endl; 
            int ans = 0;
            for(int i=0;i<n;i++){
                if(vis[i]) continue;
                int x = stones[i][0];
                int y = stones[i][1];
                int match = matchRows[x] + matchCols[y] - 2;
		cout << "x, y = " << x << ", " << y << endl;
		cout << "match = " << match << endl;
                if(match > 0){
                    matchRows[x]--;
                    matchCols[y]--;
                    vis[i] = true; 
                    
                    int curr = 1 + f();
                    ans = max(ans, curr);
                    
                    vis[i] = false;
                    matchRows[x]++;
                    matchCols[y]++;
                }
            }
            return ans;
        };
        return f();
    }
};
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    {
	Solution sol;
	vector<vector<int>> stones = {
	    {0,0},
	    {0,1},
	    {1,0},
	    {1,2},
	    {2,1},
	    {2,2}
	};
	sol.maxRemove(stones);
    }

    return 0;
}

