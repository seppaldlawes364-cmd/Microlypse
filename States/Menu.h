#include "State.h"
class Menu: public State{
private:
    Button gameButton{sf::Vector2f(400,150)};
public:
    void update() override;
    void render(sf::RenderTarget* target) override;
    Menu(GamePack& gamePack);
};