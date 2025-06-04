#include "snake.h"
void snake::show_score() {
	SetPos(80, 8);
	printf("Author: xunyi");
	SetPos(80, 11);
	printf("F3加速，F4减速");
	SetPos(80, 13);
	printf("空格暂停，ESC退出");
	SetPos(80, 15);
	printf("当前分数：%d", _score);
	SetPos(80, 16);
	printf("每个食物得分：%-2d", _food_weight);
	SetPos(80, 20);
	printf("速度越快，得分越高哦");
}
void Hide_cur() {
	HANDLE han = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO _info;
	GetConsoleCursorInfo(han, &_info);
	_info.bVisible = false;
	SetConsoleCursorInfo(han, &_info);
}
void SetPos(int x, int y) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x,y };
	SetConsoleCursorPosition(handle, pos);
}
void Creat_map()
{
	SetPos(0, 0);
	for (int i = 0; i < 40;++i)
		wprintf(L"%lc", WALL);
	for (int i = 1; i < 30; ++i) {
		SetPos(0,i);
		wprintf(L"%lc", WALL);
	}
	SetPos(2, 29);
	for (int i = 1; i < 40; ++i) {
		wprintf(L"%lc", WALL);
	}
	for (int i = 1; i <= 28; ++i) {
		SetPos(78, i);
		wprintf(L"%lc", WALL);
	}


}

void Welcome() {
	SetPos(32, 10);
	printf("欢迎来到贪吃蛇小游戏");
	SetPos(33, 20);
	system("pause");
	system("cls");
	SetPos(15, 10);
	printf("↑  ↓  ←  →分别控制蛇的移动,F3为加速,F4为减速\n");
	SetPos(25, 15);
	printf("加速将获得更高的分数！");
	SetPos(25, 20);
	system("pause");
	system("cls");
}

void GameStart(snake& _snake) {
	setlocale(LC_ALL, "");
	system("title 贪吃蛇");
	system("mode con cols=100 lines=30");
	Hide_cur();
	Welcome();
	Creat_map();
	_snake.show_score();
}
void pause() {
	while (1) {
		Sleep(100);
		if (Key_Press(VK_SPACE)) {
			break;
		}
	}
}
bool next_is_food(snake& _snake, int x, int y) {
	return _snake._food.first == x && _snake._food.second == y;
}
bool is_body(snake& _snake, int x,int y) {
	for (const auto& e : _snake._head) {
		if (e._x == x && e._y == y) {
			return true;
		}
	}
	return false;
}
void creat_food(snake& _snake) {
	srand((unsigned int)time(nullptr));
	int x = rand() % 75 + 2;
	int y = rand() % 28 + 1;
	while (is_body(_snake, x, y) || x&1) {
		x = rand() % 75 + 2;
		y = rand() % 28 + 1;
	}
	_snake._food.first = x;
	_snake._food.second = y;
	SetPos(x, y);
	wprintf(L"%lc", FOOD);
}
void not_eat(snake& _snake) {
	auto tail = _snake._head.back();
	int x = tail._x;
	int y = tail._y;
	SetPos(x, y);
	printf("  ");
	_snake._head.pop_back();
}
void Kill_by_wall(snake& _snake,int x,int y) {
	if (x >= 78 || x < 2 || y >= 29 || y <= 0) {
		_snake._sta = KILL_BY_WALL;
	}
}
void Kill_by_self(snake& _snake,int x,int y) {
	auto iter = _snake._head.begin();
	++iter;
	while (iter != _snake._head.end()) {
		if (iter->_x == x && iter->_y == y) {
			_snake._sta = KILL_BY_SELF;
			break;
		}
		++iter;
	}
}
void snake_walk(snake& _snake) {
	int next_x, next_y;
	auto snake_head = _snake._head.begin();
	switch (_snake._direct) {
	case UP:
		next_x = snake_head->_x;
		next_y = snake_head->_y - 1;
		break;
	case DOWN :
		next_x = snake_head->_x;
		next_y = snake_head->_y + 1;
		break;
	case LEFT:
		next_x = snake_head->_x - 2;
		next_y = snake_head->_y;
		break;
	case RIGHT:
		next_x = snake_head->_x + 2;
		next_y = snake_head->_y;
		break;
	}

	if (next_is_food(_snake,next_x,next_y)) {
		_snake._head.push_front({ next_x,next_y });
		_snake.show_snake();
		_snake._score += _snake._food_weight;
		creat_food(_snake);
	}
	else{
		_snake._head.push_front({ next_x,next_y });
		not_eat(_snake);
		_snake.show_snake();
	}
	Kill_by_wall(_snake,next_x,next_y);
	Kill_by_self(_snake,next_x,next_y);
}
void show_snake_start(snake& _snake) {
	SetPos(30, 23);
	wprintf(L"%lc", FOOD);
	for (int i = 0; i < 5; ++i) {
		SetPos(POS_X - 2 * i, POS_Y);
		wprintf(L"%lc", BODY);
	}
}
void GameRun(snake& _snake) {
	show_snake_start(_snake);
	while (_snake._sta == OK) {
        _snake.show_score();
		if (Key_Press(VK_UP) && _snake._direct != DOWN) {
			_snake._direct = UP;
		}
		else if (Key_Press(VK_DOWN) && _snake._direct != UP) {
			_snake._direct = DOWN;

		}
		else if (Key_Press(VK_LEFT) && _snake._direct != RIGHT) {
			_snake._direct = LEFT;

		}
		else if (Key_Press(VK_RIGHT) && _snake._direct != LEFT) {
			_snake._direct = RIGHT;

		}
		else if (Key_Press(VK_ESCAPE)) {
			_snake._sta = END_NORMAL;
			break;
		}
		else if (Key_Press(VK_SPACE)) {
			pause();
		}
		else if (Key_Press(VK_F3)) {
			if (_snake._sleep_time >= 45) {
				_snake._sleep_time -= 15;
				_snake._food_weight += 1;
			}

		}
		else if (Key_Press(VK_F4)) {
			if (_snake._sleep_time < 200) {
				_snake._sleep_time += 15;
				_snake._food_weight -= 1;
			}

		}
		else {
			Sleep(_snake._sleep_time);
			snake_walk(_snake);
		}

	}
}
void GameOver(snake& _snake) {
	system("cls");
	SetPos(15, 50);
	if (_snake._sta == END_NORMAL) {
		cout << "bye-bye";
	}
	if (_snake._sta == KILL_BY_WALL) {
		SetPos(15, 50);

		cout << "哥们儿，撞到墙了！" << endl;
		cout << "to play again:y  to quit: q" << endl;
	}
	else if (_snake._sta == KILL_BY_SELF) {
		SetPos(15, 50);
		cout << "哥们儿，咬到自己了！" << endl;
		cout << "to play again:y  to quit: q" << endl;
	}

}
