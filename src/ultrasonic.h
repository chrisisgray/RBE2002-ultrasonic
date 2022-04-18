#ifndef ULTRASONIC
#define ULTRASONIC

class Ultrasonic {
    private:
        const int trig_pin = 2;
        const int echo_pin = 3;

    public:
        void init(void);
        float readData(void);
        void printData(void);
};

#endif