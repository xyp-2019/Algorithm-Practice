// 方法一：深度优先搜索
// 我们可以将二维网格看成一个无向图，竖直或水平相邻的 1 之间有边相连。

// 为了求出岛屿的数量，我们可以扫描整个二维网格。如果一个位置为 1，则以其为起始节点开始进行深度优先搜索。在深度优先搜索的过程中，每个搜索到的 1 都会被重新标记为 0。

// 最终岛屿的数量就是我们进行深度优先搜索的次数。

// 下面的动画展示了整个算法。

class Solution 
{
private:
	// dfs：把当前位置相连的陆地全部标记成水（'0'），避免重复统
    void dfs(vector<vector<char>>& grid, int r, int c) 
	{
        int nr = grid.size();	// 获取网格总行数
		
        int nc = grid[0].size();	// 获取网格总列数

        grid[r][c] = '0';	// 将当前陆地标记为水，代表已经访问过
		
		// 向上走：行不越界，且上方是陆地，继续递归
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
		
		// 向下走：行不越界，且下方是陆地，继续递归
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
		
		// 向左走：列不越界，且左边是陆地，继续递归
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
		
		// 向右走：列不越界，且右边是陆地，继续递归
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
    }

public:
	// 主函数：统计岛屿数量
    int numIslands(vector<vector<char>>& grid) 
	{
        int nr = grid.size();	// 网格行数
		
        if (!nr) return 0;	// 如果网格为空，直接返回0个岛屿
		
        int nc = grid[0].size();	// 网格列数

        int num_islands = 0;	// 岛屿计数器，初始为0
		
		// 遍历每一行
        for (int r = 0; r < nr; ++r) 
		{
			// 遍历当前行的每一列
            for (int c = 0; c < nc; ++c) 
			{
				// 找到一块未访问的陆地，说明发现新岛屿
                if (grid[r][c] == '1') 
				{
                    ++num_islands;	// 岛屿数量+1
					
                    dfs(grid, r, c);	// DFS把这块岛屿全部标记为已访问
                }
            }
        }

        return num_islands;	// 返回岛屿总数
    }
};

// 复杂度分析

// 时间复杂度：O(MN)，其中 M 和 N 分别为行数和列数。

// 空间复杂度：O(MN)，在最坏情况下，整个网格均为陆地，深度优先搜索的深度达到 MN。

// 方法二：广度优先搜索
// 同样地，我们也可以使用广度优先搜索代替深度优先搜索。

// 为了求出岛屿的数量，我们可以扫描整个二维网格。如果一个位置为 1，则将其加入队列，开始进行广度优先搜索。在广度优先搜索的过程中，每个搜索到的 1 都会被重新标记为 0。直到队列为空，搜索结束。

// 最终岛屿的数量就是我们进行广度优先搜索的次数。

class Solution 
{
public:
	// BFS版本：计算岛屿数量
    int numIslands(vector<vector<char>>& grid) 
	{
        int nr = grid.size();	// 获取网格的行数
		
        if (!nr) return 0;	// 行数为0，网格为空，直接返回0
		
        int nc = grid[0].size();	// 获取网格的列数

        int num_islands = 0;	// 岛屿计数器，初始0
		
		// 遍历每一行
        for (int r = 0; r < nr; ++r) 
		{
			// 遍历当前行每一列
            for (int c = 0; c < nc; ++c) 
			{
				// 找到一块未访问的陆地
                if (grid[r][c] == '1') 
				{
                    ++num_islands;	// 岛屿数量+1
					
                    grid[r][c] = '0';	// 标记当前陆地为已访问
					
                    queue<pair<int, int>> neighbors;	// 队列，存放待遍历的坐标
					
                    neighbors.push({r, c});	// 把当前坐标入队
					
					// 队列不为空，持续广度优先搜索
                    while (!neighbors.empty()) 
					{
                        auto rc = neighbors.front();	// 取出队首元素
						
                        neighbors.pop();	// 队首出队
						
                        int row = rc.first, col = rc.second;	// 拆分出行、列
						
						// 向上：不越界且是陆地
                        if (row - 1 >= 0 && grid[row-1][col] == '1') 
						{
                            neighbors.push({row-1, col});	// 坐标入队
							
                            grid[row-1][col] = '0';	// 标记已访问
                        }
						
						// 向下：不越界且是陆地
                        if (row + 1 < nr && grid[row+1][col] == '1') 
						{
                            neighbors.push({row+1, col});
							
                            grid[row+1][col] = '0';
                        }
						
						// 向左：不越界且是陆地
                        if (col - 1 >= 0 && grid[row][col-1] == '1') 
						{
                            neighbors.push({row, col-1});
							
                            grid[row][col-1] = '0';
                        }
						
						// 向右：不越界且是陆地
                        if (col + 1 < nc && grid[row][col+1] == '1') 
						{
                            neighbors.push({row, col+1});
							
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }

        return num_islands;	// 返回岛屿总数
    }
};

// 复杂度分析

// 时间复杂度：O(MN)，其中 M 和 N 分别为行数和列数。

// 空间复杂度：O(min(M,N))，在最坏情况下，整个网格均为陆地，队列的大小可以达到 min(M,N)。

class Solution 
{
public:
    int orangesRotting(vector<vector<int>>& grid) 
	{
        queue<pair<int,int>>q;	// 队列，存放腐烂橘子的坐标，BFS用
		
        int dirs[4][2]={{0,1},{0,-1},{1,0},{-1,0}};	// 四个方向：右、左、下、上
		
        int m=grid.size(),n=grid[0].size();	// m是行数，n是列数
		
        int cnt=0;	//新鲜橘子的数量
		
		// 遍历整个网格
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==2)	//找到第一轮腐烂橘子
                    q.push({i,j});
					
                else if(grid[i][j]==1)
                    cnt++;	// 统计新鲜橘子总数
		
		// 队列为空（没有腐烂橘子）但还有新鲜橘子 → 永远烂不掉
        if(q.empty()&&cnt)	//如果没有腐烂橘子并且有新鲜橘子，则新鲜橘子不可能腐烂
            return -1;
			
        int ans=0;	// 记录总时间
		
        while(!q.empty())	// BFS循环，一层一层扩散
        {
            int t=q.size();	//遍历同一时间感染的橘子
			
            for(int k=0;k<t;k++)
            {
                pair<int,int>p=q.front();	// 取出队首腐烂橘子坐标
				
                q.pop();	// 弹出队首
				
                for(auto dir:dirs)	// 遍历四个方向
                {
                    int x=p.first+dir[0];	// 新坐标x
					
                    int y=p.second+dir[1];	// 新坐标y
					
                    if(x>=0&&x<m&&y>=0&&y<n&&grid[x][y]==1)	//找到新感染的橘子
                    {
                        grid[x][y]=2;	// 标记为腐烂
						
                        q.push({x,y});	// 标记为腐烂
						
                        cnt--;	// 新鲜橘子数量减1
                    }
                }
            }
			
            if(!q.empty())//如果当前轮有新感染的橘子，时间加一
                ans++;
        }
		
        if(cnt)	//如果还有没被感染的新鲜橘子
            return -1;
			
        return ans;
    }
};

// 复杂度分析

// 时间复杂度：O(nm)。即进行一次广度优先搜索的时间，其中 n,m 分别为 grid 的行数与列数。

// 空间复杂度：O(nm)。需要额外的 dis 数组记录每个新鲜橘子被腐烂的最短时间，大小为 O(nm)，且广度优先搜索中队列里存放的状态最多不会超过 nm 个，最多需要 O(nm) 的空间，所以最后的空间复杂度为 O(nm)。