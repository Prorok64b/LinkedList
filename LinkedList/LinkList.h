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
	Type at(int index);
	int  indexOf(Type obj) const;
	int  length();
	void push_back(Type value);
	void push_begin(Type value);
	void remove(int index);

	// Private members
private:
	Type			m_value;
	LinkList<Type>* m_pnext_node;

	// Private methods
private:
	LinkList<Type>* get_first_node(LinkList<Type>* list) const;
	LinkList<Type>* get_last_node(LinkList<Type>* list) const;
	Type*			find_node(LinkList<Type>* list, int index, int& counter);
	void			count_nodes(LinkList<Type>* list, int& counter);
};


// Constructors
template<typename Type>
LinkList<Type>::LinkList()
{
	m_value = NULL;
	m_pnext_node = nullptr;
}

template<typename Type>
LinkList<Type>::~LinkList()
{
}

// Public methods
template<class Type>
inline Type LinkList<Type>::at(int index)
{
	int counter = 0;
	Type* node = find_node(this, index, counter);

	if (!node) return NULL;

	return *node;
}

template<class Type>
inline int LinkList<Type>::length()
{
	int counter = 0;
	count_nodes(this, counter);
	return counter;
}

template<typename Type>
void LinkList<Type>::push_back(Type value)
{
	LinkList<Type>* last_node = get_last_node(this);

	if (!last_node->m_value)
	{
		m_value = value;
		return;
	}
	else if (last_node)
	{
		last_node->m_pnext_node = new LinkList<Type>();
		last_node->m_pnext_node->m_value = value;
	}
}

// Private methods
template<typename Type>
LinkList<Type>* LinkList<Type>::get_last_node(LinkList<Type>* list) const
{
	if (list)
	{
		if (!list->m_pnext_node)
		{
			return list;
		}
		else if (list->m_pnext_node)
		{
			return get_last_node(list->m_pnext_node);
		}
	}

	return nullptr;
}

template<class Type>
inline Type* LinkList<Type>::find_node(LinkList<Type>* list, int index, int& counter)
{
	if (list && counter == index)
		return &(list->m_value);
	else if (list->m_pnext_node)
	{
		counter++;
		return find_node(list->m_pnext_node, index, counter);
	}

	return nullptr;
}

template<class Type>
void LinkList<Type>::count_nodes(LinkList<Type>* list, int& counter)
{
	if (list && list->m_value)
	{
		counter++;
		count_nodes(list->m_pnext_node, counter);
	}
	return;
}
