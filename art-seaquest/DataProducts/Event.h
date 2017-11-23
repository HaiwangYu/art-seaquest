#ifndef DataProducts_Event_h
#define DataProducts_Event_h

//
// Some event summary statistics.  Very incomplete.
//

#include <iosfwd>

namespace tex {

  class Event {

  public:

    Event();

#ifndef __GCCXML__

    int nTracks()   const { return nPositive_ + nNegative_; }
    int nPositive() const { return nPositive_; }
    int nNegative() const { return nNegative_; }

    void increment( int q);

#endif  // __GCCXML__

  private:
    int nPositive_;
    int nNegative_;
  };

#ifndef __GCCXML__
  std::ostream& operator<<(std::ostream& ost,
                           const tex::Event& summary );
#endif  // __GCCXML__

}
#endif  /* DataProducts_Event_h */
