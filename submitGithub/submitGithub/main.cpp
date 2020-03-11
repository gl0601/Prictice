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
/*===========================��Ŀһ====================================*/
//��Ŀһ :����һ������arr����һ����num�����С�ڵ���num����������
//�����ߣ�����num��������������ұߡ�
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
	//��ʾ
	for (int i = 0; i < 10; i++)
	{
		printf(" %d", arr[i]);
	}

}
/*������������������⣩
����һ������arr����һ����num�����С��num�������������
��ߣ�����num��������������м䣬����num�������������
�ұߡ�
Ҫ�����ռ临�Ӷ�O(1)��ʱ�临�Ӷ�O(N)
*/
//template<typename T>
void polandFlag(int *arr, int l, int r, int num)
{
	int left = l - 1;
	int right = r + 1;


	while (l < right)//�������֮ǰд��l<r
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
	//��ʾ
	for (int i = 0; i < len; i++)
	{
		printf(" %d", arr[i]);
	}
}
/*===========================��Ŀ��====================================*/
//����һ�����飬���������������ڲ�ֵ���ģ��ǻ��ڱȽϵ�����
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
	//0��Ͱ��n��Ͱ��������Ϣ
	bool *hasNum = new bool[n + 1];//�Ƿ�Ϊ��
	for (int i = 0; i < n + 1; i++)
	{
		hasNum[i] = false;
	}

	int *maxs = new int[n + 1];//
	int *mins = new int[n + 1];


	int bid = 0;
	for (int i = 0; i < n; i++)
	{
		bid = bucket(arr[i], n, min, max);//Ͱ�е�λ��
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
int bucket(long num, long len, long min, long max)//��λ���ŵ��ĸ�Ͱ
{
	return (int)((num - min) * len / (max - min));
}

/*===========================������ʵ��һ��ջ====================================*/

template<class T>
class Array_To_Stack
{
public:
	Array_To_Stack(int size)
	{
		arr = new int[size];
		if (arr == NULL)
		{
			printf("��̬�ڴ����ʧ��");
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
	int peek()//����ջ��
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

/*===========================������ʵ��һ������====================================*/
class  ArrayQueue
{
public:
	ArrayQueue(int InitSize)
	{
		if (InitSize < 1) printf("queue capacity must be>0");
		arr = new int[InitSize];
		if (arr == NULL)
		{
			printf("��̬�ڴ����ʧ��");
			exit(1);
		}
		this->len = InitSize;
		first = 0;
		last = 0;
		size = 0;//Ԫ�ظ���
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
/*===========================class 3 ��Ŀ�� ������ʵ��һ�������ջ====================================*/
//Ҫ�󷵻���СԪ�أ�ʱ�临�Ӷ�ΪO��1��
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

/*===========================class 3 ��Ŀ��====================================*/
//��ν��ö��нṹʵ��ջ�ṹ��
//��ν���ջ�ṹʵ�ֶ��нṹ��
//��������ʵ��
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
//��ν���ջ�ṹʵ�ֶ��нṹ��
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
//��Ŀ��:תȦ��ӡ����
void printEdge(int **arr,int tR,int tC,int dR,int dC)
{
	if (tR==dR)//���Ͻǵ������������½ǵ�����
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
//������ת90��
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

//��Ŀ�� ����Ŀ�� �ֱ�ʵ�ַ�ת��������ͷ�ת˫������ĺ�����
/*��Ҫ�� ���������ΪN��ʱ�临�Ӷ�Ҫ��ΪO(N)������ռ�
���Ӷ�Ҫ��ΪO(1)*/





//��Ŀ��
/*��֮�����δ�ӡ����
����Ŀ�� ����һ������matrix�����ա�֮�����εķ�ʽ��ӡ��
���������磺 1 2 3 4 5 6 7 8 9 10 11 12
��֮�����δ�ӡ�Ľ��Ϊ��1��2��5��9��6��3��4��7��10��11��
8��12
��Ҫ�� ����ռ临�Ӷ�ΪO(1)��*/
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
//��Ŀ��
/*�����ж��ź���ľ���������
����Ŀ�� ����һ����N*M�����;���matrix��һ������K��
matrix��ÿһ�к�ÿһ �ж����ź���ġ�ʵ��һ���������ж�K
�Ƿ���matrix�С� ���磺 0 1 2 5 2 3 4 7 4
4 4 8 5 7 7 9 ���KΪ7������true�����KΪ6����
��false��
��Ҫ�� ʱ�临�Ӷ�ΪO(N+M)������ռ临�Ӷ�ΪO(1)��*/


//��Ŀʮ
/*��ӡ������������Ĺ�������
����Ŀ�� �����������������ͷָ��head1��head2����ӡ����
����Ĺ������֡�*/

//��Ŀʮһ
/*�ж�һ�������Ƿ�Ϊ���Ľṹ
����Ŀ�� ����һ�������ͷ�ڵ�head�����жϸ������Ƿ�Ϊ��
�Ľṹ�� ���磺 1->2->1������true�� 1->2->2->1������true��
15->6->15������true�� 1->2->3������false��
���ף� ���������ΪN��ʱ�临�ӶȴﵽO(N)������ռ临��
�ȴﵽ ��*/

void insertNodeHead(Node *&L, int arr[], int len)//��һ���������ĩ�ڵ� ����
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
//ʹ��O(N)�����ռ�, ��Ӧ�����汾��
bool isPalindromel(Node *head)
{
	//Node *cur = new Node();
	Node *cur = head->next;
	Node *p = head->next;
	
	std::stack<int> node_value;
	while (cur!=NULL)//������ѹջ
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
//ʹ��O(N/2)�����ռ�, ��Ӧ�����汾��
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
//	ע��haead��һ��ָ�벻������
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
//need O��1��extra space
bool isPalindrome3(Node* head) {
	if (head == nullptr || head->next == nullptr) {
		return true;
	}
	//������ʱ�������е㣬ż����ʱ�������е��ǰһ��
	Node* n1 = head;    // slow pointer
	Node* n2 = head;    // fast pointer
	while (n2->next != nullptr && n2->next->next != nullptr) {
		n1 = n1->next;
		n2 = n2->next->next;
	}
	n2 = n1->next;    // n2 now is the first node in the second list
	n1->next = nullptr;
	Node* n3 = nullptr;    // A ListNode to store the last node in the second list
	//��벿������
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
	//�ָ��ֳ�
	while (n1 != nullptr) {//recover list
		n2 = n1->next;
		n1->next = n3;
		n3 = n1;
		n1 = n2;
	}
	return true;

}

/*��Ŀʮ������������ĳֵ���ֳ����С���м���ȡ��ұߴ����ʽ
����Ŀ�� ����һ�����������ͷ�ڵ�head���ڵ��ֵ���������ͣ��ٸ���һ��
�� ��pivot��ʵ��һ����������ĺ��������������Ϊ�󲿷ֶ���ֵС�� pivot
�Ľڵ㣬�м䲿�ֶ���ֵ����pivot�Ľڵ㣬�Ҳ��ֶ���ֵ���� pivot�Ľڵ㡣
�����Ҫ���⣬�Ե�����Ľڵ�˳��û�и����Ҫ�� ���磺����9->0->4->5-
>1��pivot=3�� ���������������1->0->4->9->5��Ҳ������0->1->9->5->4����
֮���� ���󲿷ֶ���С��3�Ľڵ㣬�м䲿�ֶ��ǵ���3�Ľڵ㣨�����������
��Ϊ�գ����Ҳ��ֶ��Ǵ���3�Ľڵ㼴�ɡ���ĳ�����ڲ��Ľڵ�˳���� Ҫ��
���ף� ��ԭ�����Ҫ��֮����������������Ҫ��
�����С����������ֵ��ڲ�Ҳ��˳��Ҫ��Ҫ��ÿ������Ľڵ���� ���ҵ�
˳����ԭ�����нڵ���Ⱥ����һ�¡� ���磺����9->0->4->5->1��pivot=3��
�������������0->1->9->4->5�� ������ԭ����Ҫ���ͬʱ���󲿷ֽڵ����
��Ϊ0��1����ԭ������Ҳ ���ȳ���0�������1���м䲿���ڱ�����Ϊ�գ�����
���ۣ��Ҳ��ֽڵ� ������Ϊ9��4��5����ԭ������Ҳ���ȳ���9��Ȼ�����4��
������5��
���������ΪN��ʱ�临�Ӷ���ﵽO(N)������ռ临�Ӷ���ﵽO(1)��*/
/*//������ָ�봦���������Ҫ��Ҫע�⴮������ʱ��һЩϸ�ڴ���
    public static Node listPartition(Node head, int pivot) {
        Node sB = null;//С��ָ��ͷ����small begin
        Node sE = null;//С��ָ��β���� small end
        Node eB = null;//�е�ָ��ͷ���� equal begin
        Node eE = null;//�е�ָ��β����emall end
        Node bB = null;//���ָ��ͷ���� big begin
        Node bE = null;//���ָ��β���� big end
        Node next = null;//������һ���ڵ�
        //���л���
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
        //�������ִ���������������ʱ��ϸ�ڻ���ͦ��ģ�
        //�����Ĺ����������ľ���̶�����ѧϰ�Ĳ�����
        
        //1.С�����еĴ���
        if (sB != null) {
            sE.next = eB;
            eE = eE == null ? sE : eE;
        }
        //2.�еĺʹ������
        if (eB != null) {
            eE.next = bB;
        }
        return sB != null ? sB : eB != null ? eB : bB;
    }*/
//��Ŀ13
/*���ƺ������ָ��ڵ������
����Ŀ�� һ�����������ڵ����������£�
public class Node { public int value; public Node next; public
Node rand;
public Node(int data) { this.value = data; }
}
Node���е�value�ǽڵ�ֵ��nextָ���������������nextָ�������
һ ������ָ����һ���ڵ㣬randָ����Node����������ָ�룬���ָ
��� ��ָ�������е�����һ���ڵ㣬Ҳ����ָ��null�� ����һ����
Node�ڵ�������ɵ��޻��������ͷ�ڵ�head����ʵ��һ�� �������
������������нṹ�ĸ��ƣ������ظ��Ƶ��������ͷ�ڵ㡣 ���ף�
��ʹ�ö�������ݽṹ��ֻ�����޼�������������ʱ�临�Ӷ�Ϊ O(N)
�����ԭ����Ҫʵ�ֵĺ�����*/

/*��Ŀ14 �����������ཻ��һϵ������
����Ŀ�� �ڱ����У�����������л���Ҳ�����޻�����������
�������ͷ�ڵ� head1��head2����������������ཻ��Ҳ����
���ཻ����ʵ��һ�������� ������������ཻ���뷵���ཻ��
��һ���ڵ㣻������ཻ������null ���ɡ� Ҫ���������1
�ĳ���ΪN������2�ĳ���ΪM��ʱ�临�Ӷ���ﵽ O(N+M)������
�ռ临�Ӷ���ﵽO(1)��*/

//class 5
/*ʵ�ֶ��������������򡢺�������������ݹ鷽ʽ�ͷǵݹ�
��ʽ*/
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

	void preOrderRecur(treeNode *head)//������� ���ȴ�ӡ��ǰ�ڵ� Ȼ�� �ȴ�ӡ����������Ȼ���ڴ�ӡ������ 
	{
		if (head==nullptr)
		{
			return;
		}
		printf("%d + ",head->value);
		preOrderRecur(head->left);
		preOrderRecur(head->right);
	}
	void inOrderRecur(treeNode *head)//������� 
	{
		if (head == nullptr)
		{
			return;
		}
		
		preOrderRecur(head->left);
		printf("%d + ", head->value);
		preOrderRecur(head->right);
	}
	void posOrderRecur(treeNode *head)//������� 
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
				//������ѹ�ң�Ȼ��ѹ��
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
	   //��Ŀ�� ���ֱ�۵Ĵ�ӡһ�Ŷ�����
	
	int value;
	treeNode *left;
	treeNode *right;
	treeNode *parent;

};

//��Ŀ�� ���ֱ�۵Ĵ�ӡһ�Ŷ�����
//��ӡ��Ŀ1�������������ʱ��90�ȹ۲���Ի�ÿռ����Ķ�������^ ^��ʾ�丸�ڵ�Ϊ���ϣ�v v��ʾ���ڵ�Ϊ���£��������ĳһ�ö������Ľڵ㶼��һ��ֵ��Ҳ����ֱ�۵ع۲쵽����������״��
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
		std::string val = to + std::to_string(root->value) + to;//to_string(int value)����ֵת��Ϊ�ַ��������ض�Ӧ���ַ���
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

	//��Ŀ��
	/*�ڶ��������ҵ�һ���ڵ�ĺ�̽ڵ�
����Ŀ�� ������һ���µĶ������ڵ��������£�
public class Node { public int value; public Node left;
public Node right; public Node parent;
public Node(int data) { this.value = data; }
}
�ýṹ����ͨ�������ڵ�ṹ����һ��ָ�򸸽ڵ��parentָ�롣��
����һ ��Node���͵Ľڵ���ɵĶ�����������ÿ���ڵ��parentָ��
����ȷ��ָ�� �Լ��ĸ��ڵ㣬ͷ�ڵ��parentָ��null��ֻ��һ����
�������е�ĳ���ڵ� node����ʵ�ַ���node�ĺ�̽ڵ�ĺ������ڶ�
��������������������У� node����һ���ڵ����node�ĺ�̽ڵ㡣*/

//���һ���ڵ����ҽڵ㣬��ô���ĺ�̽ڵ�һ����������������ڵ㣻
//��x����������ͨ��x�ĸ�ָ���ҵ����ڵ㣬�ж�x�Ƿ�Ϊ���ڵ�����ӣ���������Ǻ�̽ڵ㣬�������ϼ�������

struct ParentNode {
	int value;
	ParentNode *leftChild;
	ParentNode *rightChild;
	ParentNode *parent;
};

class getSuccessorNode {
public:
	/**�����������ӡ�ڵ�**/
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

	/**��ĳ���ڵ��ǰ���ڵ�**/
	ParentNode* getPreviousNode(ParentNode *node)
	{
		if (node == nullptr)
			return nullptr;
		ParentNode *tmp = node;
		if (tmp->leftChild)//�ҵ����ӵ����ҽڵ�
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
//��Ŀ4
//���ܶ����������л��ͷ����л�
class SerializeTree {
public:
	/**�������л�**/
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
	/**������Ϊ����&���ų������û�����ã�ÿһ�κ����޸�que,ջ�лᱣ��ÿ���ݹ��
	�����������ݹ��ȥ��ʱ����û��pop�ĵ�queue,���Ի����
	ΪʲôJavaû����**/
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
	/**�������л�**/
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