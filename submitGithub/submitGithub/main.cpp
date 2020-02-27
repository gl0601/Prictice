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
/*===========================class 4 ��Ŀ��====================================*/

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