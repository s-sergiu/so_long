//void	run_left_animation(void *param)
//{
//	t_data			*data;
//	mlx_image_t		*player[8];
//	static int		frames;
//	static int		i;
//	uint8_t			*player_pixels;
//
//	data = param;
//	player_pixels = data->player_img->pixels;
//	if (frames == 0 || frames % 7 == 0)
//	{
//		player[i] = mlx_texture_to_image(data->mlx, data->run->left[i]);
//		memcpy(player_pixels, player[i]->pixels, SPRITE * SPRITE * sizeof(uint8_t));
//		if(i == 7)
//		{
//			frames = -1;
//			i = - 1;
//		}
//		i++;
//	}
//	frames++;
//}
//
//void	run_right_animation(void *param)
//{
//	t_data			*data;
//	mlx_image_t		*player[8];
//	static int		frames;
//	static int		i;
//
//	data = param;
//	if (frames == 0 || frames % 7 == 0)
//	{
//		player[i] = mlx_texture_to_image(data->mlx, data->run->right[i]);
//		memcpy(data->player_img->pixels, player[i]->pixels, SPRITE * SPRITE * sizeof(uint8_t));
//		if(i == 7)
//		{
//			frames = -1;
//			i = - 1;
//		}
//		i++;
//	}
//	frames++;
//}
//
//void	idle_animation(void *param)
//{
//	t_data			*data;
//	mlx_image_t		*player[8];
//	static int		frames;
//	static int		i;
//
//	data = param;
//	if (frames == 0 || frames % 7 == 0)
//	{
//		player[i] = mlx_texture_to_image(data->mlx, data->idle->right[i]);
//		memcpy(data->player_img->pixels, player[i]->pixels, SPRITE * SPRITE * sizeof(uint8_t));
//		if(i == 7)
//		{
//			frames = -1;
//			i = - 1;
//		}
//		i++;
//	}
//	frames++;
//}
//
//void	hook(void *param)
//{
//	t_data			*data;
//
//	data = param;
//	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
//		mlx_close_window(data->mlx);
//	if (mlx_is_key_down(data->mlx, MLX_KEY_D) || mlx_is_key_down(data->mlx,
//		MLX_KEY_A) || mlx_is_key_down(data->mlx, MLX_KEY_W) ||
//		mlx_is_key_down(data->mlx, MLX_KEY_S))
//	{
//		if (mlx_is_key_down(data->mlx, MLX_KEY_A))
//		{
//			run_left_animation(data);
//			data->player_img->instances[0].x -= 120 * data->mlx->delta_time;
//			data->player_box->instances[0].x -= 120 * data->mlx->delta_time;
//		}
//		if (mlx_is_key_down(data->mlx, MLX_KEY_S))
//		{
//			data->player_img->instances[0].y += 180 * data->mlx->delta_time;
//			data->player_box->instances[0].y += 180 * data->mlx->delta_time;
//		}
//		if (mlx_is_key_down(data->mlx, MLX_KEY_W))
//		{
//			data->player_img->instances[0].y -= 120 * data->mlx->delta_time;
//			data->player_box->instances[0].y -= 120 * data->mlx->delta_time;
//		}
//		if (mlx_is_key_down(data->mlx, MLX_KEY_D))
//		{
//			run_right_animation(data);
//			data->player_img->instances[0].x += 180 * data->mlx->delta_time;
//			data->player_box->instances[0].x += 180 * data->mlx->delta_time;
//		}
//	}
//	else 
//		idle_animation(data);
//}
