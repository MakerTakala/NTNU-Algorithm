#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int cur_l_block = 1;

void one_black(vector<vector<int>> &puzzle, pair<int, int> black, pair<int, int> lu_pos, int size) {
    if(size == 1) return;
    size /= 2;
    int mid_x = lu_pos.x + size, mid_y = lu_pos.y + size;

    if(black.x >= mid_x || black.y >= mid_y) {
        puzzle[mid_x - 1][mid_y - 1] = cur_l_block;
    }
    if(black.x < mid_x || black.y >= mid_y) {
        puzzle[mid_x][mid_y - 1] = cur_l_block;
    }
    if(black.x >= mid_x || black.y < mid_y) {
        puzzle[mid_x - 1][mid_y] = cur_l_block;
    }
    if(black.x < mid_x || black.y < mid_y) {
        puzzle[mid_x][mid_y] = cur_l_block;
    }
    cur_l_block++;

    one_black(puzzle, black.x >= mid_x || black.y >= mid_y ? make_pair(mid_x - 1, mid_y - 1) : black, {lu_pos.x, lu_pos.y}, size);
    one_black(puzzle, black.x < mid_x || black.y >= mid_y ? make_pair(mid_x, mid_y - 1) : black, {mid_x, lu_pos.y}, size);
    one_black(puzzle, black.x >= mid_x || black.y < mid_y ? make_pair(mid_x - 1, mid_y) : black, {lu_pos.x, mid_y}, size);
    one_black(puzzle, black.x < mid_x || black.y < mid_y ? make_pair(mid_x, mid_y) : black, {mid_x, mid_y}, size);
}

void solver(vector<vector<int>> &puzzle, vector<pair<int, int>> blacks, pair<int, int> lu_pos, int size) {
    if(blacks.size() == 1) {
        one_black(puzzle, blacks.front(), lu_pos, size);
        return;
    }

    vector<pair<int, int>> lu_blacks, ru_blacks, lb_blacks, rb_blacks;
    size /= 2;
    int mid_x = lu_pos.x + size, mid_y = lu_pos.y + size;
    for(auto black : blacks) {
        if(black.x < mid_x && black.y < mid_y) {
            lu_blacks.push_back(black);
        }
        else if(black.x >= mid_x && black.y < mid_y) {
            ru_blacks.push_back(black);
        }
        else if(black.x < mid_x && black.y >= mid_y) {
            lb_blacks.push_back(black);
        }
        else if(black.x >= mid_x && black.y >= mid_y) {
            rb_blacks.push_back(black);
        }
    }
    solver(puzzle, lu_blacks, {lu_pos.x, lu_pos.y}, size);
    solver(puzzle, ru_blacks, {mid_x, lu_pos.y}, size);
    solver(puzzle, lb_blacks, {lu_pos.x, mid_y}, size); 
    solver(puzzle, rb_blacks, {mid_x, mid_y}, size);
}


int main() {
    int n, l;
    cin>>n>>l;

    vector<vector<int>> puzzle(l, vector<int>(l, 0));
    vector<pair<int, int>> blacks(n);

    for(int i = 0, x, y; i < n; i++) {
        cin>>blacks[i].x>>blacks[i].y;
    }

    solver(puzzle, blacks, {0, 0}, l);

    for(auto y : puzzle) {
        for(auto x : y) {
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}