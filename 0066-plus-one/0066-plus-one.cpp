class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size() - 1 ;

        for(;n>=0;n--){

            digits[n] += 1;
            if(digits[n] <10)
                return digits;
            else{
                digits[n] %=10;
            }
        }
        vector<int> res = {1};
        res.insert(res.end(),digits.begin(),digits.end());

        return res;
        
    }
};