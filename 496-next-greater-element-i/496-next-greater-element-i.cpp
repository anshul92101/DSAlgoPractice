class Solution {
public:
    void print(vector<int> v){
        
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        
    }
    
    vector<int> solve(vector<int> &nums1, vector<int> &nums2, stack<int> s){
        
        vector<int> ans;
        for(int i=nums2.size()-1;i>=0;i--){
            if(s.empty()) ans.push_back(-1); 
            else{
                if(s.top()>nums2[i]) ans.push_back(s.top());
                else{

                    while(!s.empty() && s.top()<=nums2[i]) s.pop();
                    
                    if(s.empty()) ans.push_back(-1);
                    else ans.push_back(s.top());
                    
                }
            }
            s.push(nums2[i]);
        }
    
       reverse(ans.begin(), ans.end());
        //print(ans);
        return ans;
        
    }
    
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        
        unordered_map<int, int> mp;
        int n1 = nums1.size();
        stack<int> s;
        vector<int> ans;        
        vector<int> aux = solve(nums1,nums2,s);
       // print(aux);
        
        for(int i=0; i<nums2.size();i++){
            mp[nums2[i]] = i;           
        }
        
        for(int i=0;i<n1;i++){
            int index = mp[nums1[i]];
            ans.push_back(aux[index]);
        }
        
        return ans;
        
    }
};