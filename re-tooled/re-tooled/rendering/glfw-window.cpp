#include "glfw-window.hpp"

namespace ReTooled {

    GFLWWindow::GFLWWindow(const WindowData &data) : Window(data) {
        glfwSetErrorCallback([](int error, const char *description) {
            RT_CORE_LOG_ERROR("GLFW Error ({0}): {1}", error, description);
        });

        if (!glfwInit()) {
            RT_CORE_LOG_ERROR("Failed to initialize GLFW");
            throw std::runtime_error("Failed to initialize GLFW");
        }

        m_window = glfwCreateWindow(m_data.width, m_data.height, m_data.title.c_str(), nullptr, nullptr);
        if (m_window == nullptr) {
            RT_CORE_LOG_ERROR("Failed to create GLFW window");
            glfwTerminate();
            throw std::runtime_error("Failed to create GLFW window");
        }

        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, &m_data);

        glfwSetKeyCallback(m_window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
            RT_CORE_LOG_INFO("Key: {0}, Scancode: {1}, Action: {2}, Mods: {3}", key, scancode, action, mods);
            // call event callback
            auto wData = static_cast<WindowData *>(glfwGetWindowUserPointer(window));
            if (wData->eventCallback) {
                switch (action) {
                    case GLFW_PRESS:
                        wData->eventCallback(std::make_shared<ReTooled::KeyPressedEvent>(key, 0));
                        break;
                    case GLFW_RELEASE:
                        wData->eventCallback(std::make_shared<ReTooled::KeyReleasedEvent>(key));
                        break;
                    case GLFW_REPEAT:
                        wData->eventCallback(std::make_shared<ReTooled::KeyPressedEvent>(key, 1));
                        break;
                }
            }
        });

        glfwSetWindowSizeCallback(m_window, [](GLFWwindow *window, int width, int height) {
            RT_CORE_LOG_INFO("Window resized to {0}x{1}", width, height);
            // call event callback
            auto wData = static_cast<WindowData *>(glfwGetWindowUserPointer(window));
            wData->width = width;
            wData->height = height;
            if (wData->eventCallback) {
                wData->eventCallback(std::make_shared<ReTooled::WindowResizeEvent>(width, height));
            }
        });

        glfwSetWindowCloseCallback(m_window, [](GLFWwindow *window) {
            RT_CORE_LOG_INFO("Window close requested");
            // call event callback
            auto wData = static_cast<WindowData *>(glfwGetWindowUserPointer(window));
            if (wData->eventCallback) {
                wData->eventCallback(std::make_shared<ReTooled::WindowCloseEvent>());
            }
        });

        glfwSetMouseButtonCallback(m_window, [](GLFWwindow *window, int button, int action, int mods) {
            RT_CORE_LOG_INFO("Mouse button: {0}, Action: {1}, Mods: {2}", button, action, mods);
            // call event callback
            auto wData = static_cast<WindowData *>(glfwGetWindowUserPointer(window));
            if (wData->eventCallback) {
                switch (action) {
                    case GLFW_PRESS:
                        wData->eventCallback(std::make_shared<ReTooled::MouseButtonPressedEvent>(button));
                        break;
                    case GLFW_RELEASE:
                        wData->eventCallback(std::make_shared<ReTooled::MouseButtonReleasedEvent>(button));
                        break;
                }
            }
        });

        glfwSetScrollCallback(m_window, [](GLFWwindow *window, double xOffset, double yOffset) {
            RT_CORE_LOG_INFO("Mouse scroll: {0}, {1}", xOffset, yOffset);
            // call event callback
            auto wData = static_cast<WindowData *>(glfwGetWindowUserPointer(window));
            if (wData->eventCallback) {
                wData->eventCallback(std::make_shared<ReTooled::MouseScrolledEvent>(xOffset, yOffset));
            }
        });

        glfwSetCursorPosCallback(m_window, [](GLFWwindow *window, double xPos, double yPos) {
            RT_CORE_LOG_INFO("Mouse position: {0}, {1}", xPos, yPos);
            // call event callback
            auto wData = static_cast<WindowData *>(glfwGetWindowUserPointer(window));
            if (wData->eventCallback) {
                wData->eventCallback(std::make_shared<ReTooled::MouseMovedEvent>(xPos, yPos));
            }
        });
    }

    GFLWWindow::~GFLWWindow() {
        glfwTerminate();
    }

    void GFLWWindow::update() {
        glfwPollEvents();
    }
}