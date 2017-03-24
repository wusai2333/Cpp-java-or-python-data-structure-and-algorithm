<<<<<<< HEAD
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

// num Ϊ���̴�С��num*num
// i0 Ϊ������ʼ�кţ�1~num��
// j0 Ϊ������ʼ�кţ�1~num��
// in Ϊ������ֹ�кţ�1~num��
// jn Ϊ������ֹ�кţ�1~num��
// step Ϊ����ƶ�����
// data Ϊ���̸��ӷ�����data[i][j]Ϊ��(i-1)�У���(j-1)�еķ�����
// ����ֵΪ��õ�������������޷��ƶ�����ֹλ�ã������-1
// path Ϊ��������ƶ�·�ߡ�����ж����������·����̵�һ�������·����̵��ж��������������һ������ʼλ�ú���ֹλ��Ҳ��Ҫ���������޷��ƶ�����ֹλ�ã������path
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

// num Ϊ���̴�С��num*num
// i0 Ϊ������ʼ�кţ�1~num��
// j0 Ϊ������ʼ�кţ�1~num��
// in Ϊ������ֹ�кţ�1~num��
// jn Ϊ������ֹ�кţ�1~num��
// step Ϊ����ƶ�����
// data Ϊ���̸��ӷ�����data[i][j]Ϊ��(i-1)�У���(j-1)�еķ�����
// ����ֵΪ��õ�������������޷��ƶ�����ֹλ�ã������-1
// path Ϊ��������ƶ�·�ߡ�����ж����������·����̵�һ�������·����̵��ж��������������һ������ʼλ�ú���ֹλ��Ҳ��Ҫ���������޷��ƶ�����ֹλ�ã������path
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