// #if !defined(GRAPHENE_EVENT_CONSUMER_H)
// #define GRAPHENE_EVENT_CONSUMER_H

// #include <variant>

// #include "String.h"

// namespace Graphene {
// enum class EVENT_PAYLOAD_TYPE { INT, FLOAT, DOUBLE, STRING };

// class EventConsumer {
//    public:
// 	virtual void notify(
// 		const Graphene::String &topic,
// 		const std::variant<int, float, double, std::string> &message,
// 		EVENT_PAYLOAD_TYPE type) = 0;

// 	virtual void subscribe(const String &topic) = 0;
// 	virtual void unsubscribe(const String &topic) = 0;
// };

// }  // namespace Graphene

// #endif	// GRAPHENE_EVENT_CONSUMER_H
