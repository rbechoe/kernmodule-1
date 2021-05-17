#pragma once

class Ship 
{
    public:
        Ship(int initialLoad);
        int getLoad() const;
        void addLoad(int loadToAdd);

        Ship operator+(const int& loadToAdd) const;
        Ship& operator+=(const int& loadToAdd);

    private:
        int load;
};

Ship operator+(const Ship& lhs, const int& rhs);
Ship operator+(const int& lhs, const Ship& rhs);