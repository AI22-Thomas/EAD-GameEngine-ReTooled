#ifndef RETOOLED_WINDOW_HPP
#define RETOOLED_WINDOW_HPP

#include "event.hpp"

namespace ReTooled {

    struct WindowData {
        std::string title = "ReTooled";
        unsigned int width = 1280;
        unsigned int height = 720;
        std::function<void(const EventPointer &)> eventCallback;
    };

    class Window {
    public:
        Window(const WindowData &data = WindowData()) : m_data(data) {}

        virtual ~Window() {}

        virtual void update() = 0;

        virtual unsigned int getWidth() const = 0;

        virtual unsigned int getHeight() const = 0;

        virtual void setEventCallback(const std::function<ListenerType> &callback) = 0;

    protected:
        WindowData m_data;
    };

} // ReTooled

#endif //RETOOLED_WINDOW_HPP
