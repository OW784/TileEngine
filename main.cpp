#include "game_parameters.hpp"
#include "game_system.hpp"
#include "scenes.hpp"


using param = Parameters;

int main() {
	Scenes::maze = std::make_shared<MazeScene>();
	std::static_pointer_cast<MazeScene>(Scenes::maze)->set_file_path(param::maze_1);
	Scenes::maze->load();
	unsigned int game_width = ls::get_width() * 100;
	unsigned int game_height = ls::get_height() * 100;
	GameSystem::set_active_scene(Scenes::maze);
	GameSystem::start(game_width, game_height, "Tile Maze", param::time_step);

	return 0;
}