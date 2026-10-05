// 前言
// 两个字符串互为字母异位词，当且仅当两个字符串包含的字母相同。同一组字母异位词中的字符串具备相同点，可以使用相同点作为一组字母异位词的标志，使用哈希表存储每一组字母异位词，哈希表的键为一组字母异位词的标志，哈希表的值为一组字母异位词列表。

// 遍历每个字符串，对于每个字符串，得到该字符串所在的一组字母异位词的标志，将当前字符串加入该组字母异位词的列表中。遍历全部字符串之后，哈希表中的每个键值对即为一组字母异位词。

// 以下的两种方法分别使用排序和计数作为哈希表的键。

// 方法一：排序
// 由于互为字母异位词的两个字符串包含的字母相同，因此对两个字符串分别进行排序之后得到的字符串一定是相同的，故可以将排序之后的字符串作为哈希表的键。

class Solution 
{
public:
	// 函数入口，输入字符串数组strs，输出分组后的二维字符串数组
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
	{
		
		// 定义哈希表mp：key=排序后的字符串，value=一组异位词集合
        unordered_map<string, vector<string>> mp;
		
		// 范围for循环，遍历输入每一个字符串str
        for (string& str: strs) 
		{
            string key = str;	// 复制一份当前字符串，不改动原字符串
			
            sort(key.begin(), key.end());	// 把复制出来的字符串字母排序
			
            mp[key].emplace_back(str);	// 排序完当key，把原始字符串放进map对应的数组
        }
		
		// 准备最终要返回的结果数组ans
        vector<vector<string>> ans;
		
		// 迭代器遍历哈希表里每一组数据
		// ## 1. `auto it = mp.begin()`
		// `mp.begin()`：返回哈希表**第一个键值对元素的迭代器**。
		// **迭代器`it`**：可以理解成一个 “指针”，指向 map 里面的某一组 `{key , value}`。
		// `au	to`：编译器自动推导`it`的类型，完整类型写出来很长：
		//	unordered_map<string,vector<string>>::iterator it`，用 auto 省去手写。
		//  map 里面每一个元素结构：`it`指向的元素 = `pair<string, vector<string>>`，里面包含两部分：
		// `.first`：存 key（排序后的字符串，比如`"aet"`）
		// `.second`：存 value（这一组全部异位词，`vector<string>`，比如`["eat","tea"]`）
		
		// ## 2. `it != mp.end()`
		// `mp.end()`：**不是最后一个元素**！它是哈希表末尾的「哨兵位置」，代表已经遍历完所有元素。
		// 循环条件：只要迭代器`it`**没有走到末尾哨兵**，循环继续跑。

		// ##3. `++it`
		// 迭代器自增，`it`向后移动，指向 map 里**下一个键值对**。

		// ##4. 循环体内：`ans.emplace_back(it->second);`
		// `it->second`：
		// `it`是迭代器（像指针），用`->`访问指向元素的成员。
		// - `it->first` → 获取这一组的 key（排序字符串）
		// - `it->second` → 获取这一组的 value，也就是整组异位词`vector<string>`
		// `ans.emplace_back(it->second)`：把这一整组异位词，直接 push 到结果数组 ans 中。
		
        for (auto it = mp.begin(); it != mp.end(); ++it) 
		{
            ans.emplace_back(it->second);	// 把哈希表的值（整组异位词）加入结果
        }
		
		
        return ans;	// 返回分组完成的答案
    }
};

// 复杂度分析

// 时间复杂度：O(nklogk)，其中 n 是 strs 中的字符串的数量，k 是 strs 中的字符串的的最大长度。需要遍历 n 个字符串，对于每个字符串，需要 O(klogk) 的时间进行排序以及 O(1) 的时间更新哈希表，因此总时间复杂度是 O(nklogk)。

// 空间复杂度：O(nk)，其中 n 是 strs 中的字符串的数量，k 是 strs 中的字符串的的最大长度。需要用哈希表存储全部字符串。