/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_interpreting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 15:21:55 by fkoehler          #+#    #+#             */
/*   Updated: 2016/11/21 18:56:11 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char	*replace_special_char(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\\')
			i += replace_backslash(&s, i);
		else if (s[i] == '~')
			i += replace_tilde(&s, i);
		else if (s[i] == '$' && (i == 0 || (s[i - 1] != '\\')) && s[i + 1])
		{
			if (s[i + 1] == '?')
				i += replace_exit_value(&s, i);
			else
				s = str_replace_var(s, i++);
		}
		else
			i++;
	}
	return (s);
}

static char	*interpret_special_char(char *sub_arg)
{
	int		quote;

	if ((quote = is_str_quoted(sub_arg)))
		sub_arg = strdup_remove_quotes(sub_arg);
	if (quote == 1)
		return (sub_arg);
	return (replace_special_char(sub_arg));
}

char		*interpret_cmd_arg(char *cmd_arg)
{
	int		i;
	char	*ret;
	char	**arg_tab;

	i = 0;
	ret = NULL;
	arg_tab = str_subsplit_arg(cmd_arg);
	while (arg_tab[i])
	{
		arg_tab[i] = interpret_special_char(arg_tab[i]);
		i++;
	}
	ret = ft_multi_strjoin(arg_tab, "");
	free_tab(arg_tab);
	free(cmd_arg);
	return (ret);
}

char		*remove_cmd_redir(char *cmd, t_redir *redir)
{
	int		start;
	char	*tmp_cmd;
	t_redir	*tmp;

	if (!(tmp = redir))
		return (cmd);
	while (tmp)
	{
		start = ft_strstr_index(cmd, tmp->s);
		tmp_cmd = ft_replace_str(cmd, start, ft_strlen(tmp->s), "");
		free(cmd);
		cmd = tmp_cmd;
		tmp = tmp->next;
	}
	return (cmd);
}
