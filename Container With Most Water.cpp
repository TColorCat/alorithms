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
*/
