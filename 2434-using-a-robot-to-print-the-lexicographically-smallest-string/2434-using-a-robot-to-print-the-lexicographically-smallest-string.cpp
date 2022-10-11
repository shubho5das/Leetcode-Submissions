class Solution {
public:
    string robotWithString(string S) {
        int n,i,j,minIndexTillNow,smallestIndex;
        n = S.length();
        
        // 1
        vector<int> smallest(n);
        
        char smallestChar = S[n-1];
        smallest[n-1] = (n-1);
        minIndexTillNow = (n-1);
        
        for(i=(n-2) ; i>=0 ; i--){
            if(S[i] <= smallestChar){
                smallestChar = S[i];
                minIndexTillNow = i;
            }
            
            smallest[i] = minIndexTillNow;                        
        }
        
        // 2
        vector<char> T;
        string paper;                
        // 2.1                             
        for(i=0 ; i<n ; ){                
            // Special Case
            if(T.empty()){
                T.push_back(S[i]);
                i++;
                continue;
            }
                        
            smallestIndex = smallest[i];            
            if(S[smallestIndex] < T.back()){
                while(i <= smallestIndex){
                    T.push_back(S[i]);
                    i++;
                }
            }
            
            char ch = T.back();
            
            T.pop_back();
            paper += ch;
        }
        // 2.2
        while(T.size() >= 1){
            char ch = T.back();
            T.pop_back();                    
            paper += ch;
        }   
                
        return paper;
    }
};