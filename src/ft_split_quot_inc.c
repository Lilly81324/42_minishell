/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quot_inc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:40:45 by sikunne           #+#    #+#             */
/*   Updated: 2025/02/13 17:43:14 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// moves until it reaches end or opt
// returns the index of that character
// returns -1 if character not found (quotation opened and not closed)
static int	move_until(char *s, int i, char opt)
{
	i++;
	while (s[i] != opt && s[i] != '\0')
		i++;
	if (s[i] == '\0')
	{
		return (-1);
	}
	return (i);
}

// returns how many "words" are in a string
// returns -1 if error
static int	get_sets(char *s)
{
	int		i;
	int		strings;

	i = 0;
	strings = 0;
	while (s[i] != '\0')
	{
		ft_skip_spaces(&i, s);
		if (s[i] != '\0')
			strings++;
		while (s[i] != '\0' && ft_c_in_s(SPACES, s[i]) == 0)
		{
			if (s[i] == '\'')
				i = move_until(s, i, '\'');
			else if (s[i] == '\"')
				i = move_until(s, i, '\"');
			if (i < 0)
				return (-1);
			i++;
		}
	}
	return (strings);
}

// called at the first character of a string
// gives back the string, or NULL if error
// sets i to the index of the first occurence of c after that string
static char	*get_string(char *s, int *i)
{
	int		start;
	char	*str;
	int		j;

	start = *i;
	j = 0;
	while (s[*i] != '\0' && ft_c_in_s(SPACES, s[*i]) == 0)
	{
		if (s[*i] == '\'')
			*i = move_until(s, *i, '\'');
		else if (s[*i] == '\"')
			*i = move_until(s, *i, '\"');
		if (*i < 0)
			return (NULL);
		(*i)++;
	}
	str = (char *)malloc((((*i) - start) + 1) * sizeof(char));
	while (j < ((*i) - start))
	{
		str[j] = s[start + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

// turns a source string into seperate strings containing each "word"
// a "word" is defined as being between the char c, start of string
// or end of string
// compared to ft_split, this function properly handles quotes
// returns -1 if error
static int	ft_splitter(char *s, char **result)
{
	int	arrpos;
	int	i;

	arrpos = 0;
	i = 0;
	while (s[i] != '\0')
	{
		ft_skip_spaces(&i, s);
		if (s[i] != '\0')
		{
			result[arrpos] = get_string(s, &i);
			if (result[arrpos] == NULL)
				return (-1);
			arrpos++;
		}
	}
	result[arrpos] = NULL;
	return (0);
}

// Version of ft_split that respect things in quotes
// includes quotes from string and views everything as part of word
// "abc'def' ghi" -> abc'def', ghi
// This function is the central function, it uses...
// ...the other functions to split a string into...
// smaller strings and returns that array of arrays
char	**ft_split_quot_inc(char *s)
{
	int		count;
	char	**result;

	if (s == NULL)
		return (NULL);
	count = get_sets(s);
	if (count < 1)
		return (NULL);
	result = (char **)malloc((count + 1) * sizeof(int *));
	count = ft_splitter(s, result);
	if (count < 0)
	{
		ft_nullb(result);
		return (NULL);
	}
	return (result);
}
