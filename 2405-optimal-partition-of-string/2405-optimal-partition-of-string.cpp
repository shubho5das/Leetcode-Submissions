class Solution {
public:
    int partitionString(string S) {
        int n,i,cnt;
        n = S.length();
                
        unordered_set<char> visited;
        cnt = 1;
        for(i=0 ; i<n ; i++){
            if(visited.find(S[i]) != visited.end()){
                // Already visited
                visited.clear();
                cnt++; // new partition
            }
            
            visited.insert(S[i]);
        }
        
        return cnt;        
    }
};