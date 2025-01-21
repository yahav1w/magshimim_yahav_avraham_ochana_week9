#include "BSNode.h"
#include <iostream>

BSNode::BSNode(std::string data)
{
	_data = data;
	_count = 1;
	_left = nullptr;
	_right = nullptr;
}

BSNode::BSNode(const BSNode& other)
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

BSNode::~BSNode()
{
	delete _left;
	delete _right;
}

void BSNode::insert(std::string value)
{
	if (!_left && !_right)
	{
		if (value < this->_data)
		{
			BSNode* temp = new BSNode(value);
			temp->_left = this->_left;
			this->_left = temp;
		}
		else if(value > this->_data)
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

BSNode& BSNode::operator=(const BSNode& other)
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

bool BSNode::isLeaf() const
{
	if (!_left && !_right)
	{
		return true;
	}
	return false;
}

std::string BSNode::getData() const
{
	return _data;
}

int BSNode::getCount() const
{
	return _count;
}

BSNode* BSNode::getLeft() const
{
	return this->_left;
}

BSNode* BSNode::getRight() const
{
	return this->_right;
}

bool BSNode::search(const std::string val) const
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

int BSNode::getHeight() const
{
	if (!_left && !_right)
	{
		return 0;
	}

	int sum1 = _left ? _left->getHeight() : 0;
	int sum2 = _right ? _right->getHeight() : 0;

	return 1 + std::max(sum1, sum2);
}

int BSNode::getDepth(const BSNode& root) const
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

void BSNode::printNodes() const
{
	if (!_left && !_right)
	{
		std::cout << this->_data + " ";
		return;
	}
	if (_left)
	{
		this->_left->printNodes();
		std::cout << this->_data + " ";
	}
	else
	{
		std::cout << this->_data + " ";
	}
	if (_right)
	{
		this->_right->printNodes();
	}
}

//int BSNode::getCurrNodeDistFromInputNode(const BSNode* node) const
//{
//	return 0;
//}
