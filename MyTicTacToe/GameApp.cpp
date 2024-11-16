#include "GameApp.h"

#include "RenderableComponent.h"
#include "PositionComponent.h"
#include "ButtonComponent.h"

void GameApp::Initialize(const char* title, int width, int height) {

	std::cout << "Initializing GameApp" << std::endl;

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
		return;
	}

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	if (window == nullptr) {
		std::cerr << "Error creating window: " << SDL_GetError() << std::endl;
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == nullptr) {
		std::cerr << "Error creating renderer: " << SDL_GetError() << std::endl;
		return;
	}

	//Initialize game elements here

	auto actor = std::shared_ptr<Actor>(actorFactory.CreateActor("TestingActor"));
	actor->AddComponent(new PositionComponent());
	actor->AddComponent(new RenderableComponent());
	actor->AddComponent(new ButtonComponent(Vector2(100, 100)));
	actor->GetComponent<PositionComponent>()->SetPosition(Vector2(100, 100));

	Scene* scene = new Scene();
	scene->AddActor(actor);

	sceneManager.AddScene(scene);
	sceneManager.LoadScene(0);

	isRunning = true;
}


void GameApp::Run() {
	while (isRunning) {
		HandleEvents();
		Update();
		Render();
	}
}

void GameApp::Clean() {
	sceneManager.Cleanup();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void GameApp::Update() {
	sceneManager.Update(0);
}

void GameApp::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	sceneManager.Render(renderer);

	SDL_RenderPresent(renderer);
}

void GameApp::HandleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				isRunning = false;
				break;
			default:
				break;
		}
	}
}

