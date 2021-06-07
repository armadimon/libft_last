/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juahn <juahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:22:22 by juahn             #+#    #+#             */
/*   Updated: 2021/05/17 15:40:59 by juahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;

	if (!s || start < 0)
		return (0);
	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	if (!(sub_str = (char *)ft_calloc(len + 1, sizeof(char))))
		return (0);
	if (ft_strlen(s) < start)
		return (sub_str);
	while (start--)
		s++;
	ft_strlcpy(sub_str, s, len + 1);
	return (sub_str);
}
