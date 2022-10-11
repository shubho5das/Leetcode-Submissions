class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int i,n;
        n = names.size();
        
        vector<pair<int,string>> V; // {height,name}
        for(i=0 ; i<n ; i++){
            V.push_back({heights[i],names[i]});
        }
        
        sort(V.begin(),V.end());
        reverse(V.begin(),V.end());
                
        vector<string> solution(n);
        for(i=0 ; i<n ; i++){
            solution[i] = V[i].second;
        }
        
        return solution;
    }
};