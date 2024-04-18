// #include "EventQueue.h"

// void Graphene::EventQueue::subscribe(const Graphene::String& topic,
// 									 EventConsumer* consumer) {
// 	this->m_subscribers[topic].push_back(consumer);
// }

// void Graphene::EventQueue::unsubscribe(const Graphene::String& topic,
// 									   EventConsumer* consumer) {
// 	if (m_subscribers.find(topic) != m_subscribers.end()) {
// 		auto& subscribers = m_subscribers[topic];
// 		subscribers.erase(
// 			std::remove(subscribers.begin(), subscribers.end(), consumer),
// 			subscribers.end());
// 	}
// }

// void Graphene::EventQueue::publish(
// 	const Graphene::String& topic,
// 	const std::variant<int, float, double, std::string>& message,
// 	EVENT_PAYLOAD_TYPE type) {
// 	if (m_subscribers.find(topic) != m_subscribers.end()) {
// 		for (EventConsumer* consumer : m_subscribers[topic]) {
// 			consumer->notify(topic, message, type);
// 		}
// 	}
// }
