class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        int size = people.size();
        map<int,int> number_map;
        
        for (int i : people) {
            if (number_map.find(i) == number_map.end()) number_map[i] = 1;
            else number_map[i]++;
        }
        
        while (size > 0){
            int first = number_map.begin()->first;
            int capacity = limit - first;
            if (--number_map[first] == 0) number_map.erase(first); 
            --size;
            ++count;
            
            if (capacity == 0) continue;
           
            auto it = number_map.upper_bound(capacity);
            if (it != number_map.begin()) {
                --it;
                --size;

                if (--(it->second) == 0) number_map.erase(it);
            }



        }
        
        return count;  
    }
};