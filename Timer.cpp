#include "Timer.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

    Timer::Timer()
    {
        lastTime = glfwGetTime();
        nbFrames = 0;
        startingTime();
    }

    double Timer::getDelta()
    {
        return delta;
    }

    void Timer::startingTime()
    {
        auto currentTime = glfwGetTime();
        delta = currentTime - lastTime;
        nbFrames++;

        if (delta >= 1.0)
        {
            // printf and reset timer
            //printf("%f ms/frame\n", 1000.0 / double(nbFrames));
            nbFrames = 0;
            lastTime += 1.0;
        }
    }

