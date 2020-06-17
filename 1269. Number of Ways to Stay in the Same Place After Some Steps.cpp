#define m 1000000007
class Solution {
public:
    int numWays(int k, int l) {
        l = min(l,k+1);
        int dp[k+2][l+2];
        memset(dp , 0 ,sizeof dp);
        dp[0][0] =1;
    for(int  st =1;st  <= k ; st ++ )
    {
        for(int  val = 0 ; val < l;val ++)
        {
            if (val ==0 ) 
            dp[st][val] =   (dp[st-1][ val ]%m +dp[st-1][val +1 ]%m)%m ;   
            else if(val == l-1)
            dp[st][val] =  (dp[st-1][ val-1 ]%m +dp[st-1][val ]%m)%m ;   
            else         
            dp[st][val] =((dp[st-1][val+1]%m +dp[st-1][ val-1 ]%m)%m +dp[st-1][val ]%m)%m ;   

            }
    }
    return dp[k][0];
    }
    
};
