class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int i,n,cnt,ab_cnt,ba_cnt,len;
        n = words.size();
        
        map<string,int> freq; // {word,cnt}
        for(i=0 ; i<n ; i++){
            freq[words[i]]++;
        }
        
        bool aa_form_oddOccurence_present = false;
        len = 0;
        for(auto x : freq){
            string currentWord = x.first;            
            if(currentWord[0] == currentWord[1]){
                // aa form
                cnt = x.second;
                if(cnt%2 == 0){
                    len += 2*(2*cnt);        //  extra 2* for double counting
                }
                else{
                    len += 2*(2*(cnt - 1));  
                    aa_form_oddOccurence_present = true;
                }
            }
            else{
                // ab form                
                string pairedWord;
                pairedWord += currentWord[1];
                pairedWord += currentWord[0];
                
                if(freq.find(pairedWord) != freq.end()){
                    // Paired word (ba) is present
                    ab_cnt = freq[currentWord];
                    ba_cnt = freq[pairedWord];
                    /*      Let, ab_cnt = 2 
                                 ba_cnt = 3.
                             
                            Then, mn = 2
                        
                            Thus Palindrome: ba-ba- - - - - - ab-ab
                        
                            len += (2*mn) + (2*mn)   // 4 + 4
                         ie,len += 4*mn                                                 
                    */
                    len += 4*(min(ab_cnt,ba_cnt)); 
                }                                                                
            }
            
        }        
        len /= 2;       // Counted both ab-ba pairs and ba-ab pairs
        
        if(aa_form_oddOccurence_present){
            len += 2;
        }
        
        return len;
    }
};