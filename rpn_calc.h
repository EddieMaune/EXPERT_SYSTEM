/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn-calc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmpofu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:22:46 by mmpofu            #+#    #+#             */
/*   Updated: 2017/11/07 09:04:36 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CALC_H
#define RPN_CALC_H

#include <stdio.h>
#include <stdlib.h>
#include "expert_system.h"

struct	rpn
{
			struct rpn	*next;
			struct rpn	*prev;
			int			nbr;
};

struct rpn	*head;
struct rpn	*temp;
struct rpn	*new_nbr;

#endif
