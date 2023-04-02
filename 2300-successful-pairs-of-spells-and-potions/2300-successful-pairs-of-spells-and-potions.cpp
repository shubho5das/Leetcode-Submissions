class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        long long i,j,n,m,cnt,totalStrength;
        n = spells.size();
        m = potions.size();
        
        vector<pair<int,int>> V;
        for(i=0 ; i<n ; i++){
            V.push_back({spells[i],i});
        }
                
        sort(V.begin(),V.end());
        sort(potions.begin(),potions.end());
        
        vector<int> solution(n);
        j = 0;
        for(i=(n-1) ; i>=0 ; i--){
            while(j<m && (1LL * V[i].first * potions[j]) < success){
                j++;
            }
            
            cnt = (m - j);
            solution[V[i].second] = cnt;
        }
        
        return solution;        
    }
};