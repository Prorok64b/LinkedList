#pragma once

template<class Type>
class LinkList
{
	// Constructors
public:
	LinkList();
	LinkList(Type value, LinkList<Type>* next_node);
	~LinkList();

	// Public methods
public:
	Type at(int index);
	int  length();
	void push_back(Type value);
	void remove(int index);
	void Release();

	// Private members
private:
	Type			m_value;
	LinkList<Type>* m_pnext_node;

	// Private methods
private:
	LinkList<Type>* get_last_node(LinkList<Type>* list) const;
	LinkList<Type>* get_parent_node(LinkList<Type>* list, int index, int& counter);
	Type*			find_value(LinkList<Type>* list, int index, int& counter);
	void			count_nodes(LinkList<Type>* list, int& counter);
	void			rec_destroy(LinkList<Type>* list);
};

// Not class methods
template<class Type>
void push_front(LinkList<Type>** list, Type value)
{
	*list = new LinkList<Type>(value, *list);
}

// Constructors
template<typename Type>
LinkList<Type>::LinkList()
{
	m_value = NULL;
	m_pnext_node = nullptr;
}

template<class Type>
inline LinkList<Type>::LinkList(Type value, LinkList<Type>* next_node)
{
	m_value = value;
	m_pnext_node = next_node;
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
	Type* node = find_value(this, index, counter);

	if (!node) return NULL;
	else if(node)
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

template<class Type>
inline void LinkList<Type>::remove(int index)
{
	int counter = 0;
	LinkList<Type>* parent = get_parent_node(this, index, counter);

	if (!parent) throw("no element with such index");
	else if (parent)
	{
		LinkList<Type>* temp = parent->m_pnext_node;
		parent->m_pnext_node = parent->m_pnext_node->m_pnext_node;
		delete temp;
	}
}

template<class Type>
inline void LinkList<Type>::Release()
{
	rec_destroy(this);
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
inline LinkList<Type>* LinkList<Type>::get_parent_node(LinkList<Type>* list, int index, int& counter)
{
	if (list && list->m_pnext_node && counter + 1 == index)
		return list;
	else if (list->m_pnext_node->m_pnext_node)
	{
		counter++;
		return get_parent_node(list->m_pnext_node, index, counter);
	}

	return nullptr;
}

template<class Type>
inline Type* LinkList<Type>::find_value(LinkList<Type>* list, int index, int& counter)
{
	if (list && counter == index)
		return &(list->m_value);
	else if (list->m_pnext_node)
	{
		counter++;
		return find_value(list->m_pnext_node, index, counter);
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

template<class Type>
inline void LinkList<Type>::rec_destroy(LinkList<Type>* list)
{
	if (!list) return;

	if (list->m_pnext_node)
	{
		rec_destroy(list->m_pnext_node);
	}

	delete list;
}
