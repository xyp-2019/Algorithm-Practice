// 方法一：前序遍历
// 将二叉树展开为单链表之后，单链表中的节点顺序即为二叉树的前序遍历访问各节点的顺序。因此，可以对二叉树进行前序遍历，获得各节点被访问到的顺序。由于将二叉树展开为链表之后会破坏二叉树的结构，因此在前序遍历结束之后更新每个节点的左右子节点的信息，将二叉树展开为单链表。

// 对二叉树的前序遍历不熟悉的读者请自行练习「144. 二叉树的前序遍历」。

// 前序遍历可以通过递归或者迭代的方式实现。以下代码通过递归实现前序遍历。

class Solution 
{
public:
    void flatten(TreeNode* root) 
	{
        vector<TreeNode*> l;	// 定义vector，用来按前序顺序存放二叉树各个节点的指针
		
        preorderTraversal(root, l);	// 调用前序遍历函数，把所有节点存入l
		
        int n = l.size();	// 获取一共有多少个节点
		
        for (int i = 1; i < n; i++) // 从第二个节点开始循环，逐个拼接链表
		{
            TreeNode *prev = l.at(i - 1), *curr = l.at(i);	// prev取上一个节点，curr取当前节点
			
            prev->left = nullptr;	// 前一个节点左指针置空，链表不需要左子树
			
            prev->right = curr;	// 前一个节点的右指针指向当前节点，完成串联
        }
    }

    void preorderTraversal(TreeNode* root, vector<TreeNode*> &l) // 前序遍历函数，引用传递vector
	{
        if (root != NULL) // 如果当前节点不为空
		{
            l.push_back(root);	// 先把根节点放入容器（前序：先根）
			
            preorderTraversal(root->left, l);	// 递归遍历左子树
			
            preorderTraversal(root->right, l);	// 递归遍历右子树
        }
    }
};
