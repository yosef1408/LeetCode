class Solution {
    
    char complement(char ch){
        
        if(ch == '(')   return ')';
        if(ch == '[') return ']';
        return '}';
    }
        
public:
    bool isValid(string s) {
        
        vector<char> stack;

        for(int i = 0 ; i < s.size();i++){
            
            if((s[i] == ')' || s[i] == ']' || s[i] == '}')&& stack.empty())
                return false;
        
            
            if(s[i] == '('|| s[i] == '[' || s[i] == '{')
                stack.push_back(s[i]);
            else
                if(complement(stack.back()) == s[i])
                    stack.pop_back();
                else
                    return false;
        }
        
        return stack.empty();
        
    }
};