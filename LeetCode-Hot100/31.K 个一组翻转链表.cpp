// 方法一：模拟
// 思路与算法

// 本题的目标非常清晰易懂，不涉及复杂的算法，但是实现过程中需要考虑的细节比较多，容易写出冗长的代码。主要考查面试者设计的能力。

// 我们需要把链表节点按照 k 个一组分组，所以可以使用一个指针 head 依次指向每组的头节点。这个指针每次向前移动 k 步，直至链表结尾。对于每个分组，我们先判断它的长度是否大于等于 k。若是，我们就翻转这部分链表，否则不需要翻转。

// 接下来的问题就是如何翻转一个分组内的子链表。翻转一个链表并不难，过程可以参考「206. 反转链表」。但是对于一个子链表，除了翻转其本身之外，还需要将子链表的头部与上一个子链表连接，以及子链表的尾部与下一个子链表连接。

// 因此，在翻转子链表的时候，我们不仅需要子链表头节点 head，还需要有 head 的上一个节点 pre，以便翻转完后把子链表再接回 pre。

// 但是对于第一个子链表，它的头节点 head 前面是没有节点 pre 的。太麻烦了！难道只能特判了吗？答案是否定的。没有条件，我们就创造条件；没有节点，我们就创建一个节点。我们新建一个节点，把它接到链表的头部，让它作为 pre 的初始值，这样 head 前面就有了一个节点，我们就可以避开链表头部的边界条件。这么做还有一个好处，下面我们会看到。

// 反复移动指针 head 与 pre，对 head 所指向的子链表进行翻转，直到结尾，我们就得到了答案。下面我们该返回函数值了。

// 有的同学可能发现这又是一件麻烦事：链表翻转之后，链表的头节点发生了变化，那么应该返回哪个节点呢？照理来说，前 k 个节点翻转之后，链表的头节点应该是第 k 个节点。那么要在遍历过程中记录第 k 个节点吗？但是如果链表里面没有 k 个节点，答案又还是原来的头节点。我们又多了一大堆循环和判断要写，太崩溃了！

// 等等！还记得我们创建了节点 pre 吗？这个节点一开始被连接到了头节点的前面，而无论之后链表有没有翻转，它的 next 指针都会指向正确的头节点。那么我们只要返回它的下一个节点就好了。至此，问题解决。

class Solution 
{
public:
    // 翻转 [head, tail] 闭区间内的节点，返回翻转后的（新头，新尾）
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) 
	{
        ListNode* prev = tail->next; // prev 初始等于tail后面那个节点
		
        ListNode* p = head;          // p从区间起点head开始遍历
		
        while (prev != tail) // 循环条件：prev还没走到tail，继续翻转
		{       
            ListNode* nex = p->next; // 保存p原来的下一个节点
			
            p->next = prev;          // p反向指向prev
			
            prev = p;                // prev向前移动到p
			
            p = nex;                 // p移动到原先保存的nex
        }
		
        return {tail, head};         // 翻转完，tail变成新头，head变成新尾
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
	{
        ListNode* hair = new ListNode(0); // 创建哑节点hair
		
        hair->next = head;                // 哑节点指向原链表头部
		
        ListNode* pre = hair;             // pre：待反转组的前驱节点，初始指向hair

        while (head) // head不为空就继续处理分组
		{ 
            ListNode* tail = pre; // tail从pre出发，向后找本组的末尾节点
			
            // 向后走k步，定位tail
            for (int i = 0; i < k; ++i) 
			{
                tail = tail->next;
				
                if (!tail) // 走不到k个，剩余节点不足k，直接返回结果
				{ 
                    return hair->next;
                }
            }
			
            ListNode* nex = tail->next; // 保存tail后面节点，也就是下一组的起点

            // 翻转 head ~ tail，tie接收返回的新头、新尾
            tie(head, tail) = myReverse(head, tail);

            // 把翻转好的子链表接回原链表
            pre->next = head;
			
            tail->next = nex;

            // 更新指针，准备下一轮循环
            pre = tail;
			
            head = tail->next;
        }
		
        return hair->next;
    }
};

// 复杂度分析

// 时间复杂度：O(n)，其中 n 为链表的长度。head 指针会在 O(⌊kn⌋) 个节点上停留，每次停留需要进行一次 O(k) 的翻转操作。

// 空间复杂度：O(1)，我们只需要建立常数个变量。