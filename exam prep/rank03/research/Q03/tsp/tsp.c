
#include "tsp.h"

float distance(t_city a, t_city b)
{
	return sqrtf((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	calculate_distance(t_city *cities, int *permutations, int n, float *shortest_path)
{
	float length;
	int i;

	i = 0;
	length = 0.0;
	while (i < n - 1)
	{
		length = length + distance(cities[permutations[i]], cities[permutations[i + 1]]);
		i++;
	}
	length = length + distance(cities[permutations[i]], cities[permutations[0]]);
	if (length < *shortest_path)
		*shortest_path = length;
}

void	generate_permutations(t_city *cities, int *permutations, int start, int n, float *shortest_path)
{
	int	i;

	if (start == n)
	{
		calculate_distance(cities, permutations, n, shortest_path);
		return ;
	}
	i = start;
	while (i < n)
	{
		swap(&permutations[start], &permutations[i]);
		generate_permutations(cities, permutations, start + 1, n, shortest_path);
		swap(&permutations[start], &permutations[i]);
		i++;
	}
}

int main(void)
{
	int		permutations[11];
	t_city	cities[11];
	float 	shortest_path;
	int		n;

	n = 0;
	shortest_path = INFINITY;
	while (fscanf(stdin, "%f, %f\n", &cities[n].x, &cities[n].y) == 2)
	{
		permutations[n] = n;
		n++;
	}
	if (n == 0)
	{
		fprintf(stdout, "Wrong input");
		return (1);
	}
	generate_permutations(cities, permutations, 1, n, &shortest_path);
	fprintf(stdout, "%.2f\n", shortest_path);
	return (0);
}
