#include "window.hpp"

namespace ReTooled {

    Window::Window(const char *title, int width, int height) {
        m_width = width;
        m_height = height;
        m_closed = false;

        glfwSetErrorCallback([](int error, const char *description) {
            RT_CORE_LOG_ERROR("GLFW Error ({0}): {1}", error, description);
        });

        if (!glfwInit()) {
            RT_CORE_LOG_ERROR("Failed to initialize GLFW");
            throw std::runtime_error("Failed to initialize GLFW");
        }

        m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (m_window == nullptr) {
            RT_CORE_LOG_ERROR("Failed to create GLFW window");
            glfwTerminate();
            throw std::runtime_error("Failed to create GLFW window");
        }

        glfwMakeContextCurrent(m_window);

        glfwSetKeyCallback(m_window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
            RT_CORE_LOG_INFO("Key: {0}, Scancode: {1}, Action: {2}, Mods: {3}", key, scancode, action, mods);
            // call event callback
            auto windowPointer = static_cast<Window *>(glfwGetWindowUserPointer(window));
            if (windowPointer->m_eventCallback) {
                windowPointer->m_eventCallback(std::make_shared<ReTooled::KeyboardEvent>(key));
            }
        });
    }

    Window::~Window() {
        glfwTerminate();
    }

    void Window::update() {
        glfwPollEvents();
        m_closed = glfwWindowShouldClose(m_window);
    }

    bool Window::closed() const {
        return m_closed;
    }

} // ReTooled