class Solution {
public:
    int getLucky(string s, int k) {
        string num_str = "";
        
        for (char c : s) {
            int num = c - 'a' + 1;
            num_str += to_string(num);
        }
        
        int sum = 0;
        for (char c : num_str) {
            sum += c - '0';
        }
        
        while (--k > 0) {
            int new_sum = 0;
            while (sum > 0) {
                new_sum += sum % 10;
                sum /= 10;
            }
            sum = new_sum;
        }
        
        return sum;
    }
};
