#pragma once
#include <iostream>


class String2
{
public:
	class StrNode
	{
	public:
		StrNode* pNext = nullptr;
		char* pData = nullptr;
		size_t m_NOwners = 0;
		//
		static size_t sm_nNodes;
		static StrNode* sm_pHead;
		//
		StrNode(const char* data = nullptr);
		~StrNode();
		inline StrNode& operator++() { m_NOwners++; return *this; }
		inline StrNode& operator--() { m_NOwners--; if (m_NOwners == 0) delete this; }
		StrNode& operator=(const char* oc);
		const char* get() { return pData; }
		friend std::ostream& operator<<(std::ostream& os, const StrNode& on);
	private:
		void clear_strnode() { delete pData; pData = nullptr; }
		StrNode* find_prev();
		StrNode* find_eq(const char*);
	};

private:
	StrNode* DataNode;
	//----------------
	String2(const char* data = nullptr);
	String2(String2& os);
	String2& operator=(String2& os);
	String2& operator=(char* oc);
	bool operator==(const String2& os);
	bool operator==(const char* oc);
	const char* get() { return DataNode->pData; }
	void print_list();
	friend std::ostream& operator<<(std::ostream& os, const String2& on);
};