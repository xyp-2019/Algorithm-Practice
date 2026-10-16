// 方法一：迭代
// 假设链表为 1→2→3→∅，我们想要把它改成 ∅←1←2←3。

// 在遍历链表时，将当前节点的 next 指针改为指向前一个节点。由于节点没有引用其前一个节点，因此必须事先存储其前一个节点。在更改引用之前，还需要存储后一个节点。最后返回新的头引用。

class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
	{
        ListNode* prev = nullptr;	// prev：保存【前一个节点】
		
        ListNode* curr = head;	// curr：当前正在处理的节点，一开始指向1
		
        while (curr) // curr不为空就循环
		{
            ListNode* next = curr->next;	// 先记下 curr 的下一个节点（防止断链丢失）
			
            curr->next = prev;	// 当前节点的next，反转，指向前一个
			
            prev = curr;	// prev往后挪一步，变成当前节点
			
            curr = next;	// curr往后挪一步，去到原来的下一个节点
        }
		
        return prev;	// 循环结束，prev就是新链表的头节点
    }
};

// 例子：链表 `1 → 2 → 3 → nullptr`，用代码一步步模拟

// ### 初始状态

// `prev = nullptr`，`curr = 1`，链表：`1 -> 2 -> 3`

// ---

// ## 第 1 轮循环（curr=1）

// 1. `next = curr->next` → `next = 2`
// 2. `curr->next = prev` → 节点 1 的 next 改成 `nullptr`。现在：`1 → nullptr`
// 3. `prev = curr` → `prev = 1`
// 4. `curr = next` → `curr = 2`

// > 
// > 当前：prev=1，curr=2，链表片段：`1 ← nullptr`

// ## 第 2 轮循环（curr=2）

// 1. `next = curr->next` → `next =3`
// 2. `curr->next = prev` → 节点 2 的 next 指向 1。现在：`2 → 1 → nullptr`
// 3. `prev = curr` → `prev=2`
// 4. `curr = next` → `curr=3`

// > 
// > 当前：prev=2，curr=3，链表片段：`2 ←1 ← nullptr`

// ## 第 3 轮循环（curr=3）

// 1. `next = curr->next` → `next = nullptr`
// 2. `curr->next = prev` → 节点 3 的 next 指向 2。现在：`3 →2 →1 → nullptr`
// 3. `prev = curr` → `prev=3`
// 4. `curr = next` → `curr=nullptr`

// ## 退出 while 循环

// `curr == nullptr`，循环结束。
// return `prev`，也就是**3**，它就是反转后链表的头节点。
// ✅ 最终链表：`3 → 2 →1 → nullptr`

// 复杂度分析

// 时间复杂度：O(n)，其中 n 是链表的长度。需要遍历链表一次。

// 空间复杂度：O(1)。