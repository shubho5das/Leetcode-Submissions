class Solution {
public:
    bool check(int freq1[],int freq2[]){
        int cnt1, cnt2,i;
        
        cnt1 = 0, cnt2 = 0;
        for(i=0 ; i<26 ; i++){
            if(freq1[i] >= 1){
                cnt1++;
            }
            if(freq2[i] >= 1){
                cnt2++;
            }
        }
        
        return (cnt1 == cnt2);
    }
    
    bool isItPossible(string word1, string word2) {
        int n1,n2,i,j;
        n1 = word1.length();
        n2 = word2.length();
        
        int freq1[26] = {0};
        for(i=0 ; i<n1 ; i++){
            freq1[word1[i] - 'a']++;
        }
        
        
        int freq2[26] = {0};
        for(i=0 ; i<n2 ; i++){
            freq2[word2[i] - 'a']++;
        }
        
        // 2
        for(i=0 ; i<26 ; i++){
            for(j=0 ; j<26 ; j++){
                if(freq1[i] >= 1 && freq2[j] >= 1){
                    freq1[i]--, freq1[j]++;
                    freq2[j]--, freq2[i]++;

                    bool isCountDistinctSame = check(freq1,freq2);
                    if(isCountDistinctSame){
                        return true;
                    }

                    freq1[i]++, freq1[j]--;
                    freq2[j]++, freq2[i]--;                                                    
                }
            }
        }
        
        return false;        
    }
};