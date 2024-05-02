class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int result = -1;
        map<int, int> pos;
        map<int, int> neg;

        for (int i : nums){
            if(i > 0){
                i = abs(i);
                pos[i] = 1;
                if(neg.find(i) != neg.end() && i > result) result = i;
            }
            else if(i < 0){
                i = abs(i);
                neg[i] = 1;
                if(pos.find(i) != pos.end() && i > result) result = i;
            }
        }
        return result;        
    }
};