
/********************************************************************************************
																		    				
Tempelate Binary search Tree																
Feel free to make use of it at anytime, for any reason, in anyway, without any obligations	
@Hesham Magdy																				
																							
*********************************************************************************************/
#include "BSTNode.h"
#include <iostream>
#include <algorithm>
using namespace std;

namespace BST 
{
	template <class data_type>
	class BST:public BSTNode<data_type>
	{
	public:
		BST<data_type>();
		virtual void insert(data_type value);
		void remove(data_type value);
		bool search(data_type value);
		data_type min();
		data_type max();
		bool isEmpty();
		bool isBalance();
		bool isSubTree(BST* t1, BST* t2);
		void printRange(data_type first, data_type last);
		void print();
		~BST();
	private:
		BSTNode * root;
		BSTNode * insert(data_type value, BSTNode *node);
		BSTNode * remove(data_type value, BSTNode *node);
		BSTNode * search(data_type value, BSTNode *node);
		BSTNode * min(BSTNode* node);
		BSTNode * max(BSTNode* node);
		bool isBalance(BSTNode* node);
		bool Identical(BSTNode*t1, BSTNode*t2);
		bool isSubTree(BSTNode*t1, BSTNode*t2);
		int  maxHeight(BSTNode* node);
		int  minHeight(BSTNode* node);
		int  height(BSTNode* node);
		void printRange(data_type first, data_type last, BSTNode*node);
		void print(BSTNode *node);


	};


	template <class data_type>
	BST<data_type>::BST():BSTNode()
	{
		root = nullptr;
	}

	template<class data_type>
	void BST<data_type>::insert(data_type value)
	{
		insert(value, root);
	}

	template<class data_type>
	void BST<data_type>::remove(data_type value)
	{
		if (isEmpty())
			cout << "Tree is empty" << endl;
		else 
			remove(value, root);
	}

	template<class data_type>
	bool BST<data_type>::search(data_type value)
	{
		 
		return search(value, root) == nullptr ? false : true;
	}

	template<class data_type>
	data_type BST<data_type>::min()
	{
		return min(root)->data;
	}

	template<class data_type>
	data_type BST<data_type>::max()
	{
		return max(root)->data;
	}

	template<class data_type>
	bool BST<data_type>::isEmpty()
	{
		return (root==nullptr);
	}

	template<class data_type>
	bool BST<data_type>::isBalance()
	{
		return isBalance(root);
	}

	template<class data_type>
	bool BST<data_type>::isSubTree(BST * t1, BST * t2)
	{
		return isSubTree(t1->root, t2->root);
	}

	template<class data_type>
	void BST<data_type>::printRange(data_type first, data_type last)
	{
		printRange(first, last, root);
	}

	template<class data_type>
	void BST<data_type>::printRange(data_type first, data_type last, BSTNode*node)
	{
		if (node == nullptr)
			return;
		
		if (first < node->data)
		{
			printRange(first, last, node->left);
		}
		if (first<=node->data&&last>=node->data)
		{
			cout << node->data << " ";
		}
		if (node->data < last)
		{
			printRange(first, last, node->right);
		}
		
	}
	template<class data_type>
	void BST<data_type>::print()
	{
		print(root);
	}

	template<class data_type>
	BST<data_type>::~BST()
	{
		delete root;
	}

	template<class data_type>
	BSTNode<data_type>* BST<data_type>::insert(data_type value, BSTNode * node)
	{
		if (root == nullptr)
		{
			root = new BSTNode<data_type>;
			root->data = value;
		}
		if (node == nullptr)
		{
			node = new BSTNode<data_type>;
			node->data = value;
		}
		else if (value > node->data)
		{
			node->right=insert(value, node->right);
		}

		else if (value < node->data)
		{
			node->left=insert(value, node->left);
		}

		return node;
	}

	template<class data_type>
	BSTNode<data_type>* BST<data_type>::remove(data_type value, BSTNode * node)
	{
		if (node == nullptr)
			return nullptr;
		else if (value > node->data)
			node->right = remove(value, node->right);

		else if (value < node->data)
			node->left = remove(value, node->left);
		else
		{
			if (node->right&&node->left)
			{
				BSTNode * temp;
				temp = min(root->right);
				node->data = temp->data;
				node->right = remove(temp->data, node->right);
			}
			else
			{
				BSTNode * temp;
				temp = node;
				if (node->left == nullptr)
					node = node->right;
				else if (node->right == nullptr)
					node = node->left;
			}
		}
		return node;
	}

	template<class data_type>
	BSTNode<data_type> * BST<data_type>::search(data_type value, BSTNode * node)
	{
		if (node == nullptr)
			return nullptr;
		else if (value > node->data)
			node->right = search(value, node->right);

		else if (value < node->data)
			node->left = search(value, node->left);
		else
			return node;
	}

	template<class data_type>
	BSTNode<data_type> * BST<data_type>::min(BSTNode * node)
	{
		if (node == nullptr)
			return nullptr;
	    else if (node->left == nullptr)
			return node;
		else
			min(node->left);
	}

	template<class data_type>
	BSTNode<data_type> * BST<data_type>::max(BSTNode * node)
	{
		if (node == nullptr)
			return nullptr;
		else if (node->right == nullptr)
			return node;
		else
			max(node->right);
	}

	template<class data_type>
	bool BST<data_type>::isBalance(BSTNode * node)
	{
		if (node == nullptr)
			return true;
		int left_height=height(node->left);
		int right_height=height(node->right);

		if ((abs(left_height-right_height)) != 1&& (abs(left_height - right_height)) != 0)
			return false;

		else
		{
			isBalance(node->left);
			isBalance(node->right);
		}
	}

	template<class data_type>
	bool BST<data_type>::Identical(BSTNode * t1, BSTNode * t2)
	{

		if (t1 == nullptr&&t2 == nullptr)
			return true;
		if (t1 == nullptr||t2 == nullptr)
			return false;

		if (t1->data == t2->data&&t1 != nullptr&&t2 != nullptr);
		{
			return (Identical(t1->left, t2->left) && Identical(t1->right, t2->right));
		}

	}

	template<class data_type>
	bool BST<data_type>::isSubTree(BSTNode * t1, BSTNode * t2)
	{
		if (t2 == nullptr)
			return true;
		if (t1 == nullptr)
			return false;
		if (Identical(t1, t2))
			return true;
		else
		{
			if (isSubTree(t1->left, t2))
				return true;
			if (isSubTree(t1->right, t2))
				return true;
			return false;
		}
	}

	template<class data_type>
	int BST<data_type>::maxHeight(BSTNode * node)
	{
		if (node == nullptr)
			return 0;
		else
			return 1 + std::max(height(node->right), height(node->left));
	}

	template<class data_type>
	int BST<data_type>::minHeight(BSTNode * node)
	{
		if (node == nullptr)
			return 0;
		else
			return 1 + std::min(height(node->right), height(node->left));
	}

	template<class data_type>
	int BST<data_type>::height(BSTNode * node)
	{
		if (node == nullptr)
			return 0;
		else
			return 1 + std::max(height(node->right), height(node->left));
	}

	template<class data_type>
	void BST<data_type>::print(BSTNode * node)
	{
		if (node == nullptr)
			return;
		cout << node->data << " ";
		
		print(node->left);
		print(node->right);

	}

}
