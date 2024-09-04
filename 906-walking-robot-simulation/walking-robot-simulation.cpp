class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;
        int x = 0, y = 0;
        int maxDistanceSquared = 0;
        
        set<pair<int, int>> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert({obstacle[0], obstacle[1]});
        }
        
        for (int command : commands) {
            if (command == -1) {
                dir = (dir + 1) % 4;
            } else if (command == -2) {
                dir = (dir + 3) % 4;
            } else {
                for (int i = 0; i < command; ++i) {
                    int nextX = x + directions[dir][0];
                    int nextY = y + directions[dir][1];
                    
                    if (obstacleSet.find({nextX, nextY}) == obstacleSet.end()) {
                        x = nextX;
                        y = nextY;
                        maxDistanceSquared = max(maxDistanceSquared, x * x + y * y);
                    } else {
                        break;
                    }
                }
            }
        }
        
        return maxDistanceSquared;
    }
};
