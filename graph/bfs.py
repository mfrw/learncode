from collections import defaultdict as dd

class graph:
    def __init__(self):
        self.gr = dd(list)

    def add_edge(self, src, dest, dag=False):
        self.gr[src].append(dest);
        if not dag:
            self.gr[dest].append(src)


    def bfs(self, src):

        verts = len(self.gr)
        visited = [False]*(verts)
        queue = []
        queue.append(src)
        visited[src] = True
        while queue:
            src = queue.pop()
            print src,
            for i in self.gr[src]:
                if not visited[i]:
                    queue.append(i)
                    visited[i] = True

def main():
    g = graph()
    g.add_edge(0,1)
    g.add_edge(0,2)
    g.add_edge(1,2)
    g.add_edge(2,3)
    g.bfs(0)


if __name__ == '__main__':
    main()
