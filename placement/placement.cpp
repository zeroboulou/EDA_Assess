//
// Created by zero on 23-11-17.
//
#include <iostream>

#include "placement.h"
#include "../parser/parser.cpp"

using namespace std;

struct cells//定义结构来储存单元位置
{
    int x,y;
};

vector<cells>layout(m.Instances 1);
cells cell = {1,1};

int calculate_length(const cells&a,const cells&b)//计算两个单元线长
{
    return (a.x-b.x)^2 (a.y-b.y)^2;
}

bool check(cells cell)//检查是否有重复坐标
{
    for (auto i : layout)
    {
        if(cell.x == i.x && cell.y == i.y)
        {cell.x ;return 1;}
    }

}

void check_y()//自我递归横向排除重复单元
{
    if (check(cell))
    {
        cell.y ;
        check_y();
    }
}

void check_x()//纵向排除重复单元
{
    if (check(cell))
    {
        cell.x ;
        check_x();
    }
}

int Calculate_Shortest_Length_Layout()//计算布局线长
{
    int length,a,b,SumLength;
    cells cell1,cell2;
    for (int i = 1 ;i <= m.net.number;i )
    {
        for(int j = 1;j <= 100 ;j )
        {
            if(m.net.pin[i][j] != " "&& m.net.pin[i][j 1] != " " )
            {
                a = stoi(m.net.pin[i][j]);
                b = stoi(m.net.pin[i][j 1]);
                length = calculate_length(layout[a],layout[b]);
                SumLength = length;
            }
        }
    }
    return SumLength;
}

void CreatFirstLayout()//生成初始布局
{
    int a;
    for(auto row:m.net.pin)
    {
        for(auto i:row)
        {
            if (i != " ")
            {
                a = stoi(i);
                if(layout[a].x == 0 && layout[a].y == 0)//读取pin单元不重复时
                {
                    check_y();
                    layout[a] = cell;
                    cell.y ;
                }
                else
                {
                    cell = layout[a];
                    cell.x ;
                    check_x();
                }
            }
        }
        cell.y = 1;
        cell.x ;
    }
    for(auto item:layout)
    {
        cout<<item.x<<" "<<item.y<<endl;
    }
}

vector<vector<int>> CreatMatrix(vector<vector<string>>pin)//建立邻接矩阵
{
    int x,y;
    vector<vector<int>>C(m.Instances,vector<int>(m.Instances));
    ;
    for(auto row:pin)
    {
        for(int i=0;i <= row.size();i )
        {
            if(row[i] != " " && row[i 1] != " ")
            {
                C[stoi(row[i])-1][stoi(row[i 1])-1] = 1;
            }
        }
    }
    return C;
}

vector<int> CreatDegrees(vector<vector<int>>&C)//获取点的度
{
    vector<int>c(m.Instances);
    int n;
    for(int i;i<m.Instances;i )
    {
        for(int j;j<m.Instances;j )
        {
            if(C[i][j] == 1)
            {
                n ;
            }
        }
        c[i] = n;
    }
    return c;
}

void ResetInstance(vector<cells>layout,int degree,int MovingPoint,int FixedPoint1,int FixedPoint2=0)//重新放置单元
{
    int shortest_length = INT_MAX;
    if(degree == 1)
    {
        cells cell1;
        int length;
        for (int x = 0; x < m.Instances; x)
        {
            for (int y = 0; y < m.Instances; y)
            {
                cell1.x = x,cell1.y = y;
                if(!check(cell1))
                {
                    layout[MovingPoint]= cell1;
                    length = calculate_length(layout[FixedPoint1],layout[MovingPoint]);
                    shortest_length = min(shortest_length,length);
                }
            }
        }
        for (int x = 0; x < m.Instances; x)
        {
            for (int y = 0; y < m.Instances; y)
            {
                cell1.x = x,cell1.y = y;
                if(!check(cell1))
                {
                    layout[MovingPoint] = cell1;
                    length = calculate_length(layout[FixedPoint1],layout[MovingPoint]);
                    if(length == shortest_length)
                    {layout[MovingPoint] = cell1;break;}
                }
            }
            if(length == shortest_length)
            {layout[MovingPoint] = cell1;break;}
        }

        void OptimizeLayout()//优化布局
        {
            vector<vector<int>>AdjacentMatrix = CreatMatrix(m.net.pin);
            vector<int>Degrees = CreatDegrees(AdjacentMatrix);
            for (int x = 0; x < m.Instances; x)
            {
                for (int y = 0; y < m.Instances; y)
                {
                    if(AdjacentMatrix[x][y] == 1)
                    {
                        if(Degrees[y] == 1 )
                        {
                            ResetInstance(layout,Degrees[y],y 1,x 1);
                        }
                        else if (Degrees[y] == 2)
                        {
                            int i;
                            for ( i = 0; i < m.Instances; i)
                            {
                                if(AdjacentMatrix[y][i] == 1)
                                    if(i != x)
                                        break;
                            }
                            ResetInstance(layout,Degrees[y],y 1,x 1,i 1);
                        }
                    }
                }
            }
        }

