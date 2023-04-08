char    *ft_strcpy(char *s1, char *s2)
{
	int	index;

	if (!s1 || !s2)
		return (s1);
	index = -1;
	while (s2[++index])
		s1[index] = s2[index];
	s1[index] = '\0';
	return (s1);
}
