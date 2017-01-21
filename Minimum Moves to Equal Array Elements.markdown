#Minimum Moves to Equal Array Elements I
>
Question:
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

>Input: [1,2,3]

>Output: 3

>Explanation:
>Only three moves are needed (remember each move increments two elements):
>[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

##common idea
  In order to fulfill the purpose, we need to do the increments in all but the maximum element of the array.
  the brute force approach is scanning the array to find maximum element, and adding 1 to all elements except the maximum, then 
  repeat the same process.
  
  Futher, we know in order to make the min equal to max, it should add 1at least k times.{k=max-min}
  Thus,we first find the max and min element,then increment k elements and add k to the moves counts, then repeat. 
  
  the brute force's time complexity is surely O(N2) ;
                    space complexity is O(1);
                              
  it is not good.
###solution 1：Using sorting
  It is effective to sort the array first to find the max and min elements.
  And we do not need to sort the array at every repeat.
  Every time we add min element such as a[0] at first loop to equal to the max element a[n-1], 
  then a[n-2] adding k=a[n-1]-a[0],become the max element, a[1] the min element. 
  Thus,counts=∑(a[i]−a[0]).
  
  Time complexity: O(nlgn) because sorting using O(nlg(n))time
###solution 2:DP
  In short, assume that all element except a[n-1] are equalized, needed counts is kn=a[n-1]-a[n-2]
  But in order to build that situation, we need form a array of n-1 size with all element equalized except a[n-2],k=a[n-2]-a[n-3]...
  that's a loop.
  
  So, the codes is 
  <pre><code>
        int moves = 0;
        for (int i = 1; i < nums.length; i++) {
            int diff = (moves + nums[i]) - nums[i - 1];
            nums[i] += moves;
            moves += diff;
       }</code></pre> 
      

Time complexity : O(nlogn). Sorting's time 

Space complexity : O(1). Only single extra variable is used.

###Math solutions /new thought 
  This solution is based on the idea that adding 1 to all the elements except one is equivalent to decrementing 1 from a single element.
  We can easily find the number of moves required is sum(array)-n*min.
  
  /A little caution: if sum(array) is very large thus leading to overflow, it is suggested to use ∑(a[i]−min).
  Time complexity: O(n) to find min
  Space complexity: O(1)
