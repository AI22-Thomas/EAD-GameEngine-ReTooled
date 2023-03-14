#ifndef RETOOLED_EVENT_HPP
#define RETOOLED_EVENT_HPP

namespace ReTooled {
    enum class EventType {
        None = 0,
        Game, Input, Keyboard, Mouse, MouseButton
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

    class KeyboardEvent: public Event {
    public:
        KeyboardEvent(int key) : Event(EventType::Keyboard), m_key(key) {}

        int getKey() const {
            return m_key;
        }

    private:
        int m_key;
    };
}

#endif //RETOOLED_EVENT_HPP
