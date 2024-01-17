// Вариант 1.
// Ввести последовательность натуральных чисел.
//  Если в последовательности есть простые числа,
//   упорядочить последовательность по неубыванию суммы цифр.
//    В противном случае удалить из последовательности числа
//     с нечетным количеством цифр и продублировать 4-хзначные числа.
//      Последовательность хранить в односвязном списке.

#include <iostream>

struct Node
{
    int data;
    Node *next;
};

bool is_prime(int n)
{
    if (n == 2 || n == 3)
        return true;
    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int get_digit_sum(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void order_seq(Node *&root)
{
    Node *prev = nullptr;
    Node *curr = root;
    Node *next = nullptr;
    bool is_swapped = true;
    while (is_swapped)
    {
        is_swapped = false;
        curr = root;
        while (curr->next != prev)
        {
            if (get_digit_sum(curr->data) > get_digit_sum(curr->next->data))
            {
                next = curr->next;
                curr->next = next->next;
                next->next = curr;
                if (prev == nullptr)
                {
                    root = next;
                }
                else
                {
                    prev->next = next;
                }
                prev = next;
                is_swapped = true;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }
}

void remove_odd_d_dupe_four_d_nums(Node *&root)
{
    Node *prev = nullptr;
    Node *curr = root;
    Node *next = nullptr;
    while (curr != nullptr)
    {
        int num = curr->data;
        if (num < 1000)
        {
            if (num % 2 != 0)
            {
                next = curr->next;
                if (prev == nullptr)
                {
                    root = next;
                }
                else
                {
                    prev->next = next;
                }
                delete curr;
                curr = next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        else if (num >= 10000)
        {
            Node *newNode = new Node;
            newNode->data = num;
            newNode->next = curr->next;
            curr->next = newNode;
            prev = curr;
            curr = newNode->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}

void print_seq(Node *root)
{
    while (root != nullptr)
    {
        std::cout << root->data << " ";
        root = root->next;
    }
    std::cout << std::endl;
}

void deleteList(Node *&root)
{
    Node *curr = root;
    while (curr != nullptr)
    {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
    root = nullptr;
}

int main()
{
    Node *root = nullptr;
    Node *last = nullptr;
    int num;
    while (true)
    {
        std::cin >> num;
        if (num == 0)
        {
            break;
        }
        Node *newNode = new Node;
        newNode->data = num;
        newNode->next = nullptr;
        if (root == nullptr)
        {
            root = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
    }

    bool has_primes = false;
    Node *curr = root;
    while (curr != nullptr)
    {
        if (is_prime(curr->data))
        {
            has_primes = true;
            break;
        }
        curr = curr->next;
    }

    if (has_primes)
    {
        order_seq(root);
    }
    else
    {
        remove_odd_d_dupe_four_d_nums(root);
    }

    print_seq(root);
    deleteList(root);

    return 0;
}