class Solution {
public:
    int romanToInt(string S) {
        int n,i;
        n = S.length();
        
        unordered_map<string,int> specialCases;
        specialCases["IV"] = 4;
        specialCases["IX"] = 9;
        specialCases["XL"] = 40;
        specialCases["XC"] = 90;
        specialCases["CD"] = 400;
        specialCases["CM"] = 900;
        
        
        int ans = 0;
        for(i=0 ; i<n ; ){
            if(i <= (n-2) && specialCases.find(S.substr(i,2)) != specialCases.end() ){
                ans += specialCases[S.substr(i,2)];
                i += 2;
            }
            else{
                if(S[i] == 'I'){
                    ans += 1;
                }
                else if(S[i] == 'V'){
                    ans += 5;
                }
                else if(S[i] == 'X'){
                    ans += 10;
                }
                else if(S[i] == 'L'){
                    ans += 50;
                }
                else if(S[i] == 'C'){
                    ans += 100;
                }
                else if(S[i] == 'D'){
                    ans += 500;
                }
                else if(S[i] == 'M'){
                    ans += 1000;
                }
                    
                i++;
            }            
        }
        
        return ans;
            
    }
};