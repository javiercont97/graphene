#include <Graphene.h>
#include <unity/unity.h>

class ConcreteObject : public Graphene::Object {
   public:
	void notify(const Graphene::String &topic,
				const std::variant<int, float, double, std::string> &message,
				Graphene::EVENT_PAYLOAD_TYPE type) {
		this->setProperty(topic.cStyleString(), message);

		// propagate the event to other listeners
		this->dispatchEvent("notify", message, type);
	}
};

void testSetProperty() {
	ConcreteObject obj;
	obj.setProperty("name", "John Doe");
	obj.setProperty("age", 25);

	TEST_ASSERT_TRUE(obj.hasProperty("name"));
	TEST_ASSERT_TRUE(obj.hasProperty("age"));

	// NEGATIVE TEST
	TEST_ASSERT_FALSE(obj.hasProperty("address"));
}

void testGetProperty() {
	ConcreteObject obj;
	obj.setProperty("name", "John Doe");
	obj.setProperty("age", 25);

	TEST_ASSERT_EQUAL_STRING("John Doe", obj.getProperty<std::string>("name").c_str());
	TEST_ASSERT_EQUAL_INT(25, obj.getProperty<int>("age"));

	// NEGATIVE TEST
	TEST_ASSERT_EQUAL_INT(0, obj.getProperty<int>("address"));
	TEST_ASSERT_EQUAL_STRING("", obj.getProperty<std::string>("address").c_str());
}

void testHasProperty() {
	ConcreteObject obj;
	obj.setProperty("name", "John Doe");
	obj.setProperty("age", 25);

	TEST_ASSERT_TRUE(obj.hasProperty("name"));
	TEST_ASSERT_TRUE(obj.hasProperty("age"));

	// NEGATIVE TEST
	TEST_ASSERT_FALSE(obj.hasProperty("address"));
}

void testRemoveProperty() {
	ConcreteObject obj;
	obj.setProperty("name", "John Doe");
	obj.setProperty("age", 25);

	TEST_ASSERT_TRUE(obj.hasProperty("name"));
	TEST_ASSERT_TRUE(obj.hasProperty("age"));

	obj.removeProperty("name");
	obj.removeProperty("age");

	TEST_ASSERT_FALSE(obj.hasProperty("name"));
	TEST_ASSERT_FALSE(obj.hasProperty("age"));
}

void testClearProperties() {
	ConcreteObject obj;
	obj.setProperty("name", "John Doe");
	obj.setProperty("age", 25);

	TEST_ASSERT_TRUE(obj.hasProperty("name"));
	TEST_ASSERT_TRUE(obj.hasProperty("age"));

	obj.clearProperties();

	TEST_ASSERT_FALSE(obj.hasProperty("name"));
	TEST_ASSERT_FALSE(obj.hasProperty("age"));
}

void testGetPropertyNames() {
	ConcreteObject obj;
	obj.setProperty("name", "John Doe");
	obj.setProperty("age", 25);

	std::vector<std::string> names = obj.getPropertyNames();

	TEST_ASSERT_EQUAL_STRING("age", names[0].c_str());
	TEST_ASSERT_EQUAL_STRING("name", names[1].c_str());
}

