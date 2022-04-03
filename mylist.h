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
	mylist() { head = new mynode<T>; head->data = 0; }//�޲ι���
	mylist(const T &item) { head = new mynode<T>(item); }//���ι���
	mylist(mylist<T> &list);//��������
	~mylist() { clear(); }//��������
	mylist<T>& operator=(mylist<T> &List) ;//����=�����

	void clear();//�������
	bool empty_judge() const { return !this->head->data; };//�ж������Ƿ�Ϊ��
	int length() const;//��ȡ������

	bool get_head(mynode<T>*);//���ظ���ͷ����ַ
	bool get_rear(T&);//����β��ָ��
	void set_head(mynode<T> *p) { head = p; }//��������ͷ���

	void insert_head(T element);//ͷ��
	void insert_rear(T element);//β��
	mynode<T>* find(T &item);//�������ݵ�λ�ã����ص�һ���ҵ����������ֵ�Ľ��ָ��
	mynode<T>* locate(int pos);//��λָ����λ�ã����ظ�λ���ϵĽ��ָ��
	int position(T &item);
	bool insert( int pos,T &item);//��ָ��λ��pos����ֵΪitem�Ľ�㣬ʧ�ܷ���false
	bool remove(int pos, T &item);//ɾ��ָ��λ��pos�ϵĽ�㣬�Ѹý��ֵ����item��ʧ�ܷ���false
	bool get_data(int pos, T &item);//��ȡָ��λ��pos�Ľ���ֵ��ʧ�ܷ���false
	bool set_data(int pos, T &item);//����ָ��λ��pos�Ľ���ֵ��ʧ�ܷ���false

	bool print() const;//��ӡ����
	void sort();//��������������
	void reverse();//��������
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
		cerr << "�����ڴ�ʧ��!" << endl;
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

	//��������ÿ�ζ�ɾ��ͷ����next��㣬�����ͷ���
	while (NULL != head->next)
	{
		p = head->next;
		head->next = p->next;   //ÿ�ζ�ɾ��ͷ����next���
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
		if (++count % 10 == 0)  //ÿ��ʮ��Ԫ�أ����д�ӡ
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
void mylist<T>::sort()//���������෽����һ���Ǹı�ָ��ָ��ģ�һ���ǽ�ΪԪ��data���򣬶����ı�ָ��ָ��
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
		cerr << "�ڴ�������\n" << endl;
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
		cerr << "�ڴ�������\n" << endl;
		exit(-1);
	}
	mynode<T> *p = head;
	while (p->next != NULL)
		p = p->next;
	p->next = tmp;
	tmp->data = element;
	++this->head->data;
}