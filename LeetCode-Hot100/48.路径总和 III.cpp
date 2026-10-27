// 方法一：深度优先搜索
// 思路与算法

// 我们首先想到的解法是穷举所有的可能，我们访问每一个节点 node，检测以 node 为起始节点且向下延深的路径有多少种。我们递归遍历每一个节点的所有可能的路径，然后将这些路径数目加起来即为返回结果。

// 我们首先定义 rootSum(p,val) 表示以节点 p 为起点向下且满足路径总和为 val 的路径数目。我们对二叉树上每个节点 p 求出 rootSum(p,targetSum)，然后对这些路径数目求和即为返回结果。

// 我们对节点 p 求 rootSum(p,targetSum) 时，以当前节点 p 为目标路径的起点递归向下进行搜索。假设当前的节点 p 的值为 val，我们对左子树和右子树进行递归搜索，对节点 p 的左孩子节点 p 
// l
// ​
  // 求出 rootSum(p 
// l
// ​
 // ,targetSum−val)，以及对右孩子节点 p 
// r
// ​
  // 求出 rootSum(p 
// r
// ​
 // ,targetSum−val)。节点 p 的 rootSum(p,targetSum) 即等于 rootSum(p 
// l
// ​
 // ,targetSum−val) 与 rootSum(p 
// r
// ​
 // ,targetSum−val) 之和，同时我们还需要判断一下当前节点 p 的值是否刚好等于 targetSum。

// 我们采用递归遍历二叉树的每个节点 p，对节点 p 求 rootSum(p,val)，然后将每个节点所有求的值进行相加求和返回。

class Solution 
{
public:
	// 从root这个起点往下，找路径和等于targetSum的路径数量（路径必须包含root）
    int rootSum(TreeNode* root, long long targetSum) 
	{
        if (!root) 
		{
            return 0;	// 节点为空，没有符合条件路径，返回0
        }

        int ret = 0;	// 记录当前起点下符合条件的路径总数
		
        if (root->val == targetSum) 
		{
            ret++;	// 当前节点值刚好等于剩余目标和，找到一条路径，计数+1
        } 

		// 往左子树找：目标和减去当前节点的值
        ret += rootSum(root->left, targetSum - root->val);
		
		// 往右子树找：目标和减去当前节点的值
        ret += rootSum(root->right, targetSum - root->val);
		
		// 返回这个起点下所有满足条件的路径条数
        return ret;
    }

	// 主函数：整棵树里，所有起点的符合条件路径总和
    int pathSum(TreeNode* root, int targetSum) 
	{
        if (!root) 
		{
            return 0;	// 树为空，直接返回0
        }
        
        int ret = rootSum(root, targetSum);	// 以当前root为起点查找
		
        ret += pathSum(root->left, targetSum);	// 递归：左子树里重新选起点查找
		
        ret += pathSum(root->right, targetSum);	// 递归：右子树里重新选起点查找
		
        return ret;
    }
};

// 复杂度分析

// 时间复杂度：O(N 
// 2
 // )，其中 N 为该二叉树节点的个数。对于每一个节点，求以该节点为起点的路径数目时，则需要遍历以该节点为根节点的子树的所有节点，因此求该路径所花费的最大时间为 O(N)，我们会对每个节点都求一次以该节点为起点的路径数目，因此时间复杂度为 O(N 
// 2
 // )。

// 空间复杂度：O(N)，考虑到递归需要在栈上开辟空间。