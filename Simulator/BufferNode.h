#pragma once
#include "Customer.h"

class BufferNode {
protected:
	  Customer* data;
	  BufferNode *_next;
	  BufferNode *_prev;
	  bool m_isFirst;
	  bool m_marker;
public:
	  BufferNode(bool);
	  BufferNode* setCustomer(Customer* data);
	  BufferNode* prev();
	  BufferNode* next();
	  BufferNode* insert();
	  BufferNode* remove();
	  Customer* getCustomer();
};
