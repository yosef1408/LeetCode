class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        queue<pair<int,int>> cpus; //[ (#CPU UNIT LEFT, #NextAvaliable Time)]
        priority_queue<int> maxHeap;
        unordered_map<char,int> countMap;
        int timer = 0;

        //Step1: Count Frequency;
        for(int i = 0 ; i < tasks.size() ; i++)
            countMap[tasks[i]]++;
        
        //Step2: Building the MAXHEAP;
        for( const auto& [_,value] : countMap)
            maxHeap.push(value);
        
        while( (!maxHeap.empty()) || (!cpus.empty())){
            timer++;

            if(cpus.empty() == false && cpus.front().second == timer){
                    maxHeap.push(cpus.front().first);
                    cpus.pop();
                }

            while(maxHeap.empty()== false){
                int maxVal = maxHeap.top() -1 ;
                maxHeap.pop();
                if(maxVal != 0 ) 
                    cpus.push({maxVal,timer+1+n});
                timer++;
                if(cpus.empty() == false && cpus.front().second == timer){
                    maxHeap.push(cpus.front().first);
                    cpus.pop();
                }

            }

        }

        return timer-1;

        
    }
};