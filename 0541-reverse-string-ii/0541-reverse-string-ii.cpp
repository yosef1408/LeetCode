class Solution {
    
    void revese(string& s,int start, int k){
        int n = s.size();
        int end = min(k+start-1,n-1);

        for(int i = 0 ; i < (end - start + 1) / 2; i++)
        {
            //Swap
            int tmp = s[i+start];
            s[i + start] = s[(end-i)];
            s[end-i] = tmp;
        }
    }
public:
    string reverseStr(string s, int k) {
        
        
        int start = 0 ;
        
        while(start < s.size())
        {
            revese(s,start,k);
            start += 2*k;
        }
        
        return s;
        
    }
};