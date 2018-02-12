import numpy as np
class Solution:
    def lengthOfLongestSubstring(self, s):
        count = 0
        start = 0
        maxLen = 0
        n = len(s)
        t = np.arange(n)
        t = t * 0
        for i in range(0, n):
            current = s[i]
            if (t[s.find(s[i])] != 1):
                t[s.find(s[i])] = 1
                count = count + 1
            elif (count >= maxLen):
                maxLen = count
                count = 1

                for k in range(start,i):
                    print("running %d"%k)
                    if(s[k]==current):
                        start = k + 1
                        break
                    print("running %d" % k)
        print("start: %d"%start)
        print(n-start)
        return maxLen

Obj = Solution()
x = Obj.lengthOfLongestSubstring("dvdf")
print(x)