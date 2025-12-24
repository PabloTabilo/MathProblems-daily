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

typedef long long ll;
// User function Template for C++
class Solution {
  public:
    string matrixChainOrder(vector<int> &arr) {
        // code here
        // arr[] = [40, 20, 30, 10, 30]
        // A : 40x20
        // B: 20x30
        // C: 30x10
        // D: 10x30
        
        // ((AxB)xC)xD = (40x20x30) + (40x30x10) + (40x10x30)
        // (AxB)x(CxD) = (40x20x30) + (30x10x30) + (40x30x30)
        // (Ax(BxC))xD
        // Ax((BxC)xD)
        
        // [A, B, C, D]
        //      [(AB), C, D]
        //          [(ABC), D]
        //              [(ABCD)] (Finish)
        //          [(AB),(CD)]
        //              [(ABCD)] (Finish)
        //      [A, (BC), D]
        //      [A, B, (CD)]
        set<string>s;
        string t;
	t += '(';
        int n = arr.size();
        unordered_map<string, pair<ll, ll>> dim;
        for(int i=0;i<(n-1);i++){
            t += char(i + 'A');
	    t += ')';
            dim[t] = {arr[i], arr[i+1]};
            s.insert(t);
            t.pop_back();
            t.pop_back();
        }
        ll globalMin = LLONG_MAX;
        string ans = "";
        function<void(set<string>s, ll, string)> f = [&](set<string> s, ll minTot, string lastOpe){
            int m = s.size();
            if(m == 1){
                cout << "m3 = " << lastOpe << endl;
                cout << "minTot = " << minTot << endl;
                if(globalMin > minTot){
                    globalMin = minTot;
                    ans = lastOpe;
                }
                return;
            }
            auto it = s.begin();
            while(it != s.end()){
		auto nxt = it;
		nxt++;

                if(nxt == s.end()) break;

		string m1 = *it;
                string m2 = *nxt;
		string m3;
		m3 += '(';
		if(m1.size() == 3 && m2.size() == 3){
		m3 += m1[1];
		m3 += m2[1];
		}else if(m1.size() == 3){
		    m3 += m1[1];
		    m3 += m2;
		}else if(m2.size() == 3){
		    m3 += m1;
		    m3 += m2[1];
		}else{
		    m3 += m1;
		    m3 += m2;
		}
		m3 += ')';
		
                ll op = dim[m1].first * dim[m1].second * dim[m2].second;
                
		dim[m3] = {dim[m1].first, dim[m2].second};
                s.erase(m1);
                s.erase(m2);
                s.insert(m3);
                
                cout << "m1 = " << m1 << ", m2 = " << m2 << ", m3 = " << m3 << endl;
                
                f(s, minTot + op, m3);
                
                s.erase(m3);
                s.insert(m1);
                s.insert(m2);
		
		it = s.find(m2);
		nxt = it;
		nxt++;
            
            }
        };
        f(s, 0LL, "");
        for(auto [k, v] : dim){
            cout << k << " -> " << v.first << ", " << v.second << endl;
        }
	cout << "globalMin = " << globalMin << ", ans = " << ans << endl;
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solution sol;
    vector<int> arr = {40, 20, 30, 10, 30};
    sol.matrixChainOrder(arr);

    return 0;
}

