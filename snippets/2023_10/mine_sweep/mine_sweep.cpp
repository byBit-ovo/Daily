#include "mine_sweep.h"
void Mine::put_mines() {
    srand(time(0));
    int size = s_map.size();
    int count = size;
    while (count) {
        int x = rand() % size;
        int y = rand() % size;
        if (m_map[x][y] == 'e') {
            m_map[x][y] = 'm';
            --count;
        }
    }
}
Mine::Mine(int size)
{
    counts_of_empty = size * (size - 1);
    m_map.resize(size+2,vector<char>(size+2,'e'));
    s_map.resize(size, vector<char>(size, '*'));
    mine_pos.reserve(size + 2);
    for (int i = 0; i < size+2; ++i)
    {
        m_map[i].reserve(size+2);
    }
    //处理边缘
    for(int i=0;i<size+2;i+=size+1){
        for(int j=0;j<size+2;++j){
            m_map[i][j]='d';
        }
    }
    //处理边缘
    for(int i=0;i<size+2;++i){
        m_map[i][0] = 'd';
        m_map[i][size+1] = 'd';
    }
    put_mines();
}
void Mine::show_map(){
    int size = s_map.size();
    cout << "  ";
    for (int i = 0; i < size; ++i) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < size; ++i) {
        cout << i << " ";
        for (int j = 0; j < size; ++j) {
			cout << s_map[i][j] << " ";
		}
		cout << endl;
	}
}
void Mine::show_end() {
    for (int i = 1; i < m_map.size() - 1; ++i) {
        for (int j = 1; j < m_map.size() - 1; ++j) {
            cout << m_map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void Mine::run() {
	while (counts_of_empty > 0) {
		cout << "the pos to search：";
		int x, y;
		cin >> x >> y;

		if (x >= 0 && x < s_map.size() && y >= 0 && y < s_map.size()) {
			if (m_map[x + 1][y + 1] == 'm') {
				cout << "sorry,this is a mine" << endl;
				break;
			}
			else {
				find_mines(x+1, y+1);
				show_map();
			}
		}
        else
        {
            cout << "invalid input" << endl;
        }
	}
    cout << endl;
    show_end();
	if (counts_of_empty == 0) {
		cout << "congratulations! you win the game!" << endl;
	}
}
void Mine::find_mines(int x,int y) {
    //m_map[x][y]='e';
    int count = 0;
	--counts_of_empty;
	for (int i = 0; i < 8; ++i) {
		int m = x + dx[i];
		int n = y + dy[i];
		if (m_map[m][n] == 'm') {
			++count;
		}
	}

    if (count) {
        s_map[x-1][y-1] = count + '0';
        m_map[x][y] = 'f';//empty_found
    }
    else
    {
		s_map[x-1][y-1] = '$';
		m_map[x][y] = 'f';
		for (int i = 0; i < 8; ++i) {
			int m = x + dx[i];
			int n = y + dy[i];
			if (m_map[m][n] == 'e') {
                find_mines(m, n);
			}
		}
	}
}


