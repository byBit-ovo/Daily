#include <iostream>
#include <limits.h>
#include <optional>
#include <queue>
#include <unordered_map>

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& visited,
	int x, int y) {
	int n = grid.size(), m = grid[0].size();
    if(x < 0 || x >= n || y < 0 || y >= m || visited[x][y]) {
		return -1;
	}
	if(grid[x][y] == 1) {
		return 0;
	}
	visited[x][y] = true;
	int res = -1;
	for(int k = 0;k < 4;k++) {
		int nx = x + dx[k], ny = y + dy[k];
		res = std::max(res, dfs(grid, visited, nx, ny));
	}
	visited[x][y] = false;
	return res + 1;
}
// 1 0 0 
// 1 0 1 
// 1 0 0 
// 0 1 0 

class st {
public:
	static st& get(){
		static st s;
		return s;
	}
private:
	st() = default;
	st(const st& s) = delete;
	st& operator=(const st& s) = delete;
};



int main() {
	st& a = st::get();
	st& b = st::get();
    return 0;
}