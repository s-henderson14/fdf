/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:18:03 by sean              #+#    #+#             */
/*   Updated: 2023/06/25 22:53:11 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	file_check(char *filename)
{
	const char	*filetype = ".fdf";
	size_t		len;

	len = ft_strlen(filename);
	if ((int)len < 4)
		error();
	if (ft_strncmp(&filename[(int)len - 4], filetype, len) != 0)
		error();
	return (open(filename, O_RDONLY));
}
