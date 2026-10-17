// 方法一：哈希表
// 思路与算法

// 一个非常直观的思路是：我们遍历链表中的每个节点，并将它记录下来；一旦遇到了此前遍历过的节点，就可以判定链表中存在环。借助哈希表可以很方便地实现。

class Solution 
{
public:
	// 寻找链表环的入口节点，有环返回入口节点，无环返回nullptr
    ListNode *detectCycle(ListNode *head) 
	{
        unordered_set<ListNode *> visited;	// 哈希集合，保存已经访问过的节点指针
		
        while (head != nullptr) // 当前节点不为空，继续遍历
		{
            if (visited.count(head)) // 判断当前节点是否已经在集合中（之前访问过）
			{
                return head;	// 重复遇到该节点，这就是环的入口，直接返回
            }
			
            visited.insert(head);	// 当前节点没出现过，存入集合标记已访问
			
            head = head->next;	// 移动到下一个节点
        }
		
        return nullptr;	// 遍历到链表末尾，不存在环，返回空
    }
};

// 复杂度分析

// 时间复杂度：O(N)，其中 N 为链表中节点的数目。我们恰好需要访问链表中的每一个节点。

// 空间复杂度：O(N)，其中 N 为链表中节点的数目。我们需要将链表中的每个节点都保存在哈希表当中。