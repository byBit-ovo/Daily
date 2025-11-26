class Solution:
    def rotate(self, m: List[List[int]]) -> None:
        scale = len(m)
        top = 0
        left = 0
        bottom = scale - 1
        right = scale - 1
        while left < right and top < bottom:
            for i in range(0,right - left):
                m[top][top+i], m[top+i][right] = m[top+i][right],m[top][top+i]
                m[top][top+i], m[bottom][right-i] = m[bottom][right-i],m[top][top+i]
                m[top][top+i], m[bottom-i][left] = m[bottom-i][left],m[top][top+i]
            top += 1
            left += 1
            right -= 1
            bottom -= 1


        
