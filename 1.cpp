#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <sstream>

using namespace std;

const int MAXN = 10000005;

int n, m;
vector<int> adj[MAXN];
int visited[MAXN];

bool has_cycle(int u) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (visited[v] == 1) {
            return true;
        } else if (visited[v] == 0) {
            if (has_cycle(v)) {
                return true;
            }
        }
    }
    visited[u] = 2;
    return false;
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
        string input_file = "pb1_tests/test" + to_string(test_num) + ".in";
        string output_file = "pb1_tests_out/test" + to_string(test_num) + ".out";
        string expected_output_file = "pb1_tests/test" + to_string(test_num) + ".out";

        ifstream fin(input_file);
        ofstream fout(output_file);

        fin >> n >> m;

        // Clear the adj vector
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            fin >> u >> v;
            adj[u].push_back(v);
        }

        memset(visited, 0, sizeof(visited));

        int has_cycle_found = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0 && has_cycle(i)) {
                has_cycle_found = 1;
                break;
            }
        }

        fout << has_cycle_found;

        fin.close();
        fout.close();

        // Compare output with expected output
        if (compareFiles(output_file, expected_output_file)) {
            cout << "Test " << test_num << ": OK" << endl;
        } else {
            cout << "Test " << test_num << ": Bad" << endl;
        }
    }

    return 0;
}
