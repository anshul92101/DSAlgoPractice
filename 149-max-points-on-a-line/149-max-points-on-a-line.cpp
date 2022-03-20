class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int dx, dy;
        int g;
        int N = points.size();
        int ans=0;
        for(int i=0;i<N;i++){
            unordered_map<string,int> counter;
            for(int j=i+1;j<N;j++){
                
                dx = points[j][0] - points[i][0];
                dy = points[j][1] - points[i][1];
                g = gcd(dx,dy);
                string expr = to_string(dx/g) + "_" + to_string(dy/g);    
                counter[expr]++;
                ans = max(ans,counter[expr]);
            }
            
        }
        return ans+1;
        
    }
    
    int gcd(int a, int b){
        while(b){
            
            a = a%b;
            swap(a,b);
            
        }
        return a;
    }
};