#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using std::vector;
using std::cin;
using std::cout;
using std::string;

typedef vector<vector<char>>	t_map;
typedef	struct
{
	int	x;
	int	y;
	int	o;
}	t_player;

typedef struct
{
	t_map		map;
	t_player	player;
	int		count;
	int		count_on_path;
	char		path;
}	t_game;

t_game	get_map()
{
	string		line;
	t_game		game;
	t_map		map;
	t_player	player;

	// read map
	while (std::getline(cin, line))
	{
		char c;
		vector<char> tmp;

		std::istringstream sl(line);
		while(sl >> c)
			tmp.push_back(c);
		map.push_back(tmp);
	}

	// find player
	for (int j = 0; j < map.size(); j++)
		for (int i = 0; i < map[j].size(); i++)
			if (map[j][i] == '^')
			{
				player = {.x = i, .y = j, .o = 0};
				map[j][i] = '.';
				break ;
			}
	game.map = map;
	game.player = player;
	game.count = 0;
	game.count_on_path = 0;
	game.path = '$';
	return (game);
}

void	print_game(t_game &game)
{
	t_map		&map = game.map;
	t_player	&player = game.player;

	for (int j = 0; j < map.size(); j++)
	{
		for (int i = 0; i < map[j].size(); i++)
		{
			if (i == player.x && j == player.y)
				cout << "@";
			else
				cout << map[j][i];
		}
	cout << std::endl;
	}
	cout << game.count << std::endl;
	cout << std::setw(map[0].size()) << std::setfill('-') << '-' << std::endl << std::endl;
}

int	update_loop(t_game &game)
{
	t_map		&map = game.map;
	t_player	&player = game.player;

	if (game.count_on_path > 10000)
		return (1);
	// if (map[player.y][player.x] != '$')
	// 	return (0);
	// if (player.o == 0 && map[player.y - 1][player.x] == '#')
	// {
	// 	return (1);
	// }
	// else if (player.o == 1 && map[player.y][player.x + 1] == '#')
	// {
	// 	return (1);
	// }
	// else if (player.o == 2 && map[player.y + 1][player.x] == '#')
	// {
	// 	return (1);
	// }
	// else if (player.o == 3 && map[player.y][player.x - 1] == '#')
	// {
	// 	return (1);
	// }
	return (0);
}

int	update_out(t_game &game)
{
	t_map		&map = game.map;
	t_player	&player = game.player;

	if (player.x == 0 && player.o == 3)
		return (1);
	if (player.y == 0 && player.o == 0)
		return (1);
	if (player.x == map.size() - 1 && player.o == 1)
		return (1);
	if (player.y == map[0].size() - 1 && player.o == 2)
		return (1);
	return (0);
}

int	update_collide(t_game &game)
{
	t_map		&map = game.map;
	t_player	&player = game.player;

	if (player.o == 0 && map[player.y - 1][player.x] == '#')
	{
		player.o++;
		return (1);
	}
	else if (player.o == 1 && map[player.y][player.x + 1] == '#')
	{
		player.o++;
		return (1);
	}
	else if (player.o == 2 && map[player.y + 1][player.x] == '#')
	{
		player.o++;
		return (1);
	}
	else if (player.o == 3 && map[player.y][player.x - 1] == '#')
	{
		player.o = 0;
		return (1);
	}
	return (0);
}
int	update_walk(t_game &game)
{
	t_map		&map = game.map;
	t_player	&player = game.player;

	if (player.o == 3)
		player.x--;
	if (player.o == 0)
		player.y--;
	if (player.o == 1)
		player.x++;
	if (player.o == 2)
		player.y++;
	return (1);
}

int	update(t_game &game)
{
	t_map		&map = game.map;
	t_player	&player = game.player;

	if (map[player.y][player.x] != game.path)
		game.count++;
	else
		game.count_on_path++;
	map[player.y][player.x] = game.path;
	if (update_out(game))
		return 0;
	if (update_collide(game))
		return (1);
	if (update_walk(game))
		return (1);
	return (1);
}

int	test(t_game &game)
{
	while (update(game))
	{
		if (update_loop(game))
			return (1);
		// print_game(game);
	}
	return (0);
}

int	brut_force(t_game &origin_game)
{
	t_game		with_path = origin_game;
	t_map		&map = with_path.map;
	t_player	&player = with_path.player;
	int		loop_count = 0;
	int		total = 0;

	print_game(origin_game);
	test(with_path);
	print_game(with_path);
	for (int j = 0; j < map.size(); j++)
		for (int i = 0; i < map[j].size(); i++)
		{
			if (map[j][i] != with_path.path)	
				continue ;
			total++;
			cout << "testing: i=" << i << " j=" << j << std::endl;
			t_game test_game = origin_game;
			test_game.map[j][i] = '#';
			if (test(test_game))
			{
				loop_count++;
				//print_game(test_game);
			}
		}
	cout << "total: " << total << std::endl;
	return (loop_count);
}

int main()
{
	t_game	game = get_map();
	int	loop_count = 0;
	
	loop_count = brut_force(game);
	cout << loop_count << std::endl;
}