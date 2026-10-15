// 方法一：直接查找
// 思路与算法

// 我们直接遍历整个矩阵 matrix，判断 target 是否出现即可。

class Solution 
{
public:
	// 函数：在二维矩阵matrix中查找target，找到返回true，找不到返回false
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
	{
		// 遍历matrix里的每一行row
        for (const auto& row: matrix) 
		{
			// 遍历当前行里的每一个元素element
            for (int element: row) 
			{
				// 判断当前元素是否等于目标值
                if (element == target) 
				{
					// 找到目标，直接返回true，结束函数
                    return true;
                }
            }
        }
		
		// 全部遍历完都没找到目标，返回false
        return false;
    }
};

// 复杂度分析

// 时间复杂度：O(mn)。

// 空间复杂度：O(1)。