# Graphene

Graphene is a versatile and powerful RTOS-independent and hardware-independent GFX library designed specifically for embedded devices such as the STM32f769i or ESP32. It provides a comprehensive set of graphical functions and features that enable developers to create stunning user interfaces and visualizations on these platforms.

With Graphene, you can easily create and manipulate various graphical elements, including buttons, sliders, graphs, and more. The library offers a wide range of drawing primitives, such as lines, rectangles, circles, and text, allowing you to design visually appealing and interactive interfaces.

One of the key advantages of Graphene is its independence from any specific real-time operating system (RTOS) or hardware platform. This means that you can seamlessly integrate Graphene into your project, regardless of the underlying RTOS or hardware architecture. Whether you are using FreeRTOS, Zephyr, or any other RTOS, or working with STM32f769i, ESP32, or other embedded platforms, Graphene will provide consistent and reliable performance.

To get started with Graphene, simply include the library in your project and start leveraging its powerful features. The library comes with comprehensive documentation and examples to help you quickly understand and utilize its capabilities. Whether you are a beginner or an experienced developer, Graphene will simplify the process of creating visually appealing and responsive user interfaces for your embedded applications.

Start exploring the possibilities of Graphene today and unlock the full potential of your embedded devices!

## Top level design

The top level design of Graphene is based on a modular and extensible architecture. It follows a component-based approach, where each graphical element is represented as a separate component. This allows for easy customization and reusability of components across different projects.

At the core of Graphene's design is the Graphics Engine, which handles the rendering and manipulation of graphical elements. The Graphics Engine provides a set of APIs that developers can use to create, update, and interact with components.

In addition to the Graphics Engine, Graphene also includes a Theme Engine, which allows for easy customization of the visual appearance of components. Developers can define their own themes or choose from a set of pre-defined themes to achieve the desired look and feel.

To ensure optimal performance and resource utilization, Graphene employs various optimization techniques. It leverages hardware acceleration capabilities whenever available, and implements efficient algorithms for rendering and event handling.

The top level design of Graphene promotes code reusability and maintainability. It encourages the separation of concerns, with clear separation between the graphical presentation layer and the underlying business logic. This allows for easier testing, debugging, and maintenance of the codebase.

Overall, the top level design of Graphene provides a solid foundation for building visually appealing and responsive user interfaces on embedded devices. It offers flexibility, extensibility, and performance, making it a powerful choice for developers working on embedded applications.

## Requirements

The following is a list of requirements attached to user stories:

 1. [ ] As a user, I want to be able to draw lines, rectangles, circles, and text on the screen.
 2. [ ] As a user, I want to be able to create buttons with customizable labels and styles.
 3. [ ] As a user, I want to be able to create sliders with adjustable values and visual indicators.
 4. [ ] As a user, I want to be able to create graphs to visualize data in real-time.
 5. [ ] As a user, I want the library to separate the graphical presentation layer from the underlying business logic.
 6. [ ] As a user, I want to be able to customize the visual appearance of components using themes.
 7. [ ] As a user, I want the library to be compatible with different RTOSs and hardware platforms.
 8. [ ] As a user, I want the library to provide consistent and reliable performance.
 9. [ ] As a user, I want the library to be well-documented with examples to facilitate learning and usage.
10. [ ] As a user, I want the library to promote code reusability and maintainability.
11. [ ] As a user, I want the library to leverage hardware acceleration capabilities whenever available.
12. [ ] As a user, I want the library to implement efficient algorithms for rendering and event handling.
13. [ ] As a user, I want the library to be flexible and extensible for future enhancements and customizations.
14. [ ] As a user, I want the library to provide optimal performance and resource utilization.

These requirements will guide the development of Graphene and ensure that it meets the needs and expectations of its users.


## Build instructions

Use these build flags

```ini
build_flags = 
	-std=gnu++2a
	-std=c++2a
build_unflags = 
	-fno-rtti
	-std=gnu++14
```