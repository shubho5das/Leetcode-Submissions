# LarryNY's Code
# Will solve by myself - after the current internship work is over
class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []

        for x in path.split("/"):
            if x == "":
                continue
            elif x == ".":
                continue
            elif x == "..":
                if len(stack) > 0:
                    stack.pop()
            else:
                stack.append(x)

        return "/" + "/".join(stack)