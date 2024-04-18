#if !defined(GRAPHENE_OBJECT_H)
#define GRAPHENE_OBJECT_H

#include <stdint.h>

#include <unordered_map>
#include <variant>

// #include "EventConsumer.h"
// #include "EventQueue.h"
#include "String.h"

namespace Graphene {
// class Object : public EventConsumer {
class Object {
   public:
	/**
	 * @brief Set the Property object
	 *
	 * @param name
	 * @param value
	 */
	void setProperty(
		const std::string &name,
		const std::variant<int, float, double, std::string> &value);

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
		return std::get<T>(m_properties[name]);
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
	virtual Graphene::String toString() const { return "Object"; }

   protected:
	// Object properties
	std::unordered_map<std::string,
					   std::variant<int, float, double, std::string>>
		m_properties;

	// Event queue
	// EventQueue &m_eventQueue;
};

}  // namespace Graphene

#endif	// GRAPHENE_OBJECT_H
