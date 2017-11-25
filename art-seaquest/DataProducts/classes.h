//
// Build a dictionary.
//

#include "art-seaquest/DataProducts/Event.h"
#include "art-seaquest/DataProducts/HitCollection.h"

#include "art/Persistency/Common/Wrapper.h"

template class art::Wrapper<seaquest::Event>;
template class art::Wrapper<seaquest::HitCollection>;
