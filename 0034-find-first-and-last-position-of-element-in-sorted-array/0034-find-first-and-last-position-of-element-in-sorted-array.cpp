class Solution {
private:
   int lower_bound(vector<int>& nums , int low , int high , int target) {
    while(low <= high) {
        int mid = (low + high) / 2;
        
        if(nums[mid] < target) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    return low;
   }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0 , high = n - 1;

        int Starting = lower_bound(nums , low , high , target);
        int ending = lower_bound(nums , low , high , target + 1) - 1;

        if(Starting < n && nums[Starting] == target) {
            return {Starting , ending};
        }

        return {-1 , -1};
        
    }
};