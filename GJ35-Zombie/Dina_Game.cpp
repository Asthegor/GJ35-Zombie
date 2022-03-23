#pragma once
#include "Dina_Game.h"

#include <Dina.h>
#include "Menus/Logo/Logo.h"
#include "Menus/MainMenu/MainMenu.h"
#include "Game/Game.h"


Dina_Game::Dina_Game()
{
	SetTitle("GameJam GC35 - Zombies");
	SetDimensions(1280, 720);
}

void Dina_Game::Load()
{
	// Utiliser la commande GameState::AddState pour rajouter un état.
	GameState::AddState("Logo", new Logo);
	GameState::AddState("Menu", new MainMenu);
	GameState::AddState("Game", new Game);

	// Utiliser GameState::SetCurrentState pour définir l'état courant.
	GameState::SetCurrentState("Logo");
}

void Dina_Game::Update(double deltatime)
{
	// Permet de lancer la fonction Update du Component de l'état courant
	if (auto state = GameState::GetState())
		state->Update(deltatime);
}

void Dina_Game::Draw()
{
	// Permet de lancer la fonction Draw du Component de l'état courant
	if (auto state = GameState::GetState())
		state->Draw();
}

// !!! NE PAS EFFACER !!!
// 
// Fonction utilisée pour le lancement du jeu
//
DinaGame* Dina::CreateGame()
{

	return new Dina_Game;
}
