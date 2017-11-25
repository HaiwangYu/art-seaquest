#ifndef SQ_DataProducts_Event_h
#define SQ_DataProducts_Event_h

//
// Some event summary statistics.  Very incomplete.
//

#include <iosfwd>

namespace seaquest {

  class Event {

  public:

    Event();

#ifndef __GCCXML__
#endif  // __GCCXML__
  	int get_event_id() const {return _event_id;}
  	void set_event_id(const int a) {_event_id = a;}

  private:
    int _event_id;
  };

#ifndef __GCCXML__
  std::ostream& operator<<(std::ostream& ost,
                           const seaquest::Event& event );
#endif  // __GCCXML__

}
#endif  /* SQ_DataProducts_Event_h */
