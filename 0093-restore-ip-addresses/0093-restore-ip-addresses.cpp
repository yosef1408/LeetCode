class Solution {



    bool isValid(string s, int start,int end){

        string substr = s.substr(start,end-start+1);
        
        if(substr[0] == '0' && substr.size() > 1)
            return false; //Leading Zero

        int num;
        try{
            num  = stoi(substr);
        }catch(...){
            return false;
        }

        return num >= 0 && num <=255;
    }

    void backtrack(string s,vector<string>& res,int start,vector<int>cuts){


        if(start >= s.size())
            return;

        if(cuts.size() == 3){
            if(isValid(s,cuts[2]+1,s.size()-1)){

                string str1 = s.substr(0,cuts[0]+1), str2= s.substr(cuts[0]+1, cuts[1]-cuts[0]),
                str3 = s.substr(cuts[1]+1,cuts[2] - cuts[1]),str4 = s.substr((cuts[2] + 1));

                res.push_back(str1+"."+str2+"."+str3+"."+str4);
                return;
            }
        }

        for(int i = start; i < s.size(); i++)
        {
            if(isValid(s,start,i)){
                cuts.push_back(i);
                backtrack(s,res,(i+1),cuts);
                cuts.pop_back();
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> res;
        vector<int> cuts;

        if(s.size() < 4 || s.size() > 12)
            return {};
        
        backtrack(s,res,0,cuts);

        return res;   
    }
};