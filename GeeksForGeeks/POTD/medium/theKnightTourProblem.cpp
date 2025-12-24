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
    vector<vector<int>> knightTour(int n) {
        // code here
        int posX[8] = {+1, -1, +1, -1, -2, +2, -2, +2};
        int posY[8] = {-2, -2, +2, +2, -1, -1, +1, +1};
        vector<vector<int>> sol(n, vector<int>(n, -1));
        function<bool(int, int, int)>f = [&](int x, int y, int step){
            //cout << "last x, y = " << x << "," << y << endl;
            //cout << "nxt step = " << step << endl;
            if((n*n) == step){
                return true;
            }
	    if(step > (n*n)){
		return false;
	    }
            for (int k=0;k<8;k++){
                int nx = x + posX[k];
                int ny = y + posY[k];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n){
                    continue;
                }
                if(sol[nx][ny] != -1){
                    continue;
                }
                sol[nx][ny] = step;
                bool branch = f(nx, ny, step+1);
		if(branch){
		    return true;
		}
                sol[nx][ny] = -1;
            }
	    return false;
        };
        sol[0][0] = 0;
        f(0,0,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
        return sol;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solution sol;
    {
	sol.knightTour(4);
    }
    return 0;
}