void testPublish() {
	ConcreteObject obj;
	ConcreteObject obj2;
	ConcreteObject obj3;

	obj.addEventListener("topic1", &obj2);
	obj.addEventListener("topic2", &obj2);
	obj.addEventListener("topic3", &obj2);
	obj.addEventListener("topic4", &obj2);

	obj2.addEventListener("notify", &obj3);

	TEST_ASSERT_FALSE(obj3.hasProperty("notify"));

	obj.dispatchEvent("topic1", 42, Graphene::EVENT_PAYLOAD_TYPE::INT);

	TEST_ASSERT_TRUE(obj3.hasProperty("notify"));
	TEST_ASSERT_EQUAL_INT(42, obj3.getProperty<int>("notify"));

	obj.dispatchEvent("topic2", 3.14f, Graphene::EVENT_PAYLOAD_TYPE::FLOAT);

	TEST_ASSERT_TRUE(obj3.hasProperty("notify"));
	TEST_ASSERT_EQUAL_FLOAT(3.14f, obj3.getProperty<float>("notify"));

	obj2.removeEventListener("notify", &obj3);

	obj.dispatchEvent("topic3", 3.141592, Graphene::EVENT_PAYLOAD_TYPE::DOUBLE);

	TEST_ASSERT_TRUE(obj3.hasProperty("notify"));
	TEST_ASSERT_EQUAL_FLOAT(3.14f, obj3.getProperty<float>("notify"));

	obj.dispatchEvent("topic4", "Hello", Graphene::EVENT_PAYLOAD_TYPE::STRING);

	TEST_ASSERT_TRUE(obj2.hasProperty("topic1"));
	TEST_ASSERT_TRUE(obj2.hasProperty("topic2"));
	TEST_ASSERT_TRUE(obj2.hasProperty("topic3"));
	TEST_ASSERT_TRUE(obj2.hasProperty("topic4"));

	TEST_ASSERT_EQUAL_INT(42, obj2.getProperty<int>("topic1"));
	TEST_ASSERT_EQUAL_FLOAT(3.14f, obj2.getProperty<float>("topic2"));
	// TEST_ASSERT_EQUAL_DOUBLE(3.141592, obj2.getProperty<double>("topic3"));
	TEST_ASSERT_EQUAL_STRING("Hello", obj2.getProperty<std::string>("topic4").c_str());

	//  +==================================================+
	//  | source    |  event   |  listener  |  property    |
	//  +==================================================+
	//  | obj       | topic1   |  obj2      |  topic1=42   |
	//  | obj       | topic2   |  obj2      |  topic2=3.14 |
	//  | obj       | topic3   |  obj2      |  topic3=3.14 |
	//  | obj       | topic4   |  obj2      |  topic4=Hello|
	//  | obj2      | notify   |  obj3      |  notify=42   |
	//  +==================================================+
}

void testCircularPublish() {
	ConcreteObject obj;
	ConcreteObject obj2;
	ConcreteObject obj3;

	obj.addEventListener("topic1", &obj2);
	obj2.addEventListener("notify", &obj3);
	obj3.addEventListener("notify", &obj);

	obj.dispatchEvent("topic1", 42, Graphene::EVENT_PAYLOAD_TYPE::INT);

	TEST_ASSERT_TRUE(obj2.hasProperty("topic1"));
	TEST_ASSERT_TRUE(obj3.hasProperty("notify"));
	TEST_ASSERT_TRUE(obj.hasProperty("notify"));

	TEST_ASSERT_EQUAL_INT(42, obj.getProperty<int>("notify"));
	TEST_ASSERT_EQUAL_INT(42, obj2.getProperty<int>("topic1"));
	TEST_ASSERT_EQUAL_INT(42, obj3.getProperty<int>("notify"));

	//  +==================================================+
	//  | source    |  event   |  listener  |  property    |
	//  +==================================================+
	//  | obj       | topic1   |  obj2      |  topic1=42   |
	//  | obj2      | notify   |  obj3      |  notify=42   |
	//  | obj3      | notify   |  obj       |  notify=42   |
	//  +==================================================+

	// It is a circular event propagation. The event is propagated from obj to
	// obj2, then to obj3, and finally back to obj. The property "notify" is
	// set to 42 in all objects.

	// If the event propagation is not stopped, it will cause an infinite loop.
	// For example, obj2 is listening to the "notify" event from obj then
	// the event is propagated from obj to obj2, then to obj3,
	// and back to obj, the event will be propagated again to obj2, then to
	// obj3, and back to obj, and so on. This is caused by the
	// this->dispatchEvent("notify", message, type); in the
	// ConcreteObject::notify function.
	// To prevent this, the event propagation should be stopped when the event
	// is propagated back to the source object.
	// Be careful when using the event propagation mechanism to avoid infinite
	// loops.
	// BE CAREFUL! Risk of stack overflow!
}