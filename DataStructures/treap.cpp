#include <bits/stdc++.h>
using namespace std;
struct Treap{
    int x,y;
    Treap *left,*right;
    Treap(int v) x(v),y(rand()),left(nullptr),right(nullptr);
};
