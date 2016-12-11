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


int main() {
	graph g(4);
	g.add_edge(0, 1, false);
	g.add_edge(0, 2, false);
	g.add_edge(1, 2, false);
	g.add_edge(2, 3, false);

	cout << "following is dfs \n";
	g.dfs(2);
	cout << endl;
	return 0;
}
