#include<stdio.h>
#include<stddlib.h>

struct alist_node {
	int dest;
	struct alist_node *next;
};

struct alist_t {
	struct alist_node *head;
};


struct graph_t {
	int verticies;
	struct alist_t *array;
};


static alist_node *alloc_alist_node(int dest) {
	struct alist_node *new = malloc(sizeof(struct alist_node));
	if(!new)
		return NULL;
	new->dest = dest;
	new->next = NULL;
	return new;
}

struct graph_t *create_graph(int vertices) {
	struct graph_t *graph = malloc(sizeof(struct graph_t));
	if(!graph)
		return NULL;
	graph->vertices = vertices;
	graph->array = malloc(vertices * sizeof(struct alist_t));
	if(!graph->array) {
		free(graph);
		return NULL;
	}
	int i;
	for(i = 0; i < vertices; i++)
		graph->array[i].head = NULL;
	return graph;
}

int add_edge(struct graph_t *graph, int src, int dest) {
	struct alist_node *new = alloc_alist_node(dest);
	new->next = graph->array[src].head;
	graph->array[src].head = new;
	// since its a Undirected add the other edge too :)
	new = alloc_alist_node(src);
	new->next = graph->array[dest].head;
	graph->array[dest].head = new;

	return 1;
}

int is_connected(struct graph_t *graph, int src, int dest) {
	struct alist_node *tmp;
	if(!graph)
		return -1;
	tmp = graph->array[src].head;
	while(tmp) {
		if(tmp->dest == dest)
			return 1;
		tmp = tmp->next;
	}
	return 0;
}


void print_graph(struct graph_t *graph) {
	int vert;
	for(vert = 0; vert < graph->vertices; v++) {
		printf("Adj List of vert %d\n head ", vert);
		struct alist_node *temp = graph->array[vert].head;
		while(temp) {
			printf("-> %d", temp->dest);
			temp = temp->next;
		}
		printf("\n");
	}
}


int main() {
	int vert = 100;
	struct graph_t *graph = create_graph(vert);
}
