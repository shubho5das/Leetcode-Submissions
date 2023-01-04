#define inf 1000000007

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int i,n,target,currentCnt,totalCnt,a,b;
        n = tasks.size();
        
        unordered_map<int,int> freq;
        for(i=0 ; i<n ; i++){
            freq[tasks[i]]++;
        }
        
        // 2
        totalCnt = 0;
        for(auto x : freq){
            target = x.second;
            if(target == 1){
                return -1;
            }
            
            currentCnt = inf;
            if(target%2 == 1){   
                // Target is odd
                
                // Case 1: 3a
                if(target%3 == 0){
                    a = target/3;
                    if(a >= 0){
                        currentCnt = min(currentCnt,a);
                    }
                }                
                // Case 2: 3a + 2b
                a = target/3;
                if((3*a) % 2 == 0){
                    a--;
                }
                b = (target - 3*a)/2;
                if(a >= 0 && b >= 0){
                    currentCnt = min(currentCnt,(a + b));
                }                                
            }
            else{
                // Target is even
                
                // Case 1: 3a
                if(target%3 == 0){
                    a = target/3;
                    if(a >= 0){
                        currentCnt = min(currentCnt,a);                        
                    }                    
                }                
                // Case 2: 3a + 2b
                a = target/3;
                if((3*a) % 2 == 1){
                    a--;
                }
                b = (target - 3*a)/2;
                if(a >= 0 && b >= 0){
                    currentCnt = min(currentCnt,(a + b));
                }                                
                                
                // Case 3: 2a                
                if(target%2 == 0){
                    a = target/2;
                    if(a >= 0){
                        currentCnt = min(currentCnt,a);                        
                    }                    
                }                                                
            }
            
            totalCnt += currentCnt;
        }
        
        
        return totalCnt;
    }
};