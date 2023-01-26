/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:56:40 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/26 10:04:29 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char *str, int len)
{
	char	*substr;
	int		z = 0;

	substr = malloc(sizeof(char *) * (len + 1));
	if (!substr)
		return (NULL);
	while (z < len)
	{
		substr[z] = str[z];
		z++;
	}
	substr[z] = '\0';
	return (substr);
}

int	ft_count_char(char *str, int flag)
{
	int	k = 0;

	if (flag == 0)
	{
		while (str[k] == ' ' || str[k] == '\t' || str[k] == '\n')
			k++;
	}
	else
	{
		while (str[k] && str[k] != ' ' && str[k] != '\t' && str[k] != '\n')
			k++;
	}
	return (k);

}

int	word_counting(char *str)
{
	int	count = 0;
	int	j = 0;

	while (str[j] == ' ' || str[j] == '\t' || str[j] == '\n')
		j++;
	while (str[j])
	{
		while (str[j] && str[j] != ' ' && str[j] != '\t' && str[j] != '\n')
			j++;
		count++;
		while (str[j] == ' ' || str[j] == '\t' || str[j] == '\n')
			j++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	char	**array;
	int		nb_words;
	int		i = 0;

	if (!str)
		return (NULL);
	nb_words = word_counting(str);
	array = malloc(sizeof(char *) * (nb_words + 1));
	if (!array)
		return(NULL);
	while (i < nb_words)
	{
		str += ft_count_char(str, 0);
		array[i] = ft_substr(str, ft_count_char(str, 1));
		if (!array[i])
			return(NULL);
		str += ft_count_char(str, 1);
		i++;
	}
	array[i] = NULL;
	return (array);
}

// int	main(int argc, char **argv)
// {
// 	char	**split;
// 	int		i = 0;

// 	if (argc == 2)
// 	{
// 		split = ft_split(argv[1]);
// 		while (split[i])
// 			printf("%s\n", split[i++]);
// 	}
// 	printf("\n");
// 	return (0);
// }
