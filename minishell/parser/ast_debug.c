#include <stdio.h>
#include <stdlib.h>

//AST node types
typedef enum
{
	AST_COMMAND,
	AST_PIPELINE,
	AST_SEQUENCE,
	AST_REDIRECT
} ASTNodeType;

// AST node structure
typedef struct ASTNode
{
	ASTNodeType type;
	union {
		struct {
			char **argv;
		} command;	//COMMAND node holds an array of strings (arguments)

		struct {
			struct ASTNode *left;
			struct ASTNode *right;
		} binary;	//PIPELINE or SEQUENCE node holds two child nodes (left and right)

		struct {
			struct ASTNode *command;
			char *filename;
			int redirect_type; // 0 for input (<), 1 for output (>)
		} redirect;	//REDIRECT node holds a command and a file name.
	};
} ASTNode;



// Helper function to print arguments of a command
void print_command_args(char **argv) {
	if (argv) {
		for (char **arg = argv; *arg; ++arg) {
			printf(" %s", *arg);
		}
	}
	printf("\n");
}

// Recursive AST printer with tree-like ASCII formatting
void print_ast_tree(ASTNode *node, const char *prefix, int is_last) {
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

int main() {
    // Simulate: ls -l ; grep foo | sort > out.txt

    // COMMAND: ls -l
    char *ls_argv[] = {"ls", "-l", NULL};
    ASTNode *ls_node = create_command_node(ls_argv);

    // COMMAND: grep foo
    char *grep_argv[] = {"grep", "foo", NULL};
    ASTNode *grep_node = create_command_node(grep_argv);

    // COMMAND: sort
    char *sort_argv[] = {"sort", NULL};
    ASTNode *sort_node = create_command_node(sort_argv);

    // REDIRECT: sort > out.txt
    ASTNode *redirect_node = create_redirect_node(sort_node, "out.txt", 1);

    // PIPELINE: grep foo | sort > out.txt
    ASTNode *pipeline_node = create_binary_node(AST_PIPELINE, grep_node, redirect_node);

    // SEQUENCE: ls -l ; (grep foo | sort > out.txt)
    ASTNode *root = create_binary_node(AST_SEQUENCE, ls_node, pipeline_node);

    // Print the AST
    print_ast_tree(root, "", 1);

    return 0;
}