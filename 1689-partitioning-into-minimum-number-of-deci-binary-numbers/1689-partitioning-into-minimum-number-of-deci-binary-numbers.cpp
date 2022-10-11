class Solution {
public:
    int minPartitions(string S){
        int n,currentDigit,largestDigit,i;
        n = S.length();
        
        largestDigit = -1;
        for(i=0 ; i<n ; i++){
            currentDigit = (int)(S[i] - '0');
            largestDigit = max(currentDigit,largestDigit);
        }
        
        return largestDigit;                
    }
};