#include <iostream>
#include <string.h>

#include "String2.h"

String2::StrNode sm_nNodes = 0;
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
	clear_strnode();
	StrNode* prev = find_prev();
	if(prev!=nullptr) prev->pNext = pNext;
	sm_nNodes--;
}

//String2::StrNode& String2::StrNode::operator=(const char* oc) {
//}

String2::StrNode* String2::StrNode::find_prev() const {
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

std::ostream& operator<<(std::ostream& os, const String2::StrNode& on)
{
	if(on.pData!=nullptr) os << *on.pData;
	return os;
}

//========================================================================

std::ostream& operator<<(std::ostream& os, const String2& on)
{
	if (on.DataNode != nullptr) os << *on.DataNode;
	return os;
}


String2::String2(const char* data)
	:DataNode(nullptr) {
	if (data == nullptr) return;
	StrNode* cur = String2::StrNode::find_eq(data);
	if (cur != nullptr) { DataNode = cur; ++(* cur); return; }
	DataNode = new String2::StrNode(data);
}

String2::String2(String2& os)
{
	DataNode = os.DataNode;
	++(*os.DataNode);
}

String2& String2::operator=(String2& os)
{
	DataNode = os.DataNode;
	++(*os.DataNode);
	return *this;
}

String2& String2::operator=(char* oc)
{
	StrNode* cur = String2::StrNode::find_eq(oc);
	if (cur != nullptr) { DataNode = cur; ++(*cur); }
	else DataNode = new String2::StrNode(oc);
	return *this;
}

bool String2::operator==(const char* oc) const
{
	StrNode* cur = String2::StrNode::find_eq(oc);
	return (cur!=nullptr);
}

void String2::print_list()
{
	StrNode* cur = String2::StrNode::sm_pHead;
	while (cur != nullptr) {
		std::cout << cur->m_NOwners << '\t' << cur << std::endl;
		cur = cur->pNext;
	}
}
