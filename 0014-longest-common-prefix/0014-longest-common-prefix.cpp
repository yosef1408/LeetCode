class Solution {
    
    /*
    floDDDwer
    flDDDw
    fligDDDht
    
    prefixes = { f , fl }
    
    (1): one possible solution , to find all prefixes . each time we land in prefix we increase the counter; and at the end we iterate over all the prefixes we found and return the longest common prefix;
    
    time complexity , lets assume the longest string have m letters and the array have n strings, ==> O(m*n)
    space complexity , unordered_map which include all prefixes O(m*m) , we can optimze it;
    
    
    void countPrefix(unordered_map<string,int>&prefixes,string word){
        
        string pref = "";
        
        for(int i = 0 ; i < word.size();i++){
            pref += word[i];
            prefixes[pref]++;
        }
    }
    
    main(){
    not perfect but accepted solution:
    
            unordered_map<string,int> prefixes;
        
        for(auto word: strs)
            countPrefix(prefixes,word);
        
        string longestPrefix = "";
        int commonPrefix = -1;
        
        for(auto [key, value] : prefixes)
            if(value == strs.size())
                if(key.size() > longestPrefix.size() )
                    longestPrefix = key;
        
        return longestPrefix;
    }
        
        
    lets try solve it using space complexity O(1);
    
    lets take a look again : 
    
    floDDDwer
    flDDDw
    fligDDDht
    
    the max prefix is str[0] , from here while moving at the array the prefix may be smaller and smaller;
    
    prefix: floDDDwer
    (iterator 1) fl <--- prefix ,
    Psudo code:
    
    if(strs.size() == 0)
        return "";
    
    string prefix = str[0];
    
    for(int i = 0 ; i < strs.size();i++)
    
        //pop_back unused chars from prefix, at the end of the loop |prefix| == |strs[i]|
        //then
        for(int j = 0 <min(prefix.size(),strs[i].size()))
            str[i][j] == prefix[j]? true: continue,
            else prefix[j].pop_back;
            
        
    
    
    
    
        
        
        
    */
    
    

    
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() == 0)
            return "";
        
        string prefix = strs[0];
        int n = strs.size();
        
        
        for(int i = 1 ; i <n ; i++){

            
            if(strs[i].size() < prefix.size())
            {
                int pref_size =  prefix.size();
                for(int j = strs[i].size() ; j < pref_size;j++)
                    prefix.pop_back();
            }

            
            int n_min =  min(prefix.size(),strs[i].size());
            
            for(int j = 0 ; j <n_min;j++)
                if(strs[i][j] == prefix[j])
                    continue;
                else{
                    while(j < n_min)
                    {
                        prefix.pop_back();
                        j++;
                    }
                }    
        }
        return prefix;

    }
};