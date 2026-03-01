class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        ranges::sort(processorTime, greater<int>());
        ranges::sort(tasks);

        int maxTime{0};

        for (size_t i = 0; i < processorTime.size(); ++i) {
            auto currTasks = tasks | std::views::drop(i*4) | std::views::take(4);
            maxTime = std::max(maxTime, processorTime[i] + tasks[i*4 + 3]);
        }

        
        return maxTime;
    }
};