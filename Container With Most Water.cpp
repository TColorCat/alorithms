class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }
        return water;
        
        
    }
};
/*
  很容易想到，作为容量的两个因素，底边j-i，以及边沿，ai或者aj，两者是相乘关系
  所以先把一个因素设置成最大，然后逐渐缩小，这样边沿必须增大才能增大容量
  以此为根据，筛选出需要进行比较的两组边
  
  这道题，一个容器的容量受底面的长度与最低的边沿决定
可以先从一个因素开始分析
在这里寻找最低处的边沿是不可取的，所以从可以控制从低到高的顺序的底面长度开始
 
即为最大为n-1
 
在缩小底边长度的过程中，又选择边沿从低到高
 
因为是相乘关系，所以一边下降，另一个因素必须升高，否则容量肯定会变小。以此为根据
*/
