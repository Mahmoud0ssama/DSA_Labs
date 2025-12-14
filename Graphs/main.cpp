#include <iostream>
#include <vector>


using namespace std;

class Graph {

    vector< vector<int> > adj_matrix;

public:
    Graph(int n)
    {
        adj_matrix = vector< vector<int> > (n+1, vector<int>(n+1, 0));
    }

    void add_edge(int u, int v)
    {
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }

    void print()
    {
        cout << "Adjacency Matrix for the Graph: " << endl;
        int n = adj_matrix.size();
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main()
{
    Graph g(10);

    g.add_edge(1, 4);
    g.add_edge(1, 2);
    g.add_edge(4, 3);
    g.add_edge(3, 2);
    g.add_edge(3, 10);
    g.add_edge(3, 9);
    g.add_edge(2, 5);
    g.add_edge(2, 7);
    g.add_edge(2, 8);
    g.add_edge(5, 6);
    g.add_edge(5, 7);
    g.add_edge(5, 8);
    g.add_edge(7, 8);

    g.print();

    return 0;
}
