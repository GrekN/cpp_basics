#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>

enum class Player {
	User,
	AI
};

enum class Cell {
	EMPTY = '_',
	CROSS = 'X',
	NOUGHT = 'O',
};

enum class Status {
	IN_PROGRESS,
	DRAW,
	CROSS_WIN,
	NOUGHT_WIN
};

struct Game {
	Cell** field;
	Cell userPiece;
	Status status;
	Player currentPlayer;
};

struct Turn {
	int x;
	int y;
};

Cell getUserPiece() {
	int randomValue = rand() % 2;
	if (randomValue == 1) {
		return Cell::CROSS;
	}
	return Cell::NOUGHT;
}

Game* initGame() {
	Game* game = new Game();
	game->field = new Cell * [3];
	for (size_t i = 0; i < 3; i++)
	{
		game->field[i] = new Cell[3];
	}

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			game->field[i][j] = Cell::EMPTY;
		}
	}
	srand(static_cast<unsigned int>(time(nullptr)));
	game->userPiece = getUserPiece();
	game->status = Status::IN_PROGRESS;
	game->currentPlayer = game->userPiece == Cell::CROSS ? Player::User : Player::AI;
	return game;
}

void destroyGame(Game* game) {
	for (size_t i = 0; i < 3; i++)
	{
		delete game->field[i];
	}
	delete game->field;
	delete game;
}

void printField(const Cell* const* field) {
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << static_cast<char>(field[i][j]) << ' ';
		}
		std::cout << '\n';
	}
}

Cell** cloneField(const Cell* const* field) {
	Cell** newField = new Cell * [3];
	for (size_t i = 0; i < 3; i++)
	{
		newField[i] = new Cell[3];
	}

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			newField[i][j] = field[i][j];
		}
	}
	return newField;
}

void updateField(Game* game, const int x, const int y, const Cell value) {
	game->field[x][y] = value;
}


Status getGameStatus(const Cell* const* field) {

	// check rows
	for (size_t i = 0; i < 3; i++)
	{
		if (field[i][0] != Cell::EMPTY && field[i][0] == field[i][1] && field[i][1] == field[i][2]) {
			if (field[i][0] == Cell::CROSS) {
				return Status::CROSS_WIN;
			}
			else {
				return Status::NOUGHT_WIN;
			}
		}
	}

	// check columns
	for (size_t j = 0; j < 3; j++)
	{
		if (field[0][j] != Cell::EMPTY && field[0][j] == field[1][j] && field[1][j] == field[2][j]) {
			if (field[0][j] == Cell::CROSS) {
				return Status::CROSS_WIN;
			}
			else {
				return Status::NOUGHT_WIN;
			}
		}
	}

	// check diagonals
	if (field[0][0] != Cell::EMPTY && field[0][0] == field[1][1] && field[1][1] == field[2][2]) {
		if (field[0][0] == Cell::CROSS) {
			return Status::CROSS_WIN;
		}
		else {
			return Status::NOUGHT_WIN;
		}
	}
	if (field[2][0] != Cell::EMPTY && field[2][0] == field[1][1] && field[1][1] == field[0][2]) {
		if (field[2][0] == Cell::CROSS) {
			return Status::CROSS_WIN;
		}
		else {
			return Status::NOUGHT_WIN;
		}
	}

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (field[i][j] == Cell::EMPTY) {
				return Status::IN_PROGRESS;
			}
		}
	}

	return Status::DRAW;
}


void processUserInput(Game* game) {
	int x, y;
	do {
		std::cout << "Сделайте ход:";
		std::cin >> x >> y;
		if (x < 1 || x > 3 || y < 1 || y > 3 || game->field[x - 1][y - 1] != Cell::EMPTY) {
			std::cout << "Неверный номер клетки\n";
		}
	} while (x < 1 || x > 3 || y < 1 || y > 3 || game->field[x - 1][y - 1] != Cell::EMPTY);

	updateField(game, x - 1, y - 1, game->userPiece);
}

int minimax(Cell** field, bool isMaximizer) {
	Status gameStatus = getGameStatus(field);
	switch (gameStatus) {
	case Status::CROSS_WIN:
		return 10;
	case Status::NOUGHT_WIN:
		return -10;
	case Status::DRAW:
		return 0;
	}
	if (isMaximizer)
	{
		int value = -10;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (field[i][j] == Cell::EMPTY) {
					Cell** newField = cloneField(field);
					newField[i][j] = Cell::CROSS;
					int newFieldValue = minimax(newField, false);
					if (newFieldValue > value) {
						value = newFieldValue;
					}
				}
			}
		}
		return value;
	}
	else
	{
		int value = 10;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (field[i][j] == Cell::EMPTY) {
					Cell** newField = cloneField(field);
					newField[i][j] = Cell::NOUGHT;
					int newFieldValue = minimax(newField, true);
					if (newFieldValue < value) {
						value = newFieldValue;
					}
				}
			}
		}
		return value;

	}
};

Turn getBestTurn(Cell** field, Cell piece) {

	Turn bestTurn;
	int value;

	if (piece == Cell::CROSS) {
		value = -10;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (field[i][j] == Cell::EMPTY) {
					Cell** newField = cloneField(field);
					newField[i][j] = piece;
					int newFieldValue = minimax(newField, false);
					if (newFieldValue > value) {
						value = newFieldValue;
						bestTurn = { i, j };
					}
				}
			}
		}
	}
	else {
		value = 10;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (field[i][j] == Cell::EMPTY) {
					Cell** newField = cloneField(field);
					newField[i][j] = piece;
					int newFieldValue = minimax(newField, true);
					if (newFieldValue < value) {
						value = newFieldValue;
						bestTurn = { i, j };
					}
				}
			}
		}
	}
	return bestTurn;
}

void processAIInput(Game* game) {
	Cell aiPeace = game->userPiece == Cell::CROSS ? Cell::NOUGHT : Cell::CROSS;
	Turn aiTurn = getBestTurn(game->field, aiPeace);
	updateField(game, aiTurn.x, aiTurn.y, aiPeace);;
}

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");

	Game* game = initGame();
	std::cout << "Вы играете " << static_cast<char>(game->userPiece) << '\n';
	printField(game->field);

	while (game->status == Status::IN_PROGRESS) {
		if (game->currentPlayer == Player::User)
		{
			processUserInput(game);
			std::cout << "Ваш ход:\n";
		}
		else
		{
			processAIInput(game);
			std::cout << "Ход противника:\n";
		}
		printField(game->field);
		game->currentPlayer = game->currentPlayer == Player::User ? Player::AI : Player::User;
		game->status = getGameStatus(game->field);
	}

	if ((game->status == Status::CROSS_WIN && game->userPiece == Cell::CROSS) || (game->status == Status::NOUGHT_WIN && game->userPiece == Cell::NOUGHT))
	{
		std::cout << "Вы победили !";
	}
	else if ((game->status == Status::CROSS_WIN && game->userPiece == Cell::NOUGHT) || (game->status == Status::NOUGHT_WIN && game->userPiece == Cell::CROSS))
	{
		std::cout << "Вы проиграли :(";
	}
	else
	{
		std::cout << "Ничья";
	}

	destroyGame(game);
}
