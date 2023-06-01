#pragma once

class Rect;

class Polar {
  private:
   float theta;
   float mag;

  public:
   Polar();
   Polar(float, float);
   Polar operator+(const Polar&) const;
   Polar operator+(const Rect&) const;
   float getTheta() const;
   float getMag() const;
   void print() const;
};
