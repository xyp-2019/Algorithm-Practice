// 方法一：枚举
// 思路和算法

// 考虑以 i 结尾和为 k 的连续子数组个数，我们需要统计符合条件的下标 j 的个数，其中 0≤j≤i 且 [j..i] 这个子数组的和恰好为 k 。

// 我们可以枚举 [0..i] 里所有的下标 j 来判断是否符合条件，可能有读者会认为假定我们确定了子数组的开头和结尾，还需要 O(n) 的时间复杂度遍历子数组来求和，那样复杂度就将达到 O(n 
// 3
 // ) 从而无法通过所有测试用例。但是如果我们知道 [j,i] 子数组的和，就能 O(1) 推出 [j−1,i] 的和，因此这部分的遍历求和是不需要的，我们在枚举下标 j 的时候已经能 O(1) 求出 [j,i] 的子数组之和。
 
 class Solution 
 {
public:
	// 函数：寻找nums中和为k的子数组的数量，返回总数
    int subarraySum(vector<int>& nums, int k) 
	{
        const int n = nums.size();	// 获取数组长度n，const代表不可修改
		
        int count = 0;	// 计数器，记录满足条件的子数组个数，初始0
		
        int arr[n];	// 定义一个长度为n的局部数组arr（C99变长数组，LeetCode部分环境不推荐）
		
        for (int i = 0; i < n; i++) // 循环，把nums里面所有元素复制到arr数组
		{
            arr[i] = nums[i];
        }
		
		// start：子数组的起始下标
        for (int start = 0; start < nums.size(); ++start) 
		{
            int sum = 0;	// 每次更换start，累加和清零
			
			// end从start向前倒着遍历到0
            for (int end = start; end >= 0; --end) 
			{
                sum += arr[end];	// 不断累加当前arr[end]到sum
				
                if (sum == k) // 如果累加和等于目标k
				{
                    count++;	// 找到符合条件子数组，计数+1
                }
            }
        }
		
        return count;	// 返回最终统计到的子数组数量
    }
};

// 复杂度分析

// 时间复杂度：O(n 2)，其中 n 为数组的长度。枚举子数组开头和结尾需要 O(n 2) 的时间，其中求和需要 O(1) 的时间复杂度，因此总时间复杂度为 O(n 2)。

// 空间复杂度：O(1)。只需要常数空间存放若干变量。