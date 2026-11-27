#include "State.h"
class GameState:public State{
    private:
    void initMap();
    public:
    void update() override;
    void render(sf::RenderTarget* target);
    GameState(GamePack& gamePack);
};