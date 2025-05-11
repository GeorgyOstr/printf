/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:03:51 by gostroum          #+#    #+#             */
/*   Updated: 2025/05/08 15:49:26 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	if (!s[i])
		return (0);
	if (s[i++] != c)
		wc++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			wc++;
		i++;
	}
	return (wc);
}

static char	*generate_word(char const *s, size_t *i, char c)
{
	char	*w;
	size_t	start;

	while (s[*i] && s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	w = malloc(*i - start + 1);
	if (!w)
		return (NULL);
	ft_strlcpy(w, s + start, *i - start + 1);
	return (w);
}

static int	cleanup_on_fail(char **arr, size_t wi)
{
	size_t	wc;

	if (!arr[wi])
	{
		wc = wi;
		wi = 0;
		while (wi < wc)
			free(arr[wi++]);
		free(arr);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	wc;
	size_t	wi;

	i = 0;
	if (!s)
		return (NULL);
	wc = count_words(s, c);
	arr = malloc((wc + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[wc] = NULL;
	wi = 0;
	(void)(cleanup_on_fail);
	while (wi < wc)
	{
		arr[wi] = generate_word(s, &i, c);
		if (cleanup_on_fail(arr, wi))
			return (NULL);
		wi++;
	}
	return (arr);
}
