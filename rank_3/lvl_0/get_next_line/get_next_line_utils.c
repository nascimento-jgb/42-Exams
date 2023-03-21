#include "get_next_line.h"

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *dest, char *orig)
{
	char			*aux;
	unsigned int	len;
	int				i;
	int				j;

	if (!dest && !orig)
		return (NULL);
	len = ft_strlen(dest) + ft_strlen(orig);
	aux = (char *)malloc(sizeof(char) * len + 1);
	if (!aux)
		return (NULL);
	i = 0;
	j = 0;
	if (dest)
	{
		while (dest[i])
			aux[j++] = dest[i++];
		i = 0;
	}
	while (orig[i])
		aux[j++] = orig[i++];
	aux[len] = '\0';
	free((void *)dest);
	return (aux);
}
