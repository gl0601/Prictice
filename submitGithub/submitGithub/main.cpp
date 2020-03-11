#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include "class5.h"
#include "class6.h"

using namespace std;

void showArr(const int *arr, int n);
int FindMax(int max, int num);
int FindMin(int min, int num);


template<typename T>
void mySwap(T *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
bool twoSort(const int *arr, int p, int r, int target)
{
	if (arr == NULL) return false;

	int mid = (p + r) / 2;

	if (arr[mid] == target) return true;
	if (p > r) return false;

	else if (arr[mid] > target)
	{
		twoSort(arr, p, --mid, target);
	}
	else if (arr[mid] < target)
	{
		twoSort(arr, ++mid, r, target);
	}

	else
	{
		return false;
	}


}
void test()
{
	int arr[8] = { 4,5,6,7,8,8,9,10 };
	int target = 4;
	bool find = twoSort(arr, 0, 7, target);
	if (find)
	{
		printf("find");
	}
	else
		printf("not find");


}
/*===========================题目一====================================*/
//题目一 :给定一个数组arr，和一个数num，请把小于等于num的数放在数
//组的左边，大于num的数放在数组的右边。
void sort(int *arr, int p, int r, int num)
{
	//if (sizeof(arr) / sizeof(int) < 2) return;

	int left = p - 1;
	while (p < r)
	{
		if (arr[p] <= num)
		{
			mySwap(arr, ++left, p++);

		}
		else
		{
			p++;
		}

	}
}

void test01()
{
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	printf("%d", sizeof(arr) / sizeof(int));
	sort(arr, 0, 10, 2);
	//显示
	for (int i = 0; i < 10; i++)
	{
		printf(" %d", arr[i]);
	}

}
/*问题二（荷兰国旗问题）
给定一个数组arr，和一个数num，请把小于num的数放在数组的
左边，等于num的数放在数组的中间，大于num的数放在数组的
右边。
要求额外空间复杂度O(1)，时间复杂度O(N)
*/
//template<typename T>
void polandFlag(int *arr, int l, int r, int num)
{
	int left = l - 1;
	int right = r + 1;


	while (l < right)//这里错误之前写的l<r
	{
		if (arr[l] < num)
		{
			mySwap(arr, ++left, l++);
		}
		else if (arr[l] > num)
		{
			mySwap(arr, --right, l);
		}
		else
		{
			l++;
		}
	}
}

void test02()
{
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int len = sizeof(arr) / sizeof(int);

	polandFlag(arr, 0, len - 1, 3);
	//显示
	for (int i = 0; i < len; i++)
	{
		printf(" %d", arr[i]);
	}
}
/*===========================题目八====================================*/
//给定一个数组，求如果排序后，求相邻差值最大的，非基于比较的排序
int bucket(long num, long len, long min, long max);
int MaxGap(int *arr, int n)
{
	if (arr == NULL || n < 2) return 0;

	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < n; i++)
	{
		max = FindMax(max, arr[i]);
		min = FindMin(min, arr[i]);
	}
	if (max == min) return 0;
	//0号桶到n号桶的三个信息
	bool *hasNum = new bool[n + 1];//是否为空
	for (int i = 0; i < n + 1; i++)
	{
		hasNum[i] = false;
	}

	int *maxs = new int[n + 1];//
	int *mins = new int[n + 1];


	int bid = 0;
	for (int i = 0; i < n; i++)
	{
		bid = bucket(arr[i], n, min, max);//桶中的位置
		mins[bid] = hasNum[bid] ? FindMin(mins[bid], arr[i]) : arr[i];
		maxs[bid] = hasNum[bid] ? FindMax(maxs[bid], arr[i]) : arr[i];
		hasNum[bid] = true;

	}
	int res = 0;
	int lastMax = maxs[0];
	int i = 1;
	for (; i <= n; i++)
	{
		if (hasNum[i])
		{
			res = FindMax(res, mins[i] - lastMax);
			lastMax = maxs[i];
		}
	}

	delete[] hasNum;
	delete[] maxs;
	delete[] mins;

	return res;

}
int bucket(long num, long len, long min, long max)//定位数放到哪个桶
{
	return (int)((num - min) * len / (max - min));
}

