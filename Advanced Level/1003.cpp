#include <iostream>
#include <vector>
using namespace std;
#define N 500

int matrix[N][N];
int teams[N];
bool nodes[N];
vector<int> path;

int n, m, s, d, count, maxTeam, minDis;

void DFS (int t) 
{
	if (t == d) {
		int currentDis = 0, currentTeam = 0;
		for (int i = 0; i < path.size(); i++)
			currentTeam += teams[path[i]];
		for (int i = 0; i < path.size() - 1; i++)
			currentDis += matrix[path[i]][path[i + 1]];
		if (currentDis < minDis) {
			count = 1;
			minDis = currentDis;
			maxTeam = currentTeam;
		} else if (currentDis == minDis) {
			count++;
			maxTeam = currentTeam > maxTeam ? currentTeam : maxTeam;
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (matrix[t][i] != 0x7fffffff && !nodes[i]) {
			nodes[i] = true;
			path.push_back(i);
			DFS(i);
			path.pop_back();
			nodes[i] = false;
		}
	}
}
int main () 
{
	int x, y, w;
	while (cin>>n>>m>>s>>d) {
		int temp = s;
		count = 0;
		maxTeam = 0xffffffff; 
		minDis = 0x7fffffff;
		for (int i = 0; i < n; i++)
			cin>>teams[i];
		for (int i = 0; i < n; i++) {
			nodes[i] = false;
			for (int j = 0; j < n; j++)
				matrix[i][j] = 0x7fffffff;
		}
		for (int i = 0; i < m; i++) {
			cin>>x>>y>>w;
			matrix[x][y] = matrix[y][x] = w;
		}
		path.clear();
		path.push_back(temp);
		nodes[temp] = true;
		DFS(temp);
		cout<<count<<" "<<maxTeam<<endl;	
	}
	return 0;
}