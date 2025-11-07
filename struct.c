#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list 
{
	int				nb;
	struct s_list	*next;
}t_list;


int main (void)
{
	// il faut proteger le malloc et free
	t_list *root = malloc(sizeof(t_list));
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	root->nb = 42; 
	node1 ->nb = 45; 
	node2 -> nb = 54;
	root->next = node1; 
	node1->next = node2;
	node2->next = NULL;

	t_list *current;
	current = root;
	while (current)
	{
		printf("%d\n", current->nb);
		current = current ->next;
	}
	

}
