#ifndef RETOOLED_WINDOW_HPP
#define RETOOLED_WINDOW_HPP

#include "log.hpp"
#include "event.hpp"

namespace ReTooled {

    class Window {
    public:
        Window(const char *title, int width, int height);

        ~Window();

        void update();

        bool closed() const;

        inline int getWidth() const { return m_width; }

        inline int getHeight() const { return m_height; }

        void setEventCallback(const std::function<void(const EventPointer &)> &callback) {
            m_eventCallback = callback;
        }

    private:
        GLFWwindow *m_window;
        std::function<void(const EventPointer &)> m_eventCallback;
        int m_width, m_height;
        bool m_closed;
        std::string m_name;
    };

} // ReTooled

#endif //RETOOLED_WINDOW_HPP
