class Solution {
public:
    int minimizeXor(int a, int b) {
        long long setbitCnt,i,cnt,x;
        
        // Step 1
        setbitCnt = 0;
        while(b > 0){
            if(b%2 == 1){
                setbitCnt++;
            }
            b /= 2;
        }

        // Step 2        
        vector<int> V(32,0); // 32-bit bitwise representation                 
        vector<int> solution(32,0);
        
        i = 0;
        while(a > 0){
            if(a%2 == 1){
                V[i] = 1;
            }
            
            i++;
            a /= 2;
        }
                
        // 2.1
        cnt = 0;
        vector<bool> visited(32,false);        
        for(i=31 ; i>=0 && cnt < setbitCnt; i--){
            if(V[i] == 1){
                V[i] = 0;
                visited[i] = true;
                solution[i] = 1;
                cnt++;
            }               
        }                                
        // 2.2
        for(i=0 ; i<=31 && cnt < setbitCnt; i++){
            if(V[i] == 0 && !visited[i]){
                V[i] = 1;
                visited[i] = true;
                solution[i] = 1;
                cnt++;                
            }
        }
        
        
        // Determining value of x
        x = 0;
        for(i=0 ; i<=30 ; i++){
            if(solution[i] == 1){
                x += (1<<i);
            }
        }
        
        return x;
    }
};