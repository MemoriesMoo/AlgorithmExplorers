#include <iostream>
#include <math.h>
#include <float.h>
using namespace std;

struct node{
    double x;
    double y;
};

double prime(node nodes[], int n, int river, double alpha)
{
    double cost = 0;
    double dis[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dis[i][j] = 0;
        }
    }

    // 初始化距离矩阵
    if (river == 1){
        for (int i = 1; i < n; ++i) {
            dis[i][0] = nodes[i].y;
            dis[0][i] = dis[i][0];
        }
    } else{
        for (int i = 1; i < n; ++i) {
            dis[i][0] = nodes[i].y < nodes[i].x ? nodes[i].y : nodes[i].x;
            dis[0][i] = dis[i][0];
        }
    }

    // 计算节点间的欧几里得距离
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            dis[i][j] = sqrt((pow(nodes[i].x - nodes[j].x, 2) + pow(nodes[i].y - nodes[j].y, 2)));
            dis[j][i] = dis[i][j];
        }
    }

    int isin[n];
    int parent[n];
    double way[n];
    isin[0] = 1;
    parent[0] = -1;
    way[0] = 0;
    for (int i = 1; i < n; ++i) {
        isin[i] = 0;
        parent[i] = -1;
        way[i] = 0;
    }

    int v = 1;
    int fromV = 0;
    int toV = 0;
    int haha = 0;
    double minDis = DBL_MAX;
    while (v < n) {
        for (int i = 0; i < n; ++i) {
            if (isin[i] == 1) {
                for (int j = 0; j < n; ++j) {
                    if (isin[j] == 0) {
                        double nowCost = dis[i][j];
                        int son = i;
                        int pa = parent[i];
                        int fl = 1;
                        while (pa != -1) {
                            nowCost = nowCost + way[son] * pow(alpha, fl);
                            haha = fl;
                            fl++;
                            son = pa;
                            pa = parent[pa];
                        }
                        if (nowCost < minDis) {
                            minDis = nowCost;
                            fromV = i;
                            toV = j;
                        }
                    }
                }
            }
        }
        cost += minDis;
        isin[toV] = 1;
        parent[toV] = fromV;
        way[toV] = dis[fromV][toV];

        minDis = DBL_MAX;

        ++v;
    }

    return cost;
}

int main() {
    int num;
    double alpha;
    cin >> num;
    cin >> alpha;
    int n = num + 1;
    node nodes[n];
    nodes[0].x = -1;
    nodes[0].y = -1;
    for (int i = 1; i < n; ++i) {
        cin >> nodes[i].x >> nodes[i].y;
    }

    double cost_b = prime(nodes, n, 1, alpha);
    double cost_c = prime(nodes, n, 2, alpha);
    cout << cost_b << endl;
    cout << cost_c << endl;

    return 0;
}
