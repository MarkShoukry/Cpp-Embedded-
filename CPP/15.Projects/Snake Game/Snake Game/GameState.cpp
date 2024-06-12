class GameState {
public:
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual ~GameState() = default;
};
