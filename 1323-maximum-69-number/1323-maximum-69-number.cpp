class Solution {
public:
    int maximum69Number (int num) {
        int idx,i,n,ans;
        
        // 1
        string str = to_string(num);
        n = str.length();
        
        idx = -1; 
        bool sixPresent = false;
        for(i=0 ; i<n ; i++){
            if(str[i] == '6'){
                idx = i;
                sixPresent = true;
                break;                    
            }
        }
        
        if(sixPresent){
            str[idx] = '9';
        }
        
        // 2
        ans = stoi(str);
        return ans;        
    }
};