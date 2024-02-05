/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:31:01 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/31 13:31:01 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include "../src/push_swap.h"
# include "../lib/get_next_line/get_next_line.h"

int		stack_command(t_stack data, char *command);
void	print_out(t_stack data);
void	check_gnl(t_stack data_check, char *commands);

#endif