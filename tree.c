#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TREE_SIZE 100
/*
 * 顺序存储二叉树结点
 * - data：结点数据
 * - used：当前位置是否有结点
 */
typedef struct {
    int data;
    bool used;//0无1有
} SeqTreeNode;//节点的定义

/*
 * 顺序存储二叉树
 * - nodes：结点数组
 * - size：数组最大容量
 */
typedef struct SeqBiTree{
    SeqTreeNode nodes[MAX_TREE_SIZE];
    int size;
} SeqBiTree;//树的定义
//为什么我的类型名在vscode里面没有高亮变色了
void init_tree(SeqBiTree *tree){
    for(int i=1;i<MAX_TREE_SIZE;i++)
    {  tree->nodes[i].data = 0;
       tree->nodes[i].used = 0;}
    tree->size=MAX_TREE_SIZE;//补上
}//初始化二叉树

bool set_root(SeqBiTree *tree, int value){
    tree->nodes[1].data = value;
    tree->nodes[1].used = 1;
    return 1;
}//创建ancester(这个函数感觉void也可以)

bool set_left_child(SeqBiTree *tree, int parent_node, int value){
    int tmp=parent_node*2;
    if(tmp >= MAX_TREE_SIZE)
     {return 0;}//可恶啊搞忘了
    if(tree->nodes[parent_node].used == 0) 
    {return 0;}

    tree->nodes[tmp].data = value;
    tree->nodes[tmp].used = 1;
    return 1;
}//左左左

bool set_right_child(SeqBiTree *tree, int parent_node, int value){
    int tmp = parent_node * 2 + 1;
    if(tmp >= MAX_TREE_SIZE)
    { return 0;}
    if(tree->nodes[parent_node].used == 0) 
    {return 0;}

    tree->nodes[tmp].data = value;
    tree->nodes[tmp].used = 1;
    return 1;
}//右右右

void level_order(SeqBiTree *tree){

    for(int i=1;i<MAX_TREE_SIZE;i++)
    {
        if(tree->nodes[i].used =1)
        {
            printf("第%d个位置数据为%d\n",i,tree->nodes[i].data);}
        else{
            printf("第%d节点空空如也\n",i);
        }
    }
}//cenxu遍历

