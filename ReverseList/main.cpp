#include <iostream>

struct linkedlist
{
    int data;
    struct linkedlist* next;
};

struct linkedlist* reverse(struct linkedlist* head)
{
    struct linkedlist* reverseHead = head;
    if (reverseHead)
    {
        struct linkedlist* node = reverseHead->next;
        reverseHead->next = NULL;
        while (node)
        {
            struct linkedlist* tmp = node->next;
            node->next = reverseHead;
            reverseHead = node;
            node = tmp;
        }
    }
    return reverseHead;
}

void print(struct linkedlist* head)
{
    struct linkedlist* node = head;
    while (node)
    {
       std::cout << node->data;
       node = node->next;
       if (node)
           std::cout << "->";
    }
    std::cout << std::endl;
}

int main()
{
    struct linkedlist* list1 = NULL;
    print(list1);
    struct linkedlist* list2 = reverse(list1);
    print(list2);
    struct linkedlist list3Node1 = { 1, NULL };
    struct linkedlist list3Node2 = { 2, NULL };
    struct linkedlist list3Node3 = { 3, NULL };
    struct linkedlist list3Node4 = { 4, NULL };
    list3Node1.next = &list3Node2;
    list3Node2.next = &list3Node3;
    list3Node3.next = &list3Node4;
    list3Node4.next = NULL;
    struct linkedlist* list3 = &list3Node1;
    print(list3);
    struct linkedlist* list4 = reverse(list3);
    print(list4);
    return 0;
}
