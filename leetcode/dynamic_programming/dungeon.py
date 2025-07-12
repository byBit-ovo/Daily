class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        m , n = len(dungeon) , len(dungeon[0])
        cache = [ [-1] * n for _ in range(m) ]
        def dp(x: int,y: int,dungeon) -> int:
            m , n = len(dungeon) , len(dungeon[0])
            if x >= m or y >= n : return 1000*400
            if x == m-1 and y == n-1:
                if dungeon[x][y] < 0 :return 1-dungeon[x][y]
                else : return 1
            if cache[x][y] != -1: return cache[x][y]
            opt = min(dp(x+1,y,dungeon) , dp(x,y+1,dungeon))
            res = 0
            if dungeon[x][y] >= opt : res = 1
            else: res = opt - dungeon[x][y]
            cache[x][y]=res
            return res
        return dp(0,0,dungeon)
          
