<<<<<<< HEAD
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

// num 为棋盘大小：num*num
// i0 为棋子起始行号（1~num）
// j0 为棋子起始列号（1~num）
// in 为棋子终止行号（1~num）
// jn 为棋子终止列号（1~num）
// step 为最大移动步数
// data 为棋盘格子分数，data[i][j]为第(i-1)行，第(j-1)列的分数。
// 返回值为获得的最大分数。如果无法移动到终止位置，则输出-1
// path 为棋子最佳移动路线。如果有多条，则输出路径最短的一条。如果路径最短的有多条，则输出任意一条。初始位置和终止位置也需要输出。如果无法移动到终止位置，则不输出path
int maximum(int a, int b, int c, int d)
{
	int max = (a < b) ? b : a;
	max = ((max < c) ? c : max);
	return ((max < d) ? d : max);
}
int FindPath(int num, int i0, int j0, int in, int jn, int step, const vector< vector<int> >& data, vector< pair<int, int> >& path)
{	
	if (step == 0 && (j0 != jn || i0 != in)) {
		return false;
	}
	int sum_r = 0;
	int sum_l = 0;
	int sum_d = 0;
	int sum_u = 0;
	if (i0 < num - 1) {
		sum_r = data[i0][j0] + FindPath(num, i0 + 1, j0, in, jn, step - 1, data, path);
	}
	if (i0 > 0) {
		sum_l = data[i0][j0] + FindPath(num, i0 - 1, j0, in, jn, step - 1, data, path);
	}
	if (j0 < num-1) {
		sum_d = data[i0][j0] + FindPath(num, i0, j0 + 1, in, jn, step - 1, data, path);
	}
	if (j0 > 0) {
		sum_u = data[i0][j0] + FindPath(num, i0, j0 + 1, in, jn, step - 1, data, path);
	}
	if (sum_r == maximum(sum_r, sum_l, sum_u, sum_d)) {
		pair<int, int> p  { i0 + 1, j0 };
		path.push_back(p);
	}
	if (sum_l == maximum(sum_r, sum_l, sum_u, sum_d)) {
		pair<int, int> p = { i0 + 1, j0 };
		path.push_back(make_pair(i0+1, j0));
	}
	if (sum_d == maximum(sum_r, sum_l, sum_u, sum_d)) {
		pair<int, int> p = { i0 + 1, j0 };
		path.push_back(pair<int, int>(i0, j0 + 1));
	}
	if (sum_u == maximum(sum_r, sum_l, sum_u, sum_d)) {
		pair<int, int> p = { i0 + 1, j0 };
		path.push_back(pair<int, int>(i0, j0 - 1));
	}
	return maximum(sum_r, sum_l, sum_u, sum_d);
}

int main(int argc, char* argv[])
{
	int num = 10;
	int step = 0;
	int i0 = 0;
	int j0 = 0;
	int in = 0;
	int jn = 0;
	vector< vector<int> > data(num);
	for (int i = 0; i < num; ++i) {
		data[i].resize(num);
		for (int j = 0; j < num; ++j) {
			cin >> data[i][j];
		}
	}
	cin >> i0 >> j0 >> in >> jn >> step;

	vector< pair<int, int> > path;
	int maxscore = FindPath(num, i0, j0, in, jn, step, data, path);

	cout << maxscore << endl;
	if (maxscore >= 0) {
		for (int i = 0; i < path.size(); ++i) {
			if (i>0) cout << " ";
			cout << path[i].first << "," << path[i].second;
		}
	}
	cout << endl;

	return 0;
=======
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

// num 为棋盘大小：num*num
// i0 为棋子起始行号（1~num）
// j0 为棋子起始列号（1~num）
// in 为棋子终止行号（1~num）
// jn 为棋子终止列号（1~num）
// step 为最大移动步数
// data 为棋盘格子分数，data[i][j]为第(i-1)行，第(j-1)列的分数。
// 返回值为获得的最大分数。如果无法移动到终止位置，则输出-1
// path 为棋子最佳移动路线。如果有多条，则输出路径最短的一条。如果路径最短的有多条，则输出任意一条。初始位置和终止位置也需要输出。如果无法移动到终止位置，则不输出path
int maximum(int a, int b, int c, int d)
{
	int max = (a < b) ? b : a;
	max = ((max < c) ? c : max);
	return ((max < d) ? d : max);
}
int FindPath(int num, int i0, int j0, int in, int jn, int step, const vector< vector<int> >& data, vector< pair<int, int> >& path)
{	
	if (step == 0 && (j0 != jn || i0 != in)) {
		return false;
	}
	int sum_r = 0;
	int sum_l = 0;
	int sum_d = 0;
	int sum_u = 0;
	if (i0 < num - 1) {
		sum_r = data[i0][j0] + FindPath(num, i0 + 1, j0, in, jn, step - 1, data, path);
	}
	if (i0 > 0) {
		sum_l = data[i0][j0] + FindPath(num, i0 - 1, j0, in, jn, step - 1, data, path);
	}
	if (j0 < num-1) {
		sum_d = data[i0][j0] + FindPath(num, i0, j0 + 1, in, jn, step - 1, data, path);
	}
	if (j0 > 0) {
		sum_u = data[i0][j0] + FindPath(num, i0, j0 + 1, in, jn, step - 1, data, path);
	}
	if (sum_r == maximum(sum_r, sum_l, sum_u, sum_d)) {
		pair<int, int> p  { i0 + 1, j0 };
		path.push_back(p);
	}
	if (sum_l == maximum(sum_r, sum_l, sum_u, sum_d)) {
		pair<int, int> p = { i0 + 1, j0 };
		path.push_back(make_pair(i0+1, j0));
	}
	if (sum_d == maximum(sum_r, sum_l, sum_u, sum_d)) {
		pair<int, int> p = { i0 + 1, j0 };
		path.push_back(pair<int, int>(i0, j0 + 1));
	}
	if (sum_u == maximum(sum_r, sum_l, sum_u, sum_d)) {
		pair<int, int> p = { i0 + 1, j0 };
		path.push_back(pair<int, int>(i0, j0 - 1));
	}
	return maximum(sum_r, sum_l, sum_u, sum_d);
}

int main(int argc, char* argv[])
{
	int num = 10;
	int step = 0;
	int i0 = 0;
	int j0 = 0;
	int in = 0;
	int jn = 0;
	vector< vector<int> > data(num);
	for (int i = 0; i < num; ++i) {
		data[i].resize(num);
		for (int j = 0; j < num; ++j) {
			cin >> data[i][j];
		}
	}
	cin >> i0 >> j0 >> in >> jn >> step;

	vector< pair<int, int> > path;
	int maxscore = FindPath(num, i0, j0, in, jn, step, data, path);

	cout << maxscore << endl;
	if (maxscore >= 0) {
		for (int i = 0; i < path.size(); ++i) {
			if (i>0) cout << " ";
			cout << path[i].first << "," << path[i].second;
		}
	}
	cout << endl;

	return 0;
>>>>>>> origin/master
}