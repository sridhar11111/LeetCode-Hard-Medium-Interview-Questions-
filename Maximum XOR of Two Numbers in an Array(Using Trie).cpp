class Solution {
public:
    struct node{
        struct node*left;//1
        struct node*right;//0
    };
    struct node *getnode()
    {
        struct node *ptr=new node;
        ptr->left=NULL;
        ptr->right=NULL;
        return ptr;
    }
    node *root=getnode();
    
    void insert(int z)
    {
        node *curr= root;
          int k=32; 
        int zz=z;
        while(k--){
         z=zz;
         int b=(z>>k)&1;
         if(b==1)
         {
            if(curr->left==NULL) curr->left=getnode();
            curr=curr->left;
          }
        else
        {
            if(!curr->right) curr->right=getnode();
            curr=curr->right;
        }
            
        //z/=2;
        }
        
    }
    
    int maxxor(int z)
    { 
     int i=32,ans=0;
     node *curr= root;
        int zz=z,k=32;
     while(k--)
     {   z=zz;
         int b=(z>>k)&1;
         if(b==1)//go to 0right
         {
             if(curr->right!=NULL) { ans+=(1<<k); curr=curr->right;}
             else curr=curr->left;
         }
         else{
             if(curr->left!=NULL) {ans+=(1<<k);curr=curr->left;}
         else curr=curr->right;
         }
         
      //   z/=2;
         i--;
     }
     return ans;   
    }
    
    int findMaximumXOR(vector<int>& nums) {
  for(auto i:nums) insert(i);
    int mx=INT_MIN;
        for(auto i:nums) mx=max(mx,maxxor(i));
    return mx;
    }
};
