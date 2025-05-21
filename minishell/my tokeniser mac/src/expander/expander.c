#include "minishell.h"

t_ast_node  *expand_node(t_ast_node *node, char **envp)
{
	if (node->type == AST_CMD)
		expand_command(node, envp);
	else if (node->type == AST_REDIRECT)
		expand_redirect(node, envp);
	return (node);
}
//expand the command node
void	expand_command(t_ast_node *node, char **envp)
{
	char **args;
	t_list *expanded_args_ll;//rename to args_ll?

	expanded_args_ll = NULL;
	args = node->u_data.cmd.args;
	while (*args)
	{
		expand_one_arg(*args, &expanded_args_ll, envp);//need to pass envp
		args++
	}
	//convert the linked list to an array
	node->u_data.cmd.args = convert_ll_to_array(expanded_args_ll);
	//free the linked list?
}

//expand the redirect node except heredoc
void	expand_redirect(t_ast_node *node, char **envp)
{
	char *unexpanded_filename;
	t_list *expanded_filenames_ll;
	
	//check if the redirect is heredoc
	//if it is, do not expand
	if (node->u_data.redirect.type == TOKEN_HEREDOC)
		return;

	expanded_filenames_ll = NULL;
	unexpanded_filename = node->u_data.redirect.file;
	expand_one_arg(unexpanded_filename, &expanded_filenames_ll, envp);
	if (ft_lstsize(expanded_filenames_ll) != 1
		|| expanded_filenames_ll->content == "") //might be risky, use ft_strcmp?
	{
		perror("expand_redirect: invalid redirect");
		return;
	}
	else
		node->u_data.redirect.file = expanded_filenames_ll->content;
}

//convert the linked list to an array //check this its ChatGPT code
char **convert_ll_to_array(t_list *args_ll)
{
	char **args;
	int i;

	i = 0;
	args = malloc(sizeof(char *) * (ft_lstsize(args_ll) + 1));
	if (!args)
		return (NULL);
	while (args_ll)
	{
		args[i] = args_ll->content;
		args_ll = args_ll->next;
		i++;
	}
	args[i] = NULL;
	return (args);
}


