

#include <map>
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <ios>
#include <map>
#include <unordered_map>

using namespace std;

static auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

template <typename T>
void printArray(std::vector<T> values)
{
    std::cout << "[";
    for (int i = 0; i < values.size(); i++)
    {
        std::cout << values[i];
        if (values.size() - 1 > i)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

// NOTE we could use a lamda expression

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    if (search(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }

private:
    bool search(vector<vector<char>> &board, string word, int x, int y, int idx)
    {
        if (word.size() == idx)
            return true;

        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[idx])
            return false;

        char tmp = board[x][y];
        board[x][y] = '#';

        bool found = search(board, word, x + 1, y, idx + 1) |
                     search(board, word, x - 1, y, idx + 1) |
                     search(board, word, x, y + 1, idx + 1) |
                     search(board, word, x, y - 1, idx + 1);

        board[x][y] = tmp;

        return found;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<std::vector<char>> board1 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};

    std::vector<std::vector<char>> board2 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};

    std::vector<std::vector<char>> board3 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    Solution sol;

    cout << "T1: " << (sol.exist(board1, "ABCCED") ? "true" : "false") << endl;
    cout << "T2: " << (sol.exist(board2, "SEE") ? "true" : "false") << endl;
    cout << "T3: " << (sol.exist(board3, "ABCB") ? "true" : "false") << endl;

    return 0;
}

// retired solution doesn't really work:

// if (word.size() == 0) return true;
// // check up:
// if (y > 0 && path.find(std::make_pair(x, y-1)) == path.end() && board[x][y-1] == word[0]) {
//     path.insert(std::make_pair(x, y));
//     if (search(board, word.substr(1), x, y-1, path)) {
//         return true;
//     } else {
//         path.erase(std::make_pair(x, y));
//     }
// }
// // check down:
// if (y < board.size()-1 && path.find(std::make_pair(x, y+1)) == path.end() && board[x][y+1] == word[0]) {
//     path.insert(std::make_pair(x, y));
//     if (search(board, word.substr(1), x, y+1, path)) {
//         return true;
//     } else {
//         path.erase(std::make_pair(x, y));
//     }
// }
// // check left:
// if (x > 0 && path.find(std::make_pair(x-1, y)) == path.end() && board[x-1][y] == word[0]) {
//     path.insert(std::make_pair(x, y));
//     if (search(board, word.substr(1), x-1, y, path)) {
//         return true;
//     } else {
//         path.erase(std::make_pair(x, y));
//     }
// }
// // check right:
// if (x < board.size()-1 && path.find(std::make_pair(x+1, y)) == path.end() && board[x+1][y] == word[0]) {
//     path.insert(std::make_pair(x, y));
//     if (search(board, word.substr(1), x+1, y, path)) {
//         return true;
//     } else {
//         path.erase(std::make_pair(x, y));
//     }
// }
// return false;
