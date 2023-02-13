class Solution {
public:    
    vector<vector<int>> substringXorQueries(string S, vector<vector<int>>& queries) {
        int n,i,j,Q,l,r,decimalValue,len,val;
        n = S.length();
        
        // 1
        unordered_map<int,vector<int>> M; // {val:{minLength,l,r}}
        for(i=0 ; i<n ; i++){
            if(S[i] == '1'){
                decimalValue = 0, len = 0;
                for(j=i ; j<min(i+30,n) ; j++){
                    decimalValue <<= 1;
                    if(S[j] == '1'){
                        decimalValue += 1;                        
                    } 
                    len++;
                    
                    if(M.find(decimalValue) != M.end()){
                        if(len < M[decimalValue][0]){
                            M[decimalValue] = {len,i,j};
                        }
                    }
                    else{
                        M[decimalValue] = {len,i,j};
                    }                                        
                }
            }
            else{
                decimalValue = 0, len = 1;
                if(M.find(decimalValue) == M.end()){
                    M[decimalValue] = {len,i,i};
                }                
            }
        }
        
        // 2
        vector<vector<int>> solution;
        Q = queries.size();
        
        for(i=0 ; i<Q ; i++){
            val = (queries[i][0] ^ queries[i][1]);
            
            if(M.find(val) != M.end()){
                solution.push_back({M[val][1], M[val][2]});
            }
            else{
                solution.push_back({-1, -1});
            }
        }
        
        return solution;        
    }
};