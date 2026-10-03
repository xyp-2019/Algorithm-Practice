// 方法一：暴力枚举
// 思路及算法

// 最容易想到的方法是枚举数组中的每一个数 x，寻找数组中是否存在 target - x。

// 当我们使用遍历整个数组的方式寻找 target - x 时，需要注意到每一个位于 x 之前的元素都已经和 x 匹配过，因此不需要再进行匹配。而每一个元素不能被使用两次，所以我们只需要在 x 后面的元素中寻找 target - x。

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target)	// 给了数组及其要求和的目标
	{
        int n = nums.size();	// 计算数组长度
        for (int i = 0; i < n; ++i)	// 第一层循环遍历数组所有元素
		{
            for (int j = i + 1; j < n; ++j) // 第二层循环，遍历当前元素的后面所有元素
			{
                if (nums[i] + nums[j] == target) // 判断当前遍历到的两个数之和是否为目标
				{
                    return {i, j};	// 如果是目标的话，那么就返回当前元素分别对应的下标
                }
            }
        }
        return {};	// 循环结束都没有遍历到对应的结果，那么整个数组就不存在结果，返回空下标
    }
};

// 复杂度分析

// 时间复杂度：O(N*N)，其中 N 是数组中的元素数量。最坏情况下数组中任意两个数都要被匹配一次。

// 空间复杂度：O(1)。



// 方法二：哈希表
// 思路及算法

// 注意到方法一的时间复杂度较高的原因是寻找 target - x 的时间复杂度过高。因此，我们需要一种更优秀的方法，能够快速寻找数组中是否存在目标元素。如果存在，我们需要找出它的索引。

// 使用哈希表，可以将寻找 target - x 的时间复杂度降低到从 O(N) 降低到 O(1)。

// 这样我们创建一个哈希表，对于每一个 x，我们首先查询哈希表中是否存在 target - x，然后将 x 插入到哈希表中，即可保证不会让 x 和自己匹配。

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
	{
		// unordered_map 就是C++的哈希表（哈希容器）
		// 模板第一个 int：key（键）的类型，存数组里面的数字
		// 模板第二个 int：value（值）的类型，存数字对应的数组下标
		// hashtable是变量名字，你可以改名，比如叫 mp
        unordered_map<int, int> hashtable;
		
		// 遍历数组，i 是当前元素的下标，nums[i] 是当前数字。
        for (int i = 0; i < nums.size(); ++i) 
		{
			// 1. `target - nums[i]`：需要寻找的另一半目标数字
			// 2. `.find(要查找的key)`：哈希表成员函数，用于在哈希表内查找指定 key
			// 3. 返回值`it`：迭代器 iterator，可以理解为指向哈希表中某条记录的指针
			// 4. `auto`：自动推导变量类型，等价完整写法：`unordered_map<int,int>::iterator it`
			// # find () 函数两种执行结果
			// 1. 成功找到 key：it 指向哈希表中对应的 key‑value 键值对记录
			// 2. 未找到 key：`it == hashtable.end()`，end () 代表哈希表末尾，是不存在实际元素的位置
			// 千万不要写 `if(it)`，哈希迭代器不能直接判断真假，C++ 必须和`.end()`对比。
            auto it = hashtable.find(target - nums[i]);
			
			// 1. it 是迭代器，用法类似指针
			// it->first：获取这条记录的 key，也就是数组里存的数值
			// it->second：获取这条记录的 value，也就是保存的数组下标
            if (it != hashtable.end()) 
			{
				// 找到目标元素之后，直接返回两个下标：历史下标 it->second，当前下标 i
                return {it->second, i};
            }
			
			// 把数组数值 nums [i] 作为 key，数组下标 i 作为 value，存入哈希表。
            hashtable[nums[i]] = i;
        }
		
		// 题目保证一定有解，这行只是语法要求，防止函数没有返回值报错。`{}`代表空的vector。
        return {};
    }
};

// 复杂度分析

// 时间复杂度：O(N)，其中 N 是数组中的元素数量。对于每一个元素 x，我们可以 O(1) 地寻找 target - x。

// 空间复杂度：O(N)，其中 N 是数组中的元素数量。主要为哈希表的开销。