
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "parser.h"
using namespace std;

int ReadFile()
{
    string file = R"(/home/zero/CLionProjects/EDA/build/input)";
    ifstream newfile (file) ;
    string line ;
    if (!newfile.is_open())
    {
        cout<<"无法打开文件"<<file<<endl;
        return 1;
    }
    while(getline(newfile,line))
    {
        GetData (line);//输入文件数据
    }
    GetSize();//布局器大小
    GetInstance();//单元个数
    GetNetNumber();//线网个数
    GetNet();//线网长度
    GetPin();//各个线网单元
    newfile.close();
    return 0;
}