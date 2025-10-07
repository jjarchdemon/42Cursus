#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int is_valid(char *str)
{
    int bal = 0; 
    int i = 0;
    while (str[i])
    {
        if (str[i] == '(')
            bal ++;
        else if (str[i] == ')')
        {
            bal--;
            if (bal < 0 )
                return 0;
        }
        i++;
    }
    return (bal == 0);
}

//n is current index
void rip(char *s, int n, int open, int close)
{
    if (open == 0 && close == 0)
    {
        if (is_valid(s))
            puts(s);
        return;
    }

    int i = n;
    while (s[i])
    {
        if (s[i] == '(' && open > 0)
        {
            s[i] = ' ';
            rip(s, i + 1, open - 1, close);
            s[i] = '(';
        } 
        else if (s[i] == ')' && close > 0)
        {
            s[i] = ' ';
            rip(s, i + 1, open, close - 1);
            s[i] = ')';
        }
        i++;
    }
}

int main (int ac , char *av[])
{
    if (ac != 2)
        return 1;
    //make mutable copy
    int len = ft_strlen(av[1]);
    char str[len + 1];
    int i = 0;
    while (i < len)
    {
        str[i] = av[1][i];
        i++;
    }
    str[len] = '\0';

    //calc min paranthesis removal
    int open = 0 , close = 0 ;
    i = 0;
    while (i < len)
    {
        if (str[i] == '(')
            open++;
        else if (str[i] == ')')
        {
            if (open > 0)
                open--;
            else 
                close++;
        }
        i++;
    }
    //recursive fn
    rip(str, 0, open, close);
}
