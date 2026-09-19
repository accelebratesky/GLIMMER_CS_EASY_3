#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;                       // 节点存储的数据
    struct TreeNode *left;          // 左子树指针
    struct TreeNode *right;         // 右子树指针
} TreeNode;
TreeNode* create_node(int value){
    TreeNode* node=(TreeNode*)malloc(sizeof(TreeNode));
    node->data=value;
    node->left=NULL;
    node->right=NULL;
    return node;
} //new node wow模仿链表写即可
void connect(TreeNode* parent,TreeNode* songirl,int way){
    if(way==0)//左0右1
    {parent->left=songirl;}
    else
    {parent->right=songirl;}
}//笑死我了
//下面的是我在菜鸟驿站看后自己再敲一遍
void test(TreeNode* root){
     for(;root!=NULL;root=root->left){
        printf("%d ", root->data);   
     }
      for(;root!=NULL;root=root->right){
        printf("%d ", root->data);   
     }

}
// 前序遍历：根左右
void preOrder(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);   
    preOrder(root->left);       
    preOrder(root->right);      
}

//中序遍历：左根右
void inOrder(TreeNode* root) {
    if (root == NULL) return;
    inOrder(root->left);        
    printf("%d ", root->data);   
    inOrder(root->right);       
}

//后序遍历：左右根
void postOrder(TreeNode* root) {
    if (root == NULL) return;
    postOrder(root->left);      
    postOrder(root->right);     
    printf("%d ", root->data);  
}
/*
void depth(TreeNode *root, int current_depth, int max_depth){
    
    
    if (root == NULL) 
        return; 
    current_depth++;
    printf("Now the depth is:%d ",current_depth);
    depth(root->left,current_depth,100);       
    depth(root->right,current_depth,100);  

}*/
    //给遍历加一个输出层数辅助观察一下
int depth(TreeNode *root, int current_depth, int max_depth){
    if (root == NULL)  return max_depth; 
    current_depth++;
    //printf("Now the depth is:%d ",current_depth);//给你也加一个，写完屏蔽
    int left_depth=depth(root->left,current_depth,max_depth);     
    int right_depth=depth(root->right,current_depth,max_depth); 
    if(current_depth >max_depth){
        max_depth=current_depth;
    }
    if(left_depth > max_depth)
        max_depth =left_depth;
    if(right_depth> max_depth)
        max_depth= right_depth;
    return max_depth;

}
int main(){
   TreeNode*node1=create_node(1);
   TreeNode*node2=create_node(2);
   TreeNode*node3=create_node(3);
   TreeNode*node4=create_node(4);
   TreeNode*node5=create_node(5);
   TreeNode*node6=create_node(6);
   TreeNode*node7=create_node(7);
   connect(node1,node2,0);
   connect(node1,node3,1);
   connect(node2,node4,0);
   connect(node2,node5,1);
   connect(node3,node6,0);
   connect(node3,node7,1);
   //我自己都忍不住想笑，我建的好弱智啊
   test(node1);
   preOrder(node1);
   inOrder(node1);
   postOrder(node1);
   int result=depth(node1,0,0);
   printf("The final answer is %d",result);
   //为了再验证一下我的代码，把菜鸟驿站的树搬过来
   /* 构建如下二叉树:
           1
          / \
         2   3
        / \
       4   5   */
    TreeNode* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    int result2=depth(root,0,0);
   printf("The final answer is %d",result2);
   return 0;

   



    







}