class Solution {
public:
    string largestPalindromic(string num) {
        int n,i,j;
        n = num.size();
        
        int freq[10] = {0};
        for(i=0 ; i<n ; i++){
            freq[num[i] - '0']++;
        }
        
        int evenFreq[10] = {0};
        int oddFreq[10] = {0};
        for(i=0 ; i<10 ; i++){
            if(freq[i]%2 == 0){
                evenFreq[i] = freq[i];
                oddFreq[i] = 0;
            }
            else{
                evenFreq[i] = (freq[i] - 1);
                oddFreq[i] = 1;
            }
        }
        
        string current;
        char middleChar;
        bool oddOccurence = false;
        for(i=0 ; i<=9 ; i++){
            for(j=0 ; j<evenFreq[i]/2 ; j++){
                current += (char)(i + (int)('0'));
            }
            
            if(oddFreq[i] == 1){
                middleChar = (char)(i + (int)('0'));
                oddOccurence = true;
            }
        }
        
        reverse(current.begin(),current.end());
        if(current[0] == '0'){
            current = "";
        }        
        //cout<<current<<"\n";
        
        // 2
        string solution;
        // 2.1
        solution += current;
        // 2.2
        if(oddOccurence){
            solution += middleChar;
        }        
        // 2.3
        reverse(current.begin(),current.end());
        solution += current;
        
        if(solution.size() >= 1){
            return solution;            
        }
        else{
            return "0";
        }

    }
};