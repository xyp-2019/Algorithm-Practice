// 方法一：使用额外的数组

// 我们可以使用额外的数组来将每个元素放至正确的位置。用 n 表示数组的长度，我们遍历原数组，将原数组下标为 i 的元素放至新数组下标为 (i+k)modn 的位置，最后将新数组拷贝至原数组即可。

class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
	{
        int n = nums.size();	// 获取数组nums的长度n
		
        vector<int> newArr(n);	// 创建一个大小为n的新数组newArr，用来存放旋转后的结果
		
        for (int i = 0; i < n; ++i) 
		{
			// 原下标i的元素，旋转k步后，新下标 = (i + k) % n
            // 取模%是为了下标超出数组长度时，回到数组头部
            newArr[(i + k) % n] = nums[i];
        }
		
		// 清空nums原有内容，把newArr全部元素拷贝覆盖到nums上
        nums.assign(newArr.begin(), newArr.end());
    }
};

// 举个小样例：nums=[1,2,3,4],k=2,n=4
// i=0：newArr [(0+2)%4]=newArr [2]=1
// i=1：newArr [3]=2
// i=2：newArr [0]=3
// i=3：newArr [1]=4
// newArr = [3,4,1,2]，覆盖 nums，完成右旋。

// 复杂度分析

// 时间复杂度： O(n)，其中 n 为数组的长度。

// 空间复杂度： O(n)。