#ifndef RETOOLED_GFLWWINDOW_HPP
#define RETOOLED_GFLWWINDOW_HPP

#include "../window.hpp"

namespace ReTooled {
    class GFLWWindow : public Window {

    public:
        GFLWWindow(const WindowData &data = WindowData());

        ~GFLWWindow() override;

        void update() override;

        inline unsigned int getWidth() const override { return m_data.width; }

        inline unsigned int getHeight() const override { return m_data.height; }

        void setEventCallback(const std::function<ListenerType> &callback) override {
            m_data.eventCallback = callback;
        }

    private:
        GLFWwindow *m_window;
    };
}

#endif //RETOOLED_GFLWWINDOW_HPP
