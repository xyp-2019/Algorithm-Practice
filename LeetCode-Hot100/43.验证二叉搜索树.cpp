方法一: 递归
思路和算法

要解决这道题首先我们要了解二叉搜索树有什么性质可以给我们利用，由题目给出的信息我们可以知道：如果该二叉树的左子树不为空，则左子树上所有节点的值均小于它的根节点的值； 若它的右子树不空，则右子树上所有节点的值均大于它的根节点的值；它的左右子树也为二叉搜索树。

这启示我们设计一个递归函数 helper(root, lower, upper) 来递归判断，函数表示考虑以 root 为根的子树，判断子树中所有节点的值是否都在 (l,r) 的范围内（注意是开区间）。如果 root 节点的值 val 不在 (l,r) 的范围内说明不满足条件直接返回，否则我们要继续递归调用检查它的左右子树是否满足，如果都满足才说明这是一棵二叉搜索树。

那么根据二叉搜索树的性质，在递归调用左子树时，我们需要把上界 upper 改为 root.val，即调用 helper(root.left, lower, root.val)，因为左子树里所有节点的值均小于它的根节点的值。同理递归调用右子树时，我们需要把下界 lower 改为 root.val，即调用 helper(root.right, root.val, upper)。

函数递归调用的入口为 helper(root, -inf, +inf)， inf 表示一个无穷大的值。

class Solution 
{
public:
	// 辅助函数：判断以root为根的子树，所有节点值必须在(lower, upper)区间内
    bool helper(TreeNode* root, long long lower, long long upper) 
	{
		// 空节点，合法，返回true
        if (root == nullptr) 
		{
            return true;
        }
		
		// 当前节点的值超出规定区间，不是二叉搜索树，返回false
        if (root -> val <= lower || root -> val >= upper) 
		{
            return false;
        }
		
		// 左子树：上限更新为当前节点值；右子树：下限更新为当前节点值，左右都合法才返回true
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
    }
	
	// 主函数：校验整棵树是否是二叉搜索树
    bool isValidBST(TreeNode* root) 
	{
		// 初始范围：最小值~最大值，没有边界限制
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

// 复杂度分析

// 时间复杂度：O(n)，其中 n 为二叉树的节点个数。在递归调用的时候二叉树的每个节点最多被访问一次，因此时间复杂度为 O(n)。

// 空间复杂度：O(n)，其中 n 为二叉树的节点个数。递归函数在递归过程中需要为每一层递归函数分配栈空间，所以这里需要额外的空间且该空间取决于递归的深度，即二叉树的高度。最坏情况下二叉树为一条链，树的高度为 n ，递归最深达到 n 层，故最坏情况下空间复杂度为 O(n) 。