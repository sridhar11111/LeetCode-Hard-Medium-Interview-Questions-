class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n=a.size();
        if(n<3) return 0;
            int dp[n]={0};
        if(n<3) return 0;
        else{
      
            if(2*a[1]==a[0]+a[2]) dp[2]=1;
            for(int i=3;i<n;i++)
            {
                if(2*a[i-1]==a[i-2]+a[i]) dp[i]=dp[i-1]+1;
                else dp[i]=0;
            }
        }
    
        
        int ans=0;
        for(auto k:dp) ans+=k;
       return ans; 
    }
};
