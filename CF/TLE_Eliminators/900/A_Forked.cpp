#include <iostream>
#include <bits/stdc++.h>
#include <set>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        int xk, yk;
        int xq, yq;
        cin >> a >> b;
        cin >> xk >> yk;
        cin >> xq >> yq;
        int xMoves[8] = {+a, -a, +a, -a, +b, -b, +b, -b};
        int yMoves[8] = {+b, +b, -b, -b, +a, +a, -a, -a};
        int cnt = 0;
        //cout << "xk = " << xk << ", yk = " << yk << endl;
        set<pair<int,int>> vis;
        for(int i=0;i<8;i++){
            int x = xk - xMoves[i];
            int y = yk - yMoves[i];
            //cout << "x = " << x << ", y = " << y << endl;
            if(vis.find({x, y}) != vis.end()){
                //cout << "this was visited" << endl;
                continue;
            }
            for(int i=0;i<8;i++){
                int nx = x + xMoves[i];
                int ny = y + yMoves[i];
                if(nx == xq && ny == yq){
                    //cout << "nx = " << nx << ", ny = " << ny << endl;
                    //cout << "xq = " << xq << ", yq = " << yq << endl;
                    cnt++;
                    break;
                }
            }
            vis.insert({x, y});
            //cout << "------------------------" << endl;
        }
        cout << cnt << endl;
    }
    return 0;
}

