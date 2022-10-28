#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <memory>
#include <vector>

#include "Renderer/RenderMaster.h"
#include "States/StateBase.h"

#include "Context.h"

class Application
{
public:
    Application(const Config& config);

    void
    runLoop();

    template <typename T, typename... Args>
    void
    pushState(Args &&... args)
    {
        m_states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
        auto& s = m_states.back();
        s->onOpen();
    }

    void
    popState();

    const sf::Window&
    getWindow() const
    {
        return m_context.window;
    }
private:
    void handleEvents();

    std::vector<std::unique_ptr<StateBase>> m_states;
    Context m_context;
    RenderMaster m_masterRenderer;
    const Config& m_config;
    bool m_isPopState = false;
};

#endif
