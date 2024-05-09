class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : happiness) {
            if (minHeap.size() < k) {
                minHeap.push(num);
            } else {
                if (num > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(num);
                }
            }
        }

        stack<int> reversed;
        while (!minHeap.empty()){
            reversed.push(minHeap.top());
            minHeap.pop();
        }

        int count = 0;
        long long result = 0;

        while (!reversed.empty()){
            result += reversed.top() - (count++);
            reversed.pop();
            if (reversed.empty() || (reversed.top() - count) <= 0) break; 
        }

        return result;

        
        
    }
};