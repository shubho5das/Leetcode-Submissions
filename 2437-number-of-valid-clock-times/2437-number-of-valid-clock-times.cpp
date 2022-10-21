class Solution {
public:
    int countTime(string time) {
        int i,current,minWays,hrWays,ans,digit,targetNum;
                
        // hr ways
        string currentStr = time.substr(0,2); // '0?'
        // cout<<currentStr<<"\n";
        
        hrWays = 0;
        for(i=0 ; i<=23 ; i++){
            targetNum = i;
            string targetStr;
            int cnt = 2;
            while(cnt--){
                digit = targetNum%10;
                char c = (char)((int)('0') + digit);
                targetStr += c;
                targetNum /= 10;
            }
            reverse(targetStr.begin(),targetStr.end());
            // cout<<targetStr<<"\n";
            
            
            if ( (currentStr[0] == '?' || (currentStr[0] == targetStr[0])) && (currentStr[1] == '?' || (currentStr[1] == targetStr[1])) ){
                hrWays++;
            }
        }        
        
        // min Ways
        currentStr = time.substr(3,2); // '0?'
        // cout<<currentStr<<"\n";
        
        minWays = 0;
        for(i=0 ; i<=59 ; i++){
            targetNum = i;
            string targetStr;
            int cnt = 2;
            while(cnt--){
                digit = targetNum%10;
                char c = (char)((int)('0') + digit);
                targetStr += c;
                targetNum /= 10;
            }
            reverse(targetStr.begin(),targetStr.end());
            
            
            if ( (currentStr[0] == '?' || (currentStr[0] == targetStr[0])) && (currentStr[1] == '?' || (currentStr[1] == targetStr[1])) ){
                minWays++;
            }
        }        
        
        // cout<<minWays<<" "<<hrWays<<"\n";        
        ans = (minWays * hrWays);
        return ans;
    }
};