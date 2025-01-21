#pragma once
#include "iostream"
#include <string>

template <class T>
class BSNode
{
public:
	BSNode(T data);
	BSNode(const BSNode<T>& other);

	~BSNode();

	void insert(T value);
	
	BSNode<T>& operator=(const BSNode<T>& other);

	bool isLeaf() const;
	T getData() const;
	int getCount() const;
	BSNode<T>* getLeft() const;
	BSNode<T>* getRight() const;


	bool search(const T val) const;

	int getHeight() const;
	int getDepth(const BSNode<T>& root) const;

	void printNodes() const; //for question 1 part C

private:
	T _data;
	BSNode* _left;
	BSNode* _right;

	int _count; //for question 1 part B
	//int getCurrNodeDistFromInputNode(const BSNode* node) const; //auxiliary function for getDepth

};

template<class T>
inline BSNode<T>::BSNode(T data)
{
	_data = data;
	_count = 1;
	_left = nullptr;
	_right = nullptr;
}

template<class T>
inline BSNode<T>::BSNode(const BSNode<T>& other)
{
	this->_data = other._data;
	this->_count = other._count;
	_left = nullptr;
	_right = nullptr;
	if (other._left)
	{
		this->_left = new BSNode(*other._left);
	}
	if (other._right)
	{
		this->_right = new BSNode(*other._right);
	}
}

template<class T>
inline BSNode<T>::~BSNode()
{
	delete _left;
	delete _right;
}

template<class T>
inline void BSNode<T>::insert(T value)
{
	if (!_left && !_right)
	{
		if (value < this->_data)
		{
			BSNode* temp = new BSNode(value);
			temp->_left = this->_left;
			this->_left = temp;
		}
		else if (value > this->_data)
		{
			BSNode* temp = new BSNode(value);
			temp->_right = this->_right;
			this->_right = temp;
		}
		else
		{
			_count++;
		}
	}
	else if (value < this->_data)
	{
		if (this->_left == nullptr)
		{
			BSNode* temp = new BSNode(value);
			temp->_left = this->_left;
			this->_left = temp;
		}
		else
		{
			this->_left->insert(value);
		}
	}
	else if (value > this->_data)
	{
		if (this->_right == nullptr)
		{
			BSNode* temp = new BSNode(value);
			temp->_right = this->_right;
			this->_right = temp;
		}
		else
		{
			this->_right->insert(value);
		}
	}
	else
	{
		_count++;
	}
}

template<class T>
inline BSNode<T>& BSNode<T>::operator=(const BSNode<T>& other)
{
	delete _left;
	delete _right;

	_data = other._data;
	_count = other._count;
	if (other._left)
	{
		_left = new BSNode(*other._left);
	}
	if (other._right)
	{
		_right = new BSNode(*other._right);
	}

	return *this;
}

template<class T>
inline bool BSNode<T>::isLeaf() const
{
	if (!_left && !_right)
	{
		return true;
	}
	return false;
}

template<class T>
inline T BSNode<T>::getData() const
{
	return _data;
}

template<class T>
inline int BSNode<T>::getCount() const
{
	return _count;
}

template<class T>
inline BSNode<T>* BSNode<T>::getLeft() const
{
	return this->_left;
}

template<class T>
inline BSNode<T>* BSNode<T>::getRight() const
{
	return this->_right;
}

template<class T>
inline bool BSNode<T>::search(const T val) const
{
	if (val == _data)
	{
		return true;
	}
	if (_left && val < _data)
	{
		return this->_left->search(val);
	}
	if (_right && val > _data)
	{
		return this->_right->search(val);
	}
	return false;
}

template<class T>
inline int BSNode<T>::getHeight() const
{
	if (!_left && !_right)
	{
		return 0;
	}

	int sum1 = _left ? _left->getHeight() : 0;
	int sum2 = _right ? _right->getHeight() : 0;

	return 1 + std::max(sum1, sum2);
}

template<class T>
inline int BSNode<T>::getDepth(const BSNode<T>& root) const
{
	if (this == &root || &root == nullptr)
	{
		return 0;
	}
	if (root._left)
	{
		int depth = this->getDepth(*(root._left));
		if (depth != -1)
		{
			return 1 + depth;
		}
	}
	if (root._right)
	{
		int depth = this->getDepth(*(root._right));
		if (depth != -1)
		{
			return 1 + depth;
		}
	}

	return -1;
}

template<class T>
inline void BSNode<T>::printNodes() const
{
	if (!_left && !_right)
	{
		std::cout << this->_data << " ";
		return;
	}
	if (_left)
	{
		this->_left->printNodes();
		std::cout << this->_data << " ";
	}
	else
	{
		std::cout << this->_data << " ";
	}
	if (_right)
	{
		this->_right->printNodes();
	}
}
