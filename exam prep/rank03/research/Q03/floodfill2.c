<<<<<<< HEAD
typedef struct s_point
{
    int x;
    int y;
}   t_point;


void to_fill(char **map, t_point size, t_point to_test, char fill_char)
{
    if (to_test.x >= 0 && to_test.x < size.x && to_test.y >= 0 && to_test.y < size.y
        && map[to_test.y][to_test.x] == fill_char)
    {
        map[to_test.y][to_test.x] = 'F';
        to_fill(map, size, (t_point){to_test.x + 1, to_test.y}, fill_char);
        to_fill(map, size, (t_point){to_test.x - 1, to_test.y}, fill_char);
        to_fill(map, size, (t_point){to_test.x, to_test.y + 1}, fill_char);
        to_fill(map, size, (t_point){to_test.x, to_test.y - 1}, fill_char);
    }
    // else
    //     return ;
}



void  flood_fill(char **tab, t_point size, t_point begin)
{
    to_fill(tab, size, begin, tab[begin.y][begin.x]);
}
#include <stdio.h>
#include <stdlib.h>

void print_tab(char **a, t_point size)
{
    int i;
    int j;
    i = 0;
    while (i < size.y)
    {
        j = 0;
        while (j < size.x)
        {
            printf("%c ", a[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
}



char** make_area(char **a, t_point size)
{
    char **res;
    int  i, j;

    res = malloc(sizeof(char *) * size.y);
    i = 0;
    while (i < size.y)
    {
        res[i] = malloc(sizeof(char *) * (size.x + 1));
        j = 0;
        while (j < size.x)
        {
            res[i][j] = a[i][j * 2];
            j++;
        }
        i++;
    }
    return (res);
}


int main(void)
{
	t_point size = {8, 5};
	t_point begin = {1, 1};
    char **area;
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	};

    area = make_area((char **)zone, size);
	print_tab(area, size);
	flood_fill(area, size, begin);
	printf("\n");
	print_tab(area, size);
	return (0);
}
=======
  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;


void	to_fill(char **tab, t_point size, t_point curr, char character)
{
	if (curr.x >= size.x || curr.x < 0 || curr.y >= size.y || curr.y < 0 || tab[curr.y][curr.x] != character)
	{
		return ;
	}
	else
	{
		tab[curr.y][curr.x] = 'F';
		to_fill(tab, size, (t_point){curr.x + 1, curr.y}, character);
		to_fill(tab, size, (t_point){curr.x - 1, curr.y}, character);
		to_fill(tab, size, (t_point){curr.x, curr.y + 1}, character);
		to_fill(tab, size, (t_point){curr.x, curr.y - 1}, character);
	}
}


void  flood_fill(char **tab, t_point size, t_point begin)
{
	to_fill(tab, size, begin, tab[begin.y][begin.x]);
}
>>>>>>> c0537a303a9b0982da28a61625146ad18aeb3167
