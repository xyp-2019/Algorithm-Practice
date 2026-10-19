// 方法二：迭代
// 思路与算法

// 也可以通过迭代的方式实现两两交换链表中的节点。

// 创建哑结点 dummyHead，令 dummyHead.next = head。令 temp 表示当前到达的节点，初始时 temp = dummyHead。每次需要交换 temp 后面的两个节点。

// 如果 temp 的后面没有节点或者只有一个节点，则没有更多的节点需要交换，因此结束交换。否则，获得 temp 后面的两个节点 node1 和 node2，通过更新节点的指针关系实现两两交换节点。

// 具体而言，交换之前的节点关系是 temp -> node1 -> node2，交换之后的节点关系要变成 temp -> node2 -> node1，因此需要进行如下操作。

// temp.next = node2
// node1.next = node2.next
// node2.next = node1
// 完成上述操作之后，节点关系即变成 temp -> node2 -> node1。再令 temp = node1，对链表中的其余节点进行两两交换，直到全部节点都被两两交换。

// 两两交换链表中的节点之后，新的链表的头节点是 dummyHead.next，返回新的链表的头节点即可。

class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
	{
        ListNode* dummyHead = new ListNode(0);	// 创建哑节点，方便统一处理头部节点交换的边界情况
		
        dummyHead->next = head;	// 哑节点的next指向原链表头head
		
        ListNode* temp = dummyHead;	// temp指针，初始指向哑节点，作为每一组的前驱节点
		
		// 循环条件：后面至少还有2个节点，才有交换的必要
        while (temp->next != nullptr && temp->next->next != nullptr) 
		{
            ListNode* node1 = temp->next;	// node1：待交换的第一个节点
			
            ListNode* node2 = temp->next->next;	// node2：待交换的第二个节点
			
            temp->next = node2;	// 前驱节点temp，指向node2（node2换到前面）
			
            node1->next = node2->next;	// node1接上node2原来后面剩下的链表
			
            node2->next = node1;	// node2指向node1，完成这两个节点互换
			
            temp = node1;	// temp移动到node1，作为下一组节点的前驱，进入下一轮循环
        }
		
        ListNode* ans = dummyHead->next;	// 保存交换完成后新链表的头节点
		
        delete dummyHead;	// 释放哑节点内存，避免内存泄漏
		
        return ans;	// 返回新链表头
    }
};

// 举个例子 `1 → 2 → 3 → 4`，简单走一遍：

// 1. temp=dummy，node1=1，node2=2
// temp->next=2；1->next=3；2->next=1；temp 移动到 1，链表：dummy→2→1→3→4
// 2. 继续循环，node1=3，node2=4
// temp->next=4；3->next=nullptr；4->next=3；temp 移动到 3，链表：dummy→2→1→4→3
// 3. 此时 temp->next 为空，退出循环，返回 dummy->next 也就是节点

// 复杂度分析

// 时间复杂度：O(n)，其中 n 是链表的节点数量。需要对每个节点进行更新指针的操作。

// 空间复杂度：O(1)。