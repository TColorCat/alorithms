/*problem
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.*/
//BM算法
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int h_size=haystack.size();
        int n_size=needle.size();
        if(h_size==0&&n_size==0)return 0;
        vector<int>right=right_sol(needle);
        
        
        int skip;
        for(int i=0;i<=h_size-n_size;i+=skip)
        {
            skip=0;
            for(int j=n_size-1;j>=0;j--)
            {
                if(needle[j]!=haystack[i+j])
                {
                    skip=j-right[haystack[i+j]];
                    if(skip<1)skip=1;
                    break;
                }
            }
            if(skip==0)return i;
        }
        return -1;
    }
private:
    vector<int> right_sol(const string&needle)
    {
        vector<int>right(256,-1);
        for(int i=0;i<needle.size();i++)
        {
            right[needle[i]]=i;
        }
        
        return right;
    }
};
