// 方法一：搜索回溯
// 思路与算法

// 对于这类寻找所有可行解的题，我们都可以尝试用「搜索回溯」的方法来解决。

// 回到本题，我们定义递归函数 dfs(target,combine,idx) 表示当前在 candidates 数组的第 idx 位，还剩 target 要组合，已经组合的列表为 combine。递归的终止条件为 target≤0 或者 candidates 数组被全部用完。那么在当前的函数中，每次我们可以选择跳过不用第 idx 个数，即执行 dfs(target,combine,idx+1)。也可以选择使用第 idx 个数，即执行 dfs(target−candidates[idx],combine,idx)，注意到每个数字可以被无限制重复选取，因此搜索的下标仍为 idx。

// 更形象化地说，如果我们将整个搜索过程用一个树来表达，即如下图呈现，每次的搜索都会延伸出两个分叉，直到递归的终止条件，这样我们就能不重复且不遗漏地找到所有可行解：

// 当然，搜索回溯的过程一定存在一些优秀的剪枝方法来使得程序运行得更快，而这里只给出了最朴素不含剪枝的写法，因此欢迎各位读者在评论区分享自己的见解。

class Solution 
{
public:
	// candidates：候选数字数组；target：剩余需要凑出来的值
    // ans：存放所有答案；combine：当前选中的数字组合；idx：当前考虑到的下标
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) 
	{
		// 下标越界，所有数字都考虑完了，直接返回
        if (idx == candidates.size()) 
		{
            return;
        }
		
		// target减到0，说明当前组合满足条件，存入结果
        if (target == 0) 
		{
            ans.emplace_back(combine);
			
            return;
        }
		
        // 方案1：不选当前这个数，直接去看下一个下标
        dfs(candidates, target, ans, combine, idx + 1);
		
        // 方案2：选当前这个数，前提是剩下的target够减
        if (target - candidates[idx] >= 0) 
		{
			// 把当前数字加入组合
            combine.emplace_back(candidates[idx]);
			
			// 递归：因为数字可以重复选，下标不变，target减去当前数
            dfs(candidates, target - candidates[idx], ans, combine, idx);
			
			// 回溯，撤销刚才选的数
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
	{
        vector<vector<int>> ans;	// 保存最终所有合法组合
		
        vector<int> combine;	// 保存正在搜索的组合
		
        dfs(candidates, target, ans, combine, 0);	// 从下标0开始搜索
		
        return ans;
    }
};

// 复杂度分析

// 时间复杂度：O(S)，其中 S 为所有可行解的长度之和。从分析给出的搜索树我们可以看出时间复杂度取决于搜索树所有叶子节点的深度之和，即所有可行解的长度之和。在这题中，我们很难给出一个比较紧的上界，我们知道 O(n×2 
// n
 // ) 是一个比较松的上界，即在这份代码中，n 个位置每次考虑选或者不选，如果符合条件，就加入答案的时间代价。但是实际运行的时候，因为不可能所有的解都满足条件，递归的时候我们还会用 target−candidates[idx]≥0 进行剪枝，所以实际运行情况是远远小于这个上界的。

// 空间复杂度：O(target)。除答案数组外，空间复杂度取决于递归的栈深度，在最差情况下需要递归 O(target) 层