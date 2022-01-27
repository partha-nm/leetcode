struct TrieNode{
    
    TrieNode* child[2];
};

class Solution {
private:
    TrieNode* root;
public:
    void insert( int n ){
        
        TrieNode* curr = root;
        
        for( int i = 31 ; i>=0 ; i-- ){
             
            if( !(n & 1<<i) ){
                 
                if( !curr->child[0] ) curr->child[0] = new TrieNode();
                
                curr = curr->child[0];
            }
            else{
                
                if( !curr->child[1] ) curr->child[1] = new TrieNode();
                
                curr = curr->child[1];
            }
        }
    }
    
    int getXOR( int n ){
        
        int _xor = 0;
         
        TrieNode* curr = root;
        
        for( int i = 31 ; i>=0 ; i-- ){
             
            if( !( n & 1<<i ) ){
                
                if( curr->child[1] ){
                    
                    curr = curr->child[1];
                    
                    _xor += 1<<i;
                }
                else
                    curr = curr->child[0];
            }
            
            else{
                
                if( curr->child[0] ){
                    
                    curr = curr->child[0];
                    
                    _xor += 1<<i;
                }
                else
                    curr = curr->child[1];
            }
        }
        
        return _xor;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        
        int ans = 0, n = nums.size();   
        
        root = new TrieNode(); 
        
        for( int i=0 ; i<n ; i++ )
            insert( nums[i] );
        
        for( int i=0 ; i<n ; i++ )
           ans = max( ans , getXOR( nums[i] ) ); 
        
        return ans;
    }
};