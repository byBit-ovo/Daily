// 蛮力法求解任务分配问题：有n个任务需要分配给4n个人执行，每个任务只能分配给一个人，每个人只能执行一个任务。
// 第i个人执行第j个任务的成本是c[i][j]（1≤i，j≤n）。（见下图）分配方案就是由第i个人执行第j个任务，用（a1，a2，…，an）表示，
// 即第1个人执行第a1个任务，第2个人执行第a2个任务。求出总成本最小的分配方案并分析算法效率。

#include <vector>
#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;

class Solution
{
    vector<bool> hasAssigned;
    int people_count =0;
    int task_count = 0;
    int res = INT_MAX;
    int path = 0;
    int hasDispatched =0;
    int Assign_task(vector<vector<int>> cost)
    {
        people_count = cost.size();
        task_count = cost[0].size();
        hasAssigned.resize(task_count,false);
        dfs(cost,0);
        return res;
    }
    void dfs(vector<vector<int>>& cost,int row)
    {
        if(hasDispatched==task_count){
            res = min(res,path);
            return;
        }
        for(int i=0;i<task_count;++i)
        {
            if(hasAssigned[i]==true){
                continue;
            }
            //选择做当前任务的情况
            path+=cost[row][i];
            hasAssigned[i]=true;
            ++hasDispatched;
            dfs(cost,row+1);
            path-=cost[row][i];
            hasAssigned[i]=false;
            --hasDispatched;
            //不做当前任务的情况
            dfs(cost,row+1);
        }
    }

};
