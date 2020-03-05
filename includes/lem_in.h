/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeuil <mbeuil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:11:16 by mbeuil            #+#    #+#             */
/*   Updated: 2019/03/26 15:11:22 by mbeuil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include "./printf/printf.h"
# include <stdio.h>

typedef struct	s_lane
{
	char		**node;
	int			*trace;
	int			size;
	int			rounds;
	int			ants;
}				t_lane;

typedef struct	s_buffer
{
	char		**tab;
	int			s;
}				t_buffer;

typedef struct	s_rooms
{
	char		*name;
	int			role;
	int			capacity;
	int			exception;
}				t_rooms;

typedef struct	s_farm
{
	int			step;
	int			n_ants;
	char		*command;
	int			n_rooms;
	t_rooms		**rooms;
	int			start;
	int			end;
	char		**paths;
	char		**r_graph;
	t_lane		**lane;
	int			round;
	int			ant;
	t_buffer	*buffer;
	int			max_flow;
}				t_farm;

t_farm			*init_farm(void);
int				fill_farm(t_farm *farm);
int				add_paths(char *line, t_farm *farm);
int				add_rooms(char *line, t_farm *farm);
t_rooms			**dup_struct(t_farm *farm);
int				verif_room(t_farm *farm, char **tab);
int				add_command(char *line, t_farm *farm);
int				add_buffer(t_farm *farm, char *line, int i);
int				create_matrix(t_farm *farm);
int				ft_tablen(char **tab);
int				fill_paths(t_farm *farm, char **room);
void			ft_freetab(char **tab);
void			li_freefarm(t_farm *farm);
void			li_freelane(t_lane **lane);
void			li_freenode_reverse(t_lane *lane);
int				resolve_lemin(t_farm *farm);
char			**create_residual_graph(t_farm *farm);
int				verif_node(t_farm *farm, int i, int j, int *visited);
void			update_capacity(t_farm *farm, int front, int back);
void			ft_lstdelfront(t_list **queue);
int				add_lane(t_farm *farm);
void			sort_lane(t_lane **lane, int max_flow);
void			dispatch_lane(t_lane **lane, t_farm *farm);
void			save_lane(t_lane **lane, t_farm *farm);
int				print_farm(t_farm *farm);

#endif
