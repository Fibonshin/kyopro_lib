#include "../header.cpp"

//複数modでの計算
const int p1=1000000349;
const int p2=1000000103;
struct mints {
  int d1, d2;
  mints(int val=0): d1(val), d2(val) {}
  mints(int d1, int d2): d1(d1), d2(d2) {}
  mints operator+(const mints& a) const {
    return mints((d1+a.d1)%p1, (d2+a.d2)%p2);
  }
  mints operator*(const mints& a) const {
    return mints(((ll)d1*a.d1)%p1, ((ll)d2*a.d2)%p2);
  }
  bool operator==(const mints& a) const {
    return d1 == a.d1 && d2 == a.d2;
  }
};

