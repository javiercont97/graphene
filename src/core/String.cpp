#include "String.h"

Graphene::String::String() {
	// Initialize an empty string
	this->str = std::string();
}

Graphene::String::String(const char* str) {
	// Initialize a string with a C-style string
	this->str = str;
}

Graphene::String::String(const String& str) {
	// Initialize a string with another string
	this->str = str.str;
}

Graphene::String::String(const std::string& str) {
	// Initialize a string with a std::string
	this->str = str;
}

Graphene::String& Graphene::String::operator=(const char* str) {
	this->str = str;
	return *this;
}

Graphene::String& Graphene::String::operator=(const Graphene::String& str) {
	this->str = str.str;
	return *this;
}

Graphene::String& Graphene::String::operator=(const std::string& str) {
	this->str = str;
	return *this;
}

Graphene::String Graphene::String::operator+(const char* str) const {
	Graphene::String result = *this;
	result.str += str;
	return result;
}

Graphene::String Graphene::String::operator+(const Graphene::String& str) const {
	Graphene::String result = *this;
	result.str += str.str;
	return result;
}

Graphene::String Graphene::String::operator+(const std::string& str) const {
	Graphene::String result = *this;
	result.str += str;
	return result;
}

Graphene::String& Graphene::String::operator+=(const char* str) {
	this->str += str;
	return *this;
}

Graphene::String& Graphene::String::operator+=(const Graphene::String& str) {
	this->str += str.str;
	return *this;
}

Graphene::String& Graphene::String::operator+=(const std::string& str) {
	this->str += str;
	return *this;
}

bool Graphene::String::operator==(const char* str) const {
	return this->str == str;
}

bool Graphene::String::operator==(const Graphene::String& str) const {
	return this->str == str.str;
}

bool Graphene::String::operator==(const std::string& str) const {
	return this->str == str;
}

bool Graphene::String::operator!=(const char* str) const {
	return this->str != str;
}

bool Graphene::String::operator!=(const Graphene::String& str) const {
	return this->str != str.str;
}

bool Graphene::String::operator!=(const std::string& str) const {
	return this->str != str;
}

const char* Graphene::String::cStyleString() const {
	// Return the C-style string
	return this->str.c_str();
}

Graphene::String Graphene::String::fromInt(int value) {
	// Convert an integer to a string
	return std::to_string(value);
}

Graphene::String Graphene::String::fromFloat(float value, int precision) {
	// Convert a float to a string with a specified precision (default 6)
	std::string format = "%." + std::to_string(precision) + "f";
	return Graphene::String::asPrintf(format.c_str(), value);
}

Graphene::String Graphene::String::fromDouble(double value, int precision) {
	// Convert a double to a string with a specified precision (default 6)
	std::string format = "%." + std::to_string(precision) + "f";
	return Graphene::String::asPrintf(format.c_str(), value);
}

Graphene::String Graphene::String::fromBool(bool value) {
	// Convert a boolean to a string
	return value ? "true" : "false";
}

Graphene::String Graphene::String::asPrintf(const char* format, ...) {
	// Format a string using printf-style formatting
	va_list args;
	va_start(args, format);
	char buffer[1024];
	vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);
	return buffer;
}

int Graphene::String::toInt() const {
	// if string contains a dot. Convert to integer and return
	if (this->str.find('.') != std::string::npos) {
		return (int)std::round(this->toFloat());
	}

	// return 0 if the string is empty or not a number
	if (this->str.empty() || !std::all_of(this->str.begin(), this->str.end(), ::isdigit)) {
		return 0;
	}

	// Convert the string to an integer
	return std::stoi(this->str);
}

float Graphene::String::toFloat() const {
	std::regex pattern(R"(-?\d+(\.\d+)?([eE][+-]?\d+)?)");

	// return 0 if the string is empty or not a float number
	if (this->str.empty() || !std::regex_match(this->str, pattern)) {
		return 0;
	}

	// Convert the string to a float
	return std::stof(this->str);
}

double Graphene::String::toDouble() const {
	std::regex pattern(R"(-?\d+(\.\d+)?([eE][+-]?\d+)?)");

	// return 0 if the string is empty or not a number
	if (this->str.empty() || !std::regex_match(this->str, pattern)) {
		return 0;
	}

	// Convert the string to a double
	return std::stod(this->str);
}

bool Graphene::String::toBool() const {
	// Convert the string to a boolean
	return this->str == "true";
}

size_t Graphene::String::length() const {
	// Get the length of the string
	return this->str.length();
}

bool Graphene::String::empty() const {
	// Check if the string is empty
	return this->str.empty();
}

Graphene::String Graphene::String::subString(size_t pos, size_t len) const {
	return this->str.substr(pos, len);
}

bool Graphene::String::contains(const String& str) const {
	return this->str.find(str.str) != std::string::npos;
}

Graphene::String Graphene::String::toLower() const {
	// Convert the string to lower case
	std::string lower = this->str;
	std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
	return lower;
}

Graphene::String Graphene::String::toUpper() const {
	// Convert the string to upper case
	std::string upper = this->str;
	std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
	return upper;
}

size_t Graphene::String::find(const String& str) const {
	return this->str.find(str.str);
}

size_t Graphene::String::findLast(const String& str) const {
	return this->str.rfind(str.str);
}

Graphene::String Graphene::String::replace(const String& from, const String& to) const {
	std::string result = this->str;
	size_t start_pos = 0;
	while ((start_pos = result.find(from.str, start_pos)) != std::string::npos) {
		result.replace(start_pos, from.str.length(), to.str);
		start_pos += to.str.length();
	}
	return result;
}

Graphene::String Graphene::String::trim() const {
	std::string result = this->str;
	result.erase(0, result.find_first_not_of(" \t\n\r\f\v"));
	result.erase(result.find_last_not_of(" \t\n\r\f\v") + 1);
	return result;
}

char Graphene::String::operator[](size_t pos) const {
	// If the position is out of range, return null character
	if (pos >= this->length()) {
		return '\0';
	}
	return this->str[pos];
}

Graphene::String Graphene::String::reverse() const {
	std::string reversed = this->str;
	std::reverse(reversed.begin(), reversed.end());
	return reversed;
}

std::vector<Graphene::String> Graphene::String::split(const String& delimiter) const {
	std::vector<Graphene::String> result;
	std::string str = this->str;
	size_t pos = 0;
	std::string token;
	while ((pos = str.find(delimiter.str)) != std::string::npos) {
		token = str.substr(0, pos);
		result.push_back(token);
		str.erase(0, pos + delimiter.length());
	}
	result.push_back(str);
	return result;
}

bool Graphene::String::startsWith(const String& str) const {
	return this->find(str.str) == 0;
}

bool Graphene::String::endsWith(const String& str) const {
	return this->findLast(str.str) == this->length() - str.length();
}
