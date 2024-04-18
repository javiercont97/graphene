// #if !defined(GRAPHENE_EVENT_QUEUE_H)
// #define GRAPHENE_EVENT_QUEUE_H

// #include <unordered_map>

// #include "EventConsumer.h"
// #include "String.h"

// namespace Graphene {
// class EventQueue {
//    public:
// 	/**
// 	 * @brief subscribe function
// 	 *
// 	 */
// 	void subscribe(const Graphene::String &topic, EventConsumer *consumer);

// 	/**
// 	 * @brief unsubscribe function
// 	 *
// 	 */
// 	void unsubscribe(const Graphene::String &topic, EventConsumer *consumer);

// 	/**
// 	 * @brief publish function
// 	 *
// 	 */
// 	void publish(const Graphene::String &topic,
// 				 const std::variant<int, float, double, std::string> &message,
// 				 EVENT_PAYLOAD_TYPE type);

//    private:
// 	// List of subscribers
// 	std::unordered_map<Graphene::String, std::vector<EventConsumer *>,
// 					   Graphene::String::StringHash>
// 		m_subscribers;
// };

// }  // namespace Graphene

// #endif	// GRAPHENE_EVENT_QUEUE_H
