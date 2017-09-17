#pragma once
#include <Core/Application.hpp>

class Game : public Gandiva::Core::Application
{
public:
	Game();
	virtual ~Game();

private:
	virtual void update();
	virtual void render();
};

