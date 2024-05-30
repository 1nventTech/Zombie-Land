#ifndef AXIS_H
#define AXIS_H

class Axis {
    public:
        int x;
        int y;
        Axis(float x = 0, float y = 0);  // Constructor declaration
        void update(float x = 0, float y = 0);  // Method declaration
        virtual ~Axis();  // Destructor declaration
};

#endif // AXIS_H
