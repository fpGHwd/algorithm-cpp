//
// Created by suzumiya on 9/28/19.
//

#include <vector>
#include <iostream>

using namespace std;

void print_size_capacity(vector<int> vec)
{
    cout << "size: " << vec.size() << ", capacity: " << vec.capacity() << endl;
}

int main(int argc, char **argv)
{
    vector<int> vec;
    print_size_capacity(vec);

    for(int i = 0; i < 10000 ; i++)
    {
        vec.push_back(1);
        print_size_capacity(vec);
    }


}