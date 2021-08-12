class Solution {
public:
    int longestDecomposition(string text) {
        int ans = 0;
        int n = text.size();
        int i=0, j=n-1;
        int last = n;
        while(i<j)
        {
            if(text[i]==text[j])
            {
                bool ansb = true;
                
                for(int k=j+1; k<last; k++)
                {
                    if(text[k]!=text[k-j+i])
                    {
                        ansb = false;
                        break;
                    }
                }
                
                if(ansb)
                {
                    if(i!=j) ans+=2;
                 
                    else ans+=1;
                   
                    i+=last-j;
                    
                    last = j;
                    
                    j--;
                }
                else j--;
                
            }
            else j--;   
        }
        
        if(i==j) ans++;
       
        return ans;
    }
};