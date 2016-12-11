from collections import defaultdict as dd

class graph:
    def __init__(self):
        self.gr = dd(list)

    def add_edge(self, src, dest, dag=False):
        self.gr[src].append(dest);
        if not dag:
            self.gr[dest].append(src)

    def dfsutil(self, src, visited):
        visited[src] = True
        print src,
        for i in self.gr[src]:
            if not visited[i]:
                self.dfsutil(i, visited)

    def dfs(self, src):

        verts = len(self.gr)
        visited = [False]*(verts)
        self.dfsutil(src, visited)

def main():
    g = graph()
    g.add_edge(0,1)
    g.add_edge(0,2)
    g.add_edge(1,2)
    g.add_edge(2,3)
    g.dfs(0)


if __name__ == '__main__':
    main()
