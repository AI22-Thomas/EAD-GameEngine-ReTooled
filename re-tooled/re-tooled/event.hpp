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
        KeyboardEvent(int key) : Event(EventType::Keyboard), key(key) {}

        int getKey() const {
            return key;
        }

    private:
        int key;
    };
}

#endif //RETOOLED_EVENT_HPP
