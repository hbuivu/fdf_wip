#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
// # include <X11/keysym.h>
# include <stdio.h>

# define WHITE 0xFFFFFF

// # define HEIGHT	1080
// # define WIDTH	1920

# define HEIGHT	700
# define WIDTH	700

int		read_color(char *str);
void	release_lines(char **split_line);
int		count_columns(char *s);
m_list	*init_master(char *line, int fd);
p_list	**read_map(int fd, char *line, m_list *master);
void	draw_img(t_data *data, p_list **plist, m_list *master);
void	init_window(v_list *vlist);
void	calculate_coordinates(p_list **plist, m_list *m);
#endif