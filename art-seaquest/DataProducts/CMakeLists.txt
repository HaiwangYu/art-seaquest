art_make(
  LIB_LIBRARIES
    ${ART_PERSISTENCY_PROVENANCE}
    ${ART_PERSISTENCY_COMMON}
    ${ART_UTILITES}
    ${CETLIB}
    ${CLHEP}
  DICT_LIBRARIES
    art-seaquest_DataProducts
    ${ART_PERSISTENCY_CORE}
    ${ART_PERSISTENCY_PROVENANCE}
    ${ART_PERSISTENCY_COMMON}
    ${ART_UTILITES}
    ${CETLIB}
  )

#install_headers()
#install_source()
