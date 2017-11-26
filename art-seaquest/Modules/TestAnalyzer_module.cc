//
// Read the seaquest::Event data product.
//

#include "art-seaquest/DataProducts/Event.h"
#include "art-seaquest/DataProducts/Hit.h"
#include "art-seaquest/DataProducts/HitCollection.h"

#include "art/Framework/Core/EDAnalyzer.h"
#include "art/Framework/Core/ModuleMacros.h"
#include "art/Framework/Principal/Event.h"

#include <iostream>
#include <vector>
#include <memory>

namespace seaquest {

  class TestAnalyzer : public art::EDAnalyzer {

  public:

    explicit TestAnalyzer(fhicl::ParameterSet const& pset);

    void analyze( art::Event const& event) override;

  private:

    art::InputTag _inputTag;

  };

}

seaquest::TestAnalyzer::TestAnalyzer(fhicl::ParameterSet const& pset ):
  art::EDAnalyzer(pset),
  _inputTag(pset.get<std::string>("inputTag")){
}

void seaquest::TestAnalyzer::analyze( art::Event const& event){

	std::cout << "==============================================" << std::endl;
	std::cout << event.id() << std::endl;

	//< Read seaquest::Event
  auto event_header = event.getValidHandle<seaquest::Event>(_inputTag);
  std::cout << *event_header << std::endl;

  //< Read seaquest::HitCollection
  auto hit_collection = event.getValidHandle<seaquest::HitCollection>(_inputTag);
  for(auto hit : *hit_collection) {
  	std::cout << *hit << std::endl;
  }

}

DEFINE_ART_MODULE(seaquest::TestAnalyzer)
