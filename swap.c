/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwardeng <jwardeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:38:57 by jwardeng          #+#    #+#             */
/*   Updated: 2024/12/23 17:40:08 by jwardeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

/*  void swap_nodes(d_list *node1, d_list *node2)
{
        d_list *temp;
        
        if(node1 == NULL || node2 == NULL)
        return;
        temp->item = node1->item;
        node1->item = node2->item;
        node2->item = temp->item;
} */

 void swap_nodes(d_list **head)
{
    d_list *tmp1;
    d_list *tmp2;
    d_list *store;


}

int main()
{
    d_list *node1 = malloc(sizeof(d_list));
    d_list *node2 = malloc(sizeof(d_list));
    d_list *node3 = malloc(sizeof(d_list));
    if(!node1 || !node2 || !node3)
    return(1);
    int data = 5;
    int data2 = 6;
    node1->item = data;
    node1->next = node2;
    node1->prev = NULL;
    node2->item = data2;
    node2->next = node3;
    node2->prev = node1;
    node3->item = data2;
    node3->prev = node2;
    node3->next =NULL;
    printf("before1: %d\n", node1->item);
    printf("before2: %d\n", node2->item);
    printf("before3: %d\n", node3->item);
    swap_nodes(&node1);
    printf("after1: %d\n", node1->item);
    printf("after2: %d\n", node2->item);
    printf("after3: %d\n", node3->item);
    return(0);
}