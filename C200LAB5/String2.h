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
		//StrNode& operator=(const char* oc);
		const char* get() const { return pData; }
		static StrNode* find_eq(const char*);
		friend std::ostream& operator<<(std::ostream& os, const StrNode& on);
	private:
		void clear_strnode() { delete pData; pData = nullptr; }
		StrNode* find_prev() const;
	};

private:
	StrNode* data_node;
	//----------------
public:
	String2(const char* data = nullptr);
	String2(const String2& os);
	String2& operator=(const String2& os);
	String2& operator=(char* oc);
	bool operator==(const String2& os) const { return (data_node==os.data_node); };
	bool operator==(const char* oc) const;
	const char* get() const { return data_node->pData; }
	static void print_list();
	friend std::ostream& operator<<(std::ostream& os, const String2& on);
};