#include "BufferNode.h"

BufferNode::BufferNode(bool flag):
	_next(this), _prev(this), data(0), m_isFirst(flag), m_marker(false) {}

BufferNode *BufferNode::setCustomer(Customer *data)
{
	this->data = data;
	return this;
}

BufferNode *BufferNode::prev()
{
	return _prev;
}

BufferNode *BufferNode::next()
{
	return _next;
}

BufferNode *BufferNode::insert()
{
	BufferNode* b = new BufferNode(false);
	BufferNode* c = _next;
	b->_next = c;
	this->_next = b;
	c->_prev = b;
	return b;
}

Customer *BufferNode::getCustomer()
{
	return data;
}
