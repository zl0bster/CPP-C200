#include <iostream>
#include <string.h>

#include "String2.h"

size_t String2::StrNode::sm_nNodes = 0;
String2::StrNode* String2::StrNode::sm_pHead = nullptr;

String2::StrNode::StrNode(const char* data)
	:pNext(sm_pHead),
	m_NOwners(1) {
	size_t len = strlen(data) + 1;
	pData = new char[len];
	memcpy(pData, data, len);
	sm_pHead = this;
	sm_nNodes++;
}

//  find previous node and remove current from chain
String2::StrNode::~StrNode() {
	clear_strnode();
	StrNode* prev = find_prev();
	if (this == sm_pHead) sm_pHead = pNext;
	if (prev != nullptr) prev->pNext = pNext;
	sm_nNodes--;
}

void String2::StrNode::decrease_nOwners() {
	if (pData != nullptr) {
		m_NOwners--;
		if (m_NOwners == 0) delete this;
	}
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
	if (sm_nNodes != 0) {
		StrNode* curr = sm_pHead;
		while (curr->pNext != nullptr) {
			if ((strcmp(curr->pData, ch)) == 0) return curr;
			curr = curr->pNext;
		}
	}
	return nullptr;
}

std::ostream& operator<<(std::ostream& os, const String2::StrNode& on)
{
	if (on.pData != nullptr) os << on.pData;
	return os;
}

//========================================================================

std::ostream& operator<<(std::ostream& os, const String2& on)
{
	if (on.data_node != nullptr) os << *on.data_node;
	return os;
}


String2::String2(const char* data)
	:data_node(nullptr) {
	if (data == nullptr) return;
	StrNode* cur = String2::StrNode::find_eq(data);
	if (cur != nullptr) { data_node = cur; ++(*cur); return; }
	data_node = new String2::StrNode(data);

}

String2::String2(const String2& os)
{
	data_node = os.data_node;
	++(*this->data_node);
}
String2::~String2()
{
	if (data_node != nullptr) {
		data_node->decrease_nOwners();
	}
}

String2& String2::operator=(const String2& os)
{
	if (os.data_node==data_node) return *this;
	if (data_node != nullptr) {
		data_node->decrease_nOwners();
	}
	data_node = os.data_node;
	++(*this->data_node);
	return *this;
}

String2& String2::operator=(const char* oc)
{
	StrNode* cur = String2::StrNode::find_eq(oc);
	if (cur != nullptr) { data_node = cur; ++(*cur); }
	else data_node = new String2::StrNode(oc);
	return *this;
}

bool String2::operator==(const char* oc) const
{
	StrNode* cur = String2::StrNode::find_eq(oc);
	return (cur != nullptr);
}

void String2::print_list()
{
	StrNode* cur = String2::StrNode::sm_pHead;
	while (cur != nullptr) {
		std::cout << cur->m_NOwners << '\t';
		if (cur->pData != nullptr) std::cout << cur->pData;
		std::cout << std::endl;
		cur = cur->pNext;
	}
}
