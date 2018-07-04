#pragma once

template<class Type>
class LinkList
{
	// Constructors
public:
	LinkList();
	~LinkList();

	// Public methods
public:
	Type at(int index) const;
	int  indexOf(Type obj) const;
	void push_back(Type value);
	void push_begin(Type value);

	// Private members
private:
	int m_index;
	Type m_value;
	LinkList* m_pnext_node;

	// Private methods
private:
	LinkList* get_first_node(LinkList* list) const;
	LinkList* get_last_node(LinkList* list) const;
};

