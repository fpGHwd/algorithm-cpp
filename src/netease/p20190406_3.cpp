//
// Created by suzumiya on 4/6/19.
//


#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

float bat_cap[210];
float charge_time[210];
vector<int> connect[210];
//priority_queue<int> now_charge;
int now_charge[210], now_charge_size;

int main(int argc, char **argv){
    int T;
    scanf("%d", &T);
    int N,M,B,E;

    for(int i = 0; i< T; i++){
        charge_time[i] = -1.0;
    }

    for(int i = 0; i<T; i++){
        scanf("%d %d %d %d", &N, &M, &B,&E);
        for(int i = 0; i < N; i++){
            scanf("%d", bat_cap+i);
        }
        int start, end;
        for(int i = 0; i< M; i++){
            scanf("%d %d", &start,&end);
            connect[start].push_back(end);
        }

        now_charge[now_charge_size++] = B;
        while(now_charge_size > 0){
            int first = 0, need_least = bat_cap[now_charge[0]];
            for(int i = 0; i< now_charge_size; i++){
                if(bat_cap[now_charge[i]] < need_least)first = i;
            }

            float time = bat_cap[now_charge[i]] /(E /now_charge_size);
//            for(int i = 0; i< bat)

//            charge_time[max] = bat_cap[max] * 1.0 * E / now_charge.size();
            // 处理队列中的电池 - 正在充电的电池的充满还需多少容量。
            // 不能迭代啊。
//            for(auto it = connect[max].begin(); it< connect[max].end(); it++){
//                now_charge.push(*it);
//            }
//            now_charge.pop();
        }

        for(int i = 0; i< N; i++){
            if(i!= 0)printf(" ");
            printf("%.4f", charge_time[i]);
        }

    }


    return 0;
}