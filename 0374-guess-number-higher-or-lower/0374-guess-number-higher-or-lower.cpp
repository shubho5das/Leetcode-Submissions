/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:            
    int guessNumber(int n) {
        int s,e,mid,ans,guessOutcome;
        
        s = 1, e = n;
        while(s <= e){
            mid = s + (e-s)/2;
            guessOutcome = guess(mid);
            
            if(guessOutcome == 0){
                ans = mid;
                break;
            }
            
            if(guessOutcome){
                s = (mid + 1);
            }
            else{
                e = (mid - 1);
            }                                        
        }
        
        return ans;                
    }
};