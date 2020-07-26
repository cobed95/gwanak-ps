#include <iostream>
#include <vector>
#include <limits>
#include <utility>

using namespace std;

vector<vector<int>> getEdges(vector<vector<int>> C) {
    int m = C.size();
    int n = C[0].size();

    int numNodes = n * m;
    vector<vector<int>> edges;
    
    for (int i = 0; i < numNodes; i++) {
        vector<int> tmp;
        edges.push_back(tmp);
        for (int j = 0; j < n; j++) {
            
        }
    }

    return edges;
}

pair<int, int> left(pair<int, int> coord) {
    return make_pair(coord.first - 1, coord.second);
}

pair<int, int> right(pair<int, int> coord) {
    return make_pair(coord.first + 1, coord.second);
}

pair<int, int> up(pair<int, int> coord) {
    return make_pair(coord.first, coord.second - 1);
}

pair<int, int> down(pair<int, int> coord) {
    return make_pair(coord.first, coord.second + 1);
}

bool equals(pair<int, int> fst, pair<int, int> snd) {
    return fst.first == snd.first && fst.second == snd.second;
}

int getMinEffort(vector<vector<int>> C) {
    vector<vector<int>> edges;
    int m = C.size();
    int n = C[0].size();
    
    int numNodes = n * m;
    for (int i = 0; i < numNodes; i++) {
        vector<int> tmp;
        edges.push_back(tmp);
        for (int j = 0; j < numNodes; j++) {
            edges[i].push_back(20000000);
        }
    }

    for (int src = 0; src < numNodes; src++) {
        for (int dest = 0; dest < numNodes; dest++) {
            int srcY = src / n;
            int srcX = src % n;
            pair<int, int> srcCoord = make_pair(srcX, srcY);
            int destY = dest / n;
            int destX = dest % n;
            pair<int, int> destCoord = make_pair(destX, destY);
            
            if (
                    !equals(destCoord, left(srcCoord)) &&
                    !equals(destCoord, right(srcCoord)) &&
                    !equals(destCoord, up(srcCoord)) &&
                    !equals(destCoord, down(srcCoord))
            ) continue;

            int weight = C[srcY][srcX] - C[destY][destX];
            if (weight < 0) 
                weight *= -1;

            edges[src][dest] = weight;
        }
    }
    
    vector<int> shortestPaths;
    for (int i = 0; i < numNodes; i++)
        shortestPaths.push_back(20000000);

    shortestPaths[0] = 0;

    for (int src = 0; src < numNodes; src++) {
        for (int dest = 0; dest < numNodes; dest++) {
            if (src == dest || edges[src][dest] > 2000000)
                continue;
            
            if (shortestPaths[dest] > shortestPaths[src] + edges[src][dest])
                shortestPaths[dest] = shortestPaths[src] + edges[src][dest];

            for (int i = 0; i < numNodes; i++) {
                cout << shortestPaths[i] << endl;
            }
        }
    }

    return shortestPaths[numNodes - 1];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> C;
    
    for (int i = 0; i < m; i++) {
        vector<int> tmpVec;
        C.push_back(tmpVec);
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            C[i].push_back(tmp);
        }
    }

    cout << getMinEffort(C) << endl;

    return 0;
}
