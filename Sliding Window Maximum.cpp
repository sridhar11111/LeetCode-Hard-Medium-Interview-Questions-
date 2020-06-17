#define pb(c) push_back(c) 
class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
  
        
        for(int i=0;i<n;i++)
        {
         int z = nums[i];
            while(d.size() && nums[d.back()]<=z) { d.pop_back(); }
            d.pb(i);
          while(d.size() && d.front()<=i-k ) { d.pop_front(); }  
       if(i >= k-1) ans.pb(nums[d.front()]);
        
        }
    
    return ans;
    }
};
