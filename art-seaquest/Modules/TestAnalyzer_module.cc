//
// Read the seaquest::Event data product.
//

#include "art-seaquest/DataProducts/Event.h"

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

    art::InputTag summaryTag_;

  };

}

seaquest::TestAnalyzer::TestAnalyzer(fhicl::ParameterSet const& pset ):
  art::EDAnalyzer(pset),
  summaryTag_(pset.get<std::string>("summaryTag")){
}

void seaquest::TestAnalyzer::analyze( art::Event const& event){

  auto summary = event.getValidHandle<seaquest::Event>(summaryTag_);
  std::cout << event.id() << " " << *summary << std::endl;

}

DEFINE_ART_MODULE(seaquest::TestAnalyzer)
