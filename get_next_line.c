/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jambatt <jambatt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 07:59:58 by jkolosow          #+#    #+#             */
/*   Updated: 2025/05/12 16:16:24 by jambatt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8 // Default buffer size for reading from the file
#endif

// Function prototypes
char	*read_line(int fd, char *carryover); // Reads from the file and appends to carryover
char	*ft_strjoin(char *s1, char *s2);     // Joins two strings into a new string
int		ft_strlen(char *s);                 // Calculates the length of a string
char	*ft_strchr(char *s, char c);         // Finds the first occurrence of a character in a string
char	*get_line(char *s);                  // Extracts a single line from the carryover
char	*ft_strndup(char *s, size_t n);      // Duplicates the first n characters of a string
char	*update_carryover(char *carryover);  // Updates carryover after extracting a line

/* 
 * get_next_line:
 * Reads the next line from the file descriptor `fd`.
 * Uses a static variable `carryover` to store leftover data between calls.
 */
char	*get_next_line(int fd)
{
    static char	*carryover; // Static variable to persist data between function calls
    char		*line;

    carryover = read_line(fd, carryover); // Read data from the file
    line = get_line(carryover);          // Extract a single line from carryover
    if (!line)
        return (free(carryover), NULL);  // Free carryover and return NULL if no line is found
    carryover = update_carryover(carryover); // Update carryover for the next call
    return (line);
}

/* 
 * update_carryover:
 * Updates the carryover by removing the extracted line.
 * Frees the old carryover and returns the updated string.
 */
char	*update_carryover(char *carryover)
{
    char	*new;
    char 	*start;

    start = ft_strchr(carryover, '\n'); // Find the newline character
    if (!start)
    {
        free(carryover); // Free carryover if no newline is found
        return (NULL);
    }
    new = ft_strndup(start + 1, ft_strlen(start + 1)); // Duplicate the remaining string
    free(carryover); // Free the old carryover
    return (new);
}

/* 
 * get_line:
 * Extracts a single line from the given string `s`.
 * If no newline is found, returns the entire string.
 */
char	*get_line(char *s)
{
    char	*end;
    char	*line;

    end = NULL;
    if (!s)
        return (NULL); // Return NULL if the input string is NULL
    end = ft_strchr(s, '\n'); // Find the newline character
    if (!end)
        return (ft_strjoin("", s)); // Return the entire string if no newline is found
    line = ft_strndup(s, end - s + 1); // Duplicate the line up to the newline
    return (line);
}

/* 
 * ft_strndup:
 * Duplicates the first `n` characters of the string `s`.
 * Allocates memory for the new string and returns it.
 */
char	*ft_strndup(char *s, size_t n)
{
    unsigned int		index;
    char				*new;

    new = malloc((n + 1) * sizeof (char)); // Allocate memory for the new string
    if (!new)
        return (NULL); // Return NULL if memory allocation fails
    index = 0;
    while (index < n)
    {
        new[index] = *s; // Copy characters from the source string
        ++s;
        ++index;
    }
    new[index] = '\0'; // Null-terminate the new string
    return (new);
}

/* 
 * read_line:
 * Reads data from the file descriptor `fd` into a buffer.
 * Appends the data to the carryover string.
 */
char	*read_line(int fd, char *carryover)
{
    char	buffer[BUFFER_SIZE + 1]; // Buffer to store read data
    int		bytes_read;
    char	*temp;

    while (1)
    {
        if (carryover && ft_strchr(carryover, '\n')) // Stop if a newline is already in carryover
            return (carryover);
        bytes_read = read(fd, buffer, BUFFER_SIZE); // Read data from the file
        if (bytes_read == -1)
            return (free(carryover), NULL); // Return NULL on read error
        if (bytes_read == 0)
            return (carryover); // Return carryover if end of file is reached
        buffer[bytes_read] = '\0'; // Null-terminate the buffer
        if (carryover)
            temp = ft_strjoin(carryover, buffer); // Append buffer to carryover
        else
            temp = ft_strjoin("", buffer); // Create a new string from the buffer
        if (!temp)
        {
            free(carryover); // Free carryover if memory allocation fails
            return (NULL);
        }
        free(carryover); // Free the old carryover
        carryover = temp;
        temp = NULL;
    }
}

/* 
 * ft_strchr:
 * Finds the first occurrence of the character `c` in the string `s`.
 * Returns a pointer to the character or NULL if not found.
 */
char	*ft_strchr(char *s, char c)
{
    while (*s)
    {
        if (*s == c)
            return (s); // Return pointer to the character
        ++s;
    }
    return (NULL); // Return NULL if character is not found
}

/* 
 * ft_strjoin:
 * Joins two strings `s1` and `s2` into a new string.
 * Allocates memory for the new string and returns it.
 */
char	*ft_strjoin(char *s1, char *s2)
{
    int		len1;
    int		len2;
    char	*joined;
    int		index;

    len1 = ft_strlen(s1); // Get the length of the first string
    len2 = ft_strlen(s2); // Get the length of the second string
    joined = malloc((len1 + len2 + 1) * sizeof (char)); // Allocate memory for the new string
    if (!joined)
        return (NULL); // Return NULL if memory allocation fails
    index = 0;
    while (*s1)
    {
        joined[index] = *s1; // Copy characters from the first string
        ++s1;
        ++index;
    }
    while (*s2)
    {
        joined[index] = *s2; // Copy characters from the second string
        ++s2;
        ++index;
    }
    joined[index] = '\0'; // Null-terminate the new string
    return (joined);
}

