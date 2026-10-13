// 方法一：模拟
// 可以模拟螺旋矩阵的路径。初始位置是矩阵的左上角，初始方向是向右，当路径超出界限或者进入之前访问过的位置时，顺时针旋转，进入下一个方向。

// 判断路径是否进入之前访问过的位置需要使用一个与输入矩阵大小相同的辅助矩阵 visited，其中的每个元素表示该位置是否被访问过。当一个元素被访问时，将 visited 中的对应位置的元素设为已访问。

// 如何判断路径是否结束？由于矩阵中的每个元素都被访问一次，因此路径的长度即为矩阵中的元素数量，当路径的长度达到矩阵中的元素数量时即为完整路径，将该路径返回。

class Solution 
{
private:
	// 4个方向：右、下、左、上
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
	{
		// 空矩阵直接返回空
        if (matrix.size() == 0 || matrix[0].size() == 0) 
		{
            return {};
        }
        
        int rows = matrix.size(), columns = matrix[0].size();	// rows行数，columns列数
		
        vector<vector<bool>> visited(rows, vector<bool>(columns));	// visited标记该位置是否已经走过
		
        int total = rows * columns;	// 矩阵元素总个数，循环一共跑total次
		
        vector<int> order(total);	// 保存最终螺旋遍历结果

        int row = 0, column = 0;	// 当前所在位置，起点(0,0)
		
        int directionIndex = 0;	// 方向下标，0代表向右
		
        for (int i = 0; i < total; i++) 
		{
            order[i] = matrix[row][column];	// 把当前位置的值放进结果数组
			
            visited[row][column] = true;	// 标记当前格子已经访问过
			
			// 计算按照当前方向往前走一步，得到下一个位置
            int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
			
			// 判断：下一个位置越界 或者 已经被访问过 → 需要顺时针换方向
            if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) 
			{
                directionIndex = (directionIndex + 1) % 4;
            }
			// 更新当前坐标，向新方向走一步
            row += directions[directionIndex][0];
            column += directions[directionIndex][1];
        }
		
        return order;
    }
};

// ## 示例矩阵（我们模拟跑一遍）

// ```
// matrix = [
 // [1, 2, 3],
 // [4, 5, 6],
 // [7, 8, 9]
// ]
// ```

// 预期输出：`[1,2,3,6,9,8,7,4,5]`
// 总元素 `total=9`，循环 i 从 0 到 8

// > 
// > directions 顺序：0 向右 {0,1}，1 向下 {1,0}，2 向左 {0,-1}，3 向上 {-1,0}

// ### 一步步模拟

// 初始状态：`row=0, col=0，directionIndex=0（向右）`
// visited 全部是 false

// 1. i=0：当前 (0,0)=1
// order [0]=1，visited [0][0]=true
// next = (0, 1)，合法没访问，**不换方向**
// row=0, col=1
// 2. i=1：当前 (0,1)=2
// order [1]=2，visited [0][1]=true
// next=(0,2)，合法，不换方向
// row=0, col=2
// 3. i=2：当前 (0,2)=3
// order [2]=3，visited [0][2]=true
// next=(0,3)，**列 3 超出边界（最大列下标是 2）**
// → 切换方向 `directionIndex = (0+1)%4=1`（改成向下）
// row=1, col=2
// 4. i=3：当前 (1,2)=6
// order [3]=6，visited [1][2]=true
// next=(2,2) 合法，方向不变（向下）
// row=2, col=2
// 5. i=4：当前 (2,2)=9
// order [4]=9，visited [2][2]=true
// next=(3,2)，行越界，切换方向`directionIndex=2`（向左）
// row=2, col=1
// 6. i=5：当前 (2,1)=8
// order [5]=8，visited [2][1]=true
// next=(2,0) 合法，继续向左
// row=2, col=0
// 7. i=6：当前 (2,0)=7
// order [6]=7，visited [2][0]=true
// next=(2,-1) 列越界，切换方向`directionIndex=3`（向上）
// row=1, col=0
// 8. i=7：当前 (1,0)=4
// order [7]=4，visited [1][0]=true
// next=(0,0)，**已经被 visited 访问过**，切换方向`directionIndex=0`（向右）
// row=1, col=1
// 9. i=8：当前 (1,1)=5
// order [8]=5，visited [1][1]=true
// next=(1,2)，已经访问过，切换方向`directionIndex=1`
// row=2, col=1

// 循环结束，最终 order = `[1,2,3,6,9,8,7,4,5]`

// 复杂度分析

// 时间复杂度：O(mn)，其中 m 和 n 分别是输入矩阵的行数和列数。矩阵中的每个元素都要被访问一次。

// 空间复杂度：O(mn)。需要创建一个大小为 m×n 的矩阵 visited 记录每个位置是否被访问过。