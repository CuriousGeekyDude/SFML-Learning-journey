#include "SpriteBounceGame.hpp"

int main()
{
	try {
		SpriteBounceGame game;
		game.HandleInput();

		while (!game.GetWindow()->IsDone()) {
			game.Update();
			game.Render();
			game.RestartClock();
		}
	}

	catch (int error) {
		return error;
	}
	return 0;
}