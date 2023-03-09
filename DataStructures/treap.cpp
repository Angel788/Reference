#include <bits/stdc++.h>
using namespace std;
typedef struct Node *pitem;
struct Node{
    int value,key;
    pitem l,r;
    Node(int v) value(v),key(rand()),l(nullptr),r(nullptr);
};
struct treap
{
void split(pitem t, int value, pitem& left,pitem& right){
    if(!t) void(left=right=nullptr);
    if(t->value<=x) split(t->r,value,t->r,right),left=t;
    else split(t->l,value,left,t->l),right=t;
}
void marge(pitem t,pitem left,pitem right){
    if(!left || ! right){t=left?left:right;return;}
    if(left->key>right->key) marge(left->r,left->r,right), t=left;
    else marge(right->l,left,right->l), t=right;
}
void insert(pitem &t,pitem x){
    if(!t)t=x;
    else if(x->key>t->key){
        split(t,x->value,x->l,x->right), t=x;
    }
    else insert(x->value<t->value? t->l:t->r,x);
}   
};




