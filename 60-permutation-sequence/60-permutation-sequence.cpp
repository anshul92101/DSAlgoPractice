class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int fact = 1;
        for(int i=1;i<n;i++){
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string solution = "";
        k = k-1;
        while(true){
            int block_number = k/fact;
            solution += numbers[block_number] + '0';
            numbers.erase(numbers.begin() + block_number);
            if(numbers.size()==0) break;
            k = k%fact;
            fact = fact/numbers.size();
        }
        return solution;
        
    }
};