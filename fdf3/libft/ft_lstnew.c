/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:43:33 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/01/05 15:26:56 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

z_list	*ft_lstnew(void *content)
{
	z_list	*t;

	t = malloc(sizeof(z_list));
	if (t)
	{
		t->content = content;
		t->next = NULL;
		return (t);
	}
	return (NULL);
}
