#include "snake.h"
void test() {
	char ch = 'y';
	do {
		snake _snake;
		GameStart(_snake);
		GameRun(_snake);
		GameOver(_snake);
		cin >> ch;
	} while (ch == 'y');

}
 int main(){
	test();
	return 0;
}