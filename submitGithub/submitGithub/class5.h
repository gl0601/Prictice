
#pragma once
#include <iostream>
#include <queue>
#include <stack>


class treeNode1
{
public:
	int value;
	treeNode1 *leftChild;
	treeNode1 *rightChild;

};

class Node
{
public:

	int value;
	Node *next;

};

class isBan
{
public:

	isBan(bool isB,int h )
	{
		this->isBanlance = isB;
		this->depth = h;
	}

	isBan()
	{
		isBanlance = false;
		depth = 0;
	}
	
	bool isBanlance;
	int depth;

};

int nodeNums(treeNode1 *root);
int Depth(treeNode1 *root);
//列出所有的可能性treeNode
//1.左树是否平衡
//2.右树是否平衡
//3.左树的高度
//4.右树的高度
//5进行高度的比对

class BanlancedTree {
public:

	bool isBalanced(treeNode1*root) {
		if (root == nullptr)
			return true;
		return isBalancedHelper(root)->isBanlance;
	}
	isBan* isBalancedHelper(treeNode1 *root)
	{
		if (root==nullptr)
		{
			return new isBan(true, 0);
		}
		isBan* left = isBalancedHelper(root->leftChild);
		if (left->isBanlance == false)
			return new isBan(false, 0);
		isBan* right = isBalancedHelper(root->leftChild);
		if (right->isBanlance == false)
			return new isBan(false, 0);
		if (abs(left->depth - right->depth) > 1)
		{
			return new isBan(false, 0);
		}
		return new isBan(true, std::max(left->depth, right->depth) + 1);
	}
};

class judgeTree {
public:
	bool isSearchBiTree(treeNode1 *root)
	{
		if (root == nullptr)
			return true;
		std::stack<treeNode1*> s;
		int tmp = INT_MIN;
		while (!s.empty() || root != nullptr)
		{
			if (root != nullptr)
			{
				s.push(root);
				root = root->leftChild;
			}
			else
			{
				root = s.top();
				s.pop();
				if (root->value > tmp)
					tmp = root->value;
				else
					return false;
				root = root->rightChild;
			}
		}
		return true;
	}
	bool isCompleteBiTree(treeNode1 *root)
	{
		if (root == nullptr)
			return true;
		std::queue<treeNode1 *> que;
		que.push(root);
		bool leaf = false;
		treeNode1 *left;
		treeNode1 *right;
		while (!que.empty())
		{
			root = que.front();
			que.pop();
			left = root->leftChild;
			right = root->rightChild;
			if ((leaf && (left != nullptr || right != nullptr)) || (left == nullptr && right != nullptr))
			{
				return false;
			}
			if (left)
			{
				que.push(left);
			}
			if (right)
			{
				que.push(right);
			}
			else
			{
				leaf = true;
			}
		}
		return true;
	}
};