/*
  Votrubac's Solution.
  
  My Solution: https://pastebin.com/xwuCR61M
    Binary-search based approach. Made use of multiset to determine maxTime value
    Time: O(logn * n.logn). No idea why it's giving me TLE. Passing 67/82 TCs

*/

class Solution {
public:
    int maximumRobots(vector<int>& times, vector<int>& costs, long long budget) {
        long long i = 0, j = 0;
        multiset<int> ms;
        for (long long cost = 0; i < times.size(); ++i) {
            cost += costs[i];
            ms.insert(times[i]);
            if (cost * (i - j + 1) + *rbegin(ms) > budget) {
                cost -= costs[j];
                ms.erase(ms.find(times[j]));
                ++j;
            }
        }
        return i - j;
    }    
};