/*===========================用数组实现一个栈====================================*/

template<class T>
class Array_To_Stack
{
public:
	Array_To_Stack(int size)
	{
		arr = new int[size];
		if (arr == NULL)
		{
			printf("动态内存分配失败");
			exit(1);
		}
		if (size < 0) printf("The init size is less than 0");
		this->idenx = 0;
		this->maxSize = size;
	}
	~Array_To_Stack()
	{
		delete[] arr;
	}

	void push(int obj)
	{
		if (idenx == maxSize)
		{
			printf("The init size is less than 0");
		}
		arr[idenx++] = obj;
	}
	int pop()
	{
		if (idenx == maxSize)
		{
			printf("The init size is less than 0");
		}
		return arr[--idenx];
	}
	int peek()//返回栈顶
	{
		if (idenx == 0) return NULL;
		return arr[idenx - 1];
	}
	int sizeofarr()
	{
		return sizeof(arr) / sizeof(arr[0]);
	}
private:
	T *arr;
	int idenx;
	int maxSize;
};

/*===========================用数组实现一个队列====================================*/
class  ArrayQueue
{
public:
	ArrayQueue(int InitSize)
	{
		if (InitSize < 1) printf("queue capacity must be>0");
		arr = new int[InitSize];
		if (arr == NULL)
		{
			printf("动态内存分配失败");
			exit(1);
		}
		this->len = InitSize;
		first = 0;
		last = 0;
		size = 0;//元素个数
	}
	~ArrayQueue()
	{
		delete[] arr;
	}

	void push_Queue(int num)
	{
		if (size == len) printf("the queue is full");
		size++;
		arr[last] = num;
		last = (last == len - 1) ? 0 : last + 1;
	}
	int pop_Queue()
	{
		if (size == 0) printf("the queue is null");
		size--;
		int temp = arr[first];
		first = first == len - 1 ? 0 : first + 1;
		return temp;
	}


private:
	int *arr;
	int size;
	int first;
	int last;
	int len;

};
/*===========================class 3 题目二 用数组实现一个特殊的栈====================================*/
//要求返回最小元素，时间复杂度为O（1）
class Mystack
{
public:

	void mypush(int obj)
	{
		if (minStack.empty()) minStack.push(obj);
		else if (obj < getmin())
		{
			minStack.push(obj);
		}
		else
		{
			int newmin = getmin();
			minStack.push(newmin);
		}
		dateStack.push(obj);
	}
	void mypop()
	{
		if (dateStack.top() == minStack.top())
		{
			dateStack.pop();
			minStack.pop();
		}
		else
		{
			minStack.pop();
		}
	}

	int getmin() const
	{
		if (minStack.empty()) throw std::runtime_error("minstack is empty");
		return minStack.top();
	}

private:
	std::stack<int> dateStack;
	std::stack<int> minStack;

};

void test03()
{
	Mystack arr;
	arr.mypush(5);
	arr.mypush(3);
	arr.mypush(2);
	arr.mypush(4);
	arr.mypush(6);
	arr.mypush(3);
	arr.mypush(1);
	printf("%d\n", arr.getmin());
	arr.mypop();
	printf("%d\n", arr.getmin());
	arr.mypop();
	printf("%d\n", arr.getmin());
	arr.mypop();
	printf("%d\n", arr.getmin());
	arr.mypop();
	printf("%d\n", arr.getmin());
	arr.mypop();
	printf("%d\n", arr.getmin());
}

/*===========================class 3 题目三====================================*/
//如何仅用队列结构实现栈结构；
//如何仅用栈结构实现队列结构；
//俩个队列实现
class queueTostack
{
public:
	void mypush(int num)
	{
		datqueue.push(num);
	}
	int mypop()
	{
		if (datqueue.empty()) throw std::runtime_error("minstack is empty");
		while (datqueue.size() > 1)
		{
			tempqueue.push(datqueue.front());
			datqueue.pop();
		}
		int res = datqueue.front();

		datqueue.pop();
		swap();
		return res;
	}

