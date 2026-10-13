// 方法一：使用标记数组
// 思路和算法

// 我们可以用两个标记数组分别记录每一行和每一列是否有零出现。

// 具体地，我们首先遍历该数组一次，如果某个元素为 0，那么就将该元素所在的行和列所对应标记数组的位置置为 true。最后我们再次遍历该数组，用标记数组更新原数组即可。

class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
	{
        int m = matrix.size();	// m 获取矩阵行数
		
        int n = matrix[0].size();	// n 获取矩阵列数
		
        vector<int> row(m), col(n);	// row数组标记哪一行有0；col数组标记哪一列有0，初始默认都是0(false)
		
		// 第一轮遍历：找出所有含0的行和列，打上标记
        for (int i = 0; i < m; i++) 
		{
            for (int j = 0; j < n; j++) 
			{
                if (!matrix[i][j]) // 如果当前位置元素等于0
				{
                    row[i] = col[j] = true;	// 标记第i行、第j列需要全部置0
                }
            }
        }
		
		// 第二轮遍历：根据标记，把对应行列元素设为0
        for (int i = 0; i < m; i++) 
		{
            for (int j = 0; j < n; j++) 
			{
                if (row[i] || col[j]) // 当前行被标记 或者 当前列被标记
				{
                    matrix[i][j] = 0;	// 元素置0
                }
            }
        }
    }
};

// 复杂度分析

// 时间复杂度：O(mn)，其中 m 是矩阵的行数，n 是矩阵的列数。我们至多只需要遍历该矩阵两次。

// 空间复杂度：O(m+n)，其中 m 是矩阵的行数，n 是矩阵的列数。我们需要分别记录每一行或每一列是否有零出现。