int idx;

class Solution {
public:    
    static bool compare(vector<int> a,vector<int> b){
        return (a[idx] >= b[idx]);
    }
    
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        idx = k;
        sort(score.begin(),score.end(),compare);        
        return score;        
    }
};