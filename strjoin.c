/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idakhlao <idakhlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:07:15 by idakhlao          #+#    #+#             */
/*   Updated: 2024/02/27 17:31:24 by idakhlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strdup(char *src)
{
	char	*s;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen2(src) + 1;
	s = (char *)malloc(len * sizeof(char));
	if (s == NULL)
		return (NULL);
	while (src[i])
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static int	total_len(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen2(strs[i]);
		i++;
	}
	len += ft_strlen2(sep) * (size - 1);
	len += 1;
	return (len);
}

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin2(int size, char **strs, char *sep)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (size == 0)
	{
		res = ft_strdup("");
		return (res);
	}
	len = total_len(size, strs, sep);
	res = (char *)malloc(len * sizeof(char));
	if (res == NULL)
		return (NULL);
	*res = 0;
	while (i < size)
	{
		ft_strcat(res, strs[i]);
		if (i < size - 1)
			ft_strcat(res, sep);
		i++;
	}
	return (res);
}
