#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>

using namespace std;

const int INF = 1e9;

typedef pair<int, int> p;

typedef vector<vector<pair<int, int>>> Graph;

int heuristic(int u, int v) {
    return abs(u - v);
}

struct Compare {
    bool operator()(const p& p1, const p& p2) const {
        return p1.first > p2.first;
    }
};

void astar(const Graph& graph, int source, vector<int>& distances) {
    priority_queue<p, vector<p>, Compare> pq;
    pq.push(make_pair(0, source));
    distances[source] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            int g = distances[u] + weight;
            int h = heuristic(v, source);
            int f = g + h;

            if (distances[v] > g) {
                distances[v] = g;
                pq.push(make_pair(f, v));
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
        string input_file = "pb3_tests/test" + to_string(test_num) + ".in";
        string output_file = "pb3_tests_out/test" + to_string(test_num) + ".out";
        string expected_output_file = "pb3_tests/test" + to_string(test_num) + ".out";

        ifstream fin(input_file);
        int n, m, s;
        fin >> n >> m >> s;

        Graph graph(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            fin >> u >> v >> w;
            graph[u].push_back(make_pair(v, w));
        }
        fin.close();

        vector<int> distances(n + 1, INF);
        astar(graph, s, distances);

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
        graph.clear();
        distances.clear();
    }

    return 0;
}
