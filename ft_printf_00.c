/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carperez <carperez@student.45madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:58:08 by carperez          #+#    #+#             */
/*   Updated: 2023/02/26 15:12:07 by carperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_string_printer(char **pPlace, int *nPrinted)
{
	if (**pPlace != '%')
	{
		ft_putchar_fd(**pPlace, 1);
		*pPlace += 1;
		*nPrinted += 1;
		return (0);
	}
	else
	{
		*pPlace += 1;
		return (1);
	}
}

static void	ft_format_selector(t_set *pSet, int *nPrinted)
{
	char	*p_argstring;

	p_argstring = NULL;
	if (pSet->c_type == 'c' || pSet->c_type == '%')
		p_argstring = ft_print_char(pSet, nPrinted);
	else if (pSet->c_type == 's')
		p_argstring = ft_print_str(pSet, nPrinted);
	else if (pSet->c_type == 'p')
		p_argstring = ft_print_ptr(pSet, nPrinted);
	else if (pSet->c_type == 'd' || pSet->c_type == 'i')
		p_argstring = ft_print_int(pSet, nPrinted);
	else if (pSet->c_type == 'u')
		p_argstring = ft_print_uns(pSet, nPrinted);
	else if (pSet->c_type == 'x' || pSet->c_type == 'X')
		p_argstring = ft_print_hex(pSet, nPrinted);
	if (p_argstring != NULL)
	{
		ft_putstr_fd(p_argstring, 1);
		free(p_argstring);
	}
	else
		pSet->f_error = 13;
}	

static void	ft_pholder_capturer(char const *sToken, int *nPlace, t_set *pSet
		, int *nPrinted)
{
	int		ia;
	char	*p_newpholder;

	ia = 0;
	p_newpholder = NULL;
	while (*(sToken + ia) != '\0' && !ft_isalpha(*(sToken + ia))
		&& *(sToken + ia) != '%')
		ia ++;
	if (!ft_set_type(*(sToken + ia), pSet))
	{
		ia ++;
		p_newpholder = (char *) malloc ((ia + 1) * sizeof(char *));
		if (p_newpholder != NULL)
		{
			ft_strlcpy(p_newpholder, sToken, ia + 1);
			*nPlace += ia;
			ft_pholder_validator(p_newpholder, pSet);
			free(p_newpholder);
			if (!pSet->f_error)
				ft_format_selector(pSet, nPrinted);
			if (!pSet->f_error)
				ft_set_starter(pSet);
		}
	}
	if (p_newpholder == NULL)
		pSet->f_error = 1;
}

int	ft_printf(char const *sPrint, ...)
{
	t_set	s_set;
	int		n_printed;
	int		ia;

	ia = 0;
	n_printed = 0;
	if (sPrint != NULL)
	{
		va_start(s_set.lst_items, sPrint);
		ft_set_starter(&s_set);
		while (*sPrint != '\0' && !s_set.f_error)
		{
			if (ft_string_printer((char **)&sPrint, &n_printed))
			{
				ft_pholder_capturer(sPrint, &ia, &s_set, &n_printed);
				if (!s_set.f_error)
				{
					sPrint += ia;
					ia = 0;
				}
			}
		}
		va_end(s_set.lst_items);
	}
	return (n_printed);
}

// END