//https://www.interviewbit.com/problems/dungeon-princess/

int Solution::calculateMinimumHP(vector<vector<int> > & dungeon)
    {
        if(dungeon.empty() || dungeon[0].empty()) return 1;
        
        int r = dungeon.size(), c = dungeon[0].size();
        
        vector<int> row(c + 1, INT_MAX);
        
        row[c - 1] = 1;
        
        for(int i = r - 1; i >= 0; --i)
            for(int j = c - 1; j >= 0; --j)
                row[j] = max(min(row[j + 1], row[j]) - dungeon[i][j] , 1);
        
        return row[0];
    }
