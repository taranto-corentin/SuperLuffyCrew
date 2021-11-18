#ifndef POSITION_H
#define POSITION_H


class Position
{
    private:
        float x;
        float y;

    public:
        Position(float x=0.f, float y=0.f);
        virtual ~Position();
        Position(const Position& other);
        Position& operator=(const Position& other);

        //Methods
        void changePosition(const float x, const float y);
        const float getX() const;
        const float getY() const;
};

#endif // POSITION_H
