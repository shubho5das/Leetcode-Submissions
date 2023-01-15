class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int i,j,k,Q,r1,r2,c1,c2;
        Q = queries.size();
        
        vector<vector<int>> cumSum(n,vector<int>(n+1,0));
        for(k=0 ; k<Q ; k++){
            r1 = queries[k][0], r2 = queries[k][2];
            c1 = queries[k][1], c2 = queries[k][3];
            
            for(i=r1 ; i<=r2 ; i++){
                cumSum[i][c1] += 1;
                cumSum[i][c2 + 1] -= 1;
            }
        }
        
        for(i=0 ; i<n ; i++){
            for(j=1 ; j<=n ; j++){
                cumSum[i][j] = (cumSum[i][j] + cumSum[i][j-1]);
            }
        }
        
        vector<vector<int>> solution(n,vector<int>(n,0));
        for(i=0 ; i<n ; i++){
            for(j=0 ; j<n ; j++){
                solution[i][j] = cumSum[i][j];
            }
        }
        
        return solution;
        
    }
};