/* 
 * ft_strlen:
 * Calculates the length of the string `s`.
 * Returns the number of characters in the string.
 */
int	ft_strlen(char *s)
{
    int	len;

    len = 0;
    while (*s)
    {
        ++len; // Increment the length counter
        ++s;
    }
    return (len);
}

// #############################################################################

// Test functions to validate the behavior of get_next_line
void	test0(void); // Test reading from a non-existing file
void	test1(void); // Test reading from an empty file
void	test2(void); // Test reading from a file with only newlines
void	test3(void); // Test reading from a file with short text
void	test4(void); // Test reading from a file without permissions
void	test5(void); // Test reading from a file with short lines
void	test6(void); // Test reading from a file with normal line lengths
void	test7(void); // Test reading from a file with varying line lengths
void	test8(void); // Test reading from a file with a single long line
void	test9(void); // Test closing the file after reading a few lines
void	test10(void); // Test using an invalid file descriptor
void	test11(void); // Test reading from standard input

/* 
 * main:
 * Executes the test functions to validate get_next_line.
 */
int	main(void)
{
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    //test11(); // Uncomment to test reading from standard input

    return (0);
}

void	test0(void)
{
	char	filename[] = "./test_text_files/non_existing.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 0 ###");
	puts("Read from a nonexisting file.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');

	return ;
}

void	test1(void)
{
	char	filename[] = "./test_text_files/empty.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 1 ###");
	puts("Read from an empty file.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');

	return ;
}

void	test2(void)
{
	char	filename[] = "./test_text_files/newlines.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 2 ###");
	puts("Read from a file with newlines only.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');

	return ;
}

void	test3(void)
{
	char	filename[] = "./test_text_files/test.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 3 ###");
	puts("Read from a file with some short text.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');

	return ;
}

void	test4(void)
{
	char	filename[] = "./test_text_files/no_access.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 4 ###");
	puts("Read from a file without reading or writing permissions.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');

	return ;
}

void	test5(void)
{
	char	filename[] = "./test_text_files/short_lines.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 5 ###");
	puts("Read from a file with short lines.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');

	return ;
}

void	test6(void)
{
	char	filename[] = "./test_text_files/normal_text.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 6 ###");
	puts("Read from a file with \"normal\" line lengths.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');

	return ;
}

void	test7(void)
{
	char	filename[] = "./test_text_files/longer_and_shorter_lines.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 7 ###");
	puts("Read from a file with longer and shorter line lengths.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');

	return ;
}

void	test8(void)
{
	char	filename[] = "./test_text_files/single_long_line.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 8 ###");
	puts("Read from a file with one very long line.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');

	return ;
}

void	test9(void)
{
	char	filename[] = "./test_text_files/short_lines.txt";
	char	*line = NULL;
	int		fd;
	int		line_counter = 0;

	puts("### TEST 9 ###");
	puts("After 5 lines, \"close\" the file.");
	printf("filename\t->\t'%s'\n", filename);

	fd = open(filename, O_RDONLY);
	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);

		if (line_counter == 5)
			close(fd);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	close(fd);
	putchar('\n');

	return ;
}

void	test10(void)
{
	char	filename[] = "NO FILE, '42' AS FILE DESCRIPTOR";
	char	*line = NULL;
	int		fd = 42;
	int		line_counter = 0;

	puts("### TEST 10 ###");
	puts("No file has been opened, file descriptor set to an int value.");
	printf("filename\t->\t'%s'\n", filename);

	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	putchar('\n');

	return ;
}

void	test11(void)
{
	char	filename[] = "STDIN";
	char	*line = NULL;
	int		fd = 0;
	int		line_counter = 0;

	puts("### TEST 11 ###");
	puts("Read from the standard input.");
	printf("filename\t->\t'%s'\n", filename);

	printf("file descriptor\t->\t%d\n", fd);

	while ((line = get_next_line(fd)))
	{
		printf("[%2d] %s", line_counter++, line);
		free(line);
	}
	printf("'line'\t[%p]\t[%s]\n", line, line);
	putchar('\n');

	return ;
}

/* void	test0(void)
{
	char	s1[] = "hello ";
	char	s2[] = "world\n";

	printf("s1\t->\t'%s'\n", s1);
	printf("s2\t->\t'%s'\n", s2);
	printf("joined\t->\t'%s'\n", ft_strjoin(s1, s2));
	return ;
}

void	test1(void)
{
	char	s1[] = "hello ";
	char	s2[] = "";

	printf("s1\t->\t'%s'\n", s1);
	printf("s2\t->\t'%s'\n", s2);
	printf("joined\t->\t'%s'\n", ft_strjoin(s1, s2));
	return ;
}

void	test2(void)
{
	char	s1[] = "";
	char	s2[] = "world\n";

	printf("s1\t->\t'%s'\n", s1);
	printf("s2\t->\t'%s'\n", s2);
	printf("joined\t->\t'%s'\n", ft_strjoin(s1, s2));
	return ;
}

void	test3(void)
{
	char	s1[] = "";
	char	s2[] = "";

	printf("s1\t->\t'%s'\n", s1);
	printf("s2\t->\t'%s'\n", s2);
	printf("joined\t->\t'%s'\n", ft_strjoin(s1, s2));
	return ;
}

void	test4(void)
{
	char	*line;
	int	fd;

	fd = open("one_line.txt", O_RDONLY);
	while (line = get_next_line(fd))
	{
		printf("line\t->\t'%s'", line);
		free(line);
		line = NULL;
	}
	return ;
}

int	main(void)
{
	// test0();
	// test1();
	// test2();
	// test3();
	test4();
	return (0);
}
 */