// 方法一：递归
// 思路与算法

// 首先我们需要了解什么是二叉树的中序遍历：按照访问左子树——根节点——右子树的方式遍历这棵树，而在访问左子树或者右子树的时候我们按照同样的方式遍历，直到遍历完整棵树。因此整个遍历过程天然具有递归的性质，我们可以直接用递归函数来模拟这一过程。

// 定义 inorder(root) 表示当前遍历到 root 节点的答案，那么按照定义，我们只要递归调用 inorder(root.left) 来遍历 root 节点的左子树，然后将 root 节点的值加入答案，再递归调用inorder(root.right) 来遍历 root 节点的右子树即可，递归终止的条件为碰到空节点。

class Solution 
{
public:
	// 递归辅助函数：中序遍历，结果存入res数组
    void inorder(TreeNode* root, vector<int>& res) 
	{
		// 如果当前节点是空，直接返回，递归终止条件
        if (!root) 
		{
            return;
        }
		
		// 递归遍历左子树（中序：左→根→右，先左）
        inorder(root->left, res);
		
		// 访问当前根节点，把节点值放进结果数组
        res.push_back(root->val);
		
		// 递归遍历右子树（最后访问右）
        inorder(root->right, res);
    }
	
	// 主函数：返回二叉树的中序遍历结果
    vector<int> inorderTraversal(TreeNode* root) 
	{
		// 定义一个vector用来存放遍历得到的值
        vector<int> res;
		
		// 调用递归函数开始遍历
        inorder(root, res);
		
		// 返回最终遍历结果
        return res;
    }
};

// 复杂度分析

// 时间复杂度：O(n)，其中 n 为二叉树节点的个数。二叉树的遍历中每个节点会被访问一次且只会被访问一次。

// 空间复杂度：O(n)。空间复杂度取决于递归的栈深度，而栈深度在二叉树为一条链的情况下会达到 O(n) 的级别。

// 方法二：迭代
// 思路与算法

// 方法一的递归函数我们也可以用迭代的方式实现，两种方式是等价的，区别在于递归的时候隐式地维护了一个栈，而我们在迭代的时候需要显式地将这个栈模拟出来，其他都相同，具体实现可以看下面的代码。

class Solution 
{
public:
	// 二叉树中序遍历 迭代写法（栈实现）
    vector<int> inorderTraversal(TreeNode* root) 
	{
        vector<int> res;	// 存放遍历结果
		
        stack<TreeNode*> stk;	// 栈，用来暂存节点，代替递归
		
		// 循环条件：节点不为空 或者 栈里面还有节点没处理
        while (root != nullptr || !stk.empty()) 
		{
			// 一直往左走，把沿途节点全部压入栈
            while (root != nullptr) 
			{
                stk.push(root);	// 当前节点入栈
				
                root = root->left;	// 移动到左孩子
            }
			
            root = stk.top();	// 取出栈顶节点
			
            stk.pop();	// 栈顶节点弹出
			
            res.push_back(root->val);	// 记录该节点的值（访问根）
			
            root = root->right;	// 转向右子树，下一轮处理右分支
        }
		
        return res;	// 返回中序遍历结果
    }
};

// 复杂度分析

// 时间复杂度：O(n)，其中 n 为二叉树节点的个数。二叉树的遍历中每个节点会被访问一次且只会被访问一次。

// 空间复杂度：O(n)。空间复杂度取决于栈深度，而栈深度在二叉树为一条链的情况下会达到 O(n) 的级别。