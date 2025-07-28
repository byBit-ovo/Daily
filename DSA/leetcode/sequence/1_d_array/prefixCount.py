class Solution:
    def countPrefixes(self, words: list[str], s: str) -> int:
        count = 0
        for word in words:
            if s.startswith(word):
                count+=1
        return count


hash = {}
hash[0] = hash.get(0,0) + 1
print(hash)