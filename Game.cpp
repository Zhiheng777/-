#include"Game.h"
int num = 0;
void RunGame() {
	int a[N + 2][N + 2] = {0};  //雷点
	int b[N + 2][N + 2] = {0};  //周围雷数
	int c[N + 2][N + 2] = { 0 };  //已点亮雷  //
	InitGame(a, b, c);
	Show(a);  //测试
	Show(a, b, c);
	cout << "||||||输入1 开始游戏|||||||" ;
	int o;
	int x=-1, y=-1;
	cin >> o;
	cout << "总雷数:" << num<<endl;
	while (o) {
		cout << "请输入点亮位置（-1，-1代表暂不点亮）：" ;
		cin >> x>> y;
		o=Dliang(x,y,a,b,c);
		if (o) {
			cout << "请输入雷点位置（-1，-1代表暂不点雷）：";
			cin >> x>> y;
			o=Dlei(x, y,a,b,c);
		}
		if (num == 0) {
			cout << "          恭喜恭喜   " << endl;
			cout << "          牛皮牛皮" << endl;
			o = false;
		}	
	}
	cout << "游戏结束" << endl;
	Show(a);
}
int InitGame(int a[N + 2][N + 2], int b[N + 2][N + 2], int c[N + 2][N + 2]) {
	srand(time(NULL));
	num = 0;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			a[i][j] = rand() % 7> 3 ? 1 : 0;  //0.25概率有雷 1是有雷
			if (a[i][j] == 1)num++;
	//		cout << a[i][j];
		}
	//	cout << endl;
	}
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {  //雷点也有对应数要考虑
			{
				for (int m = i - 1; m <= i + 1; m++)
					for (int n = j - 1; n <= j + 1; n++)
						if(m!=i||n!=j)b[i][j] += a[m][n];
			}
		//	cout << b[i][j] << "||";
		}
	//	cout << endl;
	}
	return num;
}
void Show(int a[N + 2][N + 2], int b[N + 2][N + 2], int c[N + 2][N + 2]) {
	cout << "   ";
	for (int i = 1; i < N + 1;i++)cout << i<<"  ";
	cout << endl;
	for (int i = 1; i < N + 1; i++)cout << "-----";
	cout << endl;
	int i = 1, j = 1;
	while (i < N + 1) {
		if(i<10)
		cout << i << " |";
		else cout << i << "|";
		for (j=1; j < N + 1; j++) {
			if (c[i][j] == 1)cout << b[i][j] << "  ";
			else if (c[i][j] == -1)cout << "*" << "  ";
			else cout << "   ";
		}
		cout <<endl;
		cout <<"  |"<< endl;
		i++;
	}
}
void Show(int a[N + 2][N + 2]) {
	cout << "   ";
	for (int i = 1; i < N + 1; i++)cout << i << "  ";
	cout << endl;
	for (int i = 1; i < N + 1; i++)cout << "---";
	cout << endl;
	/*cout << "   1 2 3 4 5 6 7 8 9 10" << endl;
	cout << "   --------------------" << endl;*/
	int i = 1, j = 1;
	while (i < N + 1) {
		if (i < 10)
			cout << i << " |";
		else cout << i << "|";
		for (j = 1; j < N + 1; j++) {
			if (a[i][j] == 1)cout <<"*"<<"  ";
			else if (a[i][j] == 0)cout << "   ";
		}
		cout << endl;
		cout << "  |" << endl;
		i++;
	}
}
int  Dliang(int x, int y, int a[N + 2][N + 2], int b[N + 2][N + 2], int c[N + 2][N + 2]) {
	bool more = true;
	int Alr = 0;
	while (more) {
		more = false;
		Alr = 0;
		if (a[x][y] == 1)return 0;
		else {
			c[x][y] = 1;
			for (x = 1; x < N + 1; x++) {
				for (y = 1; y < N + 1; y++) {
					for (int i = x - 1; i <= x + 1; i++)
						for (int j = y - 1; j <= y + 1; j++)
							if (c[i][j] == -1 && (i != x || j != y))Alr++;
					if (Alr == b[x][y]&&c[x][y]==1) {
						for (int i = x - 1; i <= x + 1; i++)
							for (int j = y - 1; j <= y + 1; j++)
								if (c[i][j] == 0)c[i][j] = 1;
					}
				}
			//	more = true;
			}
		}
		Show(a, b, c);
	}
	return 1;
}
int  Dlei(int x, int y, int a[N + 2][N + 2], int b[N + 2][N + 2], int c[N + 2][N + 2]) {
	if (x == -1)return 1;
	if (a[x][y] == 0)return 0;
	int Alr;
	bool more = true;
	while (more) {
		more = false;
		Alr = 0;
		c[x][y] = -1;
		num--;
		}
	if(x!=-1)Show(a,b,c);
	return 1;
}