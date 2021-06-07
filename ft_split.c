/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juahn <juahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:24:53 by juahn             #+#    #+#             */
/*   Updated: 2021/04/14 17:27:41 by juahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_str_nb(const char *str, char c)
{
	int cnt;
	int i;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			cnt++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (cnt);
}

static void	ft_strcpy_for_split(char *dst, const char *from, const char *until)
{
	while (from < until)
		*(dst++) = *(from++);
	*dst = 0;
}

static void	ft_free_strs(char **strs, size_t index)
{
	size_t i;

	i = 0;
	while (i < index)
		free(strs[i++]);
	free(strs);
}

char		**ft_split(char const *str, char c)
{
	char			**strs;
	long long		i;
	const char		*ori;

	if (!str)
		return (0);
	if (!(strs = (char **)ft_calloc(count_str_nb(str, c) + 1, sizeof(char *))))
		return (0);
	i = 0;
	while (*str)
	{
		if (!(*str == c))
		{
			ori = str;
			while (*str && *str != c)
				str++;
			if (!(strs[i] = (char *)ft_calloc(str - ori + 1, sizeof(char))))
				ft_free_strs(strs, i);
			ft_strcpy_for_split(strs[i++], ori, str);
		}
		else
			str++;
	}
	return (strs);
}
