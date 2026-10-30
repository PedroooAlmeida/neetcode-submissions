class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // for each row, check each column 

       for (int i = 0; i < board.size(); i++) {

            unordered_map<char, bool> seenCols;

            for (int j = 0; j < board.size(); j++){
                
                if ((board[i][j] == '.')){
                    continue; 
                } else {

                    if (seenCols[board[i][j]] == true){

                        return false; 

                    }

                    seenCols[board[i][j]] = true; 
                }
            }

        }

        // for each column, check each row 

        for (int i = 0; i < board.size(); i++) {

            unordered_map<char, bool> seenRows;

            for (int j = 0; j < board.size(); j++){
                
                if ((board[j][i] == '.')){
                    continue; 
                } else {

                    if (seenRows[board[j][i]] == true){

                        return false; 

                    }

                    seenRows[board[j][i]] = true; 
                }
            }

        }

        // check 3x3
        
        vector<unordered_map<char, bool>> seenGrids(9);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int grid = (i / 3) * 3 + (j / 3);
                if (seenGrids[grid][board[i][j]] == true) {
                    return false;
                }
                seenGrids[grid][board[i][j]] = true;
            }
        }


        return true; 

    }
};