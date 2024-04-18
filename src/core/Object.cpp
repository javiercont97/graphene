#include "Object.h"

void Graphene::Object::setProperty(
	const std::string &name,
	const std::variant<int, float, double, std::string> &value) {
	this->properties[name] = value;
}

bool Graphene::Object::hasProperty(const std::string &name) {
	return properties.find(name) != properties.end();
}

void Graphene::Object::clearProperties() {
	// clear all properties
	properties.clear();
}

void Graphene::Object::removeProperty(const std::string &name) {
	properties.erase(name);
}

std::vector<std::string> Graphene::Object::getPropertyNames() {
	std::vector<std::string> names;
	for (auto &pair : properties) {
		names.push_back(pair.first);
	}
	return names;
}

void Graphene::Object::addEventListener(const std::string &event,
										Object *listener) {
	// add listener to the event
	this->eventListeners[event].push_back(listener);
}

void Graphene::Object::removeEventListener(const std::string &event,
										   Object *listener) {
	if (this->eventListeners.find(event) == this->eventListeners.end()) {
		return;
	}
	auto &listeners = this->eventListeners[event];
	listeners.erase(std::remove(listeners.begin(), listeners.end(), listener),
					listeners.end());
}

void Graphene::Object::dispatchEvent(
	const std::string &event,
	const std::variant<int, float, double, std::string> &message,
	EVENT_PAYLOAD_TYPE type) {
	if (this->eventListeners.find(event) == this->eventListeners.end()) {
		return;
	}

	auto &listeners = this->eventListeners[event];
	for (auto &listener : listeners) {
		listener->notify(event, message, type);
	}
}