#define inf 1000000000

class Solution {
public:
    vector<string> restoreIpAddresses(string S) {
        int i,j,k,l,n,val1,val2,val3,val4;
        n = S.length();
        
        vector<string> solution;
        for(i=1 ; i<n ; i++){
            for(j=(i+1) ; j<n ; j++){
                for(k=(j+1) ; k<n ; k++){
                    vector<string> octet(4);
                    octet[0] = S.substr(0,i);
                    octet[1] = S.substr(i,(j - i));
                    octet[2] = S.substr(j,(k - j));
                    octet[3] = S.substr(k,(n - k));
                    
                    bool leadingZeroPresent = false;
                    for(l=0 ; l<4 ; l++){
                        if(octet[l].length() >= 2 && octet[l][0] == '0'){
                            leadingZeroPresent = true;
                            break;
                        }
                    }
                    
                    val1 = (octet[0].length() <= 3)? stoi(octet[0]) : inf;
                    val2 = (octet[1].length() <= 3)? stoi(octet[1]) : inf;
                    val3 = (octet[2].length() <= 3)? stoi(octet[2]) : inf;
                    val4 = (octet[3].length() <= 3)? stoi(octet[3]) : inf;
                    if(!leadingZeroPresent && val1 <= 255 && val2 <= 255 && val3 <= 255 && val4 <= 255){
                        string current;
                        current += octet[0];
                        current += ".";
                        current += octet[1];
                        current += ".";
                        current += octet[2];
                        current += ".";
                        current += octet[3];
                        
                        solution.push_back(current);
                    }                                            
                }
            }
        }
        
        return solution;            
    }
};