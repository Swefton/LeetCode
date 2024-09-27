class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    vector<pair<int, int>> overlaps;
    vector<pair<int, int>> bookings;
    
    bool book(int start, int end) {
        for (auto [s, e] : overlaps) {
            if (max(s, start) < min(e, end)) {
                return false;
            }
        }
        
        for (auto [s, e] : bookings) {
            if (max(s, start) < min(e, end)) {
                overlaps.push_back({max(s, start), min(e, end)});
            }
        }
        
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
