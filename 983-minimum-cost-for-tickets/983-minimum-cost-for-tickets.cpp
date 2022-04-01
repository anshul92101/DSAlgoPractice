class Solution {
public:

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        unordered_map<int,bool> isTravelDate;
        int N = days.size();
        int lastDate = days[N-1];
        int price[lastDate+1];
        for(int i=0;i<N;i++){
            isTravelDate[days[i]] = true;
        }
        price[0] = 0;
        
        for(int date=1;date<=lastDate;date++){
            
            price[date] = price[date-1];
            if(isTravelDate[date]) price[date] = min({price[max(0,date-1)] + costs[0],price[max(0,date-7)] + costs[1],price[max(0,date-30)] + costs[2]});
           
            
        }
        
        return price[lastDate];
        
    }
};