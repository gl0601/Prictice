
#pragma once
#include "class5.h"
#include <unordered_map>
#include <vector>
#include <cstring>
#include <algorithm>

//哈希表
using namespace std;
/*设计RandomPool结构
【题目】 设计一种结构，在该结构中有如下三个功能：
insert(key)：将某个key加入到该结构，做到不重复加入。
delete(key)：将原本在结构中的某个key移除。 getRandom()：
等概率随机返回结构中的任何一个key。
【要求】 Insert、delete和getRandom方法的时间复杂度都是
O(1)*/
//class RadndomPoolTest
//{
//public:
//	RadndomPoolTest() :size(0) {}
//	
//	~RadndomPoolTest() {}
//	
//	void add(string str)
//	{
//		if (map1.find(str) == map1.end())
//		{
//			map1.insert(make_pair(str, size));
//			map2.insert(make_pair(size, str));
//			size++;
//		}
//		
//	}
//
//	string getRadndom()
//	{
//		if (size = 0)
//		{
//			return nullptr;
//		}
//
//		int idenx=rand()%size;
//		return map2[idenx];
//
//	}
//	void reMove(string str)
//	{
//		if (map1.find(str)!=map1.end())
//		{
//			int deleteIndex = map1[str];
//			int lastidenx = --size;
//			string lastStr = map2[lastidenx];
//			
//			map1.erase(str);
//			map1.erase(lastStr);
//			map2.erase(deleteIndex);
//			map2.erase(lastidenx);
//			map1.insert(make_pair(lastStr, deleteIndex));
//			map2.insert(make_pair(deleteIndex, lastStr));
//		}
//	}
//
//public:
//	unordered_map<string, int> map1;
//	unordered_map<int, string> map2;
//	int size;
//
//};

//布隆过滤器
/*

*/

/*一致性哈希（服务器设计）

*/ 

/*并查集： 并查集主要有两个作用。1：它可以查询两个元素A和B是不是同一个集合里面的。2：它可以把A和B两个元素所在的集合合并起来，注意是两个元素所在的集合，而不是两个元素。使用并查集的时候要一次性把数据全部输入，不支持动态的变化。
下面来说一下实现并查集的结构：
并查集的结构非常简单，但是很有实用性，在大量数据平均情况下，查找的复杂度可以为O(1)，其原理如下：
首先我们将一个序列的每个元素都当做一个集合，同时将这个元素标记为这个集合的代表节点，那么如何标记呢？很简单，其父节点是自己的节点就叫做代表节点！因此，我们在并查集机构中使用unordered_map(也就是STL中的unordered_map)来进行信息储存，key表示当前节点，value表示父节点！然后我们还要建立另一个unordered_map用来保存集合的大小的信息，key表示节点，value表示当前节点所在集合中的节点总数！
注意：节点总数的信息只对代表节点有效，其他节点这个信息是无效的！
并且这个并查集结构对外调用的方法有三个，分别是：

findRep()   查找代表节点
Union()   合并两个集合，合并时小集合会合并到大集合下，总的代表节点为大集合的代表节点
isSameSet()   用来判断两个集合是不是在同一个集合下


*/
//namespace gl
//{
//	
//	class UnionFindSet
//	{
//	public:
//		UnionFindSet()
//		{
//			//fatherMap = new unordered_map <Node, Node>();//key:child value:father
//			//sizeMap = new unordered_map <Node, int>();
//		}
//
//		void makeSet(list<int> nodes)//一次性得到所有的数据
//		{
//			fatherMap.clear();
//			sizeMap.clear();
//			for (int node:nodes)
//			{
//				fatherMap.insert(node,node);
//				sizeMap.insert(node,1);
//			}
//		}
//		 int findHead(int node)
//		{
//			 int father = fatherMap[node];
//			 
//			 if (father!= node)
//			 {
//				 father = findHead(father);
//			 }
//
//			 fatherMap.insert(node,father);
//			 return father;
//		}
//		 
//		 bool isSameSet(int a, int b) 
//		 {
//			 return findHead(a) == findHead(b);
//		 }
//		 //在unordered_map中进行插入有三种方式，都是把它封装成对象的形式。如下：
//		 // Hash[10] = 100;
//
//		 void Union(int a, int b) 
//		 {
//			 char aRep = findHead(a);
//			 char bRep = findHead(b);
//			 if (aRep != bRep) {
//				 int aSize = sizeMap[aRep];//获取节点数
//				 int bSize = sizeMap[bRep];
//				 if (aSize > bSize) {
//					 fatherMap[b] = a;
//					 sizeMap[a] += sizeMap[b];
//				 }
//				 else {
//					 fatherMap[a] = b;
//					 sizeMap[b] += sizeMap[a];
//				 }
//			 }
//		 }
//		 
//	private:
//
//		unordered_map <int, int> fatherMap;
//		unordered_map <int, int>  sizeMap;
//
//	};
//
//
//}

//岛问题
/*岛问题
一个矩阵中只有0和1两种值，每个位置都可以和自己的上、下、左、右
四个位置相连，如果有一片1连在一起，这个部分叫做一个岛，求一个
矩阵中有多少个岛？
举例：
0 0 1 0 1 0
1 1 1 0 1 0
1 0 0 1 0 0
0 0 0 0 0 0
这个矩阵中有三个岛。*/
void infectLands(std::vector<std::vector<int>>& lands, int N, int M, int n, int m) {
	if (n < 0 || n >= N || m < 0 || m >= M || lands[n][m] != 1) {
		return;
	}
	lands[n][m] = 2;
	infectLands(lands, N, M, n + 1, m);
	infectLands(lands, N, M, n - 1, m);
	infectLands(lands, N, M, n, m + 1);
	infectLands(lands, N, M, n, m - 1);
}

