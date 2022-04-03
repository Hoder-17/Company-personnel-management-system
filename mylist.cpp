#include "mylist.h"
//template <class T>
//mylist<T>::mylist()
//{
//	head = current = NULL;
//}
//template <class T>
//mylist<T>::~mylist()
//{
//	clear();
//}
//template <class T>
//mylist<T>::mylist(const mylist <T> &aplist)
//{
//	deepcopy();
//}
//template <class T>
//void mylist<T>::insert_head(const T &element)
//{
//	current = NULL;
//	node <T>*newnode = new node < T >;
//	newnode->data = element;
//	newnode->next = head;
//	head = newnode;
//}
//template <class T>
//void mylist<T>::insert_end(const T &element)
//{
//	current = NULL;
//	node <T>*newnode = new node < T >;
//	node <T>*tail = head;
//	newnode->data = element;
//	newnode->next = NULL;
//	if (tail==NULL)
//	{
//		head = newnode;
//	}
//	else
//	{
//		while (tail->next!=NULL)
//		{
//			tail = tail->next;
//		}
//		tail->next = newnode;
//	}
//}
//
template<class T>
mynode<T>* mylist<T>::locate(int pos)
{
	int i = 0;
	mynode<T> *p = head;

	if (pos < 0)
		return NULL;

	while (NULL != p && i < pos)
	{
		p = p->next;
		i++;
	}

	return p;
}
template<class T>
mylist<T>::mylist<T>(mylist<T> &List) {
	head = List.head;
}
template<class T>
mylist<T>& mylist<T>::operator=(mylist<T> &List) {
	head = List.head;
}
template<class T>
bool mylist<T>::insert(T &item, int pos)
{
	mynode<T> *p = locate(pos);
	if (NULL == p)
		return false;

	mynode<T> *node = new mynode<T>(item);
	if (NULL == node)
	{
		cerr << "分配内存失败!" << endl;
		exit(1);
	}
	node->next = p->next;
	p->next = node;
	return true;
}
template<class T>
bool mylist<T>::remove(int pos, T &item)
{
	mynode<T> *p = locate(pos);
	if (NULL == p || NULL == p->next)
		return false;

	mynode<T> *del = p->next;
	p->next = del->next;
	item = del->data;
	delete del;
	return true;
}
template<class T>
void mylist<T>::clear()
{
	mynode<T> *p = NULL;

	//遍历链表，每次都删除头结点的next结点，最后保留头结点
	while (NULL != head->next)
	{
		p = head->next;
		head->next = p->next;   //每次都删除头结点的next结点
		delete p;
	}
}
template<class T>
void mylist<T>::print() const
{
	int count = 0;
	mynode<T> *p = head;
	while (NULL != p->next)
	{
		p = p->next;
		std::cout << p->data << " ";
		if (++count % 10 == 0)  //每隔十个元素，换行打印
			cout << std::endl;
	}
}

template<class T>
int mylist<T>::length() const
{
	int count = 0;
	mynode<T> *p = head->next;
	while (NULL != p)
	{
		p = p->next;
		++count;
	}
	return count;
}
template<class T>
void mylist<T>::reverse()
{
	mynode<T> *pre = head->next;
	mynode<T> *curr = pre->next;
	mynode<T> *next = NULL;

	head->next->next = NULL;
	while (curr)
	{
		next = curr->next;
		curr->next = pre;
		pre = curr;
		curr = next;
	}

	head->next = pre;
}
template<class T>
bool mylist<T>::getHead(T& element)
{
	if (head==NULL)
	{
		return false;
	}
	element = head->data;
	return true;
}