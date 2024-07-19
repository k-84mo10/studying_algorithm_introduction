#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

// Edge構造体を定義
struct Edge
{
    int src, dest, weight;
};

// グラフクラスを定義
class Graph
{
    int V, E;
    std::vector<Edge> edges;

    // Union-Findのfindメソッド
    int find(std::vector<int> &parent, int i)
    {
        if (parent[i] != i)
        {
            parent[i] = find(parent, parent[i]);
        }
        return parent[i];
    }

    // Union-Findのunionメソッド
    void Union(std::vector<int> &parent, std::vector<int> &rank, int x, int y)
    {
        int xroot = find(parent, x);
        int yroot = find(parent, y);

        if (rank[xroot] < rank[yroot])
        {
            parent[xroot] = yroot;
        }
        else if (rank[xroot] > rank[yroot])
        {
            parent[yroot] = xroot;
        }
        else
        {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

public:
    Graph(int V, int E) : V(V), E(E)
    {
        edges.reserve(E);
    }

    // エッジを追加するメソッド
    void addEdge(int src, int dest, int weight)
    {
        edges.push_back({src, dest, weight});
    }

    // KruskalのMSTを求めるメソッド
    void kruskalMST()
    {
        std::vector<Edge> result;
        result.reserve(V - 1);

        // エッジを重みでソート
        sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
             { return a.weight < b.weight; });

        std::vector<int> parent(V);
        std::vector<int> rank(V, 0);

        // 各頂点を自身を親とする
        for (int i = 0; i < V; ++i)
        {
            parent[i] = i;
        }

        // MSTを構築
        for (const auto &edge : edges)
        {
            int x = find(parent, edge.src);
            int y = find(parent, edge.dest);

            if (x != y)
            {
                result.push_back(edge);
                Union(parent, rank, x, y);
            }
        }

        // MSTの表示
        std::cout << "Edges in the Minimum Spanning Tree (Kruskal's Algorithm):" << std::endl;
        for (const auto &edge : result)
        {
            std::cout << char(edge.src + 'a') << " -- " << char(edge.dest + 'a') << " == " << edge.weight << std::endl;
        }
    }

    // PrimのMSTを求めるメソッド
    void primMST()
    {
        std::vector<bool> inMST(V, false);
        std::vector<int> key(V, std::numeric_limits<int>::max());
        std::vector<int> parent(V, -1);

        // 最初の頂点を0に設定
        key[0] = 0;
        parent[0] = -1; // 初めの頂点はMSTに含まれない

        // 優先度キューで最小のキーを持つ頂点を選ぶ
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        pq.push({0, 0}); // {key, vertex}

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            // 現在の頂点がMSTに含まれているか確認
            if (inMST[u])
                continue;

            inMST[u] = true;

            // 隣接リストのエッジを調べる
            for (const auto &edge : edges)
            {
                if (edge.src == u && !inMST[edge.dest] && edge.weight < key[edge.dest])
                {
                    key[edge.dest] = edge.weight;
                    pq.push({key[edge.dest], edge.dest});
                    parent[edge.dest] = u;
                }
                else if (edge.dest == u && !inMST[edge.src] && edge.weight < key[edge.src])
                {
                    key[edge.src] = edge.weight;
                    pq.push({key[edge.src], edge.src});
                    parent[edge.src] = u;
                }
            }
        }

        // MSTの表示
        std::cout << "Edges in the Minimum Spanning Tree (Prim's Algorithm):" << std::endl;
        for (int i = 1; i < V; ++i)
        {
            std::cout << char(parent[i] + 'a') << " -- " << char(i + 'a') << " == " << key[i] << std::endl;
        }
    }
};

int main()
{
    // 頂点数とエッジ数の指定
    int V = 9;  // 頂点数
    int E = 13; // エッジ数
    Graph graph(V, E);

    int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6, h = 7, i = 8;

    // エッジの追加
    graph.addEdge(a, b, 4);
    graph.addEdge(a, h, 8);
    graph.addEdge(b, c, 8);
    graph.addEdge(b, h, 11);
    graph.addEdge(c, d, 7);
    graph.addEdge(c, f, 4);
    graph.addEdge(c, i, 2);
    graph.addEdge(d, e, 9);
    graph.addEdge(d, f, 14);
    graph.addEdge(e, f, 10);
    graph.addEdge(f, g, 2);
    graph.addEdge(g, h, 1);
    graph.addEdge(g, i, 6);
    graph.addEdge(h, i, 7);

    // Kruskalのアルゴリズムを実行
    graph.kruskalMST();

    // Primのアルゴリズムを実行
    graph.primMST();

    return 0;
}
