#if !defined(GRAPHENE_STRING_H)
#define GRAPHENE_STRING_H

#include <math.h>

#include <cstdarg>
#include <regex>
#include <string>
#include <vector>

namespace Graphene {
class String {
   public:
	/**
	 * @brief Construct a new String object. The string is empty.
	 *
	 */
	String();

	/**
	 * @brief Construct a new String object. The string is initialized with the
	 * C-style string.
	 *
	 * @param str
	 */
	String(const char* str);

	/**
	 * @brief Construct a new String object. The string is initialized with
	 * another string.
	 *
	 * @param str
	 */
	String(const String& str);

	/**
	 * @brief Construct a new String object. The string is initialized with the
	 * std::string.
	 *
	 * @param str
	 */
	String(const std::string& str);

	/**
	 * @brief Assignment operator. The string is assigned with the C-style
	 * string.
	 *
	 * @param str
	 * @return String&
	 */
	String& operator=(const char* str);

	/**
	 * @brief Assignment operator. The string is assigned with another string.
	 *
	 * @param str
	 * @return String&
	 */
	String& operator=(const String& str);

	/**
	 * @brief Assignment operator. The string is assigned with the std::string.
	 *
	 * @param str
	 * @return String&
	 */
	String& operator=(const std::string& str);

	/**
	 * @brief Concatenation operator. The string is concatenated with the
	 * C-style string.
	 *
	 * @param str
	 * @return String
	 */
	String operator+(const char* str) const;

	/**
	 * @brief Concatenation operator. The string is concatenated with another
	 * string.
	 *
	 * @param str
	 * @return String
	 */
	String operator+(const String& str) const;

	/**
	 * @brief Concatenation operator. The string is concatenated with the
	 * std::string.
	 *
	 * @param str
	 * @return String
	 */
	String operator+(const std::string& str) const;

	/**
	 * @brief Concatenation assignment operator. The string is concatenated with
	 * the C-style string.
	 *
	 * @param str
	 * @return String&
	 */
	String& operator+=(const char* str);

	/**
	 * @brief Concatenation assignment operator. The string is concatenated with
	 * another string.
	 *
	 * @param str
	 * @return String&
	 */
	String& operator+=(const String& str);

	/**
	 * @brief Concatenation assignment operator. The string is concatenated with
	 * the std::string.
	 *
	 * @param str
	 * @return String&
	 */
	String& operator+=(const std::string& str);

	/**
	 * @brief Equality operator. The string is compared with the C-style string.
	 *
	 * @param str
	 * @return true
	 * @return false
	 */
	bool operator==(const char* str) const;

	/**
	 * @brief Equality operator. The string is compared with another string.
	 *
	 * @param str
	 * @return true
	 * @return false
	 */
	bool operator==(const String& str) const;

	/**
	 * @brief Equality operator. The string is compared with the std::string.
	 *
	 * @param str
	 * @return true
	 * @return false
	 */
	bool operator==(const std::string& str) const;

	/**
	 * @brief Inequality operator. The string is compared with the C-style
	 * string.
	 *
	 * @param str
	 * @return true
	 * @return false
	 */
	bool operator!=(const char* str) const;

	/**
	 * @brief Inequality operator. The string is compared with another string.
	 *
	 * @param str
	 * @return true
	 * @return false
	 */
	bool operator!=(const String& str) const;

	/**
	 * @brief Inequality operator. The string is compared with the std::string.
	 *
	 * @param str
	 * @return true
	 * @return false
	 */
	bool operator!=(const std::string& str) const;

	/**
	 * @brief Get the C-style string.
	 *
	 * @return const char*
	 */
	const char* cStyleString() const;

	/**
	 * @brief Conversion operator. Get the C-style string. Equivalent to
	 * cStyleString().
	 *
	 * @return const char*
	 */
	operator char*() const;

	/**
	 * @brief Parse the string from the integer.
	 *
	 * @param value
	 * @return String
	 */
	static String fromInt(int value);

	/**
	 * @brief Parse the string from the float.
	 *
	 * @param value
	 * @return String
	 */
	static String fromFloat(float value, int precision = 6);

	/**
	 * @brief Parse the string from the double.
	 *
	 * @param value
	 * @return String
	 */
	static String fromDouble(double value, int precision = 6);

	/**
	 * @brief Parse the string from the boolean.
	 *
	 * @param value
	 * @return String
	 */
	static String fromBool(bool value);

	/**
	 * @brief Format the string using the printf-style format.
	 *
	 * @param format
	 * @param ...
	 * @return String
	 */
	static String asPrintf(const char* format, ...);

	/**
	 * @brief Convert the string to the integer.
	 *
	 * @return int
	 */
	int toInt() const;

	/**
	 * @brief Convert the string to the float.
	 *
	 * @return float
	 */
	float toFloat() const;

	/**
	 * @brief Convert the string to the double.
	 *
	 * @return double
	 */
	double toDouble() const;

	/**
	 * @brief Convert the string to the boolean.
	 *
	 * @return bool
	 */
	bool toBool() const;

	/**
	 * @brief Get the length of the string.
	 *
	 * @return size_t
	 */
	size_t length() const;

	/**
	 * @brief Check if the string is empty.
	 *
	 */
	bool empty() const;

	/**
	 * @brief Substring function. Get the substring from the string.
	 *
	 */
	String subString(size_t pos, size_t len) const;

	/**
	 * @brief Check if string contains the substring.
	 *
	 */
	bool contains(const String& str) const;

	/**
	 * @brief To lower case function.
	 *
	 */
	String toLower() const;

	/**
	 * @brief To upper case function.
	 *
	 */
	String toUpper() const;

	/**
	 * @brief Find the first occurrence of the substring.
	 *
	 */
	size_t find(const String& str) const;

	/**
	 * @brief Find the last occurrence of the substring.
	 *
	 */
	size_t findLast(const String& str) const;

	/**
	 * @brief Replace the substring with another string.
	 *
	 */
	String replace(const String& from, const String& to) const;

	/**
	 * @brief Trim the string.
	 *
	 */
	String trim() const;

	/**
	 * @brief Return character at the specified position.
	 *
	 */
	char operator[](size_t pos) const;

	/**
	 * @brief Reverse the string.
	 *
	 */
	String reverse() const;

	/**
	 * @brief Split the string by the delimiter.
	 *
	 */
	std::vector<String> split(const String& delimiter) const;

	/**
	 * @brief Starts with function. Check if the string starts with the
	 * substring.
	 *
	 */
	bool startsWith(const String& str) const;

	/**
	 * @brief Ends with function. Check if the string ends with the substring.
	 *
	 */
	bool endsWith(const String& str) const;

	/**
	 * @brief Operator <<. Output the string to the output stream.
	 *
	 */
	friend std::ostream& operator<<(std::ostream& os, const String& str) {
		os << str.str;
		return os;
	}

	size_t operator()(const String& str) const {
		return std::hash<std::string>()(str.str);
	}
	// struct StringHash {
	// 	size_t operator()(const String& str) const {
	// 		return std::hash<std::string>()(str.str);
	// 	}
	// };

   private:
	std::string str;
};

}  // namespace Graphene

#endif	// GRAPHENE_STRING_H