	void swap()
	{
		std::queue<int> temp = tempqueue;
		tempqueue = datqueue;
		datqueue = temp;

	}
private:
	std::queue<int> datqueue;
	std::queue<int> tempqueue;

};
void test04()
{
	queueTostack s;
	int array[] = { 1,2,3 };
	for (int i = 0; i < 3; i++)
	{
		s.mypush(array[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		printf("%d", s.mypop());
	}
}
//如何仅用栈结构实现队列结构；
class stacktoqueue
{
public:
	void mypush(int num)
	{
		Stack1.push(num);
	}

	int mypop()
	{

		if (Stack2.size() <= 0)//
		{
			while (!Stack1.empty()) 
			{
				Stack2.push(Stack1.top());
				Stack1.pop();
			}
		}
		if (Stack2.size() == 0) throw new std::exception("queue is empty");
		int res = Stack2.top();
		Stack2.pop();
		return res;
	}
	void swap()
	{
		std::stack<int>temp = Stack1;
		Stack1 = Stack2;
		Stack2 = temp;
	}
private:
	std::stack<int> Stack1;
	std::stack<int> Stack2;

};
void test05()
{
	stacktoqueue s;
	int array[] = { 1,2,3 };
	for (int i = 0; i < 3; i++)
	{
		s.mypush(array[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		printf("%d", s.mypop());
	}
}
/*===========================class 4 ====================================*/
//题目三:转圈打印矩阵
void printEdge(int **arr,int tR,int tC,int dR,int dC)
{
	if (tR==dR)//左上角的行数等于右下角的行数
	{
		for (int i = tC; i <=dC; i++)
		{
			printf("%d + ", arr[tR][i]);
		}
	}
	else if (tC==dC)
	{
		for (int i = tR; i <= dR; i++)
		{
			printf("+ %d ", arr[i][tR]);
		}
	}
	else
	{
		int curR = tR;
		int curC = tC;
		while (curC!=dC)
		{
			printf("+ %d", arr[tR][curC]);
			curR++;
		}
		while (curR != dR)
		{
			printf("+ %d", arr[curR][dC]);
			curR++;
		}
		while (curC != tC)
		{
			printf("+ %d", arr[dR][curC]);
			curC--;
		}
		while (curR != tR)
		{
			printf("+ %d", arr[curR][tC]);
			curR--;
		}
	}
}

void spirlOrderPrint(int **arr,int R,int L )
{
	int tR = 0;
	int tC = 0;
	int dR = R - 1;
	int dC = L - 1;
	while (tR<=dR &&tC<=dC)
	{
		printEdge(arr, tR, tC, dR, dC);
	}
}
//矩阵旋转90度
void rotattEdge(int **arr, int tR, int tC, int dR,int dC)
{
	int times = dC - tC;
	int tmp = 0;
	for (int i=0;i!=times;i++)
	{
		tmp = arr[tR][tC + i];
		arr[tR][tC + 1] = arr[dR - i][tC];
		arr[dR - i][tC] = arr[dR][dC-i];
		arr[dR][dC-1] = arr[tR+i][dC];
		arr[tR+i][dC] = tmp;

	}
}

void rotate(int **arr,int R ,int L)
{
	int tR = 0;
	int tC = 0;
	int dR = R - 1;
	int dC = L - 1;
	while (tR<dR)
	{
		rotattEdge(arr,tR++,tC++,dR--,dC--);
	}
}

//题目七 【题目】 分别实现反转单向链表和反转双向链表的函数。
/*【要求】 如果链表长度为N，时间复杂度要求为O(N)，额外空间
复杂度要求为O(1)*/





//题目八
/*“之”字形打印矩阵
【题目】 给定一个矩阵matrix，按照“之”字形的方式打印这
个矩阵，例如： 1 2 3 4 5 6 7 8 9 10 11 12
“之”字形打印的结果为：1，2，5，9，6，3，4，7，10，11，
8，12
【要求】 额外空间复杂度为O(1)。*/
void printLevel(int **arr, int tR, int tC, int dR, int dC, bool f)
{
	if (f)
	{
		while (tR!=dR+1)
		{

			printf("+ %d",arr[tR++][tC--]);
		
		}
	}
	else
	{
		while (dR != tR - 1)
		{
			printf("+ %d", arr[dR--][dC++]);
		}
		
	}
}
void printMatrixZigZag(int **arr,int R,int L)
{
	int tR = 0;
	int tC = 0;
	int dR = 0;
	int dC = 0;
	int endR = R - 1;
	int endC = L - 1;
	bool fromup = false;

	while (tR!=endR+1)
	{
		printLevel(arr,tR,tC,dR,dC,fromup);
		tR = tC == endC ? tR + 1:tR;
		tC = tC == endC ? tC : tC+1;
		dR = dR == endR ? dR :dR+1;
		dC = dR == endR ? dC + 1 : dC;
		fromup = !fromup;
	}
}
//题目九
/*在行列都排好序的矩阵中找数
【题目】 给定一个有N*M的整型矩阵matrix和一个整数K，
matrix的每一行和每一 列都是排好序的。实现一个函数，判断K
是否在matrix中。 例如： 0 1 2 5 2 3 4 7 4
4 4 8 5 7 7 9 如果K为7，返回true；如果K为6，返
回false。
【要求】 时间复杂度为O(N+M)，额外空间复杂度为O(1)。*/


//题目十
/*打印两个有序链表的公共部分
【题目】 给定两个有序链表的头指针head1和head2，打印两个
链表的公共部分。*/

//题目十一
/*判断一个链表是否为回文结构
【题目】 给定一个链表的头节点head，请判断该链表是否为回
文结构。 例如： 1->2->1，返回true。 1->2->2->1，返回true。
15->6->15，返回true。 1->2->3，返回false。
进阶： 如果链表长度为N，时间复杂度达到O(N)，额外空间复杂
度达到 。*/

void insertNodeHead(Node *&L, int arr[], int len)//第一个插入点是末节点 逆序
{
	Node *s;
	L = new Node();
	L->next = NULL;
	for (int i = 0; i < len; i++)
	{
		s = new Node();
		s->value = arr[i];
		s->next = L->next;
		L->next = s;
	}

}
void ShowList(Node *L)

{

	Node * p = L->next;

	while (p != NULL)

	{
		printf(" %d ", p->value);
		p = p->next;
	}
	printf("\n");

}

void deleteList(Node *&L)
{
	Node *pre = L;
	Node *p = L->next;
	
	while (p != NULL)
	{
		delete pre;
		pre = p;
		p = p->next;

	}
	delete pre;
}
//使用O(N)辅助空间, 对应基础版本．
bool isPalindromel(Node *head)
{
	//Node *cur = new Node();
	Node *cur = head->next;
	Node *p = head->next;
	
	std::stack<int> node_value;
	while (cur!=NULL)//将数据压栈
	{
		node_value.push(cur->value);
		cur = cur->next;
	}

	while (p !=NULL)
	{

		if (node_value.top()!= p->value)
		{

			return false;
		}
		else
		{
			p = p->next;
			node_value.pop();
		}
		
	}
	return true;

}
//使用O(N/2)辅助空间, 对应基础版本．
bool isPalindrome2(Node* head)
{
	if (head==nullptr ||head->next==nullptr)
	{
		return true;
	}
	std::stack<int> my_node_value;
	Node *slowNode = head;
	Node *fastNode = head;
	Node *p = head->next;
	while (fastNode->next!=nullptr && fastNode->next->next!=nullptr)
	{
		slowNode = slowNode->next;
		fastNode = fastNode->next->next;
	}
	printf("%d\n",slowNode->value);
	while (slowNode!=nullptr)
	{
		my_node_value.push(slowNode->value);
		slowNode = slowNode->next;
	}

	while (!my_node_value.empty())
	{
		if (p->value != my_node_value.top())
		{
			return false;
			break;
		}
		else
		{
			p = p->next;
			my_node_value.pop();
		}
	}
	return true;

}

//void printList(Node *head)
//{
//	注意haead是一个指针不存数据
//	while (head!=NULL)
//	{
//		printf("%d\n",head->value);
//		head = head->next;
//	}
//}

void InitList(Node *&L)
{

	L = new Node();
	L->next = NULL;
}
//need O（1）extra space
bool isPalindrome3(Node* head) {
	if (head == nullptr || head->next == nullptr) {
		return true;
	}
	//奇数的时候来到中点，偶数的时候来到中点的前一个
	Node* n1 = head;    // slow pointer
	Node* n2 = head;    // fast pointer
	while (n2->next != nullptr && n2->next->next != nullptr) {
		n1 = n1->next;
		n2 = n2->next->next;
	}
	n2 = n1->next;    // n2 now is the first node in the second list
	n1->next = nullptr;
	Node* n3 = nullptr;    // A ListNode to store the last node in the second list
	//后半部分逆序
	while (n2 != nullptr) {
		n3 = n2->next;
		n2->next = n1;
		n1 = n2;//n1 move
		n2 = n3;//n2 move
	}
	n3 = n1;    // here n1 is the last node in the second list, we need to store the last node to reconver
	n2 = head;  // compare the first and the second list
	while (n1 != nullptr && n2 != nullptr) {
		if (n1->value != n2->value) {
			return false;
			break;
		}
		else {
			n1 = n1->next;
			n2 = n2->next;
		}
	}
	n1 = n3->next;    // here we recover the second list to the origin order
	n3->next = nullptr;   // the origin last node next poiter is nullptr
	//恢复现场
	while (n1 != nullptr) {//recover list
		n2 = n1->next;
		n1->next = n3;
		n3 = n1;
		n1 = n2;
	}
	return true;

}

/*题目十二将单向链表按某值划分成左边小、中间相等、右边大的形式
【题目】 给定一个单向链表的头节点head，节点的值类型是整型，再给定一个
整 数pivot。实现一个调整链表的函数，将链表调整为左部分都是值小于 pivot
的节点，中间部分都是值等于pivot的节点，右部分都是值大于 pivot的节点。
除这个要求外，对调整后的节点顺序没有更多的要求。 例如：链表9->0->4->5-
>1，pivot=3。 调整后链表可以是1->0->4->9->5，也可以是0->1->9->5->4。总
之，满 足左部分都是小于3的节点，中间部分都是等于3的节点（本例中这个部
分为空），右部分都是大于3的节点即可。对某部分内部的节点顺序不做 要求。
进阶： 在原问题的要求之上再增加如下两个要求。
在左、中、右三个部分的内部也做顺序要求，要求每部分里的节点从左 到右的
顺序与原链表中节点的先后次序一致。 例如：链表9->0->4->5->1，pivot=3。
调整后的链表是0->1->9->4->5。 在满足原问题要求的同时，左部分节点从左到
右为0、1。在原链表中也 是先出现0，后出现1；中间部分在本例中为空，不再
讨论；右部分节点 从左到右为9、4、5。在原链表中也是先出现9，然后出现4，
最后出现5。
如果链表长度为N，时间复杂度请达到O(N)，额外空间复杂度请达到O(1)。*/
/*//用三个指针处理，这道题主要是要注意串联链表时的一些细节处理
    public static Node listPartition(Node head, int pivot) {
        Node sB = null;//小的指针头，即small begin
        Node sE = null;//小的指针尾，即 small end
        Node eB = null;//中的指针头，即 equal begin
        Node eE = null;//中的指针尾，即emall end
        Node bB = null;//大的指针头，即 big begin
        Node bE = null;//大的指针尾，即 big end
        Node next = null;//保存下一个节点
        //进行划分
        while (head != null) {
            next = head.next;
            head.next = null;
            if (head.value < pivot) {
                if (sB == null) {
                    sB = head;
                    sE = head;
                } else {
                    sE.next = head;
                    sE = sE.next;
                }
            } else if (head.value == pivot) {
                if (eB == null) {
                    eB = head;
                    eE = head;
                } else {
                    eE.next = head;
                    eE = eE.next;
                }
            } else {
                if (bB == null) {
                    bB = head;
                    bE = head;
                } else {
                    bE.next = head;
                    bE = bE.next;
                }
            }
            head = next;
        }
        //把三部分串连起来，串联的时候细节还是挺多的，
        //串联的过程下面代码的精简程度是最学习的部分了
        
        //1.小的与中的串联
        if (sB != null) {
            sE.next = eB;
            eE = eE == null ? sE : eE;
        }
        //2.中的和大的连接
        if (eB != null) {
            eE.next = bB;
        }
        return sB != null ? sB : eB != null ? eB : bB;
    }*/
//题目13
/*复制含有随机指针节点的链表
【题目】 一种特殊的链表节点类描述如下：
public class Node { public int value; public Node next; public
Node rand;
public Node(int data) { this.value = data; }
}
Node类中的value是节点值，next指针和正常单链表中next指针的意义
一 样，都指向下一个节点，rand指针是Node类中新增的指针，这个指
针可 能指向链表中的任意一个节点，也可能指向null。 给定一个由
Node节点类型组成的无环单链表的头节点head，请实现一个 函数完成
这个链表中所有结构的复制，并返回复制的新链表的头节点。 进阶：
不使用额外的数据结构，只用有限几个变量，且在时间复杂度为 O(N)
内完成原问题要实现的函数。*/

/*题目14 两个单链表相交的一系列问题
【题目】 在本题中，单链表可能有环，也可能无环。给定两个
单链表的头节点 head1和head2，这两个链表可能相交，也可能
不相交。请实现一个函数， 如果两个链表相交，请返回相交的
第一个节点；如果不相交，返回null 即可。 要求：如果链表1
的长度为N，链表2的长度为M，时间复杂度请达到 O(N+M)，额外
空间复杂度请达到O(1)。*/

//class 5
/*实现二叉树的先序、中序、后序遍历，包括递归方式和非递归
方式*/
class treeNode
{
public:
	treeNode()
	{
		value = 0;
		left = nullptr;
		right = nullptr;
	}

	treeNode(int data)
	{
		this->value = data;
		left = nullptr;
		right = nullptr; 
	}

	void preOrderRecur(treeNode *head)//先序遍历 ：先打印当前节点 然后 先打印完左子树，然后在打印右子树 
	{
		if (head==nullptr)
		{
			return;
		}
		printf("%d + ",head->value);
		preOrderRecur(head->left);
		preOrderRecur(head->right);
	}
	void inOrderRecur(treeNode *head)//中序遍历 
	{
		if (head == nullptr)
		{
			return;
		}
		
		preOrderRecur(head->left);
		printf("%d + ", head->value);
		preOrderRecur(head->right);
	}
	void posOrderRecur(treeNode *head)//中序遍历 
	{
		if (head == nullptr)
		{
			return;
		}

		preOrderRecur(head->left);
		preOrderRecur(head->right);
		printf("%d + ", head->value);
	}

	void preOrderUnRecur(treeNode *head)
	{
		
		if (head != nullptr)
		{
			std::stack<int>my_stack;
			my_stack.push(head->value);
			while (!my_stack.empty())
			{
				int cur_value = my_stack.top();
				printf("%d", cur_value);
				my_stack.pop();
				//有右先压右，然后压左
				if (head->right != nullptr)
				{
					my_stack.push(head->right->value);
				}

				if (head->left!=nullptr)
				{
					my_stack.push(head->left->value);
				}
				
			}
		}
		
		
	}
	void inOrderUnRecur(treeNode *head)
	{
		if (head!=nullptr)
		{
			std::stack<treeNode*> nodeValue;
			while (head!=nullptr || !nodeValue.empty())
			{
				if(head!=nullptr)
				{ 
					nodeValue.push(head);
					head = head->left;
				}
				else
				{
					
					head = nodeValue.top();
					nodeValue.pop();
					printf("%d", head->value);
					head = head->right;
				}
			}
		}
	
	}
	void posOrderUnRecur1(treeNode *head)
	{
		if (head!=nullptr)
		{
			std::stack<treeNode *>s1;
			std::stack<treeNode *>s2;
			s1.push(head);
			while (!s1.empty())
			{
				head = s1.top();
				s1.pop();
				s2.push(head);
				if (head->left != nullptr)
				{
					s1.push(head->left);
				}
				if (head->right != nullptr)
				{
					s1.push(head->right);
				}
			}
			while (!s2.empty())
			{
				printf("%d", s2.top()->value);
				s2.pop();
			}
		}

	}

	void posOrderUnRecur2(treeNode *head)
	{
		if (head!=nullptr)
		{
			std::stack<treeNode*>stack;
			stack.push(head);
			treeNode *c=nullptr;
			while (!stack.empty())
			{
				c = stack.top();
				if (c->left!=nullptr && head!=c->left && head!=c->right)
				{
					stack.push(c->left);
				}
				else if (c->right != nullptr &&  head != c->right)
				{
					stack.push(c->right);
				}
				else
				{
					printf("%d",stack.top()->value);
					stack.pop();
					head = c;
				}
			}
		}
	} 
	   //题目二 如何直观的打印一颗二叉树
	
	int value;
	treeNode *left;
	treeNode *right;
	treeNode *parent;

};

//题目二 如何直观的打印一颗二叉树
//打印题目1中树的情况，逆时针90度观察可以获得空间概念的二叉树，^ ^表示其父节点为左上，v v表示父节点为左下，这样如果某一棵二叉树的节点都是一个值，也可以直观地观察到二叉树的形状。
class printBinaryTree {
public:
	void printTree(treeNode *root)
	{
		std::cout << "Print Binary Tree:" << std::endl;
		printInOrder(root, 0, "H", 17);
		std::cout << std::endl;
	}
	void printInOrder(treeNode *root, int height, std::string to, int len)
	{
		if (root == nullptr)
			return;
		printInOrder(root->right, height + 1, "v", len);
		std::string val = to + std::to_string(root->value) + to;//to_string(int value)将数值转化为字符串。返回对应的字符串
		int lenM = val.size();
		int lenL = (len - lenM) / 2;
		int lenR = len - lenM - lenL;
		val = getSpace(lenL) + val + getSpace(lenR);
		std::cout << getSpace(height * len) + val << std::endl;
		printInOrder(root->left, height + 1, "^", len);
	}
	std::string getSpace(int num)
	{
		std::string space = " ";
		std::string buf;
		for (int i = 0; i < num; i++) {
			buf.append(space);
		}
		return buf;
	}
};

void testisPalindromel()
{
	Node *a;
	InitList(a);

	int arr[4] = { 1,2,2,1 };
	insertNodeHead(a, arr, 4);
	//printList(a);
	ShowList(a);

	if (isPalindrome2(a))
		printf("yes");
	else
	{
		printf("no");
	}
	deleteList(a);
}

	//题目三
	/*在二叉树中找到一个节点的后继节点
【题目】 现在有一种新的二叉树节点类型如下：
public class Node { public int value; public Node left;
public Node right; public Node parent;
public Node(int data) { this.value = data; }
}
该结构比普通二叉树节点结构多了一个指向父节点的parent指针。假
设有一 棵Node类型的节点组成的二叉树，树中每个节点的parent指针
都正确地指向 自己的父节点，头节点的parent指向null。只给一个在
二叉树中的某个节点 node，请实现返回node的后继节点的函数。在二
叉树的中序遍历的序列中， node的下一个节点叫作node的后继节点。*/

//如果一个节点有右节点，那么他的后继节点一定是右子树的最左节点；
//当x无右子树，通过x的父指针找到父节点，判断x是否为父节点的左孩子，如果是则是后继节点，否则向上继续查找

struct ParentNode {
	int value;
	ParentNode *leftChild;
	ParentNode *rightChild;
	ParentNode *parent;
};

class getSuccessorNode {
public:
	/**层序遍历，打印节点**/
	void levelTraversal(ParentNode *root)
	{
		if (root == nullptr)
			return;
		queue<ParentNode *> qu;
		qu.push(root);
		while (!qu.empty())
		{
			root = qu.front();
			qu.pop();
			cout << "value is: " << root->value << " ";
			if (root->parent != nullptr)
				cout << "parent node is: " << root->parent->value << ". " << endl;
			else
				cout << "Root!" << endl;
			if (root->leftChild)
				qu.push(root->leftChild);
			if (root->rightChild)
				qu.push(root->rightChild);
		}
	}
	ParentNode* getNextNode(ParentNode *node)
	{
		if (node == nullptr)
			return node;
		if (node->rightChild!=nullptr)
		{
			return getLeftest(node->rightChild);
		}
		else
		{
			ParentNode *parent = node->parent;
			while (parent!=nullptr && parent->leftChild!=node)
			{
				node = parent;
				parent = node->parent;
			}
			return parent;
		}
	}
	ParentNode* getLeftest(ParentNode *node)
	{
		if (node == nullptr)
			return node;
		while (node->leftChild != nullptr)
		{
			node = node->leftChild;
		}
		return node;
	}

	/**找某个节点的前驱节点**/
	ParentNode* getPreviousNode(ParentNode *node)
	{
		if (node == nullptr)
			return nullptr;
		ParentNode *tmp = node;
		if (tmp->leftChild)//找到左孩子的最右节点
		{
			return getRightest(tmp->leftChild);
		}
		else
		{
			while (tmp->parent != nullptr)
			{
				if (tmp == tmp->parent->rightChild)
					return tmp->parent;
				else
					tmp = tmp->parent;
			}
			return nullptr;
		}
	}
	ParentNode* getRightest(ParentNode *node)
	{
		if (node == nullptr)
			return nullptr;
		while (node->rightChild != nullptr)
		{
			node = node->rightChild;
		}
		return node;
	}

};
//题目4
//介绍二叉树的序列化和反序列化
class SerializeTree {
public:
	/**先序序列化**/
	string serializeTree(treeNode *root)
	{
		if (root == nullptr)
			return "$_";
		string res = to_string(root->value) + "_";
		res = res + serializeTree(root->left);
		res = res + serializeTree(root->right);
		return res;
	}
	treeNode* reserializeTree(string serial)
	{
		vector<string> res;
		SplitString(serial, res, "_");
		queue<string> que;
		for (int i = 0; i < res.size(); i++)
		{
			que.push(res[i]);
		}
		return reconTree(que);
	}
	/**又是因为引用&符号出错，如果没有引用，每一次函数修改que,栈中会保存每个递归的
	参数，这样递归回去的时候还是没有pop的的queue,所以会出错
	为什么Java没事呢**/
	treeNode* reconTree(queue<string> &que)
	{
		string val = que.front();
		que.pop();
		queue<string> ss = que;
		if (val == "$")
		{
			return nullptr;
		}
		treeNode *root=new treeNode();
		root->value = atoi(val.c_str());
		root->left = reconTree(que);
		root->right = reconTree(que);
		return root;
	}
	/**层序序列化**/
	string levelSerial(treeNode *root)
	{
		if (root == nullptr)
			return "$_";
		queue<treeNode*> que;
		treeNode *tmp;
		que.push(root);
		string res = "";
		while (!que.empty())
		{
			tmp = que.front();
			que.pop();
			if (tmp != nullptr)
			{
				res = res + to_string(tmp->value) + "_";
				que.push(tmp->left);
				que.push(tmp->right);
			}
			else
			{
				res = res + "$_";
			}
		}
		return res;
	}
	treeNode* levelReconTree(string serial)
	{
		vector<string> res;
		SplitString(serial, res, "_");
		queue<treeNode*> que;
		treeNode *root = generateNode(res[0]);
		if (root != nullptr)
			que.push(root);
		treeNode *node = nullptr;
		int i = 1;
		while (!que.empty())
		{
			node = que.front();
			que.pop();
			node->left = generateNode(res[i++]);
			node->right = generateNode(res[i++]);
			if (node->left != nullptr)
				que.push(node->left);
			if (node->right != nullptr)
				que.push(node->right);
		}
		return root;
	}
	treeNode* generateNode(string s)
	{
		if (s == "$")
			return nullptr;
		treeNode *root = new treeNode;
		root->value = atoi(s.c_str());
		root->left = nullptr;
		root->right = nullptr;
		return root;
	}

	void SplitString(const string& s, vector<string>& v, const string& c)
	{
		string::size_type pos1, pos2;
		pos2 = s.find(c);
		pos1 = 0;
		while (string::npos != pos2)
		{
			v.push_back(s.substr(pos1, pos2 - pos1));

			pos1 = pos2 + c.size();
			pos2 = s.find(c, pos1);
		}
		if (pos1 != s.length())
			v.push_back(s.substr(pos1));
	}
};

int main()
{
	compareStr::testcomStr();

	return 0;
}
void showArr(const int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
	}
}
int FindMax(int max, int num)
{
	return (num > max) ? num : max;
}
int FindMin(int min, int num)
{
	return min = (num < min) ? num : min;
}