#include <stdlib.h>
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

/*int	handle_no_event(void *data)
{
	return (0);
}*/

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	printf("Keypress: %d\n", keysym);
	return (0);
}

/*int	handle_keyrelease(int keysym, t_data *data)
{
	printf("Keyrelease: %d\n", keysym);
	return (0);
}*/

int main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "Windoe Wun"); 
	if (data.win_ptr == NULL)
		return (free(data.win_ptr), 1);
	/*HOOK SETUP*/
	/*mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);*/
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	/*mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);*/

	//mlx_key_hook(data.win_ptr, &handle_input, &data);
	
	mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}

