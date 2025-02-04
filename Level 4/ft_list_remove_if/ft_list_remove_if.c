// Passed Moulinette 2019.09.01

#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
	if (begin_list == NULL || *begin_list == NULL)
		return;

	t_list *cur = *begin_list;

	if (cmp(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else // if there is a no else, you cant pass the Moulinette, tryed 2023.09.08
	{
		cur = *begin_list;
		ft_list_remove_if(&cur->next, data_ref, cmp);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

t_list *create_elem(void *data)
{
    t_list *new = malloc(sizeof(t_list));
    if (!new)
        return NULL;
    new->data = data;
    new->next = NULL;
    return new;
}

void print_list(t_list *list)
{
    while (list)
    {
        printf("%d -> ", *(int *)(list->data));
        list = list->next;
    }
    printf("NULL\n");
}

int cmp(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int a = 1, b = 2, c = 3, d = 2, e = 5;
    int ref = 2;

    t_list *list = create_elem(&a);
    list->next = create_elem(&b);
    list->next->next = create_elem(&c);
    list->next->next->next = create_elem(&d);
    list->next->next->next->next = create_elem(&e);

    printf("Lista original:\n");
    print_list(list);

    ft_list_remove_if(&list, &ref, cmp);

    printf("Lista após remover %d:\n", ref);
    print_list(list);

    return 0;
}
