/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:28:27 by jyap              #+#    #+#             */
/*   Updated: 2023/11/01 13:55:48 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(const char *str, char c)
{
	size_t	count;

	if (!str)
		return (0);
	if (!*str)
		return (0);
	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

char	**ft_split(const char *str, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = malloc((ft_count_word(str, c) + 1) * sizeof(*lst));
	if (!str || !lst)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str)
		{
			if (!ft_strchr(str, c))
				word_len = ft_strlen(str);
			else
				word_len = ft_strchr(str, c) - str;
			lst[i] = ft_substr(str, 0, word_len);
			i++;
			str += word_len;
		}
	}
	lst[i] = 0;
	return (lst);
}
