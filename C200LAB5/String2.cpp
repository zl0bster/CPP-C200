#include <iostream>
#include <string.h>

#include "String2.h"

String2::StrNode sm_node = 0;
String2::StrNode sm_pHead = nullptr;

String2::StrNode::StrNode(const char* data)
	:pNext(sm_pHead),
	m_NOwners(1) {
	size_t len = strlen(data) + 1;
	pData = new char[len];
	memcpy(pData, data, len);
	sm_pHead = this;
	sm_nNodes++;
}

// todo find previous node and remove current from chain
String2::StrNode::~StrNode() {
}

String2::StrNode& String2::StrNode::operator=(const char* oc) {
}

String2::StrNode* String2::StrNode::find_prev() {
	//returns nullptr if wrong or node is last one | single one
	StrNode* curr = sm_pHead;
	while (curr->pNext != nullptr) {
		if (curr->pNext == this) return curr;
		curr = curr->pNext;
	}
	return nullptr;
}

String2::StrNode* String2::StrNode::find_eq(const char* ch) {
	//returns nullptr if not found
	StrNode* curr = sm_pHead;
	while (curr->pNext != nullptr) {
		if ((strcmp(curr->pData, ch)) == 0) return curr;
		curr = curr->pNext;
	}
	return nullptr;
}
