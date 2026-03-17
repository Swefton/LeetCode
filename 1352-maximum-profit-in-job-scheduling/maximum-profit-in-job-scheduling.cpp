class Solution {
    public:
        int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
            struct Job {
                int start, end, profit;
            };

            int n = startTime.size();

            vector<Job> jobs(n);
            for (int i = 0; i < n; ++i) {
                jobs[i] = {startTime[i], endTime[i], profit[i]};
            }

            sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b){
                return a.end < b.end;
            });

            vector<int> bestScores(n + 1, 0);

            for (int i = 1; i <= n; ++i) {
               int prevIdx = upper_bound(jobs.begin(), jobs.begin() + i - 1, jobs[i-1].start, [](int val, const Job& j) { return val < j.end; }) - jobs.begin(); 

                bestScores[i] = max(bestScores[i-1], jobs[i-1].profit + bestScores[prevIdx]); 
            }

            return bestScores.back();
        }
};