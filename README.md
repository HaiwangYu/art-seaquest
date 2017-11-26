# art-seaquest

Prototype package for the SeaQuest experiment in the FermiLab **art** framework.

Folder description:

- art-seaquest: source code:
  - DataProducts: art data products - interface objects that holds data 
  - Modules: art modules - **Producer**, **Filter**, **Analyzer** in the art world

- scripts: setup the environment in **seaquestgpvm01.fnal.gov** virtual machine at FermiLab. Currently using **art** from the **LArSoft** project. Need to be updated in the future.
  - UPS area: /cvmfs/fermilab.opensciencegrid.org/products/larsoft
  - Need UPS products: **art** (v1_17_07), **cetbuildtools**

- ups: package dependency descriptions; files needed for the **buildtool**
