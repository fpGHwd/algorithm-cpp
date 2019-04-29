//
// Created by suzumiya on 4/12/19.
//

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/** 请完成下面这个函数，实现题目要求的功能 **/
/** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
int getPathCount(int bridgeList_size, char** bridgeList, char* command) {

    return 0;
}

int main() {
    int res;

    int _bridgeList_size = 0;
    int _bridgeList_i;
    scanf("%d\n", &_bridgeList_size);
    char* _bridgeList[_bridgeList_size];
    for(_bridgeList_i = 0; _bridgeList_i < _bridgeList_size; _bridgeList_i++) {
        char* _bridgeList_item;
        _bridgeList_item = (char *)malloc(512000 * sizeof(char));
        scanf("\n%[^\n]", &_bridgeList_item);

        _bridgeList[_bridgeList_i] = _bridgeList_item;
    }
    char* _command;
    _command = (char *)malloc(512000 * sizeof(char));
    scanf("\n%[^\n]",_command); // 命令

    res = getPathCount(_bridgeList_size, _bridgeList, _command);
    printf("%d\n", res);

    return 0;

}