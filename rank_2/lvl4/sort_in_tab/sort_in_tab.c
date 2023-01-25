/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:03:00 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/25 12:05:05 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_in_tab(int *tab, unsigned int size)
{
	int	i= 0;
	int	aux;

	while (tab[i])
	{
		if (tab[i] > tab[i + 1])
		{
			aux = tab[i + 1];
			tab[i + 1] = tab[i];
			tab [i] = aux;
			i = 0;
		}
		else
			i++;
	}
}
