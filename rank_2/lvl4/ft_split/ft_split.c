/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:56:40 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/14 11:21:36 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_wordlen(char *str)
{
	int	i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		++i;
	return (i);
}

char	*word_dupe(char *str)
{
	int	i = 0;
	int	len = ft_wordlen(str);
	char	*word = malloc(sizeof(char) * (len + 1));

	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

void	fill_words(char **array, char *str)
{
	int	word_index = 0;

	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	while (*str != '\0')
	{
		array[word_index] = word_dupe(str);
		++word_index;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
	}
}

int		count_words(char *str)
{
	int	num_words = 0;

	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str;
	while (*str != '\0')
	{
		++num_words;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
	}
	return (num_words);
}

char	**ft_split(char *str)
{
	int		num_words;
	char	**array;

	num_words = count_words(str);
	array = malloc(sizeof(char *) * (num_words + 1));
	array[num_words] = 0;
	fill_words(array, str);
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


/*           ???        */

int	ft_wrdlen(char *str)
{
	int	count = 0;

	while (str[count] != '\0' && str[count] != ' ' && str[count] != '\t' && str[count] != '\n')
		count++;
	return (count);
}

char	*ft_duplicate(char *str)
{
	char *dup;
	int	len;
	int	i = 0;

	len = ft_wrdlen(str);
	dup = malloc(sizeof(char *) * len + 1);
	dup[len] = '\0';
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}

void	fill_words(char **array, char *str)
{
	int index = 0;

	while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
	while (*str != '\0')
	{
		array[index] = ft_duplicate(str);
		index++;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n' )
			str++;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
	}
}

int	ft_count_words(char *str)
{
	int	count = 0;

	while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
	while (*str != '\0')
	{
		count++;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n' )
			str++;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
	}
	return (count);
}

char **ft_split(char *str)
{
	char	**split;
	int		n_words;

	n_words = ft_count_words(str);
	split = malloc(sizeof(char **) * n_words + 1);
	if (!split)
		return (NULL);
	split[n_words] = '\0';
	fill_words(split, str);
	return (split);
}
