#ifndef RETOOLED_EVENT_HPP
#define RETOOLED_EVENT_HPP

#include "eventpp/eventqueue.h"

namespace ReTooled {
    enum class EventType {
        None = 0,
        Game, Input, Keyboard, Mouse, MouseButton
    };

    class Event {
    public:
        explicit Event(const EventType eType) : type(eType) {

        }

        virtual ~Event() = default;

        EventType getType() const {
            return type;
        }

    private:
        EventType type;
    };

    struct EventPolicy {
        static EventType getEvent(const Event &event) {
            return event.getType();
        }
    };

    using QueueType = eventpp::EventQueue<EventType, void(const Event &), EventPolicy>;
    using ListenerType = void(const Event &);

    class KeyboardEvent: public Event {
    public:
        KeyboardEvent(int key) : Event(EventType::Keyboard), key(key) {}

        int getKey() const {
            return key;
        }

    private:
        int key;
    };
}

#endif //RETOOLED_EVENT_HPP
