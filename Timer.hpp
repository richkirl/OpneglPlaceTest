#ifndef TIMER_HPP
#define TIMER_HPP
#include <chrono>
#include <iostream>
class Timer{
public:
 
    double lastTime;
    int nbFrames=0;
    bool inLoop=false;
    double delta;

    static double ms;

    Timer();
    double getDelta();
   
    void startingTime();
    

};
#endif