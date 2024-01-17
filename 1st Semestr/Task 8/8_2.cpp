// Ввести последовательность натуральных чисел.
//  Если последовательность упорядочена по невозрастанию или по неубыванию,
//   удалить из последовательности числа, в которые входят цифры 2 и 8
//    (одновременно), и продублировать числа, заканчивающиеся цифрой 5.
//     В противном случае упорядочить последовательность по неубыванию.
// 	 Последовательность хранить в односвязном списке.


#include <iostream>


struct Node
{
	int val;
	Node *next;
};
struct linked_list
{
	Node *first;
	Node *last;
	bool is_empty()
	{
		return first == nullptr;
	}
	Node *get_el_by_index(int index)
	{
		if (is_empty())
			throw;
		if (length() <= index)
			throw;
		if (index < 0)
			index += length();
		Node *current = first;
		for (size_t i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current;
	}
	int length()
	{
		if (is_empty())
			return 0;
		int counter = 1;
		Node *current = first;
		while (current != last)
		{
			counter++;
			current = current->next;
		}
		return counter;
	}
	int elem(int index)
	{
		return get_el_by_index(index)->val;
	}
	void print()
	{
		if (is_empty())
			return;
		Node *current = first;
		while (current)
		{
			std::cout << current->val << ' ';
			current = current->next;
		}
		std::cout << std::endl;
	}
	void append(int n)
	{
		Node *elem = new Node();
		elem->val = n;
		if (is_empty())
		{
			first = elem;
			last = elem;
			return;
		}
		last->next = elem;
		last = elem;
	}
	void pop(int index)
	{
		if ((index == 0) && (length() == 1))
		{
			first = nullptr;
			return;
		}
		if (index == 0)
		{
			first = get_el_by_index(1);
			return;
		}
		if (index == length() - 1)
		{
			last = get_el_by_index(index - 1);
			last->next = nullptr;
			return;
		}
		get_el_by_index(index - 1)->next = get_el_by_index(index + 1);
		return
	}
}