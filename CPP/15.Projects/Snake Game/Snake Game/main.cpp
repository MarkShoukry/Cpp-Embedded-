#include "GameController.cpp"

int main() 
{
    GameController& controller = GameController::getInstance();
    controller.run();
    return 0;
}
