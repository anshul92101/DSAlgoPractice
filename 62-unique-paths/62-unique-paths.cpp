class Solution {
public:
    map<pair<int,int>,int> dp;

    int solve(int i, int j){
       
       if(i<0 || j<0) return 0;
       if(i==0 && j==0) return 1;
       if(dp.find({i,j})!=dp.end()) return dp[{i,j}];
       else return dp[{i,j}] = solve(i-1,j) + solve(i,j-1);
    
    }
    
    int uniquePaths(int m, int n) {
        
       int res = solve(m-1,n-1);
       return res;
        
    }
};