#pragma once
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <list>
#include <time.h>
#include <unordered_map>
#include <map>
#include <iostream>
#define WALL L'□'
#define FOOD L'★'
#define BODY L'●'
#define Key_Press(vk) (GetAsyncKeyState(vk)&1)
#define POS_X 30
#define POS_Y 10
using namespace std;
void SetPos(int x, int y);
typedef enum direction {
	UP,DOWN,LEFT,RIGHT
}direction;
typedef enum status {
	OK,KILL_BY_SELF,KILL_BY_WALL,END_NORMAL
}status;
struct snake_node {
	snake_node(int x, int y) :_x(x), _y(y){}
	int _x = 0;
	int _y = 0;
	snake_node* _next = nullptr;
};
class snake {
private:
	typedef snake_node _node;
public:
	void show_snake() {
		for (const auto& e : _head) {
			SetPos(e._x, e._y);
			wprintf(L"%lc", BODY);
		}
	}
	pair<int,int> _food;
	list<_node> _head;
	int _food_weight = 10;
	int _sleep_time = 120;
	direction _direct = RIGHT;
	status _sta = OK;
	int _score = 0;
	void show_score();
	snake() {
		_food.first = 30; _food.second = 23;
		for (int i = 0; i < 5; ++i) {
			_head.push_back({POS_X - 2 * i, POS_Y});
		}
	}
};

void GameStart(snake& _snake);
void GameRun(snake& _snake);
void GameOver(snake& _snake);
void Hide_cur();
void Welcome();
void Creat_map();
void Kill_by_wall(snake& _snake,int x,int y);
void Kill_by_self(snake& _snake,int x,int y);