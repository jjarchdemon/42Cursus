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

void rip(char *str, int n, int open, int close) //snoc						
{
	if (open == 0 && close == 0)
	{
		if (is_valid(str))
			puts(str);
		return;
	}
	int i = n;
	while (str[i])
	{
		if (str[i]=='(' && open > 0)
		{
			str[i] = ' ';
			rip(str, i+1, open-1, close);
			str[i] = '(';
		}
		else if (str[i]==')' && close > 0)
		{
			str[i] = ' ';
			rip(str, i+1, open, close-1);
			str[i] = ')';
		}
		i++; //forgot this
	}
}


void find_subsets(int *set, int set_size, int *subset, int subset_size, int sum, int index)
{
        int i = 0;
        int subset_sum;
        //base case
        if (index == set_size)
        {
                subset_sum = 0;
                while (i < subset_size)
                {
                        subset_sum += subset[i];
                        i++;
                }
                if (subset_sum == sum)
                        print_subset(subset, subset_size);
                return;
        }
        subset[subset_size] = set[index];
        find_subsets(set, set_size, subset, subset_size + 1, sum, index + 1);
        find_subsets(set, set_size, subset, subset_size, sum, index + 1);
}



void find_subset(int *set, int set_size, int *subset, int subset_size, int sum, int index)
{
	int i = 0;
	int subset_sum;
	if (index == set_size)
	{
		subset_sum = 0;
		while (i < subset_size)
		{
			subset_sum += subset[i];
			i++;
		}
		if (subset_sum == sum)
			print subset;
		return;
	}

	subset[subset_size] = set[index];
	find_subset(set, set_size, subset, subset_size+1, sum, index+1);
	find_subset(set, set_size, subset, subset_size, sum, index+1);
}








































