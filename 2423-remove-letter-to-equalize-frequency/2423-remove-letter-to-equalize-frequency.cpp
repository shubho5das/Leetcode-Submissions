#define inf 1000000

class Solution {
public:
    bool equalFrequency(string word) {
        int i,n,countMx,countMn,mn,mx;
        n = word.size();
        
        // 1
        unordered_map<char,int> freq;
        for(i=0 ; i<n ; i++){
            freq[word[i]]++;
        }
        
        // Special Case - all unique
        unordered_set<char> P;
        for(i=0 ; i<n ; i++){
            P.insert(word[i]);
        }
        
        if(P.size() == n){
            return true;
        }
        
        // Special Case: All same
        if(P.size() == 1){
            return true;
        }
        
        
        // 2
        if(freq.size() <= 1){
            return false;
        }
        
        
        mn = inf, mx = -inf;
        for(auto x : freq){
            mn = min(mn,x.second);
            mx = max(mx,x.second);
        }
                                                        
        countMx = 0, countMn = 0;
        for(auto x : freq){
            if(x.second == mn){
                countMn++;
            }
            else if(x.second == mx){
                countMx++;
            }
        }
        int freqSize = freq.size();
        
        
        // Special Case - {1, <all same freq>}        
        if(mn == 1 && countMn == 1 && countMx == (freqSize - 1)){
            return true;
        }
        
        
        
        if( (mx == (mn + 1)) && (countMn == (freqSize - 1)) && (countMx == 1)){
            return true;
        }
        else{
            return false;
        }
    }
};