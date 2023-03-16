#ifndef RETOOLED_EVENT_HPP
#define RETOOLED_EVENT_HPP

namespace ReTooled {
    enum class EventType {
        None = 0,
        Game, WindowResize, WindowClose, KeyPressed, KeyReleased, MouseButtonPressedEvent, MouseButtonReleasedEvent,
        MouseMovedEvent, MouseScrolledEvent
    };

    class Event {
    public:
        explicit Event(const EventType eType) : m_type(eType) {

        }

        virtual ~Event() = default;

        EventType getType() const {
            return m_type;
        }

    private:
        EventType m_type;
    };

    using EventPointer = std::shared_ptr<Event>;

    struct EventPolicy {
        static EventType getEvent(const EventPointer &event) {
            return event->getType();
        }
    };

    using ListenerType = void(const EventPointer &);
    using QueueType = eventpp::EventQueue<EventType, ListenerType, EventPolicy>;


// Event types:
    class WindowResizeEvent : public Event {
    public:
        WindowResizeEvent(int width, int height) : Event(EventType::WindowResize), m_width(width), m_height(height) {}

        int getWidth() const {
            return m_width;
        }

        int getHeight() const {
            return m_height;
        }

    private:
        int m_width, m_height;
    };

    class WindowCloseEvent : public Event {
    public:
        WindowCloseEvent() : Event(EventType::WindowClose) {}
    };

    class KeyPressedEvent : public Event {
    public:
        KeyPressedEvent(int key, int repeat) : Event(EventType::KeyPressed), m_key(key), m_repeat(repeat) {}

        int getKey() const {
            return m_key;
        }

        int getRepeat() const {
            return m_repeat;
        }

    private:
        int m_key, m_repeat;

    };

    class KeyReleasedEvent : public Event {
    public:
        KeyReleasedEvent(int key) : Event(EventType::KeyReleased), m_key(key) {}

        int getKey() const {
            return m_key;
        }

    private:
        int m_key;
    };

    class MouseButtonPressedEvent : public Event {
    public:
        MouseButtonPressedEvent(int button) : Event(EventType::MouseButtonPressedEvent), m_button(button) {}

        int getButton() const {
            return m_button;
        }

    private:
        int m_button;
    };

    class MouseButtonReleasedEvent : public Event {
    public:
        MouseButtonReleasedEvent(int button) : Event(EventType::MouseButtonReleasedEvent), m_button(button) {}

        int getButton() const {
            return m_button;
        }

    private:
        int m_button;
    };

    class MouseMovedEvent : public Event {
    public:
        MouseMovedEvent(double x, double y) : Event(EventType::MouseMovedEvent), m_x(x), m_y(y) {}

        double getX() const {
            return m_x;
        }

        double getY() const {
            return m_y;
        }

    private:
        double m_x, m_y;
    };

    class MouseScrolledEvent : public Event {
    public:
        MouseScrolledEvent(double xOffset, double yOffset) : Event(EventType::MouseScrolledEvent), m_xOffset(xOffset),
                                                             m_yOffset(yOffset) {}

        double getXOffset() const {
            return m_xOffset;
        }

        double getYOffset() const {
            return m_yOffset;
        }

    private:
        double m_xOffset, m_yOffset;
    };
}

#endif //RETOOLED_EVENT_HPP
