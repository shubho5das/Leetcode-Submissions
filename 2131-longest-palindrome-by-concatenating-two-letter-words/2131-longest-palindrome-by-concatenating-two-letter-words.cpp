class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> map;
        for(auto word : words){
            map[word] ++;
        }
        int ans = 0;
        for(int i=0; i<words.size(); i++) {
            string str = words[i];
            if(map[str] <= 0){
                continue;
            }
            map[str] --;
            string str_rev = str;
            reverse(str_rev.begin(), str_rev.end());
            if(map.find(str_rev) != map.end() and map[str_rev] > 0){
                //cout<<str<<" ";
                ans +=4;
                map[str_rev] --;
            }
            else{
                map[str] ++;
            }
        }
        for(int i=0; i<words.size(); i++) {
            string str = words[i];
            if(map[str] > 0) {
                if(str[0] == str[1]) {
                    ans += 2;
                    break;
                }
            }
        }
        return ans;
    }
};