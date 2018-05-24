#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Edge {
	int start, end, cost;
	bool operator < ( const Edge& other) const {
		return cost < other.cost;
	}
};

struct revEdge {
	int start, end, cost;
	bool operator < (const revEdge& other) const {
		return cost > other.cost;
	}
};

int n, m;
int p[1010];
int find(int x) {
	if (x == p[x]) return x;
	return p[x] = find(p[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	p[y] = x;
}

int main() {
	scanf("%d %d", &n, &m);
	n++; m++;
	vector<Edge> Graph(m);
	vector<revEdge> revGraph(m);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		Graph[i].start = revGraph[i].start = a;
		Graph[i].end = revGraph[i].end = b;
		Graph[i].cost = revGraph[i].cost = c;
	}
	sort(Graph.begin(), Graph.end());
	sort(revGraph.begin(), revGraph.end());
	
	int uproad = 0;
	for (int i = 0; i < n; i++) p[i] = i;
	for (int i = 0; i < m; i++) {
		Edge e;
		e.start = Graph[i].start;
		e.end = Graph[i].end;
		e.cost = Graph[i].cost;
		if (find(e.start) == find(e.end)) continue;
		merge(e.start, e.end);
		if (e.cost == 0) uproad += 1;
	}
	
	int downroad = 0;
	for (int i = 0; i < n; i++)	p[i] = i;
	for (int i = 0; i < m; i++) {
		revEdge re;
		re.start = revGraph[i].start;
		re.end = revGraph[i].end;
		re.cost = revGraph[i].cost;
		if (find(re.start) == find(re.end)) continue;
		merge(re.start, re.end);
		if (re.cost == 0) downroad += 1;
	}
	printf("%d\n", uproad*uproad - downroad*downroad);
}