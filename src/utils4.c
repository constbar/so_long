#include "../so_long.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	l;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	l = ft_strlen(s1);
	while (l && ft_strchr(set, s1[l]))
		l--;
	return (ft_substr((char *)s1, 0, l + 1));
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p && *p != c)
		p++;
	if (*p == c)
		return (p);
	else
		return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*p;

	if (s && start >= ft_strlen(s))
		len = 0;
	p = (char *)malloc(sizeof(char) * len + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < len && s)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

void	gnl_helper(char **pn, char **remains)
{
	if (*pn)
	{
		**pn = '\0';
		*remains = ft_duplicate(++(*pn));
	}
}
