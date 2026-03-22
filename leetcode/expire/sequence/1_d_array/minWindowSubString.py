class Solution:
    def minWindow(self, s: str, t: str) -> str:
        tCount, window= {},{}
        valid = 0
        for c in t:
            if c in tCount : tCount[c]+=1
            else : tCount[c]=1
        res=""
        i=0
        for j in range(len(s)):
            c = s[j]
            if c in window : window[c]+=1
            else : window[c]=1
            if c in tCount and window[c] == tCount[c] : valid+=1
            while len(tCount)==valid:
                if res=="" :res=s[i:j+1]
                elif j-i+1 < len(res): res = s[i:j+1]
                window[s[i]]-=1
                if s[i] in tCount and window[s[i]] < tCount[s[i]]: valid-=1
                i+=1
        return res



        
