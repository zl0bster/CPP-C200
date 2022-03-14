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
		static size_t sm_nNodes;
		static StrNode* sm_pHead;
		//-----------------------
		StrNode(const char* data = nullptr, const StrNode* prev = nullptr);
		~StrNode();
		inline StrNode& operator++() { m_NOwners++; }
		inline StrNode& operator--() { m_NOwners--; if (m_NOwners == 0) clear_strnode(); }
		StrNode& operator=(const char* oc);
		char* get();
		friend std::ostream& operator<<(std::ostream& os, const StrNode& on);
	private:
		void clear_strnode() { delete pData; pData = nullptr; }
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
	char* get();
	void print_list();
	friend std::ostream& operator<<(std::ostream& os, const String2& on);
};