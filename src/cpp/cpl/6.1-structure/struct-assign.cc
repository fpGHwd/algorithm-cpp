//
// Created by suzumiya on 10/2/19.
//

struct inner{
    int m;
    int n;
};

struct point{
    int x;
    int y;
    struct inner z;
};

int main(){
    struct point a,b;
    a.x = 5;
    a.y = 4;
    struct inner p;
    p.m =1; p.n =2;
    a.z = p;
    b = a;

    struct point c = a;

    // 是浅拷贝的一种
    return 0;
}