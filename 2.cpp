#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

const int INF = 1e9;

int n, m, s;
vector<pair<int, int>> graph[100001];
vector<int> distances;

void topologicalSort(int startNode, vector<bool>& visited, vector<int>& sorted) {
    visited[startNode] = true;
    for (auto neighbor : graph[startNode]) {
        int v = neighbor.first;
        if (!visited[v]) {
            topologicalSort(v, visited, sorted);
        }
    }
    sorted.push_back(startNode);
}

void shortestPath(int startNode) {
    vector<bool> visited(n + 1, false);
    vector<int> sorted;
    topologicalSort(startNode, visited, sorted);
    distances.assign(n + 1, INF);
    distances[startNode] = 0;
    for (int i = sorted.size() - 1; i >= 0; i--) {
        int u = sorted[i];
        if (distances[u] != INF) {
            for (auto neighbor : graph[u]) {
                int v = neighbor.first;
                int w = neighbor.second;
                if (distances[v] > distances[u] + w) {
                    distances[v] = distances[u] + w;
                }
            }
        }
    }
}

bool compareFiles(const string& file1, const string& file2) {
    ifstream fin1(file1);
    ifstream fin2(file2);
    string line1, line2;

    while (getline(fin1, line1) && getline(fin2, line2)) {
        if (line1 != line2) {
            fin1.close();
            fin2.close();
            return false;
        }
    }

    bool isEOF1 = (fin1.peek() == ifstream::traits_type::eof());
    bool isEOF2 = (fin2.peek() == ifstream::traits_type::eof());

    fin1.close();
    fin2.close();

    return (isEOF1 && isEOF2);
}

int main() {
    for (int test_num = 1; test_num <= 10; test_num++) {
        string input_file = "pb2_tests/test" + to_string(test_num) + ".in";
        string output_file = "pb2_tests_out/test" + to_string(test_num) + ".out";
        string expected_output_file = "pb2_tests/test" + to_string(test_num) + ".out";

        ifstream fin(input_file);
        fin >> n >> m >> s;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            fin >> u >> v >> w;
            graph[u].push_back({v, w});
        }
        fin.close();

        shortestPath(s);

        ofstream fout(output_file);
        for (int i = 1; i <= n; i++) {
            if (distances[i] == INF)
                fout << -1 << " ";
            else
                fout << distances[i] << " ";
        }
        fout.close();

        // Compare output with expected output
        if (compareFiles(output_file, expected_output_file)) {
            cout << "Test " << test_num << ": OK" << endl;
        } else {
            cout << "Test " << test_num << ": Bad" << endl;
        }

        // Clear the graph and distances for the next test
        for (int i = 1; i <= n; i++) {
            graph[i].clear();
        }
        distances.clear();
    }

    return 0;
}
