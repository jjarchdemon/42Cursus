/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseph <joseph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:43:23 by joseph            #+#    #+#             */
/*   Updated: 2025/05/14 14:54:51 by joseph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//the helper functions - advance, peek, match

// advance: move to the next token.
void advance(Parser *parser)
{
	if (parser->current)
		parser->current = parser->current->next;
}

// peek: look at/return the current token
t_token *peek(Parser *parser)
{
	return parser->current;
}
// match: check if the current token is of a specific type 
// and advance if it is & return true (1)
int match(Parser *parser, t_token_type type)
{
	if (peek(parser) && peek(parser)->type == type)
	{
		advance(parser);
		return 1;
	}
	return 0;
}
// ************************* AST creation fns  ******************************

ASTNode *create_command_node(char **argv)
{
	ASTNode *node = malloc(sizeof(ASTNode));
	node->type = AST_COMMAND;
	node->command.argv = argv;
	return node;
}

ASTNode *create_binary_node(ASTNodeType type, ASTNode *left, ASTNode *right)
{
	ASTNode *node = malloc(sizeof(ASTNode));
	node->type = type;
	node->binary.left = left;
	node->binary.right = right;
	return node;
}

ASTNode *create_redirect_node(ASTNode *command, char *filename, int redirect_type)
{
	ASTNode *node = malloc(sizeof(ASTNode));
	node->type = AST_REDIRECT;
	node->redirect.command = command;
	node->redirect.filename = filename;
	node->redirect.redirect_type = redirect_type;
	return node;
}

/* *************************  PARSER fns  ********************************** */

ASTNode *parse_command(Parser *parser)
{
	// Simple command: list of words
	t_token *tok = peek(parser);
	/*
	if (!tok || tok->type != TOKEN_WORD)
		return (NULL);
	*/
	int argc = 0;
	//t_token *start = tok;
	while (tok && tok->type == TOKEN_WORD)
	{
		argc++;
		tok = tok->next;
	}

	char **argv = malloc(sizeof(char *) * (argc + 1));
	for (int i = 0; i < argc; i++)
	{
		argv[i] = parser->current->content;
		advance(parser);
	}
	argv[argc] = NULL;

	ASTNode *cmd = create_command_node(argv);

	// Check for redirection
	while (1) {
		if (match(parser, TOKEN_REDIRECT_IN))
		{
			if (!peek(parser) || peek(parser)->type != TOKEN_WORD)
				return NULL;
			char *filename = peek(parser)->content;
			advance(parser);
			cmd = create_redirect_node(cmd, filename, 0);
		}
		else if (match(parser, TOKEN_REDIRECT_OUT_TRUNC))
		{
			if (!peek(parser) || peek(parser)->type != TOKEN_WORD)
				return NULL;
			char *filename = peek(parser)->content;
			advance(parser);
			cmd = create_redirect_node(cmd, filename, 1);
		} 
		else
			break;
	}
	return cmd;
}

ASTNode *parse_pipeline(Parser *parser)
{
	ASTNode *left = parse_command(parser);
	while (match(parser, TOKEN_PIPE))
	{
		ASTNode *right = parse_command(parser);
		if (!right)
			return NULL;
		left = create_binary_node(AST_PIPELINE, left, right);
	}
	return left;
}

ASTNode *parse_sequence(Parser *parser)
{
	ASTNode *left = parse_pipeline(parser);
	while (match(parser, TOKEN_SEQUENCE))
	{
		ASTNode *right = parse_pipeline(parser);
		if (!right) return NULL;
		left = create_binary_node(AST_SEQUENCE, left, right);
	}
	return left;
}

ASTNode *parse(Parser *parser)
{
	return parse_sequence(parser);
}

// Helper function to print arguments of a command
static void print_command_args(char **argv) {
	if (argv) {
		for (char **arg = argv; *arg; ++arg) {
			printf(" %s", *arg);
		}
	}
	printf("\n");
}

// Recursive AST printer with tree-like ASCII formatting
void print_ast_tree(ASTNode *node, const char *prefix, int is_last) 
{
	if (!node)
		return;

	// └── or ├── based on whether it's the last child
	printf("%s%s", prefix, is_last ? "└── " : "├── ");

	// Print node info
	switch (node->type) {
		case AST_COMMAND:
			printf("COMMAND:");
			print_command_args(node->command.argv);
			break;
		case AST_PIPELINE:
			printf("PIPELINE\n");
			break;
		case AST_SEQUENCE:
			printf("SEQUENCE\n");
			break;
		case AST_REDIRECT:
			printf("REDIRECT (%s): %s\n",
				   node->redirect.redirect_type == 0 ? "input" : "output",
				   node->redirect.filename);
			break;
		default:
			printf("UNKNOWN NODE\n");
			return;
	}

	// Prepare new prefix for child nodes
	char new_prefix[256];
	snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, is_last ? "    " : "│   ");

	// Recurse into children
	switch (node->type) {
		case AST_PIPELINE:
		case AST_SEQUENCE:
			print_ast_tree(node->binary.left, new_prefix, 0);  // not last
			print_ast_tree(node->binary.right, new_prefix, 1); // last
			break;
		case AST_REDIRECT:
			print_ast_tree(node->redirect.command, new_prefix, 1); // only child
			break;
		default:
			break; // COMMAND has no children
	}
}

void	free_ast_tree(ASTNode *node)
{
	char **argv;
	if (!node)
		return;
	switch (node->type) {
		case AST_COMMAND:
			argv = node->command.argv;
			while (*argv)
			{
				free(*argv); // Free each argument
				argv++;
			}
			free(node->command.argv); // Free the array of arguments
			break;
		case AST_PIPELINE:
		case AST_SEQUENCE:
			free_ast_tree(node->binary.left);  // Free left child
			free_ast_tree(node->binary.right); // Free right child
			break;
		case AST_REDIRECT:
			free(node->redirect.filename); // Free the filename
			free_ast_tree(node->redirect.command); // Free the command
			break;
		default:
			break;
	}
	free(node); // Free the node itself
}
