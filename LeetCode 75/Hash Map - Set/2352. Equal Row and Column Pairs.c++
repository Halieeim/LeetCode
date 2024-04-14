class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<string, int> table_row;
        map<string, int> table_col;
        int counter = 0;
        // rows
        for(int i = 0; i < grid.size(); i++){
            string s = "";
            for(int j = 0; j < grid[0].size(); j++){
                s += to_string(grid[i][j]) + " ";
            }
            cout << s << endl;
            auto it = table_row.find(s);
            if(it != table_row.end()){
                table_row[s] += 1;
            }
            else table_row[s] = 1;
        }
        cout << "==================" << endl;
        // columns
        for(int i = 0; i < grid[0].size(); i++){
            string s = "";
            for(int j = 0; j < grid.size(); j++){
                s += to_string(grid[j][i]) + " ";
            }
            cout << s << endl;
            auto it = table_col.find(s);
            if(it != table_col.end()){
                table_col[s] += 1;
            }
            else table_col[s] = 1;
        }
        cout << "================" << endl;

        for(auto it = table_row.begin(); it != table_row.end(); it++){
            cout << it->second << endl;
            auto ptr = table_col.find(it->first);
            if(ptr != table_col.end()){
                counter += (it->second * table_col[it->first]);
            }
        }
        return counter;
    }
};