# Graphene

Graphene is named after a 2D material which is in fact as thin as 1 carbon atom thick, this is because the library is meant to be super-thin and run on most embedded system chips (STM32, ESP, or even Arduino boards).

Graphene is a versatile and powerful RTOS-independent and hardware-independent GFX library designed specifically for embedded devices such as the STM32f769i or ESP32. It provides a comprehensive set of graphical functions and features that enable developers to create stunning user interfaces and visualizations on these platforms.

With Graphene, you can easily create and manipulate various graphical elements, including buttons, sliders, labels, and more. The library offers a wide range of drawing primitives, such as lines, rectangles, circles, and text, allowing you to design visually appealing and interactive interfaces.

One of the key advantages of Graphene is its independence from any specific real-time operating system (RTOS) or hardware platform. This means that you can seamlessly integrate Graphene into your project, regardless of the underlying RTOS or hardware architecture. Whether you are using FreeRTOS, Zephyr, or any other RTOS, or working with STM32f769i, ESP32, or other embedded platforms, Graphene will provide consistent and reliable performance.

To get started with Graphene, simply include the library in your project and start leveraging its powerful features. The library comes with comprehensive documentation and examples to help you quickly understand and utilize its capabilities. Whether you are a beginner or an experienced developer, Graphene will simplify the process of creating visually appealing and responsive user interfaces for your embedded applications.

Start exploring the possibilities of Graphene today and unlock the full potential of your embedded devices!

## Build instructions

Add these build flags to platformio.ini

```ini
build_flags =  
	-std=gnu++2a
	-std=c++2a
build_unflags = 
	-fno-rtti
	-std=gnu++14
```

## Feature flags
Add these macros definition before importing Graphene.h to enable the desired features

This can be done either by CMakeLists.txt file
```cmake
# Enable the image format feature import/export
add_definitions(-DENABLE_GRAPHENE_IMAGE_FORMAT)

# Board+Display specific drivers (display and touch). Use only one at a time
add_definitions(-DENABLE_STM32F769I_DRIVERS)
add_definitions(-DENABLE_NODEMCU_DRIVERS)
```

Or platformio.ini file

```ini
build_flags =  
	-D ENABLE_GRAPHENE_IMAGE_FORMAT
	-D ENABLE_STM32F769I_DRIVERS
	-D ENABLE_NODEMCU_DRIVERS
```

-----
Note: For other platforms you might need to implement touch drivers and display drivers. See current implementations bundled in the library as an starting point

## Docs
Visit the [wiki](https://github.com/javiercont97/graphene/wiki) to read Graphene Docs!