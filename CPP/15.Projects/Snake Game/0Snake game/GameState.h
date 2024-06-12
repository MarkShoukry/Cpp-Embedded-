#pragma once

class GameState 
{

public:
    virtual void HandleInput() = 0 ;
    virtual void Update() = 0 ;
    virtual void Render() = 0 ;

    virtual ~GameState() = default ;

};