#include "Game.hpp"


int main()
{
	std::unique_ptr<Game> game = std::make_unique<Game>();

	while (game->GetWindow()->isOpen())
	{
		game->HandleInput();
		game->Update();
		game->Render();
		game->GameOver();
		game->RestartTimer();

	}

}