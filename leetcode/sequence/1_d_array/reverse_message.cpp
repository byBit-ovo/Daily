class Solution {
public:
    string reverseMessage(string message) {
        int len = message.size()-1;
        int j = len,i=len;
        string res;
        while(j>=0)
        {
            while(j>=0 && message[j]==' ')
            {
                --j;
            }
            if(j<0){
                break;
            }
            i = j;
            while(i>=0 && message[i]!=' ')
            {
                --i;
            }
            string word = message.substr(i+1,j-i);
            if(!res.empty())
            {
                res+=' ';
            }
            res += word;
            j=i;
        }
        return res;
    }

};
