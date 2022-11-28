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
//
//void	run_left_animation(void *param)
//{
//	t_data			*data;
//	mlx_image_t		*player[8];
//	static int		frames;
//	static int		i;
//
//	data = param;
//	if (frames == 0 || frames % 7 == 0)
//	{
//		player[i] = mlx_texture_to_image(data->mlx, data->run->left[i]);
//		memcpy(data->player_img->pixels, player[i]->pixels, 64 * 64 * 4);
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
//		memcpy(data->player_img->pixels, player[i]->pixels, 64 * 64 * 4);
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
//		memcpy(data->player_img->pixels, player[i]->pixels, 64 * 64 * 4);
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

void	init_run_texture(t_data **data)
{
	t_run	*run;

	(*data)->run = (t_run *)malloc(sizeof(t_run));
	run = (*data)->run;
	run->right[0] = mlx_load_png("assets/player/run/right/0.png");
	run->right[1] = mlx_load_png("assets/player/run/right/1.png");
	run->right[2] = mlx_load_png("assets/player/run/right/2.png");
	run->right[3] = mlx_load_png("assets/player/run/right/3.png");
	run->right[4] = mlx_load_png("assets/player/run/right/4.png");
	run->right[5] = mlx_load_png("assets/player/run/right/5.png");
	run->right[6] = mlx_load_png("assets/player/run/right/6.png");
	run->right[7] = mlx_load_png("assets/player/run/right/7.png");
	run->right[8] = NULL;
	run->left[0] = mlx_load_png("assets/player/run/left/0.png");
	run->left[1] = mlx_load_png("assets/player/run/left/1.png");
	run->left[2] = mlx_load_png("assets/player/run/left/2.png");
	run->left[3] = mlx_load_png("assets/player/run/left/3.png");
	run->left[4] = mlx_load_png("assets/player/run/left/4.png");
	run->left[5] = mlx_load_png("assets/player/run/left/5.png");
	run->left[6] = mlx_load_png("assets/player/run/left/6.png");
	run->left[7] = mlx_load_png("assets/player/run/left/7.png");
	run->left[8] = NULL;
	load_run_images(data);
	delete_run_textures(data);
}

void	load_run_images(t_data **data)
{
	t_run	*run;

	run = (*data)->run;
	run->right_run[0] = mlx_texture_to_image((*data)->mlx, run->right[0]);
	run->right_run[1] = mlx_texture_to_image((*data)->mlx, run->right[1]);
	run->right_run[2] = mlx_texture_to_image((*data)->mlx, run->right[2]);
	run->right_run[3] = mlx_texture_to_image((*data)->mlx, run->right[3]);
	run->right_run[4] = mlx_texture_to_image((*data)->mlx, run->right[4]);
	run->right_run[5] = mlx_texture_to_image((*data)->mlx, run->right[5]);
	run->right_run[6] = mlx_texture_to_image((*data)->mlx, run->right[6]);
	run->right_run[7] = mlx_texture_to_image((*data)->mlx, run->right[7]);
	run->right_run[8] = NULL;
	run->left_run[0] = mlx_texture_to_image((*data)->mlx, run->left[0]);
	run->left_run[1] = mlx_texture_to_image((*data)->mlx, run->left[1]);
	run->left_run[2] = mlx_texture_to_image((*data)->mlx, run->left[2]);
	run->left_run[3] = mlx_texture_to_image((*data)->mlx, run->left[3]);
	run->left_run[4] = mlx_texture_to_image((*data)->mlx, run->left[4]);
	run->left_run[5] = mlx_texture_to_image((*data)->mlx, run->left[5]);
	run->left_run[6] = mlx_texture_to_image((*data)->mlx, run->left[6]);
	run->left_run[7] = mlx_texture_to_image((*data)->mlx, run->left[7]);
	run->left_run[8] = NULL;
}

void	destroy_run_structure(t_data **data)
{
	t_run	*image;

	image = (*data)->run;
	free(image);
}

void	delete_run_textures(t_data **data)
{
	t_run	*run;

	run = (*data)->run;
	mlx_delete_texture(run->right[0]);
	mlx_delete_texture(run->right[1]);
	mlx_delete_texture(run->right[2]);
	mlx_delete_texture(run->right[3]);
	mlx_delete_texture(run->right[4]);
	mlx_delete_texture(run->right[5]);
	mlx_delete_texture(run->right[6]);
	mlx_delete_texture(run->right[7]);
	mlx_delete_texture(run->left[0]);
	mlx_delete_texture(run->left[1]);
	mlx_delete_texture(run->left[2]);
	mlx_delete_texture(run->left[3]);
	mlx_delete_texture(run->left[4]);
	mlx_delete_texture(run->left[5]);
	mlx_delete_texture(run->left[6]);
	mlx_delete_texture(run->left[7]);
}

