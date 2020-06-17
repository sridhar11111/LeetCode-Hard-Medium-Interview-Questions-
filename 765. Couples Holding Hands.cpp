class Solution {
public:
    int c= 0;
    int val[201];
    bool vis[201]={0};
    int paiir (int val){if(val&1) return val-1; return val+1; }
    void dfs(int vl,vector<int>&row)
    {   vis[vl]=1;
        c++;
        int val1 = row[2*vl] ,val2= row[2*vl +1];
        if(!vis[ val[paiir(val1)] ]){dfs(val[paiir(val1)],row);}
       if(!vis[ val[paiir(val2)] ] ) {dfs(val[paiir(val2)],row);}
 
    }
    
    int minSwapsCouples(vector<int>& row) {
        int  ans = 0;
        int n=row.size();
        n/=2;
        
        for(int i=0;i<2*n;i++) {val[row[i]] =i/2;}
        for(int i=0;i<n;i++){
            if(!vis[i]) 
            {
                dfs(i,row);ans+= (c-1);
            }
            
            c=0;
        } 
    return ans;
    }
};
