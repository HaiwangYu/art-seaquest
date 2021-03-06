# art-seaquest

Prototype package for the SeaQuest experiment in the FermiLab **art** framework.

[Doxygen page](https://haiwangyu.github.io/seaquest-offline-doc/index.html)

### Folder description:

- [art-seaquest](art-seaquest): source code:
  - DataProducts: art data products - interface objects that holds data 
  - Modules: art modules - **Producer**, **Filter**, **Analyzer** in the art world

- [scripts](scripts): setup the environment in **seaquestgpvm01.fnal.gov** virtual machine at FermiLab. Currently using **art** from the **LArSoft** project. Need to be updated in the future.
  - UPS area: /cvmfs/fermilab.opensciencegrid.org/products/larsoft
  - Need UPS products: **art** (v1_17_07), **cetbuildtools**

- [ups](ups): package dependency descriptions; files needed for the **buildtool**

### Build
In a FermiLab VM. 
```
mkdir [path-to-build-dir]
cd [path-to-build-dir]
cp [path-to-source]/art-seaquest/scripts/*.sh .
source setup.sh
source setup_build.sh
buildtool -j 4
```

### Run
In a test folder
```
cp [path-to-source]/art-seaquest/Modules/*.fcl .
art -c testProducer.fcl
art -c testAnalyzer.fcl
```

### Related

| Name | redmine page | Repository (read-only) |
|:---|:---|:---|
| **art** | https://cdcvs.fnal.gov/redmine/projects/art | http://cdcvs.fnal.gov/projects/art |
| **art-workbook** | https://cdcvs.fnal.gov/redmine/projects/art-workbook | http://cdcvs.fnal.gov/projects/art-workbook |
| **toyExperiment** | | http://cdcvs.fnal.gov/projects/toyExperiment |

- **art/LArSoft Course**: https://indico.fnal.gov/event/9928/overview, 3-7 August 2015
