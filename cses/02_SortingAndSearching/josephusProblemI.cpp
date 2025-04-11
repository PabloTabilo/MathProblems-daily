#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int k = 1;
    int p = log2(n);
    int m = 1 << p;
    if(m < n){
        p++;
        m = 1 << p;
    }
    int base = m;
    m *= 2;
    vector<int> st(m, 0);
    for(int i=0;i<n;i++){
        st[i+base] = 1; 
    }
    for(int i = m - 1; i > 1; i--){
        int parent = i / 2;
        st[parent] += st[i];
    }
    //cout << "p = " << p << endl;
    //cout << "st:"; for(auto x : st) cout << x << " "; cout << endl;
    function<int(int,int,int,int)>get_node = [&](int cnt, int idx, int prev, int h){
        //cout << "cnt = " << cnt << ", idx = " << idx << ", prev = " << prev << ", h = " << h << endl;
        int v;
        if(h >= p){
            st[idx] = 0; 
            v = idx - base + 1;
            return v;
        }
        //cout << "l = st[idx*2] = " << st[idx * 2] << endl;
        int l = st[idx * 2];
        if(cnt <= l){
            //cout << "go to left cnt <= l" << endl;
            v = get_node(cnt, 2*idx, 0, h+1);
        }else{
            //cout << "go to right cnt > l" << endl;
            v = get_node(cnt-l, 2*idx + 1, l, h+1);
        }
        st[idx] = st[idx*2] + st[idx*2 + 1];
        return v;
    }; 

    int sz = n;
    int i = k % sz;
    vector<int> ans;
    while(sz > 0){
        //cout << "i = " << i << endl;
        int v = get_node(i+1, 1, 0, 0);
        //cout << "v = " << v << endl;
        //cout << "st:"; for(auto x : st) cout << x << " "; cout << endl;
        ans.push_back(v);
        sz--;
        if(sz == 0) break;
        i = (i + k) % sz;
        //cout << "-------------------------" << endl;
    }
    //cout << "ans: "; 
    for(auto x : ans){
        cout << x << " ";
    }
    cout << endl; 
    return 0;
}

