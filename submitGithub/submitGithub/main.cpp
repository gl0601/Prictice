#include <iostream>
#include <stack>
#include <queue>
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


int main()
{
	//Array_To_Stack<int> arr(3);

	//arr.push(1);
	//arr.push(2);
	//arr.push(3);

	////int arr[10] = {0,1,3,5,5,8,7,9,18};

	//printf("%d",arr.sizeofarr());
	printf("ceshi");
	printf("1");
	printf("3");
	printf("4");
	test05();
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