int countIslands(std::vector<std::vector<int>>& lands) {
	if (lands.size() == 0 || lands[0].size() == 0) {
		return 0;
	}
	int res = 0;
	int N = lands.size();//行数
	int M = lands[0].size();//列数
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (lands[i][j] == 1) {
				res++;
				infectLands(lands, N, M, i, j);
			}

		}
	}
	return res;
}

//前缀树
const int MaxBranchNum = 26;//可以扩展

class TrieNode
{
public:
	string word;
	int path;
	int end;
	TrieNode *nexts[MaxBranchNum];

	TrieNode()
	{
		word = "";
		path = 0;
		end = 0;
		memset(nexts, NULL, sizeof(TrieNode*) * MaxBranchNum);

	}

};

class Trie
{
public:
	Trie()
	{
		root = new TrieNode();
	}

	~Trie()
	{
		while (root!=nullptr)
		{
			delete root;
		}
	}

	void insert(string str)
	{
		if (str=="")
		{
			return;
		}
		//将string转化为字符串数组
		char *buf=new char[str.size()];
		strcpy(buf,str.c_str());
	
		TrieNode* node = root;
		int idenx = 0;
		for (int i=0;i<strlen(buf);i++)
		{
			idenx = buf[i] - 'a';
			if (node->nexts[idenx]==nullptr)//有没有走向当前节点的路径，没有的话就建出来
			{
				node->nexts[idenx] = new TrieNode();
			}
			node = node->nexts[idenx];
			node->path++;//有一条路径划过这个节点

		}
		node->end++;
		node->word = str;
	}
	void deleteStr(string str)
	{
		if (str=="")
			return;

		if (search(str)!=0)
		{
			char *buf = new char[str.size()];
			strcpy(buf, str.c_str());
			TrieNode* node = root;
			TrieNode*temp;
			int idenx = 0;
			for (int i = 0; i < strlen(buf); i++)
			{
				idenx = buf[i] - 'a';
				temp = node->nexts[idenx];
				if (--node->nexts[idenx]->path == 0)
				{
					delete node->nexts[idenx];
				}
				node = temp;
			}
			node->end--;
		}

	}
	int search(string str)
	{
		if (str == "")
			return 0;
		char *buf = new char[str.size()];
		strcpy(buf,str.c_str());
		TrieNode* node = root;
		for (int i=0;i<strlen(buf);i++)
		{
			int idenx = buf[i] - 'a';
			if (node->nexts==nullptr)
			{
				return 0;
			}
			node = node->nexts[idenx];
		}

		if (node!=nullptr)
		{
			return node->end;//插过的次数
		}
		else
		{
			return 0;
		}
	}
	int prefixNumbers(string str)
	{
		if (str == "")
			return 0;
		char *buf=new char[str.size()];
		strcpy(buf, str.c_str());
		TrieNode* node = root;
		int index = 0;
		for (int i = 0; i < strlen(buf); i++)
		{
			index = buf[i] - 'a';
			if (node->nexts[index] == nullptr)
			{
				return 0;
			}
			node = node->nexts[index];
		}
		return node->path;
		
	}
	void printPre(string str)
	{
		if (str == "")
			return;
		char *buf=new char[str.size()];
		strcpy(buf, str.c_str());
		TrieNode* node = root;
		int index = 0;
		for (int i = 0; i < strlen(buf); i++)
		{
			index = buf[i] - 'a';
			if (node->nexts[index] == nullptr)
			{
				return;
			}
			node = node->nexts[index];
		}
		Print(node);
		
	}
	void Print(TrieNode* node)
	{
		if (node == nullptr)
			return;
		if (node->word != "")
		{
			cout << node->word << " " << node->path << endl;
		}
		for (int i = 0; i < MaxBranchNum; i++)
		{
			Print(node->nexts[i]);
		}
	
	}

	void printAll()
	{
		Print(root);
	}
private:
	TrieNode *root;

};

void testTrieNode()
{
	cout << "Hello world!" << endl;
	Trie trie;
	string str = "li";
	cout << trie.search(str) << endl;
	trie.insert(str);
	cout << trie.search(str) << endl;
	trie.deleteStr(str);
	cout << trie.search(str) << endl;
	trie.insert(str);
	cout << trie.search(str) << endl;

	trie.insert(str);
	cout << trie.search(str) << endl;

	trie.deleteStr("li");
	cout << trie.search(str) << endl;
	trie.deleteStr("li");
	cout << trie.search(str) << endl;
	trie.insert("lia");
	trie.insert("lic");
	trie.insert("liab");
	trie.insert("liad");
	trie.deleteStr("lia");
	cout << trie.search("lia") << endl;
	cout << trie.prefixNumbers("lia") << endl;//

}

//字典序
/*题目七 给定一个字符串类型的数组strs，找到一种拼接方式，使得把所
有字 符串拼起来之后形成的字符串具有最低的字典序。*/
namespace compareStr
{
	bool cmp(string &str1,string &str2)
	{
		return str1 + str2 < str2 + str1 ? true : false;
	}
	string lowestString(vector<string>& str)
	{
		if (str.size() == 0) return "";
		int len = str.size();
		string res;
		sort(str.begin(),str.end(),cmp);
		for (int i = 0; i < len; i++)
		{
			res += str[i];

		}
		return res;
	}
	
	void testcomStr()
	{
		std::vector<std::string> str1 = { "b", "ba" };
		std::vector<std::string> str2 = { "jibw", "ji", "jp", "bw", "jibw" };
		std::string res1 = lowestString(str1);
		std::string res2 = lowestString(str2);
		std::cout << res1 << std::endl;
		std::cout << res2 << std::endl;
	}
	
}