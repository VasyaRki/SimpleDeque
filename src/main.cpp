#include "include/deque.h"

#include <iostream>

using namespace std;

int main()
{
    deque<int> a;
    for (int i = 0; i < 5; i++)
        a.push_back(i);
    a.show();
    a.pop_back();
    a.show();
    a.pop_front();
    a.show();
}