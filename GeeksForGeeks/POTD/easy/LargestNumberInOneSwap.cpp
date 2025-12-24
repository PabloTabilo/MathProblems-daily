class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        priority_queue<pair<char, int>> pq;
        int n = s.length();
        for(int i=0;i<n;i++){
            pq.push({s[i], i});
        }
        int idx1 = -1;
        int idx2 = -1;
        for(int i=0;i<n;i++){
            while(!pq.empty() && pq.top().second <= i){
                pq.pop();
            }
            if(!pq.empty() && pq.top().first > s[i]){
                idx1 = i;
                idx2 = pq.top().second;
                break;
            }
        }
        
        if(idx1 != -1){
            swap(s[idx1], s[idx2]);
        }
        
        return s;
        
    }
};
