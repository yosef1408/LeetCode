class Solution {
    
    void backtrack(vector<vector<string>>& syn,vector<string>& comb ,string text, unordered_map<string,int> &seen){
        
        string word = "";
        for(int i = 0 ; i < text.size() ;i++)
        {
            if(text[i] == ' ')
            {
                for(int j = 0; j < syn.size() ; j++){
                    if(syn[j][0] == word )
                    {
                        string combination = text.substr(0,(i-word.size())) + syn[j][1] + text.substr(i);
                        combination.pop_back();
                        if(seen[combination] == 0){
                            comb.push_back(combination);
                            seen[combination]++;
                            combination = combination +' ';
                            backtrack(syn,comb,combination,seen);
                        }

                    }else if (syn[j][1] == word )
                    {
                        string combination = text.substr(0,(i-word.size())) + syn[j][0] + text.substr(i);
                        combination.pop_back();

                        if(seen[combination] == 0){
                            comb.push_back(combination);
                            seen[combination]++;
                            combination = combination +' ';
                            backtrack(syn,comb,combination,seen);
                        }

                    }
                }
                word = "";
            }
            else
                word += text[i];
            
        }

    }
    
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        
        unordered_map<string,int> seen;
        vector<string> res;
        res.push_back(text);
        seen[text] = 1;

        text = text + ' ';
                
        backtrack(synonyms, res,text,seen);
        sort(res.begin(),res.end());
        
        return res;
        
        
        
        
    }
};