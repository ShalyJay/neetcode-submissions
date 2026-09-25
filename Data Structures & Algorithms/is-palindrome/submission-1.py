class Solution:
    def isPalindrome(self, s: str) -> bool:

        beg = 0
        end = len(s) - 1

        while(beg < end):
            if s[beg].isalnum() and s[end].isalnum():
                if s[beg].lower() != s[end].lower():
                    return False
                else:
                    beg += 1
                    end -= 1
                    continue
            else:
                if not s[beg].isalnum():
                    beg += 1
                if not s[end].isalnum():
                    end -= 1
        
        return True