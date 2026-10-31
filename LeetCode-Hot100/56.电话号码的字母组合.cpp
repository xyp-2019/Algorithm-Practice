// 方法一：回溯
// 首先使用哈希表存储每个数字对应的所有可能的字母，然后进行回溯操作。

// 回溯过程中维护一个字符串，表示已有的字母排列（如果未遍历完电话号码的所有数字，则已有的字母排列是不完整的）。该字符串初始为空。每次取电话号码的一位数字，从哈希表中获得该数字对应的所有可能的字母，并将其中的一个字母插入到已有的字母排列后面，然后继续处理电话号码的后一位数字，直到处理完电话号码中的所有数字，即得到一个完整的字母排列。然后进行回退操作，遍历其余的字母排列。

// 回溯算法用于寻找所有的可行解，如果发现一个解不可行，则会舍弃不可行的解。在这道题中，由于每个数字对应的每个字母都可能进入字母组合，因此不存在不可行的解，直接穷举所有的解即可。

class Solution 
{
public:
	// 主函数：输入数字字符串，返回所有字母组合
    vector<string> letterCombinations(string digits) 
	{
		// 存放最终所有组合结果
        vector<string> combinations;
		
		// 如果输入是空字符串，直接返回空结果
        if (digits.empty()) 
		{
            return combinations;
        }
		
		// 建立数字到对应字母的映射
        unordered_map<char, string> phoneMap
		{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
		
		// 用来保存当前正在拼接的组合
        string combination;
		
		// 启动回溯：从第0位数字开始
        backtrack(combinations, phoneMap, digits, 0, combination);
		
        return combinations;
    }

	// 回溯函数
    // combinations：结果容器；phoneMap：数字字母映射；digits：输入数字串；index：当前处理到第几个数字；combination：当前拼接串
    void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& combination) 
	{
		// 终止条件：index走到末尾，说明当前组合拼完了，存入结果
        if (index == digits.length()) 
		{
            combinations.push_back(combination);
        } 
		
		else 
		{
			// 取出当前位置的数字字符
            char digit = digits[index];
			
			// 拿到这个数字对应的全部字母
            const string& letters = phoneMap.at(digit);
			
			// 遍历每一个可选字母
            for (const char& letter: letters) 
			{
				// 选这个字母，加到当前串末尾
                combination.push_back(letter);
				
				// 递归处理下一位数字
                backtrack(combinations, phoneMap, digits, index + 1, combination);
				
				// 回溯撤销：删掉刚才加的字母，尝试下一个选择
                combination.pop_back();
            }
        }
    }
};

// 复杂度分析

// 时间复杂度：O(3 
// m
 // ×4 
// n
 // )，其中 m 是输入中对应 3 个字母的数字个数（包括数字 2、3、4、5、6、8），n 是输入中对应 4 个字母的数字个数（包括数字 7、9），m+n 是输入数字的总个数。当输入包含 m 个对应 3 个字母的数字和 n 个对应 4 个字母的数字时，不同的字母组合一共有 3 
// m
 // ×4 
// n
  // 种，需要遍历每一种字母组合。

// 空间复杂度：O(m+n)，其中 m 是输入中对应 3 个字母的数字个数，n 是输入中对应 4 个字母的数字个数，m+n 是输入数字的总个数。除了返回值以外，空间复杂度主要取决于哈希表以及回溯过程中的递归调用层数，哈希表的大小与输入无关，可以看成常数，递归调用层数最大为 m+n。