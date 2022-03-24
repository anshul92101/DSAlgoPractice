class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int petrolTank = 0;
        int curr = 0;
        int start=0, diff, N = gas.size();
        
        for(int i=0;i<N;i++){
            
            diff = gas[i]- cost[i];
            petrolTank+= diff;
            curr+= diff;
            
            if(curr<0){
                start = i+1;
                curr = 0;
            }
            
        }
        
        if(petrolTank>=0) return start;
        return -1;
        
        
    }
};