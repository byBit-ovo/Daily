#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Mine{
private:
	vector<vector<char>> m_map;
	vector<vector<char>> s_map;
	vector<pair<int, int>> mine_pos;
	int counts_of_empty;
	int dx[8] = { -1,-1,-1,0, 0,1,1, 1 };
	int dy[8] = { 1, 0,-1,1,-1,1,0,-1 };
public:
	Mine(int size = 11);
	void show_map();
	void put_mines();
	void find_mines(int x, int y);
    void run();
	void show_end();
};