class Solution:
    def orderlyQueue(self, s: str, k: int) -> str:
        if k==1:
            mins = s
            for i in range(len(s)):
                if s<mins:
                    mins=s
                s = s[1:]+s[0]
            return mins
        else:
            return "".join(sorted(s))