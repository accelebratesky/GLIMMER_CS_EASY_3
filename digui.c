# include<stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;                       // 节点存储的数据
    struct TreeNode *left;          // 左子树指针
    struct TreeNode *right;         // 右子树指针
} TreeNode;
//顺序栈
typedef struct Stack {
    TreeNode **arr;//指针数组，高级；结构体里的arr只是一个指针变量，此时它还没有数组空间
    int top;//最外面的节点的号（-1是空）
    int capacity;//最大了，再多撑不下
} Stack;
Stack *createStack(int capacity) {
    Stack *stack = malloc(sizeof(Stack));//申请8+4+4=16的空间
    stack->arr = malloc(sizeof(TreeNode *) * capacity);//真正开辟数组，想要多大就多大
    stack->top = -1;//暂无
    stack->capacity = capacity;
    return stack;
}//让我们创建一个新栈吧 
int isEmpty(Stack *stack) {
    return stack->top == -1;//简便的写法
}//你空不空
void push(Stack *stack, TreeNode *node) {
    if (stack->top == stack->capacity - 1) {
        return;
    }//吃不下了（-1是空哦，所以这里是-1）
    stack->arr[++stack->top] = node;//我吃，前置自增
}//节点来
TreeNode *pop(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }//被掏空了
    return stack->arr[stack->top--];//我吐，后置自减(只是逻辑上不在属于，下回加的时候会直接覆盖，如果free这个空间就没啦！！可以手动置空=NULL)
}//节点滚


/*
void preorderTraversal(TreeNode *root)// 补全这个函数 ok
{
    if(root == NULL) return; //刚开始忘了
    Stack *newst = createStack(100);
    TreeNode* tmp = root;

    while(!isEmpty(newst) || tmp != NULL)
    {
        for(;;)
        {
            printf("%d ", tmp->data);
            push(newst, tmp);
            if(tmp->left == NULL) break;
            tmp = tmp->left;
        }
        tmp = pop(newst);
        tmp = tmp->right;
    }
}//栈操作二叉树前序遍历，遍历的英文是traversal
*/
void preorderTraversal(TreeNode *root) 
{   
     if(root == NULL) return;//刚开始忘了
    Stack *newst = createStack(100);
    TreeNode* tmp=root;
    
    while(!isEmpty(newst) || tmp != NULL)
    {
       for(;tmp!=NULL;tmp=tmp->left)
        {
            printf("%d ",tmp->data);
            push(newst,tmp);
        }
        tmp=pop(newst);
        tmp=tmp->right;
    }
   
}//栈操作二叉树前序遍历，遍历的英文是traversal
void inorderTraversal(TreeNode *root)
{
    if(root == NULL) return;
    Stack *newst = createStack(100);
    TreeNode* tmp=root;

    while(!isEmpty(newst)||tmp!= NULL)
    {
        for(;tmp!= NULL;tmp=tmp->left)
        {
            push(newst,tmp);
        }
        tmp=pop(newst);
        printf("%d ",tmp->data); 
        tmp=tmp->right;
    }
}//思考了一下中序遍历，好像和递归一样改个位置
