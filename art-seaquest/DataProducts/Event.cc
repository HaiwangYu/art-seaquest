//
// Some statistics about an event. Not very complete ...
//

#include "Event.h"

#include <ostream>

tex::Event::Event():
  nPositive_(0),
  nNegative_(0){
}

#ifndef __GCCXML__

void tex::Event::increment( int q){
  if ( q > 0 ){
    ++nPositive_;
  } else{
    ++nNegative_;
  }
}

std::ostream& tex::operator<<(std::ostream& ost,
                         const tex::Event& summary){
  ost << "( Event Summary: Tracks: Postive: "
      << summary.nPositive()
      << " Negative: "
      << summary.nNegative()
      << ")";

  return ost;
}

#endif // __GCCXML__
