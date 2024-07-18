#include <iostream>
#include <vector>
#include <algorithm>

class StronglyConnectedComponents
{
    std::vector<std::vector<int>> graph;
    std::vector<std::vector<int>> reverseGraph;
    std::vector<bool> detected;
    std::vector<int> finishedOrder;
    std::vector<int> component;

    void dfs(std::vector<std::vector<int>> &graph, int node)
    {
        detected[node] = true;
        for (int nextNode : graph[node])
        {
            if (!detected[nextNode])
            {
                dfs(graph, nextNode);
            }
        }
        finishedOrder.push_back(node);
    }

    void dfs_reverse(std::vector<std::vector<int>> &graph, int node)
    {
        detected[node] = true;
        component.push_back(node);
        for (int nextNode : graph[node])
        {
            if (!detected[nextNode])
            {
                dfs_reverse(graph, nextNode);
            }
        }
    }

    void create_reverse_graph()
    {
        reverseGraph.resize(graph.size());
        for (int i = 0; i < graph.size(); i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                reverseGraph[graph[i][j]].push_back(i);
            }
        }
    }

public:
    explicit StronglyConnectedComponents(std::vector<std::vector<int>> &graph) : graph(graph)
    {
        detected.resize(graph.size(), false);
        create_reverse_graph();
    }
    ~StronglyConnectedComponents() {}

    std::vector<std::vector<int>> get_strongly_connected_components()
    {
        for (int i = 0; i < graph.size(); i++)
        {
            if (!detected[i])
            {
                dfs(graph, i);
            }
        }

        std::fill(detected.begin(), detected.end(), false);
        std::vector<std::vector<int>> stronglyConnectedComponents;
        for (int i = finishedOrder.size() - 1; i >= 0; i--)
        {
            if (!detected[finishedOrder[i]])
            {
                component.clear();
                dfs_reverse(reverseGraph, finishedOrder[i]);
                stronglyConnectedComponents.push_back(component);
            }
        }

        return stronglyConnectedComponents;
    }
};

int main()
{
    std::vector<std::vector<int>> graph = {
        {1},
        {2},
        {0},
        {1, 2, 4},
        {3, 5},
        {6},
        {4},
        {5, 6, 7}};

    StronglyConnectedComponents scc(graph);
    std::vector<std::vector<int>> components = scc.get_strongly_connected_components();

    for (const auto &component : components)
    {
        for (int node : component)
        {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
