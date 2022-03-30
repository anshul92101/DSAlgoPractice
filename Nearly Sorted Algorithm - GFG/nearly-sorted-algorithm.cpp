#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printVector(vector<int> nums){
    
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    
}

vector<int> sort(vector<int> &nums, int k){
    
    int N= nums.size();
    priority_queue<int,vector<int>, greater<int>> minH;
    vector<int> solution;
    
    for(int i=0;i<N;i++){
        minH.push(nums[i]);
        if(minH.size()>k && !minH.empty()){
            solution.push_back(minH.top());
            minH.pop();
        }
    }
    while(!minH.empty()){
        solution.push_back(minH.top());
        minH.pop();
    }
    return solution;

    
}


int main() {
    
    int T ,N, K;
    cin>>T;
    while(T--){
        
        cin>>N; 
        cin>>K;
        vector<int> nums;
        for(int i=0;i<N;i++){
            int num;
            cin>>num;
            nums.push_back(num);
        }
        vector<int> solution = sort(nums,K);
        printVector(solution);
    }
    
	//code
	return 0;
}