#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

// 农户位置坐标类
class PosFarmer
{
    // 此处为方便赋值将成员属性和函数属性均设置为public
public:
    // 坐标信息
    double x;
    double y;

    // 构造函数 此处使用全缺省是保证存在默认构造函数存在
    PosFarmer(int xx = -1, int yy = -1) : x(xx), y(yy) {}

    // 默认析构函数
    ~PosFarmer() = default;
};

// 计算最小生成树的权重
double calMSTWeight(std::vector<std::vector<double>> &distances, int farmerNums)
{
    double totalWeight = 0.0;
    std::vector<double> minDistances(farmerNums, 0); // 记录每个节点到最小生成树的最小距离
    std::vector<bool> isInMST(farmerNums, false);    // 记录节点是否已经在最小生成树中
    isInMST[0] = true;                               // 从第一个节点开始构建最小生成树

    // 遍历需要加入最小生成树的节点
    for (int visitedNodes = 1; visitedNodes < farmerNums; ++visitedNodes)
    {
        double minDistance = std::numeric_limits<double>::max(); // 记录最小距离
        int startNode = 0;                                       // 记录最小距离的边的起始节点
        int endNode = 0;                                         // 记录最小距离的边的结束节点

        // 遍历已经在最小生成树中的节点
        for (int i = 0; i < farmerNums; ++i)
            if (isInMST[i])
                // 遍历节点 i的邻居节点
                for (int j = 0; j < farmerNums; ++j)
                    if (!isInMST[j] && distances[i][j] > 0)
                        // 更新最小距离及相关节点信息
                        if ((distances[i][j] + minDistances[i]) < minDistance)
                        {
                            endNode = j;
                            startNode = i;
                            minDistance = distances[i][j] + minDistances[i];
                        }

        minDistances[endNode] = minDistance; // 更新最小距离
        totalWeight += minDistance;          // 更新总权重
        isInMST[endNode] = true;             // 将具有最小距离的节点加入最小生成树
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
    std::vector<std::vector<double>> norDis(totalPos, std::vector<double>(totalPos, 0));
    // c情形距离矩阵（两条河流）
    std::vector<std::vector<double>> douDis(totalPos, std::vector<double>(totalPos, 0));
    // d情形距离矩阵（c的拓展情形）
    std::vector<std::vector<double>> unreachDis(totalPos, std::vector<double>(totalPos, 0));

    for (int i = 1; i < totalPos; ++i)
    {
        // 一条河流情形 将norDis矩阵的第一列和第一行设置为农户的y坐标 即距离河流的垂直距离 纵坐标
        norDis[i][0] = norDis[0][i] = farmers[i].y;

        // 两条河流情形 对于douDis和unreachDis矩阵的第一列以及第一行设置为农户的y坐标或x坐标的较小值 即距离哪条河流更近
        douDis[i][0] = unreachDis[i][0] = douDis[0][i] = unreachDis[0][i] =
            farmers[i].y < farmers[i].x ? farmers[i].y : farmers[i].x;

        for (int j = i + 1; j < totalPos; ++j)
            // 计算农户i和j之间的欧几里得距离并将距离赋值给各个距离矩阵中对应的位置
            // 因为三种情形的农户间距离不变可统一进行赋值
            norDis[i][j] = norDis[j][i] = douDis[i][j] = unreachDis[i][j] = douDis[j][i] = unreachDis[j][i] =
                std::sqrt((std::pow(farmers[i].x - farmers[j].x, 2) + std::pow(farmers[i].y - farmers[j].y, 2)));
    }

    double norDisWeight = calMSTWeight(norDis, totalPos);
    double douDisWeight = calMSTWeight(douDis, totalPos);

    int k, l;

    // 多少对农户彼此之间不能直接修水道
    std::cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int farmerNoCon1, farmerNoCon2;
        std::cin >> farmerNoCon1 >> farmerNoCon2;
        // 将指定农户之间的边的权值（水道成本）设为最大值 表示不可达
        //  std::numeric_limits<double>::max()用于获取double类型的最大值
        unreachDis[farmerNoCon1][farmerNoCon2] = unreachDis[farmerNoCon2][farmerNoCon1] =
            std::numeric_limits<double>::max();
    }

    // 不能直接从河道获取水源的农户数目
    std::cin >> l;
    for (int i = 0; i < l; ++i)
    {
        int farmerNoWater;
        std::cin >> farmerNoWater;
        // 将指定农户与两条河流的边的权值设为最大值（即成本为最大值）表示不可达
        //  std::numeric_limits<double>::max()用于获取double类型的最大值
        // 第一次提交此处存在bug
        unreachDis[0][farmerNoWater] = unreachDis[farmerNoWater][0] =
            std::numeric_limits<double>::max();
    }

    double unreachDisWeight = calMSTWeight(unreachDis, totalPos);

    // 每种输出进行换行符合输出要求
    std::cout << norDisWeight << std::endl;
    std::cout << douDisWeight << std::endl;
    std::cout << unreachDisWeight << std::endl;

    return 0;
}
