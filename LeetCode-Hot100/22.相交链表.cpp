// 方法一：哈希集合
// 思路和算法

// 判断两个链表是否相交，可以使用哈希集合存储链表节点。

// 首先遍历链表 headA，并将链表 headA 中的每个节点加入哈希集合中。然后遍历链表 headB，对于遍历到的每个节点，判断该节点是否在哈希集合中：

// 如果当前节点不在哈希集合中，则继续遍历下一个节点；

// 如果当前节点在哈希集合中，则后面的节点都在哈希集合中，即从当前节点开始的所有节点都在两个链表的相交部分，因此在链表 headB 中遍历到的第一个在哈希集合中的节点就是两个链表相交的节点，返回该节点。

// 如果链表 headB 中的所有节点都不在哈希集合中，则两个链表不相交，返回 null。

class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
	{
		// 创建哈希集合，存放链表节点的指针（内存地址），用来记录遍历过的节点
        unordered_set<ListNode *> visited;
		
		// temp指针，先用来遍历链表A，初始指向A的头结点
        ListNode *temp = headA;
		
		// 遍历链表A，直到temp为空（走到链表末尾）
        while (temp != nullptr) 
		{
			// 将当前A链表节点的指针存入集合
            visited.insert(temp);
			
			// temp移动到下一个节点
            temp = temp->next;
        }
		
		// 重置temp指针，现在用来遍历链表B，初始指向B的头结点
        temp = headB;
		
		
        while (temp != nullptr) 
		{
			// 判断集合里是否存在当前B节点的指针（地址）
            if (visited.count(temp)) 
			{
				// 找到相同地址，也就是相交节点，直接返回该节点
                return temp;
            }
			
			// 没找到，继续看B的下一个节点
            temp = temp->next;
        }
		
		// B全部遍历完，没有找到相交节点，返回nullptr（无相交）
        return nullptr;
    }
};

// 复杂度分析

// 时间复杂度：O(m+n)，其中 m 和 n 是分别是链表 headA 和 headB 的长度。需要遍历两个链表各一次。

// 空间复杂度：O(m)，其中 m 是链表 headA 的长度。需要使用哈希集合存储链表 headA 中的全部节点。