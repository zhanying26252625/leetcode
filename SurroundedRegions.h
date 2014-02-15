/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region .

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

class Solution {
public:

    void solve(vector<vector<char>> &board) {
        
        if(board.size()<3||board[0].size()<3){
            return;
        }
        
        solve2(board);
    }
    
     void solve2(vector<vector<char>> &board)
    {
        if (board.empty()) return;
        int M = board.size();
        int N = board[0].size();

        for (int i = 0; i < M; i++)
        {
            if (board[i][0] == 'O') bfs(board, M, N, i, 0);
            if (board[i][N-1] == 'O') bfs(board, M, N, i, N-1);
        }

        for (int j = 1; j < N-1; j++)
        {
            if (board[0][j] == 'O') bfs(board, M, N, 0, j);
            if (board[M-1][j] == 'O') bfs(board, M, N, M-1, j);
        }
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'D') board[i][j] = 'O';
    }

    void bfs(vector<vector<char>> &board, int M, int N, int i, int j)
    {
        queue<pair<int, int>> queue;
        board[i][j] = 'D';
        queue.push(make_pair(i, j));
        
        while (!queue.empty())
        {
            i = queue.front().first;
            j = queue.front().second;
            queue.pop();
            if (i > 1 && board[i-1][j] == 'O')
            {
                board[i-1][j] = 'D';
                queue.push(make_pair(i-1, j));
            }
            if (i < M-1 && board[i+1][j] == 'O')
            {
                board[i+1][j] = 'D';
                queue.push(make_pair(i+1, j));
            }
            if (j > 1 && board[i][j-1] == 'O')
            {
                board[i][j-1] = 'D';
                queue.push(make_pair(i, j-1));
            }
            if (j < N-1 && board[i][j+1] == 'O')
            {
                board[i][j+1] = 'D';
                queue.push(make_pair(i, j+1));
            }
        }
    }
	
	/*
	    void solve(vector<vector<char>> &board) {
        
        if(board.size()<3||board[0].size()<3)
            return;
        
        for(int i = 0 ; i < board[0].size(); ++i){
            if(board[0][i]=='O') dfs(board,0,i);
            if(board[board.size()-1][i]=='O') dfs(board,board.size()-1,i);    
        }
        
        for(int i = 0 ; i < board.size(); ++i){
            if(board[i][0]=='O') dfs(board,i,0);
            if(board[i][board[0].size()-1]=='O') dfs(board,i,board[0].size()-1);    
        }
        
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j]=='B') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
        return;
    }
    
    void dfs(vector<vector<char>> &board, int i, int j){
        
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||board[i][j]!='O')
            return;
        
        board[i][j]='B'; //mark it as border
        dfs(board,i-1,j);
        dfs(board,i+1,j);
        dfs(board,i,j-1);
        dfs(board,i,j+1);
    }
	*/
};