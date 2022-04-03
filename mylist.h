#pragma once
#include "employee.h"
template<class T>
struct mynode
{
	T data;
	mynode<T> *next;
	mynode(mynode<T> *ptr = NULL) { next = ptr; }
	mynode(const T &item, mynode<T> *ptr = NULL)
	{
		next = ptr;
		data = item;
	}
};

template<class T>
class mylist
{
public:
	mylist() { head = new mynode<T>; head->data = 0; }//无参构造
	mylist(const T &item) { head = new mynode<T>(item); }//含参构造
	mylist(mylist<T> &list);//拷贝构造
	~mylist() { clear(); }//析构函数
	mylist<T>& operator=(mylist<T> &List) ;//重载=运算符

	void clear();//链表清空
	bool empty_judge() const { return !this->head->data; };//判断链表是否为空
	int length() const;//获取链表长度

	bool get_head(mynode<T>*);//返回附加头结点地址
	bool get_rear(T&);//返回尾部指针
	void set_head(mynode<T> *p) { head = p; }//设置链表头结点

	void insert_head(T element);//头插
	void insert_rear(T element);//尾插
	mynode<T>* find(T &item);//查找数据的位置，返回第一个找到的满足该数值的结点指针
	mynode<T>* locate(int pos);//定位指定的位置，返回该位置上的结点指针
	int position(T &item);
	bool insert( int pos,T &item);//在指定位置pos插入值为item的结点，失败返回false
	bool remove(int pos, T &item);//删除指定位置pos上的结点，把该结点值赋给item，失败返回false
	bool get_data(int pos, T &item);//获取指定位置pos的结点的值，失败返回false
	bool set_data(int pos, T &item);//设置指定位置pos的结点的值，失败返回false

	bool print() const;//打印链表
	void sort();//链表排序，排序编号
	void reverse();//链表逆置
private:
	mynode<T> *head;
};
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
mynode<T>* mylist<T>::find(T &item)
{
	if (!empty_judge())
	{
		mynode<T> *tmp = head;
		while (tmp->data != item && tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		if (tmp->data == item)
			return tmp;
	}
	return head;
}
template<class T>
int mylist<T>::position(T &item)
{
	int pos = 0;
	if (!empty_judge())
	{
		mynode<T> *tmp = head;
		while (tmp->data != item && tmp->next != NULL)
		{
			tmp = tmp->next;
			pos++;
		}
		if (tmp->data == item)
			return pos;
	}
	return pos;
}
template<class T>
mylist<T>::mylist<T>(mylist<T> &list) {
	T value;
	mynode<T> *srcptr=new mynode<T>;
	if (list.get_head(srcptr))
	{
		mynode<T> *desptr = head = new mynode<T>;
		head->data = srcptr->data;
		while (srcptr->next != NULL)
		{
			value = srcptr->next->data;
			desptr->next = new mynode<T>(value);
			desptr = desptr->next;
			srcptr = srcptr->next;
		}
		desptr->next = NULL;
	};
}
template<class T>
mylist<T>& mylist<T>::operator=(mylist<T>& L)
{
	if (!L.empty_judge())
	{
		mynode<T> *srcptr = L.head, *desptr = this->head;
		while (srcptr->next != NULL)
		{
			desptr->data = srcptr->data;
			desptr->next = new mynode<T>;
			srcptr = srcptr->next;
			desptr = desptr->next;
		}
		desptr->data = srcptr->data;
	}
	return *this;
}
template<class T>
bool mylist<T>::insert(int pos, T &item)
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
//template<class T>
//bool mylist<T>::remove(int pos, T &item)
//{
//	mynode<T> *p = locate(pos);
//	if (NULL == p)
//		return false;
//
//	mynode<T> *del = p->next;
//	p->next = del->next;
//	item = del->data;
//	delete del;
//	return true;
//}
template<class T>
bool mylist<T>::remove(int i, T& x)
{
	if (i > 0 && i <= this->head->data)
	{
		mynode<T> *tmp = this->head, *p;
		if (i != 1)
		{
			int j = 0;
			while (j != i - 1)
			{
				tmp = tmp->next;
				++j;
			}
			p = tmp->next;
			tmp->next = p->next;
			x = p->data;
			delete p;
		}
		else
		{
			p = tmp->next;
			x = p->data;
			tmp->next = p->next;
			delete p;
		}
		--this->head->data;
		return true;
	}
	return false;
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
bool mylist<T>::print() const
{
	int count = 0;
	mynode<T> *p = head;
	if (p==NULL)
	{
		return false;
	}
	while (NULL != p->next)
	{
		p = p->next;
		std::cout << p->data << " ";
		if (++count % 10 == 0)  //每隔十个元素，换行打印
			cout << std::endl;
	}
	return true;
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
bool mylist<T>::get_head(mynode<T>* element)
{
	if (head == NULL)
	{
		return false;
	}
	element =head;
	return true;
}
template<class T>
bool mylist<T>::get_rear(T& element)
{
	if (head == NULL)
	{
		return false;
	}
	mynode<T> *p = head;
	while (p->next != NULL)
		p = p->next;
	element = p->data;
	return true;
}
template<class T>
bool mylist<T>::set_data(int pos, T& item)
{
	if (pos > 0 && pos <= head->data)
	{
		int j = 0;
		mynode<T> *tmp = head;
		while (j != pos)
		{
			tmp = tmp->next;
			++j;
		}
		tmp->data = item;
		return true;
	}
	else
	{
		return false;
	}
}
template<class T>
bool mylist<T>::get_data(int pos,T&item)
{
	if (pos > 0 && pos <= head->data)
	{
		mynode<T> *tmp = head;
		int j = 0;
		while (j != pos)
		{
			tmp = tmp->next;
			++j;
		}
		item=tmp->data;
		return true;
	}
	else
	{
		return false;
	}
}
template<class T>
void mylist<T>::sort()//排序有两类方法，一种是改变指针指向的，一种是仅为元素data排序，而不改变指针指向
{
	if (this->head->data > 1)
	{
		int i = this->head->data, j;
		mynode<T> *p = this->head, *q;
		while (i)
		{
			p = p->next;
			q = p->next;
			j = i - 1;
			while (j)
			{
				if (p->data > q->data)
				{
					p->data = p->data + q->data;
					q->data = p->data - q->data;
					p->data = p->data - q->data;
					q = q->next;
				}
				--j;
			}
			--i;
		}
	}
}
template<class T>
void mylist<T>::insert_head(T element)
{
	mynode<T> *tmp = new mynode<T>;
	if (tmp == NULL)
	{
		cerr << "内存分配错误！\n" << endl;
		exit(-1);
	}

	if (this->head->next != NULL)
	{
		tmp->next = this->head->next;
		head->next = tmp;
	}
	else
	{
		head->next = tmp;
		tmp->next = NULL;
	}
	tmp->data = element;
	++this->head->data;
}
template<class T>
void mylist<T>::insert_rear(T element)
{
	mynode<T> *tmp = new mynode<T>;
	if (tmp == NULL)
	{
		cerr << "内存分配错误！\n" << endl;
		exit(-1);
	}
	mynode<T> *p = head;
	while (p->next != NULL)
		p = p->next;
	p->next = tmp;
	tmp->data = element;
	++this->head->data;
}