#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int row, int col, vector<vector<int>>& board, int val) {
    for (int i = 0; i < 9; i++) {
        // row
        if (board[row][i] == val) {
            return false;
        }
        // col
        if (board[i][col] == val) {
            return false;
        }
        // 3x3 matrix
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>>&board){
    //col size
int n=board[0].size();
// matrix row and col
for(int row=0;row<n;row++){
    for(int col=0;col<n;col++){
            //checking for empty value
        if(board[row][col]==0){
            // trail and error for all values 1 to 9
            for(int val=1;val<=9;val++){
                // checking if a value can be inserted
                if(isSafe(row,col,board,val)){
                    board[row][col]=val;
                    //recursive call --> checking for next null value
                    bool nextsol=solve(board);
                    // if we get next sol also
                    if(nextsol){
                        return true;
                    }
                    else{
                        //back track -->   if we dont get value we get back old value (0)
                    board[row][col]=0;

                }
                }


            }

        return false;
        }
    }
}
return true;

}
int main() {
    vector<vector<int>> mat = {{3,0,6,5,7,8,0,9,2},
                               {5,2,9,1,3,4,7,6,8},
                               {4,8,0,6,2,9,5,3,1},
                               {2,6,3,4,1,5,9,8,7},
                               {9,7,4,8,6,3,1,2,5},
                               {8,5,1,7,9,2,6,4,3},
                               {1,3,8,9,4,7,2,5,6},
                               {6,9,2,3,5,0,8,7,4},
                               {7,4,5,2,8,6,3,1,9}};

    bool ans = solve(mat);

    if (ans) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
