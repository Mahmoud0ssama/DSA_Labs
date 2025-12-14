#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Graph
{

    vector< vector<int> > adj_matrix;
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

    int GetAdjUnVis(int v, vector<bool>& vis)
    {
        for (int i = 1; i <= n; i++)
        {
            if (adj_matrix[v][i] && !vis[i])
                return i;
        }
        return -1;
    }

    vector<int> dfs(int start)
    {
        stack<int> s;
        vector<int> res;
        vector<bool> vis(n + 1, false);

        vis[start] = true;
        s.push(start);

        while (!s.empty())
        {
            int v1 = s.top();
            int v2 = GetAdjUnVis(v1, vis);

            if (v2 == -1)
            {
                res.push_back(v1);
                s.pop();
            }
            else
            {
                vis[v2] = true;
                s.push(v2);
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

    cout << "\nBFS starting from node 1:\n";
    vector<int> dfs_result = g.dfs(1);

    for (int i = 0; i < dfs_result.size(); i++)
    {
        cout << dfs_result[i] << " ";
    }
    cout << endl;

    return 0;

}
