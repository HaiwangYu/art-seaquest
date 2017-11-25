//
// Create the Event TestProducer data product.
//

#include "art-seaquest/DataProducts/Event.h"

#include "art/Framework/Core/EDProducer.h"
#include "art/Framework/Core/ModuleMacros.h"
#include "art/Framework/Principal/Event.h"

#include <iostream>
#include <vector>
#include <memory>

namespace seaquest {

  class TestProducer : public art::EDProducer {

  public:

    explicit TestProducer(fhicl::ParameterSet const& pset);

    void produce( art::Event& event) override;

  private:

    art::InputTag fitsTag_;

  };

}

seaquest::TestProducer::TestProducer(fhicl::ParameterSet const& pset ):
  fitsTag_(pset.get<std::string>("fitsTag")){

  produces<seaquest::Event>();
}

void seaquest::TestProducer::produce( art::Event& event){

  // Create empty output data produc.
  auto event_out = std::make_unique<seaquest::Event>();

  std::cout << event.id() << " " << *event_out << std::endl;

  event.put( std::move(event_out) );

}

DEFINE_ART_MODULE(seaquest::TestProducer)
