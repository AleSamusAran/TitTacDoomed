#include "Game.h"

Game::Game()
{
	int pos = 0;
	for (size_t i = 0; i < sizeof(mSlots)/sizeof(mSlots[0]); i++)
	{
		for (size_t j = 0; j < sizeof(mSlots[0])/ sizeof(Slot); j++)
		{
			mSlots[i][j].mPosition = pos;
			mSlots[i][j].mValue = " ";
			pos++;
		}
	}
}

Game::~Game()
{
}

void Game::Draw()
{
	std::cout << endl
		<< " " + mSlots[0][0].mValue + " | " + mSlots[0][1].mValue + " | " + mSlots[0][2].mValue + " " << endl
		<< "-----------" << endl
		<< " " + mSlots[1][0].mValue + " | " + mSlots[1][1].mValue + " | " + mSlots[1][2].mValue + " " << endl
		<< "-----------" << endl
		<< " " + mSlots[2][0].mValue + " | " + mSlots[2][1].mValue + " | " + mSlots[2][2].mValue + " " << endl
			 << endl;
}

void Game::Input(int position, Player player)
{
	for (size_t i = 0; i < sizeof(mSlots) / sizeof(mSlots[0]); i++)
	{
		for (size_t j = 0; j < sizeof(mSlots[0]) / sizeof(Slot); j++)
		{
			mSlots[i][j].mValue = (mSlots[i][j].mPosition == position)? (player == Player::PLAYER_ONE)? "X" : "O" : mSlots[i][j].mValue;
		}
	}
}

 bool Game::CheckResult(Player player)
{
	string playerName = (player == Player::PLAYER_ONE) ? "Player One" : "Player Two";

	for (size_t i = 0; i < sizeof(mSlots) / sizeof(mSlots[0]); i++)
	{
		if (mSlots[i][0].mValue == mSlots[i][1].mValue && mSlots[i][0].mValue == mSlots[i][2].mValue && mSlots[i][0].mValue != " ")
		{
			cout << playerName + " Wins!!!!" << endl;
			return true;
		}
	}

	for (size_t i = 0; i < sizeof(mSlots[0]) / sizeof(Slot); i++)
	{
		if (mSlots[0][i].mValue == mSlots[1][i].mValue && mSlots[0][i].mValue == mSlots[2][i].mValue && mSlots[0][i].mValue != " ")
		{
			cout << playerName + " Wins!!!!" << endl;
			return true;
		}
	}

	if (mSlots[0][0].mValue == mSlots[1][1].mValue && mSlots[0][0].mValue == mSlots[2][2].mValue && mSlots[0][0].mValue != " ")
	{
		cout << playerName + " Wins!!!!" << endl;
		return true;
	}

	if (mSlots[0][2].mValue == mSlots[1][1].mValue && mSlots[0][2].mValue == mSlots[2][0].mValue && mSlots[0][2].mValue !=  " ")
	{
		cout << playerName + " Wins!!!!" << endl;
		return true;
	}

	return false;
}
