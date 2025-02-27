char	*ft_strcpy(char *s1, char *s2)
{
	char *s3 = s1;
	while (*s1 && *s2)
	{	*s2 = *s1;
		s2++;
		s1++;
	}
	return(s3);
}
