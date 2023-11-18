//
// Created by zero on 23-11-17.
//

#ifndef EDA_DATABASE_H
#define EDA_DATABASE_H

#include <vector>
#include <string>

using namespace std;

struct NumNet
{
    int number;//线网个数
    vector<string>Net;//保存每个线网长度
    vector<int>NetSum;//线网长度求和
    vector<vector<string>>pin;//保存各个线网的单元
};
struct data
{
    vector<int>data1;//储存所有数字
    string DieSize[2];//布局大小
    int Instances;//单元个数
    struct NumNet net;
};


#endif //EDA_DATABASE_H
