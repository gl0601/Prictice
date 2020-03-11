
#pragma once
#include "class5.h"
#include <unordered_map>
#include <vector>
#include <cstring>
#include <algorithm>

//��ϣ��
using namespace std;
/*���RandomPool�ṹ
����Ŀ�� ���һ�ֽṹ���ڸýṹ���������������ܣ�
insert(key)����ĳ��key���뵽�ýṹ���������ظ����롣
delete(key)����ԭ���ڽṹ�е�ĳ��key�Ƴ��� getRandom()��
�ȸ���������ؽṹ�е��κ�һ��key��
��Ҫ�� Insert��delete��getRandom������ʱ�临�Ӷȶ���
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

//��¡������
/*

*/

/*һ���Թ�ϣ����������ƣ�

*/ 

/*���鼯�� ���鼯��Ҫ���������á�1�������Բ�ѯ����Ԫ��A��B�ǲ���ͬһ����������ġ�2�������԰�A��B����Ԫ�����ڵļ��Ϻϲ�������ע��������Ԫ�����ڵļ��ϣ�����������Ԫ�ء�ʹ�ò��鼯��ʱ��Ҫһ���԰�����ȫ�����룬��֧�ֶ�̬�ı仯��
������˵һ��ʵ�ֲ��鼯�Ľṹ��
���鼯�Ľṹ�ǳ��򵥣����Ǻ���ʵ���ԣ��ڴ�������ƽ������£����ҵĸ��Ӷȿ���ΪO(1)����ԭ�����£�
�������ǽ�һ�����е�ÿ��Ԫ�ض�����һ�����ϣ�ͬʱ�����Ԫ�ر��Ϊ������ϵĴ���ڵ㣬��ô��α���أ��ܼ򵥣��丸�ڵ����Լ��Ľڵ�ͽ�������ڵ㣡��ˣ������ڲ��鼯������ʹ��unordered_map(Ҳ����STL�е�unordered_map)��������Ϣ���棬key��ʾ��ǰ�ڵ㣬value��ʾ���ڵ㣡Ȼ�����ǻ�Ҫ������һ��unordered_map�������漯�ϵĴ�С����Ϣ��key��ʾ�ڵ㣬value��ʾ��ǰ�ڵ����ڼ����еĽڵ�������
ע�⣺�ڵ���������Ϣֻ�Դ���ڵ���Ч�������ڵ������Ϣ����Ч�ģ�
����������鼯�ṹ������õķ������������ֱ��ǣ�

findRep()   ���Ҵ���ڵ�
Union()   �ϲ��������ϣ��ϲ�ʱС���ϻ�ϲ����󼯺��£��ܵĴ���ڵ�Ϊ�󼯺ϵĴ���ڵ�
isSameSet()   �����ж����������ǲ�����ͬһ��������


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
//		void makeSet(list<int> nodes)//һ���Եõ����е�����
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
//		 //��unordered_map�н��в��������ַ�ʽ�����ǰ�����װ�ɶ������ʽ�����£�
//		 // Hash[10] = 100;
//
//		 void Union(int a, int b) 
//		 {
//			 char aRep = findHead(a);
//			 char bRep = findHead(b);
//			 if (aRep != bRep) {
//				 int aSize = sizeMap[aRep];//��ȡ�ڵ���
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

//������
/*������
һ��������ֻ��0��1����ֵ��ÿ��λ�ö����Ժ��Լ����ϡ��¡�����
�ĸ�λ�������������һƬ1����һ��������ֽ���һ��������һ��
�������ж��ٸ�����
������
0 0 1 0 1 0
1 1 1 0 1 0
1 0 0 1 0 0
0 0 0 0 0 0
�������������������*/
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
	int N = lands.size();//����
	int M = lands[0].size();//����
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

//ǰ׺��
const int MaxBranchNum = 26;//������չ

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
		//��stringת��Ϊ�ַ�������
		char *buf=new char[str.size()];
		strcpy(buf,str.c_str());
	
		TrieNode* node = root;
		int idenx = 0;
		for (int i=0;i<strlen(buf);i++)
		{
			idenx = buf[i] - 'a';
			if (node->nexts[idenx]==nullptr)//��û������ǰ�ڵ��·����û�еĻ��ͽ�����
			{
				node->nexts[idenx] = new TrieNode();
			}
			node = node->nexts[idenx];
			node->path++;//��һ��·����������ڵ�

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
			return node->end;//����Ĵ���
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

//�ֵ���
/*��Ŀ�� ����һ���ַ������͵�����strs���ҵ�һ��ƴ�ӷ�ʽ��ʹ�ð���
���� ����ƴ����֮���γɵ��ַ���������͵��ֵ���*/
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