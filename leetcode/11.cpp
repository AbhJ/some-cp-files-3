class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), l = 0, r = n - 1, ans = 0;
        while (l < r){
          int leftHeight = height[l], rightHeight = height[r];
          ans = max(min(leftHeight, rightHeight) * (r - l), ans);
          if(leftHeight < rightHeight)
            l++;
          else
            r--;
        }
        return ans;
    }
};