#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Graph
{

    vector<vector<int> > adj_matrix;
    int n;

public:
    Graph(int n)
    {
        this->n = n;
        adj_matrix = vector<vector<int> >(n+1, vector<int>(n+1, 0));
    }

    void add_edge(int u, int v)
    {
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1; //for undirected
    }

    void print()
    {
        cout << "Adjacency Matrix for the Graph: " << endl;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    vector<int> bfs(int start)
    {
        vector <int> res;
        queue <int> q;
        vector<bool> vis(n + 1, false);

        vis[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            res.push_back(v);

            for (int i = 1; i <= n; i++)
            {
                if (adj_matrix[v][i] && !vis[i])
                {
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
        return res;
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

    cout << "\nBFS starting from node 3:\n";
    vector<int> bfs_result = g.bfs(3);

    for (int i = 0; i < bfs_result.size(); i++)
    {
        cout << bfs_result[i] << " ";
    }
    cout << endl;

    return 0;

}
