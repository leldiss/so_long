/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leldiss <leldiss@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:41:05 by leldiss           #+#    #+#             */
/*   Updated: 2022/03/09 01:30:45 by leldiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(int button, t_root *root)
{
	static int	steps = 0;

	if (button == ESCAPE)
		end_programm(root);
	if (button == UP)
		steps = move_player_up(root, steps);
	else if (button == DOWN)
		steps = move_player_down(root, steps);
	else if (button == LEFT)
		steps = move_player_left(root, steps);
	else if (button == RIGHT)
		steps = move_player_right(root, steps);
	return (0);
}

t_root	draw_map(t_root root, char *file_name)
{
	int	i;
	int	k;

	i = 0;
	root.y = 0;
	root.collect_count = 0;
	root = map_create(file_name, root);
	root = get_textures(root);
	while (i < root.linecount)
	{
		root.x = 0;
		k = 0;
		while (k < root.linelength)
		{
			root = draw_texture(root, i, k);
			root.x += STEP_X;
			k++;
		}
		root.y += STEP_Y;
		i++;
	}
	return (root);
}

t_root	get_textures(t_root root)
{
	int	img_width;
	int	img_height;

	img_height = STEP_Y;
	img_width = STEP_X;
	root.player = mlx_xpm_file_to_image(root.connection, PLAYER,
			&img_width, &img_height);
	root.floor = mlx_xpm_file_to_image(root.connection, FLOOR,
			&img_width, &img_height);
	root.wall = mlx_xpm_file_to_image(root.connection, WALL,
			&img_width, &img_height);
	root.door = mlx_xpm_file_to_image(root.connection, EXIT,
			&img_width, &img_height);
	root.collectible = mlx_xpm_file_to_image(root.connection, COLLECTIBLE,
			&img_width, &img_height);
	return (root);
}

t_root	draw_texture(t_root root, int i, int k)
{
	if (root.map[i][k] == '1')
		mlx_put_image_to_window(root.connection, root.window,
			root.wall, root.x, root.y);
	else if (root.map[i][k] == '0')
		mlx_put_image_to_window(root.connection, root.window,
			root.floor, root.x, root.y);
	else if (root.map[i][k] == 'C')
	{
		mlx_put_image_to_window(root.connection, root.window,
			root.collectible, root.x, root.y);
		root.collect_count++;
	}
	else if (root.map[i][k] == 'E')
		mlx_put_image_to_window(root.connection, root.window,
			root.door, root.x, root.y);
	else if (root.map[i][k] == 'P')
	{
		mlx_put_image_to_window(root.connection, root.window,
			root.player, root.x, root.y);
		root.player_x = root.x;
		root.player_y = root.y;
		root.playerx_matrix = k;
		root.playery_matrix = i;
	}
	return (root);
}

int	main(int argc, char *argv[])
{
	t_root	root;

	root.e = 0;
	valid_file(argc, argv[1]);
	root.linecount = line_count(argv[1]);
	root.linelength = line_length(argv[1]);
	if (root.linecount == -1)
		null_error("open or reading file error");
	else if (root.linelength == -1)
		null_error("map should be a rectangular");
	else if (root.linecount < 3 || root.linelength < 5)
		null_error("map configuration error");
	root.connection = mlx_init();
	root.window = mlx_new_window(root.connection, STEP_X
			* root.linelength, STEP_Y * root.linecount, "so_long");
	root = draw_map(root, argv[1]);
	mlx_hook(root.window, 2, 1L << 0, &close_window, &root);
	mlx_hook(root.window, 17, 1L << 17, &end_programm, &root);
	mlx_hook(root.window, 12, 1L << 18, &mlx_expose_hook, &root);
	mlx_loop(root.connection);
	return (0);
}
