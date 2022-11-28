# LarryNY's Code
        
class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        losses = collections.Counter()

        for winner, loser in matches:
            losses[loser] += 1
            losses[winner] += 0

        ans = [[], []]
        for player in sorted(losses.keys()):
            if losses[player] == 0:
                ans[0].append(player)
            elif losses[player] == 1:
                ans[1].append(player)
        return ans        