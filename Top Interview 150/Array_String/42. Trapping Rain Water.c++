class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0, left = 0, right = height.size()-1, Lmax = 0, Rmax = 0;

        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] >= Lmax){
                    Lmax = height[left];
                }
                else {
                    water += Lmax - height[left];
                    
                }
                left++;
            }
            else{
                if(height[right] >= Rmax){
                    Rmax = height[right];
                }
                else {
                    water += Rmax - height[right];
                    
                }
                right--;
            }
        }
        return water;
    }
};