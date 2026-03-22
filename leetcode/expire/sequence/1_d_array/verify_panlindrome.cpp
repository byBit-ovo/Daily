class Solution {
public:
    bool is_alph(char c)
    {
        return (c>='0' &&  c<='9') ||
               (c>='a' && c <='z') ||
               (c>='A' && c<='Z');
    }
    bool isPalindrome(string s) {
        for(auto& e:s)
            if(isupper(e))
                e = tolower(e);
        
        for(int i=0,j=s.size()-1;i<=j;)
        {
            if(!is_alph(s[i]))
            {
                ++i;
                continue;
            }
            if(!is_alph(s[j]))
            {
                --j;
                continue;
            }
            if(s[i] != s[j])
            {
                return false;
            }
            ++i;--j;
        }
        return true;
    }
};