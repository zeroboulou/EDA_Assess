//
// Created by zero on 23-11-17.
//

#ifndef EDA_PLACEMENT_H
#define EDA_PLACEMENT_H
#include <vector>

#include "../parser/parser.h"


using namespace std;


vector<cells>layout(m.Instances 1);
cells cell = {1,1};

int calculate_length(const cells&a,const cells&b);//计算两个单元线长


bool check(cells cell);//检查是否有重复坐标


void check_y();//自我递归横向排除重复单元



void check_x();//纵向排除重复单元


int Calculate_Shortest_Length_Layout();//计算布局线长



void CreatFirstLayout();//生成初始布局


vector<vector<int>> CreatMatrix(vector<vector<string>>pin);//建立邻接矩阵


vector<int> CreatDegrees(vector<vector<int>>&C);//获取点的度


void ResetInstance(vector<cells>layout,int degree,int MovingPoint,int FixedPoint1,int FixedPoint2=0);//重新放置单元


void OptimizeLayout();//优化布局

#endif //EDA_PLACEMENT_H
