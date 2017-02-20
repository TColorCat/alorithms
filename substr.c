/*problem
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.*/
//BM算法
//仅仅使用坏字符原则
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
    /*根据模式字符串构造了一张每个字符在模式串中出现的最右位置的表格
      匹配失败后，将会把主串中的相应的字符和其在模式串中出现的最右位置对其
      坏字符原则*/
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
//BK算法 using hash
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int h_size=haystack.size();
        int n_size=needle.size();
        
        if(h_size==0&&n_size==0)return 0;//特殊情况
        
        
        size_t hash_needle=hash<string>{}(needle);
       
        
        
        
        
       bool flag=true;
        for(int i=0;i<=h_size-n_size;i++)
        {
           size_t hash_haysub=hash<string>{}(haystack.substr(i,n_size));
           if(hash_needle==hash_haysub)
           {
               flag=true;
               for(int j=0;j<n_size;j++)
               {
                   if(needle[j]!=haystack[i+j])
                   {
                       flag=false;
                       break;
                   }
               }
               if(flag)
                return i;
                
           }
           
        }
        return -1;//没有匹配
    }

};
