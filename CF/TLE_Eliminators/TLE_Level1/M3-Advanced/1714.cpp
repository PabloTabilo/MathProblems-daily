#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
	int n, H, M;
	cin >> n >> H >> M;
	int h, m;
	int bestH, bestM;
	int hours, mins;
	int best = 100000;
	int ans;
	for(int i=0;i<n;i++){
	    cin >> h >> m;
	    if(H == h && M == m){
		hours = 0;
		mins = 0;
	    }
	    // must do a loop
	    else if(H > h || (H == h && M > m)){
		mins = (60 - M) % 60;
		if(M != 0){
		    hours = (24 - (H+1)) % 24;
		}else{
		    hours = (24 - H) % 24;
		}
		hours += h;
		mins += m;
		if(mins >= 60){
		    int hoursDiff = mins / 60;
		    hours += hoursDiff;
		    mins -= (60 * hoursDiff);
		}
	    }else if(H == h && m > M){
		hours = 0;
		mins = m - M;
	    }else{
		mins = (60 - M) % 60;
		if(M != 0){
		    hours = h - (H+1);
		}else{
		    hours = h - H;
		}
		mins += m;
		if(mins >= 60){
		    int hoursDiff = mins / 60;
		    hours += hoursDiff;
		    mins -= (60 * hoursDiff);
		}
	    }
	    //cout << "hours = " << hours << ", mins = " << mins << endl;
	    ans = hours*60 + mins;
	    if(best > ans){
		bestH = hours;
		bestM = mins;
		best = ans;
	    }
	}
	//cout << "bestH bestM:";
	cout << bestH << " " << bestM << endl;

    }

    return 0;
}

