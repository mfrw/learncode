#include <iostream>
#include <list>


using namespace std;

class graph {
	int verts;
	list<int> *alist;
	void dfsutil(int v, bool visited[]);
	public:
	graph(int v);
	void add_edge(int src, int dest);
	void add_edge(int src, int dest, bool dag);
	void dfs(int src);
	void bfs(int src);
};

graph::graph(int v)
{
	this->verts = v;
	alist = new list<int>[v];
}
void graph::dfsutil(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";
	list<int>::iterator i;
	for(i = alist[v].begin(); i != alist[v].end(); i++)
		if(!visited[*i])
			dfsutil(*i, visited);
}

void graph::add_edge(int src, int dest)
{
	alist[src].push_back(dest);
}
void graph::add_edge(int src, int dest, bool dag)
{
	alist[src].push_back(dest);
	if(!dag) // if its not a dag then have a edge in the dest list too
		alist[dest].push_back(src);
}

void graph::dfs(int src)
{
	bool *visited = new bool[verts];
	for(int i = 0;i < verts; i++)
		visited[i] = false;
	dfsutil(src, visited);
}

void graph::bfs(int src)
{
	bool *visited = new bool[verts];
	for(int i = 0; i < verts; i++)
		visited[i] = false;
	list<int> queue;

	visited[src] = true;
	queue.push_back(src);

	list<int>::iterator i;
	while(!queue.empty()) {
		src = queue.front();
		cout << src << " ";
		queue.pop_front();
		for(i = alist[src].begin(); i != alist[src].end(); i++) {
			if(!visited[*i]) {
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}



int main() {
	graph g(6);
	g.add_edge(0, 1, false);
	g.add_edge(0, 2, false);
	g.add_edge(1, 2, false);
	g.add_edge(2, 3, false);
	g.add_edge(3, 4, false);
	g.add_edge(4, 5, false);
	g.add_edge(5, 0, false);

	cout << "following is dfs \n";
	g.dfs(0);
	cout << endl;
	cout << "following is bfs \n";
	g.bfs(0);
	cout << endl;
	return 0;
}
