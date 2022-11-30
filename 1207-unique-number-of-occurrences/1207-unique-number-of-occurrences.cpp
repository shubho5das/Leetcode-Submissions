class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int i,n,cnt;
        n = arr.size();
        
        // 1
        unordered_map<int,int> freq;
        for(i=0 ; i<n ; i++){
            freq[arr[i]]++;
        }
        
        // 2
        unordered_set<int> visited;
        for(auto x : freq){
            cnt = x.second;
            
            if(visited.find(cnt) != visited.end()){
                return false;
            }
            visited.insert(cnt);            
        }
        
        return true;
    }
};