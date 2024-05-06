#if !defined(GRAPHENE_OBJECT_H)
#define GRAPHENE_OBJECT_H

#include <stdint.h>

#include <cstdarg>
#include <unordered_map>
#include <variant>

#include "String.h"

namespace Graphene {
enum class EVENT_PAYLOAD_TYPE { INT, FLOAT, DOUBLE, STRING };

class Object {
   public:
	/**
	 * @brief Set the Property object
	 *
	 * @param name
	 * @param value
	 */
	void setProperty(const std::string &name, const std::variant<int, float, double, std::string> &value);

	/**
	 * @brief Get the Property object
	 *
	 * @tparam T
	 * @param name
	 * @return T
	 */
	template <typename T>
	T getProperty(const std::string &name) {
		if (!hasProperty(name)) {
			return T();
		}
		return std::get<T>(properties[name]);
	}

	/**
	 * @brief Check if the property exists
	 *
	 * @param name
	 * @return true
	 * @return false
	 */
	bool hasProperty(const std::string &name);

	/**
	 * @brief clearProperties function
	 *
	 */
	void clearProperties();

	/**
	 * @brief removeProperty function
	 *
	 */
	void removeProperty(const std::string &name);

	/**
	 * @brief getPropertyNames function
	 *
	 */
	std::vector<std::string> getPropertyNames();

	/**
	 * @brief toString function
	 *
	 * @return Graphene::String
	 */
	virtual Graphene::String toString() const {
		return "Object";
	}

	/**
	 * @brief addEventListener function
	 *
	 * @param event
	 * @param listener
	 */
	void addEventListener(const std::string &event, Object *listener);

	/**
	 * @brief removeEventListener function
	 *
	 * @param event
	 * @param listener
	 */
	void removeEventListener(const std::string &event, Object *listener);

	/**
	 * @brief dispatchEvent function
	 *
	 * @param event
	 */
	void dispatchEvent(const std::string &event,
					   const std::variant<int, float, double, std::string> &message,
					   EVENT_PAYLOAD_TYPE type);

	/**
	 * @brief Notify function
	 *
	 */
	virtual void notify(const Graphene::String &topic,
						const std::variant<int, float, double, std::string> &message,
						EVENT_PAYLOAD_TYPE type) = 0;

   protected:
	// Object properties
	std::unordered_map<std::string, std::variant<int, float, double, std::string>> properties;

	// Event listeners
	std::unordered_map<std::string, std::vector<Object *>> eventListeners;
};

}  // namespace Graphene

#endif	// GRAPHENE_OBJECT_H
