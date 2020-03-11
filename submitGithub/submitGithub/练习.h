#pragma once
#include "class5.h"

void preOrder(treeNode1 *head)
{
	if (head == nullptr)
	{
		return;
	}
		std::stack<treeNode1*>stack;
		stack.push(head);
		while (!stack.empty())
		{
			head = stack.top();
			stack.pop();
			std::cout << head->value << std::endl;
			if (head->rightChild != nullptr)
			{
				stack.push(head->rightChild);
			}

			if (head->leftChild != nullptr)
			{
				stack.push(head->leftChild);
			}
		}
	
}