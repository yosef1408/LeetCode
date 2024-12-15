class Solution {
public:
    vector<int> grayCode(int n) {
        
        vector<int> result;
        result.push_back(0);
        int addEle = 1;
        
        while(result.size() < pow(2.0,n)){
            
            for(int i = result.size() -  1; i >=0 ;i--){
                result.push_back((addEle+result[i]));
            }
            addEle *=2;
        }
        return result;
        
    }
};