class Solution {
public:
    #define md 1000000007
    int sumSubarrayMins(vector<int>& A) {
        int n= A.size();
    vector<int>a(n+2,-1);
    // 0  =-1  1 - > n  n+1 =-1 
        for(int i=1;i<=n;i++) a[i] = A[i-1];
        vector<int>l(n+2,-1);
        vector<int>r(n+2,-1);
    stack<pair<int,int>>s;
        s.push({a[1],1});
        for(int i=2;i<=n;i++){
        while(s.size() && a[i]<= (s.top()).first ) {
            auto k = s.top();
            l[k.second] = i;
            s.pop();}
            s.push({a[i],i});
        }
        while(!s.empty()) { l[(s.top()).second] = n+1;s.pop(); }
        
        
        stack<pair<int,int>>s2;
        s2.push({a[n],n});
        for(int i=n-1;i>=1;i--){
        while(s2.size() && a[i]< (s2.top()).first ) {
            auto k = s2.top();
            r[k.second] = i;
            s2.pop();}
            s2.push({a[i],i});
        }
        while(!s2.empty()) { r[(s2.top()).second] = 0; s2.pop();}
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans = (ans +  ( (abs(l[i]-i) * abs(r[i]-i))%md * a[i])%md)%md ;
                ans%md; 
        }
        
        
        
        for(int i=0;i<n+2;i++ ) cout<<l[i]<<' ';cout<<endl;
         for(int i=0;i<n+2;i++ ) cout<<r[i]<<' ';
        
    return ans%md;    
    }
};
