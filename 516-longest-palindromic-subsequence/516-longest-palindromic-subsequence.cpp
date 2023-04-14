// LarryNY's Code
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int N = s.length();

        // inclusive bounds
        // left -> 0 to N
        // right -> 0 to N
        // total number of inputs is O(N^2)
        // each input takes O(1) time
        // total time is O(N^2)
        // O(N^2) space
        vector<vector<bool>> has_cache(N, vector<bool>(N, false));
        vector<vector<int>> cache(N, vector<int>(N, 0));

        function<int(int, int)> getLongest = [&](int left, int right) -> int {
            if (left > right) {
                return 0;
            }
            if (left == right) {
                return 1;
            }
            if (has_cache[left][right]) {
                return cache[left][right];
            }

            int best = 0;
            if (s[left] == s[right]) {
                best = max(best, getLongest(left + 1, right - 1) + 2);
            }
            best = max(best, getLongest(left + 1, right));
            best = max(best, getLongest(left, right - 1));

            has_cache[left][right] = true;
            cache[left][right] = best;
            return best;
        };

        return getLongest(0, N - 1);
    }
};