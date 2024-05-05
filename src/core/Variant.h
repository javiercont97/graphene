#if !defined(GRAPHENE_VARIANT_H)
#define GRAPHENE_VARIANT_H

#include <stdint.h>

#include <string>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <variant>
#include <vector>

namespace Graphene {
using Data = std::variant<bool,
						  int,
						  float,
						  double,
						  std::string,
						  std::vector<int>,
						  std::vector<float>,
						  std::vector<double>,
						  std::vector<std::string>>;

template <typename T>
struct Types : std::disjunction<std::is_same<T, bool>,
								std::is_same<T, int>,
								std::is_same<T, float>,
								std::is_same<T, double>,
								std::is_same<T, std::string>,

								std::is_same<T, std::vector<int>>,
								std::is_same<T, std::vector<float>>,
								std::is_same<T, std::vector<double>>,
								std::is_same<T, std::vector<std::string>>> {};

class Variant {
   public:
	/**
	 * @brief Construct a new Variant object
	 *
	 */
	Variant() {
		data = 0;
	}

	/**
	 * @brief Construct a new Variant object
	 *
	 */
	Variant(const Data &value) {
		data = value;
	}

	/**
	 * @brief Construct a new Variant object
	 *
	 */
	Variant(const char *value) {
		data = std::string(value);
	}

	/**
	 * @brief Copy constructor
	 *
	 */
	Variant(const Variant &other) {
		data = other.data;
	}

	/**
	 * @brief Construct a new Variant object
	 * using the assignment operator
	 *
	 * For example:
	 * Graphene::Variant v = 42;
	 * Graphene::Variant v2 = 3.14f;
	 * Graphene::Variant v3 = true;
	 * Graphene::Variant v4 = std::string("Hello, World!");
	 * Graphene::Variant v5 = "Hello, World!";
	 *
	 */
	template <typename T, typename = std::enable_if_t<Types<T>::value>>
	Variant(T value) {
		data = value;
	}

	/**
	 * @brief Assignment operator for char*
	 *
	 */
	Variant &operator=(const char *value) {
		data = std::string(value);
		return *this;
	}

	/**
	 * @brief To int
	 *
	 */
	int toInt() {
		return std::get<int>(data);
	}

	/**
	 * @brief To float
	 *
	 */
	float toFloat() {
		return std::get<float>(data);
	}

	/**
	 * @brief To double
	 *
	 */
	double toDouble() {
		return std::get<double>(data);
	}

	/**
	 * @brief To string
	 *
	 */
	std::string toString() {
		return std::get<std::string>(data);
	}

	/**
	 * @brief To bool
	 *
	 */
	bool toBool() {
		return std::get<bool>(data);
	}

	/**
	 * @brief To vector of ints
	 *
	 */
	std::vector<int> toIntVector() {
		return std::get<std::vector<int>>(data);
	}

	/**
	 * @brief To vector of floats
	 *
	 */
	std::vector<float> toFloatVector() {
		return std::get<std::vector<float>>(data);
	}

	/**
	 * @brief To vector of doubles
	 *
	 */
	std::vector<double> toDoubleVector() {
		return std::get<std::vector<double>>(data);
	}

	/**
	 * @brief To vector of strings
	 *
	 */
	std::vector<std::string> toStringVector() {
		return std::get<std::vector<std::string>>(data);
	}

   private:
	Data data;
};

}  // namespace Graphene

#endif	// GRAPHENE_VARIANT_H
