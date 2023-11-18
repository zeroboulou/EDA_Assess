//
// Created by zero on 23-11-17.
//

#ifndef EDA_PARSER_H
#define EDA_PARSER_H

#include <string>
#include <cctype>
#include <fstream>
#include <vector>

#include "../database/database.h"

using namespace std;
struct data m;

bool is_digit(char c)//判断字符串中的数字字符
{
    return isdigit(c);
}

void GetData (string line)//获取所有数据
{
    for (char i:line)
    {
        if (is_digit(i))
        {
            m.data1.push_back(i);
        }
    }
}

void GetSize()//获取布局器大小
{
    for(int i=0;i<2;i )
    {
        m.DieSize[i] = m.data1[i];
    }
}

void GetInstance()//获取单元个数
{
    m.Instances = m.data1[2];
}

void GetNetNumber()//获取线网个数
{
    m.net.number = m.data1[11];
}

void GetNet()//获取每个线网长度
{
    int sum=0;
    m.net.NetSum.assign(1,0);
    m.net.Net.resize(m.net.number);
    try
    {
        for(int n=1;n<=m.net.number;n )
        {
            m.net.Net[n] = m.data1[2*n sum 11];
            auto b = stoi(m.net.Net[n]);
            sum = b;
            m.net.NetSum.push_back(sum);
        }
    }
    catch (const invalid_argument&e)
    {
        cerr<<"Invalid argument:"<<e.what()<<endl;
    }
}

void GetPin ()//获取每个线网的单元
{

    try
    {
        for (int i = 1;i<=m.net.number; i )
        {
            vector<string>x(100);
            auto a = stoi(m.net.Net[i]);
            auto b = m.net.NetSum[i-1];
            for(int j = 1;j <= stoi(m.net.Net[i]);j )
            {
                x[j] = m.data1[m.net.NetSum[i-1] j 2*i 11];
            }
            m.net.pin.push_back(x);

        }
    }
    catch (const invalid_argument&e)
    {
        cerr<<"Invalid argument:"<<e.what()<<endl;
    }
    auto d = m.net.pin;
    for(const auto&row:d)
    {for(const auto&i : row)
        {
            cout<<i<<" ";
        }
        cout << endl;
    }

}

#endif //EDA_PARSER_H
