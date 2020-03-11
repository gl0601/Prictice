#include "class5.h"
//平衡二叉树
/*
套路：递归函数很好用 递归回回到同一个节点三次 可以解决很多问题；
以每个节点为节点的二叉树为平衡树的话，那整个二叉树就是平衡二叉树
1.左树是否平衡
2.右树是否平衡
3.左树的高度
4.右树的高度
5进行高度的比对
平衡二叉树：任何一棵树的左子树与右子树的高度差不超过1.
这里用递归函数很好用，递归会到达一个节点三次，先访问节点，然后左子树一次，右子树一次
如果以每个节点为头的树都是平衡的，这棵树是平衡的，每次递归需要判断以下几个问题，最后返回左右子树的高度差，如果不超过1就是平衡二叉树。

左树是否平衡
右树是否平衡
左树平衡，左树的高度
右树平衡，右树的高度

这里有三种实现方法，三种方法的实质都是一样的。第一种最麻烦，是根据视频学习总结的关于递归函数的涉及通用思路来写的，第2 3种实现更简单一些。
第一种，通用设计思路

列出所有可能性【上面列出的四种】
整理返回值类型【需要返回子树是否平衡，以及平衡情况下子树的高度】
整个递归过程按照同样的结构返回子树的信息
整合子树的信息，得到自己需要的信息
向上返回
*/


/*题目七：判断一棵树是否是搜索二叉树、判断一棵树是否是完全二叉树
搜索二叉树：任何一个节点，左子树上的值都比他的值小，右子树上所有的值都比它的值大
由定义可以想到，如果二叉树中序遍历是依次升序的 ，就是搜索二叉树【一般不出现重复节点，重复节点可以压缩到一个小的结构上】
在中序遍历的过程中保证升序，在非递归版本的中序遍历中进行修改
完全二叉树：
堆的结构，堆是完全二叉树，将二叉树按层遍历，

如果一个节点有右孩子没有左孩子，直接返回false
如果一个节点不是左右两个孩子都全，或者有左没右，或者左右都没有
后面遇到的所有节点都必须是叶结点，否则不是完全二叉树
*/


/*题目八：已知一棵完全二叉树，求其节点的个数
要求：时间复杂度低于O(N)，N为这棵树的节点个数
如果遍历整棵二叉树，时间复杂度为严格O（N），因为该树是完全二叉树，也就是叶子节点只在最后一层，所以可以利用满二叉树的性质进行加速。
思路：首先遍历左边界，一路走到最左边节点，可以得到该二叉树的层数depth，然后遍历右子树的左边界，如果层数也是depth,说明左子树的满二叉树，下一步递归求右子树节点个数即可。如果右子树的左边界没有到达最后一层，说明右子树是depth-1层的满二叉树，下一步递归求左子树节点个数即可。

满二叉树：高度l 节点个数2 的l次-1；

*/
int nodeNums(treeNode1 *root)
{
	if (root == nullptr)
		return 0;
	int depth = Depth(root);
	int rightD = Depth(root->rightChild) + 1;//右子树的左边界

	if (depth == rightD)
	{
		//左子树是满的，递归右子树
		return nodeNums(root->rightChild) + 1 + pow(2, depth - 1) - 1;
	}
	else
	{
		//右子树是满的递归左子树
		return nodeNums(root->leftChild) + 1 + pow(2, depth - 2) - 1;
	}

}
int Depth(treeNode1 *root)
{
	if (root == nullptr)
		return 0;
	int depth = 0;
	while (root != nullptr)
	{
		depth++;
		root = root->leftChild;
	}
	return depth;
}

//左的代码
int mostLeftLevel(treeNode1 *node,int level)
{
	while (node!=nullptr)
	{
		level++;
		node = node->leftChild;
	}
	return level - 1;
}
int bs(treeNode1 *node,int level,int h)
{
	if (level ==h)
	{
		return 1;
	}
	if ( mostLeftLevel(node->rightChild, level +1)==h)
	{
		return (1 << (h - level) + bs(node->rightChild, level + 1, h));

	}
	else
	{
		return (1 << (h - level -1) + bs(node->leftChild, level + 1, h));
	}
}

int nodeNum(treeNode1 *head)
{
	if (head==nullptr)
	{
		return 0;
	}
	return bs(head,1,mostLeftLevel(head,1));
}
/*题目五：折纸问题
【题目】 请把一段纸条竖着放在桌子上，然后从纸条的下边向上方对折1次，压出折痕后展开。此时折痕是凹下去的，即折痕突起的方向指向纸条的背面。如果从纸条的下边向上方连续对折 2 次，压出折痕后展开，此时有三条折痕，从上到下依次是下折痕、下折痕和上折痕。
给定一个输入参数N，代表纸条都从下边向上方连续对折N次， 请从上到下打印所有折痕的方向。 例如：N=1时，打印： down N=2时，打印： down down up
  注意折纸的方向都是从下向上折的，每次对折之后，关于之前的折痕，都会是折痕以上为down,折痕以上为up。
*/
