#ifndef PLAYINGSTATE_H_INCLUDED
#define PLAYINGSTATE_H_INCLUDED

#include "StateBase.h"
#include "../Application.h"

namespace sf
{
    class Event;
}

class StatePlaying : public StateBase
{
public:
    StatePlaying(Application& app, const Config& config);

    void 
    handleEvent(sf::Event e) override;
    void 
    handleInput() override;
    void 
    update(float deltaTime) override;
    void 
    render(RenderMaster& renderer) override;
    void
    onOpen() override;
};

#endif
