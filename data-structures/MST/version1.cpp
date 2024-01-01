#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <queue>

// 农户位置坐标类
class PosFarmer
{
    // 此处为方便赋值将成员属性和函数属性均设置为public
public:
    // 坐标信息
    double x;
    double y;

    // 构造函数 此处使用全缺省是保证存在默认构造函数存在
    PosFarmer(double xx = -1, double yy = -1) : x(xx), y(yy) {}

    // 默认析构函数
    ~PosFarmer() = default;
};

// 计算最小生成树的总权重
double calMSTWeight(std::vector<std::vector<double>> &distances, int farmerNums, int farmerI, int farmerJ) {
    // 记录节点是否被访问
    std::vector<bool> visitedNodes(farmerNums, false);
    // 记录从最小生成树到未访问节点的最小权值
    std::vector<double> minWeight(farmerNums, std::numeric_limits<double>::max());

    // 设置起始节点为0
    minWeight[0] = 0;
    // 记录总权值
    double totalWeight = 0.0;

    // 遍历需要加入最小生成树的节点
    for (int it = 0; it < farmerNums; ++it) {
        // 选择未访问节点中权值最小的节点
        int curNode = -1;
        double minNode = std::numeric_limits<double>::max();

        // 遍历所有节点，找到未访问节点中键值最小的节点
        for (int j = 0; j < minWeight.size(); ++j)
            if (!visitedNodes[j] && minWeight[j] < minNode) {
                minNode = minWeight[j];
                curNode = j;
            }

        // 如果找不到未访问节点，退出循环
        if (curNode == -1)
            break;

        // 处理当前节点
        visitedNodes[curNode] = true;

        // 遍历所有未访问节点，更新权值为新节点到未访问节点的距离
        for (int adjacentNode = 0; adjacentNode < farmerNums; ++adjacentNode)
            if (!visitedNodes[adjacentNode])
                minWeight[adjacentNode] = std::min(minWeight[adjacentNode], distances[curNode][adjacentNode]);

        // 累加总权值
        totalWeight += minWeight[curNode];
        
        // 处理相邻节点
        if (curNode == farmerI || curNode == farmerJ) {
            int neighbourNode = (curNode == farmerI) ? farmerJ : farmerI;

            // 标记相邻节点为已访问 防止后续继续访问
            visitedNodes[neighbourNode] = true;
            
            // 累加总权值
            totalWeight += distances[farmerI][farmerJ];
            
            // 更新相邻节点的权值
            for (int adjacentNode = 0; adjacentNode < farmerNums; ++adjacentNode)
                if (!visitedNodes[adjacentNode])
                    minWeight[adjacentNode] = std::min(minWeight[adjacentNode], distances[neighbourNode][adjacentNode]);
        }
    }

    return totalWeight;
}

int main()
{
    // 获取农户数量
    int farmerNums;
    std::cin >> farmerNums;
    // 整个矩阵需要完整 因此包括河流上的坐标信息因此需要+1满足需求
    int totalPos = farmerNums + 1;

    // 存储整个结构坐标信息结构体向量
    std::vector<PosFarmer> farmers(totalPos);

    // 此处不能使用auto循环 会导致无法输出结果
    // 因为此处需要获取的仅仅是农户坐标信息
    // for(auto& farmer:farmers)
    //     std::cin >> farmer.x >> farmer.y;

    // 获取农户坐标 农户编号从1开始
    for (int i = 1; i < totalPos; ++i)
        std::cin >> farmers[i].x >> farmers[i].y;

    // b情形距离矩阵（一条河流）
    std::vector<std::vector<double>> norDis(totalPos, std::vector<double>(totalPos, -1));
    // c情形距离矩阵（两条河流）
    std::vector<std::vector<double>> douDis(totalPos, std::vector<double>(totalPos, -1));
    // d情形距离矩阵（c的拓展情形）
    std::vector<std::vector<double>> reachDis(totalPos, std::vector<double>(totalPos, -1));

    for (int i = 1; i < totalPos; ++i)
    {
        // 一条河流情形 将norDis矩阵的第一列和第一行设置为农户的y坐标 即距离河流的垂直距离 纵坐标
        norDis[i][0] = norDis[0][i] = farmers[i].y;

        // 两条河流情形 对于douDis和unreachDis矩阵的第一列以及第一行设置为农户的y坐标或x坐标的较小值 即距离哪条河流更近
        douDis[i][0] = reachDis[i][0] = douDis[0][i] = reachDis[0][i] =
            farmers[i].y < farmers[i].x ? farmers[i].y : farmers[i].x;

        for (int j = i + 1; j < totalPos; ++j)
            // 计算农户i和j之间的欧几里得距离并将距离赋值给各个距离矩阵中对应的位置
            // 因为三种情形的农户间距离不变可统一进行赋值
            norDis[i][j] = norDis[j][i] = douDis[i][j] = reachDis[i][j] = douDis[j][i] = reachDis[j][i] =
                std::sqrt((std::pow(farmers[i].x - farmers[j].x, 2) + std::pow(farmers[i].y - farmers[j].y, 2)));
    }

    // 农户默认为-1 -1不处理
    double norDisWeight = calMSTWeight(norDis, totalPos, -1, -1);
    double douDisWeight = calMSTWeight(douDis, totalPos, -1, -1);

    // // 农户必须相连
    // int i, j;
    // std::cin >> i >> j;
    // reachDis[i][j] = reachDis[j][i] = 0.0;
    // std::cout << "Input a: " << a << ", b: " << b << std::endl;
    // std::cout << "unreachDis[a][b]: " << unreachDis[a][b] << std::endl;
    // std::cout << "unreachDis[b][a]: " << unreachDis[b][a] << std::endl;

    // 获取两个农户的编号，它们必须连接
    int i, j;
    std::cin >> i >> j;

    // 将c和d情形下的距离矩阵根据要求更新后计算每种情况下的总权值（最低成本）并输出
    double unreachDisWeught = calMSTWeight(reachDis, totalPos, i, j);
    // 每种输出进行换行符合输出要求
    std::cout << norDisWeight << std::endl;
    std::cout << douDisWeight << std::endl;
    std::cout << unreachDisWeught << std::endl;

    return 0;
}
