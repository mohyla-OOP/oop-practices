// All operators are class member functions
// Replace member functions with utilities
class WrappedVector
{
private:
   static const size_t _n;
   double* _v;
   void fill();

public:

   WrappedVector();
   WrappedVector(const WrappedVector&);
   WrappedVector& operator=(const WrappedVector&);
   ~WrappedVector();


   double size() const {return _n;}
   bool operator==(const WrappedVector&) const;
   bool operator!=(const WrappedVector&) const;
   double operator*(const WrappedVector&) const;
   const WrappedVector operator*(double) const;
   const WrappedVector operator+
      (const WrappedVector&) const;
   ostream& show(ostream& os) const;
};

ostream& operator<<(ostream& os, const WrappedVector& u);

// double operator*(double, const WrappedVector&);
