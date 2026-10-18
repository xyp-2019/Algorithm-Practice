// 方法一：递归
// 思路

// 我们可以如下递归地定义两个链表里的 merge 操作（忽略边界情况，比如空链表等）：

// { 
// list1[0]+merge(list1[1:],list2)
// list2[0]+merge(list1,list2[1:])
// ​
  
// list1[0]<list2[0]
// otherwise
// ​
 
// 也就是说，两个链表头部值较小的一个节点与剩下元素的 merge 操作结果合并。

// 算法

// 我们直接将以上递归过程建模，同时需要考虑边界情况。

// 如果 l1 或者 l2 一开始就是空链表 ，那么没有任何操作需要合并，所以我们只需要返回非空链表。否则，我们要判断 l1 和 l2 哪一个链表的头节点的值更小，然后递归地决定下一个添加到结果里的节点。如果两个链表有一个为空，递归结束。

class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		// 函数：合并两个升序链表，返回合并后新链表头节点
        if (l1 == nullptr) 
		{
            return l2;
        } 
		
		// 如果l2为空链表，直接返回l1
		else if (l2 == nullptr) 
		{
            return l1;
        } 
		
		// 如果l1当前节点值更小
		else if (l1->val < l2->val) 
		{
			// l1的next指向：l1下一个节点 和 l2 合并后的结果
            l1->next = mergeTwoLists(l1->next, l2);
			
            return l1;	// 返回当前l1节点作为这一段的头
        } 
		
		// l2当前节点值更小或者相等
		else 
		{
			// l2的next指向：l1 和 l2下一个节点 合并后的结果
            l2->next = mergeTwoLists(l1, l2->next);
			
            return l2;	// 返回当前l2节点作为这一段的头
        }
    }
};

// 复杂度分析

// 时间复杂度：O(n+m)，其中 n 和 m 分别为两个链表的长度。因为每次调用递归都会去掉 l1 或者 l2 的头节点（直到至少有一个链表为空），函数 mergeTwoList 至多只会递归调用每个节点一次。因此，时间复杂度取决于合并后的链表长度，即 O(n+m)。

// 空间复杂度：O(n+m)，其中 n 和 m 分别为两个链表的长度。递归调用 mergeTwoLists 函数时需要消耗栈空间，栈空间的大小取决于递归调用的深度。结束递归调用时 mergeTwoLists 函数最多调用 n+m 次，因此空间复杂度为 O(n+m)。