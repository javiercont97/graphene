#include "Object.h"

void Graphene::Object::setProperty(
	const std::string &name,
	const std::variant<int, float, double, std::string> &value) {
	this->m_properties[name] = value;
}

bool Graphene::Object::hasProperty(const std::string &name) {
	return m_properties.find(name) != m_properties.end();
}

void Graphene::Object::clearProperties() {
	// clear all properties
	m_properties.clear();
}

void Graphene::Object::removeProperty(const std::string &name) {
	m_properties.erase(name);
}

std::vector<std::string> Graphene::Object::getPropertyNames() {
	std::vector<std::string> names;
	for (auto &pair : m_properties) {
		names.push_back(pair.first);
	}
	return names;
}

// void Graphene::Object::notify(
// 	const Graphene::String &topic,
// 	const std::variant<int, float, double, std::string> &message,
// 	EVENT_PAYLOAD_TYPE type) {
// 	// Do nothing, override this function in derived classes
// }

// void Graphene::Object::subscribe(const Graphene::String &topic) {
// 	this->m_eventQueue.subscribe(topic, this);
// }

// void Graphene::Object::unsubscribe(const Graphene::String &topic) {
// 	this->m_eventQueue.unsubscribe(topic, this);
// }

// void Graphene::Object::publish(
// 	const Graphene::String &topic,
// 	const std::variant<int, float, double, std::string> &message,
// 	EVENT_PAYLOAD_TYPE type) {
// 	this->m_eventQueue.publish(topic, message, type);
// }
