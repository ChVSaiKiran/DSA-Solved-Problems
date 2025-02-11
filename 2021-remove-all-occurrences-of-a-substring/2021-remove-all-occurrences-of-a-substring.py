class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        n = len(part)
        idx = s.find(part)
        while idx != -1:
            s = s[:idx] + s[idx + n:]
            idx = s.find(part)
        return s